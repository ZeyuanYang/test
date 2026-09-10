/*
 * upp_Set.h
 *
 *  Created on: 2025年9月24日
 *      Author: 18832
 */

#ifndef UPP_SET_H_
#define UPP_SET_H_
#include "soc_C6748.h"
#include "upp.h"
#include "interrupt.h"
#include "psc.h"			        // 电源与睡眠控制宏及设备抽象层函数声明

volatile int upp_interrupt_count = 0;
volatile int upp_error_count = 0;
void OmaplFpgauPPSetup(void);
void uPPIsr(void);


#endif /* UPP_SET_H_ */
