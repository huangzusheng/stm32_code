#ifndef __GPIO_UART_H__
#define __GPIO_UART_H__
#include "stdint.h"


/*
	备注：void gpio_uart_senddata(uint16_t tx_data);uint16_t gpio_uart_recvdata(void);的参数都是uint16_t的数据类型
	因为可能在一帧数据的传输过程中时9bit。uint8_t类型的数据存储不下。
*/


/*baud*/
#define BAUD_115200		0
#define BAUD_9600		1

/*word_length*/
#define WORD_LENGTH_8B	0
#define WORD_LENGTH_9B	1

/*@word_length*/
#define STOP_BIT_1		0
#define STOP_BIT_1_5	1
#define STOP_BIT_2		2

/*parity*/
#define PARITY_NONE		0
#define PARITY_ODD		1	/*奇校验*/
#define	PARITY_EVEN		2	/*偶校验*/

/**/
typedef struct _uart_para_{
	uint32_t baud;/*波特率*/
	uint32_t word_length;/*传输的字长*/
	uint32_t stop_bit;/*停止位*/
	uint32_t parity;/*奇偶校验*/
}uart_para_t;

/**/
void gpio_uart_init(uart_para_t *pUart_init_para);
void gpio_uart_senddata(uint16_t tx_data);
uint16_t gpio_uart_recvdata(void);


#endif/*__GPIO_UART_H__*/
