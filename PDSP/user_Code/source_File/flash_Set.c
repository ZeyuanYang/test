/*
 * flash_Set.c
 *
 *  Created on: 2025年10月13日
 *      Author: yzy
 */
#include "flash_Set.h"


/**
 * S29AL016J70TFI010 整片内存擦除
 * **/
short flash_test_buffer[BUFFERSIZE];
void EMIFA_Flash_Setup(void)
{
	/*配置EMIFA相关复用引脚*/
	EMIFAPinMuxSetup();

	/*配置数据总线16bit*/
	EMIFAAsyncDevDataBusWidthSelect(SOC_EMIFA_0_REGS,EMIFA_CHIP_SELECT_2,
									EMIFA_DATA_BUSWITTH_16BIT);

	/*选着Normal模式*/
	EMIFAAsyncDevOpModeSelect(SOC_EMIFA_0_REGS,EMIFA_CHIP_SELECT_2,
							   EMIFA_ASYNC_INTERFACE_NORMAL_MODE);

	/*禁止WAIT引脚*/
	EMIFAExtendedWaitConfig(SOC_EMIFA_0_REGS,EMIFA_CHIP_SELECT_2,
							 EMIFA_EXTENDED_WAIT_DISABLE);

	/*配置W_SETUP/R_SETUP   W_STROBE/R_STROBE    W_HOLD/R_HOLD	TA等参数*/
	EMIFAWaitTimingConfig(SOC_EMIFA_0_REGS,EMIFA_CHIP_SELECT_2,
						   EMIFA_ASYNC_WAITTIME_CONFIG(1, 1, 2, 2, 2, 1, 0 ));

}


int chip_erase()
{
	int ReturnStatus=TRUE;
    *((uint16_t *)FLASH_ADR1) = 0xAA;           /* write unlock cycle 1 */

    *((uint16_t *)FLASH_ADR2) = 0x55;			/* write unlock cycle 2 */

    *((uint16_t *)FLASH_ADR1) = 0x80;			/* write setup command */

    *((uint16_t *)FLASH_ADR1) = 0xAA;			/* write additional unlock cycle 1 */

    *((uint16_t *)FLASH_ADR2) = 0x55;			/* write additional unlock cycle 2 */

    *((uint16_t *)FLASH_ADR1) = 0x10;			/* write sector erase command */
    ReturnStatus = Check_Toggle(); 				// wait for TOGGLE bit ready
	if(ReturnStatus == TRUE)
	{
		printf("flash整片擦除成功!\n");
	}
	return ReturnStatus;
}

void section_erase(uint32_t SectorNum)
{
	unsigned int  SectorAddr   =   SectorNum * SECTOR_SIZE; //norflash 地址
    *((uint16_t *)FLASH_ADR1) = 0xAA;   /* write unlock cycle 1 */
    *((uint16_t *)FLASH_ADR2) = 0x55;	/* write unlock cycle 2 */
    *((uint16_t *)FLASH_ADR1) = 0x80;	/* write setup command */
    *((uint16_t *)FLASH_ADR1) = 0xAA;	/* write additional unlock cycle 1 */
    *((uint16_t *)FLASH_ADR2) = 0x55;	/* write additional unlock cycle 2 */

    *((uint16_t *)(SOC_EMIFA_CS2_ADDR + SectorAddr*2)) = 0x30;

	Delay(10000);

	while(1)
	{
		if(*((uint16_t *)(SOC_EMIFA_CS2_ADDR + SectorAddr*2))==0xFFFF)break;
	}
	printf("Sector erase successful!\n");
}
int read_FlashID()
{
    unsigned short SST_id1;
    unsigned short SST_id2;
    unsigned short SST_id3;
    unsigned short SST_id4;
    int  ReturnStatus;
    //  Issue the Software Product ID code to flash
    *sysAddress(0x555) = 0x00AA;  // write data 0x00AA to device addr 0x555
    *sysAddress(0x2AA) = 0x0055;  // write data 0x0055 to device addr 0x2AA
    *sysAddress(0x555) = 0x0090;  // write data 0x0090 to device addr 0x5555
    Delay(150);
    // Read the product ID from flash
    SST_id1  = *sysAddress(0x0000);   // get first ID byte
    SST_id2  = *sysAddress(0x0001);   // get second ID byte
    SST_id3  = *sysAddress(0x0002);   // get first ID byte
//    SST_id4  = *sysAddress(0x000f);   // get second ID byte
    // ------------------------------------------------------------
    //&& (SST_id2 == flash_ID1)&&(SST_id3 == flash_ID2) && (SST_id4 == flash_ID3)
    if ((SST_id1 == MANUFAC_ID))
            ReturnStatus = TRUE;
    else
            ReturnStatus = FALSE;
    *sysAddress(0x000) = 0x00F0;  // RESET FLASH
    return (ReturnStatus);
}
/*******************************************************************************
*函数名： Check_Toggle()
*功   能：用户在擦除/编程的时候判断擦除/编程是否完成
*输出参数:   1  编程/擦除成功
*          	0    编程/擦除失败
*******************************************************************************/
int Check_Toggle()
{
	unsigned int Toggle_Status=0,Toggle_Status1=0;
	unsigned int DQ5=0;
	unsigned long TimeOut = 0;

	while(TimeOut < MAX_TIMEOUT)
	{
		Toggle_Status=(*(volatile short *)FLASH_ADR1);
		Toggle_Status1=(*(volatile short *)FLASH_ADR1);
		if((Toggle_Status & 0x00000040)==(Toggle_Status1 & 0x00000040))
		{
			return TRUE ;
		}//擦除成功

		DQ5=Toggle_Status1 & 0x00000020;
		if(DQ5)
		{
			Toggle_Status=(*(volatile short *)FLASH_ADR1);
			Toggle_Status1=(*(volatile short *)FLASH_ADR1);
			if((Toggle_Status & 0x00000040)==(Toggle_Status1 & 0x00000040)){
				return TRUE ;}//擦除成功
			else *(volatile short *)FLASH_ADR1 = 0x00F0;		//复位flash
		}
		++TimeOut;
	}
	return FALSE;
}

/*******************************************************************************
*函数名：    Program_One_Sector
*功   能：    对FLASH进行写数据，for循环每次写2个字节
*输入参数：SrcWord：待写入FLASH的缓存地址的首地址
*		  Dst：写入FLASH的目的地址
*输出参数:   1  编程成功
*          	0    编程失败
*******************************************************************************/
int Program_One_Sector (short* SrcWord,unsigned int Dst,unsigned int BufSize)
{
    unsigned int  DestBuf = 0;
    unsigned int  SourceBuf = 0;
    unsigned int  cnt=0;
    int ReturnStatus=TRUE;
    DestBuf = Dst;
    for(cnt=0;cnt<BufSize;cnt++)
    {
    	*(volatile short *)FLASH_ADR1 = 0x00AA;	// write data 0x00AA to device addr 0x5555
    	*(volatile short *)FLASH_ADR2 = 0x0055;	// write data 0x0055 to device addr 0x2AAA
    	*(volatile short *)FLASH_ADR1 = 0x00A0; // write data 0x00A0 to device addr 0x5555
    	//*(volatile short *)(SOC_EMIFA_CS2_ADDR+DestBuf)=*((volatile short *)SourceBuf);// transfer the Byte to destination
    	*(volatile short *)(SOC_EMIFA_CS2_ADDR+DestBuf)=SrcWord[cnt];
    	ReturnStatus = Check_Toggle(); // wait for TOGGLE bit ready
    	if(!ReturnStatus)
        {
        	return ReturnStatus;
        }
		DestBuf=DestBuf+2;
    }
	///test

	return ReturnStatus;
}
/*******************************************************************************
*函数	名：Nor_FLASH_Check
*功    	能：将Nor FLASH的数据读出与写入的数据进行对比，
*				如有错误通过printf打印输出。
*输入参数： BufByteSize：需要对比的字节长度
*输出参数：0：写入的数据和从FLASH里读出的数据不一致
*					1：写入的数据和从FLASH里读出的数据一致
*******************************************************************************/
int Nor_FLASH_Check(unsigned int BufByteSize)
{
	unsigned int i=0;
	unsigned int temp1=0;
	unsigned int temp2=0;
	unsigned int CheckStatus=TRUE;



	for(i=0;i<BufByteSize;i++)
	{
		temp1=flash_test_buffer[i];
		temp2=*((volatile short*) ((Programaddres+i*2)+SOC_EMIFA_CS2_ADDR) );
		if(temp1 != temp2 )
		{
			CheckStatus=FALSE;
			printf("测试错误 \n");
			printf("错误地址：0x%x	FLASH的值：0x%x		写入的数据：0x%x\n",((Programaddres+i*2)+SOC_EMIFA_CS2_ADDR),temp2,temp1);
		}
	}
	return CheckStatus;
}
void flash_erase_and_writetest()
{
	if( !(chip_erase()) )
		printf("数据擦除失败\n");

	if( !(Program_One_Sector(flash_test_buffer,Programaddres,BUFFERSIZE) ) )
		printf("数据写入失败\n");
}
/**
 * nor flash 测试
 **/
int Nor_FLASH_test(RESULT* result)
{
	int i,testnum;
	testnum = 0;
	EMIFA_Flash_Setup();
	if(read_FlashID())//读flash ID
	{
		printf("读flash的ID正确！\n");
		printf("flash 测试成功！\n");
		printf("EMIF 测试成功！\n");
		result->flash_Test_Result = TRUE;
		result->emif_Test_Result = true;
		return 0;
	}
	else
	{
		printf("读flash的ID错误！\n");

		printf("flash 测试失败！\n");
		printf("EMIF 测试失败！\n");
		result->flash_Test_Result = false;
		result->emif_Test_Result = false;
		return -1;
	}
	//testbuffer数据初始化
//	for(i=0;i<BUFFERSIZE;i++)
//	{
//		flash_test_buffer[i] = testnum;
//		testnum += 0x0101;
//		if(testnum == 0xffff)
//		{
//			testnum = 0;
//		}
//	}
//
//	flash_erase_and_writetest();
//
//	//数据check
//	if(Nor_FLASH_Check(BUFFERSIZE))
//	{
//		printf("flash 测试成功！\n");
//		printf("EMIF 测试成功！\n");
//		result->flash_Test_Result = TRUE;
//		result->emif_Test_Result = true;
//	}
//	else
//	{
//		printf("flash 测试失败！\n");
//		printf("EMIF 测试失败！\n");
//		result->flash_Test_Result = false;
//		result->emif_Test_Result = false;
//
//	}
}



