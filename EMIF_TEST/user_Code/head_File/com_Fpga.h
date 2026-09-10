/*
 * com_Fpga.h
 *
 *  Created on: 2025Äê11ÔÂ4ÈÕ
 *      Author: yzy
 */

#ifndef COM_FPGA_H_
#define COM_FPGA_H_
#include "stdio.h"
#include "soc_c6748.h"
#include "Result.h"

void emif_429_Write();
void emif_429_Read(RESULT* result);
void emif_Read_Fpga_2991(RESULT* result);

#endif /* COM_FPGA_H_ */
