/*
 * mcbsp_Set.c
 *
 *  Created on: 2025年9月25日
 *      Author: 18832
 */
#include "mcbsp_Set.h"
#include "interrupt.h"

// McBSP0 外设存储空间映射
volatile struct hw_McBSP1Regs McBSP0Regs,McBSP1Regs;
#pragma DATA_SECTION(McBSP0Regs,".Reg_McBSP0");
#pragma DATA_SECTION(McBSP1Regs,".Reg_McBSP1");

unsigned char i = 0;
unsigned char j = 0;
unsigned char z = 0;
unsigned int McBSP0_VarRx[100];
unsigned int McBSP1_VarRx[100];
void mcbsp_test(RESULT* result)
{
	mcbspPinMuxSetup();
	// MCBSP 中断初始化
	McBSP0InterruptInit();

	// MCBSP 控制器初始化
	McBSP0Init();
	// 初始化接收变量
	for(z = 0; z < 100; z++)
	{
		McBSP0_VarRx[z] = 0;
		McBSP1_VarRx[z] = 0;
	}

	for(;;)
	{

	}

}

/****************************************************************************/
/*                                                                          */
/*              McBSP0 McBSP1 中断初始化                                           */
/*                                                                          */
/****************************************************************************/
void McBSP0InterruptInit(void)
{
    // 初始化 DSP 中断控制器
    IntDSPINTCInit();

    // 注册 McBSP0 中断服务函数
    IntRegister(C674X_MASK_INT4, McBSP0ISR_RX);
    IntRegister(C674X_MASK_INT5, McBSP0ISR_TX);
    //注册Mcbsp1 中断服务函数
    IntRegister(C674X_MASK_INT6, McBSP1ISR_RX);
    IntRegister(C674X_MASK_INT7, McBSP1ISR_TX);


    // 映射系统中断至可屏蔽中断
    IntEventMap(C674X_MASK_INT4, SYS_INT_MCBSP0_RINT);
    IntEventMap(C674X_MASK_INT5, SYS_INT_MCBSP0_XINT);

    IntEventMap(C674X_MASK_INT6, SYS_INT_MCBSP1_RINT);
    IntEventMap(C674X_MASK_INT7, SYS_INT_MCBSP1_XINT);
    // 使能可屏蔽中断
    IntEnable(C674X_MASK_INT4);
    IntEnable(C674X_MASK_INT5);

    IntEnable(C674X_MASK_INT6);
    IntEnable(C674X_MASK_INT7);

    // 使能全局中断
    IntGlobalEnable();
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
	McBSP1_VarRx[j] = McBSP1Regs.DRR;
	j++;
	if(j == 100)
	{
		for(z=0;z<100;z++)
		{
			printf("McBSP1_VarRx[%d] = %d\r\n",z,McBSP1_VarRx[z]);
			McBSP1_VarRx[z] = 0;
		}
		printf("\r\n");
		j = 0;
	}
}
/****************************************************************************/
/*                                                                          */
/*              McBSP0  McBSP1 初始化                                               */
/*                                                                          */
/****************************************************************************/
void McBSP0Init(void)
{
	// McBSP0 串行口控制寄存器
	McBSP0Regs.SPCR.bit.FREE=1;
	McBSP0Regs.SPCR.bit.SOFT=1;

	McBSP1Regs.SPCR.bit.FREE=1;
	McBSP1Regs.SPCR.bit.SOFT=1;

	// 禁用 FRST GRST XRST RRST
	McBSP0Regs.SPCR.bit.FRST=0;
	McBSP0Regs.SPCR.bit.GRST=0;
	McBSP0Regs.SPCR.bit.XRST=0;
	McBSP0Regs.SPCR.bit.RRST=0;

	McBSP1Regs.SPCR.bit.FRST=0;
	McBSP1Regs.SPCR.bit.GRST=0;
	McBSP1Regs.SPCR.bit.XRST=0;
	McBSP1Regs.SPCR.bit.RRST=0;

	// McBSP0  Mcbsp1管脚控制寄存器
	// 发送帧同步信号由内部采样率生成器输出
	McBSP0Regs.PCR.bit.FSXM=1;
	McBSP1Regs.PCR.bit.FSXM=1;
	// 接收帧同步信号外部输入
	McBSP0Regs.PCR.bit.FSRM=0;
	McBSP1Regs.PCR.bit.FSRM=0;
	// 发送时钟信号由内部采样率生成器产生
	McBSP0Regs.PCR.bit.CLKXM=1;
	McBSP1Regs.PCR.bit.CLKXM=1;
	// 接收时钟信号由内部采样率生成器产生
	McBSP0Regs.PCR.bit.CLKRM=1;
	McBSP1Regs.PCR.bit.CLKRM=1;
	// 内部采样率生成器时钟信号由 McBSP 内部输入时钟产生(DSP 时钟频率 1/2)
	McBSP0Regs.PCR.bit.SCLKME=0;
	McBSP1Regs.PCR.bit.SCLKME=0;
	// 发送帧同步信号高电平有效
	McBSP0Regs.PCR.bit.FSXP=0;
	McBSP1Regs.PCR.bit.FSXP=0;
	// 接收帧同步信号高电平有效
	McBSP0Regs.PCR.bit.FSRP=0;
	McBSP1Regs.PCR.bit.FSRP=0;
	// 发送数据在时钟信号上降沿采样
	McBSP0Regs.PCR.bit.CLKXP=0;
	McBSP1Regs.PCR.bit.CLKXP=0;
	// 接收数据在时钟信号下降沿采样
	McBSP0Regs.PCR.bit.CLKRP=0;
	McBSP1Regs.PCR.bit.CLKRP=0;

	// McBSP0  McBSP1采样率生成寄存器
	// 采样率生成寄存器自由运行
	McBSP0Regs.SRGR.bit.GSYNC=0;
	McBSP1Regs.SRGR.bit.GSYNC=0;
	// CLKS上升沿产生CLKG和FSG
	McBSP0Regs.SRGR.bit.CLKSP=0;
	McBSP1Regs.SRGR.bit.CLKSP=0;
	// 采样率生成器时钟信号由 McBSP 内部输入时钟产生(DSP 时钟频率 1/2)
	McBSP0Regs.SRGR.bit.CLKSM=1;
	McBSP1Regs.SRGR.bit.CLKSM=1;
	// 指定帧周期值(+1) 一帧总共有32bit
	McBSP0Regs.SRGR.bit.FPER=31;
	McBSP1Regs.SRGR.bit.FPER=31;
	// 指定帧宽度值(+1)
	McBSP0Regs.SRGR.bit.FWID=0;
	McBSP1Regs.SRGR.bit.FWID=0;
	// 采样率生成器时钟分频
	McBSP0Regs.SRGR.bit.CLKGDV=11;
	McBSP1Regs.SRGR.bit.CLKGDV=11;


	// McBSP0 接收控制寄存器
	// 多相位帧
	McBSP0Regs.RCR.bit.RPHASE=1;
	McBSP1Regs.RCR.bit.RPHASE=1;
	// 指定相位 2 接收帧长度(1个字)
	McBSP0Regs.RCR.bit.RFRLEN2=0;
	McBSP1Regs.RCR.bit.RFRLEN2=0;
	// 指定相位 2 接收字长度(16 位)
	McBSP0Regs.RCR.bit.RWDLEN2=0x2;
	McBSP1Regs.RCR.bit.RWDLEN2=0x2;
	// 无压缩 MSB(最高有效位)
	McBSP0Regs.RCR.bit.RCOMPAND=0;
	McBSP1Regs.RCR.bit.RCOMPAND=0;
	// 忽略第一个接收帧同步脉冲
	McBSP0Regs.RCR.bit.RFIG=1;
	McBSP1Regs.RCR.bit.RFIG=1;
	// 无接收数据延迟位
	McBSP0Regs.RCR.bit.RDATDLY=0;
	McBSP1Regs.RCR.bit.RDATDLY=0;

	// 指定相位 1 接收帧长度(1 个字)
	McBSP0Regs.RCR.bit.RFRLEN1=0;
	McBSP1Regs.RCR.bit.RFRLEN1=0;
	// 指定相位 2 接收字长度(16 位)
	McBSP0Regs.RCR.bit.RWDLEN1=0x2;
	McBSP1Regs.RCR.bit.RWDLEN1=0x2;
	// 无数据位倒置
	McBSP0Regs.RCR.bit.RWDREVRS=0;
	McBSP1Regs.RCR.bit.RWDREVRS=0;

	// McBSP0  McBSP1发送控制寄存器
	// 多相位帧
	McBSP0Regs.XCR.bit.XPHASE=1;
	McBSP1Regs.XCR.bit.XPHASE=1;
	// 指定相位 2 发送帧长度(1个字)
	McBSP0Regs.XCR.bit.XFRLEN2=0;
	McBSP1Regs.XCR.bit.XFRLEN2=0;
	// 指定相位 2 发送字长度(16 位)
	McBSP0Regs.XCR.bit.XWDLEN2=0x2;
	McBSP1Regs.XCR.bit.XWDLEN2=0x2;
	// 无压缩 MSB(最高有效位)
	McBSP0Regs.XCR.bit.XCOMPAND=0;
	McBSP1Regs.XCR.bit.XCOMPAND=0;
	// 忽略第一个发送帧同步脉冲
	McBSP0Regs.XCR.bit.XFIG=1;
	McBSP1Regs.XCR.bit.XFIG=1;
	// 无发送数据延迟位
	McBSP0Regs.XCR.bit.XDATDLY=0;
	McBSP1Regs.XCR.bit.XDATDLY=0;
	// 指定相位 1 发送帧长度(1 个字)
	McBSP0Regs.XCR.bit.XFRLEN1=0;
	McBSP1Regs.XCR.bit.XFRLEN1=0;
	// 指定相位 2 发送字长度(16 位)
	McBSP0Regs.XCR.bit.XWDLEN1=0x2;
	McBSP1Regs.XCR.bit.XWDLEN1=0x2;
	// 无数据位倒置
	McBSP0Regs.XCR.bit.XWDREVRS=0;
	McBSP1Regs.XCR.bit.XWDREVRS=0;

	// 延时等待内部同步
	unsigned char i;
	for(i=0;i<100;i++)
		asm (" nop");

	// 使能 接收
	McBSP0Regs.SPCR.bit.RRST=1;
	McBSP1Regs.SPCR.bit.RRST=1;
	// 使能 接收帧同步信号
	McBSP0Regs.SPCR.bit.FRST=1;
	McBSP1Regs.SPCR.bit.FRST=1;

	// 使能 内部采样率生成器
	McBSP0Regs.SPCR.bit.GRST=1;
	McBSP1Regs.SPCR.bit.GRST=1;
	// 使能 发送
	McBSP0Regs.SPCR.bit.XRST=1;
	McBSP1Regs.SPCR.bit.XRST=1;

	for(i=0;i<100;i++)
		asm (" nop ");
}

