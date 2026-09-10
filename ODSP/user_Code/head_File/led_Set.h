/*
 * led_Set.h
 *
 *  Created on: 2025Äê10ÔÂ27ÈÕ
 *      Author: yzy
 */

#ifndef LED_SET_H_
#define LED_SET_H_

#include "gpio.h"
#include "soc_C6748.h"

void gpioModeSet(void);

void gpioWriteSet(unsigned int Flag);

void gpioReadSet(void);



#endif /* LED_SET_H_ */
