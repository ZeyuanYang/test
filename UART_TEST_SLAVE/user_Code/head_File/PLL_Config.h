/*
 * PLL_Config.h
 *
 *  Created on: 2025Äê10ÔÂ9ÈÕ
 *      Author: 18832
 */

#ifndef PLL_CONFIG_H_
#define PLL_CONFIG_H_

/**************************************************************************************************************************************************
   Device_PLL0 init:

   CLKMODE -  0---->On Chip Oscilator  1---->External Oscilator
   PLL0_SYSCLK1 - Fixed ratio /1
   PLL0_SYSCLK2 - Fixed ratio /2
   PLL0_SYSCLK3 - Variable Divider (EMIFA)
   PLL0_SYSCLK4 - Fixed ratio /4
   PLL0_SYSCLK5 - Not used -- do nothing
   PLL0_SYSCLK6 - Fixed ratio /1
   PLL0_SYSCLK7 - Variable Divider (RMII)
******************************************************************************************************************************************************/
void C6748_PLLC0Init(unsigned int CLKMODE, unsigned int PLLM, unsigned int POSTDIV,unsigned int PLLDIV1, unsigned int PLLDIV2, unsigned int PLLDIV3, unsigned int PLLDIV7 );

/**********************************************************************************
DDR PLL1 init:

***********************************************************************************/
void C6748_PLLC1Init(unsigned int PLLM,unsigned int POSTDIV,unsigned int PLLDIV1, unsigned int PLLDIV2, unsigned int PLLDIV3 );

#endif /* PLL_CONFIG_H_ */
