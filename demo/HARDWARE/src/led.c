#include "led.h"
#include "stm32f10x.h"


/**/
void led_init(void)
{
	GPIO_InitTypeDef gpio_init_structure;

	/**/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
 	
	gpio_init_structure.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init_structure.GPIO_Pin = GPIO_Pin_5;
	gpio_init_structure.GPIO_Speed = GPIO_Speed_50MHz;	
 	GPIO_Init(GPIOB, &gpio_init_structure);

 	/**/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE); 
	
	gpio_init_structure.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init_structure.GPIO_Pin = GPIO_Pin_5;
	gpio_init_structure.GPIO_Speed = GPIO_Speed_50MHz;	
 	GPIO_Init(GPIOE, &gpio_init_structure); 		

 	/**/
 	led_control(_LED_0_, _LED_OFF_);
 	led_control(_LED_1_, _LED_OFF_);
}

/**/
void led_control(int led_name, int led_state)
{
	if(led_name == _LED_0_)
	{
		if(led_state == _LED_ON_)
		{
			GPIO_ResetBits(GPIOB, GPIO_Pin_5);
		}
		else
		{
			GPIO_SetBits(GPIOB, GPIO_Pin_5);
		}
	}
	else
	{
		if(led_state == _LED_ON_)
		{
			GPIO_ResetBits(GPIOE, GPIO_Pin_5);
		}
		else
		{
			GPIO_SetBits(GPIOE, GPIO_Pin_5);
		}
	}
}

