#include "timer.h"
#include "led.h"
#include "stm32f10x.h"

void timer3_init(uint16_t rcc, uint16_t poc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInit_data;
	NVIC_InitTypeDef NVIC_Init_data;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseStructInit(&TIM_TimeBaseInit_data);
	TIM_TimeBaseInit_data.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit_data.TIM_Period = rcc;
	TIM_TimeBaseInit_data.TIM_Prescaler = poc;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInit_data);

	/**/
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	/**/
	NVIC_Init_data.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_Init_data.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init_data.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_Init_data.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_Init_data);

	TIM_Cmd(TIM3, ENABLE);
}

void TIM3_IRQHandler(void)
{
	static uint32_t count;
	if(TIM_GetITStatus(TIM3, TIM_IT_Update))
	{
		count ++;
		if((count % 2) == 0)
		{
			led_control(_LED_0_, _LED_ON_);
			led_control(_LED_1_, _LED_ON_);
		}
		else
		{	
			led_control(_LED_0_, _LED_OFF_);
			led_control(_LED_1_, _LED_OFF_);
		}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}