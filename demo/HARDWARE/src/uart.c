#include "uart.h"
#include "stm32f10x.h"

void uart1_init(void)
{
	GPIO_InitTypeDef gpio_init_data;
	USART_InitTypeDef usart_init_data;
	NVIC_InitTypeDef nvic_init_data;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/**/
	gpio_init_data.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init_data.GPIO_Pin = GPIO_Pin_9;
	gpio_init_data.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &gpio_init_data);

	gpio_init_data.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_init_data.GPIO_Pin = GPIO_Pin_10;
	gpio_init_data.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &gpio_init_data);

	/**/
	usart_init_data.USART_BaudRate = 115200;
	usart_init_data.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usart_init_data.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	usart_init_data.USART_Parity = USART_Parity_No;
	usart_init_data.USART_StopBits = USART_StopBits_1;
	usart_init_data.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &usart_init_data);

	/**/
	nvic_init_data.NVIC_IRQChannel = USART1_IRQn;
	nvic_init_data.NVIC_IRQChannelCmd = ENABLE;
	nvic_init_data.NVIC_IRQChannelPreemptionPriority = 1;
	nvic_init_data.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&nvic_init_data);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

	/**/
	USART_Cmd(USART1, ENABLE);
	
}
void USART1_IRQHandler(void)
{
	uint8_t rx_data = 0;
	if(USART_GetITStatus(USART1, USART_IT_RXNE))
	{
		rx_data = USART_ReceiveData(USART1);
		USART_SendData(USART1, rx_data);
	}
}