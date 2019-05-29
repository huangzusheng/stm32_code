#include "exti.h"
#include "delay.h"
#include "beep.h"
#include "key.h"

void exti_init(void)
{
	GPIO_InitTypeDef gpio_init_data;
	NVIC_InitTypeDef nvic_init_data;
	EXTI_InitTypeDef exti_init_data;
	
	/**/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	gpio_init_data.GPIO_Mode = GPIO_Mode_IPU;
	gpio_init_data.GPIO_Pin = GPIO_Pin_4;
	gpio_init_data.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOE, &gpio_init_data);

	/**/
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);

	/**/
	exti_init_data.EXTI_Line = EXTI_Line4;
	exti_init_data.EXTI_LineCmd = ENABLE;
	exti_init_data.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_init_data.EXTI_Trigger =EXTI_Trigger_Falling;
	EXTI_Init(&exti_init_data);

	/**/
	nvic_init_data.NVIC_IRQChannel = EXTI4_IRQn;
	nvic_init_data.NVIC_IRQChannelCmd = ENABLE;
	nvic_init_data.NVIC_IRQChannelPreemptionPriority = 1;
	nvic_init_data.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&nvic_init_data);
}


uint32_t int_count = 0;
void EXTI4_IRQHandler(void)
{
	delay_ms(10);
	if(_KEY0_ == 0)
	{
		int_count ++;
		if((int_count%2) == 0)
		{
			beep_control(_BEEP_ON_);
		}
		else
		{
			beep_control(_BEEP_OFF_);
		}
	}

	EXTI_ClearITPendingBit(EXTI_Line4);
}