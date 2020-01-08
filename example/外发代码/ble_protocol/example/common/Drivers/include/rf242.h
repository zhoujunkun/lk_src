#ifndef __RF242_H__
#define __RF242_H__
#include "cmsdk_cm0.h"

/* RF242 Commands */
#define R_REG			0x00
#define W_REG 			0x20
#define R_RX_PLOAD 		0x61
#define W_TX_PLOAD		0xA0
#define FLUSH_TX		0xE1
#define FLUSH_RX		0xE2
#define REUSE_TX_PL		0xE3
#define R_RX_PL_WID		0x60
#define W_ACK_PLOAD		0xA8
#define W_TX_PLOAD_NOACK	0xB0
#define NOP				0xFF

/* RF242 Registers */
#define CFG_TOP 		0x00
#define MASK_RX_DR		0x40
#define MASK_TX_DS		0x20
#define MASK_MAX_RT		0x10
#define EN_CRC			0x08
#define CRC_2B			0x04
#define PWR_ON			0x02
#define RX_ON			0x01

/* Enable/Disable Auto ACK */
#define EN_AA			0x01
#define ENAA_P5			0x20
#define ENAA_P4			0x10
#define ENAA_P3			0x08
#define ENAA_P2			0x04
#define ENAA_P1			0x02
#define ENAA_P0			0x01

/* Enable/Disable RX pipe number */
#define EN_RX_ADDR		0x02
#define ENRX_P5			0x20
#define ENRX_P4			0x10
#define ENRX_P3			0x08
#define ENRX_P2			0x04
#define ENRX_P1			0x02
#define ENRX_P0			0x01

/* Address Width setup */
#define SETUP_AW		0x03

/* Retransmit count and delay setting */
#define SETUP_RETR		0x04
#define ARD_250us		0x00
#define ARD_500us		0x10
#define ARD_750us		0x20
#define ARD_1000us		0x30
#define ARD_1250us		0x40
#define ARD_1500us		0x50
#define ARD_1750us		0x60
#define ARD_2000us		0x70
#define ARD_2250us		0x80
#define ARD_2500us		0x90
#define ARD_2750us		0xA0
#define ARD_3000us		0xB0
#define ARD_3250us		0xC0
#define ARD_3500us		0xD0
#define ARD_3750us		0xE0
#define ARD_4000us		0xF0
#define ARC_0			0x00
#define ARC_1			0x01
#define ARC_2			0x02
#define ARC_3			0x03
#define ARC_4			0x04
#define ARC_5			0x05
#define ARC_6			0x06
#define ARC_7			0x07
#define ARC_8			0x08
#define ARC_9			0x09
#define ARC_10			0x0A
#define ARC_11			0x0B
#define ARC_12			0x0C
#define ARC_13			0x0D
#define ARC_14			0x0E
#define ARC_15			0x0F

/* Channel number is from 0 (2400) to 127 (2527) */
#define RF_CH			0x05

/* TX Power and Rate setting */
#define SETUP_RF		0x06
#define RATE_1M			0x00
#define RATE_2M			0x08
#define RATE_250K		0x20
#define PWR_LEVEL1		0x00
#define PWR_LEVEL2		0x02
#define PWR_LEVEL3		0x04
#define PWR_LEVEL4		0x06

/* Interrupt status */
#define STATUS			0x07
#define RX_DR			0x40
#define TX_DS			0x20
#define MAX_RT			0x10
#define RX_P_NO_5		0x0C
#define RX_P_NO_4		0x0A
#define RX_P_NO_3		0x08
#define RX_P_NO_2		0x06
#define RX_P_NO_1		0x04
#define RX_P_NO_0		0x02

/* AA Retransmition Setting */
#define OBSERVE_TX	0x08
/* Value from 0 to 15, clear by changing channel */
#define PLOS_CNT		0xF0
/* Value from 0 to 15, clear by sending packet successfully */
#define ARC_CNT			0x0F

/* RSSI indicator and Enable/Disable Setting */
#define RSSI			0x09
#define EN_RSSI			0x10
#define RSSI_2			0x02 // - 59dBm
#define RSSI_1			0x01 // - 69dBm

/* TX and RX Address setting */
#define RX_ADDR_P0		0x0A
#define RX_ADDR_P1		0x0B
#define RX_ADDR_P2		0x0C
#define RX_ADDR_P3		0x0D
#define RX_ADDR_P4		0x0E
#define RX_ADDR_P5		0x0F
#define TX_ADDR			0x10

/* RX width, vaule from 1 to 32 */
#define RX_PW_P0		0x11
#define RX_PW_P1		0x12
#define RX_PW_P2		0x13
#define RX_PW_P3		0x14
#define RX_PW_P4		0x15
#define RX_PW_P5		0x16

/* FIFO Status */
#define STATUS_FIFO	0x17
#define TX_REUSE		0x40
#define TX_FULL			0x20
#define TX_EMPTY		0x10
#define RX_FULL			0x02
#define RX_EMPTY		0x01

/* Enable/Disable Dynamic Paylod Per Pipe Setting */
#define DYNPD				0x1C
#define DPL_P5			0x20
#define DPL_P4			0x10
#define DPL_P3			0x08
#define DPL_P2			0x04
#define DPL_P1			0x02
#define DPL_P0			0x01

/* Enable/Disable Dynamic Payload , ACK Payload, Dynamic ACK function */
#define FEATURE			0x1D
#define EN_DPL			0x04
#define	EN_ACK_PAY	0x02
#define EN_DYN_ACK	0x01

#define BANK_SEL		0x1F

//========================    RF242 CSN, CE, IRQ setting ==============================

#define RF_SPI_INIT			 PB->DIR_b.DIR7=1;PB->DIR_b.DIR6=1;PB->DIR_b.DIR5=1;PB->DIR_b.DIR4=1;
#define RF_CS_HIGH       PB->SET_b.SET6=1	      //RF CS
#define RF_CS_LOW        PB->CLR_b.CLR6=1	      //RF CS

#define RF_CLK_HIGH     PB->SET_b.SET5=1	      //RF SCLK
#define RF_CLK_LOW      PB->CLR_b.CLR5=1	      //RF SCLK

#define RF_MISO        	 PB->PIN_b.PIN3            //RF MISO
#define RF_MOSI_HIGH       	 PB->SET_b.SET4=1             //RF MOSI
#define RF_MOSI_LOW       	 PB->CLR_b.CLR4=1             //RF MOSI

#define RF_CE_HIGH       PB->SET_b.SET7=1	      //RF CE
#define RF_CE_LOW        PB->CLR_b.CLR7=1	      //RF CE
#define IRQ_STATUS	     PA->PIN_b.PIN15				// IRQ : Low Active

#define SYS_Delay_10us() // waiting for 10us

#define TX_ADR_WIDTH    5   
#define RX_ADR_WIDTH    5 


//========================   USER DEFINE ==============================

extern void RF242_Init(void);

/* register and data read/write */
extern void RF242_Write_Reg(uint8_t reg,uint8_t value);
extern uint8_t RF242_Read_Reg(uint8_t reg);
extern void RF242_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t len);
extern void RF242_Read_Buf(uint8_t reg,uint8_t *pBuf,uint8_t len);

/* Interrupt function */
extern void RF242_ClearRX_DR(void);
extern void RF242_ClearTX_DS(void);
extern void RF242_ClearTX_DS(void);

/* TX/RX function */
void RF242_FlushTX(void);
void RF242_FlushRX(void);
extern uint8_t RF242_RxPacket(uint8_t *rxbuf);
extern void RF242_TxPacket(uint8_t *txbuf, uint8_t len);
void RF242_TxPacketWithoutAck(uint8_t *txbuf, uint8_t len);
void RF242_TxACKPacket(uint8_t *txbuf, uint8_t len);
uint8_t RF242_isTXComplete(void);

extern uint8_t RF242_CheckID(void);
extern void RF242_PowerOn(void);
extern void RF242_PowerOff(void);

/* Feature Settingg */
extern void RF242_Feature_DYN_ACK(uint8_t Dyn_ack);
extern void RF242_Feature_DPL(uint8_t Dpl);
extern void RF242_Feature_ACK_PAY(uint8_t Ack_pay);

/* RSSI Setting */
extern void RF242_EnableRSSI(void);
extern void RF242_DisableRSSI(void);

/* Mode selection */
extern void RF242_TX_Mode(void);
extern void RF242_RX_Mode(void);

extern void RF242_SetChannel(uint8_t channel);

extern uint8_t SPI_Byte_ReadWrite(uint8_t data);
#endif

