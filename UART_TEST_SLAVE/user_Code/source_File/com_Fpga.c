/*
 * com_Fpga.c
 *
 *  Created on: 2025年11月4日
 *      Author: yzy
 */
#include "com_Fpga.h"
#include <math.h>

void emif_429_Write()
{
	int i;
	for(i=0;i<100;i++)
	{
		((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x00080000))[i] = 0xA5A5;

	}
	printf("429写数据完成！\n");
}

void emif_429_Read(RESULT* result)
{
	unsigned short int temp;
//	printf("开始读429数据...\n");
	temp = (*((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x00a0000)));
	Delay(0xfff);
	temp = (*((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x00a0000)));
	Delay(0xfff);
	if((*((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x00a0000))) == (unsigned short int)0xA5A5)
	{
		printf("DSP read fpga_429 test success!\n");
		printf("429 read  = %d\n",*((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x00a0000)));
		result->P_fpga_429_channel = true;
	}
	else
	{
		printf("DSP read fpga_429 test failure!\n");
		printf("429 read  = %d\n",*((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x00a0000)));
		result->P_fpga_429_channel = false;
	}
}


void emif_Read_Fpga_2991(RESULT* result)
{
	float fpga_temp1,fpga_temp2,fpga_vol1,fpga_vol2,fpga_vol3,fpga_vol4;
	fpga_temp1 =(*((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x040000)) * 0.0625) - 273.15;

//	fpga_temp2 =( *((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x040002)) * 0.0625) - 273.15;

	fpga_vol1 = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x040004)) * 305.18 / 1000000;

	fpga_vol2 = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x040006)) * 305.18 / 1000000;

	fpga_vol3 = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x040008)) * 305.18 / 1000000;

	fpga_vol4 = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR + 0x04000a)) * 305.18 / 1000000;

//	printf("fpga_tem1:%.4f ℃\n",fpga_temp1);
////	printf("fpga_tem2:%.4f ℃\n",fpga_temp2);
//	printf("fpga_vol1:%.4f V\n",fpga_vol1);
//	printf("fpga_vol2:%.4f V\n",fpga_vol2);
//	printf("fpga_vol3:%.4f V\n",fpga_vol3);
//	printf("fpga_vol4:%.4f V\n",fpga_vol4);
	result->p_fpga_temperature_1 = ceil(fpga_temp1*10);
//	result->p_fpga_temperature_2 = fpga_temp2;
	result->p_fpga_voltage_1 = ceil(fpga_vol1*100);
	result->p_fpga_voltage_2 = ceil(fpga_vol2*100);
	result->p_fpga_voltage_3 = ceil(fpga_vol3*100);
	result->p_fpga_voltage_4 = ceil(fpga_vol4*100);
}
