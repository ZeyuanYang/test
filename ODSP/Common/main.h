/****************************************************************************/
/*                                                                          */
/*              OMAPL138 ¼° DSP C6748 Ð¾Æ¬¼Ä´æÆ÷¶¨Òå                        */
/*                                                                          */
/*              2014Äê02ÔÂ10ÈÕ                                              */
/*                                                                          */
/****************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

/****************************************************************************/
/*                                                                          */
/*              ¼Ä´æÆ÷¶¨Òå                                                  */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/
/*                                                                          */
/*              SYSCFG0                                                     */
/*                                                                          */
/****************************************************************************/
// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 0
union SYSCFG0Regs_PINMUX0
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX0_3_0  :4;  // 0-3
		volatile unsigned int PINMUX0_7_4  :4;  // 4-7
		volatile unsigned int PINMUX0_11_8 :4;  // 8-11
		volatile unsigned int PINMUX0_15_12:4;  // 12-15
		volatile unsigned int PINMUX0_19_16:4;  // 16-19
		volatile unsigned int PINMUX0_23_20:4;  // 20-23
		volatile unsigned int PINMUX0_27_24:4;  // 24-27
		volatile unsigned int PINMUX0_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 1
union SYSCFG0Regs_PINMUX1
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX1_3_0  :4;  // 0-3
		volatile unsigned int PINMUX1_7_4  :4;  // 4-7
		volatile unsigned int PINMUX1_11_8 :4;  // 8-11
		volatile unsigned int PINMUX1_15_12:4;  // 12-15
		volatile unsigned int PINMUX1_19_16:4;  // 16-19
		volatile unsigned int PINMUX1_23_20:4;  // 20-23
		volatile unsigned int PINMUX1_27_24:4;  // 24-27
		volatile unsigned int PINMUX1_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 2
union SYSCFG0Regs_PINMUX2
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX2_3_0  :4;  // 0-3
		volatile unsigned int PINMUX2_7_4  :4;  // 4-7
		volatile unsigned int PINMUX2_11_8 :4;  // 8-11
		volatile unsigned int PINMUX2_15_12:4;  // 12-15
		volatile unsigned int PINMUX2_19_16:4;  // 16-19
		volatile unsigned int PINMUX2_23_20:4;  // 20-23
		volatile unsigned int PINMUX2_27_24:4;  // 24-27
		volatile unsigned int PINMUX2_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 3
union SYSCFG0Regs_PINMUX3
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX3_3_0  :4;  // 0-3
		volatile unsigned int PINMUX3_7_4  :4;  // 4-7
		volatile unsigned int PINMUX3_11_8 :4;  // 8-11
		volatile unsigned int PINMUX3_15_12:4;  // 12-15
		volatile unsigned int PINMUX3_19_16:4;  // 16-19
		volatile unsigned int PINMUX3_23_20:4;  // 20-23
		volatile unsigned int PINMUX3_27_24:4;  // 24-27
		volatile unsigned int PINMUX3_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 4
union SYSCFG0Regs_PINMUX4
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX4_3_0  :4;  // 0-3
		volatile unsigned int PINMUX4_7_4  :4;  // 4-7
		volatile unsigned int PINMUX4_11_8 :4;  // 8-11
		volatile unsigned int PINMUX4_15_12:4;  // 12-15
		volatile unsigned int PINMUX4_19_16:4;  // 16-19
		volatile unsigned int PINMUX4_23_20:4;  // 20-23
		volatile unsigned int PINMUX4_27_24:4;  // 24-27
		volatile unsigned int PINMUX4_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 5
union SYSCFG0Regs_PINMUX5
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX5_3_0  :4;  // 0-3
		volatile unsigned int PINMUX5_7_4  :4;  // 4-7
		volatile unsigned int PINMUX5_11_8 :4;  // 8-11
		volatile unsigned int PINMUX5_15_12:4;  // 12-15
		volatile unsigned int PINMUX5_19_16:4;  // 16-19
		volatile unsigned int PINMUX5_23_20:4;  // 20-23
		volatile unsigned int PINMUX5_27_24:4;  // 24-27
		volatile unsigned int PINMUX5_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 6
union SYSCFG0Regs_PINMUX6
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX6_3_0  :4;  // 0-3
		volatile unsigned int PINMUX6_7_4  :4;  // 4-7
		volatile unsigned int PINMUX6_11_8 :4;  // 8-11
		volatile unsigned int PINMUX6_15_12:4;  // 12-15
		volatile unsigned int PINMUX6_19_16:4;  // 16-19
		volatile unsigned int PINMUX6_23_20:4;  // 20-23
		volatile unsigned int PINMUX6_27_24:4;  // 24-27
		volatile unsigned int PINMUX6_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 7
union SYSCFG0Regs_PINMUX7
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX7_3_0  :4;  // 0-3
		volatile unsigned int PINMUX7_7_4  :4;  // 4-7
		volatile unsigned int PINMUX7_11_8 :4;  // 8-11
		volatile unsigned int PINMUX7_15_12:4;  // 12-15
		volatile unsigned int PINMUX7_19_16:4;  // 16-19
		volatile unsigned int PINMUX7_23_20:4;  // 20-23
		volatile unsigned int PINMUX7_27_24:4;  // 24-27
		volatile unsigned int PINMUX7_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 8
union SYSCFG0Regs_PINMUX8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX8_3_0  :4;  // 0-3
		volatile unsigned int PINMUX8_7_4  :4;  // 4-7
		volatile unsigned int PINMUX8_11_8 :4;  // 8-11
		volatile unsigned int PINMUX8_15_12:4;  // 12-15
		volatile unsigned int PINMUX8_19_16:4;  // 16-19
		volatile unsigned int PINMUX8_23_20:4;  // 20-23
		volatile unsigned int PINMUX8_27_24:4;  // 24-27
		volatile unsigned int PINMUX8_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 9
union SYSCFG0Regs_PINMUX9
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX9_3_0  :4;  // 0-3
		volatile unsigned int PINMUX9_7_4  :4;  // 4-7
		volatile unsigned int PINMUX9_11_8 :4;  // 8-11
		volatile unsigned int PINMUX9_15_12:4;  // 12-15
		volatile unsigned int PINMUX9_19_16:4;  // 16-19
		volatile unsigned int PINMUX9_23_20:4;  // 20-23
		volatile unsigned int PINMUX9_27_24:4;  // 24-27
		volatile unsigned int PINMUX9_31_28:4;  // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 10
union SYSCFG0Regs_PINMUX10
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX10_3_0  :4; // 0-3
		volatile unsigned int PINMUX10_7_4  :4; // 4-7
		volatile unsigned int PINMUX10_11_8 :4; // 8-11
		volatile unsigned int PINMUX10_15_12:4; // 12-15
		volatile unsigned int PINMUX10_19_16:4; // 16-19
		volatile unsigned int PINMUX10_23_20:4; // 20-23
		volatile unsigned int PINMUX10_27_24:4; // 24-27
		volatile unsigned int PINMUX10_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 11
union SYSCFG0Regs_PINMUX11
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX11_3_0  :4; // 0-3
		volatile unsigned int PINMUX11_7_4  :4; // 4-7
		volatile unsigned int PINMUX11_11_8 :4; // 8-11
		volatile unsigned int PINMUX11_15_12:4; // 12-15
		volatile unsigned int PINMUX11_19_16:4; // 16-19
		volatile unsigned int PINMUX11_23_20:4; // 20-23
		volatile unsigned int PINMUX11_27_24:4; // 24-27
		volatile unsigned int PINMUX11_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 12
union SYSCFG0Regs_PINMUX12
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX12_3_0  :4; // 0-3
		volatile unsigned int PINMUX12_7_4  :4; // 4-7
		volatile unsigned int PINMUX12_11_8 :4; // 8-11
		volatile unsigned int PINMUX12_15_12:4; // 12-15
		volatile unsigned int PINMUX12_19_16:4; // 16-19
		volatile unsigned int PINMUX12_23_20:4; // 20-23
		volatile unsigned int PINMUX12_27_24:4; // 24-27
		volatile unsigned int PINMUX12_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 13
union SYSCFG0Regs_PINMUX13
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX13_3_0  :4; // 0-3
		volatile unsigned int PINMUX13_7_4  :4; // 4-7
		volatile unsigned int PINMUX13_11_8 :4; // 8-11
		volatile unsigned int PINMUX13_15_12:4; // 12-15
		volatile unsigned int PINMUX13_19_16:4; // 16-19
		volatile unsigned int PINMUX13_23_20:4; // 20-23
		volatile unsigned int PINMUX13_27_24:4; // 24-27
		volatile unsigned int PINMUX13_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 14
union SYSCFG0Regs_PINMUX14
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX14_3_0  :4; // 0-3
		volatile unsigned int PINMUX14_7_4  :4; // 4-7
		volatile unsigned int PINMUX14_11_8 :4; // 8-11
		volatile unsigned int PINMUX14_15_12:4; // 12-15
		volatile unsigned int PINMUX14_19_16:4; // 16-19
		volatile unsigned int PINMUX14_23_20:4; // 20-23
		volatile unsigned int PINMUX14_27_24:4; // 24-27
		volatile unsigned int PINMUX14_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 15
union SYSCFG0Regs_PINMUX15
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX15_3_0  :4; // 0-3
		volatile unsigned int PINMUX15_7_4  :4; // 4-7
		volatile unsigned int PINMUX15_11_8 :4; // 8-11
		volatile unsigned int PINMUX15_15_12:4; // 12-15
		volatile unsigned int PINMUX15_19_16:4; // 16-19
		volatile unsigned int PINMUX15_23_20:4; // 20-23
		volatile unsigned int PINMUX15_27_24:4; // 24-27
		volatile unsigned int PINMUX15_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 16
union SYSCFG0Regs_PINMUX16
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX16_3_0  :4; // 0-3
		volatile unsigned int PINMUX16_7_4  :4; // 4-7
		volatile unsigned int PINMUX16_11_8 :4; // 8-11
		volatile unsigned int PINMUX16_15_12:4; // 12-15
		volatile unsigned int PINMUX16_19_16:4; // 16-19
		volatile unsigned int PINMUX16_23_20:4; // 20-23
		volatile unsigned int PINMUX16_27_24:4; // 24-27
		volatile unsigned int PINMUX16_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 17
union SYSCFG0Regs_PINMUX17
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX17_3_0  :4; // 0-3
		volatile unsigned int PINMUX17_7_4  :4; // 4-7
		volatile unsigned int PINMUX17_11_8 :4; // 8-11
		volatile unsigned int PINMUX17_15_12:4; // 12-15
		volatile unsigned int PINMUX17_19_16:4; // 16-19
		volatile unsigned int PINMUX17_23_20:4; // 20-23
		volatile unsigned int PINMUX17_27_24:4; // 24-27
		volatile unsigned int PINMUX17_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 18
union SYSCFG0Regs_PINMUX18
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX18_3_0  :4; // 0-3
		volatile unsigned int PINMUX18_7_4  :4; // 4-7
		volatile unsigned int PINMUX18_11_8 :4; // 8-11
		volatile unsigned int PINMUX18_15_12:4; // 12-15
		volatile unsigned int PINMUX18_19_16:4; // 16-19
		volatile unsigned int PINMUX18_23_20:4; // 20-23
		volatile unsigned int PINMUX18_27_24:4; // 24-27
		volatile unsigned int PINMUX18_31_28:4; // 28-31
	} bit;
};

// ¹Ü½Å¸´ÓÃ¿ØÖÆ¼Ä´æÆ÷ 19
union SYSCFG0Regs_PINMUX19
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int PINMUX19_3_0  :4; // 0-3
		volatile unsigned int PINMUX19_7_4  :4; // 4-7
		volatile unsigned int PINMUX19_11_8 :4; // 8-11
		volatile unsigned int PINMUX19_15_12:4; // 12-15
		volatile unsigned int PINMUX19_19_16:4; // 16-19
		volatile unsigned int PINMUX19_23_20:4; // 20-23
		volatile unsigned int PINMUX19_27_24:4; // 24-27
		volatile unsigned int PINMUX19_31_28:4; // 28-31
	} bit;
};

// Ð¾Æ¬ÐÅºÅ¼Ä´æÆ÷
union SYSCFG0Regs_CHIPSIG
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int CHIPSIG0:1;       // 0
		volatile unsigned int CHIPSIG1:1;       // 1
		volatile unsigned int CHIPSIG2:1;       // 2
		volatile unsigned int CHIPSIG3:1;       // 3
		volatile unsigned int CHIPSIG4:1;       // 4
		volatile unsigned int         :27;      // 5-31
	} bit;
};

// Ð¾Æ¬ÐÅºÅÇå³ý¼Ä´æÆ÷
union SYSCFG0Regs_CHIPSIG_CLR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int CHIPSIG0:1;       // 0
		volatile unsigned int CHIPSIG1:1;       // 1
		volatile unsigned int CHIPSIG2:1;       // 2
		volatile unsigned int CHIPSIG3:1;       // 3
		volatile unsigned int CHIPSIG4:1;       // 4
		volatile unsigned int         :27;      // 5-31
	} bit;
};

// SYSCFG0 ¼Ä´æÆ÷×é
struct hw_SYSCFG0Regs
{
    volatile unsigned int 			REVID;
    volatile unsigned int   		RSVD0;
    volatile unsigned int   		DIEIDR0;
    volatile unsigned int 			DIEIDR1;
    volatile unsigned int 			DIEIDR2;
    volatile unsigned int 			DIEIDR3;
    volatile unsigned int 			DEVIDR0;
    volatile unsigned char   		RSVD1[2];
    volatile unsigned int   		BOOTCFG;
    volatile unsigned int   		RSVD2[5];
    volatile unsigned int 			KICK0R;
    volatile unsigned int 			KICK1R;
    volatile unsigned int 			HOST0CFG;
    volatile unsigned int 			HOST1CFG;
    volatile unsigned int   		RSVD3[38];
    volatile unsigned int 			IRAWSTAT;
    volatile unsigned int   		IENSTAT;
    volatile unsigned int 			IENSET;
    volatile unsigned int 			IENCLR;
    volatile unsigned int 			EOI;
    volatile unsigned int   		FLTADDRR;
    volatile unsigned int 			FLTSTAT;
    volatile unsigned int   		RSVD4[5];
    volatile unsigned int 			MSTPRI0;
    volatile unsigned int 			MSTPRI1;
    volatile unsigned int   		MSTPRI2;
    volatile unsigned int   		RSVD5;
    union SYSCFG0Regs_PINMUX0  		PINMUX0;
    union SYSCFG0Regs_PINMUX1  		PINMUX1;
    union SYSCFG0Regs_PINMUX2  		PINMUX2;
    union SYSCFG0Regs_PINMUX3  		PINMUX3;
    union SYSCFG0Regs_PINMUX4  		PINMUX4;
    union SYSCFG0Regs_PINMUX5  		PINMUX5;
    union SYSCFG0Regs_PINMUX6  		PINMUX6;
    union SYSCFG0Regs_PINMUX7  		PINMUX7;
    union SYSCFG0Regs_PINMUX8  		PINMUX8;
    union SYSCFG0Regs_PINMUX9  		PINMUX9;
    union SYSCFG0Regs_PINMUX10  	PINMUX10;
    union SYSCFG0Regs_PINMUX11  	PINMUX11;
    union SYSCFG0Regs_PINMUX12 		PINMUX12;
    union SYSCFG0Regs_PINMUX13 		PINMUX13;
    union SYSCFG0Regs_PINMUX14 		PINMUX14;
    union SYSCFG0Regs_PINMUX15 		PINMUX15;
    union SYSCFG0Regs_PINMUX16 		PINMUX16;
    union SYSCFG0Regs_PINMUX17 		PINMUX17;
    union SYSCFG0Regs_PINMUX18 		PINMUX18;
    union SYSCFG0Regs_PINMUX19 		PINMUX19;
    volatile unsigned int 			SUSPSRC;
    union SYSCFG0Regs_CHIPSIG 		CHIPSIG;
    union SYSCFG0Regs_CHIPSIG_CLR 	CHIPSIG_CLR;
    volatile unsigned int 			CFGCHIP0;
    volatile unsigned int 			CFGCHIP1;
    volatile unsigned int 			CFGCHIP2;
    volatile unsigned int 			CFGCHIP3;
    volatile unsigned int 			CFGCHIP4;
};

//// SYSCFG0 ´æ´¢¿Õ¼äÓ³Éä
//#pragma DATA_SECTION(SYSCFG0Regs,".Reg_SYSCFG0");
//volatile struct hw_SYSCFG0Regs SYSCFG0Regs;

/****************************************************************************/
/*                                                                          */
/*              GPIO                                                        */
/*                                                                          */
/****************************************************************************/
// GPIO ×éÖÐ¶ÏÊ¹ÄÜ¼Ä´æÆ÷
union GPIORegs_BINTEN
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int EN0     :1;  	 // 0
		volatile unsigned int EN1     :1;  	 // 1
		volatile unsigned int EN2     :1;  	 // 2
		volatile unsigned int EN3     :1;  	 // 3
		volatile unsigned int EN4     :1;  	 // 4
		volatile unsigned int EN5     :1;  	 // 5
		volatile unsigned int EN6     :1;  	 // 6
		volatile unsigned int EN7     :1;  	 // 7
		volatile unsigned int EN8     :1;  	 // 8
		volatile unsigned int         :23; 	 // 9-31
	} bit;
};

// GPIO01 ·½Ïò¼Ä´æÆ÷
union GPIORegs_DIR01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 Êä³öÊý¾Ý¼Ä´æÆ÷
union GPIORegs_OUT_DATA01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 ÖÃÎ»¼Ä´æÆ÷
union GPIORegs_SET_DATA01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 ¸´Î»¼Ä´æÆ÷
union GPIORegs_CLR_DATA01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 ÊäÈëÊý¾Ý¼Ä´æÆ÷
union GPIORegs_IN_DATA01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 ÉèÖÃÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_RIS_TRIG01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 Çå³ýÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_RIS_TRIG01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 ÉèÖÃÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_FAL_TRIG01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 Çå³ýÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_FAL_TRIG01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO01 ÖÐ¶Ï×´Ì¬¼Ä´æÆ÷
union GPIORegs_INTSTAT01
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP0P0   :1;  	 // 0
		volatile unsigned int GP0P1   :1;  	 // 1
		volatile unsigned int GP0P2   :1;  	 // 2
		volatile unsigned int GP0P3   :1;  	 // 3
		volatile unsigned int GP0P4   :1;  	 // 4
		volatile unsigned int GP0P5   :1;  	 // 5
		volatile unsigned int GP0P6   :1;  	 // 6
		volatile unsigned int GP0P7   :1;  	 // 7
		volatile unsigned int GP0P8   :1;  	 // 8
		volatile unsigned int GP0P9   :1;  	 // 9
		volatile unsigned int GP0P10  :1;  	 // 10
		volatile unsigned int GP0P11  :1;  	 // 11
		volatile unsigned int GP0P12  :1;  	 // 12
		volatile unsigned int GP0P13  :1;  	 // 13
		volatile unsigned int GP0P14  :1;  	 // 14
		volatile unsigned int GP0P15  :1;  	 // 15
		volatile unsigned int GP1P0   :1;  	 // 16
		volatile unsigned int GP1P1   :1;  	 // 17
		volatile unsigned int GP1P2   :1;  	 // 18
		volatile unsigned int GP1P3   :1;  	 // 19
		volatile unsigned int GP1P4   :1;  	 // 20
		volatile unsigned int GP1P5   :1;  	 // 21
		volatile unsigned int GP1P6   :1;  	 // 22
		volatile unsigned int GP1P7   :1;  	 // 23
		volatile unsigned int GP1P8   :1;  	 // 24
		volatile unsigned int GP1P9   :1;  	 // 25
		volatile unsigned int GP1P10  :1;  	 // 26
		volatile unsigned int GP1P11  :1;  	 // 27
		volatile unsigned int GP1P12  :1;  	 // 28
		volatile unsigned int GP1P13  :1;  	 // 29
		volatile unsigned int GP1P14  :1;  	 // 30
		volatile unsigned int GP1P15  :1;  	 // 31
	} bit;
};

// GPIO23 ·½Ïò¼Ä´æÆ÷
union GPIORegs_DIR23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 Êä³öÊý¾Ý¼Ä´æÆ÷
union GPIORegs_OUT_DATA23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 ÖÃÎ»¼Ä´æÆ÷
union GPIORegs_SET_DATA23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 ¸´Î»¼Ä´æÆ÷
union GPIORegs_CLR_DATA23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 ÊäÈëÊý¾Ý¼Ä´æÆ÷
union GPIORegs_IN_DATA23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 ÉèÖÃÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_RIS_TRIG23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 Çå³ýÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_RIS_TRIG23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 ÉèÖÃÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_FAL_TRIG23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 Çå³ýÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_FAL_TRIG23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO23 ÖÐ¶Ï×´Ì¬¼Ä´æÆ÷
union GPIORegs_INTSTAT23
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP2P0   :1;  	 // 0
		volatile unsigned int GP2P1   :1;  	 // 1
		volatile unsigned int GP2P2   :1;  	 // 2
		volatile unsigned int GP2P3   :1;  	 // 3
		volatile unsigned int GP2P4   :1;  	 // 4
		volatile unsigned int GP2P5   :1;  	 // 5
		volatile unsigned int GP2P6   :1;  	 // 6
		volatile unsigned int GP2P7   :1;  	 // 7
		volatile unsigned int GP2P8   :1;  	 // 8
		volatile unsigned int GP2P9   :1;  	 // 9
		volatile unsigned int GP2P10  :1;  	 // 10
		volatile unsigned int GP2P11  :1;  	 // 11
		volatile unsigned int GP2P12  :1;  	 // 12
		volatile unsigned int GP2P13  :1;  	 // 13
		volatile unsigned int GP2P14  :1;  	 // 14
		volatile unsigned int GP2P15  :1;  	 // 15
		volatile unsigned int GP3P0   :1;  	 // 16
		volatile unsigned int GP3P1   :1;  	 // 17
		volatile unsigned int GP3P2   :1;  	 // 18
		volatile unsigned int GP3P3   :1;  	 // 19
		volatile unsigned int GP3P4   :1;  	 // 20
		volatile unsigned int GP3P5   :1;  	 // 21
		volatile unsigned int GP3P6   :1;  	 // 22
		volatile unsigned int GP3P7   :1;  	 // 23
		volatile unsigned int GP3P8   :1;  	 // 24
		volatile unsigned int GP3P9   :1;  	 // 25
		volatile unsigned int GP3P10  :1;  	 // 26
		volatile unsigned int GP3P11  :1;  	 // 27
		volatile unsigned int GP3P12  :1;  	 // 28
		volatile unsigned int GP3P13  :1;  	 // 29
		volatile unsigned int GP3P14  :1;  	 // 30
		volatile unsigned int GP3P15  :1;  	 // 31
	} bit;
};

// GPIO45 ·½Ïò¼Ä´æÆ÷
union GPIORegs_DIR45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 Êä³öÊý¾Ý¼Ä´æÆ÷
union GPIORegs_OUT_DATA45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 ÖÃÎ»¼Ä´æÆ÷
union GPIORegs_SET_DATA45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 ¸´Î»¼Ä´æÆ÷
union GPIORegs_CLR_DATA45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 ÊäÈëÊý¾Ý¼Ä´æÆ÷
union GPIORegs_IN_DATA45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 ÉèÖÃÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_RIS_TRIG45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 Çå³ýÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_RIS_TRIG45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 ÉèÖÃÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_FAL_TRIG45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 Çå³ýÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_FAL_TRIG45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO45 ÖÐ¶Ï×´Ì¬¼Ä´æÆ÷
union GPIORegs_INTSTAT45
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP4P0   :1;  	 // 0
		volatile unsigned int GP4P1   :1;  	 // 1
		volatile unsigned int GP4P2   :1;  	 // 2
		volatile unsigned int GP4P3   :1;  	 // 3
		volatile unsigned int GP4P4   :1;  	 // 4
		volatile unsigned int GP4P5   :1;  	 // 5
		volatile unsigned int GP4P6   :1;  	 // 6
		volatile unsigned int GP4P7   :1;  	 // 7
		volatile unsigned int GP4P8   :1;  	 // 8
		volatile unsigned int GP4P9   :1;  	 // 9
		volatile unsigned int GP4P10  :1;  	 // 10
		volatile unsigned int GP4P11  :1;  	 // 11
		volatile unsigned int GP4P12  :1;  	 // 12
		volatile unsigned int GP4P13  :1;  	 // 13
		volatile unsigned int GP4P14  :1;  	 // 14
		volatile unsigned int GP4P15  :1;  	 // 15
		volatile unsigned int GP5P0   :1;  	 // 16
		volatile unsigned int GP5P1   :1;  	 // 17
		volatile unsigned int GP5P2   :1;  	 // 18
		volatile unsigned int GP5P3   :1;  	 // 19
		volatile unsigned int GP5P4   :1;  	 // 20
		volatile unsigned int GP5P5   :1;  	 // 21
		volatile unsigned int GP5P6   :1;  	 // 22
		volatile unsigned int GP5P7   :1;  	 // 23
		volatile unsigned int GP5P8   :1;  	 // 24
		volatile unsigned int GP5P9   :1;  	 // 25
		volatile unsigned int GP5P10  :1;  	 // 26
		volatile unsigned int GP5P11  :1;  	 // 27
		volatile unsigned int GP5P12  :1;  	 // 28
		volatile unsigned int GP5P13  :1;  	 // 29
		volatile unsigned int GP5P14  :1;  	 // 30
		volatile unsigned int GP5P15  :1;  	 // 31
	} bit;
};

// GPIO67 ·½Ïò¼Ä´æÆ÷
union GPIORegs_DIR67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 Êä³öÊý¾Ý¼Ä´æÆ÷
union GPIORegs_OUT_DATA67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 ÖÃÎ»¼Ä´æÆ÷
union GPIORegs_SET_DATA67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 ¸´Î»¼Ä´æÆ÷
union GPIORegs_CLR_DATA67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 ÊäÈëÊý¾Ý¼Ä´æÆ÷
union GPIORegs_IN_DATA67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 ÉèÖÃÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_RIS_TRIG67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 Çå³ýÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_RIS_TRIG67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 ÉèÖÃÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_FAL_TRIG67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 Çå³ýÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_FAL_TRIG67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO67 ÖÐ¶Ï×´Ì¬¼Ä´æÆ÷
union GPIORegs_INTSTAT67
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP6P0   :1;  	 // 0
		volatile unsigned int GP6P1   :1;  	 // 1
		volatile unsigned int GP6P2   :1;  	 // 2
		volatile unsigned int GP6P3   :1;  	 // 3
		volatile unsigned int GP6P4   :1;  	 // 4
		volatile unsigned int GP6P5   :1;  	 // 5
		volatile unsigned int GP6P6   :1;  	 // 6
		volatile unsigned int GP6P7   :1;  	 // 7
		volatile unsigned int GP6P8   :1;  	 // 8
		volatile unsigned int GP6P9   :1;  	 // 9
		volatile unsigned int GP6P10  :1;  	 // 10
		volatile unsigned int GP6P11  :1;  	 // 11
		volatile unsigned int GP6P12  :1;  	 // 12
		volatile unsigned int GP6P13  :1;  	 // 13
		volatile unsigned int GP6P14  :1;  	 // 14
		volatile unsigned int GP6P15  :1;  	 // 15
		volatile unsigned int GP7P0   :1;  	 // 16
		volatile unsigned int GP7P1   :1;  	 // 17
		volatile unsigned int GP7P2   :1;  	 // 18
		volatile unsigned int GP7P3   :1;  	 // 19
		volatile unsigned int GP7P4   :1;  	 // 20
		volatile unsigned int GP7P5   :1;  	 // 21
		volatile unsigned int GP7P6   :1;  	 // 22
		volatile unsigned int GP7P7   :1;  	 // 23
		volatile unsigned int GP7P8   :1;  	 // 24
		volatile unsigned int GP7P9   :1;  	 // 25
		volatile unsigned int GP7P10  :1;  	 // 26
		volatile unsigned int GP7P11  :1;  	 // 27
		volatile unsigned int GP7P12  :1;  	 // 28
		volatile unsigned int GP7P13  :1;  	 // 29
		volatile unsigned int GP7P14  :1;  	 // 30
		volatile unsigned int GP7P15  :1;  	 // 31
	} bit;
};

// GPIO8 ·½Ïò¼Ä´æÆ÷
union GPIORegs_DIR8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 Êä³öÊý¾Ý¼Ä´æÆ÷
union GPIORegs_OUT_DATA8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 ÖÃÎ»¼Ä´æÆ÷
union GPIORegs_SET_DATA8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 ¸´Î»¼Ä´æÆ÷
union GPIORegs_CLR_DATA8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 ÊäÈëÊý¾Ý¼Ä´æÆ÷
union GPIORegs_IN_DATA8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 ÉèÖÃÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_RIS_TRIG8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 Çå³ýÉÏÉýÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_RIS_TRIG8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 ÉèÖÃÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_SET_FAL_TRIG8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 Çå³ýÏÂ½µÑØ´¥·¢¼Ä´æÆ÷
union GPIORegs_CLR_FAL_TRIG8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO8 ÖÐ¶Ï×´Ì¬¼Ä´æÆ÷
union GPIORegs_INTSTAT8
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int GP8P0   :1;  	 // 0
		volatile unsigned int GP8P1   :1;  	 // 1
		volatile unsigned int GP8P2   :1;  	 // 2
		volatile unsigned int GP8P3   :1;  	 // 3
		volatile unsigned int GP8P4   :1;  	 // 4
		volatile unsigned int GP8P5   :1;  	 // 5
		volatile unsigned int GP8P6   :1;  	 // 6
		volatile unsigned int GP8P7   :1;  	 // 7
		volatile unsigned int GP8P8   :1;  	 // 8
		volatile unsigned int GP8P9   :1;  	 // 9
		volatile unsigned int GP8P10  :1;  	 // 10
		volatile unsigned int GP8P11  :1;  	 // 11
		volatile unsigned int GP8P12  :1;  	 // 12
		volatile unsigned int GP8P13  :1;  	 // 13
		volatile unsigned int GP8P14  :1;  	 // 14
		volatile unsigned int GP8P15  :1;  	 // 15
		volatile unsigned int         :16; 	 // 16-31
	} bit;
};

// GPIO ¼Ä´æÆ÷×é
struct hw_GPIORegs
{
    volatile unsigned int			REVID;
    volatile unsigned int			Reserved1;
    union GPIORegs_BINTEN 			BINTEN;
    volatile unsigned int			Reserved2;

	union GPIORegs_DIR01			DIR01;
	union GPIORegs_OUT_DATA01		OUT_DATA01;
	union GPIORegs_SET_DATA01 		SET_DATA01;
	union GPIORegs_CLR_DATA01 		CLR_DATA01;
	union GPIORegs_IN_DATA01 		IN_DATA01;
	union GPIORegs_SET_RIS_TRIG01 	SET_RIS_TRIG01;
	union GPIORegs_CLR_RIS_TRIG01 	CLR_RIS_TRIG01;
	union GPIORegs_SET_FAL_TRIG01 	SET_FAL_TRIG01;
	union GPIORegs_CLR_FAL_TRIG01 	CLR_FAL_TRIG01;
	union GPIORegs_INTSTAT01 		INTSTAT01;

	union GPIORegs_DIR23			DIR23;
	union GPIORegs_OUT_DATA23		OUT_DATA23;
	union GPIORegs_SET_DATA23 		SET_DATA23;
	union GPIORegs_CLR_DATA23 		CLR_DATA23;
	union GPIORegs_IN_DATA23 		IN_DATA23;
	union GPIORegs_SET_RIS_TRIG23 	SET_RIS_TRIG23;
	union GPIORegs_CLR_RIS_TRIG23 	CLR_RIS_TRIG23;
	union GPIORegs_SET_FAL_TRIG23 	SET_FAL_TRIG23;
	union GPIORegs_CLR_FAL_TRIG23 	CLR_FAL_TRIG23;
	union GPIORegs_INTSTAT23 		INTSTAT23;

	union GPIORegs_DIR45			DIR45;
	union GPIORegs_OUT_DATA45		OUT_DATA45;
	union GPIORegs_SET_DATA45 		SET_DATA45;
	union GPIORegs_CLR_DATA45 		CLR_DATA45;
	union GPIORegs_IN_DATA45 		IN_DATA45;
	union GPIORegs_SET_RIS_TRIG45 	SET_RIS_TRIG45;
	union GPIORegs_CLR_RIS_TRIG45 	CLR_RIS_TRIG45;
	union GPIORegs_SET_FAL_TRIG45 	SET_FAL_TRIG45;
	union GPIORegs_CLR_FAL_TRIG45 	CLR_FAL_TRIG45;
	union GPIORegs_INTSTAT45 		INTSTAT45;

	union GPIORegs_DIR67			DIR67;
	union GPIORegs_OUT_DATA67		OUT_DATA67;
	union GPIORegs_SET_DATA67 		SET_DATA67;
	union GPIORegs_CLR_DATA67 		CLR_DATA67;
	union GPIORegs_IN_DATA67 		IN_DATA67;
	union GPIORegs_SET_RIS_TRIG67 	SET_RIS_TRIG67;
	union GPIORegs_CLR_RIS_TRIG67 	CLR_RIS_TRIG67;
	union GPIORegs_SET_FAL_TRIG67 	SET_FAL_TRIG67;
	union GPIORegs_CLR_FAL_TRIG67 	CLR_FAL_TRIG67;
	union GPIORegs_INTSTAT67 		INTSTAT67;

	union GPIORegs_DIR8				DIR8;
	union GPIORegs_OUT_DATA8		OUT_DATA8;
	union GPIORegs_SET_DATA8 		SET_DATA8;
	union GPIORegs_CLR_DATA8 		CLR_DATA8;
	union GPIORegs_IN_DATA8 		IN_DATA8;
	union GPIORegs_SET_RIS_TRIG8 	SET_RIS_TRIG8;
	union GPIORegs_CLR_RIS_TRIG8 	CLR_RIS_TRIG8;
	union GPIORegs_SET_FAL_TRIG8 	SET_FAL_TRIG8;
	union GPIORegs_CLR_FAL_TRIG8 	CLR_FAL_TRIG8;
	union GPIORegs_INTSTAT8 		INTSTAT8;
};

//// GPIO ÍâÉè´æ´¢¿Õ¼äÓ³Éä
//#pragma DATA_SECTION(GPIORegs,".Reg_GPIO");
//volatile struct hw_GPIORegs GPIORegs;

/****************************************************************************/
/*                                                                          */
/*              McBSP1                                                      */
/*                                                                          */
/****************************************************************************/
// McBSP1 ´®ÐÐ¿Ú¿ØÖÆ¼Ä´æÆ÷
union McBSP1Regs_SPCR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int RRST        :1;       // 0
		volatile unsigned int RRDY        :1;       // 1
		volatile unsigned int RFULL       :1;       // 2
		volatile unsigned int RSYNCERR    :1;       // 3
		volatile unsigned int RINTM       :2;       // 4-5
		volatile unsigned int             :1;       // 6
		volatile unsigned int DXENA       :1;       // 7
		volatile unsigned int             :3;       // 8-10
		volatile unsigned int CLKSTP      :2;       // 11-12
		volatile unsigned int RJUST       :2;       // 13-14
		volatile unsigned int DLB         :1;       // 15
		volatile unsigned int XRST        :1;       // 16
		volatile unsigned int XRDY        :1;       // 17
		volatile unsigned int XEMPTY      :1;       // 18
		volatile unsigned int XSYNCERR    :1;       // 19
		volatile unsigned int XINTM       :2;       // 20-21
		volatile unsigned int GRST        :1;       // 22
		volatile unsigned int FRST        :1;       // 23
		volatile unsigned int SOFT        :1;       // 24
		volatile unsigned int FREE        :1;       // 25
		volatile unsigned int             :6;       // 26-31
	} bit;
};

// McBSP1 ½ÓÊÕ¿ØÖÆ¼Ä´æÆ÷
union McBSP1Regs_RCR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int         :4;         // 0-3
		volatile unsigned int RWDREVRS:1;         // 4
		volatile unsigned int RWDLEN1 :3;         // 5-7
		volatile unsigned int RFRLEN1 :7;         // 8-14
		volatile unsigned int         :1;         // 15
		volatile unsigned int RDATDLY :2;         // 16-17
		volatile unsigned int RFIG    :1;         // 18
		volatile unsigned int RCOMPAND:2;         // 19-20
		volatile unsigned int RWDLEN2 :3;         // 21-23
		volatile unsigned int RFRLEN2 :7;         // 24-30
		volatile unsigned int RPHASE  :1;         // 31
	} bit;
};

// McBSP1 ·¢ËÍ¿ØÖÆ¼Ä´æÆ÷
union McBSP1Regs_XCR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int         :4;         // 0-3
		volatile unsigned int XWDREVRS:1;         // 4
		volatile unsigned int XWDLEN1 :3;         // 5-7
		volatile unsigned int XFRLEN1 :7;         // 8-14
		volatile unsigned int         :1;         // 15
		volatile unsigned int XDATDLY :2;         // 16-17
		volatile unsigned int XFIG    :1;         // 18
		volatile unsigned int XCOMPAND:2;         // 19-20
		volatile unsigned int XWDLEN2 :3;         // 21-23
		volatile unsigned int XFRLEN2 :7;         // 24-30
		volatile unsigned int XPHASE  :1;         // 31
	} bit;
};

// McBSP1 ²ÉÑùÂÊÉú³É¼Ä´æÆ÷
union McBSP1Regs_SRGR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int CLKGDV  :8;         // 0-7
		volatile unsigned int FWID    :8;         // 8-15
		volatile unsigned int FPER    :12;        // 16-27
		volatile unsigned int FSGM    :1;         // 28
		volatile unsigned int CLKSM   :1;         // 29
		volatile unsigned int CLKSP   :1;         // 30
		volatile unsigned int GSYNC   :1;         // 31
	} bit;
};

// McBSP1 ¶àÍ¨µÀ¿ØÖÆ¼Ä´æÆ÷
union McBSP1Regs_MCR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int RMCM    :1;         // 0
		volatile unsigned int         :1;         // 1
		volatile unsigned int RCBLK   :3;         // 2-4
		volatile unsigned int RPABLK  :2;         // 5-6
		volatile unsigned int RPBBLK  :2;         // 7-8
		volatile unsigned int RMCME   :1;         // 9
		volatile unsigned int         :6;         // 15-10
		volatile unsigned int XMCM    :2;         // 16-17
		volatile unsigned int XCBLK   :3;         // 18-20
		volatile unsigned int XPABLK  :2;         // 21-22
		volatile unsigned int XPBBLK  :2;         // 23-24
		volatile unsigned int XMCME   :1;         // 25
		volatile unsigned int         :6;         // 26-31
	} bit;
};

// McBSP1 ¹Ü½Å¿ØÖÆ¼Ä´æÆ÷
union McBSP1_PCR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int CLKRP   :1;         // 0
		volatile unsigned int CLKXP   :1;         // 1
		volatile unsigned int FSRP    :1;         // 2
		volatile unsigned int FSXP    :1;         // 3
		volatile unsigned int         :1;         // 4-5
		volatile unsigned int         :1;         // 6
		volatile unsigned int SCLKME  :1;         // 7
		volatile unsigned int CLKRM   :1;         // 8
		volatile unsigned int CLKXM   :1;         // 9
		volatile unsigned int FSRM    :1;         // 10
		volatile unsigned int FSXM    :1;         // 11
		volatile unsigned int         :2;         // 12-13
		volatile unsigned int         :18;        // 14-31
	} bit;
};

// McBSP1 ¼Ä´æÆ÷×é
struct hw_McBSP1Regs
{
    volatile unsigned int 	DRR;
    volatile unsigned int 	DXR;
    union McBSP1Regs_SPCR	SPCR;
    union McBSP1Regs_RCR	RCR;
    union McBSP1Regs_XCR	XCR;
    union McBSP1Regs_SRGR	SRGR;
    union McBSP1Regs_MCR	MCR;
    volatile unsigned int 	RCERE0;
    volatile unsigned int 	XCERE0;
    union McBSP1_PCR		PCR;
    volatile unsigned int 	RCERE1;
    volatile unsigned int 	XCERE1;
    volatile unsigned int 	RCERE2;
    volatile unsigned int 	XCERE2;
    volatile unsigned int 	RCERE3;
    volatile unsigned int 	XCERE3;
};

//// McBSP1 ÍâÉè´æ´¢¿Õ¼äÓ³Éä
//#pragma DATA_SECTION(McBSP1Regs,".Reg_McBSP1");
//#pragma DATA_SECTION(McBSP0Regs,".Reg_McBSP1");
//volatile struct hw_McBSP1Regs McBSP1Regs,McBSP0Regs;

/****************************************************************************/
/*                                                                          */
/*              uPP                                                         */
/*                                                                          */
/****************************************************************************/
// uPP ÍâÉè¿ØÖÆ¼Ä´æÆ÷
union uPPRegs_UPPCR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int FREE    :1;        // 0
		volatile unsigned int SOFT    :1;        // 1
		volatile unsigned int RTEMU   :1;        // 2
		volatile unsigned int EN      :1;        // 3
		volatile unsigned int SWRST   :1;        // 4
		volatile unsigned int         :2;        // 5-6
		volatile unsigned int DB      :1;        // 7
		volatile unsigned int         :24;       // 8-31
	} bit;
};

// uPP Êý×Ö»·Â·ÅäÖÃ¼Ä´æÆ÷
union uPPRegs_UPDLB
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int         :12;       // 0-11
		volatile unsigned int AB      :1;        // 12
		volatile unsigned int BA      :1;        // 13
		volatile unsigned int         :18;       // 14-31
	} bit;
};

// uPP Í¨µÀ¿ØÖÆ¼Ä´æÆ÷
union uPPRegs_UPCTL
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int MODE    :2;        // 0-1
		volatile unsigned int CHN     :1;        // 2
		volatile unsigned int SDRTXIL :1;        // 3
		volatile unsigned int DDRDEMUX:1;        // 4
		volatile unsigned int         :11;       // 5-15
		volatile unsigned int DRA     :1;        // 16
		volatile unsigned int IWA     :1;        // 17
		volatile unsigned int DPWA    :3;        // 18-20
		volatile unsigned int DPFA    :2;        // 21-22
		volatile unsigned int         :1;        // 23
		volatile unsigned int DRB     :1;        // 24
		volatile unsigned int IWB     :1;        // 25
		volatile unsigned int DPWB    :3;        // 26-28
		volatile unsigned int DPFB    :2;        // 29-30
		volatile unsigned int         :1;        // 31
	} bit;
};

// uPP ½Ó¿ÚÅäÖÃ¼Ä´æÆ÷
union uPPRegs_UPICR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int MODE    :2;        // 0-1
		volatile unsigned int CHN     :1;        // 2
		volatile unsigned int SDRTXIL :1;        // 3
		volatile unsigned int DDRDEMUX:1;        // 4
		volatile unsigned int         :11;       // 5-15
		volatile unsigned int DRA     :1;        // 16
		volatile unsigned int IWA     :1;        // 17
		volatile unsigned int DPWA    :3;        // 18-20
		volatile unsigned int DPFA    :2;        // 21-22
		volatile unsigned int         :1;        // 23
		volatile unsigned int DRB     :1;        // 24
		volatile unsigned int IWB     :1;        // 25
		volatile unsigned int DPWB    :3;        // 26-28
		volatile unsigned int DPFB    :2;        // 29-30
		volatile unsigned int         :1;        // 31
	} bit;
};

// uPP Í¨µÀ¿ÕÏÐ×´Ì¬¼Ä´æÆ÷
union uPPRegs_UPIVR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int VALA    :12;       // 0-15
		volatile unsigned int VALB    :18;       // 16-31
	} bit;
};

// uPP ÃÅÏÞÅäÖÃ¼Ä´æÆ÷
union uPPRegs_UPTCR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int RDSIZEI :2;        // 0-1
		volatile unsigned int         :6;        // 2-7
		volatile unsigned int RDSIZEQ :2;        // 8-9
		volatile unsigned int         :6;        // 10-15
		volatile unsigned int TXSIZEA :2;        // 16-17
		volatile unsigned int         :6;        // 18-23
		volatile unsigned int TXSIZEB :2;        // 24-25
		volatile unsigned int         :6;        // 26-31
	} bit;
};

// uPP ÖÐ¶Ï×´Ì¬¼Ä´æÆ÷
union uPPRegs_UPISR
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int DPEI    :1;        // 0
		volatile unsigned int UORI    :1;        // 1
		volatile unsigned int ERRI    :1;        // 2
		volatile unsigned int EOWI    :1;        // 3
		volatile unsigned int EOLI    :1;        // 4
		volatile unsigned int         :3;        // 5-7
		volatile unsigned int DPEQ    :1;        // 8
		volatile unsigned int UORQ    :1;        // 9
		volatile unsigned int ERRQ    :1;        // 10
		volatile unsigned int EOWQ    :1;        // 11
		volatile unsigned int EOLQ    :1;        // 12
		volatile unsigned int         :19;       // 13-31
	} bit;
};

// uPP ÖÐ¶Ï×´Ì¬¼Ä´æÆ÷
union uPPRegs_UPIER
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int DPEI    :1;        // 0
		volatile unsigned int UORI    :1;        // 1
		volatile unsigned int ERRI    :1;        // 2
		volatile unsigned int EOWI    :1;        // 3
		volatile unsigned int EOLI    :1;        // 4
		volatile unsigned int         :3;        // 5-7
		volatile unsigned int DPEQ    :1;        // 8
		volatile unsigned int UORQ    :1;        // 9
		volatile unsigned int ERRQ    :1;        // 10
		volatile unsigned int EOWQ    :1;        // 11
		volatile unsigned int EOLQ    :1;        // 12
		volatile unsigned int         :19;       // 13-31
	} bit;
};

// uPP ÖÐ¶ÏÊ¹ÄÜÉèÖÃ¼Ä´æÆ÷
union uPPRegs_UPIES
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int DPEI    :1;        // 0
		volatile unsigned int UORI    :1;        // 1
		volatile unsigned int ERRI    :1;        // 2
		volatile unsigned int EOWI    :1;        // 3
		volatile unsigned int EOLI    :1;        // 4
		volatile unsigned int         :3;        // 5-7
		volatile unsigned int DPEQ    :1;        // 8
		volatile unsigned int UORQ    :1;        // 9
		volatile unsigned int ERRQ    :1;        // 10
		volatile unsigned int EOWQ    :1;        // 11
		volatile unsigned int EOLQ    :1;        // 12
		volatile unsigned int         :19;       // 13-31
	} bit;
};

// uPP ÖÐ¶ÏÇå³ý¼Ä´æÆ÷
union uPPRegs_UPIEC
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int DPEI    :1;        // 0
		volatile unsigned int UORI    :1;        // 1
		volatile unsigned int ERRI    :1;        // 2
		volatile unsigned int EOWI    :1;        // 3
		volatile unsigned int EOLI    :1;        // 4
		volatile unsigned int         :3;        // 5-7
		volatile unsigned int DPEQ    :1;        // 8
		volatile unsigned int UORQ    :1;        // 9
		volatile unsigned int ERRQ    :1;        // 10
		volatile unsigned int EOWQ    :1;        // 11
		volatile unsigned int EOLQ    :1;        // 12
		volatile unsigned int         :19;       // 13-31
	} bit;
};

// uPP DMA Í¨µÀ I ×´Ì¬ 2 ¼Ä´æÆ÷
union uPPRegs_UPIS2
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int ACT     :1;        // 0
		volatile unsigned int PEND    :1;        // 1
		volatile unsigned int         :2;        // 2-3
		volatile unsigned int WM      :4;        // 4-7
		volatile unsigned int         :24;       // 8-31
	} bit;
};

// uPP DMA Í¨µÀ Q ×´Ì¬ 2 ¼Ä´æÆ÷
union uPPRegs_UPQS2
{
	volatile unsigned int all;

	struct
	{
		volatile unsigned int ACT     :1;        // 0
		volatile unsigned int PEND    :1;        // 1
		volatile unsigned int         :2;        // 2-3
		volatile unsigned int WM      :4;        // 4-7
		volatile unsigned int         :24;       // 8-31
	} bit;
};

// uPP ¼Ä´æÆ÷×é
struct hw_uPPRegs
{
    volatile unsigned int 	UPPID;
    union uPPRegs_UPPCR 	UPPCR;
    union uPPRegs_UPDLB 	UPDLB;
    volatile unsigned char  RSVD0[4];
    union uPPRegs_UPCTL 	UPCTL;
    volatile unsigned int 	UPICR;
    union uPPRegs_UPIVR 	UPIVR;
    union uPPRegs_UPTCR 	UPTCR;
    union uPPRegs_UPISR 	UPISR;
    union uPPRegs_UPIER 	UPIER;
    union uPPRegs_UPIES 	UPIES;
    union uPPRegs_UPIEC 	UPIEC;
    volatile unsigned int 	UPEOI;
    volatile unsigned char  RSVD1[12];
    volatile unsigned int 	UPID0;
    volatile unsigned int 	UPID1;
    volatile unsigned int 	UPID2;
    volatile unsigned char  RSVD2[4];
    volatile unsigned int 	UPIS0;
    volatile unsigned int 	UPIS1;
    union uPPRegs_UPIS2 	UPIS2;
    volatile unsigned char  RSVD3[4];
    volatile unsigned int 	UPQD0;
    volatile unsigned int 	UPQD1;
    volatile unsigned int 	UPQD2;
    volatile unsigned char	RSVD4[4];
    volatile unsigned int	UPQS0;
    volatile unsigned int	UPQS1;
    union uPPRegs_UPQS2  	UPQS2;
};

//// uPP ÍâÉè´æ´¢¿Õ¼äÓ³Éä
//#pragma DATA_SECTION(uPPRegs,".Reg_uPP");
//volatile struct hw_uPPRegs uPPRegs;


#endif
