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

enum class TimChannel : uint8_t {C1=1u, C2, C3, C4};

class Config {
private:
public:
	/// @brief Configure GPIO pin
	/// @param port port name
	/// @param pin pin index
	/// @param mode pin mode
	static void GPIO(GPIO_TypeDef *port, uint16_t pin,
			GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed=GPIO_Speed_30MHz)
	{
		if (port == GPIOA) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		} else if (port == GPIOC) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		} else if (port == GPIOD) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
		}

		GPIO_InitTypeDef Config {
			.GPIO_Pin=pin,
			.GPIO_Speed=speed,
			.GPIO_Mode=mode
		};
		GPIO_Init(port, &Config);
	}

	/// @brief Configure GPIO interrupt
	/// @param port port index
	/// @param pin pin index
	/// @param line line index
	/// @param trigger EXTI trigger type (ie rising, falling or both)
	static void GPIO_Intr(uint8_t port, uint8_t pin, uint32_t line,
							EXTITrigger_TypeDef trigger)
	{
		GPIO_EXTILineConfig(port, pin);

		EXTI_InitTypeDef kbd_exti = {
			.EXTI_Line = line,
			.EXTI_Mode = EXTI_Mode_Interrupt,
			.EXTI_Trigger = trigger,
			.EXTI_LineCmd = ENABLE,
		};
		EXTI_Init(&kbd_exti);

		NVIC_InitTypeDef kbd_nvic = {
			.NVIC_IRQChannel = EXTI7_0_IRQn,
			.NVIC_IRQChannelPreemptionPriority = 0,
			.NVIC_IRQChannelSubPriority = 1,
			.NVIC_IRQChannelCmd = ENABLE,
		};
		NVIC_Init(&kbd_nvic);
	}

	/// @brief Configure MASTER timer
	/// @param TIM pointer to the timer
	/// @param period value to be loaded into Auto-Reload Register (0x0-0xFFFF)
	/// @param prescaler value used to divide the TIM clock (0x0-0xFFFF)
	/// @param mode one of TIM_Counter_Mode_x, specifies the counter mode
	static void Timer_M(TIM_TypeDef *TIM, uint16_t period, uint16_t prescaler,
						uint16_t mode)
	{
		if (TIM == TIM1) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
		} else if (TIM == TIM2) {
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		}

		TIM_TimeBaseInitTypeDef TimerConfig {
			.TIM_Prescaler = prescaler,
			.TIM_CounterMode = mode,
			.TIM_Period = period,
			.TIM_ClockDivision = TIM_CKD_DIV1
		};
		TIM_TimeBaseInit(TIM, &TimerConfig);
	}

	/// @brief Configure SLAVE timer
	/// @param slave pointer to slave timer
	/// @param master pointer to master timer
	/// @param source TIM_TRGOSource that triggers output of the slave timer
	/// @param period value to be loaded into Auto-Reload Register (0x0-0xFFFF)
	/// @param mode one of TIM_Counter_Mode_x, specifies the counter mode
	static void Timer_S(TIM_TypeDef *slave, TIM_TypeDef *master, 
		uint16_t source, uint16_t period, uint16_t mode)
	{
		if (slave == master) {
			return;
		}

		TIM_SelectOutputTrigger(master, source);

		if (slave == TIM1) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
			TIM_SelectInputTrigger(slave, TIM_TS_ITR1);
		} else if (slave == TIM2) {
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
			TIM_SelectInputTrigger(slave, TIM_TS_ITR0);
		}

		TIM_SelectSlaveMode(slave, TIM_SlaveMode_External1);

		TIM_CounterModeConfig(slave, mode);
		TIM_SetAutoreload(slave, period);
	}

	/// @brief Configure timer interrupt
	/// @param TIM pointer to the timer for which interrupt is to be set
	void Timer_Intr(TIM_TypeDef *TIM)
	{
		NVIC_InitTypeDef init {
			.NVIC_IRQChannel = 0,
			.NVIC_IRQChannelPreemptionPriority = 1,
			.NVIC_IRQChannelSubPriority = 1,
			.NVIC_IRQChannelCmd = ENABLE
		};

		if (TIM == TIM1) {
			TIM_ITConfig(TIM, TIM_IT_Update, ENABLE);
			init.NVIC_IRQChannel = TIM1_UP_IRQn;
		} else if (TIM == TIM2) {
			TIM_ITConfig(TIM, TIM_IT_Update, ENABLE);
			init.NVIC_IRQChannel = TIM2_IRQn;
		}
		NVIC_Init(&init);
	}

	/// @brief Configure puls width modulation
	/// @param TIM pointer to the timer
	/// @param ch 
	/// @param pulse 
	/// @param mode 
	static void PWM(TIM_TypeDef *TIM, TimChannel ch,
					uint16_t pulse, uint16_t mode)
	{
		TIM_OCInitTypeDef config={
			.TIM_OCMode = mode,
			.TIM_OutputState = TIM_OutputState_Enable,
			.TIM_Pulse = pulse,
			.TIM_OCPolarity = TIM_OCPolarity_High
		};

		typedef void (*TIM_OCInit)(TIM_TypeDef *, TIM_OCInitTypeDef *);
		TIM_OCInit oi[5] = {(TIM_OCInit)(0), TIM_OC1Init, TIM_OC2Init, 
							TIM_OC3Init, TIM_OC4Init};
		oi[(uint8_t)ch](TIM, &config );

		TIM_CtrlPWMOutputs(TIM, ENABLE);

		typedef void (*TIM_OCConfig)(TIM_TypeDef *, uint16_t);
		TIM_OCConfig oc[5] = {(TIM_OCConfig)(0), TIM_OC1PreloadConfig,
								TIM_OC2PreloadConfig, TIM_OC3PreloadConfig,
								TIM_OC4PreloadConfig};
		oc[(uint8_t)ch](TIM, TIM_OCPreload_Disable);

		TIM_ARRPreloadConfig(TIM, ENABLE);
	}
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif