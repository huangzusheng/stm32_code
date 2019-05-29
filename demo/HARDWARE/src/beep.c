#include "beep.h"
#include "stm32f10x.h"


/*beep PB8*/
void beep_init(void)
{
	/**/
	GPIO_InitTypeDef gpio_init_struct;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	/**/
	gpio_init_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_8;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_init_struct);

	/**/
	beep_control(_BEEP_OFF_);
}


/**/
void beep_control(int beep_state)
{
	if(beep_state == _BEEP_ON_)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_8);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	}
}
