/*
 * crc_Check.c
 *
 *  Created on: 2026年9月2日
 *      Author: 18832
 */


#include "crc_Check.h"
#include "hw_types.h"
#include "soc_C6748.h"
#include "gpio.h"
/*===========================================================================
 * 函数: Crc32CalcU32
 *---------------------------------------------------------------------------
 * 功能: 计算 32 位字数组的 CRC-32 校验值（Slicing-by-4 算法）。
 *
 * 参数:
 *   Data - 指向待计算数据的 32 位字数组指针（volatile，防编译器优化）
 *   Len  - 待计算的 32 位字个数
 *
 * 返回: 计算得到的 CRC-32 校验值（32 位无符号整数）
 *
 * 说明:
 *   - 使用 Slicing-by-4 算法，每次循环处理一个 32 位字。
 *   - 将当前 CRC 与输入字异或后，按字节拆分为 4 个索引，
 *     分别查 4 张表 (GCrc32Tab0 ~ GCrc32Tab3) 后异或累加。
 *   - CRC 初始值为 0xFFFFFFFF，最终异或 0xFFFFFFFF 后输出。
 *   - 相比逐字节查表，该算法在 32 位处理器上效率更高。
 *===========================================================================*/
#define CPU_FREQ_HZ                 (440000000U)
#define SYSCLK2_HZ                  (CPU_FREQ_HZ / 2U)
#define TIMEOUT_LOOP_DIV            (8U)
#define TIMEOUT_LOOPS_PER_US        (SYSCLK2_HZ / 1000000U / TIMEOUT_LOOP_DIV)
#define EMIFA_WR32(regbase)     (*(volatile uint32_t*)(SOC_EMIFA_CS3_ADDR + (regbase<<1U)))
#define EMIFA_WR16(regbase)     (*(volatile uint16_t*)(SOC_EMIFA_CS3_ADDR + (regbase<<1U)))
#define TIMEOUT_US(us)  ((uint32_t)((us) * TIMEOUT_LOOPS_PER_US))

uint32_t Crc32CalcU32(volatile uint32_t *Data, uint32_t Len)
{
    int32_t i;
    uint32_t X = 0U;
    uint32_t Crc = 0xFFFFFFFFU;

    /* 逐字循环处理每个 32 位数据 */
    for (i = 0U; i < Len; i++)
    {
        /* X = 当前 CRC 异或当前输入字 —— 将旧 CRC 与新数据融合 */
        X = Crc ^ Data[i];
        /*
         * Slicing-by-4 核心步骤：
         * 将 X 按低到高字节拆分为 4 个 8 位索引，分别在 4 张表中查找
         * 对应的 CRC 部分值，然后异或合并：
         *   - X & 0xFF        -> byte 0, 查 GCrc32Tab3
         *   - (X >> 8) & 0xFF -> byte 1, 查 GCrc32Tab2
         *   - (X >> 16) & 0xFF-> byte 2, 查 GCrc32Tab1
         *   - (X >> 24) & 0xFF-> byte 3, 查 GCrc32Tab0
         */
        Crc = GCrc32Tab3[X & 0xFFU] ^
              GCrc32Tab2[(X >> 8) & 0xFFU] ^
              GCrc32Tab1[(X >> 16) & 0xFFU] ^
              GCrc32Tab0[(X >> 24) & 0xFFU];
    }

    /* 最终值与 0xFFFFFFFF 异或后返回（标准 CRC-32 后处理） */
    return (Crc ^ 0xFFFFFFFFU);
}


/*===========================================================================
 * 函数: Crc32CheckU32
 *---------------------------------------------------------------------------
 * 功能: 校验 32 位字数组的 CRC-32 值是否与期望值匹配。
 *
 * 参数:
 *   Data   - 指向待校验数据的 32 位字数组指针
 *   Len    - 待校验的 32 位字个数
 *   ExpCrc - 期望的 CRC-32 校验值
 *
 * 返回: 校验成功返回 1，失败返回 0。
 *
 * 说明:
 *   内部调用 Crc32CalcU32 计算实际 CRC 值，然后与 ExpCrc 比较。
 *===========================================================================*/
uint32_t Crc32CheckU32(volatile uint32_t *Data, uint32_t Len,uint32_t ExpCrc)
{
    uint32_t Crc;

    /* 调用 Crc32CalcU32 计算当前数据的 CRC-32 值 */
    Crc = Crc32CalcU32(Data, Len);

    /* 比对计算结果与期望值，一致返回 1（成功），否则返回 0（失败） */
    if (Crc != ExpCrc)
    {
        return 0U;
    }
    return 1U;
}
uint32_t CrcCheck(uint32_t CrcAddr, volatile uint32_t *DataBuf, uint32_t Count)
{
    uint32_t TimeOutCnt = 0U;
    uint32_t ExpCrcVal = 0U;

    /* 轮询等待FPGA写入CRC值（最大等待10微秒） */
    while (TimeOutCnt <= TIMEOUT_US(10))
    {
        ExpCrcVal = EMIFA_WR32(CrcAddr);

        GPIOPinWrite(SOC_GPIO_0_REGS,103,1);

        if (ExpCrcVal != 0U)
        {
            /* FPGA已准备就绪，执行CRC校验 */
            return Crc32CheckU32(DataBuf, Count, ExpCrcVal);
        }
        TimeOutCnt++;
    }
    /* 超时：FPGA未在预期时间内完成计算 */
    return FALSE;
}


void Delay_US(int time_US)
{
    uint32_t TimeOutCnt = 0;

    while (TimeOutCnt <= TIMEOUT_US(time_US))
    {
        TimeOutCnt++;
    }

}

