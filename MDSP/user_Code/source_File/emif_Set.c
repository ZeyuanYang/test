/*
 * emif_Test.c
 *
 *  Created on: 2025年9月24日
 *      Author: 18832
 */

#include "emif_Set.h"
#include "stdio.h"
#include <stdlib.h>
#include <stdint.h>

#define EMIF_BUFFER_LENGTH 3072
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
						   EMIFA_ASYNC_WAITTIME_CONFIG(2, 5, 2, 2, 5, 2, 1 ));
	//1, 1, 2, 2, 2, 1, 0
}


/*函数名称：crc_cal_by_halfbyte:按半字节计算CRC
  函数参数：uint8_t* ptr:指向发送缓冲区的首字节
            uint32_t len:要发送的总字节数
  函数返回值：uint16_t
  多项式采用CRC-CCITT  0x1021
*/
const unsigned short int crc_ta_4[16]={ /* CRC 半字节余式表 */
    0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
    0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
};

unsigned short int crc_cal_by_halfbyte(unsigned char* ptr, unsigned int  len)
{
	unsigned short int  crc = 0xffff;

    while(len-- != 0)
    {
    	unsigned char high = (unsigned char)(crc/4096); //暂存CRC的高4位
        crc <<= 4;
        crc ^= crc_ta_4[high^(*ptr/16)];

        high = (unsigned char)(crc/4096);
        crc <<= 4;
        crc ^= crc_ta_4[high^(*ptr&0x0f)];

        ptr++;
    }

    return crc;
}


//void read_txt()
//{
//    file = fopen("rom_data_dsp.txt", "r");
//    if (file == NULL) {
//            printf("无法打开文件 %s\n", filename);
//            return 1;
//        }
//
//}


void emif_Test(RESULT* result)
{

    FILE *file;
    char line[256];
    int count = 0;


	char emif_result1[] = "Emif test success!\n";
	char emif_result2[] = "Emif test failure!\n";
	unsigned short int read_crc,write_crc;
//	unsigned short int fpgatest;
	unsigned short int test_num = 0x0000;
	short int* temp;
	unsigned short int i,j;// emif_wbuffer[EMIF_BUFFER_LENGTH];
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

//	signed short int *emif_read_buffer = (signed short int*)malloc(EMIF_BUFFER_LENGTH*2);
//    if (emif_read_buffer == NULL) {
//        fprintf(stderr, "Memory allocation failed!\n");
//    }
//
//	for(i=0;i<EMIF_BUFFER_LENGTH;i++)
//	{
//		((signed short int *)emif_read_buffer)[i] = ((signed short int *)(SOC_EMIFA_CS3_ADDR+0x100000))[i];
//	}
//	//计算crc
//
//	read_crc = crc_cal_by_halfbyte((unsigned char*)emif_read_buffer,EMIF_BUFFER_LENGTH*2);
//
//
//	//从本地读取数据
//	if ((file = fopen("rom_data_dsp.txt", "rb")) == NULL)
//	{
//		printf("Open rom_data_dsp.txt fail!\n");
//		fclose(file);
//	}
//    temp = (short int*)emif_read_buffer;
//
//
//    while (count< EMIF_BUFFER_LENGTH&&fgets(line, sizeof(line), file)) {
//           // 使用sscanf提取逗号前的整数
//           if (sscanf(line, "%hd,", (short int *)(temp++)) == 1) {
//               count++;
//           } else {
//               printf("第 %d 行格式错误: %s", count + 1, line);
//           }
//       }
//
//    //计算初始数据crc校验
//    write_crc = crc_cal_by_halfbyte((unsigned char*)emif_read_buffer,EMIF_BUFFER_LENGTH*2);
//
//    free(emif_read_buffer);
//    if(write_crc == read_crc)
//    {
//    	printf("emif读写fpga测试成功！\n");
//    }
//    else
//    {
//    	printf("emif读写fpga测试失败！\n");
//    }

//    //写数据
//	signed short int *emif_read_buffer = (signed short int*)malloc(EMIF_BUFFER_LENGTH*2);
//    if (emif_read_buffer == NULL)
//    {
//        fprintf(stderr, "Memory allocation failed!\n");
//    }
//    temp = (short int*)emif_read_buffer;
//
//	//从本地读取数据
//	if ((file = fopen("rom_data_dsp.txt", "rb")) == NULL)
//	{
//		printf("Open rom_data_dsp.txt fail!\n");
//		fclose(file);
//	}
//
//    while (count < EMIF_BUFFER_LENGTH&&fgets(line, sizeof(line), file))
//    {
//	   // 使用sscanf提取逗号前的整数
//	   if (sscanf(line, "%hd,", (short int *)(temp++)) == 1) {
//		   count++;
//	   } else {
//		   printf("第 %d 行格式错误: %s", count + 1, line);
//	   }
//    }
//
//    //计算写数据crc
//    write_crc = crc_cal_by_halfbyte((unsigned char*)emif_read_buffer,EMIF_BUFFER_LENGTH*2);
//
//
//    //写入内存
//	for(i=0;i<EMIF_BUFFER_LENGTH;i++)
//	{
//	    ((signed short int *)(SOC_EMIFA_CS3_ADDR))[i] = ((signed short int *)emif_read_buffer)[i];
//	}
//
//	memset(emif_read_buffer,0,EMIF_BUFFER_LENGTH*2);
//    //读fpga数据
//
//	for(i=0;i<EMIF_BUFFER_LENGTH;i++)
//	{
//		((signed short int *)emif_read_buffer)[i] = ((signed short int *)(SOC_EMIFA_CS3_ADDR))[i];
//	}
//	//计算读数据crc
//	read_crc = crc_cal_by_halfbyte((unsigned char*)emif_read_buffer,EMIF_BUFFER_LENGTH*2);
//
//	free(emif_read_buffer);
//    if(write_crc == read_crc)
//	{
//		printf("emif读写fpga测试成功！\n");
//	}
//	else
//	{
//		printf("emif读写fpga测试失败！\n");
//	}
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
//		printf("EMIF写读fpga测试失败!\n");
		result->MDSP_emif_Test_Result = false;
//		printf("打印读取到的数据:\n");
//		for(i=0;i<EMIF_BUFFER_LENGTH;i++)
//		{
//			printf("%d   ",emif_rbuffer[i]);
//		}
//		printf( "EMIFA_error_count=%d\n",EMIFA_error_count);
//		while(1);
	}
	else
	{
//		printf("EMIF写读fpga测试成功!\n");
		result->MDSP_emif_Test_Result = true;
	}
}

