/******************************************************************************
 * ME30RF24 2.4G driver
 * Version 1.0 
 ******************************************************************************/
#include "RF24.h"
#include "ioconfig.h"
#include "sys.h"

void RF24_Init()
{	
		//intial SPI IO
		RF_SPI_INIT;
		//reset RF
		RF24_Reset();
		//initial register
		RF24_Write_Reg(0x02,0x4060);
		RF24_Write_Reg(0x03,0x5810);
		RF24_Write_Reg(0x05,0x7FA6);
		RF24_Write_Reg(0x0A,0x2053);
		RF24_Write_Reg(0x0B,0x887F);
		RF24_Write_Reg(0x0d,0x6003);
		RF24_Write_Reg(0x0F,0x661D);			//RX Control SINGLE BIT DEMODE
		RF24_Write_Reg(0x1a,0x00F7);

}

void RF24_Write_Reg(uint8_t reg,uint16_t value)
{
	RF_CS_LOW;	   
  	
	SPI_Byte_ReadWrite(W_REG&reg);
	SPI_Byte_ReadWrite(value>>8);
	SPI_Byte_ReadWrite(0xFF&value);
	
	RF_CS_HIGH;   
}

uint16_t RF24_Read_Reg(uint8_t reg)
{
 	uint16_t value;

	RF_CS_LOW;	    
  	
	SPI_Byte_ReadWrite(R_REG|reg);
	
	value = SPI_Byte_ReadWrite(NOP);
	value = (value<<8)|SPI_Byte_ReadWrite(NOP);
	RF_CS_HIGH; 

	return value;
}

uint8_t RF24_Read_Buf(uint8_t *pBuf)
{
	uint8_t i;
	uint8_t valid_length = 0;

	RF_CS_LOW;																
	SPI_Byte_ReadWrite(R_REG|RX_FIFO_REG);									 /*Write Fifo ADDRESS*/
	valid_length   = SPI_Byte_ReadWrite(0xFF);					 /*Read first length*/
	if(valid_length > 0x7F)
	{
		RF_CS_HIGH;
		return 0;
	}    
	for(i = 0; i < valid_length; i++)
		pBuf[i]=SPI_Byte_ReadWrite(NOP);
	RF_CS_HIGH; 
	return valid_length;	
}

void RF24_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t len)
{
	uint8_t i;
	uint16_t reg_value;

	reg_value = RF24_Read_Reg(SYN_TXRX_CTRL)&0x3FFF;
	RF24_Write_Reg(SYN_TXRX_CTRL,reg_value); //reset TX_EN andRX_EN, enter idle mode
	
	RF24_Write_Reg(TX_FIFO_RD_PTR,0x8000); //Reset Fifo Write Point
	
	RF_CS_LOW;
	
	SPI_Byte_ReadWrite(W_REG&TX_FIFO_REG);
	SPI_Byte_ReadWrite(len);
  for(i = 0; i < len; i++)
		SPI_Byte_ReadWrite(*pBuf++); 
	
	RF_CS_HIGH;	 

}

void RF24_Reset(void)
{
	RF_RST_LOW;
  SYS_DelaymS(1);
  RF_RST_HIGH;
  SYS_DelaymS(5);
	//delay 5ms to let RF stable
}

void RF24_StartRX(void)// reentrant
{
    uint16_t reg_value;

    reg_value = RF24_Read_Reg(SYN_TXRX_CTRL)&0x3FFF;
		RF24_Write_Reg(SYN_TXRX_CTRL,reg_value); //reset TX_EN andRX_EN, enter idle mode
		
    RF24_Write_Reg(RX_FIFO_RD_PTR,0x8080);             /*Reset fifo read pointer*/
		
    RF24_Write_Reg(SYN_TXRX_CTRL,reg_value|0x4000); //start RX mode
}

void RF24_StartTX(void)
{
    uint16_t reg_value;
	
    reg_value = RF24_Read_Reg(SYN_TXRX_CTRL)&0x3FFF;
		RF24_Write_Reg(SYN_TXRX_CTRL,reg_value); //reset TX_EN andRX_EN, enter idle mode
	
    RF24_Write_Reg(SYN_TXRX_CTRL,reg_value|0x8000);
}

void RF24_FlushRX(void)
{
	RF24_Write_Reg(RX_FIFO_RD_PTR,0x8080);             /*Reset fifo read pointer*/
}

void RF24_FlushTX(void)
{
	RF24_Write_Reg(TX_FIFO_RD_PTR,0x8080);             /*Reset fifo read pointer*/
}

uint8_t RF24_RxPacket(uint8_t *rxbuf)
{
	uint8_t ret = 0, len = 0;
	
	//Check and Receive Data
	if(IRQ_STATUS)
	{
		len = RF24_Read_Buf(rxbuf);
		ret = 1;
	}
	
	return ret;
}


void RF24_EnableAutoAck(void)
{
	  uint16_t reg_value;
    RF24_Write_Reg(TIMING_CON0,0x857F); //set resend times
    reg_value = RF24_Read_Reg(MIS_CON	);
		RF24_Write_Reg(MIS_CON,reg_value|0x08); /*Enable Chip Auto ACK function*/
}

void RF24_DisableAutoAck(void)
{
	  uint16_t reg_value;
    
    reg_value = RF24_Read_Reg(MIS_CON	);
		RF24_Write_Reg(MIS_CON,reg_value&0xFFF7);/*Enable Chip Auto ACK function*/
}

void RF24_RX_Mode(void)
{
    uint16_t reg_value;
    
    reg_value = RF24_Read_Reg(SYN_TXRX_CTRL);
		RF24_Write_Reg(SYN_TXRX_CTRL,reg_value&0x3FFF); //reset TX_EN andRX_EN, enter idle mode
    RF24_Write_Reg(SYN_TXRX_CTRL,reg_value|0x4000); //start RX mode
}

void RF24_TX_Mode(void)
{
    uint16_t reg_value;
    
    reg_value = RF24_Read_Reg(SYN_TXRX_CTRL);
		RF24_Write_Reg(SYN_TXRX_CTRL,reg_value&0x3FFF); //reset TX_EN andRX_EN, enter idle mode
    RF24_Write_Reg(SYN_TXRX_CTRL,reg_value|0x8000); //startTX mode
}

void RF24_SetChannel(uint8_t channel)
{
    uint16_t reg_value;
    if (channel>127) return;
    reg_value = RF24_Read_Reg(SYN_TXRX_CTRL);
    RF24_Write_Reg(SYN_TXRX_CTRL,(reg_value&0xFF80)|channel); //set channel
}

void RF24_SetupPA(uint8_t pa)
{
	RF24_Write_Reg(POWER_CTRL,pa&0x0F); //0:6dBM;0xF:-18dBM
}

uint8_t SPI_Byte_ReadWrite(uint8_t data)
{
	uint32_t indata=0,i,cmpdata=0x80;

	for (i=0;i<8;i++)
	{
		RF_CLK_HIGH;
		if (cmpdata&data)
			RF_MOSI_HIGH;
		else
			RF_MOSI_LOW;
		
		RF_CLK_LOW;
		indata=indata<<1;
		if (RF_MISO)
			indata|=1;
		cmpdata=cmpdata>>1;
	}
	return indata;
} 
// END SPI_Transfer

