#ifndef __KEY_H__
#define __KEY_H__
#include "stdint.h"

#define _KEY0_ GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)
#define _KEY1_ GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)
#define _KEY2_ GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)

#define _KEY0_PRESS_	1
#define _KEY1_PRESS_	2
#define _KEY2_PRESS_	3


/**/
void key_init(void);
uint8_t key_scan(void);

#endif/*__KEY_H__*/
