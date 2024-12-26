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

enum class TimChannel : uint8_t {C1=0u, C2, C3, C4};

class Config {
private:
public:

	static void init_System()
	{
		SystemInit();
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
		SystemCoreClockUpdate();
		
		// Disable GPIO Alternate Functions and extrnal oscilator
		// Othewize GPIO PORT A does not work
		RCC_HSEConfig(RCC_HSE_OFF);
		GPIO_PinRemapConfig(GPIO_Remap_PA1_2, DISABLE);

		// Remapping
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	}

	/// @brief Configure GPIO and pin
	/// @param port port name
	/// @param pin pin index
	/// @param mode pin mode
	/// @param speed defaults to GPIO_Speed_30MHz
	static void GPIO(GPIO_TypeDef *port, uint16_t pin, GPIOMode_TypeDef mode, 
						GPIOSpeed_TypeDef speed=GPIO_Speed_30MHz)
	{
		GPIO_InitTypeDef config = { //initialize configuration
			.GPIO_Pin = pin,
			.GPIO_Speed = speed,
			.GPIO_Mode = mode
		};
		if (port == GPIOA) { // enable peripheral clock
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		} else if (port == GPIOC) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		} else if (port == GPIOD) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
		}
		GPIO_Init(port, &config); // initialize port
	};

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
	/// @param period length of the timer period, loaded into Auto-Reload Register (0x0-0xFFFF)
	/// @param prescaler used to divide timer speed compared to system clock by x times (0x0-0xFFFF)
	/// @param mode one of TIM_Counter_Mode_Up(_Down, or other); count up, down or other
	static void Timer_M(TIM_TypeDef *TIM, uint16_t period, uint16_t prescaler, uint16_t mode)
	{
		if (TIM == TIM2) {
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		} else if (TIM == TIM1) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
		}
		TIM_TimeBaseInitTypeDef TimerConfig = {
			.TIM_Prescaler = prescaler, //0u,
			.TIM_CounterMode = mode, //TIM_CounterMode_Up,
			.TIM_Period = period, //1268u, //1524u, //992u, 
			.TIM_ClockDivision = TIM_CKD_DIV1,
		};
		TIM_TimeBaseInit(TIM, &TimerConfig);
	};

	/// @brief Configure SLAVE timer, that gets triggered by MASTER
	/// @param slave pointer to slave timer
	/// @param master pointer to master timer
	/// @param source TIM_TRGOSource that triggers output of the slave timer
	/// @param period length of the timer period, loaded into Auto-Reload Register (0x0-0xFFFF)
	/// @param mode one of TIM_Counter_Mode_Up(_Down, or other); count up, down or other
	static void Timer_S(TIM_TypeDef *slave, TIM_TypeDef *master, 
		uint16_t source, uint16_t period, uint16_t mode)
	{
		if (slave == master) { return; }
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
	static void Timer_Intr(TIM_TypeDef *TIM)
	{
		NVIC_InitTypeDef NVIC_InitStruct={
			.NVIC_IRQChannel = 0,
			.NVIC_IRQChannelPreemptionPriority = 1,
			.NVIC_IRQChannelSubPriority = 1,
			.NVIC_IRQChannelCmd = ENABLE
		};
		if (TIM == TIM1) {
			TIM_ITConfig(TIM, TIM_IT_Update, ENABLE);
			NVIC_InitStruct.NVIC_IRQChannel = TIM1_UP_IRQn;
		} else if (TIM == TIM2) {
			TIM_ITConfig(TIM, TIM_IT_Update, ENABLE);
			NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
		}
		NVIC_Init(&NVIC_InitStruct);
	};

	/// @brief Configure puls width modulation
	/// @param TIM pointer to the timer
	/// @param ch timer channel
	/// @param pulse_len pulse length, loaded in Capture Compare Register (0x0-0xFFFF)
	/// @param mode timer mode
	/// @param output_state forward PWM signal to an actual pin, default Enable
	/// @param polarity polarity of the signal, default high
	static void PWM(TIM_TypeDef *TIM, TimChannel ch, uint16_t pulse_len, //183u, //100u,
			uint16_t mode, uint16_t output_state=TIM_OutputState_Enable,
			uint16_t polarity=TIM_OCPolarity_High)
	{
		TIM_OCInitTypeDef config={
			.TIM_OCMode = mode,
			.TIM_OutputState = output_state,
			.TIM_Pulse = pulse_len,
			.TIM_OCPolarity = polarity
		};

		// use function pointer array instead of if-else
		typedef void (*TIM_OCInit)(TIM_TypeDef *, TIM_OCInitTypeDef *);
		constexpr const TIM_OCInit oi[4] = {TIM_OC1Init, TIM_OC2Init,
										TIM_OC3Init, TIM_OC4Init};
		oi[(uint8_t)ch](TIM, &config );
		TIM_CtrlPWMOutputs(TIM, ENABLE);

		// use function pointer array instead of if-else
		typedef void (*TIM_OCConfig)(TIM_TypeDef *, uint16_t);
		constexpr const TIM_OCConfig oc[4] = {TIM_OC1PreloadConfig,
			TIM_OC2PreloadConfig, TIM_OC3PreloadConfig, TIM_OC4PreloadConfig};
		oc[(uint8_t)ch](TIM, TIM_OCPreload_Disable);
		TIM_ARRPreloadConfig(TIM, ENABLE);
	};
};
