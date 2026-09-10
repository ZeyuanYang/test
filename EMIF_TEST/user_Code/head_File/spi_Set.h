/*
 * spi_Set.h
 *
 *  Created on: 2025年9月24日
 *      Author: 18832
 */

#ifndef SPI_SET_H_
#define SPI_SET_H_
#include "soc_C6748.h"
#include "spi.h"
#include "Result.h"
// SPI 管脚配置
#define SIMO_SOMI_CLK_CS        0x00000E01
#define CHAR_LENGTH             0x8
void SPIInit(void);
void SPIDataFormatConfig(unsigned int dataFormat);
void SPI0CSPinMuxSetup(unsigned int csPinNum);
void SPI1CSPinMuxSetup(unsigned int csPinNum);
void SPIInterruptInit(void);
void HI_8435_Spi_write0_test();
void HI_8435_Spi_read_test(RESULT* result);
void SpiTransfer(void);
void SPIIsr(void);


void spi_Test(RESULT* result);
#endif /* SPI_SET_H_ */
