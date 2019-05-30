#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "uart.h"
#include "exti.h"
#include "timer.h"
#include "gpio_uart.h"


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


char gsrc_buf[1024];
char gdst_buf[1024];

 int main(void)
 {
 	uint32_t index = 0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);
	delay_init();

	for(index = 0; index < 1024; index ++)
	{
		gsrc_buf[index] = index;
	}
	memset(gdst_buf, 0, 1024);

	//dma_memcpy(gsrc_buf, gdst_buf, 1024);

	printf("dst:");
	for(index = 0; index < 1024; index ++)
	{
		printf("0x%02x ", gdst_buf[index]);
	}
	
	while(1)
	{
		printf("heello\r\n");
		delay_ms(1000);
	}

 
 #if 0
	uint8_t key_value = 0;
	uart_para_t uart_init_data;
	uint8_t index = 0;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
 
	delay_init();

	uart_init_data.baud = 9600;
	uart_init_data.parity = PARITY_NONE;
	uart_init_data.stop_bit = STOP_BIT_1;
	uart_init_data.word_length = WORD_LENGTH_8B;
	gpio_uart_init(&uart_init_data);

	while(1)
	{
		index = 0;
		for(index = 0; index < 255; index ++)
		{
			gpio_uart_senddata(index);
		}
		delay_ms(1000);
	}
	
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
#endif	
 }
