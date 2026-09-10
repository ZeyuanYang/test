///*
// * uart_Set.c
// *
// *  Created on: 2025年9月23日
// *      Author: 18832
// */
//#include "uart_Set.h"
////#define ODSP_TESTRESULT_ADDR (0x11710000)
//char Send[] = {0xaa};
////unsigned char* receiveAddr = (unsigned char*)ODSP_TESTRESULT_ADDR;
//void UART_0_Init(void)
//{
//	// 配置 UART0 参数
//	// 波特率 115200 数据位 8 停止位 1 无校验位
//    UARTConfigSetExpClk(SOC_UART_0_REGS, UART_0_FREQ, BAUD_9600, UART_WORDL_8BITS, UART_OVER_SAMP_RATE_16);
//	// 使能 UART0
//	UARTEnable(SOC_UART_0_REGS);
//////    /* Enabling the FIFO and flushing the Tx and Rx FIFOs.*/
//    UARTFIFOEnable(SOC_UART_0_REGS);
//////    /* Setting the UART Receiver Trigger Level*/
//    UARTFIFOLevelSet(SOC_UART_0_REGS, UART_RX_TRIG_LEVEL_1);
//}
//
//void UART_1_Init(void)
//{
//	// 配置 UART1 参数
//	// 波特率 115200 数据位 8 停止位 1 无校验位
//    UARTConfigSetExpClk(SOC_UART_1_REGS, UART_1_FREQ, BAUD_9600, UART_WORDL_8BITS, UART_OVER_SAMP_RATE_16);
//	// 使能 UART1
//	UARTEnable(SOC_UART_1_REGS);
////    /* Enabling the FIFO and flushing the Tx and Rx FIFOs.*/
//    UARTFIFOEnable(SOC_UART_1_REGS);
//////    /* Setting the UART Receiver Trigger Level*/
//    UARTFIFOLevelSet(SOC_UART_1_REGS, UART_RX_TRIG_LEVEL_1);
//}
//
//
//void uart_test(RESULT* result)
//{
//	unsigned char i;
//	unsigned char Receive;
//	// 发送缓存
////	char Send[] = "Hello,uart1 this is uart0.I'm fine!\n\r";
//	char Send[] = {0x55};
////	UARTPinMuxSetup(0, FALSE);
////	UARTPinMuxSetup(1, FALSE);
////	UART_0_Init();
////	UART_1_Init();
//
//	for(i = 0; i < sizeof(Send); i++)
//		UARTCharPut(SOC_UART_0_REGS, Send[i]);
//	while(1)
//	{
//		Receive=UARTCharGet(SOC_UART_0_REGS);
//		if(Receive == 0x5)
//		{
//			result->MDSP_uart_Test_Result = true;
//			break;
//		}
//		else
//		{
//			result->MDSP_uart_Test_Result = false;
//			break;
//		}
//	}
//}
//
///****************************************************************************/
///*                                                                          */
///*              设置UART0中断                                                 										*/
///*                                                                          */
///****************************************************************************/
//void ConfigureIntUART0(void)
//{
//	IntRegister(C674X_MASK_INT5, UART0Isr);
//	IntEventMap(C674X_MASK_INT5, SYS_INT_UART0_INT);
//	IntEnable(C674X_MASK_INT5);
//}
///****************************************************************************/
///*                                                                          */
///*              设置UART1中断                                                 										*/
///*                                                                          */
///****************************************************************************/
//void ConfigureIntUART1(void)
//{
//	IntRegister(C674X_MASK_INT4, UART1Isr);
//	IntEventMap(C674X_MASK_INT4, SYS_INT_UART1_INT);
//	IntEnable(C674X_MASK_INT4);
//}
///****************************************************************************/
///*                                                                          */
///*              UART0中断处理函数                                      										*/
///*                                                                          */
///****************************************************************************/
//
//void UART0Isr()
//{
//    static unsigned int length = sizeof(Send);
//    static unsigned int count = 0;
//    unsigned char rxData = 0;
//    unsigned int int_id = 0,i=0;
//
//    /* This determines the cause of UART2 interrupt.*/
//    int_id = UARTIntStatus(SOC_UART_0_REGS);
//
//    // Clear UART1 system interrupt in DSPINTC
//    IntEventClear(SYS_INT_UART0_INT);
//
//
////    /* Checked if the cause is transmitter empty condition.*/
////    if(UART_INTID_TX_EMPTY == int_id)
////    {
////        if(0 < length)
////        {
////            /* Write a byte into the THR if THR is free. */
////            UARTCharPutNonBlocking(SOC_UART_0_REGS, Send[count]);
////            length--;
////            count++;
////        }
////        if(0 == length)
////        {
////            /* Disable the Transmitter interrupt in UART.*/
////            UARTIntDisable(SOC_UART_0_REGS, UART_INT_TX_EMPTY);
////        }
////     }
//
//    /* Check if the cause is receiver data condition.*/
//    if(UART_INTID_RX_DATA == int_id)
//    {
//        rxData = UARTCharGetNonBlocking(SOC_UART_0_REGS);
//        UARTCharPutNonBlocking(SOC_UART_0_REGS, rxData);
//        if(rxData == 0xa5)
//        {
//        	printf("串口正在接收ODSP发来的数据...\n");
//        }
//        receiveAddr[i] = rxData;
//        i++;
//    }
//
//
//    /* Check if the cause is receiver line error condition.*/
//    if(UART_INTID_RX_LINE_STAT == int_id)
//    {
//        while(UARTRxErrorGet(SOC_UART_0_REGS))
//        {
//            /* Read a byte from the RBR if RBR has data.*/
//            UARTCharGetNonBlocking(SOC_UART_0_REGS);
//        }
//    }
//    return;
//}
///****************************************************************************/
///*                                                                          */
///*              UART1中断处理函数                                      										*/
///*                                                                          */
///****************************************************************************/
//
//void UART1Isr()
//{
//    static unsigned int length = sizeof(Send);
//    static unsigned int count = 0;
//    unsigned char rxData = 0;
//    unsigned int int_id = 0,i=0;
//
//    /* This determines the cause of UART2 interrupt.*/
//    int_id = UARTIntStatus(SOC_UART_1_REGS);
//
//    // Clear UART1 system interrupt in DSPINTC
//    IntEventClear(SYS_INT_UART1_INT);
//
//
//    /* Checked if the cause is transmitter empty condition.*/
////    if(UART_INTID_TX_EMPTY == int_id)
////    {
////        if(0 < length)
////        {
////            /* Write a byte into the THR if THR is free. */
////            UARTCharPutNonBlocking(SOC_UART_1_REGS, Send[count]);
////            length--;
////            count++;
////        }
////        if(0 == length)
////        {
////            /* Disable the Transmitter interrupt in UART.*/
////            UARTIntDisable(SOC_UART_1_REGS, UART_INT_TX_EMPTY);
////        }
////     }
//
//    /* Check if the cause is receiver data condition.*/
////    if(UART_INTID_RX_DATA == int_id)
////    {
////        rxData = UARTCharGetNonBlocking(SOC_UART_1_REGS);
////        UARTCharPutNonBlocking(SOC_UART_1_REGS, rxData);
////
////        printf("%c ",rxData);
////    }
//    if(UART_INTID_RX_DATA == int_id)
//    {
//        rxData = UARTCharGetNonBlocking(SOC_UART_1_REGS);
//        UARTCharPutNonBlocking(SOC_UART_1_REGS, rxData);
//        if(rxData == 0xa5)
//        {
//        	printf("串口正在接收ODSP发来的数据...\n");
//        }
////        receiveAddr[i] = rxData;
//        i++;
//    }
//
//    /* Check if the cause is receiver line error condition.*/
//    if(UART_INTID_RX_LINE_STAT == int_id)
//    {
//        while(UARTRxErrorGet(SOC_UART_1_REGS))
//        {
//            /* Read a byte from the RBR if RBR has data.*/
//            UARTCharGetNonBlocking(SOC_UART_1_REGS);
//        }
//    }
//    return;
//}
//
//
//
