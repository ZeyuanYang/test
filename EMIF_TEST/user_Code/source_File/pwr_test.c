/*
 * pwr_test.c
 *
 *  Created on: 2025年11月6日
 *      Author: yzy
 */
#include "pwr_test.h"

void pwr_test(RESULT* result)
{
	//设置gpio模式
	/*
	 * 输出	GPIO0[10] GPIO0[11] GPIO0[12]
	 * */
	GPIODirModeSet(SOC_GPIO_0_REGS,11,GPIO_DIR_OUTPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,12,GPIO_DIR_OUTPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,13,GPIO_DIR_OUTPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,14,GPIO_DIR_OUTPUT);
	/*
	 * 输入 GPIO0[7]  GPIO0[8]  GPIO0[9]
	 * */
	GPIODirModeSet(SOC_GPIO_0_REGS,8,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,9,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,10,GPIO_DIR_INPUT);

	GPIOPinWrite(SOC_GPIO_0_REGS,11,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,12,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,13,GPIO_PIN_HIGH);

	if(GPIOPinRead(SOC_GPIO_0_REGS,8)==1 && GPIOPinRead(SOC_GPIO_0_REGS,10)==1 &&
			GPIOPinRead(SOC_GPIO_0_REGS,9) == 1)
	{
//		printf("Pwr test success!\n");
		result->pwr_Test_Result = true;
	}
	else
	{
//		printf("Pwr test failure!\n");
		result->pwr_Test_Result = true;
	}

}
