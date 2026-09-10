/*
 * upp_Set.c
 *
 *  Created on: 2025年9月24日
 *      Author: 18832
 */
#include "upp_Set.h"
void OmaplFpgauPPSetup(void)
{
	// 外设使能
	PSCModuleControl(SOC_PSC_1_REGS, HW_PSC_UPP, PSC_POWERDOMAIN_ALWAYS_ON, PSC_MDCTL_NEXT_ENABLE);

	// 引脚复用配置
	uPPPinMuxSetup(uPP_CHA_8BIT_CHB_8BIT);

	// uPP复位
	uPPReset(SOC_UPP_0_REGS);

	// 数据格式配置
	uPPDataFmtConfig(SOC_UPP_0_REGS, uPP_CHA, uPP_DataPackingFmt_LJZE | uPP_DataPacking_FULL
							| uPP_InterfaceWidth_8BIT | uPP_DataRate_SINGLE);

	uPPDataFmtConfig(SOC_UPP_0_REGS, uPP_CHB, uPP_DataPackingFmt_LJZE | uPP_DataPacking_FULL
							| uPP_InterfaceWidth_8BIT | uPP_DataRate_SINGLE);

	// 通道配置
	uPPChannelConfig(SOC_UPP_0_REGS, uPP_DDRDEMUX_DISABLE | uPP_SDRTXIL_DISABLE | uPP_CHN_TWO
							| uPP_DUPLEX0);

	// 引脚配置
	uPPPinConfig(SOC_UPP_0_REGS, uPP_CHA, uPP_PIN_TRIS | uPP_PIN_ENABLE | uPP_PIN_WAIT | uPP_PIN_START);

	uPPPinConfig(SOC_UPP_0_REGS, uPP_CHB, uPP_PIN_ENABLE | uPP_PIN_WAIT | uPP_PIN_START);

	// 时钟配置
	// uPPCLK = (CPUCLK / 2) / (2 * (DIV + 1) (DIV = 0, 1, 2, 3 ... 15)
	// 456MHz 主频下支持的时钟 114MHz、57MHz、38MHz、28.5MHz、22.8MHz ......
	uPPClkConfig(SOC_UPP_0_REGS, uPP_CHB, 57000000, 228000000, uPP_PIN_PHASE_NORMAL);

	// 空闲输出配置
	uPPIdleValueConfig(SOC_UPP_0_REGS, uPP_CHB, 0xAAAA);

	// 中断使能
	uPPIntEnable(SOC_UPP_0_REGS, uPP_DMA_CHI, uPP_INT_EOW);
	uPPIntEnable(SOC_UPP_0_REGS, uPP_DMA_CHQ, uPP_INT_EOW);

	// 中断映射
	IntRegister(C674X_MASK_INT5, uPPIsr);
	IntEventMap(C674X_MASK_INT5, SYS_INT_UPP_INT);
	IntEnable(C674X_MASK_INT5);

	// uPP使能
	uPPEnable(SOC_UPP_0_REGS);
}
/**
 * 中断服务函数
 * */
void uPPIsr(void)
{
	unsigned int intr_dmai_status, intr_dmaq_status;

	// 取得 DMA 中断状态
	intr_dmai_status = uPPIntStatus(SOC_UPP_0_REGS, uPP_DMA_CHI);
	intr_dmaq_status = uPPIntStatus(SOC_UPP_0_REGS, uPP_DMA_CHQ);

	while(intr_dmai_status != 0 || intr_dmaq_status != 0)
	{
		if (intr_dmai_status & uPP_INT_EOL)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHI, uPP_INT_EOL);
		}

		if (intr_dmai_status & uPP_INT_EOW)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHI, uPP_INT_EOW);
			upp_interrupt_count++;
		}

		if (intr_dmai_status & uPP_INT_ERR)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHI, uPP_INT_ERR);
			upp_error_count++;
		}

		if (intr_dmai_status & uPP_INT_UOR)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHI, uPP_INT_UOR);
			upp_error_count++;
		}

		if (intr_dmai_status & uPP_INT_DPE)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHI, uPP_INT_DPE);
			upp_error_count++;
		}

		if (intr_dmaq_status & uPP_INT_EOL)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHQ, uPP_INT_EOL);
		}

		if (intr_dmaq_status & uPP_INT_EOW)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHQ, uPP_INT_EOW);
			upp_interrupt_count++;
		}

		if (intr_dmaq_status & uPP_INT_ERR)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHQ, uPP_INT_ERR);
			upp_error_count++;
		}

		if (intr_dmaq_status & uPP_INT_UOR)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHQ, uPP_INT_UOR);
			upp_error_count++;
		}

		if (intr_dmaq_status & uPP_INT_DPE)
		{
			uPPIntClear(SOC_UPP_0_REGS, uPP_DMA_CHQ, uPP_INT_DPE);
			upp_error_count++;
		}

		// uPP 中断将多个事件组合为同一中断源
		// 判断是否全部事情被处理完毕
		intr_dmai_status = uPPIntStatus(SOC_UPP_0_REGS, uPP_DMA_CHI);
		intr_dmaq_status = uPPIntStatus(SOC_UPP_0_REGS, uPP_DMA_CHQ);
	}

	// 通知 CPU uPP 中断处理完毕以便后续事件可以产生
	uPPEndOfInt(SOC_UPP_0_REGS);
}


