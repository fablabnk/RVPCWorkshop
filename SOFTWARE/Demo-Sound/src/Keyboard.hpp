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
#include <ch32v00x.h>
#include "Config.hpp"
#include "Delay.hpp"

/// #TODO: ensure that this goes to FLASH memory
/// @brief Maps keyboard keycodes to ascii table values
constexpr const std::array<char, 128u> gKeyCodeToAscii = {
	0x00, // 0x00
	0x00, // 0x01   <F9>
	0x00, // 0x02
	0x00, // 0x03   <F5>
	0x00, // 0x04   <F3>
	0x00, // 0x05   <F1>
	0x00, // 0x06   <F2>
	0x00, // 0x07   <F12>
	0x00, // 0x08
	0x00, // 0x09   <F10>
	0x00, // 0x0A   <F8>
	0x00, // 0x0B   <F6>
	0x00, // 0x0C   <F4>
	0x09, // 0x0D	<Tab>
	'`',  // 0x0E
	0x00, // 0x0F

	0x00, // 0x10
	0x00, // 0x11	<Alt Left>
	0x00, // 0x12	<Shift Left>
	0x00, // 0x13
	0x00, // 0x14	<Ctrl Left>
	'q',  // 0x15
	'1',  // 0x16
	0x00, // 0x17
	0x00, // 0x18
	0x00, // 0x19
	'z',  // 0x1A
	's',  // 0x1B
	'a',  // 0x1C
	'w',  // 0x1D
	'2',  // 0x1E
	0x00, // 0x1F

	0x00, // 0x20
	'c',  // 0x21
	'x',  // 0x22
	'd',  // 0x23
	'e',  // 0x24
	'4',  // 0x25
	'3',  // 0x26
	0x00, // 0x27
	0x00, // 0x28
	' ',  // 0x29
	'v',  // 0x2A
	'f',  // 0x2B
	't',  // 0x2C
	'r',  // 0x2D
	'5',  // 0x2E
	0x00, // 0x2F

	0x00, // 0x30
	'n',  // 0x31
	'b',  // 0x32
	'h',  // 0x33
	'g',  // 0x34
	'y',  // 0x35
	'6',  // 0x36
	0x00, // 0x37
	0x00, // 0x38
	0x00, // 0x39
	'm',  // 0x3A
	'j',  // 0x3B
	'u',  // 0x3C
	'7',  // 0x3D
	'8',  // 0x3E
	0x00, // 0x3F

	0x00, // 0x40
	',',  // 0x41
	'k',  // 0x42
	'i',  // 0x43
	'o',  // 0x44
	'0',  // 0x45
	'9',  // 0x46
	0x00, // 0x47
	0x00, // 0x48
	'.',  // 0x49
	'/',  // 0x4A
	'l',  // 0x4B
	';',  // 0x4C
	'p',  // 0x4D
	'-',  // 0x4E
	0x00, // 0x4F

	0x00, // 0x50
	0x00, // 0x51
	'\'', // 0x52
	0x00, // 0x53
	'[',  // 0x54
	'=',  // 0x55
	0x00, // 0x56
	0x00, // 0x57
	0x00, // 0x58	<CapsLock>
	0x00, // 0x59
	0x0D, // 0x5A	<Enter>
	']',  // 0x5B
	0x00, // 0x5C
	'\\', // 0x5D
	0x00, // 0x5E
	0x00, // 0x5F

	0x00, // 0x60
	0x00, // 0x61
	0x00, // 0x62
	0x00, // 0x63
	0x00, // 0x64
	0x00, // 0x65
	0x08, // 0x66	<Backspace>
	0x00, // 0x67
	0x00, // 0x68
	0x00, // 0x69
	0x00, // 0x6A
	0x00, // 0x6B
	0x00, // 0x6C
	0x00, // 0x6D
	0x00, // 0x6E
	0x00, // 0x6F

	0x00, // 0x70
	0x00, // 0x71
	0x00, // 0x72
	0x00, // 0x73
	0x00, // 0x74
	0x00, // 0x75
	0x1B, // 0x76   <Esc>
	0x00, // 0x77
	0x00, // 0x78   <F11>
	0x00, // 0x79
	0x00, // 0x7A
	0x00, // 0x7B
	0x00, // 0x7C
	0x00, // 0x7D
	0x00, // 0x7E
	0x00, // 0x7F
};

#define KBD_PERIPHERY     (RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD)

class Keyboard {
private:

	static bool     is_init;            // current state of keyboard
	static bool     is_rawdata_ready;   // flag
	static bool     is_data_ready;      // flag
	static uint8_t  rawdata_idx;        // raw data buffer bits counter / idx
	static uint16_t rawdata;            // raw data buffer
	static uint32_t data;               // key-code buffer

	static inline void raw_reset() {
		rawdata = 0;
		rawdata_idx = 0;
		is_rawdata_ready = 0;
	}
public:
	/// @brief Only static members, no need to construct an instance
	Keyboard() = delete;

	/// @brief Initialize keyboard hardware
	static void init() {
		if (is_init) { return; }
		Tick::init();
		Config::GPIO(GPIOD, GPIO_Pin_1, GPIO_Mode_IN_FLOATING); // configure clock pin
		Config::GPIO(GPIOA, GPIO_Pin_2, GPIO_Mode_IN_FLOATING); // configure data pin
		Config::GPIO_Intr(GPIO_PortSourceGPIOD, GPIO_PinSource1,
						EXTI_Line1, EXTI_Trigger_Falling); // set up key-press interrupt
		is_init = true;
	}

	static char ascii(uint32_t key_code) {
		return gKeyCodeToAscii[((uint8_t)key_code) & 0b01111111];
	}

	/// @brief Wait for any of: key-press or key-release
	/// @return int32_t key-code
	static uint32_t wait_any() {
		uint32_t code = read();
		while (code == 0x0000) {
			code = read();
		}
		return code;
	}

	/// @brief Wait for key-press event
	/// @return int32_t key-code
	static uint32_t wait_press() {
		uint32_t code = read();
		while (code == 0 || (code & 0xFF00) == 0xF000) {
			code = read();
		}
		return code;
	}

	/// @brief Wait for key-release event
	/// @return int32_t key-code
	static uint32_t wait_release() {
		uint32_t code = read();
		while ((code & 0xFF00) != 0xF000) {
			code = read();
		}
		return code;
	}

	static void handle() {
		if (is_rawdata_ready == 0) { return; /* no data */ }
		if (is_data_ready) { return raw_reset(); /* keyboard was not read yet */ }

		// Check start bit
		uint16_t mask = 0b0000010000000000;
		if (rawdata & mask) { return raw_reset(); /* wrong start bit */ } 

		// Get data bits
		uint8_t buff = 0;
		uint8_t one = 0;
		for (uint8_t bit = 0; bit < 8; bit++) {
			mask >>= 1;
			if (rawdata & mask) {
				buff |= (1 << bit);
				one ^= 1;
			}
		}

		// Get parity bit
		mask >>= 1;
		uint8_t parity = (rawdata & mask) ^ one;

		// Check stop bit
		mask >>= 1;
		if ((rawdata & mask) == 0) { return raw_reset(); /* wrong stop bit */ }

		if (parity) { // got a valid keycode
			data <<= 8;
			data |= ((uint32_t)buff);
			is_data_ready = ((buff & 0xE0) != 0xE0);
		}
		raw_reset();
	}

	static uint32_t read() {
		handle();
		if (is_data_ready) {
			uint32_t kbd_code = data;
			data = 0;
			is_data_ready = false;
			return kbd_code;
		}
		return 0;
	}

	/// @brief Store keyboard incoming raw data bit
	static void store_bit() {
		// if previous rawdata is still ready, ignore incoming bits
		if (is_rawdata_ready == false) {
			rawdata_idx++;      // increment received bits counter
			rawdata <<= 1;      // prepare rawdata buffer to receive next bit
			// if keyboard data pin is Hi, set rawdata bit to 1
			if (GPIOA->INDR & GPIO_Pin_2) { rawdata |= 1; }
			// mark rawdata as ready once the entire frame has been received
			is_rawdata_ready = (rawdata_idx == 11);
		}
		EXTI->INTFR = EXTI_Line1; // get ready for the next interrupt event
	}
};

/* initialize static data members */

bool        Keyboard::is_init = false;
bool        Keyboard::is_rawdata_ready= false;
bool        Keyboard::is_data_ready= false;
uint8_t     Keyboard::rawdata_idx = 0;
uint16_t    Keyboard::rawdata = 0;
uint32_t    Keyboard::data = 0;

/* ****************************** */

/// @brief Keyboard datapin-triggered-interrupt handler
void EXTI7_0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI7_0_IRQHandler(void) {
	Keyboard::store_bit();
}
