/*
 * main.c
 *
 *  Created on: 2026年8月27日
 *      Author: 18832
 */

/*
 * main.c
 *
 *  Created on: 2026年8月27日
 *      Author: 18832
 */


/****************************************************************************/
/*                                                                          */
/*              通用异步串口1测试（查询方式）                               */
/*                                                                          */
/*              2014年04月20日                                              */
/*                                                                          */
/****************************************************************************/
// 注意：DSP ports, Shared RAM, UART0, EDMA, SPI0, MMC/SDs,
//       VPIF, LCDC, SATA, uPP, DDR2/mDDR (bus ports), USB2.0, HPI, PRU
//       这些外设使用的时钟来源为 PLL0_SYSCLK2 默认频率为 CPU 频率的二分之一
//       但是，ECAPs, UART1/2, Timer64P2/3, eHRPWMs,McBSPs, McASP0, SPI1
//       这些外设的时钟来源可以在 PLL0_SYSCLK2 和 PLL1_SYSCLK2 中选择
//       通过修改 System Configuration (SYSCFG) Module
//       寄存器 Chip Configuration 3 Register (CFGCHIP3) 第四位 ASYNC3_CLKSRC
//       配置时钟来源
//       （默认值） 0 来源于 PLL0_SYSCLK2
//                  1 来源于 PLL1_SYSCLK2
//       如果不是为了降低功耗，不建议修改这个值，它会影响所有相关外设的时钟频率

#include "TL6748.h"                 // 创龙 DSP6748 开发板相关声明

#include "hw_types.h"               // 宏命令
#include "hw_syscfg0_C6748.h"       // 系统配置模块寄存器
#include "soc_C6748.h"              // DSP C6748 外设寄存器

#include "psc.h"                    // 电源与睡眠控制宏及设备抽象层函数声明
#include "gpio.h"                   // 通用输入输出口宏及设备抽象层函数声明
#include "uart.h"                   // 通用异步串口宏及设备抽象层函数声明
#include <stdio.h>
/****************************************************************************/
/*                                                                          */
/*              宏定义                                                      */
/*                                                                          */
/****************************************************************************/
// 软件断点
#define SW_BREAKPOINT     asm(" SWBP 0 ");

// 时钟
#define SYSCLK_1_FREQ     (456000000)
#define SYSCLK_2_FREQ     (SYSCLK_1_FREQ/2)
#define UART_1_FREQ       (SYSCLK_2_FREQ)
#define UART_0_FREQ       (SYSCLK_2_FREQ)
/****************************************************************************/
/*                                                                          */
/*              全局变量                                                    */
/*                                                                          */
/****************************************************************************/
// 发送缓存
char Send[] = "Tronlong UART1 Application......\n\r";

/****************************************************************************/
/*                                                                          */
/*              函数声明                                                    */
/*                                                                          */
/****************************************************************************/
// 外设使能配置
void PSCInit(void);

// GPIO 管脚复用配置
void GPIOBankPinMuxSet();
// GPIO 管脚初始化
void GPIOBankPinInit();

// UART 初始化
void UARTInit(void);

/****************************************************************************/
/*                                                                          */
/*              主函数                                                      */
/*                                                                          */
/****************************************************************************/
int main(void)
{
    // 外设使能配置
    PSCInit();

    UARTPinMuxSetup(0, FALSE);

    // UART 初始化
    UARTInit();

    // 发送字符串
//    unsigned char i;
//    for(i = 0; i < 34; i++)
//        UARTCharPut(SOC_UART_0_REGS, Send[i]);

    // 接收缓存
    unsigned char Receive;
    // 主循环
    for(;;)
    {
        Receive=UARTCharGet(SOC_UART_0_REGS);
        Delay(0xff);
        UARTCharPut(SOC_UART_0_REGS, Receive);
    }
}

/****************************************************************************/
/*                                                                          */
/*              PSC 初始化                                                  */
/*                                                                          */
/****************************************************************************/
void PSCInit(void)
{
    // 使能 UART0 模块
    // 对相应外设模块的使能也可以在 BootLoader 中完成
    PSCModuleControl(SOC_PSC_0_REGS, HW_PSC_UART0, PSC_POWERDOMAIN_ALWAYS_ON,PSC_MDCTL_NEXT_ENABLE);
}


/****************************************************************************/
/*                                                                          */
/*              UART 初始化                                                 */
/*                                                                          */
/****************************************************************************/
void UARTInit(void)
{
    // 配置 UART0 参数
    // 波特率 115200 数据位 8 停止位 1 无校验位
    UARTConfigSetExpClk(SOC_UART_0_REGS, UART_0_FREQ, BAUD_9MBPS, UART_WORDL_8BITS, UART_OVER_SAMP_RATE_16);
    // 使能 UART0
    UARTEnable(SOC_UART_0_REGS);
}
