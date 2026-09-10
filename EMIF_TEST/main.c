#include "TL6748.h"                 // 创龙 DSP6748 开发板相关声明

#include "hw_types.h"               // 宏命令
#include "hw_syscfg0_C6748.h"       // 系统配置模块寄存器
#include "soc_C6748.h"              // DSP C6748 外设寄存器

#include "psc_Set.h"                    // 电源与睡眠控制宏及设备抽象层函数声明
#include "gpio.h"                   // 通用输入输出口宏及设备抽象层函数声明
#include "uart.h"                   // 通用异步串口宏及设备抽象层函数声明
#include <stdio.h>
#include "emif_Set.h"
#include "PLL_Config.h"
#include "crc_Check.h"
#include "main.h"
/**
 * @def EMIFA_WR32(regbase)
 * @brief EMIFA 32 位写操作宏
 *        基地址 SOC_EMIFA_CS3_ADDR + (regbase << 1)
 *        FPGA 挂在 EMIFA 的 CS3 片选上，16 位宽数据总线，
 *        地址左移 1 位实现字节对齐。
 * @param regbase EMIFA 寄存器偏移地址
 */

/**
 * @def EMIFA_WR16(regbase)
 * @brief EMIFA 16 位写操作宏
 *        基地址 SOC_EMIFA_CS3_ADDR + (regbase << 1)
 * @param regbase EMIFA 寄存器偏移地址
 */
#define CrcAddr              0xa01a
#define EMIF_FFT_DATA_RD_LEN    (8192U)
#define EMIFA_WR32(regbase)     (*(volatile uint32_t*)(SOC_EMIFA_CS3_ADDR + (regbase<<1U)))

int main()
{
    int i,Tmp;
    volatile unsigned int crcVlaue;
    static uint32_t CrcDataBuf[EMIF_FFT_DATA_RD_LEN] = {0};
    Peripheral_Psc_Set();
    EMIFASetup();
    GPIOBankPinMuxSet();
    GPIODirModeSet(SOC_GPIO_0_REGS, 100, GPIO_DIR_INPUT);
    GPIODirModeSet(SOC_GPIO_0_REGS, 103, GPIO_DIR_OUTPUT);

    C6748_PLLC0Init(0,10,0,0,1,2,9);

    while(1)
    {
        GPIOPinWrite(SOC_GPIO_0_REGS,103,1);
        Delay_US(100);
        GPIOPinWrite(SOC_GPIO_0_REGS,103,0);
        while(!GPIOPinRead(SOC_GPIO_0_REGS,100));

        for(i=0;i<EMIF_FFT_DATA_RD_LEN;i++)
        {
            Tmp = EMIFA_WR32(0xa016);
            CrcDataBuf[i] = Tmp;
        }

        if(CrcCheck(CrcAddr, CrcDataBuf, EMIF_FFT_DATA_RD_LEN))
        {
            printf("emif read data crc check success!\n");
        }
        else
        {
            printf("emif read data crc check error!\n");
        }
    }
}





