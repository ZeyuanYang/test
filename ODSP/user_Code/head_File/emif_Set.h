/*
 * emif_Test.h
 *
 *  Created on: 2025年9月23日
 *      Author: 18832
 */

#ifndef EMIF_TEST_H_
#define EMIF_TEST_H_

#include "soc_C6748.h"			    // DSP C6748 外设寄存器
#include "emifa.h"
#include "PinMultiplex.h"
#include "Result.h"
void EMIFASetup(void);



void emif_Test(RESULT* result);



#endif /* EMIF_TEST_H_ */
