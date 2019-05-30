#ifndef __GPIO_UART_H__
#define __GPIO_UART_H__
#include "stdint.h"


/*
	��ע��void gpio_uart_senddata(uint16_t tx_data);uint16_t gpio_uart_recvdata(void);�Ĳ�������uint16_t����������
	��Ϊ������һ֡���ݵĴ��������ʱ9bit��uint8_t���͵����ݴ洢���¡�
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
#define PARITY_ODD		1	/*��У��*/
#define	PARITY_EVEN		2	/*żУ��*/

/**/
typedef struct _uart_para_{
	uint32_t baud;/*������*/
	uint32_t word_length;/*������ֳ�*/
	uint32_t stop_bit;/*ֹͣλ*/
	uint32_t parity;/*��żУ��*/
}uart_para_t;

/**/
void gpio_uart_init(uart_para_t *pUart_init_para);
void gpio_uart_senddata(uint16_t tx_data);
uint16_t gpio_uart_recvdata(void);


#endif/*__GPIO_UART_H__*/
