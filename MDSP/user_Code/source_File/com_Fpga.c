/*
 * com_Fpga.c
 *
 *  Created on: 2025年11月3日
 *      Author: yzy
 */
#include "com_Fpga.h"
#include <math.h>

void emif_429_Write()
{
	int i;
	for(i=0;i<100;i++)
	{
		((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x00080000))[i] = 0x5a5a;
	}
//	printf("429写数据完成！\n");
	Delay(0xffff);
}
void emif_429_Read(RESULT* result)
{
//	printf("开始读429数据....\n");
	unsigned short int temp;
	temp = (*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000a0000)));
	temp = (*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000c0000)));
	temp = (*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000e0000)));
	Delay(0xfff);
	temp = (*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000a0000)));
	temp = (*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000c0000)));
	temp = (*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000e0000)));
	Delay(0xfff);
	if((*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000a0000))) == (unsigned short int)0x5a5a||
		(*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000c0000))) == (unsigned short int)0x5a5a||
		(*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000e0000))) == (unsigned short int)0x5a5a)
	{
//		printf("DSP read fpga_429 test success!\n");
//		printf("429[1] = %d\n",*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000a0000)));
//		printf("429[2] = %d\n",*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000c0000)));
//		printf("429[3] = %d\n",*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000e0000)));
		result->M_fpga_429_channel1 = true;
		result->M_fpga_429_channel2 = true;
		result->M_fpga_429_channel3 = true;
	}
	else
	{
//		printf("DSP read fpga_429 test failure!\n");
//		printf("429[1] = %d\n",*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000a0000)));
//		printf("429[2] = %d\n",*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000c0000)));
//		printf("429[3] = %d\n",*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x000e0000)));
		result->M_fpga_429_channel1 = false;
		result->M_fpga_429_channel2 = false;
		result->M_fpga_429_channel3 = false;
	}
}
void emif_Read_Fpga_2991(RESULT* result)
{
	float fpga_tem1,fpga_tem2,fpga_vol1,fpga_vol2,fpga_vol3,fpga_vol4;
	fpga_tem1 = (*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x040000)) * 0.0625)-273.15;

	fpga_tem2 = (*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x040002)) * 0.0625)-273.15;

	fpga_vol1 = *((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x040004)) * 305.18 / 1000000;

	fpga_vol2 = *((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x040006)) * 305.18 / 1000000;

	fpga_vol3 = *((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x040008)) * 305.18 / 1000000;

	fpga_vol4 = *((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x04000a)) * 305.18 / 1000000;

//	printf("fpga_tem1:%.4f ℃\n",fpga_tem1);
//	printf("fpga_tem2:%.4f ℃\n",fpga_tem2);
//	printf("fpga_vol1:%.4f V\n",fpga_vol1);
//	printf("fpga_vol2:%.4f V\n",fpga_vol2);
//	printf("fpga_vol3:%.4f V\n",fpga_vol3);
//	printf("fpga_vol4:%.4f V\n",fpga_vol4);
	result->M_fpga_temperature_1 = ceil(fpga_tem1*10);
	result->M_fpga_temperature_2 = ceil(fpga_tem2*10);
	result->M_fpga_voltage_1 = ceil(fpga_vol1*100);
	result->M_fpga_voltage_2 = ceil(fpga_vol2*100);
	result->M_fpga_voltage_3 = ceil(fpga_vol3*100);
	result->M_fpga_voltage_4 = ceil(fpga_vol4*100);
}
void emif_print_soft_version(void)
{
	int i;
	char DSP_version[] = "\nDSP test software version is 1.0!\n";
	char FPGA_version[] = "\nFpga test software version is 1.0!\n";

	Delay(0xffff);


	for(i=0;i<strlen(DSP_version);i++)
	{
		*((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x60000)) = DSP_version[i];
	}
	Delay(0xffff);

	for(i=0;i<strlen(FPGA_version);i++)
	{
		*((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x60000)) = FPGA_version[i];
	}
}


