#ifndef __RF24_H__
#define __RF24_H__
#include "cmsdk_cm0.h"

/* RF24 Commands */
#define R_REG			0x80
#define W_REG 			0x7F
#define NOP				0xFF

/* RF24 Registers */
#define SYN_TXRX_CTRL		0x00 
#define MIS_CON				 	0x01
#define POWER_CTRL		 	0x02
#define OP_CON0					0x03
//-		0x06~0x04
#define OP_CON1					0x07
//-		0x0A~0x08
#define TIMING_CON0			0x0B
#define TIMING_CON1		 	0x0C
//-		0x10~0x0D
#define RSSI_VAL				0x11
#define BLK_STATUS			0x12
//-		0x15~0x13
#define MAIN_STATUS			0x16
//-		0x1B~0x17
#define AMS_TEST_CTRL		0x1C
//-		0x1D
#define OP_CTRL				 	0x1E
#define SYN_WORD_1		 	0x1F
#define SYN_WORD_2			0x20
#define SYN_WORD_3			0x21
#define SYN_WORD_4			0x22
//-	R/W 	0x23
#define FIFO_THR			 	0x24
#define RX_FIFO_RD_PTR		 	0x25
#define TX_FIFO_RD_PTR			0x26
#define TX_FIFO_REG			0x27
#define RX_FIFO_REG			0x28
//-	R/W	0x29



//========================    RF24 SPI,CS, RST, IRQ setting ==============================
#define RF_SPI_INIT			 	PA->DIR_b.DIR15=1;PB->DIR_b.DIR6=1;PB->DIR_b.DIR5=1;PB->DIR_b.DIR3=1;
#define RF_CS_HIGH       	PB->SET_b.SET6=1	      //RF CS
#define RF_CS_LOW        	PB->CLR_b.CLR6=1	      //RF CS
#define RF_CLK_HIGH     	PB->SET_b.SET5=1	      //RF SCLK
#define RF_CLK_LOW      	PB->CLR_b.CLR5=1	      //RF SCLK
#define RF_MISO        	 	PB->PIN_b.PIN4            //RF MISO
#define RF_MOSI_HIGH      PB->SET_b.SET3=1             //RF MOSI
#define RF_MOSI_LOW       PB->CLR_b.CLR3=1             //RF MOSI

#define RF_RST_HIGH       PA->SET_b.SET15=1	      //RF RST
#define RF_RST_LOW        PA->CLR_b.CLR15=1	      //RF RST
#define IRQ_STATUS	     	PB->PIN_b.PIN7				// IRQ : Low Active

//========================  Driver  ==============================

void RF24_Init(void);
void RF24_Write_Reg(uint8_t reg,uint16_t value);
uint16_t RF24_Read_Reg(uint8_t reg);
uint8_t RF24_Read_Buf(uint8_t *pBuf);
void RF24_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t len);
void RF24_Reset(void);
void RF24_StartRX(void);
void RF24_StartTX(void);
void RF24_FlushRX(void);
void RF24_FlushTX(void);
void RF24_EnableAutoAck(void);
void RF24_DisableAutoAck(void);
void RF24_RX_Mode(void);
void RF24_TX_Mode(void);
void RF24_SetChannel(uint8_t channel);
void RF24_SetupPA(uint8_t pa);
uint8_t SPI_Byte_ReadWrite(uint8_t data);
#endif
