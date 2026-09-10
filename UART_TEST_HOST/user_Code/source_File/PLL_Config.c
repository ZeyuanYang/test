/*
 * PLL_Config.c
 *
 *  Created on: 2025Äê10ÔÂ9ÈÕ
 *      Author: yzy
 */

#include "c6748.h"
#include "PLL_Config.h"

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
void C6748_PLLC0Init(unsigned int CLKMODE, unsigned int PLLM, unsigned int POSTDIV,unsigned int PLLDIV1, unsigned int PLLDIV2, unsigned int PLLDIV3, unsigned int PLLDIV7 )
{

    unsigned int i=0;

    /* Clear PLL lock bit */
    CFGCHIP0 &= ~(0x00000010);

    /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
    PLL0_PLLCTL &= ~(0x00000020);

    /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Freon */
    PLL0_PLLCTL &= ~(0x00000200);

    /* Set PLLEN=0 to put in bypass mode*/
    PLL0_PLLCTL &= ~(0x00000001);

    /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
    for(i=0; i<PLLEN_MUX_SWITCH; i++) {;}

    /* Select the Clock Mode bit 8 as External Clock or On Chip Oscilator*/
    PLL0_PLLCTL &= 0xFFFFFEFF;
    PLL0_PLLCTL |= (CLKMODE << 8);

    /*Clear PLLRST bit to reset the PLL */
    PLL0_PLLCTL &= ~(0x00000008);

    /* Disable the PLL output*/
    PLL0_PLLCTL |= (0x00000010);

    /* PLL initialization sequence
    Power up the PLL by setting PWRDN bit set to 0 */
    PLL0_PLLCTL &= ~(0x00000002);

    /* Enable the PLL output*/
    PLL0_PLLCTL &= ~(0x00000010);

    /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
    for(i=0; i<PLL_STABILIZATION_TIME; i++) {;}

    /*Program the required multiplier value in PLLM*/
    PLL0_PLLM    = PLLM;

    /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio*/
    PLL0_POSTDIV = 0x8000 | POSTDIV;

    /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
    while(PLL0_PLLSTAT & 0x1==1){}

    /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
    PLL0_PLLDIV1 = 0x8000 | PLLDIV1;             // Fixed Ratio /1
    PLL0_PLLDIV2 = 0x8000 | PLLDIV2;             // Fixed Ratio /2
    PLL0_PLLDIV4 = 0x8000 | (((PLLDIV1+1)*4)-1); // Fixed Ratio /4
    PLL0_PLLDIV6 = 0x8000 | PLLDIV1;             // Fixed Ratio /1
    PLL0_PLLDIV3 = 0x8000 | PLLDIV3;             // Variable Ratio (EMIF)
    PLL0_PLLDIV7 = 0x8000 | PLLDIV7;             // Variable Ratio (RMII)


    /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
    PLL0_PLLCMD |= 0x1;

    /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
    while(PLL0_PLLSTAT & 0x1==1) { }

    /*Wait for PLL to reset properly.*/
    for(i=0; i<PLL_RESET_TIME_CNT; i++) {;}

    /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
    PLL0_PLLCTL |= 0x8;

    /*Wait for PLL to lock.*/
    for(i=0; i<PLL_LOCK_TIME_CNT; i++) {;}

    /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
    PLL0_PLLCTL |=  0x1;
}

/**********************************************************************************
DDR PLL1 init:

***********************************************************************************/
void C6748_PLLC1Init(unsigned int PLLM,unsigned int POSTDIV,unsigned int PLLDIV1, unsigned int PLLDIV2, unsigned int PLLDIV3 )
{

    unsigned int i=0;

    /* Clear PLL lock bit */
    CFGCHIP3 &= ~(0x00000020);

    /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
    PLL1_PLLCTL &= ~(0x00000020);

    /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Freon */
    PLL1_PLLCTL &= ~(0x00000200);

    /* Set PLLEN=0 to put in bypass mode*/
    PLL1_PLLCTL &= ~(0x00000001);

    /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
    for(i=0; i<PLLEN_MUX_SWITCH; i++) {;}

    /*Clear PLLRST bit to reset the PLL */
    PLL1_PLLCTL &= ~(0x00000008);

    /* Disable the PLL output*/
    PLL1_PLLCTL |= (0x00000010);

    /* PLL initialization sequence
    Power up the PLL by setting PWRDN bit set to 0 */
    PLL1_PLLCTL &= ~(0x00000002);

    /* Enable the PLL output*/
    PLL1_PLLCTL &= ~(0x00000010);

    /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
    for(i=0; i<PLL_STABILIZATION_TIME; i++) {;}

    /*Program the required multiplier value in PLLM*/
    PLL1_PLLM    = PLLM;

    /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio*/
    PLL1_POSTDIV = 0x8000 | POSTDIV;

    /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
    while(PLL1_PLLSTAT & 0x1==1){}

    /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
    PLL1_PLLDIV1 = 0x8000 | PLLDIV1;   // DDR frequency (aka 2X_CLK)
    PLL1_PLLDIV2 = 0x8000 | PLLDIV2;   // Optional CFGCHIP3[ASYNC3_CLKSRC] clock source
    PLL1_PLLDIV3 = 0x8000 | PLLDIV3;   // Optional PLL0 clock source

    /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
    PLL1_PLLCMD |= 0x1;

    /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
    while(PLL1_PLLSTAT & 0x1==1) { }

    /*Wait for PLL to reset properly */
    for(i=0; i<PLL_RESET_TIME_CNT; i++) {;}

    /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
    PLL1_PLLCTL |= 0x8;

    /*Wait for PLL to lock. See PLL spec for PLL lock time*/
    for(i=0; i<PLL_LOCK_TIME_CNT; i++) {;}

    /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
    PLL1_PLLCTL |=  0x1;
}


