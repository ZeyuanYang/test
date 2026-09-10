/*
 * mcbsp_Set.c
 *
 *  Created on: 2025年9月25日
 *      Author: 18832
 */
#include "mcbsp_Set.h"
#include "interrupt.h"
#include "PinMultiplex.h"
#include "gpio.h"
#include "c6748.h"
// McBSP0 外设存储空间映射
volatile struct hw_McBSP1Regs McBSP0Regs,McBSP1Regs;
#pragma DATA_SECTION(McBSP0Regs,".Reg_McBSP0");
#pragma DATA_SECTION(McBSP1Regs,".Reg_McBSP1");

unsigned char i = 0;
unsigned char j = 0;
unsigned char z = 0;
unsigned int McBSP0_VarRx[100];
unsigned int McBSP1_VarRx[100];
volatile tBoolean mcbsp_flag;
void mcbsp_test(RESULT* result)
{
	mcbspPinMuxSetup();
	// MCBSP 中断初始化
	McBSPInterruptInit();

	// MCBSP 控制器初始化
	McBSPInit();
	// 初始化接收变量
	for(z = 0; z < 100; z++)
	{
		McBSP0_VarRx[z] = 0;
		McBSP1_VarRx[z] = 0;
	}
	result->MDSP_mcbsp_Test_Result = mcbsp_flag;
	result->ODSP_mcbsp_Test_Result = mcbsp_flag;
}

/****************************************************************************/
/*                                                                          */
/*              McBSP0 McBSP1 中断初始化                                           */
/*                                                                          */
/****************************************************************************/
void McBSPInterruptInit(void)
{
    // 初始化 DSP 中断控制器
//    IntDSPINTCInit();
    //注册Mcbsp1 中断服务函数
    IntRegister(C674X_MASK_INT7, McBSP1ISR_RX);
    IntRegister(C674X_MASK_INT8, McBSP1ISR_TX);

    // 映射系统中断至可屏蔽中断

    IntEventMap(C674X_MASK_INT7, SYS_INT_MCBSP1_RINT);
    IntEventMap(C674X_MASK_INT8, SYS_INT_MCBSP1_XINT);
    // 使能可屏蔽中断

    IntEnable(C674X_MASK_INT7);
    IntEnable(C674X_MASK_INT8);

    // 使能全局中断
//    IntGlobalEnable();
}

/****************************************************************************/
/*                                                                          */
/*              McBSP0 McBSP1中断服务函数                                         */
/*                                                                          */
/****************************************************************************/
void McBSP0ISR_TX(void)
{
	McBSP0Regs.DXR =1000+i;
	i++;
	McBSP0Regs.DXR =1000+i;
	i++;

	if(i == 100)
	{
		i = 0;
	}
}

void McBSP0ISR_RX(void)
{
	McBSP0_VarRx[j] = McBSP0Regs.DRR;
	j++;
	if(j == 100)
	{
		for(z=0;z<100;z++)
		{
			printf("McBSP0_VarRx[%d] = %d\r\n",z,McBSP0_VarRx[z]);
			McBSP0_VarRx[z] = 0;
		}
		printf("\n");
		j = 0;
	}
}
//Mcbsp1中断服务函数
void McBSP1ISR_TX(void)
{
	McBSP1Regs.DXR =1000+i;
	i++;
	McBSP1Regs.DXR =1000+i;
	i++;

	if(i == 100)
	{
		i = 0;
	}
}

void McBSP1ISR_RX(void)
{
	Delay(0xffff);
	while(!McBSP1Regs.SPCR.bit.RRDY);
	McBSP1_VarRx[j] = McBSP1Regs.DRR;

//	printf("McBSP1_VarRx = %d\r\n",McBSP1Regs.DRR);
	j++;
	if(j == 100)
	{
		for(z=0;z<100;z++)
		{
//			printf("McBSP1_VarRx[%d] = %d\r\n",z,McBSP1_VarRx[z]);
			if(McBSP1_VarRx[z] == 0xa5a5)
			{
				//收到了ODSP发来的数
				mcbsp_flag = true;
				//关闭接收中断使能
				IntDisable(C674X_MASK_INT7);
			}
			else{
				mcbsp_flag = false;
				IntDisable(C674X_MASK_INT7);
			}
			McBSP1_VarRx[z] = 0;
		}
		printf("\r\n");
		j = 0;
		//给出ODSP停止发送数据中断
		GPIOPinWrite(SOC_GPIO_0_REGS, 143, GPIO_PIN_HIGH);
		GPIOPinWrite(SOC_GPIO_0_REGS, 144, GPIO_PIN_LOW);
	}
}
/****************************************************************************/
/*                                                                          */
/*             McBSP1 初始化                                               */
/*                                                                          */
/****************************************************************************/
void McBSPInit(void)
{
	// McBSP1 串行口控制寄存器
	McBSP1Regs.SPCR.bit.FREE=1;
	McBSP1Regs.SPCR.bit.SOFT=0;
	// 禁用 FRST GRST XRST RRST
	McBSP1Regs.SPCR.bit.FRST=0;
	McBSP1Regs.SPCR.bit.GRST=0;
	McBSP1Regs.SPCR.bit.XRST=0;
	McBSP1Regs.SPCR.bit.RRST=0;
//	McBSP1Regs.SPCR.bit.XINTM = 2;
	McBSP1Regs.SPCR.bit.RINTM = 2;
	McBSP1Regs.SPCR.bit.DLB = 0;

	// McBSP1  管脚控制寄存器
	// 发送帧同步信号由外部驱动
	McBSP1Regs.PCR.bit.FSXM=0;

	// 接收帧同步信号外部输入
	McBSP1Regs.PCR.bit.FSRM=0;
	// 发送时钟信号由内外部驱动(输入引脚)
	McBSP1Regs.PCR.bit.CLKXM=0;
	// 接收时钟信号由外部驱动
	McBSP1Regs.PCR.bit.CLKRM=0;
	// 内部采样率生成器时钟信号由外部驱动(来自于接收端时钟信号)CLKR
	McBSP1Regs.PCR.bit.SCLKME=1;
	// 发送帧同步信号高电平有效
	McBSP1Regs.PCR.bit.FSXP=0;
	// 接收帧同步信号高电平有效
	McBSP1Regs.PCR.bit.FSRP=1;
	// 发送数据在时钟信号上升沿采样
	McBSP1Regs.PCR.bit.CLKXP=0;
	// 接收数据在时钟信号下降沿采样
	McBSP1Regs.PCR.bit.CLKRP=1;
	//   McBSP1采样率生成寄存器
	// 采样率生成寄存器同步
	McBSP1Regs.SRGR.bit.GSYNC=1;
	// CLKS上升沿产生CLKG和FSG
	McBSP1Regs.SRGR.bit.CLKSP=0;
	// 内部采样率生成器时钟信号由外部驱动(来自于接收端时钟信号)CLKR
	McBSP1Regs.SRGR.bit.CLKSM=0;
	// 指定帧周期值(+1) 一帧总共有32bit
	McBSP1Regs.SRGR.bit.FPER=15;
	// 指定帧宽度值(+1)
	McBSP1Regs.SRGR.bit.FWID=0;
	// 采样率生成器时钟分频
	McBSP1Regs.SRGR.bit.CLKGDV=0;

	McBSP1Regs.SRGR.bit.FSGM = 0; //buqueding 1 为1表示使用内部帧同步发生器

	// McBSP1接收控制寄存器
	// 单相位
	McBSP1Regs.RCR.bit.RPHASE=0;
//	// 指定相位 2 接收帧长度(1个字)
//	McBSP1Regs.RCR.bit.RFRLEN2=0;
//	// 指定相位 2 接收字长度(16 位)
//	McBSP1Regs.RCR.bit.RWDLEN2=0x2;
	// 无压缩 MSB(最高有效位)
	McBSP1Regs.RCR.bit.RCOMPAND=0;
	// 忽略第一个接收帧同步脉冲
	McBSP1Regs.RCR.bit.RFIG=1;
	// 数据延迟1位
	McBSP1Regs.RCR.bit.RDATDLY=1;

	// 指定相位 1 接收帧长度(1 个字)
	McBSP1Regs.RCR.bit.RFRLEN1=0;
	// 指定相位 2 接收字长度(16 位)
	McBSP1Regs.RCR.bit.RWDLEN1=0x2;
	// 无数据位倒置
	McBSP1Regs.RCR.bit.RWDREVRS=0;

	// McBSP1发送控制寄存器
	// 多相位帧
	McBSP1Regs.XCR.bit.XPHASE=0;
//	// 指定相位 2 发送帧长度(1个字)
//	McBSP1Regs.XCR.bit.XFRLEN2=0;
//	// 指定相位 2 发送字长度(16 位)
//	McBSP1Regs.XCR.bit.XWDLEN2=0x2;
	// 无压缩 MSB(最高有效位)
	McBSP1Regs.XCR.bit.XCOMPAND=0;
	// 忽略第一个发送帧同步脉冲
	McBSP1Regs.XCR.bit.XFIG=1;
	// 无发送数据延迟位
	McBSP1Regs.XCR.bit.XDATDLY=1;
	// 指定相位 1 发送帧长度(1 个字)
	McBSP0Regs.XCR.bit.XFRLEN1=0;
	// 指定相位 1 发送字长度(16 位)
	McBSP1Regs.XCR.bit.XWDLEN1=0x2;
	// 无数据位倒置
	McBSP1Regs.XCR.bit.XWDREVRS=0;

	// 延时等待内部同步
	unsigned char i;
	for(i=0;i<100;i++)
		asm (" nop");

	// 使能 接收
	McBSP1Regs.SPCR.bit.RRST=1;
	// 使能内部帧同步信号发生器
//	McBSP1Regs.SPCR.bit.FRST=0;
//
//	 使能 内部采样率生成器
	McBSP1Regs.SPCR.bit.GRST=1;
//	// 使能 发送
//	McBSP1Regs.SPCR.bit.XRST=1;
//
	for(i=0;i<100;i++)
		asm (" nop ");

}

