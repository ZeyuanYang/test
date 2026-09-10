/*
 * spi_Set.c
 *
 *  Created on: 2025年9月24日
 *      Author: 18832
 */
#include "spi_Set.h"
#include "iic_Set.h"
#include "interrupt.h"
#include "PinMultiplex.h"
#include <stdio.h>
//operator code
#define HI_8435_w_CTR             0x02
#define HI_8435_r_CTR             0x82

#define HI_8435_w_Sense_banks     0x04      //0x0f
#define HI_8435_r_Sense_banks     0x84

volatile unsigned int flag = 1;

unsigned int tx_len;
unsigned int rx_len;
unsigned char vrf_data[260];
unsigned char tx_data[260];
unsigned char rx_data[260] = {0};
unsigned char *p_tx;
unsigned char *p_rx;

void spi_Test(RESULT* result)
{
	/* Performing the Pin Multiplexing for SPI0. */
	SPIPinMuxSetup(0);
	/*
	 ** Using the Chip Select(CS) 0 pin of SPI1 to communicate with SPI Flash.
	 */
	//选择spi0 CS0 连接HI-8435
	SPI0CSPinMuxSetup(0);
//	InterruptInit();
	SPIInterruptInit();

    // SPI 初始化
    SPIInit();

    HI_8435_Spi_write0_test();

    HI_8435_Spi_read_test(result);
//    printf("HI_8435_r_Sense_banks:%d\n",rx_data[1]);
}


void SPIInit(void)
{
    unsigned char cs  = 0x01;
    unsigned char dcs = 0x01;
    unsigned int  val = SIMO_SOMI_CLK_CS;

    SPIReset(SOC_SPI_0_REGS);

    SPIOutOfReset(SOC_SPI_0_REGS);

    SPIModeConfigure(SOC_SPI_0_REGS, SPI_MASTER_MODE);

    SPIClkConfigure(SOC_SPI_0_REGS, 228000000, 20000000, SPI_DATA_FORMAT0);

    SPIPinControl(SOC_SPI_0_REGS, 0, 0, &val);

    SPIDefaultCSSet(SOC_SPI_0_REGS, dcs);

    // 配置 SPI 数据格式
    SPIDataFormatConfig(SPI_DATA_FORMAT0);

    // 配置 SPI 数据格式及片选信号
    SPIDat1Config(SOC_SPI_0_REGS, (SPI_CSHOLD | SPI_DATA_FORMAT0), cs);

	// 映射中断到 INT1
    SPIIntLevelSet(SOC_SPI_0_REGS, SPI_RECV_INTLVL | SPI_TRANSMIT_INTLVL);

    // 使能 SPI
    SPIEnable(SOC_SPI_0_REGS);
}

void SPIDataFormatConfig(unsigned int dataFormat)
{
    // 配置 SPI 时钟
    SPIConfigClkFormat(SOC_SPI_0_REGS,
                        (SPI_CLK_POL_HIGH | SPI_CLK_INPHASE),
                         dataFormat);

    // 配置 SPI 发送时 MSB 优先
    SPIShiftMsbFirst(SOC_SPI_0_REGS, dataFormat);

    // 设置字符长度
    SPICharLengthSet(SOC_SPI_0_REGS, CHAR_LENGTH, dataFormat);
}
/****************************************************************************/
/*                                                                          */
/*              SPI 中断初始化                                              */
/*                                                                          */
/****************************************************************************/
void SPIInterruptInit(void)
{
	// 注册中断服务函数
	IntRegister(C674X_MASK_INT4, SPIIsr);

	// 映射中断事件
	IntEventMap(C674X_MASK_INT4, SYS_INT_SPI0_INT);

	// 使能可屏蔽中断
	IntEnable(C674X_MASK_INT4);
}

void HI_8435_Spi_write0_test()
{
    tx_data[0] = HI_8435_w_Sense_banks;
    tx_data[1] = 0x0f;
    tx_len = rx_len = 2;
    SPIDat1Config(SOC_SPI_0_REGS, (SPI_CSHOLD | SPI_DATA_FORMAT0), 0x1);
    SpiTransfer();
}

void HI_8435_Spi_read_test(RESULT* result)
{
	unsigned char temp1,temp2,temp3,temp4,temp5,temp6;
    tx_data[0] = HI_8435_r_Sense_banks;
    tx_len = rx_len = 2;
    SPIDat1Config(SOC_SPI_0_REGS, (SPI_CSHOLD | SPI_DATA_FORMAT0), 0x1);
    SpiTransfer();
    temp1 = rx_data[1];

    tx_data[0] = 0x90;
    tx_len = rx_len = 2;
    SPIDat1Config(SOC_SPI_0_REGS, (SPI_CSHOLD | SPI_DATA_FORMAT0), 0x1);
    SpiTransfer();
    temp2 = rx_data[1];

    tx_data[0] = 0x92;
    tx_len = rx_len = 2;
    SPIDat1Config(SOC_SPI_0_REGS, (SPI_CSHOLD | SPI_DATA_FORMAT0), 0x1);
    SpiTransfer();
    temp3 = rx_data[1];

    tx_data[0] = 0x94;
    tx_len = rx_len = 2;
    SPIDat1Config(SOC_SPI_0_REGS, (SPI_CSHOLD | SPI_DATA_FORMAT0), 0x1);
    SpiTransfer();
    temp4 = rx_data[1];

    tx_data[0] = 0x96;
    tx_len = rx_len = 2;
    SPIDat1Config(SOC_SPI_0_REGS, (SPI_CSHOLD | SPI_DATA_FORMAT0), 0x1);
    SpiTransfer();
    temp5 = rx_data[1];
    if(temp1 == 15 && temp2 == 221 && temp3 == 185 && temp4 == 4 && temp5 == 0)
    {
    	printf("Spi test success!\n");
    	printf("HI8435 test success!\n");
    	result->spi_Test_Result = true;
    	result->spi_HI8435_Test_Result = true;
    }
    else
    {
    	printf("HI8435 test failure!\n");
    	result->spi_Test_Result = false;
    	result->spi_HI8435_Test_Result = false;
    }


}

/****************************************************************************/
/*                                                                          */
/*              SPI 中断服务函数                                            */
/*                                                                          */
/****************************************************************************/
void SPIIsr(void)
{
    unsigned int intCode = 0;
    IntEventClear(SYS_INT_SPI0_INT);
    intCode = SPIInterruptVectorGet(SOC_SPI_0_REGS);

    while (intCode)
    {
        if(intCode == SPI_TX_BUF_EMPTY)
        {
            tx_len--;
            SPITransmitData1(SOC_SPI_0_REGS, *p_tx);
            p_tx++;
            if (!tx_len)
            {
                SPIIntDisable(SOC_SPI_0_REGS, SPI_TRANSMIT_INT);
            }
        }

        if(intCode == SPI_RECV_FULL)
        {
            rx_len--;
            *p_rx = (char)SPIDataReceive(SOC_SPI_0_REGS);
            p_rx++;
            if (!rx_len)
            {
                flag = 0;
                SPIIntDisable(SOC_SPI_0_REGS, SPI_RECV_INT);
            }
        }

        intCode = SPIInterruptVectorGet(SOC_SPI_0_REGS);
    }
}
void SpiTransfer(void)
{
    p_tx = &tx_data[0];
    p_rx = &rx_data[0];
    SPIIntEnable(SOC_SPI_0_REGS, (SPI_RECV_INT | SPI_TRANSMIT_INT));
    while(flag);
    flag = 1;

    SPIDat1Config(SOC_SPI_0_REGS, SPI_DATA_FORMAT0, 0x1);
}

