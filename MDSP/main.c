/*
 * main.c
 *
 *  Created on: 2025年9月22日
 *      Author: yzy
 */
#include <stdio.h>
#include <string.h>
#include "soc_C6748.h"			    // DSP C6748 外设寄存器
#include "PinMultiplex.h"
#include "gpio.h"
#include "uart.h"
//include "uart_Set.h"#
#include "psc_Set.h"
#include "spi_Set.h"
#include "Result.h"
#include "PLL_Config.h"
#include "timer.h"
#include "emif_Set.h"
#include "flash_Set.h"
#include "com_Fpga.h"
#include "data_Set.h"
#include "string.h"
#include "result_Report.h"
#include "interrupt.h"
#include "mcbsp_Set.h"
// 软件断点
#define SW_BREAKPOINT   asm(" SWBP 0 ");
RESULT my_Result;
/*
 * 定时器计数阈值
 * */
// 低32位
#define TMR_PERIOD_LSB32  (0x5F5E100)  //0x0D970100 0xc845880  0x5F5E100
// 高32位
#define TMR_PERIOD_MSB32  (0)
#define ODSP_TESTRESULT_ADDR (0x11F00100)//0x00F00000//0x11700000
#define PDSP_TESTRESULT_ADDR (0x11F00130)
#define SYSCLK_1_FREQ   (456000000)
#define SYSCLK_2_FREQ   (SYSCLK_1_FREQ/2)
#define UART_0_FREQ     (SYSCLK_2_FREQ)
#define UART_1_FREQ     (SYSCLK_2_FREQ)
#define UART_2_FREQ     (SYSCLK_2_FREQ)
//#define SYSCLK_1_FREQ   (300000000)
//#define UART_0_FREQ     SYSCLK_1_FREQ
//#define SYSCLK_2_FREQ   (210000000)
//#define UART_1_FREQ     SYSCLK_2_FREQ
//#define UART_2_FREQ     SYSCLK_2_FREQ

void TimerIsr(void);
void TimerInterruptInit(void);
void TimerInit(void);
static void SetupInt(void);
static void ConfigureIntUART1(void);
static void ConfigureIntUART0(void);
void mcbsp_gpio_dir_set();
void UART_1_Init(void);
void UART_0_Init(void);
static void UART0Isr();
static int timer_count = 0;

volatile tBoolean Flag = TRUE;
volatile tBoolean ODSP_result_rec_Flag = false;
volatile tBoolean PDSP_result_rec_Flag = false;
RESULT* mytest_Result = &my_Result;
unsigned char* receiveAddr = (unsigned char*)ODSP_TESTRESULT_ADDR;
unsigned char* receiveAddr1 = (unsigned char*)PDSP_TESTRESULT_ADDR;

int main()
{
	unsigned int intFlags0 = 0,intFlags1 = 0;

	data_Set(mytest_Result);
	// 外设使能配置
	Peripheral_Psc_Set();

	GPIOBankPinMuxSet();
	//mcbsp 管脚电平设置
	GPIODirModeSet(SOC_GPIO_0_REGS, 2, GPIO_DIR_OUTPUT); //gpio0[1]
	GPIODirModeSet(SOC_GPIO_0_REGS, 3, GPIO_DIR_OUTPUT); //gpio0[2]
	GPIODirModeSet(SOC_GPIO_0_REGS, 4, GPIO_DIR_OUTPUT); //gpio0[3]
	GPIODirModeSet(SOC_GPIO_0_REGS, 5, GPIO_DIR_OUTPUT); //gpio0[4]
	GPIODirModeSet(SOC_GPIO_0_REGS, 6, GPIO_DIR_OUTPUT); //gpio0[5]
	GPIODirModeSet(SOC_GPIO_0_REGS, 7, GPIO_DIR_OUTPUT); //gpio0[6]

	GPIODirModeSet(SOC_GPIO_0_REGS, 104, GPIO_DIR_INPUT); //gpio6[7]

	GPIODirModeSet(SOC_GPIO_0_REGS, 107, GPIO_DIR_OUTPUT); //gpio6[10]
	GPIODirModeSet(SOC_GPIO_0_REGS, 121, GPIO_DIR_OUTPUT); //GPIO7[8]

	GPIOPinWrite(SOC_GPIO_0_REGS,2,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,3,GPIO_PIN_LOW);
	GPIOPinWrite(SOC_GPIO_0_REGS,4,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,5,GPIO_PIN_LOW);
	GPIOPinWrite(SOC_GPIO_0_REGS,6,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,7,GPIO_PIN_LOW);

	GPIOPinWrite(SOC_GPIO_0_REGS,107,GPIO_PIN_LOW);
	GPIOPinWrite(SOC_GPIO_0_REGS,121,GPIO_PIN_LOW);

	//gpio6[1] 设置为输出模式
	GPIODirModeSet(SOC_GPIO_0_REGS, 98, GPIO_DIR_OUTPUT);
	//gpio8[12] 设置为输出模式，用于接收odsp数据标志
	GPIODirModeSet(SOC_GPIO_0_REGS, 141, GPIO_DIR_OUTPUT);
	//gpio8[13]
	GPIODirModeSet(SOC_GPIO_0_REGS, 142, GPIO_DIR_OUTPUT);

//	//gpio8[14] 设置为输出模式，用于mcbsp数据接收标志
//	GPIODirModeSet(SOC_GPIO_0_REGS, 143, GPIO_DIR_OUTPUT);
//	//gpio8[15]
//	GPIODirModeSet(SOC_GPIO_0_REGS, 144, GPIO_DIR_OUTPUT);

	//gpio6[8] 设置为输出模式，用于接收Pdsp数据标志
	GPIODirModeSet(SOC_GPIO_0_REGS, 105, GPIO_DIR_OUTPUT);
	//gpio6[9]
	GPIODirModeSet(SOC_GPIO_0_REGS, 106, GPIO_DIR_OUTPUT);

	//标志位清空
	GPIOPinWrite(SOC_GPIO_0_REGS, 141, GPIO_PIN_LOW);
	GPIOPinWrite(SOC_GPIO_0_REGS, 142, GPIO_PIN_HIGH);
//	GPIOPinWrite(SOC_GPIO_0_REGS, 143, GPIO_PIN_LOW);
//	GPIOPinWrite(SOC_GPIO_0_REGS, 144, GPIO_PIN_HIGH);
	//标志位清空
	GPIOPinWrite(SOC_GPIO_0_REGS, 105, GPIO_PIN_LOW);
	GPIOPinWrite(SOC_GPIO_0_REGS,106,GPIO_PIN_HIGH);
	//gpio6[3] fpga端读429flag
	GPIODirModeSet(SOC_GPIO_0_REGS, 100, GPIO_DIR_INPUT);
	//gpio6[4] fpga端读lisanliang
	GPIODirModeSet(SOC_GPIO_0_REGS, 101, GPIO_DIR_INPUT);
	//gpio6[2] fpga端读pwr
	GPIODirModeSet(SOC_GPIO_0_REGS, 99, GPIO_DIR_INPUT);
	//GPIO6[6] FPGA test&429write flag
	GPIODirModeSet(SOC_GPIO_0_REGS, 103, GPIO_DIR_INPUT);

//    //pll0系统配置系统时钟300Mhz Emif中配置为 148MHZ
//	C6748_PLLC0Init(0,10,0,0,1,2,9); //uart0  300 mhz
//	//pll2 210MHZ
//	C6748_PLLC1Init(7,0,0,1,2);  //uart1 2 210 mhz

	// 定时器 / 计数器初始化
	UARTPinMuxSetup(1, FALSE);
	UARTPinMuxSetup(0, FALSE);
	TimerInit(); //mask6
	// UART 初始化
	UART_1_Init();
	UART_0_Init();
	//DSP中断初始化
	SetupInt();

//	// 定时器 / 计数器中断初始化
	TimerInterruptInit();

    ConfigureIntUART0();//mask5
    ConfigureIntUART1();//mask4

    /* Preparing the 'intFlags' variable to be passed as an argument.*/
   intFlags0 |= (UART_INT_LINE_STAT  | UART_INT_TX_EMPTY |  UART_INT_RXDATA_CTI);
   intFlags1 |= (UART_INT_LINE_STAT  | UART_INT_TX_EMPTY |  UART_INT_RXDATA_CTI);
   // intFlags0 |= UART_INT_RXDATA_CTI;
    /* Enable the Interrupts in UART.*/
   Nor_FLASH_test(mytest_Result);

//   mcbsp_test(mytest_Result); //mask 7 8


   while(1)
   {
	   if(!(GPIOPinRead(SOC_GPIO_0_REGS,103)))
	   {
		   emif_Test(mytest_Result);
		   //接收MFPGA的数据
		   emif_429_Write();
		   break;
	   }
   }

//   memcpy((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x60000),mytest_Result,sizeof(my_Result));
	while(1)
	{
		if(GPIOPinRead(SOC_GPIO_0_REGS,100))
		{
			Delay(0xffff);
			if(GPIOPinRead(SOC_GPIO_0_REGS,101))
			{
				mytest_Result->M_fpga_lisanliang = true;
//				puts("MFPGA 离散量测试成功！\n");
			}
			else
			{
				mytest_Result->M_fpga_lisanliang = false;
//				puts("MFPGA 离散量测试失败！\n");
			}
			if(GPIOPinRead(SOC_GPIO_0_REGS,99))
			{
				mytest_Result->M_fpga_pwr_test = true;
//				puts("MFPGA pwr测试成功！\n");
			}
			else
			{
				mytest_Result->M_fpga_pwr_test = false;
//				puts("MFPGA pwr测试失败！\n");
			}
			emif_429_Read(mytest_Result);
			emif_Read_Fpga_2991(mytest_Result);
			break;
		}
		else
		{}
	}
   //读取MFpga mcbsp端口电平信号
    mcbsp_GPIO_PinMuxSetup();
    mcbsp_gpio_dir_set();
	if(GPIOPinRead(SOC_GPIO_0_REGS,26) == 1 && GPIOPinRead(SOC_GPIO_0_REGS,27) == 0 &&
			GPIOPinRead(SOC_GPIO_0_REGS,28) == 0 && GPIOPinRead(SOC_GPIO_0_REGS,29) == 1
			&& GPIOPinRead(SOC_GPIO_0_REGS,30) == 1 && GPIOPinRead(SOC_GPIO_0_REGS,31) == 0
			&& GPIOPinRead(SOC_GPIO_0_REGS,136) == 1)
	{
		mytest_Result->M_fpga_mcbsp = true;
	}
	else
	{
		mytest_Result->M_fpga_mcbsp = false;
	}

   //设置接收ODSP结果标志位
   UARTIntEnable(SOC_UART_0_REGS, intFlags0);
   GPIOPinWrite(SOC_GPIO_0_REGS, 141, GPIO_PIN_HIGH);
   GPIOPinWrite(SOC_GPIO_0_REGS, 142, GPIO_PIN_LOW);
//   puts("等待ODSP结果发送...\n");

   for(;;)
   {
	   if(ODSP_result_rec_Flag == true)
	   {
		   my_Result.ODSP_uart_Test_Result = TRUE;
		   my_Result.ODSP_mcbsp_Test_Result = *((unsigned char*)(ODSP_TESTRESULT_ADDR+3));
		   my_Result.MDSP_uart_Test_Result = TRUE;
		   my_Result.MDSP_mcbsp_Test_Result = *((unsigned char*)(ODSP_TESTRESULT_ADDR+4));
		   my_Result.ODSP_IIC_Test_Result = *((unsigned char*)(ODSP_TESTRESULT_ADDR+6));
		   my_Result.ODSP_emif_Test_Result = *((unsigned char*)(ODSP_TESTRESULT_ADDR+7));
		   my_Result.ODSP_flash_Test_Result = *((unsigned char*)(ODSP_TESTRESULT_ADDR+8));
		   my_Result.ODSP_NVRAM_Test_Result = *((unsigned char*)(ODSP_TESTRESULT_ADDR+9));
		   my_Result.ODSP_voltage_1 = *((unsigned short int*)(ODSP_TESTRESULT_ADDR+10));
		   my_Result.ODSP_voltage_2 = *((unsigned short int*)(ODSP_TESTRESULT_ADDR+12));
		   my_Result.ODSP_voltage_3 = *((unsigned short int*)(ODSP_TESTRESULT_ADDR+14));
		   my_Result.ODSP_voltage_4 = *((unsigned short int*)(ODSP_TESTRESULT_ADDR+16));
		   my_Result.ODSP_temperature_1 = *((unsigned short int*)(ODSP_TESTRESULT_ADDR+18));
		   my_Result.ODSP_temperature_2 = *((unsigned short int*)(ODSP_TESTRESULT_ADDR+20));
//		   puts("ODSP 测试结果整合完成！\n");
		   break;
	   }
   }

   //发送PDSP串口启动标志位
   UARTIntEnable(SOC_UART_1_REGS, intFlags1);
   GPIOPinWrite(SOC_GPIO_0_REGS, 105, GPIO_PIN_HIGH);
   GPIOPinWrite(SOC_GPIO_0_REGS, 106, GPIO_PIN_LOW);
   //采用轮训方式接收PDSP数据
//   int i =0;
//   char receive;
//   while(1)
//   {
//	   receive  = UARTCharGet(SOC_UART_1_REGS);
//	   *(receiveAddr1++) =  receive;
//	   i++;
//	   if(receive == 0x5a)
//	   {
//		   break;
//	   }
//   }
//
//   //printf("等待PDSP结果发送...\n");
   for(;;)
   {
	   if(PDSP_result_rec_Flag == true)
	   {
		   my_Result.PDSP_uart_Test_Result = TRUE;
		   my_Result.PDSP_mcbsp_Test_Result = *((unsigned char*)(ODSP_TESTRESULT_ADDR+5));
		   my_Result.PDSP_spi_Test_Result = *((char*)(PDSP_TESTRESULT_ADDR+4));
		   my_Result.PDSP_spi_HI8435_Test_Result = *((char*)(PDSP_TESTRESULT_ADDR+5));
		   my_Result.PDSP_emif_Test_Result = *((char*)(PDSP_TESTRESULT_ADDR+6));
		   my_Result.PDSP_flash_Test_Result = *((char*)(PDSP_TESTRESULT_ADDR+7));
		   my_Result.PDSP_power_Test_Result = *((char*)(PDSP_TESTRESULT_ADDR+8));
		   my_Result.p_fpga_lisanliang = *((char*)(PDSP_TESTRESULT_ADDR+9));
		   my_Result.P_fpga_429_channel1 = *((char*)(PDSP_TESTRESULT_ADDR+10));
		   my_Result.P_fpga_mcbsp = *((char*)(PDSP_TESTRESULT_ADDR+11));
		   my_Result.P_fpga_voltage_1 = *((unsigned short int*)(PDSP_TESTRESULT_ADDR+13));
		   my_Result.P_fpga_voltage_2 = *((unsigned short int*)(PDSP_TESTRESULT_ADDR+15));
		   my_Result.P_fpga_voltage_3 = *((unsigned short int*)(PDSP_TESTRESULT_ADDR+17));
		   my_Result.P_fpga_voltage_4 = *((unsigned short int*)(PDSP_TESTRESULT_ADDR+19));
		   my_Result.P_fpga_temperature_1 = *((unsigned short int*)(PDSP_TESTRESULT_ADDR+21));
//		   printf("PDSP 测试结果整合完成！\n");
		   break;
	   }
   }
//   uart_test(mytest_Result);
//	IIC_test(mytest_Result);//Odsp D8
////mcbsp_test(mytest_Result);
//	spi_Test(mytest_Result);//PDSP D2
//	emif_Test(mytest_Result);
	/*
	 * 将测试结果发送至fpga
	 */
//	memcpy((int*)SOC_EMIFA_CS3_ADDR,mytest_Result,sizeof(my_Result));

//	while(1)
//	{
//		switch(timer_count)
//		{
//			case 0:
////				uart_test(mytest_Result);
//				break;
//			case 3:
////				IIC_test(mytest_Result);
//				break;
//			case 6:
////				mcbsp_test(mytest_Result);
//				break;
//			case 9:
//					spi_Test(mytest_Result);
//				break;
//			case 12:
////				emif_Test(mytest_Result);
//				break;
//			default:
//				break;
//		}
//
//		if(timer_count>16)
//		{
//			printf("测试结束，等待上报测试结果......\n");
//			break;
//		}
//	}
//   int i,j;
//	memcpy((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x60000),mytest_Result,sizeof(my_Result));
//   for(j=0;j<1;j++)
//   {
//	   for(i=0;i<sizeof(test);i++)
//	   {
//		   *((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x60000)) = test[i] ;
////		   Delay(0xfff);
//
//	   }
//   }

//    result_send_test();
//	resultPrint(mytest_Result);
	Delay(0xfff);
	PrintResult_O(mytest_Result);
	Delay(0xfff);
	PrintResult_M(mytest_Result);
	Delay(0xfff);
	PrintResult_P(mytest_Result);
/*
 * 测试软件版本号查询
 * */
//	while(1)
//	{
//		   if(GPIOPinRead(SOC_GPIO_0_REGS,104))
//		   {
//			   emif_print_soft_version();
//			   break;
//		   }
//	}
//flash擦除指令
//	while(1)
//	{
//		if((*((unsigned short int *)(SOC_EMIFA_CS3_ADDR+0x100000))) == 0xfefe)
//		{
//
//			//给ODSP 和 PDSP分别发送flash内存擦除指令
//			GPIOPinWrite(SOC_GPIO_0_REGS,107,GPIO_PIN_HIGH);
//			GPIOPinWrite(SOC_GPIO_0_REGS,121,GPIO_PIN_HIGH);
//
//			//gpio给ODSP和MDSP分别发送信号
//
//			//延时一段时间，保证收到信号
//			Delay(0xffff);
//
//			//开始MDSP flash芯片擦除
//			EMIFA_Flash_Setup();
//			chip_erase();
//			break;
//		}
//
//	}




//	puts("测试结果已经上报完成！\n");
	for(;;)
	{

	}
}
/****************************************************************************/
/*                                                                          */
/*             设置中断                                                 										*/
/*                                                                          */
/****************************************************************************/
static void SetupInt(void)
{

	// Initialize the DSP INTC
	IntDSPINTCInit();

	// Enable DSP interrupts globally
	IntGlobalEnable();
}
/****************************************************************************/
/*                                                                          */
/*              定时器 / 计数器初始化                                       */
/*                                                                          */
/****************************************************************************/
void TimerInit(void)
{
    // 配置 定时器 / 计数器 2 为 64 位模式
    TimerConfigure(SOC_TMR_2_REGS, TMR_CFG_64BIT_CLK_INT);

    // 设置周期
    TimerPeriodSet(SOC_TMR_2_REGS, TMR_TIMER12, TMR_PERIOD_LSB32);
    TimerPeriodSet(SOC_TMR_2_REGS, TMR_TIMER34, TMR_PERIOD_MSB32);

    // 使能 定时器 / 计数器 2
    TimerEnable(SOC_TMR_2_REGS, TMR_TIMER12, TMR_ENABLE_CONT);
}

/****************************************************************************/
/*                                                                          */
/*              定时器 / 计数器中断初始化                                   */
/*                                                                          */
/****************************************************************************/
void TimerInterruptInit(void)
{
	// 注册中断服务函数
	IntRegister(C674X_MASK_INT6, TimerIsr);

	// 映射中断到 DSP 可屏蔽中断
	IntEventMap(C674X_MASK_INT6, SYS_INT_T64P2_TINTALL);

	// 使能 DSP 可屏蔽中断
	IntEnable(C674X_MASK_INT6);

	// 使能 定时器 / 计数器 中断
	TimerIntEnable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
}
/****************************************************************************/
/*                                                                          */
/*              定时器中断服务函数                                                */
/*                                                                          */
/****************************************************************************/

void TimerIsr(void)
{
    // 禁用定时器 / 计数器中断
    TimerIntDisable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

    // 清除中断标志
    IntEventClear(SYS_INT_T64P2_TINTALL);

    TimerIntStatusClear(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

//    // 改变 LED 状态
     GPIOPinWrite(SOC_GPIO_0_REGS, 98, Flag);
     Flag=!Flag;
     GPIOPinWrite(SOC_GPIO_0_REGS, 98, Flag);
//    printf("entrance timer interupt...\n");
//    test++;
    //每秒发送一个字符
//    UARTCharPut(SOC_UART_1_REGS, Send[0]);
//    UARTCharPut(SOC_UART_0_REGS, Send[0]);
//
//   if(count == sizeof(Send))
//   {
//	   count = 0;
//   }
    // 重新设置初始值
//    printf("This is a timer print test!\n");
    timer_count++;
    sendTime++;

    // 重新设置初始值
    TimerInit();

    // 使能 定时器 / 计数器 中断
    TimerIntEnable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
}
/****************************************************************************/
/*                                                                          */
/*              UART1中断处理函数                                      										*/
/*                                                                          */
/****************************************************************************/

static void UART1Isr()
{
    static unsigned int length = 0;
    static unsigned int count = 0;
    unsigned char rxData = 0;
    unsigned int int_id = 0,i=0;

    /* This determines the cause of UART2 interrupt.*/
    int_id = UARTIntStatus(SOC_UART_1_REGS);

    // Clear UART1 system interrupt in DSPINTC
    IntEventClear(SYS_INT_UART1_INT);


    /* Checked if the cause is transmitter empty condition.*/
    if(UART_INTID_TX_EMPTY == int_id)
    {
        if(0 < length)
        {
//            /* Write a byte into the THR if THR is free. */
//            UARTCharPutNonBlocking(SOC_UART_1_REGS, Send[count]);
//            length--;
//            count++;
        }
        if(0 == length)
        {
            /* Disable the Transmitter interrupt in UART.*/
            UARTIntDisable(SOC_UART_1_REGS, UART_INT_TX_EMPTY);
        }
     }

    /* Check if the cause is receiver data condition.*/
//    if(UART_INTID_RX_DATA == int_id)
//    {
//        rxData = UARTCharGetNonBlocking(SOC_UART_1_REGS);
//        UARTCharPutNonBlocking(SOC_UART_1_REGS, rxData);
//
//        printf("%c ",rxData);
//    }
    if(UART_INTID_RX_DATA == int_id)
    {
        rxData = UARTCharGetNonBlocking(SOC_UART_1_REGS);
        UARTCharPutNonBlocking(SOC_UART_1_REGS, rxData);
        if(rxData == 0xa5)
        {
       // 	puts("串口正在接收PDSP发来的数据...\n");
        }
        *(receiveAddr1++) = rxData;
        if(rxData == 0x5a)
        {
       // 	puts("串口接收PDSP发来的数据完成！\n");
        	PDSP_result_rec_Flag = true;
        }
    }

    /* Check if the cause is receiver line error condition.*/
    if(UART_INTID_RX_LINE_STAT == int_id)
    {
        while(UARTRxErrorGet(SOC_UART_1_REGS))
        {
            /* Read a byte from the RBR if RBR has data.*/
            UARTCharGetNonBlocking(SOC_UART_1_REGS);
        }
    }
    return;
}
/****************************************************************************/
/*                                                                          */
/*              设置UART1中断                                                 										*/
/*                                                                          */
/****************************************************************************/
static void ConfigureIntUART1(void)
{
	IntRegister(C674X_MASK_INT4, UART1Isr);
	IntEventMap(C674X_MASK_INT4, SYS_INT_UART1_INT);
	IntEnable(C674X_MASK_INT4);
}
/****************************************************************************/
/*                                                                          */
/*              UART 初始化                                                 */
/*                                                                          */
/****************************************************************************/
void UART_1_Init(void)
{
	// 配置 UART1 参数
	// 波特率 115200 数据位 8 停止位 1 无校验位
    UARTConfigSetExpClk(SOC_UART_1_REGS, UART_1_FREQ, BAUD_9600, UART_WORDL_8BITS, UART_OVER_SAMP_RATE_16);
	// 使能 UART1
	UARTEnable(SOC_UART_1_REGS);
//    /* Enabling the FIFO and flushing the Tx and Rx FIFOs.*/
    UARTFIFOEnable(SOC_UART_1_REGS);
////    /* Setting the UART Receiver Trigger Level*/
    UARTFIFOLevelSet(SOC_UART_1_REGS, UART_RX_TRIG_LEVEL_1);
}

/****************************************************************************/
/*                                                                          */
/*              设置UART0中断                                                 										*/
/*                                                                          */
/****************************************************************************/
static void ConfigureIntUART0(void)
{
	IntRegister(C674X_MASK_INT5, UART0Isr);
	IntEventMap(C674X_MASK_INT5, SYS_INT_UART0_INT);
	IntEnable(C674X_MASK_INT5);
}
/****************************************************************************/
/*                                                                          */
/*              UART0中断处理函数                                      										*/
/*                                                                          */
/****************************************************************************/

static void UART0Isr()
{
    static unsigned int length = 0;
    static unsigned int count = 0;
    unsigned char rxData = 0;
    unsigned int int_id = 0,i=0;

    /* This determines the cause of UART2 interrupt.*/
    int_id = UARTIntStatus(SOC_UART_0_REGS);

    // Clear UART1 system interrupt in DSPINTC
    IntEventClear(SYS_INT_UART0_INT);


    /* Checked if the cause is transmitter empty condition.*/
    if(UART_INTID_TX_EMPTY == int_id)
    {
        if(0 < length)
        {
//            /* Write a byte into the THR if THR is free. */
//            UARTCharPutNonBlocking(SOC_UART_0_REGS, Send[count]);
//            length--;
//            count++;
        }
        if(0 == length)
        {
            /* Disable the Transmitter interrupt in UART.*/
            UARTIntDisable(SOC_UART_0_REGS, UART_INT_TX_EMPTY);
        }
     }

    /* Check if the cause is receiver data condition.*/
//    if(UART_INTID_RX_DATA == int_id)
//    {
//        rxData = UARTCharGetNonBlocking(SOC_UART_0_REGS);
//        UARTCharPutNonBlocking(SOC_UART_0_REGS, rxData);
//
//        printf("%c",rxData);
//    }
	if(UART_INTID_RX_DATA == int_id)
	{

		rxData = UARTCharGetNonBlocking(SOC_UART_0_REGS);
//		rxData = UARTCharGet(SOC_UART_0_REGS);
//		UARTCharPutNonBlocking(SOC_UART_0_REGS, rxData);
		if(rxData == 0xa5)
		{
//			puts("串口正在接收ODSP发来的数据...\n");
		}
		*(receiveAddr++) = rxData;
//		i++;
//		printf("%c",rxData);
		if(rxData == 0x5a)
		{
//			puts("串口接收ODSP发来的数据完成！\n");
			ODSP_result_rec_Flag = true;
		}
		Delay(0xff);
	}

    /* Check if the cause is receiver line error condition.*/
    if(UART_INTID_RX_LINE_STAT == int_id)
    {
        while(UARTRxErrorGet(SOC_UART_0_REGS))
        {
            /* Read a byte from the RBR if RBR has data.*/
            UARTCharGetNonBlocking(SOC_UART_0_REGS);
        }
    }
    return;
}
void UART_0_Init(void)
{
	// 配置 UART0 参数
	// 波特率 115200 数据位 8 停止位 1 无校验位
    UARTConfigSetExpClk(SOC_UART_0_REGS, UART_0_FREQ, BAUD_9600, UART_WORDL_8BITS, UART_OVER_SAMP_RATE_16);
	// 使能 UART0
	UARTEnable(SOC_UART_0_REGS);
////    /* Enabling the FIFO and flushing the Tx and Rx FIFOs.*/
    UARTFIFOEnable(SOC_UART_0_REGS);
////    /* Setting the UART Receiver Trigger Level*/
    UARTFIFOLevelSet(SOC_UART_0_REGS, UART_RX_TRIG_LEVEL_1);
}

void mcbsp_gpio_dir_set()
{
	GPIODirModeSet(SOC_GPIO_0_REGS,26,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,27,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,28,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,29,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,30,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,31,GPIO_DIR_INPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,136,GPIO_DIR_INPUT);
}



