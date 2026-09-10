/*
 * PinMultiplex.c
 *
 *  Created on: 2025年9月22日
 *      Author: 18832
 */
#include "hw_types.h"
#include "soc_OMAPL138.h"
#include "hw_syscfg0_OMAPL138.h"
#include "psc.h"
#include "PinMultiplex.h"
#include "main.h"

// SYSCFG0 存储空间映射
volatile struct hw_SYSCFG0Regs SYSCFG0Regs;
#pragma DATA_SECTION(SYSCFG0Regs,".Reg_SYSCFG0");
#define PINMUX12_EMIF_A_ENABLE     (SYSCFG_PINMUX12_PINMUX12_31_28_EMA_A0 << \
									SYSCFG_PINMUX12_PINMUX12_31_28_SHIFT) | \
								   (SYSCFG_PINMUX12_PINMUX12_27_24_EMA_A1 << \
								    SYSCFG_PINMUX12_PINMUX12_27_24_SHIFT) | \
								   (SYSCFG_PINMUX12_PINMUX12_23_20_EMA_A2 << \
								    SYSCFG_PINMUX12_PINMUX12_23_20_SHIFT) | \
								   (SYSCFG_PINMUX12_PINMUX12_19_16_EMA_A3 << \
								    SYSCFG_PINMUX12_PINMUX12_19_16_SHIFT) | \
								   (SYSCFG_PINMUX12_PINMUX12_15_12_EMA_A4 << \
								    SYSCFG_PINMUX12_PINMUX12_15_12_SHIFT) | \
								   (SYSCFG_PINMUX12_PINMUX12_11_8_EMA_A5 << \
								    SYSCFG_PINMUX12_PINMUX12_11_8_SHIFT) | \
								   (SYSCFG_PINMUX12_PINMUX12_7_4_EMA_A6 << \
								    SYSCFG_PINMUX12_PINMUX12_7_4_SHIFT) | \
								   (SYSCFG_PINMUX12_PINMUX12_3_0_EMA_A7 << \
								    SYSCFG_PINMUX12_PINMUX12_3_0_SHIFT)

#define PINMUX11_EMIF_A_ENABLE     (SYSCFG_PINMUX11_PINMUX11_31_28_EMA_A8 << \
									SYSCFG_PINMUX11_PINMUX11_31_28_SHIFT) | \
								   (SYSCFG_PINMUX11_PINMUX11_27_24_EMA_A9 << \
								    SYSCFG_PINMUX11_PINMUX11_27_24_SHIFT) | \
								   (SYSCFG_PINMUX11_PINMUX11_23_20_EMA_A10 << \
								    SYSCFG_PINMUX11_PINMUX11_23_20_SHIFT) | \
								   (SYSCFG_PINMUX11_PINMUX11_19_16_EMA_A11 << \
								    SYSCFG_PINMUX11_PINMUX11_19_16_SHIFT) | \
								   (SYSCFG_PINMUX11_PINMUX11_15_12_EMA_A12 << \
								    SYSCFG_PINMUX11_PINMUX11_15_12_SHIFT) | \
								   (SYSCFG_PINMUX11_PINMUX11_11_8_EMA_A13 << \
								    SYSCFG_PINMUX11_PINMUX11_11_8_SHIFT) | \
								   (SYSCFG_PINMUX11_PINMUX11_7_4_EMA_A14 << \
								    SYSCFG_PINMUX11_PINMUX11_7_4_SHIFT) | \
								   (SYSCFG_PINMUX11_PINMUX11_3_0_EMA_A15 << \
								    SYSCFG_PINMUX11_PINMUX11_3_0_SHIFT)

#define PINMUX10_EMIF_A_ENABLE  	(SYSCFG_PINMUX10_PINMUX10_31_28_EMA_A16 << \
								    SYSCFG_PINMUX10_PINMUX10_31_28_SHIFT) | \
								    (SYSCFG_PINMUX10_PINMUX10_27_24_EMA_A17 << \
								    SYSCFG_PINMUX10_PINMUX10_27_24_SHIFT) | \
								    (SYSCFG_PINMUX10_PINMUX10_23_20_EMA_A18 << \
								    SYSCFG_PINMUX10_PINMUX10_23_20_SHIFT) | \
								    (SYSCFG_PINMUX10_PINMUX10_19_16_EMA_A19 << \
								    SYSCFG_PINMUX10_PINMUX10_19_16_SHIFT) | \
								    (SYSCFG_PINMUX10_PINMUX10_15_12_EMA_A20 << \
								    SYSCFG_PINMUX10_PINMUX10_15_12_SHIFT) | \
								    (SYSCFG_PINMUX10_PINMUX10_11_8_EMA_A21 << \
								    SYSCFG_PINMUX10_PINMUX10_11_8_SHIFT)  | \
									(SYSCFG_PINMUX10_PINMUX10_7_4_EMA_A22 << \
								    SYSCFG_PINMUX10_PINMUX10_7_4_SHIFT)

#define PINMUX9_EMIF_D_ENABLE      (SYSCFG_PINMUX9_PINMUX9_3_0_EMA_D7 << \
                                    SYSCFG_PINMUX9_PINMUX9_3_0_SHIFT) | \
                                   (SYSCFG_PINMUX9_PINMUX9_7_4_EMA_D6 << \
                                    SYSCFG_PINMUX9_PINMUX9_7_4_SHIFT) | \
                                   (SYSCFG_PINMUX9_PINMUX9_11_8_EMA_D5 << \
                                    SYSCFG_PINMUX9_PINMUX9_11_8_SHIFT) | \
                                   (SYSCFG_PINMUX9_PINMUX9_15_12_EMA_D4 << \
                                    SYSCFG_PINMUX9_PINMUX9_15_12_SHIFT) | \
                                   (SYSCFG_PINMUX9_PINMUX9_19_16_EMA_D3 << \
                                    SYSCFG_PINMUX9_PINMUX9_19_16_SHIFT) | \
                                   (SYSCFG_PINMUX9_PINMUX9_23_20_EMA_D2 << \
                                    SYSCFG_PINMUX9_PINMUX9_23_20_SHIFT) | \
                                   (SYSCFG_PINMUX9_PINMUX9_27_24_EMA_D1 << \
                                    SYSCFG_PINMUX9_PINMUX9_27_24_SHIFT) | \
                                   (SYSCFG_PINMUX9_PINMUX9_31_28_EMA_D0 << \
                                    SYSCFG_PINMUX9_PINMUX9_31_28_SHIFT)

#define PINMUX8_EMIF_D_ENABLE      (SYSCFG_PINMUX8_PINMUX8_3_0_EMA_D15 << \
							        SYSCFG_PINMUX8_PINMUX8_3_0_SHIFT) | \
							       (SYSCFG_PINMUX8_PINMUX8_7_4_EMA_D14 << \
		       						SYSCFG_PINMUX8_PINMUX8_7_4_SHIFT) | \
				    			   (SYSCFG_PINMUX8_PINMUX8_11_8_EMA_D13 << \
					    			SYSCFG_PINMUX8_PINMUX8_11_8_SHIFT) | \
						    	   (SYSCFG_PINMUX8_PINMUX8_15_12_EMA_D12 << \
							    	SYSCFG_PINMUX8_PINMUX8_15_12_SHIFT) | \
					    		   (SYSCFG_PINMUX8_PINMUX8_19_16_EMA_D11 << \
						    		SYSCFG_PINMUX8_PINMUX8_19_16_SHIFT) | \
							       (SYSCFG_PINMUX8_PINMUX8_23_20_EMA_D10 << \
								    SYSCFG_PINMUX8_PINMUX8_23_20_SHIFT) | \
	     						   (SYSCFG_PINMUX8_PINMUX8_27_24_EMA_D9 << \
		    						SYSCFG_PINMUX8_PINMUX8_27_24_SHIFT) | \
			    				   (SYSCFG_PINMUX8_PINMUX8_31_28_EMA_D8 << \
				    				SYSCFG_PINMUX8_PINMUX8_31_28_SHIFT)

#define PINMUX5_EMIF_BA_ENABLE     (SYSCFG_PINMUX5_PINMUX5_31_28_EMA_BA0 << \
							        SYSCFG_PINMUX5_PINMUX5_31_28_SHIFT) | \
							       (SYSCFG_PINMUX5_PINMUX5_27_24_EMA_BA1 << \
							        SYSCFG_PINMUX5_PINMUX5_27_24_SHIFT)

#define PINMUX7_EMIF_CTL_ENABLE    (SYSCFG_PINMUX7_PINMUX7_3_0_NEMA_CS2 << \
	    							SYSCFG_PINMUX7_PINMUX7_3_0_SHIFT) | \
								   (SYSCFG_PINMUX7_PINMUX7_7_4_NEMA_CS3 << \
									SYSCFG_PINMUX7_PINMUX7_7_4_SHIFT) | \
								   (SYSCFG_PINMUX7_PINMUX7_23_20_NEMA_OE << \
								    SYSCFG_PINMUX7_PINMUX7_23_20_SHIFT) | \
								   (SYSCFG_PINMUX7_PINMUX7_19_16_NEMA_WE << \
								    SYSCFG_PINMUX7_PINMUX7_19_16_SHIFT)



#define PINMUX6_EMA_CLK_ENABLE    (SYSCFG_PINMUX6_PINMUX6_3_0_EMA_CLK << \
								    SYSCFG_PINMUX6_PINMUX6_3_0_SHIFT) | \
								  (SYSCFG_PINMUX6_PINMUX6_19_16_NEMA_WE_DQM0<< \
							        SYSCFG_PINMUX6_PINMUX6_19_16_SHIFT) | \
							      (SYSCFG_PINMUX6_PINMUX6_23_20_NEMA_WE_DQM1<< \
							    	SYSCFG_PINMUX6_PINMUX6_23_20_SHIFT)



void EMIFAPinMuxSetup(void)
{
	 volatile unsigned int savePinMux = 0;

	 savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(12)) & \
						 ~(SYSCFG_PINMUX12_PINMUX12_31_28 | \
						   SYSCFG_PINMUX12_PINMUX12_27_24 | \
						   SYSCFG_PINMUX12_PINMUX12_23_20 | \
						   SYSCFG_PINMUX12_PINMUX12_19_16 | \
						   SYSCFG_PINMUX12_PINMUX12_15_12 | \
						   SYSCFG_PINMUX12_PINMUX12_11_8  | \
						   SYSCFG_PINMUX12_PINMUX12_7_4   | \
						   SYSCFG_PINMUX12_PINMUX12_3_0);

     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(12)) = \
    		 (PINMUX12_EMIF_A_ENABLE | savePinMux);

	 savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(11)) & \
						 ~(SYSCFG_PINMUX11_PINMUX11_31_28 | \
						   SYSCFG_PINMUX11_PINMUX11_27_24 | \
						   SYSCFG_PINMUX11_PINMUX11_23_20 | \
						   SYSCFG_PINMUX11_PINMUX11_19_16 | \
						   SYSCFG_PINMUX11_PINMUX11_15_12 | \
						   SYSCFG_PINMUX11_PINMUX11_11_8  | \
						   SYSCFG_PINMUX11_PINMUX11_7_4   | \
						   SYSCFG_PINMUX11_PINMUX11_3_0);

     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(11)) = \
    		 (PINMUX11_EMIF_A_ENABLE | savePinMux);

	 savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(10)) & \
						 ~(SYSCFG_PINMUX10_PINMUX10_31_28 | \
						   SYSCFG_PINMUX10_PINMUX10_27_24 | \
						   SYSCFG_PINMUX10_PINMUX10_23_20 | \
						   SYSCFG_PINMUX10_PINMUX10_19_16 | \
						   SYSCFG_PINMUX10_PINMUX10_15_12 | \
						   SYSCFG_PINMUX10_PINMUX10_11_8  | \
						   SYSCFG_PINMUX10_PINMUX10_7_4   | \
						   SYSCFG_PINMUX10_PINMUX10_3_0);

     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(10)) = \
    		 (PINMUX10_EMIF_A_ENABLE | savePinMux);

	 savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(9)) & \
						 ~(SYSCFG_PINMUX9_PINMUX9_31_28 | \
						   SYSCFG_PINMUX9_PINMUX9_27_24 | \
						   SYSCFG_PINMUX9_PINMUX9_23_20 | \
						   SYSCFG_PINMUX9_PINMUX9_19_16 | \
						   SYSCFG_PINMUX9_PINMUX9_15_12 | \
						   SYSCFG_PINMUX9_PINMUX9_11_8  | \
						   SYSCFG_PINMUX9_PINMUX9_7_4   | \
						   SYSCFG_PINMUX9_PINMUX9_3_0);

     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(9)) = \
          (PINMUX9_EMIF_D_ENABLE | savePinMux);

	 savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(8)) & \
						 ~(SYSCFG_PINMUX8_PINMUX8_31_28 | \
						   SYSCFG_PINMUX8_PINMUX8_27_24 | \
						   SYSCFG_PINMUX8_PINMUX8_23_20 | \
						   SYSCFG_PINMUX8_PINMUX8_19_16 | \
						   SYSCFG_PINMUX8_PINMUX8_15_12 | \
						   SYSCFG_PINMUX8_PINMUX8_11_8  | \
						   SYSCFG_PINMUX8_PINMUX8_7_4   | \
						   SYSCFG_PINMUX8_PINMUX8_3_0);

     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(8)) = \
          (PINMUX8_EMIF_D_ENABLE | savePinMux);

	 savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) & \
						 ~(SYSCFG_PINMUX5_PINMUX5_31_28 | \
						   SYSCFG_PINMUX5_PINMUX5_27_24);

     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) = \
          (PINMUX5_EMIF_BA_ENABLE | savePinMux);

	 savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(7)) & \
						 ~(SYSCFG_PINMUX7_PINMUX7_23_20 | \
						   SYSCFG_PINMUX7_PINMUX7_19_16 | \
						   SYSCFG_PINMUX7_PINMUX7_3_0);

     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(7)) = \
          (PINMUX7_EMIF_CTL_ENABLE | savePinMux);

	 savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(6)) & \
						 ~(SYSCFG_PINMUX6_PINMUX6_3_0 | \
						   SYSCFG_PINMUX6_PINMUX6_19_16 | \
						   SYSCFG_PINMUX6_PINMUX6_23_20);

     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(6)) = \
          (PINMUX6_EMA_CLK_ENABLE | savePinMux);
}

/****************************************************************************/
/*                                                                          */
/*              宏定义                                                      */
/*                                                                          */
/****************************************************************************/
//I2C0 pins
#define PINMUX4_I2C0_SDA_ENABLE    (SYSCFG_PINMUX4_PINMUX4_15_12_I2C0_SDA << \
                                    SYSCFG_PINMUX4_PINMUX4_15_12_SHIFT)

#define PINMUX4_I2C0_SCL_ENABLE    (SYSCFG_PINMUX4_PINMUX4_11_8_I2C0_SCL << \
                                    SYSCFG_PINMUX4_PINMUX4_11_8_SHIFT)


// I2C1
#define PINMUX4_I2C1_SDA_ENABLE    (SYSCFG_PINMUX4_PINMUX4_23_20_I2C1_SDA << \
                                    SYSCFG_PINMUX4_PINMUX4_23_20_SHIFT)

#define PINMUX4_I2C1_SCL_ENABLE    (SYSCFG_PINMUX4_PINMUX4_19_16_I2C1_SCL << \
                                    SYSCFG_PINMUX4_PINMUX4_19_16_SHIFT)
void I2CPinMuxSetup(unsigned int instanceNum)
{
	unsigned int savePinMux = 0;

	if(0 == instanceNum)
	{

		savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
		~(SYSCFG_PINMUX4_PINMUX4_15_12 | \
		SYSCFG_PINMUX4_PINMUX4_11_8);

		HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
		(PINMUX4_I2C0_SDA_ENABLE | \
		PINMUX4_I2C0_SCL_ENABLE | \
		savePinMux);

	}

	else if(1 == instanceNum)
	{
		savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
		~(SYSCFG_PINMUX4_PINMUX4_23_20 | \
		SYSCFG_PINMUX4_PINMUX4_19_16);

		HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
		(PINMUX4_I2C1_SDA_ENABLE | \
		PINMUX4_I2C1_SCL_ENABLE | \
		savePinMux);

	}

	else
	{

	}
}
/****************************************************************************/
/*                                                                          */
/*              宏定义                                                      */
/*                                                                          */
/****************************************************************************/
//SPI0
#define PINMUX3_SPI0_CLK_ENABLE   (SYSCFG_PINMUX3_PINMUX3_3_0_SPI0_CLK << \
                                    SYSCFG_PINMUX3_PINMUX3_3_0_SHIFT)

#define PINMUX3_SPI0_SIMO_ENABLE  (SYSCFG_PINMUX3_PINMUX3_15_12_SPI0_SIMO0 << \
                                    SYSCFG_PINMUX3_PINMUX3_15_12_SHIFT)

#define PINMUX3_SPI0_SOMI_ENABLE  (SYSCFG_PINMUX3_PINMUX3_11_8_SPI0_SOMI0 << \
                                    SYSCFG_PINMUX3_PINMUX3_11_8_SHIFT)

#define PINMUX3_SPI0_ENA_ENABLE   (SYSCFG_PINMUX3_PINMUX3_7_4_NSPI0_ENA << \
                                    SYSCFG_PINMUX3_PINMUX3_7_4_SHIFT)

// SPI1 pins
#define PINMUX5_SPI1_CLK_ENABLE   (SYSCFG_PINMUX5_PINMUX5_11_8_SPI1_CLK << \
                                   SYSCFG_PINMUX5_PINMUX5_11_8_SHIFT)

#define PINMUX5_SPI1_SIMO_ENABLE  (SYSCFG_PINMUX5_PINMUX5_23_20_SPI1_SIMO0 << \
                                   SYSCFG_PINMUX5_PINMUX5_23_20_SHIFT)

#define PINMUX5_SPI1_SOMI_ENABLE  (SYSCFG_PINMUX5_PINMUX5_19_16_SPI1_SOMI0 << \
                                   SYSCFG_PINMUX5_PINMUX5_19_16_SHIFT)

#define PINMUX5_SPI1_ENA_ENABLE   (SYSCFG_PINMUX5_PINMUX5_15_12_NSPI1_ENA << \
                                   SYSCFG_PINMUX5_PINMUX5_15_12_SHIFT)
/****************************************************************************/
/*                                                                          */
/*              管脚复用配置                                                */
/*                                                                          */
/****************************************************************************/
void SPIPinMuxSetup(unsigned int instanceNum)
{
  unsigned int savePinMux = 0;

  if(0 == instanceNum)
  {
    savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) & \
                       ~(SYSCFG_PINMUX3_PINMUX3_3_0 | \
                         SYSCFG_PINMUX3_PINMUX3_15_12 | \
                         SYSCFG_PINMUX3_PINMUX3_11_8 | \
                         SYSCFG_PINMUX3_PINMUX3_7_4);

    HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) = \
         (PINMUX3_SPI0_CLK_ENABLE | PINMUX3_SPI0_SIMO_ENABLE | \
          PINMUX3_SPI0_SOMI_ENABLE | PINMUX3_SPI0_ENA_ENABLE | \
          savePinMux);

  }
  else if(1 == instanceNum)
  {
    savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) & \
                        ~(SYSCFG_PINMUX5_PINMUX5_11_8 | \
                          SYSCFG_PINMUX5_PINMUX5_23_20 | \
                          SYSCFG_PINMUX5_PINMUX5_19_16 | \
                          SYSCFG_PINMUX5_PINMUX5_15_12);

    HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) = \
         (PINMUX5_SPI1_CLK_ENABLE | PINMUX5_SPI1_SIMO_ENABLE | \
          PINMUX5_SPI1_SOMI_ENABLE | PINMUX5_SPI1_ENA_ENABLE | \
          savePinMux);
  }
  else
  {

  }

}

void SPI0CSPinMuxSetup(unsigned int csPinNum)
{
     unsigned int spi0CSPinMux = 0;
     unsigned int savePinMux = 0;

     switch(csPinNum)
     {
          case 0:
              spi0CSPinMux = (SYSCFG_PINMUX4_PINMUX4_7_4_NSPI0_SCS0 << \
                              SYSCFG_PINMUX4_PINMUX4_7_4_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                                 ~(SYSCFG_PINMUX4_PINMUX4_7_4);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
                   (spi0CSPinMux | savePinMux);
          break;

          case 1:
              spi0CSPinMux = (SYSCFG_PINMUX4_PINMUX4_3_0_NSPI0_SCS1 << \
                              SYSCFG_PINMUX4_PINMUX4_3_0_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                                 ~(SYSCFG_PINMUX4_PINMUX4_3_0);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
                   (spi0CSPinMux | savePinMux);

          break;

          case 2:
              spi0CSPinMux = (SYSCFG_PINMUX3_PINMUX3_31_28_NSPI0_SCS2 << \
                              SYSCFG_PINMUX3_PINMUX3_31_28_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) & \
                                 ~(SYSCFG_PINMUX3_PINMUX3_31_28);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) = \
                   (spi0CSPinMux | savePinMux);

          break;

          case 3:
              spi0CSPinMux = (SYSCFG_PINMUX3_PINMUX3_27_24_NSPI0_SCS3 << \
                              SYSCFG_PINMUX3_PINMUX3_27_24_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) & \
                                 ~(SYSCFG_PINMUX3_PINMUX3_27_24);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) = \
                   (spi0CSPinMux | savePinMux);

          break;

          case 4:
              spi0CSPinMux = (SYSCFG_PINMUX3_PINMUX3_23_20_NSPI0_SCS4 << \
                              SYSCFG_PINMUX3_PINMUX3_23_20_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) & \
                                 ~(SYSCFG_PINMUX3_PINMUX3_23_20);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) = \
                   (spi0CSPinMux | savePinMux);

          break;

          case 5:
              spi0CSPinMux = (SYSCFG_PINMUX3_PINMUX3_19_16_NSPI0_SCS5 << \
                              SYSCFG_PINMUX3_PINMUX3_19_16_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) & \
                                 ~(SYSCFG_PINMUX3_PINMUX3_19_16);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) = \
                   (spi0CSPinMux | savePinMux);

          break;

          default:
          break;
     }

}

void SPI1CSPinMuxSetup(unsigned int csPinNum)
{
     unsigned int spi1CSPinMux = 0;
     unsigned int savePinMux = 0;

     switch(csPinNum)
     {
          case 0:
              spi1CSPinMux = (SYSCFG_PINMUX5_PINMUX5_7_4_NSPI1_SCS0 << \
                              SYSCFG_PINMUX5_PINMUX5_7_4_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) & \
                                 ~(SYSCFG_PINMUX5_PINMUX5_7_4);
              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) = \
                   (spi1CSPinMux | savePinMux);

          break;

          case 1:
              spi1CSPinMux = (SYSCFG_PINMUX5_PINMUX5_3_0_NSPI1_SCS1 << \
                              SYSCFG_PINMUX5_PINMUX5_3_0_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) & \
                                 ~(SYSCFG_PINMUX5_PINMUX5_3_0);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) = \
                   (spi1CSPinMux | savePinMux);

          break;

          case 2:
              spi1CSPinMux = (SYSCFG_PINMUX4_PINMUX4_31_28_NSPI1_SCS2 << \
                              SYSCFG_PINMUX4_PINMUX4_31_28_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) &
                                 ~(SYSCFG_PINMUX4_PINMUX4_31_28);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
                   (spi1CSPinMux | savePinMux);

          break;

          case 3:
              spi1CSPinMux = (SYSCFG_PINMUX4_PINMUX4_27_24_NSPI1_SCS3 << \
                              SYSCFG_PINMUX4_PINMUX4_27_24_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                                 ~(SYSCFG_PINMUX4_PINMUX4_27_24);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
                   (spi1CSPinMux | savePinMux);

          break;

          case 4:
              spi1CSPinMux = (SYSCFG_PINMUX4_PINMUX4_23_20_NSPI1_SCS4 << \
                              SYSCFG_PINMUX4_PINMUX4_23_20_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                                 ~(SYSCFG_PINMUX4_PINMUX4_23_20);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
                   (spi1CSPinMux | savePinMux);

          break;

          case 5:
              spi1CSPinMux = (SYSCFG_PINMUX4_PINMUX4_19_16_NSPI1_SCS5 << \
                              SYSCFG_PINMUX4_PINMUX4_19_16_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                                 ~(SYSCFG_PINMUX4_PINMUX4_19_16);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
                   (spi1CSPinMux | savePinMux);

          break;

          case 6:
              spi1CSPinMux = (SYSCFG_PINMUX4_PINMUX4_15_12_NSPI1_SCS6 << \
                              SYSCFG_PINMUX4_PINMUX4_15_12_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                                 ~(SYSCFG_PINMUX4_PINMUX4_15_12);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
                   (spi1CSPinMux | savePinMux);

          break;

          case 7:
              spi1CSPinMux = (SYSCFG_PINMUX4_PINMUX4_11_8_NSPI1_SCS7 << \
                              SYSCFG_PINMUX4_PINMUX4_11_8_SHIFT);

              savePinMux = HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                                 ~(SYSCFG_PINMUX4_PINMUX4_11_8);

              HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
                   (spi1CSPinMux | savePinMux);

          break;

          default:
          break;

     }
}





/****************************************************************************/
/*                                                                          */
/*              宏定义                                                      */
/*                                                                          */
/****************************************************************************/
// UART0
#define PINMUX3_UART0_CTS_ENABLE    (SYSCFG_PINMUX3_PINMUX3_27_24_UART0_CTS << \
                                     SYSCFG_PINMUX3_PINMUX3_27_24_SHIFT)

#define PINMUX3_UART0_RTS_ENABLE    (SYSCFG_PINMUX3_PINMUX3_31_28_UART0_RTS << \
                                     SYSCFG_PINMUX3_PINMUX3_31_28_SHIFT)

#define PINMUX3_UART0_TXD_ENABLE    (SYSCFG_PINMUX3_PINMUX3_23_20_UART0_TXD << \
                                     SYSCFG_PINMUX3_PINMUX3_23_20_SHIFT)

#define PINMUX3_UART0_RXD_ENABLE    (SYSCFG_PINMUX3_PINMUX3_19_16_UART0_RXD << \
                                     SYSCFG_PINMUX3_PINMUX3_19_16_SHIFT)

// UART1
#define PINMUX0_UART1_CTS_ENABLE    (SYSCFG_PINMUX0_PINMUX0_23_20_UART1_CTS << \
                                     SYSCFG_PINMUX0_PINMUX0_23_20_SHIFT)

#define PINMUX0_UART1_RTS_ENABLE    (SYSCFG_PINMUX0_PINMUX0_19_16_UART1_RTS << \
                                     SYSCFG_PINMUX0_PINMUX0_19_16_SHIFT)

#define PINMUX4_UART1_TXD_ENABLE    (SYSCFG_PINMUX4_PINMUX4_31_28_UART1_TXD << \
                                     SYSCFG_PINMUX4_PINMUX4_31_28_SHIFT)

#define PINMUX4_UART1_RXD_ENABLE    (SYSCFG_PINMUX4_PINMUX4_27_24_UART1_RXD << \
                                     SYSCFG_PINMUX4_PINMUX4_27_24_SHIFT)


// UART2
#define PINMUX0_UART2_CTS_ENABLE    (SYSCFG_PINMUX0_PINMUX0_31_28_UART2_CTS << \
                                     SYSCFG_PINMUX0_PINMUX0_31_28_SHIFT)

#define PINMUX0_UART2_RTS_ENABLE    (SYSCFG_PINMUX0_PINMUX0_27_24_UART2_RTS << \
                                     SYSCFG_PINMUX0_PINMUX0_27_24_SHIFT)

#define PINMUX4_UART2_TXD_ENABLE    (SYSCFG_PINMUX4_PINMUX4_23_20_UART2_TXD << \
                                     SYSCFG_PINMUX4_PINMUX4_23_20_SHIFT)

#define PINMUX4_UART2_RXD_ENABLE    (SYSCFG_PINMUX4_PINMUX4_19_16_UART2_RXD << \
                                     SYSCFG_PINMUX4_PINMUX4_19_16_SHIFT)
/****************************************************************************/
/*                                                                          */
/*              管脚复用配置                                                */
/*                                                                          */
/****************************************************************************/
void UARTPinMuxSetup(unsigned int instanceNum, unsigned int modemCtrlChoice)
{
  unsigned int svPinMuxRtsCts = 0;
  unsigned int svPinMuxTxdRxd = 0;

  if(0 == instanceNum)
  {
    if(TRUE == modemCtrlChoice)
    {
      svPinMuxRtsCts = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) & \
                        ~(SYSCFG_PINMUX3_PINMUX3_27_24 | \
                          SYSCFG_PINMUX3_PINMUX3_31_28));

      HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) = \
        (PINMUX3_UART0_CTS_ENABLE | \
         PINMUX3_UART0_RTS_ENABLE | \
         svPinMuxRtsCts);
    }

  svPinMuxTxdRxd = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) & \
                    ~(SYSCFG_PINMUX3_PINMUX3_23_20 | \
                      SYSCFG_PINMUX3_PINMUX3_19_16));

  HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(3)) = \
    (PINMUX3_UART0_TXD_ENABLE | \
     PINMUX3_UART0_RXD_ENABLE | \
     svPinMuxTxdRxd);
  }

  else if(1 == instanceNum)
  {
    if(TRUE == modemCtrlChoice)
    {
      svPinMuxRtsCts = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(0)) & \
                        ~(SYSCFG_PINMUX0_PINMUX0_23_20 | \
                          SYSCFG_PINMUX0_PINMUX0_19_16));

      HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(0)) = \
        (PINMUX0_UART1_CTS_ENABLE | \
         PINMUX0_UART1_RTS_ENABLE | \
         svPinMuxRtsCts);
    }

    svPinMuxTxdRxd = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                      ~(SYSCFG_PINMUX4_PINMUX4_31_28 | \
                        SYSCFG_PINMUX4_PINMUX4_27_24));

    HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
      (PINMUX4_UART1_TXD_ENABLE | \
       PINMUX4_UART1_RXD_ENABLE | \
       svPinMuxTxdRxd);
  }

  else if(2 == instanceNum)
  {

    if(TRUE == modemCtrlChoice)
    {
      svPinMuxRtsCts = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(0)) & \
                        ~(SYSCFG_PINMUX0_PINMUX0_31_28 | \
                          SYSCFG_PINMUX0_PINMUX0_27_24));

      HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(0)) = \
        (PINMUX0_UART2_CTS_ENABLE | \
         PINMUX0_UART2_RTS_ENABLE | \
         svPinMuxRtsCts);
    }

    svPinMuxTxdRxd = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) & \
                      ~(SYSCFG_PINMUX4_PINMUX4_23_20 | \
                        SYSCFG_PINMUX4_PINMUX4_19_16));

    HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(4)) = \
      (PINMUX4_UART2_TXD_ENABLE | \
       PINMUX4_UART2_RXD_ENABLE | \
       svPinMuxTxdRxd);

  }

  else
  {

  }
}
void GPIOBankPinMuxSet(void)
{
	// PINMUX0
	SYSCFG0Regs.PINMUX0.bit.PINMUX0_31_28 = 8;        // D7  GPIO0[8]
	SYSCFG0Regs.PINMUX0.bit.PINMUX0_27_24 = 8;        // D9  GPIO0[9]
	SYSCFG0Regs.PINMUX0.bit.PINMUX0_23_20 = 8;        // D10 GPIO0[10]
	SYSCFG0Regs.PINMUX0.bit.PINMUX0_19_16 = 8;         // D6  GPIO0[11]
	SYSCFG0Regs.PINMUX0.bit.PINMUX0_15_12 = 8;     		//12
	SYSCFG0Regs.PINMUX0.bit.PINMUX0_11_8 = 8;//13
	SYSCFG0Regs.PINMUX0.bit.PINMUX0_7_4 = 8;//14
	SYSCFG0Regs.PINMUX0.bit.PINMUX0_3_0 = 8;//15

	//GPIO6 [1]
	SYSCFG0Regs.PINMUX19.bit.PINMUX19_23_20 = 8;
	//GPIO8[12]数据同步flag
	SYSCFG0Regs.PINMUX18.bit.PINMUX18_23_20 = 8;
	//GPIO8[13]数据同步flag
	SYSCFG0Regs.PINMUX18.bit.PINMUX18_19_16 = 8;

	//GPIO8[14]mcbsp数据同步信号
	SYSCFG0Regs.PINMUX18.bit.PINMUX18_15_12 = 8;
	//GPIO8[15]mcbsp数据同步信号
	SYSCFG0Regs.PINMUX18.bit.PINMUX18_11_8 = 8;

	//GPIO7[8]  ODSP flash擦除信号
	SYSCFG0Regs.PINMUX17.bit.PINMUX17_7_4 = 8;

	//m
	SYSCFG0Regs.PINMUX1.bit.PINMUX1_23_20 = 8;//gpio0[2]
	SYSCFG0Regs.PINMUX1.bit.PINMUX1_27_24 = 8;//gpio0[1]
	SYSCFG0Regs.PINMUX1.bit.PINMUX1_15_12 = 8;//gpio0[4]
	SYSCFG0Regs.PINMUX1.bit.PINMUX1_19_16 = 8;//gpio0[3]
	SYSCFG0Regs.PINMUX1.bit.PINMUX1_11_8 = 8;//gpio0[5]
	SYSCFG0Regs.PINMUX1.bit.PINMUX1_7_4 = 8;//gpio0[6]
	//p
	SYSCFG0Regs.PINMUX2.bit.PINMUX2_27_24 = 4; //gpio1 9
	SYSCFG0Regs.PINMUX2.bit.PINMUX2_23_20 = 4; //gpio1 10
	SYSCFG0Regs.PINMUX2.bit.PINMUX2_19_16 = 4; //gpio1 11
	SYSCFG0Regs.PINMUX2.bit.PINMUX2_15_12 = 4; //gpio1 12
	SYSCFG0Regs.PINMUX2.bit.PINMUX2_11_8 = 4; //gpio1 13
	SYSCFG0Regs.PINMUX2.bit.PINMUX2_7_4 = 4; //gpio1 14
	SYSCFG0Regs.PINMUX2.bit.PINMUX2_31_28 = 4; //gpio8 7
}

void mcbspPinMuxSetup(void)
{
	// McBSP 管脚复用配置
	//配置Mcbsp0管脚
	SYSCFG0Regs.PINMUX2.all=0x02222220;
	//配置Mcbsp1管脚
	SYSCFG0Regs.PINMUX1.all=0x22222220;
}

