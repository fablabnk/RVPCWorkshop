/* ***************************************************************************
MIT License

Copyright (c) 2024 k-off pacovali@student.42berlin.de

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*************************************************************************** */

#pragma once

#include <array>
#include <bitset>
#include <ch32v00x.h>
#include "Config.hpp"
#include "VGAMode.hpp"
#include "Delay.hpp"

/// @brief Manages VGA interface, puts scanline on the screen
class VGA {
private:
	static inline const VGAMode* mode = nullptr;			// vga mode: resolution, refresh rate, etc.

	static inline GPIO_TypeDef *data_port = GPIOC;			// data port
	static inline uint16_t data_pin = GPIO_Pin_2;			// data pin

	static inline GPIO_TypeDef *hsync_port = GPIOC;			// horisontal synch. port
	static inline uint16_t hsync_pin = GPIO_Pin_1;			// horisontal synch. pin
	static inline TIM_TypeDef *hsync_tim = TIM2;			// horisontal synch. timer
	static inline TimChannel htimer_ch = TimChannel::C4;	// horisontal synch. channel
	static inline uint16_t hdelay = 200;					// amount of ticks before start of visible part of scanline

	static inline GPIO_TypeDef *vsync_port = GPIOA;			// vertical synch. port
	static inline uint16_t vsync_pin = GPIO_Pin_1;			// vertical synch. pin
	static inline TIM_TypeDef *vsync_tim = TIM1;			// vertical synch. timer
	static inline TimChannel vtimer_ch = TimChannel::C2;	// vertical synch. channel

	// returns timer period in ticks, rounded to the closest integer value
	static inline uint16_t htimer_period() {
		return ((Tick::SysClock + (mode->linefreq / 2u)) / mode->linefreq) - 1u;
	}

	// returns pwm pulse in ticks, rounded to the closest integer value
	static inline uint16_t hpulse_width() {
		float period_tick = (htimer_period() + 1) * 10;	// period in sys ticks (x10 for rounding)
		float period_pix = mode->htotal();				// period in pixels
		float pulse_pix = mode->htim.spulse;			// pulse time in pixels
		float duty_cycle = period_pix / pulse_pix; 		// pulse fraction 
		return static_cast<uint16_t>((period_tick / duty_cycle + 5) / 10);
	}

	// Get max amount of ticks before start of visible part of scanline
	static inline uint16_t get_hdelay() {
		uint16_t hidden_pixels = mode->htim.bporch + mode->htim.spulse;
		uint16_t total_pixels = hidden_pixels + mode->htim.fporch + mode->hres;
		return htimer_period() * hidden_pixels / total_pixels -1; // add a border of ±4 pixels
	}

public:

	// Scanline buffer
	static inline std::array<uint8_t, 40> SL {
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b11111111, 0b0,
		0b10101010, 0b01101010, 0b01010101,
	};

	// Initialize VGA interface
	static inline void init() {
		Config::GPIO(data_port, data_pin, GPIO_Mode_Out_PP);
		Config::GPIO(hsync_port, hsync_pin, GPIO_Mode_AF_PP);
		Config::GPIO(vsync_port, vsync_pin, GPIO_Mode_AF_PP);

		change_mode(&mPAL720x576_50Hz);
	}

	/// @brief reset vertical timer interrupt
	static inline void vtim_reset() {
		vsync_tim->INTFR = (uint16_t)(~TIM_IT_Update);
	}

	/// @brief reset horizontal timer interrupt
	static inline void htim_reset() {
		hsync_tim->INTFR = (uint16_t)(~TIM_IT_Update);
	}

	/// @brief Allows to change modes to one of those predefined in VGAMode.hpp.
	///			As GPIO max frequency is 30MHz, anything above 640x480 is 
	///			unobtainable
	/// @param _mode VGA interface mode
	static inline void change_mode(const VGAMode* _mode) {
		mode = _mode;

		// Stop timers
		TIM_Cmd(vsync_tim, DISABLE);
		TIM_Cmd(hsync_tim, DISABLE);

		// HSync
		uint16_t hpolarity = (mode->hsync == Sync::Hi) ? TIM_OCPolarity_High :
															TIM_OCPolarity_Low;
		GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);
		Config::Timer_M(hsync_tim, htimer_period(), 0, TIM_CounterMode_Up);
		Config::PWM(hsync_tim, htimer_ch, hpulse_width(), TIM_OCMode_PWM1, 
					TIM_OutputState_Enable, hpolarity);
		Config::Timer_Intr(hsync_tim);

		// VSync
		uint16_t vpolarity = (mode->vsync == Sync::Hi) ? TIM_OCPolarity_High :
															TIM_OCPolarity_Low;
		GPIO_PinRemapConfig(GPIO_PartialRemap2_TIM1, ENABLE);
		Config::Timer_S(vsync_tim, hsync_tim, TIM_TRGOSource_OC4Ref,
						mode->vtotal(), TIM_CounterMode_Up);
		Config::PWM(vsync_tim, vtimer_ch, mode->vtim.spulse, TIM_OCMode_PWM1,
					TIM_OutputState_Enable, vpolarity);
		Config::Timer_Intr(vsync_tim);
		hdelay = get_hdelay();

		// Start timers
		TIM_Cmd(vsync_tim, ENABLE);
		TIM_Cmd(hsync_tim, ENABLE);
	}

	/// @brief Checks whether current scanline is in displayable area of the screen
	/// @return true or false
	static inline bool is_displayable() {
		uint16_t min = mode->vtim.spulse + mode->vtim.bporch + 5; // black border of 5 lines on top
		uint16_t max = min + mode->vres - 10; // black border of 5 lines on bottom
		return TIM1->CNT >= min && TIM1->CNT < max;
	}

	/// @brief Get current scanline index
	/// @return uint16_t
	static inline uint16_t line_idx() {
		return TIM1->CNT - (mode->vtim.spulse + mode->vtim.bporch);
	}

	/// @brief Get max amount of characters in a line for current resolution
	/// @return uint16_t
	static inline uint16_t hres_chars() {
		return mode->hres >> 3;
	}

	/// @brief Get max amount of characters in a column for current resolution
	/// @return uint16_t
	static inline uint16_t vres_chars() {
		return mode->vres >> 3;
	}

	/// @brief Puts scanline on the screen
	static inline void put_scanline() {
		if (!is_displayable()) return ;
		while(TIM2->CNT < hdelay) ;
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[0] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[0] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[0] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[0] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[0] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[0] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[0])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[0] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[1] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[1] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[1] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[1] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[1] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[1] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[1])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[1] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[2] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[2] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[2] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[2] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[2] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[2] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[2])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[2] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[3] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[3] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[3] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[3] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[3] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[3] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[3])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[3] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[4] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[4] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[4] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[4] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[4] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[4] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[4])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[4] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[5] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[5] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[5] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[5] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[5] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[5] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[5])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[5] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[6] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[6] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[6] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[6] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[6] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[6] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[6])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[6] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[7] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[7] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[7] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[7] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[7] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[7] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[7])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[7] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[8] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[8] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[8] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[8] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[8] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[8] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[8])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[8] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[9] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[9] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[9] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[9] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[9] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[9] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[9])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[9] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[10] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[10] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[10] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[10] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[10] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[10] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[10])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[10] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[11] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[11] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[11] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[11] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[11] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[11] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[11])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[11] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[12] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[12] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[12] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[12] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[12] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[12] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[12])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[12] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[13] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[13] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[13] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[13] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[13] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[13] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[13])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[13] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[14] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[14] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[14] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[14] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[14] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[14] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[14])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[14] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[15] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[15] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[15] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[15] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[15] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[15] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[15])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[15] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[16] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[16] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[16] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[16] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[16] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[16] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[16])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[16] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[17] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[17] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[17] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[17] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[17] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[17] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[17])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[17] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[18] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[18] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[18] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[18] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[18] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[18] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[18])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[18] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[19] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[19] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[19] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[19] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[19] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[19] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[19])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[19] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[20] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[20] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[20] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[20] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[20] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[20] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[20])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[20] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[21] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[21] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[21] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[21] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[21] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[21] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[21])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[21] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[22] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[22] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[22] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[22] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[22] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[22] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[22])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[22] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[23] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[23] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[23] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[23] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[23] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[23] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[23])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[23] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[24] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[24] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[24] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[24] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[24] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[24] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[24])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[24] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[25] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[25] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[25] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[25] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[25] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[25] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[25])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[25] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[26] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[26] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[26] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[26] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[26] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[26] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[26])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[26] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[27] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[27] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[27] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[27] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[27] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[27] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[27])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[27] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[28] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[28] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[28] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[28] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[28] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[28] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[28])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[28] << 1));
		GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[29] >> 6)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[29] >> 5)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[29] >> 4)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[29] >> 3)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[29] >> 2)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[29] >> 1)); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[29])); GPIOC->OUTDR = (~GPIO_Pin_2 | (SL[29] << 1));
	}
};
