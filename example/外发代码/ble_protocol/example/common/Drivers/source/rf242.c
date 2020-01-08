/******************************************************************************
 * ME30RF242 2.4G driver
 * Version 1.0 
 ******************************************************************************/
#include "cmsdk_cm0.h"
#include "rf242.h"
#include "ioconfig.h"
#include "sys.h"
/* default TX/RX Address and Address Width */
const uint8_t TX_ADDRESS[TX_ADR_WIDTH]={0x67,0xE7,0xE7,0xE7,0xE7}; 
const uint8_t RX_ADDRESS[RX_ADR_WIDTH]={0x67,0xE7,0xE7,0xE7,0xE7}; 

#define simplified 0

/* memo */
uint8_t DYN_ACKOn = 0;
uint8_t ACK_PAYOn = 0;

#if simplified 
uint8_t Initial_Reg_Array[] = {
0x1F, 0x01, 0x00,
0x1B, 0x04, 0x10, 0xE1, 0xD3, 0x3D,
0x19, 0x04, 0x06, 0xAA, 0xA2, 0xDB,
0x1A, 0x04, 0x27, 0x61, 0x01, 0xF8,
0x1F, 0x01, 0x01,
0x18, 0x04, 0xBF, 0x94, 0x00, 0xDF,
0x19, 0x04, 0xBB, 0x48, 0x9A, 0xE8,
0x1B, 0x04, 0x76, 0x87, 0xCA, 0x01,
0x1F, 0x01, 0x02,
0x1B, 0x04, 0xA0, 0x00, 0x18, 0xA0,
0x1F, 0x01, 0x04,
0x18, 0x04, 0x01, 0x00, 0xF0, 0x00,
0x1F, 0x01, 0x05,
0x18, 0x04, 0x84, 0x03, 0x2A, 0x03,
0x19, 0x04, 0x90, 0xBF, 0x00, 0x00,
0x1A, 0x04, 0xA0, 0x0F, 0x00, 0x00,
0x1f, 0x01, 0x08,
0x19, 0x01, 0x10,
0x18, 0x04, 0x00, 0x00, 0x00, 0x00,
0x19, 0x01, 0x1e,
0x19, 0x01, 0x3e,
0x19, 0x01, 0x5e,
0x19, 0x01, 0x7e,
0x19, 0x01, 0x1f,
0x19, 0x01, 0x3f,
0x19, 0x01, 0x5f,
0x19, 0x01, 0x7f,
0x19, 0x01, 0x00,
0x1F, 0x01, 0x09,
0x18 ,0x04 ,0x00 ,0x00 ,0xFE ,0xFE,
0x19, 0x04, 0x98, 0x00, 0x03, 0x00,
0x1F, 0x01, 0x00
};
#else
uint8_t Initial_Reg_Array[] = {
0x1F, 0x01, 0x00,
0x1B, 0x04, 0x10, 0xE1, 0xD3, 0x3D,
0x19, 0x04, 0x06, 0xAA, 0xA2, 0xDB,
0x1A, 0x04, 0x27, 0x61, 0x01, 0xF8,
0x1F, 0x01, 0x01,
0x18, 0x04, 0xBF, 0x94, 0x00, 0xDF,
0x19, 0x04, 0xBB, 0x48, 0x9A, 0xE8,
0x1B, 0x04, 0x76, 0x87, 0xCA, 0x01,
0x1F, 0x01, 0x02,
0x1B, 0x04, 0xA0, 0x00, 0x18, 0xA0,
0x1F, 0x01, 0x04,
0x18, 0x04, 0x01, 0x00, 0xF0, 0x00,
0x1F, 0x01, 0x05,
0x18, 0x04, 0x84, 0x03, 0x2A, 0x03,
0x19, 0x04, 0x90, 0xBF, 0x00, 0x00,
0x1A, 0x04, 0xA0, 0x0F, 0x00, 0x00,
0x1F ,0x01 ,0x08,
0x19 ,0x01 ,0x10,
0x18 ,0x04 ,0x07 ,0x02 ,0x04 ,0x00,
0x19 ,0x01 ,0xD8,
0x19 ,0x01 ,0xF8,
0x18 ,0x04 ,0xD1 ,0x01 ,0xF8 ,0x03,
0x19 ,0x01 ,0x9E,
0x19 ,0x01 ,0xBE,
0x18 ,0x04 ,0x00 ,0x0A ,0x08 ,0x00,
0x19 ,0x01 ,0xDE,
0x19 ,0x01 ,0xFE,
0x18 ,0x04 ,0xCE ,0xC1 ,0xFF ,0x03,
0x19 ,0x01 ,0x9F,
0x19 ,0x01 ,0xbF,
0x18 ,0x04 ,0x00 ,0x08 ,0x08 ,0x00,
0x19 ,0x01 ,0xDF,
0x19 ,0x01 ,0xFF,
0x18 ,0x04 ,0x1D ,0xEE ,0xEF ,0x00,
0x19 ,0x01 ,0x1E,
0x19 ,0x01 ,0x3E,
0x18 ,0x04 ,0x07 ,0x5B ,0x30 ,0x0A,
0x19 ,0x01 ,0x5E,
0x19 ,0x01 ,0x7E,
0x18 ,0x04 ,0x66 ,0xCC ,0xFC ,0x00,
0x19 ,0x01 ,0x1F,
0x19 ,0x01 ,0x3F,
0x18 ,0x04 ,0x01 ,0x0B ,0x50 ,0x0C,
0x19 ,0x01 ,0x5F,
0x19 ,0x01 ,0x7F,
0x19 ,0x01 ,0x25,
0x1F ,0x01 ,0x09,
0x18 ,0x04 ,0x00 ,0x00 ,0xFE ,0xFE,
0x19 ,0x04 ,0x98 ,0x00 ,0x03 ,0x00,
0x1F ,0x01 ,0x00
};
#endif

void RF242_Init()
{
	/* Initial Register */
		uint32_t i = 0, j = 0, k = 0;
		uint8_t data[4];		
		uint32_t array_length = sizeof(Initial_Reg_Array);
	
		RF_SPI_INIT;
		RF_CE_LOW;
		RF_CS_HIGH;
		RF_CLK_LOW;
		RF_MOSI_LOW;
		
		RF242_PowerOff();
		
		while(i < array_length)
		{
			if(Initial_Reg_Array[i+1] == 0x01)
			{
				RF242_Write_Reg( W_REG | Initial_Reg_Array[i], Initial_Reg_Array[i+2]);
				i += 3;
			}
			else
			{ k=Initial_Reg_Array[i+1];
				for(j = 0; j < k; j++)
				{
					data[j] = Initial_Reg_Array[i+2+j];
				}

				RF242_Write_Buf( W_REG | Initial_Reg_Array[i], data, Initial_Reg_Array[i + 1]);
				i += 2+k;
			}
		}
	
	RF242_Write_Reg(W_REG | CFG_TOP, EN_CRC | CRC_2B);
	RF242_Write_Reg(W_REG | EN_AA,0x00);    
  RF242_Write_Reg(W_REG | EN_RX_ADDR,0x00);
  RF242_Write_Reg(W_REG | RF_CH,77);	
	RF242_Write_Reg(W_REG | RX_PW_P0,1);
		
	RF242_Write_Reg(W_REG | SETUP_RF, RATE_1M | PWR_LEVEL4); // set RF as 1Mbps and Max TX power

}

uint8_t RF242_CheckID(void)
{
	uint8_t ret = 0;
	uint8_t data[4];
	
	/* When power off, Chip ID can be read */
	RF242_PowerOff();
	/* When RSSI disable, Chip ID can be read */
	RF242_DisableRSSI();
//	while(1)
//	{
	RF242_Read_Buf(0x18, data, 4); 
//	}
	if(data[0] == 0x41 && data[1] == 0x72)
		ret = 1;

	return ret;
}

void RF242_Write_Reg(uint8_t reg,uint8_t value)
{
	RF_CS_LOW;	   
  	
	SPI_Byte_ReadWrite(reg);
	SPI_Byte_ReadWrite(value);
	
	RF_CS_HIGH;   
}

uint8_t RF242_Read_Reg(uint8_t reg)
{
 	uint8_t value;

	RF_CS_LOW;	    
  	
	SPI_Byte_ReadWrite(reg);
	
	value = SPI_Byte_ReadWrite(NOP);
	
	RF_CS_HIGH; 

	return value;
}

void RF242_Read_Buf(uint8_t reg,uint8_t *pBuf,uint8_t len)
{
	uint8_t i;
	
	RF_CS_LOW;      
  	
	SPI_Byte_ReadWrite(reg);  	   
 	
	for(i = 0; i < len; i++)
		pBuf[i]=SPI_Byte_ReadWrite(NOP);
	
	RF_CS_HIGH; 
}

void RF242_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t len)
{
	uint8_t i;
	
	RF_CS_LOW;
	
	SPI_Byte_ReadWrite(reg);
	
  for(i = 0; i < len; i++)
		SPI_Byte_ReadWrite(*pBuf++); 
	
	RF_CS_HIGH;	 
}

uint8_t RF242_isRXReady(void)
{
	uint8_t ret = 0, state;
	
	state = RF242_Read_Reg(STATUS);  
	if(state & RX_DR)
		ret = 1;
	
	return ret;
}

uint8_t RF242_isTXFULL(void)
{
	uint8_t ret = 0, state;
		
	state = RF242_Read_Reg(STATUS_FIFO);
	if(state & TX_FULL)
		ret = 1;
	return ret;
}

uint8_t RF242_isRXEMPTY(void)
{
	uint8_t ret = 0, state;
	
	state = RF242_Read_Reg(STATUS_FIFO);
	if(state & RX_EMPTY)
		ret = 1;
	return ret;	
}

void RF242_ClearRX_DR(void)
{
	uint8_t state;
		
	state = RF242_Read_Reg(STATUS);
	state |= RX_DR;
	RF242_Write_Reg(W_REG | STATUS, state);
}

void RF242_ClearTX_DS(void)
{
	uint8_t state;
	
	state = RF242_Read_Reg(STATUS); 
	state |= TX_DS;	
	RF242_Write_Reg(W_REG | STATUS, state); 
	
}

void RF242_ClearMAX_RT(void)
{
	uint8_t state;
	
	state = RF242_Read_Reg(STATUS); 
	state |= MAX_RT;	
	RF242_Write_Reg(W_REG | STATUS, state);
}

void RF242_FlushRX(void)
{
	RF242_Write_Reg(FLUSH_RX, NOP);
}

void RF242_FlushTX(void)
{
	RF242_Write_Reg(FLUSH_TX, NOP);
}

uint8_t RF242_RxPacket(uint8_t *rxbuf)
{
	uint8_t ret = 0, len = 0;
	
	//Check and Receive Data
	if(RF242_isRXReady())
	{
		len = RF242_Read_Reg(R_RX_PL_WID);
		if(len==0)
			RF242_FlushRX();
		else
			RF242_Read_Buf(R_RX_PLOAD, rxbuf, len); 
	
		//Clear RX_DR status
		RF242_ClearRX_DR();
		
		ret = 1;
	}
	
	return ret;
}

void RF242_TxPacket(uint8_t *txbuf, uint8_t len)
{ 
	//Check Queue is full or not and Send packet
	if(!RF242_isTXFULL())
	{	
		if(!DYN_ACKOn)
			RF242_Write_Buf(W_TX_PLOAD, txbuf, len);
		else
			RF242_Write_Buf(W_TX_PLOAD_NOACK, txbuf, len);
		
		RF_CE_HIGH;
    //CE High till TX_DS=1 or IRQ=0	
	}
}

//Notice, RF242_TxACKPacket() is used only at PRX mode with EN_AA=1
//this function sholud be used before RX recevied Packet
//to let ACK packet be prepared 
void RF242_TxACKPacket(uint8_t *txbuf, uint8_t len)
{ 
	//Check Queue is full or not and Send packet
	if(!RF242_isTXFULL())
	{	
		RF242_Write_Buf(W_ACK_PLOAD, txbuf, len);
	}
}

//Notice, RF242_TxPacketWithoutAck() is only can ve used under EN_AA=1
//Only for Auto-ACK mode condition
void RF242_TxPacketWithoutAck(uint8_t *txbuf, uint8_t len)
{ 
	//Check Queue is full or not and Send packet
	if(!RF242_isTXFULL())
	{
  	
		if(DYN_ACKOn)
			RF242_Write_Buf(W_TX_PLOAD, txbuf, len);
		else
			RF242_Write_Buf(W_TX_PLOAD_NOACK, txbuf, len);
 	
	  RF_CE_HIGH;
    //CE High till TX_DS=1 or IRQ=0			
	}
}	
uint8_t RF242_isTXComplete(void)
{
	if (RF242_Read_Reg(STATUS)&TX_DS)
		return 1;
	else
		return 0;
}
void RF242_RX_Mode(void)
{
	  	     
  uint8_t value;
	
	value = RF242_Read_Reg(CFG_TOP); 
	value |= RX_ON;	
	RF242_Write_Reg(W_REG | CFG_TOP, value); 	
	RF_CE_HIGH;
}

void RF242_TX_Mode(void)
{
	uint8_t value;
	
	value = RF242_Read_Reg(CFG_TOP); 
	value &= ~RX_ON;
	RF242_Write_Reg(W_REG | CFG_TOP, value); 
	
}

void RF242_PowerOn(void)
{
	uint8_t value;
	uint8_t data[4];

	//restore RF internal LDO output voltage to no	normal value
	//Notice:
	//this restore step is only if user had refine the internal LDO to lower value when Power Off 
	//otherwise user can skip this restore step
	data[0] = 0x06;
	data[1] = 0xAA;
	data[2] = 0xA2;
	data[3] = 0xDB;
	RF242_Write_Buf( W_REG | 0x19, data, 4);
	//after resotre RF internal LDO output, please add 100us delay after LDO output stable
	SYS_DelayuS(200);
	
	value = RF242_Read_Reg(CFG_TOP); 
	value |= PWR_ON;	
	RF242_Write_Reg(W_REG | CFG_TOP, value); 
	

}

void RF242_PowerOff(void)
{
	uint8_t value;
	uint8_t data[4];
	
	value = RF242_Read_Reg(CFG_TOP); 
	value &= ~PWR_ON;
	RF242_Write_Reg(W_REG | CFG_TOP, value); 	
	
	//refine RF internal LDO output voltage to lower value
	//Notice:
	//this refine step is only required for power saving purposed otherwise user can skip this refine step
	data[0] = 0x06;
	data[1] = 0xAA;
	data[2] = 0x02;
	data[3] = 0x00;
	RF242_Write_Buf( W_REG | 0x19, data, 4);
}

void RF242_Feature_DYN_ACK(uint8_t Dyn_ack)
{
	uint8_t value;
	
	/* Dynamic Ack Setting */
	value = RF242_Read_Reg(FEATURE);
	
	if(Dyn_ack)
	{
		value |= EN_DYN_ACK;
		DYN_ACKOn = 1;
	}
	else
	{
		value &= ~EN_DYN_ACK;
		DYN_ACKOn = 0;
	}
	
	RF242_Write_Reg(W_REG | FEATURE, value); 	
}

void RF242_Feature_DPL(uint8_t Dpl)
{
	uint8_t value;
	
	/* Dynamic Ack Setting */
	value = RF242_Read_Reg(FEATURE);
	
	if(Dpl)
		value |= EN_DPL;
	else
		value &= ~EN_DPL;
	
	RF242_Write_Reg(W_REG | FEATURE, value); 	
}

void RF242_Feature_ACK_PAY(uint8_t Ack_pay)
{
	uint8_t value;
	
	/* Ack Payload Setting */
	value = RF242_Read_Reg(FEATURE);
	
	if(Ack_pay)
	{
		value |= EN_ACK_PAY;
		ACK_PAYOn = 1;
	}
	else
	{
		value &= ~EN_ACK_PAY;
		ACK_PAYOn = 0;
	}
	
	RF242_Write_Reg(W_REG | FEATURE, value); 	
}

void RF242_EnableRSSI(void)
{
	uint8_t value;
	
	value = RF242_Read_Reg(RSSI);
	value |= EN_RSSI;
	
	RF242_Write_Reg(W_REG | RSSI, value); 	
}

void RF242_DisableRSSI(void)
{
	uint8_t value;
	
	value = RF242_Read_Reg(RSSI);
	value &= ~EN_RSSI;
	
	RF242_Write_Reg(W_REG | RSSI, value); 	
}

void RF242_SetChannel(uint8_t channel)
{
	
	RF242_Write_Reg(W_REG | RF_CH, channel); 
	
}

void RF242_Enable5dBm(void)
{
	uint8_t data[4];
// Refine RF TX power
// Register 0x06, SETUP_RF
// RF_PWR[1:0]=	2'b11 +6dBm
//							2'b10	5dBm
//							2'b01	-6dBm
//							2'b00 -12dBm
	data[0] = 0x3F;
	data[1] = 0x1D;
	data[2] = 0x01;
	data[3] = 0xDF;
	RF242_Write_Reg( W_REG | 0x1F, 0x01);
	RF242_Write_Buf( W_REG | 0x18, data, 4);
	RF242_Write_Reg( W_REG | 0x1F, 0x00);
}

void RF242_Enable4dBm(void)
{
	uint8_t data[4];
// Refine RF TX power
// Register 0x06, SETUP_RF
// RF_PWR[1:0]=	2'b11 +6dBm
//							2'b10	4dBm
//							2'b01	-6dBm
//							2'b00 -12dBm
	data[0] = 0x3F;
	data[1] = 0x1B;
	data[2] = 0x01;
	data[3] = 0xDF;
	RF242_Write_Reg( W_REG | 0x1F, 0x01);
	RF242_Write_Buf( W_REG | 0x18, data, 4);
	RF242_Write_Reg( W_REG | 0x1F, 0x00);
}

void RF242_Enable3dBm(void)
{
	uint8_t data[4];
// Refine RF TX power
// Register 0x06, SETUP_RF
// RF_PWR[1:0]=	2'b11 +6dBm
//							2'b10	3dBm
//							2'b01	-6dBm
//							2'b00 -12dBm
	data[0] = 0x3F;
	data[1] = 0x19;
	data[2] = 0x01;
	data[3] = 0xDF;
	RF242_Write_Reg( W_REG | 0x1F, 0x01);
	RF242_Write_Buf( W_REG | 0x18, data, 4);
	RF242_Write_Reg( W_REG | 0x1F, 0x00);
}

void RF242_Enable0dBm(void)
{
	uint8_t data[4];
// Refine RF TX power
// Register 0x06, SETUP_RF
// RF_PWR[1:0]=	2'b11 +6dBm
//							2'b10	0dBm
//							2'b01	-6dBm
//							2'b00 -12dBm
	data[0] = 0x3F;
	data[1] = 0x17;
	data[2] = 0x01;
	data[3] = 0xDF;
	RF242_Write_Reg( W_REG | 0x1F, 0x01);
	RF242_Write_Buf( W_REG | 0x18, data, 4);
	RF242_Write_Reg( W_REG | 0x1F, 0x00);
}

void RF242_EnableRSSIHoldPacketMode(void)
{
	uint8_t data[4];
	/* refine RF mode*/
	data[0] = 0x00;
	data[1] = 0x00;
	data[2] = 0xFB;
	data[3] = 0xF6;
	RF242_Write_Reg( W_REG | 0x1F, 0x09);
	RF242_Write_Buf( W_REG | 0x18, data, 4);
	RF242_Write_Reg( W_REG | 0x1F, 0x00);
}

void RF242_DisableRSSIHoldPacketMode(void)
{
	uint8_t data[4];
	/* refine RF mode*/
	data[0] = 0x00;
	data[1] = 0x00;
	data[2] = 0xFE;
	data[3] = 0xFE;
	RF242_Write_Reg( W_REG | 0x1F, 0x09);
	RF242_Write_Buf( W_REG | 0x18, data, 4);
	RF242_Write_Reg( W_REG | 0x1F, 0x00);
}
uint8_t SPI_Byte_ReadWrite(uint8_t data)
//{
//	uint32_t indata=0,i,cmpdata=0x80;

//	for (i=0;i<8;i++)
//	{
//		if (cmpdata&data)
//			RF_MOSI_HIGH;
//		else
//			RF_MOSI_LOW;
//		if (RF_MISO)
//			indata|=1;
//		RF_CLK_HIGH;
//		
//		indata=indata<<1;
//		cmpdata=cmpdata>>1;
//		RF_CLK_LOW;
//	}
//	return (indata>>1);
//} 
{
		uint32_t i,cmpdata=0x80;

		for (i=0;i<8;i++)
		{
			if (cmpdata&data)
				RF_MOSI_HIGH;
			else
				RF_MOSI_LOW;
			
			data  = data << 1;
			RF_CLK_HIGH;
			data |= RF_MISO;           
			RF_CLK_LOW;
		}
		RF_MOSI_LOW;      // reset SDI
		return (data);
}

// END SPI_Transfer

