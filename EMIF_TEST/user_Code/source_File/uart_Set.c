///*
// * uart_Set.c
// *
// *  Created on: 2025年9月23日
// *      Author: 18832
// */
//#include "uart_Set.h"
//
//void UART_0_Init(void)
//{
//    UARTConfigSetExpClk(SOC_UART_0_REGS, UART_0_FREQ, BAUD_9600, UART_WORDL_8BITS, UART_OVER_SAMP_RATE_16);
//	// 使能 UART1
//	UARTEnable(SOC_UART_0_REGS);
//}
//
//void UART_1_Init(void)
//{
//    UARTConfigSetExpClk(SOC_UART_1_REGS, UART_1_FREQ, BAUD_9600, UART_WORDL_8BITS, UART_OVER_SAMP_RATE_16);
//	// 使能 UART1
//	UARTEnable(SOC_UART_1_REGS);
//
//////    /* Enabling the FIFO and flushing the Tx and Rx FIFOs.*/
//	UARTFIFOEnable(SOC_UART_1_REGS);
//////    /* Setting the UART Receiver Trigger Level*/
//	UARTFIFOLevelSet(SOC_UART_1_REGS, UART_RX_TRIG_LEVEL_1);
//}
//
//void UART_2_Init(void)
//{
//    UARTConfigSetExpClk(SOC_UART_2_REGS, UART_2_FREQ, BAUD_9600, UART_WORDL_8BITS, UART_OVER_SAMP_RATE_16);
//	// 使能 UART1
//	UARTEnable(SOC_UART_2_REGS);
//}
//
//void  uart_test(RESULT* result)
//{
//	unsigned char i;
//	unsigned char Receive;
//	// 发送缓存
////	char Send[] = "Hello,uart1 this is uart0.I'm fine!\n\r";
//	char Send[] = {0x55};
//	UARTPinMuxSetup(0, FALSE);
//	UARTPinMuxSetup(1, FALSE);
//	UART_0_Init();
//	UART_1_Init();
//
//	for(i = 0; i < sizeof(Send); i++)
//		UARTCharPut(SOC_UART_0_REGS, Send[i]);
//	while(1)
//	{
//		Receive=UARTCharGet(SOC_UART_0_REGS);
//		if(Receive == 0x55)
//		{
//			result->uart_Test_Result = true;
//			break;
//		}
//		else
//		{
//			result->uart_Test_Result = false;
//			break;
//		}
//	}
//}
//
//void sendTestResult(RESULT* result)
//{
//	char* send;
//	unsigned int i;
//	send = (char*)result;
//	UARTPinMuxSetup(1, FALSE);
//	UART_1_Init();
//	for(i = 0; i < sizeof(RESULT); i++)
//	{
//		UARTCharPut(SOC_UART_1_REGS, send[i]);
//		Delay(0xffff);
//		printf("%c",send[i]);
//	}
//
//	printf("ODSP test result send success!\n");
//}
//
//
//
