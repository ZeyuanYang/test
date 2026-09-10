/*
 * nvram_Set.c
 *
 *  Created on: 2025年10月21日
 *      Author: yzy
 */
#include "nvram_Set.h"
#include "stdio.h"


int nvram_Write_test(unsigned int Address,unsigned int Data_length)
{
	unsigned int i;
	unsigned short int test_num = 0;
	if(Data_length>64*1024*8)
	{
		printf("NVRAM写入数据长度超限！\n");
		return -1;
	}

	for(i=0;i<Data_length;i++)
	{
		((unsigned short int*)(SOC_EMIFA_CS3_ADDR+Address))[i] = test_num;
//		 nvram_order_set();
		if(test_num == 0xffff)
		{
			test_num = 0;
		}
		test_num += 0x0101;
	}
	return 0;
}


int nvram_Read_test(unsigned int Address,unsigned int Data_length,RESULT* result)
{
	unsigned int i,err_count=0;
	unsigned short int test_num = 0;
	if(Data_length>64*1024*8)
	{
		printf("NVRAM读取数据长度超限！\n");
		return -1;
	}
	for(i=0;i<Data_length;i++)
	{

		if(*((unsigned short int*)(SOC_EMIFA_CS3_ADDR+Address+2*i)) != test_num)
		{
			err_count++;
		}
		if(test_num == 0xffff)
		{
			test_num = 0;
		}
		test_num += 0x0101;
//		printf("%d\n",((unsigned short int*)(SOC_EMIFA_CS3_ADDR+Address))[i]);
		if(err_count)
		{
			printf("NVRAM写读数据测试失败！\n");
			return -1;
		}
	}
//	result->nvram_Test_Result = true;
	printf("NVRAM测试成功！\n");
	return 0;
}

/*
 1. Read address 0x4E38 Valid READ
 2. Read address 0xB1C7 Valid READ
 3. Read address 0x83E0 Valid READ
 4. Read address 0x7C1F Valid READ
 5. Read address 0x703F Valid READ
 6. Read address 0x8FC0 Initiate STORE cycle
 * */
void nvram_order_set(void)
{
	int temp;
	temp = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x4e38));

	temp = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0xb1c7));

	temp = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x83e0));

	temp = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x7c1f));

	temp = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x703f));

	temp = *((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x8fc0));
//	printf("temp = %d\n",temp);
}

void nvram_test(RESULT* result)
{

	nvram_Write_test(0,1024);
	nvram_Read_test(0,1024,result);
}


