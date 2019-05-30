#include "dma_mtom.h"
#include "stm32f10x.h"


/**/
static void dma_init(void)
{
	DMA_InitTypeDef dma_init_data;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	DMA_DeInit(DMA1_Channel1);

	/**/
	dma_init_data.DMA_BufferSize = 1000; /*先随便设置一个dma拷贝长度*/
	dma_init_data.DMA_DIR = DMA_DIR_PeripheralDST;
	dma_init_data.DMA_M2M = DMA_M2M_Enable;
	dma_init_data.DMA_MemoryBaseAddr = 0;
	dma_init_data.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	dma_init_data.DMA_MemoryInc = DMA_MemoryInc_Enable;
	dma_init_data.DMA_Mode = DMA_Mode_Normal;
	dma_init_data.DMA_PeripheralBaseAddr = 0;
	dma_init_data.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	dma_init_data.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	dma_init_data.DMA_Priority = DMA_Priority_High;
	DMA_Init(DMA1_Channel1, &dma_init_data);
}

/**/
void dma_memcpy(const void *src, void *det, uint16_t data_len)
{
	static uint8_t dma_init_flag = 0;

	if(dma_init_flag == 0)
	{
		dma_init();
		dma_init_flag = 1;
	}

	/**/
	DMA_SetCurrDataCounter(DMA1_Channel1, data_len);
	DMA_Cmd(DMA1_Channel1, ENABLE);

	while(DMA_GetCurrDataCounter(DMA1_Channel1) != 0);
}

