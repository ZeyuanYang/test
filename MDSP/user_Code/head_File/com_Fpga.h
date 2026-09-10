/*
 * com_Fpga.h
 *
 *  Created on: 2025年11月3日
 *      Author: yzy
 */
#include "stdio.h"
#include "soc_C6748.h"			    // DSP C6748 外设寄存器
#include "Result.h"
#ifndef COM_FPGA_H_
#define COM_FPGA_H_

void emif_429_Write();

void emif_429_Read(RESULT* result);

void emif_Read_Fpga_2991(RESULT* result);

#endif /* COM_FPGA_H_ */
