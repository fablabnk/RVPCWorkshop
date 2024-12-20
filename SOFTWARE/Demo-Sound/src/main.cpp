/*
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
*/



#include <ch32v00x.h>
#include "Buzzer.hpp"
#include "Config.hpp"
#include "Keyboard.hpp"

/// =========================================================================
///								Interrupt Handlers
///	=========================================================================
#ifdef __cplusplus
extern "C" {
#endif

int main(void);

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void NMI_Handler(void) {
	
}

void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast"))); 
void HardFault_Handler(void) {
	while (1) {
		
	}
}

/// @brief Keyboard datapin-triggered-interrupt handler
void EXTI7_0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI7_0_IRQHandler(void) {
	Keyboard::store_bit();
}

#ifdef __cplusplus
}
#endif

/// =========================================================================
///								==================
///	=========================================================================

// main application loop
void loop();

int main(void) {
	Config::init_System();	// initialize system clock and memory
	Tick::init();			// initialize sistem tick
	Keyboard::init();		// initialize keyboard
	Buzzer::init();			// initialize buzzer

	// run application
	loop();
}
