/*
 * led_Set.c
 *
 *  Created on: 2025Äê10ÔÂ27ÈÕ
 *      Author: yzy
 */
#include "led_Set.h"

void gpioModeSet(void)
{
	GPIODirModeSet(SOC_GPIO_0_REGS, 98, GPIO_DIR_OUTPUT);
}

void gpioWriteSet(unsigned int Flag)
{
    GPIOPinWrite(SOC_GPIO_0_REGS, 98, Flag);
}

void gpioReadSet(void)
{

}


