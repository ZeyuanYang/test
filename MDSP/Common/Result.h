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
	volatile unsigned short int Frame_head; //0xA5A5

	volatile unsigned short int ODSP_result_frame_head; //0xb1b1
	volatile tBoolean ODSP_uart_Test_Result;
	volatile tBoolean ODSP_mcbsp_Test_Result;
	volatile tBoolean ODSP_IIC_Test_Result;
	volatile tBoolean ODSP_emif_Test_Result;
	volatile tBoolean ODSP_flash_Test_Result;
	volatile tBoolean ODSP_NVRAM_Test_Result;
	volatile  unsigned short int ODSP_voltage_1;
	volatile  unsigned short int ODSP_voltage_2;
	volatile  unsigned short int ODSP_voltage_3;
	volatile  unsigned short int ODSP_voltage_4;
	volatile  unsigned short int ODSP_temperature_1;
	volatile  unsigned short int ODSP_temperature_2;
	volatile unsigned short int ODSP_result_frame_tail; //0xb2b2

	volatile unsigned short int MDSP_result_frame_head; //0xc1c1
	volatile tBoolean MDSP_uart_Test_Result;
	volatile tBoolean MDSP_mcbsp_Test_Result;
	volatile tBoolean MDSP_emif_Test_Result;
	volatile tBoolean MDSP_flash_Test_Result;
	volatile unsigned short int MDSP_result_frame_tail; //0xc2c2

	volatile unsigned short int PDSP_result_frame_head; //0xd1d1
	volatile tBoolean PDSP_uart_Test_Result;
	volatile tBoolean PDSP_mcbsp_Test_Result;
	volatile tBoolean PDSP_spi_Test_Result;
	volatile tBoolean PDSP_spi_HI8435_Test_Result;
	volatile tBoolean PDSP_emif_Test_Result;
	volatile tBoolean PDSP_flash_Test_Result;
	volatile tBoolean PDSP_power_Test_Result;
	volatile unsigned short int PDSP_result_frame_tail; //0xd2d2

	volatile unsigned short int P_fpga_rsult_frame_head; //0xe1e1
	volatile tBoolean P_fpga_429_channel1;
	volatile tBoolean p_fpga_lisanliang;
	volatile tBoolean P_fpga_mcbsp;
	volatile  unsigned short int P_fpga_voltage_1;
	volatile  unsigned short int P_fpga_voltage_2;
	volatile  unsigned short int P_fpga_voltage_3;
	volatile  unsigned short int P_fpga_voltage_4;
	volatile  unsigned short int P_fpga_temperature_1;
	volatile unsigned short int P_fpga_rsult_frame_tail; //0xe2e2

	volatile unsigned short int m_fpga_result_frame_head; //0xf1f1
	volatile tBoolean M_fpga_429_channel1;
	volatile tBoolean M_fpga_429_channel2;
	volatile tBoolean M_fpga_429_channel3;
	volatile tBoolean M_fpga_pwr_test;
	volatile tBoolean M_fpga_lisanliang;
	volatile tBoolean M_fpga_mcbsp;
	volatile  unsigned short int M_fpga_voltage_1;
	volatile  unsigned short int M_fpga_voltage_2;
	volatile  unsigned short int M_fpga_voltage_3;
	volatile  unsigned short int M_fpga_voltage_4;
	volatile  unsigned short int M_fpga_temperature_1;
	volatile  unsigned short int M_fpga_temperature_2;
	volatile unsigned short int m_fpga_result_frame_tail; //0xf2f2
	volatile unsigned short int Frame_tail; //0xE5E5
}RESULT;

typedef struct new_result
{
		volatile unsigned short int Frame_head; //0xA5A5
		volatile unsigned short int HXB_DSP_test_result_frame_head; //0xcccc
		volatile tBoolean DSP_MCBSP_Test_Result;
		volatile tBoolean DSP_UART_Test_Result;
		volatile tBoolean DSP_IIC_Test_Result;
		volatile tBoolean DSP_EMIF_Test_Result;
		volatile tBoolean DSP_SPI_Test_Result;
		volatile tBoolean DSP_SPI_HI8435_Test_Result;
		volatile tBoolean DSP_POWER_Test_Result;
		volatile tBoolean DSP_NVRAM_Test_Result;
		volatile tBoolean DSP_FLASH_Test_Result;
		volatile unsigned short int HXB_DSP_test_result_frame_tail; //0xeeee

		volatile unsigned short int HXB_FPGA_test_result_frame_head; //0xcccc
		volatile tBoolean FPGA_429_Test_Result;
		volatile tBoolean FPGA_pwr_Test_Result;
		volatile tBoolean FPGA_lisanliang_Test_Result;
		volatile unsigned short int HXB_FPGA_test_result_frame_tail; //0xeeee

		volatile unsigned short int Frame_tail; //0xE5E5

}New_Result;


#endif /* RESULT_H_ */
