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

#include <cstdint>
#include <ch32v00x.h>

#include "Config.hpp"
#include "Delay.hpp"
#include "Sound.hpp"

/// @brief Buzzes
class Buzzer {
private:
	// 0 and 1 in a readable form
	enum PinState {Lo, Hi};

	static void boot_sound() {
		buzz( 698, 50);
		buzz( 880, 50);
		buzz(1047, 50);
		buzz(1397, 50);
	}
	static bool is_init;
public:
	/// @brief Only static members, no need to initialize
	Buzzer() = delete;

	/// @brief Initialize buzzer hardware
	static void init() {
		if (is_init) {
			return;
		}
		Config::GPIO(GPIOC, GPIO_Pin_4, GPIO_Mode_Out_PP);
		is_init = true;
		boot_sound();
	}

	/// @brief Buzz at frequency 'f' for time 't'
	/// @param f frequency, Hz
	/// @param t time, ms
	static void buzz(uint32_t f, uint32_t t) {
		uint8_t pin_state = PinState::Lo;
		uint32_t half_period = 500'000 / f; // half_period is inverse of Hz
		
		TimeoutMs timeout(t);
		while (!timeout) {
			pin_state = !pin_state;         // flip pin state
			Delay::us(half_period);
			if (pin_state == PinState::Hi) {
				GPIOC->BSHR = GPIO_Pin_4;   // pin_state set
			} else {
				GPIOC->BCR = GPIO_Pin_4;    // pin_state unset
			}
		}
	}

	static void play(const CSound& sound) {
		uint8_t pin_state = PinState::Lo;
		TimeoutMs timeout(sound.t);
		while (!timeout) {
			pin_state = !pin_state;         // flip pin state
			Delay::us(sound.hp);
			if (pin_state == PinState::Hi) {
				GPIOC->BSHR = GPIO_Pin_4;   // pin_state set
			} else {
				GPIOC->BCR = GPIO_Pin_4;    // pin_state unset
			}
		}
	}
};

bool Buzzer::is_init = false;
