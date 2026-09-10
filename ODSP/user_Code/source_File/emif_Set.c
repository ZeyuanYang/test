/*
 * emif_Test.c
 *
 *  Created on: 2025年9月24日
 *      Author: 18832
 */

#include "emif_Set.h"
#include "stdio.h"
#define EMIF_BUFFER_LENGTH 1024
void EMIFASetup(void)
{
	/*配置EMIFA相关复用引脚*/
	EMIFAPinMuxSetup();

	/*配置数据总线16bit*/
	EMIFAAsyncDevDataBusWidthSelect(SOC_EMIFA_0_REGS,EMIFA_CHIP_SELECT_3,
									EMIFA_DATA_BUSWITTH_16BIT);

	/*选着Normal模式*/
	EMIFAAsyncDevOpModeSelect(SOC_EMIFA_0_REGS,EMIFA_CHIP_SELECT_3,
							   EMIFA_ASYNC_INTERFACE_NORMAL_MODE);

	/*禁止WAIT引脚*/
	EMIFAExtendedWaitConfig(SOC_EMIFA_0_REGS,EMIFA_CHIP_SELECT_3,
							 EMIFA_EXTENDED_WAIT_DISABLE);

	/*配置W_SETUP/R_SETUP   W_STROBE/R_STROBE    W_HOLD/R_HOLD	TA等参数*/
	EMIFAWaitTimingConfig(SOC_EMIFA_0_REGS,EMIFA_CHIP_SELECT_3,
						   EMIFA_ASYNC_WAITTIME_CONFIG(2, 4, 2, 2, 4, 2, 0 ));
	//1, 1, 2, 2, 2, 1, 0
}

void emif_Test(RESULT* result)
{
//	unsigned short int fpgatest;
	unsigned short int test_num = 0x0000;
	unsigned short int i, emif_wbuffer[EMIF_BUFFER_LENGTH];
	unsigned short int  emif_rbuffer[EMIF_BUFFER_LENGTH];
	volatile int EMIFA_error_count = 0;
	EMIFASetup();
	while(test_num<0xffff)
	{
		//对FPGA进行循环写读测试
		for(i=0;i<EMIF_BUFFER_LENGTH;i++)
		{
			((unsigned short int *)(SOC_EMIFA_CS3_ADDR))[i] = test_num;
		}

		//读
		for (i = 0; i < EMIF_BUFFER_LENGTH; i++)
		{
		   emif_rbuffer[i] = ((unsigned short int*)(SOC_EMIFA_CS3_ADDR))[i];
		}
		//测试
		for (i = 0; i<EMIF_BUFFER_LENGTH; i++)
		{
			if (test_num != emif_rbuffer[i])
			{
				EMIFA_error_count++;
			}
		}
		if(EMIFA_error_count)
		{
			break;
		}

		test_num += 0x101;
	}

//	{
//		//Fpga ceshi
//		*((short int*)(SOC_EMIFA_CS3_ADDR + 0x4000+1)) = 0x55;
//		fpgatest = *((short int*)(SOC_EMIFA_CS3_ADDR + 0x4000+1));
//		printf("fpgatest = %d\n",fpgatest);
//		*((short int*)(SOC_EMIFA_CS3_ADDR + 0x4800+1)) = 0x55;
//		fpgatest = *((short int*)(SOC_EMIFA_CS3_ADDR + 0x4800+1));
//		printf("fpgatest = %d\n",fpgatest);
//		*((short int*)(SOC_EMIFA_CS3_ADDR + 0x5000+1)) = 0x55;
//		fpgatest = *((short int*)(SOC_EMIFA_CS3_ADDR + 0x5000+1));
//		printf("fpgatest = %d\n",fpgatest);
//		*((short int*)(SOC_EMIFA_CS3_ADDR + 0x5800+1)) = 0x55;
//		fpgatest = *((short int*)(SOC_EMIFA_CS3_ADDR + 0x5800+1));
//		printf("fpgatest = %d\n",fpgatest);
//		*((short int*)(SOC_EMIFA_CS3_ADDR + 0x6000+1)) = 0x55;
//		fpgatest = *((short int*)(SOC_EMIFA_CS3_ADDR + 0x6000+1));
//		printf("fpgatest = %d\n",fpgatest);
//		*((short int*)(SOC_EMIFA_CS3_ADDR + 0x6800+1)) = 0x55;
//		fpgatest = *((short int*)(SOC_EMIFA_CS3_ADDR + 0x6800+1));
//		printf("fpgatest = %d\n",fpgatest);
//	}

	/* 报告通信结果*/
	if (EMIFA_error_count)
	{
		printf("EMIF写读fpga测试失败!\n");
		result->emif_Test_Result = false;
		printf("打印读取到的数据:\n");
		for(i=0;i<EMIF_BUFFER_LENGTH;i++)
		{
			printf("%d   ",emif_rbuffer[i]);
		}
		printf( "EMIFA_error_count=%d\n",EMIFA_error_count);
//		while(1);
	}
	else
	{
		printf("EMIF写读fpga测试成功!\n");
		result->emif_Test_Result = true;
	}
}

