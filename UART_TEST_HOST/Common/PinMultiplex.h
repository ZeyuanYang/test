/*
 * PinMultiplex.h
 *
 *  Created on: 2025Äê9ÔÂ22ÈÕ
 *      Author: 18832
 */

#ifndef PINMULTIPLEX_H_
#define PINMULTIPLEX_H_
#include "main.h"

extern void EMIFAPinMuxSetup(void);
extern void GPIOBankPinMuxSet(void);
extern void I2CPinMuxSetup(unsigned int instanceNum);
extern void SPIPinMuxSetup(unsigned int instanceNum);
extern void UARTPinMuxSetup(unsigned int instanceNum,unsigned int modemCtrlChoice);
extern void uPPPinMuxSetup(unsigned char OperatingMode);
extern void mcbspPinMuxSetup(void);
void mcbsp_GPIO_PinMuxSetup(void);
void  Peripheral_PinMultiplex_Set(void);
#endif /* PINMULTIPLEX_H_ */
