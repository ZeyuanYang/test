/*
 * result_Report.c
 *
 *  Created on: 2025Äê11ÔÂ12ÈÕ
 *      Author: yzy
 */
#include "result_Report.h"
#define strAddr 0x00820000
int  volatile sendTime = 0;

//volatile  int send_temp = 0;
char* straddr = (char*)strAddr;
//char straddr[100]="";
void myprint(char* temp)
{
	int i;
	for(i=0;i<strlen(temp);i++)
	{
		*((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x60000)) = temp[i];
	}
}

void my_delay()
{
    int  send_temp = 10;
	send_temp = sendTime;
	while(1)
	{
		if(send_temp != sendTime)
		{
			break;
		}
	}

}

void result_send_test()
{
	int i;
	for(i=0;i<23;i++)
	{
		*((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x60000)) = 0xA5A5;
		*((unsigned short int*)(SOC_EMIFA_CS3_ADDR+0x60000)) = 0xA3A3;
	}
}

void memyclear()
{
	memset(straddr,0xff,50);
}

void stradd(char* temp)
{
	int i,len;
	len = strlen(temp);
	for(i=0;i<len;i++)
	{
		straddr[i] = temp[i];
	}
}

void PrintResult_O(RESULT* myResult)
{
//	char* temp = (char*)malloc(50*sizeof(char));
//
//	char temp3[] = "Odsp mcbsp test success!\n";
//	char temp5[] = "Odsp iic test success!\n";
//	char temp7[] = "Odsp emif test success!\n";
//	char temp9[] = "Odsp nor flash test success!\n";
//	char temp11[] = "Odsp NVRAM test failure!\n";
//	sprintf(temp,"Odsp 2991 voltage1 is %.2f V\n",1.3);
//	char temp1[] = "Odsp uart test success!\n";
//	int buffsize = 500;
//	int temp_sum =0;
//	int	temp_sendtime = 15;
//
//	while(1)
//	{
//		if(sendTime != temp_sendtime)
//		{
//			temp_sendtime = sendTime;
//			switch(temp_sum){
//			case 0:
//				myprint(temp1);
//			    break;
//			case 1:
//				myprint(temp1);
//			    break;
//			case 2:
//				myprint(temp3);
//				break;
//			case 3:
//				myprint(temp5);
//				break;
//			case 4:
//				myprint(temp7);
//				break;
//			case 5:
//				myprint(temp9);
//				break;
//			case 6:
//				myprint(temp11);
//				break;
//			case 7:
//				myprint(temp);
//				break;
//			default :
//				temp_sum = 0;
//				break;
//				}
//			temp_sum++;
//		}
//	}
////	char temp1[] = "\nOdsp uart test success!\n";
//	static unsigned short int flag = 1;
//
//	char tp[100]="\nOdsp uart test success!\n";
//	while(flag)
//	{
//		char strtemp1[] = "000Odsp uart test success!\r\n\0";
//		memcpy(straddr,strtemp1,sizeof(strtemp1));
////		stradd("\nOdsp uart test success!\n\0");
//		myprint(strtemp1);
//		memyclear();
//
//		char strtemp2[] = "111Odsp uart test success!\r\n\0";
//		memcpy(straddr,strtemp2,sizeof(strtemp2));
////		stradd("111\nOdsp uart test success!\n\0");
//		myprint(strtemp2);
//		memyclear();
//
//		char strtemp3[] = "222Odsp uart test success!\r\n\0";
//		memcpy(straddr,strtemp3,sizeof(strtemp3));
////		stradd("222\nOdsp uart test success!\n\0");
//		myprint(strtemp3);
//		memyclear();
//
//
//		char strtemp4[] = "333Odsp uart test success!\r\n\0";
//		memcpy(straddr,strtemp4,sizeof(strtemp4));
//	//	*tp  = "333\nOdsp uart test success!\n";
////		stradd("333\nOdsp uart test success!\n\0");
//		myprint(strtemp4);
//		memyclear();
//
//		char strtemp5[] = "444Odsp uart test success!\r\n\0";
//		memcpy(straddr,strtemp5,sizeof(strtemp5));
////		*tp  = "333\nOdsp uart test success!\n";
////		stradd("333\nOdsp uart test success!\n\0");
//		myprint(strtemp5);
//		memyclear();
//	}
	if(myResult->ODSP_uart_Test_Result == true)
	{
		stradd("\nODSP uart test success!\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}
	else
	{
		stradd("\nODSP uart test failure!\n");
		myprint(straddr);
		memyclear();
		my_delay();

	}


	if(myResult->ODSP_mcbsp_Test_Result == true && myResult->PDSP_mcbsp_Test_Result == true)
	{
		stradd("\nODSP MCBSP0 and PDSP MCBSP1 test success!\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}
	else
	{
		stradd("\nODSP MCBSP0 and PDSP MCBSP1 test failure!\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}

//	if(myResult->ODSP_IIC_Test_Result == true)
//	{
//		stradd("\nOdsp iic test success!\n");
//		myprint(straddr);
//		memyclear();
//		my_delay();
//	}
//	else
//	{
//		stradd("\nOdsp iic test failure!\n");
//		myprint(straddr);
//		memyclear();
//		my_delay();
//	}

//	if(myResult->ODSP_emif_Test_Result == true)
//	{
//		stradd("\nOdsp emif test success!\n");
//		myprint(straddr);
//		memyclear();
//		my_delay();
//	}
//	else
//	{
//		stradd("\nOdsp emif test failure!\n");
//		myprint(straddr);
//		memyclear();
//		my_delay();
//	}

	if(myResult->ODSP_flash_Test_Result == true)
	{
		stradd("\nODSP nor flash device id is 0x22C4\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}
	else
	{
		stradd("\nODSP nor flash test failure!\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}

	if(myResult->ODSP_NVRAM_Test_Result == true)
	{
		stradd("\nODSP NVSRAM test success!\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}
	else
	{
		stradd("\nODSP NVSRAM test failure!\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}
	sprintf(straddr,"\nODSP 1.8V test is %.2f V \n",(myResult->ODSP_voltage_1)/100.00);
	myprint(straddr);
	memyclear();
	my_delay();

//	sprintf(straddr,"\nOdsp 2991 voltage2 is %.2f V \n",(myResult->ODSP_voltage_2)/10.00);
//	myprint(straddr);
//	memyclear();
//	my_delay();

	sprintf(straddr,"\nODSP 1.3V test is %.2f V \n",(myResult->ODSP_voltage_3)/100.00);
	myprint(straddr);
	memyclear();
	my_delay();

	sprintf(straddr,"\nODSP 3.3V test is %.2f V \n",(myResult->ODSP_voltage_4)/100.00);
	myprint(straddr);
	memyclear();
	my_delay();

	sprintf(straddr,"\nODSP temperture is %.1f ¡æ\n",myResult->ODSP_temperature_1/10.0);
	myprint(straddr);
	memyclear();
	my_delay();

//	sprintf(straddr,"\nOdsp 2991 temperture2 is %.1f ¡æ\n",myResult->ODSP_temperature_2*1.0);
//	myprint(straddr);
//	memyclear();
//	my_delay();

}
void PrintResult_P(RESULT* myResult)
{
	char temp[50];
//	int buffsize = 500;
	char temp13[] = "\nPDSP uart test success!\n";
	char temp14[] = "\nPDSP uart test failure!\n";
	if(myResult->PDSP_uart_Test_Result == true)
	{
		myprint(temp13);
		my_delay();
	}
	else
	{
		myprint(temp14);
		my_delay();
	}

	char temp15[] = "\nPFPGA and PDSP MCBSP0 test success!\n";
	char temp16[] = "\nPFPGA and PDSP MCBSP0 test failure!\n";
	if(myResult->P_fpga_mcbsp == true)
	{
		myprint(temp15);
		my_delay();
	}
	else
	{
		myprint(temp16);
		my_delay();
	}

	char temp17[] = "\nPDSP SPI test success!\n";
	char temp18[] = "\nPDSP SPI test failure!\n";
	if(myResult->PDSP_spi_Test_Result == true)
	{
		myprint(temp17);
		my_delay();
	}
	else
	{
		myprint(temp18);
		my_delay();
	}

	char temp19[] = "\nPDSP HI8435 test success!\n";
	char temp20[] = "\nPDSP HI8435 test failure!\n";
	if(myResult->PDSP_spi_HI8435_Test_Result == true)
	{
		myprint(temp19);
		my_delay();
	}
	else
	{
		myprint(temp20);
		my_delay();
	}


	char temp21[] = "\nPFPGA and PDSP emif test success!\n";
	char temp22[] = "\nPFPGA and PDSP emif test failure!\n";
	if(myResult->PDSP_emif_Test_Result == true)
	{
		myprint(temp21);
		my_delay();
	}
	else
	{
		myprint(temp22);
		my_delay();
	}


	char temp23[] = "\nPDSP nor flash device id is 0x22C4\n";
	char temp24[] = "\nPDSP flash test failure!\n";
	if(myResult->PDSP_flash_Test_Result == true)
	{
		myprint(temp23);
		my_delay();
	}
	else
	{
		myprint(temp24);
		my_delay();
	}

	char temp25[] = "\nPDSP pwr test success!\n";
	char temp26[] = "\nPDSP pwr test failure!\n";
	if(myResult->PDSP_power_Test_Result == true)
	{
		myprint(temp25);
		my_delay();
	}
	else
	{
		myprint(temp26);
		my_delay();
	}

	char temp27[] = "\nPFPGA 429 test success!\n";
	char temp28[] = "\nPFPGA 429 test failure!\n";
	if(myResult->P_fpga_429_channel1 == true)
	{
		myprint(temp27);
		my_delay();
	}
	else
	{
		myprint(temp28);
		my_delay();
	}

	char temp30[] = "\nPFPGA gpio test success!\n";
	char temp31[] = "\nPFPGA gpio test failure!\n";
	if(myResult->p_fpga_lisanliang == true)
	{
		myprint(temp30);
		my_delay();
	}
	else
	{
		myprint(temp31);
		my_delay();
	}

	stradd("\nPFPGA flash test success!\n");
	myprint(straddr);
	memyclear();
	my_delay();


	sprintf(temp,"\nPFPGA 1.0V test is %.2f V \n",(myResult->P_fpga_voltage_1)/100.00);
	myprint(temp);
	my_delay();
	sprintf(temp,"\nPFPGA 1.3V test is %.2f V \n",(myResult->P_fpga_voltage_2)/100.00);
	myprint(temp);
	my_delay();
	sprintf(temp,"\nPFPGA 1.8V test is %.2f V \n",(myResult->P_fpga_voltage_3)/100.00);
	myprint(temp);
	my_delay();
	sprintf(temp,"\nPFPGA 3.3V test is %.2f V \n",(myResult->P_fpga_voltage_4)/100.00);
	myprint(temp);
	my_delay();
	sprintf(temp,"\nPFPGA temperture is %.1f ¡æ \n",myResult->P_fpga_temperature_1/10.0);
	myprint(temp);
	my_delay();
}
void PrintResult_M(RESULT* myResult)
{
	char temp[50];
	char temp13[] = "\nMDSP uart test success!\n";
	char temp14[] = "\nMDSP uart test failure!\n";
	if(myResult->MDSP_uart_Test_Result == true)
	{
		myprint(temp13);
		my_delay();
	}
	else
	{
		myprint(temp14);
		my_delay();
	}
	char temp15[] = "\nODSP MCBSP1 and MDSP MCBSP1 test success!\n";
	char temp16[] = "\nODSP MCBSP1 and MDSP MCBSP1 test failure!\n";
	if(myResult->MDSP_mcbsp_Test_Result == true)
	{
		myprint(temp15);
		my_delay();
	}
	else
	{
		myprint(temp16);
		my_delay();
	}
	if(myResult->M_fpga_mcbsp == true)
	{
		stradd("\nMFPGA and MDSP MCBSP0 test success!\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}
	else
	{
		stradd("\nMFPGA and MDSP MCBSP0 test failure!\n");
		myprint(straddr);
		memyclear();
		my_delay();
	}




	char temp17[] = "\nMFPGA and MDSP emif test success!\n";
	char temp18[] = "\nMFPGA and MDSP emif test failure!\n";
	if(myResult->MDSP_emif_Test_Result == true)
	{
		myprint(temp17);
		my_delay();
	}
	else
	{
		myprint(temp18);
		my_delay();
	}
	char temp19[] = "\nMDSP nor flash device id is 0x22C4\n";
	char temp30[] = "\nMDSP flash test failure!\n";
	if(myResult->MDSP_flash_Test_Result == true)
	{
		myprint(temp19);
		my_delay();
	}
	else
	{
		myprint(temp30);
		my_delay();
	}
	char temp20[] = "\nMFPGA 429 test success!\n";
	char temp31[] = "\nMFPGA 429 test failure!\n";
	if(myResult->M_fpga_429_channel1 == true && myResult->M_fpga_429_channel2 == true && myResult->M_fpga_429_channel3 == true)
	{
		myprint(temp20);
		my_delay();
	}
	else
	{
		myprint(temp31);
		my_delay();
	}

//	char temp21[] = "\nMfpga 429 channel2 test success!\n";
//	char temp32[] = "\nMfpga 429 channel2 test failure!\n";
//	if(myResult->M_fpga_429_channel2 == true)
//	{
//		myprint(temp21);
//		my_delay();
//	}
//	else
//	{
//		myprint(temp32);
//		my_delay();
//	}
//	char temp22[] = "\nMfpga 429 channel3 test success!\n";
//	char temp33[] = "\nMfpga 429 channel3 test failure!\n";
//	if(myResult->M_fpga_429_channel1 == true)
//	{
//		myprint(temp22);
//		my_delay();
//	}
//	else
//	{
//		myprint(temp33);
//		my_delay();
//	}

	char temp23[] = "\nMFPGA pwr test success!\n";
	char temp34[] = "\nMFPGA pwr test failure!\n";
	if(myResult->M_fpga_pwr_test == true)
	{
		myprint(temp23);
		my_delay();
	}
	else
	{
		myprint(temp34);
		my_delay();
	}

	char temp24[] = "\nMFPGA gpio test success!\n";
	char temp35[] = "\nMFPGA gpio test failure!\n";
	if(myResult->M_fpga_lisanliang == true)
	{
		myprint(temp24);
		my_delay();
	}
	else
	{
		myprint(temp35);
		my_delay();
	}

	stradd("\nMFPGA flash test success!\n");
	myprint(straddr);
	memyclear();
	my_delay();


	sprintf(temp,"\nMFPGA 1.0V test is %.2f V \n",myResult->M_fpga_voltage_1/100.00);
	myprint(temp);
	my_delay();
	sprintf(temp,"\nMFPGA 1.3V test is %.2f V \n",(myResult->M_fpga_voltage_2)/100.00);
	myprint(temp);
	my_delay();
	sprintf(temp,"\nMFPGA 1.8V test is %.2f V \n",(myResult->M_fpga_voltage_3)/100.00);
	myprint(temp);
	my_delay();
	sprintf(temp,"\nMFPGA 3.3V test is %.2f V \n",(myResult->M_fpga_voltage_4)/100.00);
	myprint(temp);
	my_delay();
	sprintf(temp,"\nMFPGA temperture is %.1f ¡æ \n",myResult->M_fpga_temperature_1/10.0);
	myprint(temp);
	my_delay();
//	sprintf(temp,"\nMfpga 2991 temperture2 is %.1f ¡æ \n",myResult->M_fpga_temperature_2*1.0);
//	myprint(temp);
//	my_delay();
}
