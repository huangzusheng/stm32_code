#include "gpio_uart.h"
#include "stm32f10x.h"
#include "delay.h"


/*串口的默认参数配置*/
static uart_para_t ggpio_uart = {BAUD_115200, WORD_LENGTH_8B, STOP_BIT_1, PARITY_NONE};


/**/
void gpio_uart_init(uart_para_t *puart_init_para)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	/*参数的校验*/

	/**/
	ggpio_uart.baud = puart_init_para->baud;
	ggpio_uart.word_length = puart_init_para->word_length;
	ggpio_uart.stop_bit = puart_init_para->stop_bit;
	ggpio_uart.parity = puart_init_para->parity;

	/*gpio初始化*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}


/**/
void gpio_uart_senddata(uint16_t tx_data)
{
	uint32_t delay_time_us = 0;
	uint8_t bit_length = 8;
	uint32_t index = 0;
	uint16_t tmp_data = 0;

	/**/
	delay_time_us = 1000000/ggpio_uart.baud;
	if(ggpio_uart.word_length == WORD_LENGTH_9B)
	{
		bit_length = 9;
	}
	else
	{
		bit_length = 8;
	}

	/**/
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	delay_us(delay_time_us);

	for(index = 0; index < bit_length; index ++)
	{
		tmp_data = (tx_data >> index);
		if(tmp_data & 0x1)
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_9);
		}
		else
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_9);
		}
		delay_us(delay_time_us);
	}

	/**/
	if(ggpio_uart.parity == PARITY_EVEN)
	{

	}
	else if(ggpio_uart.parity == PARITY_ODD)
	{

	}

	/**/
	GPIO_SetBits(GPIOA, GPIO_Pin_9);
	if(ggpio_uart.stop_bit == STOP_BIT_2)
	{
		delay_us(delay_time_us*2);
	}
	else if(ggpio_uart.stop_bit == STOP_BIT_1_5)
	{
		delay_us(delay_time_us*3/2);
	}
	else
	{
		delay_us(delay_time_us);
	}
}


/**/
uint16_t gpio_uart_recvdata(void)
{
	return 0;
}

