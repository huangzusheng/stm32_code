#include "key.h"
#include "delay.h"
#include "stm32f10x.h"

void key_init(void)
{
	GPIO_InitTypeDef gpio_init_structure;

	/**/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
 	
	gpio_init_structure.GPIO_Mode = GPIO_Mode_IPU;
	gpio_init_structure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	gpio_init_structure.GPIO_Speed = GPIO_Speed_50MHz;	
 	GPIO_Init(GPIOE, &gpio_init_structure);
}



uint8_t key_scan(void)
{
	if((_KEY0_ == 0) || (_KEY1_ == 0) || (_KEY2_ == 0))
	{
		delay_ms(10);
		if(_KEY0_ == 0)
		{
			return _KEY0_PRESS_;
		}
		else if(_KEY1_ == 0)
		{
			return _KEY1_PRESS_;
		}
		else if(_KEY2_ == 0)
		{
			return _KEY2_PRESS_;
		}
	}

	return 0;
}
