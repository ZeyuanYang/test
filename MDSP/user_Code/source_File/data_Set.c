/*
 * data_Set.c
 *
 *  Created on: 2025Äê11ÔÂ6ÈÕ
 *      Author: yzy
 */
#include "data_Set.h"

void data_Set(RESULT* my_result)
{
	my_result->Frame_head = 0xA5A5;
	my_result->Frame_tail = 0xE5E5;
	my_result->ODSP_result_frame_head = 0xb1b1;
	my_result->ODSP_result_frame_tail = 0xb2b2;
	my_result->MDSP_result_frame_head = 0xc1c1;
	my_result->MDSP_result_frame_tail = 0xc2c2;
	my_result->PDSP_result_frame_head = 0xd1d1;
	my_result->PDSP_result_frame_tail = 0xd2d2;
	my_result->P_fpga_rsult_frame_head = 0xe1e1;
	my_result->P_fpga_rsult_frame_tail = 0xe2e2;
	my_result->m_fpga_result_frame_head = 0xf1f1;
	my_result->m_fpga_result_frame_tail = 0xf2f2;
}

void new_Data_Set(New_Result* my_result)
{
	my_result->Frame_head = 0xA3A3;
	my_result->Frame_tail = 0xA3A3;
	my_result->HXB_DSP_test_result_frame_head = 0xCCCC;
	my_result->HXB_DSP_test_result_frame_tail = 0xCCCC;
	my_result->HXB_FPGA_test_result_frame_head = 0xEEEE;
	my_result->HXB_FPGA_test_result_frame_tail = 0xEEEE;
}
