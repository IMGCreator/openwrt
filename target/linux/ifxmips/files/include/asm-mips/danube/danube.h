/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 *
 *   Copyright (C) 2005 infineon
 *   Copyright (C) 2007 John Crispin <blogic@openwrt.org> 
 *
 */
#ifndef _DANUBE_H__
#define _DANUBE_H__


/*------------ GENERAL */

#define BOARD_SYSTEM_TYPE		"DANUBE"

#define IOPORT_RESOURCE_START	0x10000000
#define IOPORT_RESOURCE_END		0xffffffff
#define IOMEM_RESOURCE_START	0x10000000
#define IOMEM_RESOURCE_END		0xffffffff


/*------------ ASC1 */

#define DANUBE_ASC1_BASE_ADDR	(KSEG1 + 0x1E100C00)

/* FIFO status register */
#define DANUBE_ASC1_FSTAT		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0048))
#define ASCFSTAT_TXFFLMASK		0x3F00
#define ASCFSTAT_TXFFLOFF		8

/* ASC1 transmit buffer */
#define DANUBE_ASC1_TBUF		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0020))

/* channel operating modes */
#define ASCOPT_CSIZE			0x3
#define ASCOPT_CS7				0x1
#define ASCOPT_CS8				0x2
#define ASCOPT_PARENB			0x4
#define ASCOPT_STOPB			0x8
#define ASCOPT_PARODD			0x0
#define ASCOPT_CREAD			0x20

/* hardware modified control register */
#define DANUBE_ASC1_WHBSTATE	((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0018))

/* receive buffer register */
#define DANUBE_ASC1_RBUF		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0024))

/* status register */
#define DANUBE_ASC1_STATE		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0014))

/* interrupt control */
#define DANUBE_ASC1_IRNCR		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x00F8))

#define ASC_IRNCR_TIR			0x4
#define ASC_IRNCR_RIR			0x2
#define ASC_IRNCR_EIR			0x4

/* clock control */
#define DANUBE_ASC1_CLC			((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0000))

#define DANUBE_ASC1_CLC_DISS	0x2

/* port input select register */
#define DANUBE_ASC1_PISEL		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0004))

/* tx fifo */
#define DANUBE_ASC1_TXFCON		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0044))

/* rx fifo */
#define DANUBE_ASC1_RXFCON		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0040))

/* control */
#define DANUBE_ASC1_CON			((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0010))

/* timer reload */
#define DANUBE_ASC1_BG			((u32*)(DANUBE_ASC1_BASE_ADDR + 0x0050))

/* int enable */
#define DANUBE_ASC1_IRNREN		((u32*)(DANUBE_ASC1_BASE_ADDR + 0x00F4))

#define ASC_IRNREN_RX_BUF		0x8
#define ASC_IRNREN_TX_BUF		0x4
#define ASC_IRNREN_ERR			0x2
#define ASC_IRNREN_TX			0x1


/*------------ RCU */

#define DANUBE_RCU_BASE_ADDR	0xBF203000

/* reset request */
#define DANUBE_RCU_REQ			((u32*)(DANUBE_RCU_BASE_ADDR + 0x0010))
#define DANUBE_RST_ALL			0x40000000


/*------------ MCD */

#define DANUBE_MCD_BASE_ADDR	(KSEG1 + 0x1F106000)

/* chip id */
#define DANUBE_MCD_CHIPID		((u32*)(DANUBE_MCD_BASE_ADDR + 0x0028))


/*------------ GPTU */

#define DANUBE_GPTU_BASE_ADDR	0xB8000300

/* clock control register */
#define DANUBE_GPTU_GPT_CLC		((u32*)(DANUBE_GPTU_BASE_ADDR + 0x0000))

/* captur reload register */
#define DANUBE_GPTU_GPT_CAPREL	((u32*)(DANUBE_GPTU_BASE_ADDR + 0x0030))

/* timer 6 control register */
#define DANUBE_GPTU_GPT_T6CON	((u32*)(DANUBE_GPTU_BASE_ADDR + 0x0020))


/*------------ EBU */

#define DANUBE_EBU_BASE_ADDR	0xBE105300

/* bus configuration register */
#define DANUBE_EBU_BUSCON0		((u32*)(DANUBE_EBU_BASE_ADDR + 0x0060))
#define DANUBE_EBU_PCC_CON		((u32*)(DANUBE_EBU_BASE_ADDR + 0x0090))
#define DANUBE_EBU_PCC_IEN		((u32*)(DANUBE_EBU_BASE_ADDR + 0x00A4))
#define DANUBE_EBU_PCC_ISTAT	((u32*)(DANUBE_EBU_BASE_ADDR + 0x00A0))


/*------------ CGU */

#define DANUBE_CGU_BASE_ADDR	0xBF103000

/* clock mux */
#define DANUBE_CGU_SYS			((u32*)(DANUBE_CGU_BASE_ADDR + 0x0010))
#define DANUBE_CGU_IFCCR		((u32*)(DANUBE_CGU_BASE_ADDR + 0x0018))
#define DANUBE_CGU_PCICR		((u32*)(DANUBE_CGU_BASE_ADDR + 0x0034))

#define CLOCK_60M				60000000
#define CLOCK_83M				83333333
#define CLOCK_111M				111111111
#define CLOCK_133M				133333333
#define CLOCK_167M				166666667
#define CLOCK_333M				333333333


/*------------ CGU */

#define DANUBE_PMU_BASE_ADDR	(KSEG1 + 0x1F102000)

#define DANUBE_PMU_PWDCR		((u32*)(DANUBE_PMU_BASE_ADDR + 0x001C))
#define DANUBE_PMU_PWDSR		((u32*)(DANUBE_PMU_BASE_ADDR + 0x0020))


/*------------ ICU */

#define DANUBE_ICU_BASE_ADDR	0xBF880200


#define DANUBE_ICU_IM0_ISR		((u32*)(DANUBE_ICU_BASE_ADDR + 0x0000))
#define DANUBE_ICU_IM0_IER		((u32*)(DANUBE_ICU_BASE_ADDR + 0x0008))
#define DANUBE_ICU_IM0_IOSR		((u32*)(DANUBE_ICU_BASE_ADDR + 0x0010))
#define DANUBE_ICU_IM0_IRSR		((u32*)(DANUBE_ICU_BASE_ADDR + 0x0018))
#define DANUBE_ICU_IM0_IMR		((u32*)(DANUBE_ICU_BASE_ADDR + 0x0020))

#define DANUBE_ICU_IM1_ISR		((u32*)(DANUBE_ICU_BASE_ADDR + 0x0028))

#define DANUBE_ICU_OFFSET		(DANUBE_ICU_IM1_ISR - DANUBE_ICU_IM0_ISR)


/*------------ ETOP */

#define DANUBE_PPE32_BASE_ADDR	0xBE180000

#define ETHERNET_PACKET_DMA_BUFFER_SIZE		0x600

#define DANUBE_PPE32_MEM_MAP	(DANUBE_PPE32_BASE_ADDR + 0x10000 )

#define MII_MODE 1

#define REV_MII_MODE 2

/* mdio access */
#define DANUBE_PPE32_MDIO_ACC	((u32*)(DANUBE_PPE32_MEM_MAP + 0x1804))

#define MDIO_ACC_REQUEST		0x80000000
#define MDIO_ACC_READ			0x40000000
#define MDIO_ACC_ADDR_MASK		0x1f
#define MDIO_ACC_ADDR_OFFSET	0x15
#define MDIO_ACC_REG_MASK		0xff
#define MDIO_ACC_REG_OFFSET		0x10
#define MDIO_ACC_VAL_MASK		0xffff

/* configuration */
#define DANUBE_PPE32_CFG		((u32*)(DANUBE_PPE32_MEM_MAP + 0x1808))

#define PPE32_MII_MASK			0xfffffffc
#define PPE32_MII_NORMAL		0x8
#define PPE32_MII_REVERSE		0xe

/* packet length */
#define DANUBE_PPE32_IG_PLEN_CTRL	((u32*)(DANUBE_PPE32_MEM_MAP + 0x1820))

#define PPE32_PLEN_OVER			0x5ee
#define PPE32_PLEN_UNDER		0x400000

/* enet */
#define DANUBE_PPE32_ENET_MAC_CFG	((u32*)(DANUBE_PPE32_MEM_MAP + 0x1840))

#define PPE32_CGEN				0x800


/*------------ DMA */
#define DANUBE_DMA_BASE_ADDR	0xBE104100

#define DANUBE_DMA_CS			((u32*)(DANUBE_DMA_BASE_ADDR + 0x18))
#define DANUBE_DMA_CIE			((u32*)(DANUBE_DMA_BASE_ADDR + 0x2C))
#define DANUBE_DMA_IRNEN		((u32*)(DANUBE_DMA_BASE_ADDR + 0xf4))
#define DANUBE_DMA_CCTRL		((u32*)(DANUBE_DMA_BASE_ADDR + 0x1C))
#define DANUBE_DMA_CIS			((u32*)(DANUBE_DMA_BASE_ADDR + 0x28))
#define DANUBE_DMA_CDLEN		((u32*)(DANUBE_DMA_BASE_ADDR + 0x24))
#define DANUBE_DMA_PS			((u32*)(DANUBE_DMA_BASE_ADDR + 0x40))
#define DANUBE_DMA_PCTRL		((u32*)(DANUBE_DMA_BASE_ADDR + 0x44))
#define DANUBE_DMA_CTRL			((u32*)(DANUBE_DMA_BASE_ADDR + 0x10))
#define DANUBE_DMA_CPOLL		((u32*)(DANUBE_DMA_BASE_ADDR + 0x14))
#define DANUBE_DMA_CDBA			((u32*)(DANUBE_DMA_BASE_ADDR + 0x20))


/*------------ PCI */
#define PCI_CR_PR_BASE_ADDR		(KSEG1 + 0x1E105400)

#define PCI_CR_FCI_ADDR_MAP0	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00C0))
#define PCI_CR_FCI_ADDR_MAP1	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00C4))
#define PCI_CR_FCI_ADDR_MAP2	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00C8))
#define PCI_CR_FCI_ADDR_MAP3	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00CC))
#define PCI_CR_FCI_ADDR_MAP4	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00D0))
#define PCI_CR_FCI_ADDR_MAP5	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00D4))
#define PCI_CR_FCI_ADDR_MAP6	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00D8))
#define PCI_CR_FCI_ADDR_MAP7	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00DC))
#define PCI_CR_CLK_CTRL			((u32*)(PCI_CR_PR_BASE_ADDR + 0x0000))
#define PCI_CR_PCI_MOD			((u32*)(PCI_CR_PR_BASE_ADDR + 0x0030))
#define PCI_CR_PC_ARB			((u32*)(PCI_CR_PR_BASE_ADDR + 0x0080))
#define PCI_CR_FCI_ADDR_MAP11hg	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00E4))
#define PCI_CR_BAR11MASK		((u32*)(PCI_CR_PR_BASE_ADDR + 0x0044))
#define PCI_CR_BAR12MASK		((u32*)(PCI_CR_PR_BASE_ADDR + 0x0048))
#define PCI_CR_BAR13MASK		((u32*)(PCI_CR_PR_BASE_ADDR + 0x004C))
#define PCI_CS_BASE_ADDR1		((u32*)(PCI_CS_PR_BASE_ADDR + 0x0010))
#define PCI_CR_PCI_ADDR_MAP11	((u32*)(PCI_CR_PR_BASE_ADDR + 0x0064))
#define PCI_CR_FCI_BURST_LENGTH	((u32*)(PCI_CR_PR_BASE_ADDR + 0x00E8))
#define PCI_CR_PCI_EOI			((u32*)(PCI_CR_PR_BASE_ADDR + 0x002C))

#define PCI_CS_PR_BASE_ADDR		(KSEG1 + 0x17000000)

#define PCI_CS_STS_CMD			((u32*)(PCI_CS_PR_BASE_ADDR + 0x0004))

#define PCI_MASTER0_REQ_MASK_2BITS	8
#define PCI_MASTER1_REQ_MASK_2BITS	10
#define PCI_MASTER2_REQ_MASK_2BITS	12
#define INTERNAL_ARB_ENABLE_BIT		0


/*------------ WDT */

#define DANUBE_WDT_BASE_ADDR	(KSEG1 + 0x1F880000)

#define DANUBE_BIU_WDT_CR		((u32*)(DANUBE_WDT_BASE_ADDR + 0x03F0))
#define DANUBE_BIU_WDT_SR		((u32*)(DANUBE_WDT_BASE_ADDR + 0x03F8))

#define DANUBE_BIU_WDT_CR_GEN				(1 << 31)
#define DANUBE_BIU_WDT_CR_DSEN				(1 << 30)
#define DANUBE_BIU_WDT_CR_LPEN				(1 << 29)

#define DANUBE_BIU_WDT_CR_CLKDIV_GET(value) (((value) >> 24) & ((1 << 2) - 1))
#define DANUBE_BIU_WDT_CR_PWL_GET(value)	(((value) >> 26) & ((1 << 2) - 1))
#define DANUBE_BIU_WDT_CR_PWL_SET(value)	((((1 << 2) - 1) & (value)) << 26)
#define DANUBE_BIU_WDT_CR_PW_SET(value)		(((( 1 << 8) - 1) & (value)) << 16)
#define DANUBE_BIU_WDT_CR_CLKDIV_SET(value)	(((( 1 << 2) - 1) & (value)) << 24)
#define DANUBE_BIU_WDT_CR_RELOAD_SET(value)	(((( 1 << 16) - 1) & (value)) << 0)


/*------------ LED */

#define DANUBE_LED_BASE_ADDR	(KSEG1 + 0x1E100BB0)
#define DANUBE_LED_CON0			((u32*)(DANUBE_LED_BASE_ADDR + 0x0000))
#define DANUBE_LED_CON1			((u32*)(DANUBE_LED_BASE_ADDR + 0x0004))
#define DANUBE_LED_CPU0			((u32*)(DANUBE_LED_BASE_ADDR + 0x0008))
#define DANUBE_LED_CPU1			((u32*)(DANUBE_LED_BASE_ADDR + 0x000C))
#define DANUBE_LED_AR			((u32*)(DANUBE_LED_BASE_ADDR + 0x0010))

#define LED_CON0_SWU			(1 << 31)
#define LED_CON0_AD1			(1 << 25)
#define LED_CON0_AD0			(1 << 24)

#define DANUBE_LED_2HZ          (0)
#define DANUBE_LED_4HZ          (1 << 23)
#define DANUBE_LED_8HZ          (2 << 23)
#define DANUBE_LED_10HZ         (3 << 23)
#define DANUBE_LED_MASK         (0xf << 23)

#define DANUBE_LED_UPD_SRC_FPI  (1 << 31)
#define DANUBE_LED_UPD_MASK     (3 << 30)
#define DANUBE_LED_ADSL_SRC		(3 << 24)

#define DANUBE_LED_GROUP0		(1 << 0)
#define DANUBE_LED_GROUP1		(1 << 1)
#define DANUBE_LED_GROUP2		(1 << 2)

#define DANUBE_LED_RISING		0
#define DANUBE_LED_FALLING		(1 << 26)
#define DANUBE_LED_EDGE_MASK	(1 << 26)


/*------------ GPIO */

#define DANUBE_GPIO_BASE_ADDR	(0xBE100B00)

#define DANUBE_GPIO_P0_OUT		((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0010))
#define DANUBE_GPIO_P1_OUT		((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0040))
#define DANUBE_GPIO_P0_IN		((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0014))
#define DANUBE_GPIO_P1_IN		((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0044))
#define DANUBE_GPIO_P0_DIR		((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0018))
#define DANUBE_GPIO_P1_DIR		((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0048))
#define DANUBE_GPIO_P0_ALTSEL0	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x001C))
#define DANUBE_GPIO_P1_ALTSEL0	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x004C))
#define DANUBE_GPIO_P0_ALTSEL1	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0020))
#define DANUBE_GPIO_P1_ALTSEL1	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0050))
#define DANUBE_GPIO_P0_OD		((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0024))
#define DANUBE_GPIO_P1_OD		((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0054))
#define DANUBE_GPIO_P0_STOFF	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0028))
#define DANUBE_GPIO_P1_STOFF	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0058))
#define DANUBE_GPIO_P0_PUDSEL	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x002C))
#define DANUBE_GPIO_P1_PUDSEL	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x005C))
#define DANUBE_GPIO_P0_PUDEN	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0030))
#define DANUBE_GPIO_P1_PUDEN	((u32*)(DANUBE_GPIO_BASE_ADDR + 0x0060))


/*------------ SSC */

#define DANUBE_SSC1_BASE_ADDR	(KSEG1 + 0x1e100800)






#endif
