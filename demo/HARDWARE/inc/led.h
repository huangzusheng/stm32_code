#ifndef __LED_H__
#define __LED_H__


#define _LED_0_		0
#define _LED_1_		1

#define _LED_ON_	0
#define _LED_OFF_	1

/**/
void led_init(void);
void led_control(int led_name, int led_state);

#endif/*__LED_H__*/
