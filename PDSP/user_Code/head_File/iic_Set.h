/*
 * iic_Set.h
 *
 *  Created on: 2025年9月24日
 *      Author: 18832
 */

#ifndef IIC_SET_H_
#define IIC_SET_H_
#include "soc_C6748.h"
#include "i2c.h"
#include "interrupt.h"              // DSP C6748 中断相关应用程序接口函数声明及系统事件号定义
#include "Result.h"

#define ADDRESS  0x48

void IICInit(void);
void InterruptInit();
void IICInterruptInit(void);
void IICSend(unsigned int iic, unsigned int dataCnt);
void IICReceive(unsigned int iic, unsigned int dataCnt);
void IICIsr(void);
unsigned char LtC2991_Read(unsigned int Address);
void tlc_ByteWrite(unsigned int Address, unsigned char Data);
void TLC_2991_AckPolling(void);
extern void Delay(volatile unsigned int delay);
void set_Tlc2991();
void test_Tlc2991(RESULT* result);

void IIC_test(RESULT* result);





#endif /* IIC_SET_H_ */
