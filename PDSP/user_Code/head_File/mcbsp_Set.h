/*
 * mcbsp_Set.h
 *
 *  Created on: 2025Äê9ÔÂ25ÈÕ
 *      Author: 18832
 */

#ifndef MCBSP_SET_H_
#define MCBSP_SET_H_
#include "main.h"
#include "Result.h"

void McBSP0InterruptInit(void);
void McBSP0ISR_TX(void);
void McBSP0ISR_RX(void);
void McBSP1ISR_TX(void);
void McBSP1ISR_RX(void);
void McBSP0Init(void);

void mcbsp_test(RESULT* result);
#endif /* MCBSP_SET_H_ */
