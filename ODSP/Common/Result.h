/*
 * Result.h
 *
 *  Created on: 2025Äê9ÔÂ22ÈÕ
 *      Author: yzy
 */

#ifndef RESULT_H_
#define RESULT_H_
#include "hw_types.h"
typedef struct result{
	unsigned short int zhenTou;
	volatile tBoolean uart_Test_Result;
	volatile tBoolean mcbsp_Test_Result;
	volatile tBoolean M_mcbsp_Test_Result;
	volatile tBoolean P_mcbsp_Test_Result;
	volatile tBoolean iic_Test_Result;
	volatile tBoolean emif_Test_Result;
	volatile tBoolean flash_Test_Result;
	volatile tBoolean nvram_Test_Result;
	volatile  unsigned short int voltage_1;
	volatile  unsigned short int voltage_2;
	volatile  unsigned short int voltage_3;
	volatile  unsigned short int voltage_4;
	volatile  unsigned short int temperature_1;
	volatile  unsigned short int temperature_2;
	unsigned short int zhenWei;
}RESULT;

#endif /* RESULT_H_ */
