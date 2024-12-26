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

#include <ch32v00x.h>

class Tick {
private:
	/// @brief curent state of SysTick
	static inline bool is_init = false;

public:

	Tick() = delete;

	#if defined(SYSCLK_FREQ_24MHz_HSE) || defined(SYSCLK_FREQ_24MHZ_HSI)
		static inline uint32_t SysClock = 24'000'000u;
	#elif  defined(SYSCLK_FREQ_8MHz_HSI) || defined(SYSCLK_FREQ_8MHz_HSE)
		static inline uint32_t SysClock = 8'000'000u;
	#else
		static inline uint32_t SysClock = 48'000'000u;
	#endif

	/// @brief Amount of system core clock ticks per millisecond
	static inline uint32_t ticks_per_ms = SysClock / 1'000u;

	/// @brief Amount of system core clock ticks per microsecond
	static inline uint32_t ticks_per_us = SysClock / 1'000'000u;

	/// @brief Initialize SysTick
	static void init() {
		if (is_init) {
			return;
		}
		SysTick->SR &= ~(1 << 0);
		SysTick->CMP = 0xFFFFFFFF;
		SysTick->CNT = 0;
		SysTick->CTLR = 0xF;
		is_init = true;
	}
};

/// @brief Allows to set a delay at 'tick', 'us' or 'ms' scale
class Delay {
public:

	/// @brief This class only has static members and shouldn't be constucted
	Delay() = delete;

	/// @brief Delays execution by 'amount' of milliseconds
	/// @param amount milliseconds
	static void ms(uint32_t amount) {
		volatile uint32_t delay = amount * Tick::ticks_per_ms;
		volatile uint32_t start = SysTick->CNT;
		while (SysTick->CNT - start < delay) ;
	}

	/// @brief Delays execution by 'amount' of microseconds
	/// @param amount microseconds
	static void us(uint32_t amount) {
		volatile uint32_t delay = amount * Tick::ticks_per_us;
		volatile uint32_t start = SysTick->CNT;
		while (SysTick->CNT - start < delay) ;
	}

	/// @brief Delays execution by 'amount' of system core clock ticks
	/// @param amount ticks
	static void ticks(uint32_t amount) {
		static volatile uint32_t start = SysTick->CNT;
		while (SysTick->CNT - start < amount) {
		}
	}
};

/// @brief Allows to set a timeout in ms and check whether it has been reached
class TimeoutMs {
private:

	/// @brief Start of the delay - current system tick value
	volatile uint32_t start;
	/// @brief Amount of ticks until the end of the delay
	volatile uint32_t stop;

public:

	TimeoutMs(uint32_t amount) {
		set(amount);
	}
	
	/// @brief Sets timeout for 'amount' of milliseconds
	/// @param amount milliseconds
	void set(uint32_t amount) {
		start = SysTick->CNT;
		stop = amount * Tick::ticks_per_ms;
	}

	/// @brief Returns true if timeout has not been reached
	/// @return true or false
	bool operator!() const {
		volatile auto current = SysTick->CNT;
		return (current - start < stop);
	}
};