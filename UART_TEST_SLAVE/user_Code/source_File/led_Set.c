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
    GPIOPinWrite(SOC_GPIO_0_REGS,98, Flag);
	GPIOPinWrite(SOC_GPIO_0_REGS,11,Flag);
	GPIOPinWrite(SOC_GPIO_0_REGS,12,Flag);
	GPIOPinWrite(SOC_GPIO_0_REGS,13,Flag);
	GPIOPinWrite(SOC_GPIO_0_REGS,14,Flag);
}

void gpioReadSet(void)
{

}

void mcbsp_gpio_dir_set()
{
	GPIODirModeSet(SOC_GPIO_0_REGS,26,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,27,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,28,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,29,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,30,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,31,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,136,GPIO_DIR_INPUT);
}
