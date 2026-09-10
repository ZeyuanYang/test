/*
 * iic_Set.c
 *
 *  Created on: 2025年9月24日
 *      Author: 18832
 */

#include "iiC_Set.h"
#include <stdio.h>
#include "PinMultiplex.h"
#define ADDRESS  0x48
/****************************************************************************/
/*                                                                          */
/*              全局变量                                                    */
/*                                                                          */
/****************************************************************************/
static volatile  char slaveData[9];

static volatile unsigned int dataIdx = 0;
static volatile unsigned int txCompFlag = 1;
static volatile unsigned int AckRolling = 0;
float voltage1,voltage2,voltage3,voltage4,temperature1,temperature2;

void IIC_test(RESULT* result)
{
	I2CPinMuxSetup(1);
//	InterruptInit();
	IICInterruptInit();
	IICInit();
	set_Tlc2991();
	test_Tlc2991(result);
	printf("IIC 2991 test success!\n");
}

void IICInit(void)
{
    //IIC 复位 / 禁用
    I2CMasterDisable(SOC_I2C_1_REGS);

    // 配置总线速度为 100KHz
    I2CMasterInitExpClk(SOC_I2C_1_REGS, 24000000, 8000000, 100000);

    // 设置从设备地址
    I2CMasterSlaveAddrSet(SOC_I2C_1_REGS, ADDRESS);

    // IIC 使能
    I2CMasterEnable(SOC_I2C_1_REGS);
}

void InterruptInit()
{
	// 初始化 DSP 中断控制器
	IntDSPINTCInit();
	// 使能 DSP 全局中断
	IntGlobalEnable();
}
void IICInterruptInit(void)
{
    IntRegister(C674X_MASK_INT6, IICIsr);
    IntEventMap(C674X_MASK_INT6, SYS_INT_I2C1_INT);
	IntEnable(C674X_MASK_INT6);
}
// iic IIC 模块基址
// dataCnt 数据大小
// 阻塞函数
void IICSend(unsigned int iic, unsigned int dataCnt)
{
    txCompFlag = 1;
    dataIdx = 0;

    while(I2CMasterBusBusy(iic));

    I2CSetDataCount(iic, dataCnt);

    I2CMasterControl(iic, I2C_CFG_MST_TX | I2C_CFG_STOP);

    I2CMasterIntEnableEx(iic, I2C_INT_TRANSMIT_READY | I2C_INT_STOP_CONDITION | I2C_INT_NO_ACK);

    I2CMasterStart(iic);

    // 等待数据发送完成
    while(txCompFlag);

    while(I2CMasterBusBusy(iic));
}
// iic IIC 模块基址
// dataCnt 数据大小
// 阻塞函数
void IICReceive(unsigned int iic, unsigned int dataCnt)
{
    txCompFlag = 1;
    dataIdx = 0;

    while(I2CMasterBusBusy(SOC_I2C_1_REGS));

    I2CSetDataCount(SOC_I2C_1_REGS, dataCnt);

    I2CMasterControl(SOC_I2C_1_REGS, I2C_CFG_MST_RX | I2C_CFG_STOP);

    I2CMasterIntEnableEx(SOC_I2C_1_REGS, I2C_INT_DATA_READY | I2C_INT_STOP_CONDITION | I2C_INT_NO_ACK);

    I2CMasterStart(SOC_I2C_1_REGS);

    // 等待数据接收完成
    while(txCompFlag);

    while(I2CMasterBusBusy(SOC_I2C_1_REGS));
}

void IICIsr(void)
{
    volatile unsigned int intCode = 0;

    // 取得中断代码
    intCode = I2CInterruptVectorGet(SOC_I2C_1_REGS);

    while(intCode!=0)
    {
    	// 清除中断事件
    	IntEventClear(SYS_INT_I2C1_INT);

		if (intCode == I2C_INTCODE_TX_READY)
		{
		  I2CMasterDataPut(SOC_I2C_1_REGS, slaveData[dataIdx]);
		  dataIdx++;
		}

		if(intCode == I2C_INTCODE_RX_READY)
		{
		  slaveData[dataIdx] = I2CMasterDataGet(SOC_I2C_1_REGS);
		  dataIdx++;
		}

		if (intCode == I2C_INTCODE_STOP)
		{
		 I2CMasterIntDisableEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY |
											   I2C_INT_DATA_READY |
											   I2C_INT_NO_ACK |
											   I2C_INT_STOP_CONDITION);
		  txCompFlag = 0;
		}

		if (intCode == I2C_INTCODE_NACK)
		{
		 I2CMasterIntDisableEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY |
											   I2C_INT_DATA_READY |
											   I2C_INT_NO_ACK |
											   I2C_INT_STOP_CONDITION);
		 // 产生停止位
		 I2CMasterStop(SOC_I2C_1_REGS);

		 I2CStatusClear(SOC_I2C_1_REGS, I2C_CLEAR_STOP_CONDITION);

		 // 清除中断
		 IntEventClear(SYS_INT_I2C1_INT);
		 txCompFlag = 0;
		 AckRolling = 1;
		}

		if (I2CMasterIntStatus(SOC_I2C_1_REGS) & I2C_ICSTR_NACKSNT)
		{
		 I2CMasterIntDisableEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY |
											   I2C_INT_DATA_READY |
											   I2C_INT_NO_ACK |
											   I2C_INT_STOP_CONDITION);

		 // 产生停止位
		 I2CMasterStop(SOC_I2C_1_REGS);

		 I2CStatusClear(SOC_I2C_1_REGS, (I2C_CLEAR_NO_ACK_SENT |
										 I2C_CLEAR_STOP_CONDITION));

		 // 清除中断
		 IntEventClear(SYS_INT_I2C1_INT);
		 txCompFlag = 0;
		}

		intCode = I2CInterruptVectorGet(SOC_I2C_1_REGS);
    }
}
/****
 * TLC2991通过IIC写一个字节到指定地址
 */
void tlc_ByteWrite(unsigned int Address, unsigned char Data)
{
    slaveData[0] = Address;
    slaveData[1] = Data;
    IICSend(SOC_I2C_1_REGS,2);
}
/**
 * 从LtC2991读一个字节
 *
 */
unsigned char LtC2991_Read(unsigned int Address)
{
	slaveData[0] = Address;

	IICSend(SOC_I2C_1_REGS,1);
	IICReceive(SOC_I2C_1_REGS, 1);

   	return slaveData[0];
}
void TLC_2991_AckPolling(void)
{
	do
	{
		AckRolling = 0;
		Delay(0xFFFFF);
		slaveData[0] = ADDRESS;
		IICSend(SOC_I2C_1_REGS, 1);
		Delay(0xFFFFF);
	}while(AckRolling==1);
}
void Delay(volatile unsigned int delay)
{
    while(delay--);
}

//配置LTC2991
void set_Tlc2991()
{
	int test;
//	//使能采样管脚
	//v3-v4||V3单端  V1-v2 V1单端
	tlc_ByteWrite(0x06, 0x33);
	TLC_2991_AckPolling();
	//配置V7 V8 V5 V6 | V7、V5单端
	tlc_ByteWrite(0x07, 0x00);
	TLC_2991_AckPolling();
	//使能芯片
//	int test,test1;
	tlc_ByteWrite(0x01, 0xf0);
	TLC_2991_AckPolling();
	test = LtC2991_Read(0x06);
//	test1 = TLC_CurrentAddressRead();
	printf("test: %d\n",test);
}

void test_Tlc2991(RESULT* result)
{
	//电压测试1
	/*
	 * V7 msb 16h/lsb 17h
	 * */
	int lsb,msb;
	int temp1,temp2;
	lsb = LtC2991_Read(0x17);
	msb = LtC2991_Read(0x16);
	voltage1 = ((msb & 0x3F) << 8) | lsb;
	voltage1 = voltage1 * 305.18 / 1000000;  //转换为实际电压值

	//电压测试2
	/*
	 * V5单端   msb 12h/lsb 13h
	 * */
	lsb = LtC2991_Read(0x13);
	msb = LtC2991_Read(0x12);
	voltage2 = ((msb & 0x3F) << 8) | lsb;
	voltage2 = voltage2 * 305.18 / 1000000;  //转换为实际电压值

	//电压测试3
	/*
	 * V6单端
	 * */
	lsb = LtC2991_Read(0x15);
	msb = LtC2991_Read(0x14);
	voltage3 = ((msb & 0x3F) << 8) | lsb;
	voltage3 = voltage3 * 305.18 / 1000000;  //转换为实际电压值

	//电压测试4
	/*
	 * V8 单端
	 * */
	lsb = LtC2991_Read(0x19);
	msb = LtC2991_Read(0x18);
	voltage4 = ((msb & 0x3F) << 8) | lsb;
	voltage4 = voltage4 * 305.18 / 1000000;  //转换为实际电压值
	/*
	 * 温度测试 ODSP温度获取(差分)
	 * V1-V2
	 * */
	lsb = LtC2991_Read(0x0b);
	msb = LtC2991_Read(0x0a);
	temp1 = ((msb & 0x3F) << 8) | lsb;
	//v2
	lsb = LtC2991_Read(0x0d);//0xa
	msb = LtC2991_Read(0x0c);//0xb  pDSPtemperature
	temp2 = ((msb & 0x3F) << 8) | lsb;
	temperature1 = temp1 * 0.0625;
//	temperature1 = (temp1 - temp2) * 0.0625; //转换为实际温度值

	/*
	 * 温度测试 PDSP温度获取(差分)
	 * V3-V4
	 * */
	lsb = LtC2991_Read(0x0f);
	msb = LtC2991_Read(0x0e);
	temp1 = ((msb & 0x3F) << 8) | lsb;
	//v4
	lsb = LtC2991_Read(0x11);//0xa
	msb = LtC2991_Read(0x10);//0xb  pDSPtemperature
	temp2 = ((msb & 0x3F) << 8) | lsb;
	temperature2 = temp1 * 0.0625;
//	temperature2 = (temp1 - temp2) * 0.0625; //转换为实际温度值

//	result->temperature_1 = temperature1;
//	result->temperature_1 = temperature2;
//	result->voltage_1 = voltage1;
//	result->voltage_2 = voltage2;
//	result->voltage_3 = voltage3;
//	result->voltage_4 = voltage4;


	printf("电压V5:%.4fV\n",voltage2);
	printf("电压V6:%.4fV\n",voltage3);
	printf("电压V7:%.4fV\n",voltage1);
	printf("电压V8:%.4fV\n",voltage4);

	printf("ODSP温度:%.4f℃\n",temperature1);
	printf("PDSP温度:%.4f℃\n",temperature2);
}
