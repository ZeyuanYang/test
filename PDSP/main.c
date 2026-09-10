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
//#include "uart_Set.h"
#include "uart.h"
#include "psc_Set.h"
#include "iic_Set.h"
#include "spi_Set.h"
#include "Result.h"
#include "PLL_Config.h"
#include "timer.h"
#include "emif_Set.h"
#include "flash_Set.h"
#include "nvram_Set.h"
#include "led_Set.h"
#include "com_Fpga.h"
#include "pwr_test.h"


#define SYSCLK_1_FREQ   (456000000)   ///456
#define SYSCLK_2_FREQ   (SYSCLK_1_FREQ/2)
#define UART_0_FREQ     (SYSCLK_2_FREQ)
#define UART_1_FREQ     (SYSCLK_2_FREQ)
#define UART_2_FREQ     (SYSCLK_2_FREQ)
/**************/
/****ODSP******/
/**************/
// 软件断点
#define SW_BREAKPOINT   asm(" SWBP 0 ");
RESULT my_Result;
RESULT* mytest_Result = &my_Result;
unsigned char* send = (unsigned char*)&my_Result;
/*
 * 定时器计数阈值
 * */
// 低32位
#define TMR_PERIOD_LSB32  (0xBEBC200)  //0x0D970100 0xc845880  5F5 E100
// 高32位 0
#define TMR_PERIOD_MSB32  (0)
void TimerIsr(void);
void TimerInterruptInit(void);
void TimerInit(void);
static void ConfigureIntUART1(void);
static void SetupInt(void);
static void UART1Isr(void);
static int timer_count = 0;
volatile tBoolean Flag = TRUE;
volatile sendFlag = false;
void UART_1_Init(void);
int main()
{
	unsigned int intFlags = 0;
	RESULT* mytest_Result = &my_Result;

	//添加帧头帧尾
	mytest_Result->zhenTou = 0xa5a5;
	mytest_Result->zhenWei = 0x5a5a;

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

	GPIODirModeSet(SOC_GPIO_0_REGS, 107, GPIO_DIR_INPUT); //gpio6[10]


	GPIOPinWrite(SOC_GPIO_0_REGS,2,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,3,GPIO_PIN_LOW);
	GPIOPinWrite(SOC_GPIO_0_REGS,4,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,5,GPIO_PIN_LOW);
	GPIOPinWrite(SOC_GPIO_0_REGS,6,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,7,GPIO_PIN_LOW);

	UARTPinMuxSetup(1, FALSE);
	pwr_test(mytest_Result);

	//离散量输入
	GPIODirModeSet(SOC_GPIO_0_REGS,15,GPIO_DIR_OUTPUT);
	GPIODirModeSet(SOC_GPIO_0_REGS,16,GPIO_DIR_OUTPUT);

	//gpio6[1] 设置为输出模式
	GPIODirModeSet(SOC_GPIO_0_REGS, 98, GPIO_DIR_OUTPUT);

	//gpio6[8] 设置为输入模式，读取MDSP电平标志位
	GPIODirModeSet(SOC_GPIO_0_REGS, 105, GPIO_DIR_INPUT);
	//gpio6[9]
	GPIODirModeSet(SOC_GPIO_0_REGS, 106, GPIO_DIR_INPUT);

	//离散量输入
	GPIOPinWrite(SOC_GPIO_0_REGS,15,GPIO_PIN_HIGH);
	GPIOPinWrite(SOC_GPIO_0_REGS,16,GPIO_PIN_LOW);

	//gpio6[3] 读pfpga端429flag
	GPIODirModeSet(SOC_GPIO_0_REGS, 100, GPIO_DIR_INPUT);

	//gpio6[4] 读pfpga端lisanliang
	GPIODirModeSet(SOC_GPIO_0_REGS, 101, GPIO_DIR_INPUT);
	//GPIO6[6] FPGA test&429write flag
	GPIODirModeSet(SOC_GPIO_0_REGS, 103, GPIO_DIR_INPUT);

    //pll0系统配置系统时钟300Mhz Emif中配置为 148MHZ
//	C6748_PLLC0Init(0,10,0,0,1,2,9);
//	//sysclk2 210MHZ
//	C6748_PLLC1Init(7,0,0,1,2);

	// 定时器 / 计数器初始化
	TimerInit();//屏蔽向量5
	UART_1_Init();

	//DSP中断初始化
	SetupInt();
	ConfigureIntUART1(); //mask 6

	// 定时器 / 计数器中断初始化
	TimerInterruptInit(); //mask5
//	uart_test(mytest_Result);
//mcbsp_test(mytest_Result);
	spi_Test(mytest_Result);//PDSP D2 //mask4
	/*
	 * 将测试结果发送至fpga
	 */
	Nor_FLASH_test(mytest_Result);

	intFlags |= (UART_INT_LINE_STAT  | UART_INT_TX_EMPTY |  UART_INT_RXDATA_CTI);

//	emif_Test(mytest_Result);
//
//	//等待获取pfpga数据
//	emif_429_Write();
   while(1)
   {
	   if(!(GPIOPinRead(SOC_GPIO_0_REGS,103)))
	   {
		   emif_Test(mytest_Result);
		   //接收PFPGA的数据
		   emif_429_Write();
		   break;
	   }
   }
	//等待429读标志位
	while(1)
	{
		if(GPIOPinRead(SOC_GPIO_0_REGS,100))
		{
			if(GPIOPinRead(SOC_GPIO_0_REGS,101))
			{
				mytest_Result->p_fpga_lisanliang = true;
//				printf("PFPGA离散量测试成功！\n");
			}
			else
			{
				mytest_Result->p_fpga_lisanliang = false;
//				printf("PFPGA离散量测试失败！\n");
			}
			emif_429_Read(mytest_Result);
			emif_Read_Fpga_2991(mytest_Result);
			break;
		}
		else
		{

		}
	}
   //读取Pfpgamcbsp端口电平验证通路
    mcbsp_GPIO_PinMuxSetup();
    mcbsp_gpio_dir_set();
	if(GPIOPinRead(SOC_GPIO_0_REGS,26) == 1 && GPIOPinRead(SOC_GPIO_0_REGS,27) == 0 &&
			GPIOPinRead(SOC_GPIO_0_REGS,28) == 0 && GPIOPinRead(SOC_GPIO_0_REGS,29) == 1
			&& GPIOPinRead(SOC_GPIO_0_REGS,30) == 1 && GPIOPinRead(SOC_GPIO_0_REGS,31) == 0
			&& GPIOPinRead(SOC_GPIO_0_REGS,136) == 1)
	{
		mytest_Result->P_fpga_mcbsp = true;
	}
	else
	{
		mytest_Result->P_fpga_mcbsp = false;
	}


	//2、等待开始发送数据标志位(from D2) |GPIO6[8]
	//waite send flag
	for(;;)
	{
		//检测允许发送标志
		if(GPIOPinRead(SOC_GPIO_0_REGS,105)==1&&GPIOPinRead(SOC_GPIO_0_REGS,106)==0)
		{
			printf("PDSP准备发送数据...\n");
			break;
		}
	}
	//2、收到标志位后 串口发送测试结果 D2--->D6(uart1--->uart1)
	UARTIntEnable(SOC_UART_1_REGS, intFlags);

//	int i,temp;
//	for(i=0;i<sizeof(my_Result);i++)
//	{
//		UARTCharPut(SOC_UART_1_REGS,send[i]);
//		temp = send[i];
////		printf("%d ",temp);
////		Delay(0xffff);
//	}

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

//	emif_Test(mytest_Result);
//	memcpy((int*)SOC_EMIFA_CS3_ADDR,mytest_Result,sizeof(my_Result));
//	while(1)
//	{
//		if(GPIOPinRead(SOC_GPIO_0_REGS,107) == 1) //检测电平信号
//		{
//			EMIFA_Flash_Setup();
//			chip_erase();
//			break;
//		}
//
//	}

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
	IntRegister(C674X_MASK_INT5, TimerIsr);

	// 映射中断到 DSP 可屏蔽中断
	IntEventMap(C674X_MASK_INT5, SYS_INT_T64P2_TINTALL);

	// 使能 DSP 可屏蔽中断
	IntEnable(C674X_MASK_INT5);

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

    // 改变 LED 状态
     gpioWriteSet(Flag);
     Flag=!Flag;
     gpioWriteSet(Flag);

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

    // 重新设置初始值
    TimerInit();

    // 使能 定时器 / 计数器 中断
    TimerIntEnable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
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
    /* Enabling the FIFO and flushing the Tx and Rx FIFOs.*/
    UARTFIFOEnable(SOC_UART_1_REGS);
    /* Setting the UART Receiver Trigger Level*/
    UARTFIFOLevelSet(SOC_UART_1_REGS, UART_RX_TRIG_LEVEL_1);
}

static void ConfigureIntUART1(void)
{
	IntRegister(C674X_MASK_INT6, UART1Isr);
	IntEventMap(C674X_MASK_INT6, SYS_INT_UART1_INT);
	IntEnable(C674X_MASK_INT6);
}
static void UART1Isr()
{
    static unsigned int length = sizeof(my_Result);//sizeof(my_Result)
    static unsigned int i,count = 0;
    unsigned char rxData = 0;
    unsigned int int_id = 0;
//    char* Send = &mytest_Result;

    /* This determines the cause of UART2 interrupt.*/
    int_id = UARTIntStatus(SOC_UART_1_REGS);

    // Clear UART1 system interrupt in DSPINTC
    IntEventClear(SYS_INT_UART1_INT);

    /* Checked if the cause is transmitter empty condition.*/
    if(UART_INTID_TX_EMPTY == int_id)
    {
        if(0 < length)
        {
            /* Write a byte into the THR if THR is free. */
        	for(i=0;i<27;i++)
        	{
                UARTCharPut(SOC_UART_1_REGS, send[count]);
                length--;
                count++;
                Delay(0xffff);
        	}
 //           printf("uart working....\n");
        }
        if(0 == length)
        {
            /* Disable the Transmitter interrupt in UART.*/
            UARTIntDisable(SOC_UART_1_REGS, UART_INT_TX_EMPTY);
//            printf("PDSP数据发送完成！\n");
        }
     }

    /* Check if the cause is receiver data condition.*/
    if(UART_INTID_RX_DATA == int_id)
    {
        rxData = UARTCharGetNonBlocking(SOC_UART_1_REGS);
////      UARTCharPutNonBlocking(SOC_UART_1_REGS, rxData);
//        printf("%c",rxData);
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
