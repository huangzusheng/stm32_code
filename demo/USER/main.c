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
 ALIENTEK ս��STM32F103������ʵ��0
 ����ģ��
 ע�⣬�����ֲ��е��½������½�ʹ�õ�main�ļ� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
 int main(void)
 {
	uint8_t key_value = 0;
	uart_para_t uart_init_data;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
 
	delay_init();

	uart_init_data.baud = 115200;
	uart_init_data.parity = PARITY_NONE;
	uart_init_data.stop_bit = STOP_BIT_1;
	uart_init_data.word_length = WORD_LENGTH_8B;
	gpio_uart_init(&uart_init_data);

	while(1)
	{
		gpio_uart_senddata(0x0a);
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
 }
