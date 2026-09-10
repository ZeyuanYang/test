/*
 * flash_Set.h
 *
 *  Created on: 2025年10月13日
 *      Author: yzy
 */

#ifndef FLASH_SET_H_
#define FLASH_SET_H_

#include "hw_types.h"
#include "Result.h"
#include "soc_C6748.h"
#include "stdint.h"
#include <stdio.h>
#include "emifa.h"
#include "PinMultiplex.h"
#define MAX_TIMEOUT	0x7FFFFFFF   // A ceiling constant used by Check_Toggle_



#define 	SECTOR_SIZE	     	0x10000     //128kb

#define     MAX_SECTOR_NUM   	128

#define     BUFFERSIZE          0x8080


// FLASH 地址
#define FLASH_ADR1                (SOC_EMIFA_CS2_ADDR+(0x555<<1))

#define FLASH_ADR2                (SOC_EMIFA_CS2_ADDR+(0x2aa<<1))

#define FLASH_ADR3                (SOC_EMIFA_CS2_ADDR+(0x000<<1))
#define sysAddress(offset)    ((volatile short*)(SOC_EMIFA_CS2_ADDR+(offset)*2))

#define Programaddres 0x0

#define MANUFAC_ID           0x0001  // CYPRESS Manufacturer's ID code
#define flash_ID1            0x227E  // S29GL064S device code  0x01 0x22c4  0x2249
#define flash_ID2            0x220C  // S29GL064S device code  0x02 0xc4    0x49
#define flash_ID3            0x2201  // S29GL064S device code



void EMIFA_Flash_Setup(void);
int read_FlashID();
int Nor_FLASH_test(RESULT* result);
void flash_erase_and_writetest();
int Check_Toggle();
int chip_erase();
void section_erase(uint32_t SectorNum);
int Program_One_Sector (short* SrcWord,unsigned int Dst,unsigned int BufSize);
int Nor_FLASH_Check(unsigned int BufByteSize);
#endif /* FLASH_SET_H_ */
