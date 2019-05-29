#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "uart.h"
#include "exti.h"
#include "timer.h"


/************************************************
 ALIENTEK 战舰STM32F103开发板实验0
 工程模板
 注意，这是手册中的新建工程章节使用的main文件 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
 int main(void)
 {
	uint8_t key_value = 0;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
 
	delay_init();
	led_init();
	beep_init();
	key_init();
	//uart1_init();
	//exti_init();
	timer3_init(4999, 7999);

	while(1)
	{
#if 0	
		key_value = key_scan();
		if(key_value == _KEY0_PRESS_)
		{
			beep_control(_BEEP_ON_);
		}
		else if(key_value == _KEY1_PRESS_)
		{
			beep_control(_BEEP_OFF_);
		}
		else if(key_value == _KEY2_PRESS_)
		{
			//led_control(int led_name, int led_state)
		}
		delay_ms(100);
#endif		
	}
 }
