/*
 * nvram_Set.h
 *
 *  Created on: 2025Äê10ÔÂ21ÈÕ
 *      Author: yzy
 */

#ifndef NVRAM_SET_H_
#define NVRAM_SET_H_

#include "emif_Set.h"
#include "Result.h"
int nvram_Write_test(unsigned int Address,unsigned int Data_length);

int nvram_Read_test(unsigned int Address,unsigned int Data_length,RESULT* result);

void nvram_order_set(void);

void nvram_test(RESULT* result);





#endif /* NVRAM_SET_H_ */
