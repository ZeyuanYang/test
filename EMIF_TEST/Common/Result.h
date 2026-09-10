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
	volatile tBoolean spi_Test_Result;
	volatile tBoolean spi_HI8435_Test_Result;
	volatile tBoolean emif_Test_Result;
	volatile tBoolean flash_Test_Result;
	volatile tBoolean pwr_Test_Result;
	volatile tBoolean p_fpga_lisanliang;
	volatile tBoolean P_fpga_429_channel;
	volatile tBoolean P_fpga_mcbsp;
	volatile unsigned short int p_fpga_voltage_1;
	volatile unsigned short int p_fpga_voltage_2;
	volatile unsigned short int p_fpga_voltage_3;
	volatile unsigned short int p_fpga_voltage_4;
	volatile unsigned short int p_fpga_temperature_1;
	volatile unsigned short int p_fpga_temperature_2;

	unsigned short int zhenWei;
}RESULT;

#endif /* RESULT_H_ */
