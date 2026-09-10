#ifndef __C6748_H_
#define __C6748_H_

#include "stdint.h"
#include "stdio.h"

#include "hw_pllc_OMAPL138.h"
#include "hw_syscfg0_OMAPL138.h"
#include "hw_syscfg1_OMAPL138.h"
#include "soc_OMAPL138.h"
#include "hw_psc_OMAPL138.h"
#include "hw_ddr2_mddr.h"
#include "hw_types.h"
#include "psc.h"
#include "c6748.h"


#define PLL0_BASE       0x01C11000                              /*SYSTEM PLL BASE ADDRESS*/
#define PLL0_PID        *(unsigned int*) (PLL0_BASE + 0x00)     /*PID*/
#define PLL0_RSTYPE     *(unsigned int*) (PLL0_BASE + 0xE4)     /*Reset Type status Reg*/
#define PLL0_PLLCTL     *(unsigned int*) (PLL0_BASE + 0x100)    /*PLL Control Register*/
#define PLL0_OCSEL      *(unsigned int*) (PLL0_BASE + 0x104)    /*OBSCLK Select Register*/
#define PLL0_SECCTL     *(unsigned int*) (PLL0_BASE + 0x108)    /*PLL Secondary Control Register*/
#define PLL0_PLLM       *(unsigned int*) (PLL0_BASE + 0x110)    /*PLL Multiplier*/
#define PLL0_PREDIV     *(unsigned int*) (PLL0_BASE + 0x114)    /*Pre divider*/
#define PLL0_PLLDIV1    *(unsigned int*) (PLL0_BASE + 0x118)    /*Divider-1*/
#define PLL0_PLLDIV2    *(unsigned int*) (PLL0_BASE + 0x11C)    /*Divider-2*/
#define PLL0_PLLDIV3    *(unsigned int*) (PLL0_BASE + 0x120)    /*Divider-3*/
#define PLL0_OSCDIV1    *(unsigned int*) (PLL0_BASE + 0x124)    /*Oscilator Divider*/
#define PLL0_POSTDIV    *(unsigned int*) (PLL0_BASE + 0x128)    /*Post Divider*/
#define PLL0_BPDIV      *(unsigned int*) (PLL0_BASE + 0x12C)    /*Bypass Divider*/
#define PLL0_WAKEUP     *(unsigned int*) (PLL0_BASE + 0x130)    /*Wakeup Reg*/
#define PLL0_PLLCMD     *(unsigned int*) (PLL0_BASE + 0x138)    /*Command Reg*/
#define PLL0_PLLSTAT    *(unsigned int*) (PLL0_BASE + 0x13C)    /*Status Reg*/
#define PLL0_ALNCTL     *(unsigned int*) (PLL0_BASE + 0x140)    /*Clock Align Control Reg*/
#define PLL0_DCHANGE    *(unsigned int*) (PLL0_BASE + 0x144)    /*PLLDIV Ratio Chnage status*/
#define PLL0_CKEN       *(unsigned int*) (PLL0_BASE + 0x148)    /*Clock Enable Reg*/
#define PLL0_CKSTAT     *(unsigned int*) (PLL0_BASE + 0x14C)    /*Clock Status Reg*/
#define PLL0_SYSTAT     *(unsigned int*) (PLL0_BASE + 0x150)    /*Sysclk status reg*/
#define PLL0_PLLDIV4    *(unsigned int*) (PLL0_BASE + 0x160)    /*Divider 4*/
#define PLL0_PLLDIV5    *(unsigned int*) (PLL0_BASE + 0x164)    /*Divider 5*/
#define PLL0_PLLDIV6    *(unsigned int*) (PLL0_BASE + 0x168)    /*Divider 6*/
#define PLL0_PLLDIV7    *(unsigned int*) (PLL0_BASE + 0x16C)    /*Divider 7*/
#define PLL0_PLLDIV8    *(unsigned int*) (PLL0_BASE + 0x170)    /*Divider 8*/
#define PLL0_PLLDIV9    *(unsigned int*) (PLL0_BASE + 0x174)    /*Divider 9*/
#define PLL0_PLLDIV10   *(unsigned int*) (PLL0_BASE + 0x178)    /*Divider 10*/
#define PLL0_PLLDIV11   *(unsigned int*) (PLL0_BASE + 0x17C)    /*Divider 11*/
#define PLL0_PLLDIV12   *(unsigned int*) (PLL0_BASE + 0x180)    /*Divider 12*/
#define PLL0_PLLDIV13   *(unsigned int*) (PLL0_BASE + 0x184)    /*Divider 13*/
#define PLL0_PLLDIV14   *(unsigned int*) (PLL0_BASE + 0x188)    /*Divider 14*/
#define PLL0_PLLDIV15   *(unsigned int*) (PLL0_BASE + 0x18C)    /*Divider 15*/
#define PLL0_PLLDIV16   *(unsigned int*) (PLL0_BASE + 0x190)    /*Divider 16*/
#define DDR_SLEW            *(unsigned int*)(0x01E2C004)                    //DDR_SLEW Register


#define PLL1_BASE       0x01E1A000                              /*SYSTEM PLL1 BASE ADDRESS*/
#define PLL1_PID        *(unsigned int*) (PLL1_BASE + 0x00)     /*PID*/
#define PLL1_RSTYPE     *(unsigned int*) (PLL1_BASE + 0xE4)     /*Reset Type status Reg*/
#define PLL1_PLLCTL     *(unsigned int*) (PLL1_BASE + 0x100)    /*PLL Control Register*/
#define PLL1_OCSEL      *(unsigned int*) (PLL1_BASE + 0x104)    /*OBSCLK Select Register*/
#define PLL1_SECCTL     *(unsigned int*) (PLL1_BASE + 0x108)    /*PLL Secondary Control Register*/
#define PLL1_PLLM       *(unsigned int*) (PLL1_BASE + 0x110)    /*PLL Multiplier*/
#define PLL1_PREDIV     *(unsigned int*) (PLL1_BASE + 0x114)    /*Pre divider*/
#define PLL1_PLLDIV1    *(unsigned int*) (PLL1_BASE + 0x118)    /*Divider-1*/
#define PLL1_PLLDIV2    *(unsigned int*) (PLL1_BASE + 0x11C)    /*Divider-2*/
#define PLL1_PLLDIV3    *(unsigned int*) (PLL1_BASE + 0x120)    /*Divider-3*/
#define PLL1_OSCDIV1    *(unsigned int*) (PLL1_BASE + 0x124)    /*Oscilator Divider*/
#define PLL1_POSTDIV    *(unsigned int*) (PLL1_BASE + 0x128)    /*Post Divider*/
#define PLL1_BPDIV      *(unsigned int*) (PLL1_BASE + 0x12C)    /*Bypass Divider*/
#define PLL1_WAKEUP     *(unsigned int*) (PLL1_BASE + 0x130)    /*Wakeup Reg*/
#define PLL1_PLLCMD     *(unsigned int*) (PLL1_BASE + 0x138)    /*Command Reg*/
#define PLL1_PLLSTAT    *(unsigned int*) (PLL1_BASE + 0x13C)    /*Status Reg*/
#define PLL1_ALNCTL     *(unsigned int*) (PLL1_BASE + 0x140)    /*Clock Align Control Reg*/
#define PLL1_DCHANGE    *(unsigned int*) (PLL1_BASE + 0x144)    /*PLLDIV Ratio Chnage status*/
#define PLL1_CKEN       *(unsigned int*) (PLL1_BASE + 0x148)    /*Clock Enable Reg*/
#define PLL1_CKSTAT     *(unsigned int*) (PLL1_BASE + 0x14C)    /*Clock Status Reg*/
#define PLL1_SYSTAT     *(unsigned int*) (PLL1_BASE + 0x150)    /*Sysclk status reg*/
#define PLL1_PLLDIV4    *(unsigned int*) (PLL1_BASE + 0x160)    /*Divider 4*/
#define PLL1_PLLDIV5    *(unsigned int*) (PLL1_BASE + 0x164)    /*Divider 5*/
#define PLL1_PLLDIV6    *(unsigned int*) (PLL1_BASE + 0x168)    /*Divider 6*/
#define PLL1_PLLDIV7    *(unsigned int*) (PLL1_BASE + 0x16C)    /*Divider 7*/
#define PLL1_PLLDIV8    *(unsigned int*) (PLL1_BASE + 0x170)    /*Divider 8*/
#define PLL1_PLLDIV9    *(unsigned int*) (PLL1_BASE + 0x174)    /*Divider 9*/
#define PLL1_PLLDIV10   *(unsigned int*) (PLL1_BASE + 0x178)    /*Divider 10*/
#define PLL1_PLLDIV11   *(unsigned int*) (PLL1_BASE + 0x17C)    /*Divider 11*/
#define PLL1_PLLDIV12   *(unsigned int*) (PLL1_BASE + 0x180)    /*Divider 12*/
#define PLL1_PLLDIV13   *(unsigned int*) (PLL1_BASE + 0x184)    /*Divider 13*/
#define PLL1_PLLDIV14   *(unsigned int*) (PLL1_BASE + 0x188)    /*Divider 14*/
#define PLL1_PLLDIV15   *(unsigned int*) (PLL1_BASE + 0x18C)    /*Divider 15*/
#define PLL1_PLLDIV16   *(unsigned int*) (PLL1_BASE + 0x190)    /*Divider 16*/



/*DDR MMR Declaration*/
#define VTPIO_CTL           *(unsigned int*)(0x01E2C000)                  // VTPIO_CTL Register
#define EMIFDDR_SDRAM_CFG   0xB0000000
#define EMIFDDR_REVID       *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x00)      //EMIF Module ID and Revision Register
#define EMIFDDR_SDRSTAT     *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x04)      //SDRAM Status Register
#define EMIFDDR_SDCR        *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x08)      //SDRAM Bank Config Register
#define EMIFDDR_SDRCR       *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x0C)      //SDRAM Refresh Control Register
#define EMIFDDR_SDTIMR1     *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x10)      //SDRAM Timing Register1
#define EMIFDDR_SDTIMR2     *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x14)      //SDRAM Timing Register2
#define EMIFDDR_SDCR2       *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x1C)      //SDRAM Config Register2
#define EMIFDDR_PBBPR       *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x20)      //VBUSM Burst Priority Register
#define EMIFDDR_VBUSMCFG1   *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x28)      //VBUSM config Value1 Register
#define EMIFDDR_VBUSMCFG2   *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0x2C)      //VBUSM config Value2 Register
#define EMIFDDR_IRR         *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xC0)      //Interrupt Raw Register
#define EMIFDDR_IMR         *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xC4)      //Interrupt Masked Register
#define EMIFDDR_IMSR        *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xC8)      //Interrupt Mask Set Register
#define EMIFDDR_IMCR        *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xCC)      //Interrupt Mask Clear Register
#define DDRPHYREV           *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xE0)      //DDR PHY ID and Revision Register
#define DRPYC1R             *(unsigned int*)(EMIFDDR_SDRAM_CFG + 0xE4)      //DDR PHY Control 1 Register

#define DDR2 0              // Do not change this value
#define MDDR 1              // Do not change this value
#define VTP_TIMEOUT 200     // This value can be optimized by the user
#define DDR_DEBUG 0         // Set this to "1" to program DDR with more timing slack



#define EMIFA             0x68000000
#define EMIFA_AWAITCFG    *(unsigned int*)(EMIFA + 0x04)
#define EMIFA_SDCFG       *(unsigned int*)(EMIFA + 0x08)
#define EMIFA_SDREF       *(unsigned int*)(EMIFA + 0x0C)
#define EMIFA_ACFG2       *(unsigned int*)(EMIFA + 0x10)    //Async Bank1 Config Register
#define EMIFA_ACFG3       *(unsigned int*)(EMIFA + 0x14)    //Async Bank2 Config Register
#define EMIFA_ACFG4       *(unsigned int*)(EMIFA + 0x18)    //Async Bank3 Config Register
#define EMIFA_ACFG5       *(unsigned int*)(EMIFA + 0x1C)    //Async Bank4 Config Register
#define EMIFA_SDTIM       *(unsigned int*)(EMIFA + 0x20)    //SDRAM Timing Register
#define EMIFA_SRPD        *(unsigned int*)(EMIFA + 0x3C)
#define EMIFA_NANDFCR     *(unsigned int*)(EMIFA + 0x60)


/*PSC Module Related Registers*/
#define PSC0_BASE       0x01C10000
#define PSC1_BASE       0x01E27000

#define PSC0_MDCTL      (PSC0_BASE+0xA00)
#define PSC0_MDSTAT     (PSC0_BASE+0x800)
#define PSC0_PTCMD      *(unsigned int*) (PSC0_BASE + 0x120)
#define PSC0_PTSTAT     *(unsigned int*) (PSC0_BASE + 0x128)

#define PSC1_MDCTL      (PSC1_BASE+0xA00)
#define PSC1_MDSTAT     (PSC1_BASE+0x800)
#define PSC1_PTCMD      *(unsigned int*) (PSC1_BASE + 0x120)
#define PSC1_PTSTAT     *(unsigned int*) (PSC1_BASE + 0x128)

#define PSC_TIMEOUT      200 // This value can be optimized by the user




/*System MMR Declaration*/
#define SYS_BASE           0x01C14000
#define HOST0CFG           *(unsigned int*)(SYS_BASE + 0x040)  //ARM HOST0CFG
#define KICK0R             *(unsigned int*)(SYS_BASE + 0x038)
#define KICK1R             *(unsigned int*)(SYS_BASE + 0x03c)
#define PINMUX0            *(unsigned int*)(SYS_BASE + 0x120)  //PINMUX0
#define PINMUX1            *(unsigned int*)(SYS_BASE + 0x124)  //PINMUX1
#define PINMUX2            *(unsigned int*)(SYS_BASE + 0x128)  //PINMUX2
#define PINMUX3            *(unsigned int*)(SYS_BASE + 0x12C)  //PINMUX3
#define PINMUX4            *(unsigned int*)(SYS_BASE + 0x130)  //PINMUX4
#define PINMUX5            *(unsigned int*)(SYS_BASE + 0x134)  //PINMUX5
#define PINMUX6            *(unsigned int*)(SYS_BASE + 0x138)  //PINMUX6
#define PINMUX7            *(unsigned int*)(SYS_BASE + 0x13C)  //PINMUX7
#define PINMUX8            *(unsigned int*)(SYS_BASE + 0x140)  //PINMUX8
#define PINMUX9            *(unsigned int*)(SYS_BASE + 0x144)  //PINMUX9
#define PINMUX10           *(unsigned int*)(SYS_BASE + 0x148)  //PINMUX10
#define PINMUX11           *(unsigned int*)(SYS_BASE + 0x14C)  //PINMUX11
#define PINMUX12           *(unsigned int*)(SYS_BASE + 0x150)  //PINMUX12
#define PINMUX13           *(unsigned int*)(SYS_BASE + 0x154)  //PINMUX13
#define PINMUX14           *(unsigned int*)(SYS_BASE + 0x158)  //PINMUX14
#define PINMUX15           *(unsigned int*)(SYS_BASE + 0x15C)  //PINMUX15
#define PINMUX16           *(unsigned int*)(SYS_BASE + 0x160)  //PINMUX16
#define PINMUX17           *(unsigned int*)(SYS_BASE + 0x164)  //PINMUX17
#define PINMUX18           *(unsigned int*)(SYS_BASE + 0x168)  //PINMUX18
#define PINMUX19           *(unsigned int*)(SYS_BASE + 0x16C)  //PINMUX19
#define CFGCHIP0           *(unsigned int*)(SYS_BASE + 0x17C)
#define CFGCHIP2           *(unsigned int*)(SYS_BASE + 0x184)
#define CFGCHIP3           *(unsigned int*)(SYS_BASE + 0x188)
#define PD0                0   /*Power Domain-0*/
#define PD1                1   /*Power Domain-1*/

#define PLLEN_MUX_SWITCH         4
#define PLL_LOCK_TIME_CNT        2400
#define PLL_STABILIZATION_TIME   2000
#define PLL_RESET_TIME_CNT       200


#endif
