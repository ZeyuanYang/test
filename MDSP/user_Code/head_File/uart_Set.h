/*
 * uart_Set.h
 *
 *  Created on: 2025Äê9ÔÂ23ÈÕ
 *      Author: yzy
 */

#ifndef UART_SET_H_
#define UART_SET_H_

#include "uart.h"
#include "PinMultiplex.h"
#include "soc_C6748.h"
#include "hw_types.h"
#include "Result.h"
#include "interrupt.h"

#define SYSCLK_1_FREQ   (456000000)
#define SYSCLK_2_FREQ   (SYSCLK_1_FREQ/2)
#define UART_0_FREQ     (SYSCLK_2_FREQ)
#define UART_1_FREQ     (SYSCLK_2_FREQ)
#define UART_2_FREQ     (SYSCLK_2_FREQ)


void UART_0_Init(void);

void UART_1_Init(void);

void UART_2_Init(void);

void uart_test(RESULT* result);

void ConfigureIntUART1(void);

void ConfigureIntUART0(void);

void UART1Isr();

void UART0Isr();
#endif /* UART_SET_H_ */
