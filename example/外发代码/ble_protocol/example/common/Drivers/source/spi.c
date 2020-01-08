/*****************************************************************************
*   spi.c:  source file for spi module
*		ver 1.0
******************************************************************************/
#include "CMSDK_CM0.h"
#include "sys.h"
#include "spi.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	SPI_Open
Function Definition	void SPI_Open(uint8_t framemode, uint8_t bitwidth, uint8_t master, uint8_t spionlymode)
Function Description	Initial SPI infterface 
Input Parameters	Framemode: SPI_FRAME/SSI_FRAME, current support SPI_FRAME only
Bitwidth: data size, from 4-bit to 16-bit
Master: selection of master or slave, SPI_MASTER/SPI_SLAVE
spionlymode: SPI_MODE0~SPI_MODE3
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_Open(uint8_t framemode, uint8_t bitwidth, uint8_t master, uint8_t spionlymode)
{
	//enable SPI clock
	SYSCON->SYSAHBCLKCTRL_b.SPI_CLK=1;
	//set spi frame SPI/SSI selcetion
	SPI->CR0_b.FRF=framemode;
	//select bit width
	SPI->CR0_b.DSS=bitwidth-1;
	//Set master/slave
	if (master==SPI_MASTER)
		SPI->CR1_b.MS=0;
	else
		SPI->CR1_b.MS=1;
	//set SPI mode
	SPI->CR0_b.CPOL=spionlymode;
	SPI->CR0_b.CPHA=spionlymode>>1;
	//enable SPIcontroller
	SPI->CR1_b.SSE=1;
	
	return;
}
/*****************************************************************************
Function Name	SPI_Close
Function Definition	void SPI_Close(void)
Function Description	De-Initial SPI interface 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_Close(void)
{
	//Disable SPI clock
	SYSCON->SYSAHBCLKCTRL_b.SPI_CLK=0;
	return;
}
/*****************************************************************************
Function Name	SPI_SetClk
Function Definition	void SPI_SetClk(uint32_t freq)
Function Description	Setup SPI clock. In Master mode, SPI frequency set no more than system clock divide by 7; 
												in Slave mode, the frequency set no more than system clock divide by 12.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_SetClk(uint32_t freq)
{
	uint32_t div;
	
	div=SystemCoreClock/freq;
	
	if (SPI->CR1_b.MS)
	{
		//slave mode
		if (div<12)
			div=12;
	}else
	{
		//master mode
		if (div<7)
			div=7;
		
	}
	//set up divider
	SPI->CPSR_b.CPSDVSR=div;
	return;
}
/*****************************************************************************
Function Name	SPI_ClearFIFO
Function Definition	void SPI_ClearFIFO(void)
Function Description	Clear SPI TX and RX FIFO.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_ClearFIFO(void)
{
	//wait untile TX FIFO empty
	while(SPI_TX_FIFO_Not_Empty);
	//clear RX FIFO
	SPI->CR1_b.RSFR=1;
	SPI->CR1_b.RSFR=0;
	return;
}
/*****************************************************************************
Function Name	SPI_SingleWriteRead
Function Definition	void SPI_SingleWriteRead(uint16_t *data)
Function Description	Write data to external SPI device and same time read same size data back from SPI device.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_SingleWriteRead(uint16_t *data)
{
	//wait untile TX FIFO empty
	while(SPI_TX_FIFO_Not_Empty);
	//clear RX FIFO
	SPI->CR1_b.RSFR=1;
	SPI->CR1_b.RSFR=0;
	//Write data to FIFO
	SPI->DR=*data;
	//wait untile TX FIFO empty
	while(SPI_TX_FIFO_Not_Empty);
	//Read data from FIFO	
	*data=SPI->DR;
	return;
}
/*****************************************************************************
Function Name	SPI_Write
Function Definition	void SPI_Write (uint8_t *src, uint8_t noofdata)
Function Description	Write data to SPI FIFO, if FIFO full, stop with rest number of data and current data pointer
Input Parameters	*src: pointer to data
noofdata: number of data to send
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_Write (uint8_t *src, uint8_t noofdata)
{
	uint32_t n;
	while(noofdata!=0)
	{
	//wait untile TX FIFO empty
	//while(SPI_TX_FIFO_Not_Empty);
//	//clear RX FIFO
//	SPI->CR1_b.RSFR=1;
//	SPI->CR1_b.RSFR=0;
//	//Write data to FIFO
	if (SPI->SR_b.TNF)
	{
	SPI->DR=*src++;
		noofdata--;
	}
	//wait untile TX FIFO empty
//	while(SPI_TX_FIFO_Not_Empty);
//	//Read data from FIFO	
//	//*data=SPI->DR;
	
		
//		//Write data to FIFO
//		if (SPI->SR_b.TNF)
		
//		for(n=0;n<8;n++)
//		{			
//			SPI->DR=*src++;	
//			noofdata--;
//			if (noofdata==0)
//				break;
//		}
	}
	//wait untile TX FIFO empty
	while(SPI_TX_FIFO_Not_Empty);
	return;
}
/*****************************************************************************
Function Name	SPI_Read
Function Definition	void SPI_Read (uint8_t *dst, uint8_t noofdata)
Function Description	Read data from SPI FIFO.
Input Parameters	*dst: pointer to destination
noofdata: number of data read
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_Read (uint8_t *dst, uint8_t noofdata)
{
	uint8_t notx,norx;
	notx=noofdata;norx=noofdata;
	//wait untile TX FIFO empty
	while(SPI_TX_FIFO_Not_Empty);
	//clear RX FIFO
	SPI->CR1_b.RSFR=1;
	SPI->CR1_b.RSFR=0;
	//
	while(notx!=0)
	{
		//Get data form FIFO
		if (SPI->SR_b.RNE)
		{
			*dst++=SPI->DR;
			norx--;
		}
		//Write data to FIFO
		if (SPI->SR_b.TNF)
		{			
			SPI->DR=0x00;	
			notx--;
		}
	}
	while(norx!=0)
	{
		//Get data form FIFO
		if (SPI->SR_b.RNE)
		{
			*dst++=SPI->DR;
			norx--;
		}
	}
	return;
}
/*****************************************************************************
Function Name	SPI_ClrInt(may not need)
Function Definition	void SPI_ClrInt(void)
Function Description	Clear SPI interrupt
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_ClrInt(void)
{
	SPI->ICR_b.RORIC;
}
/*****************************************************************************
Function Name	SPI_EnableInt
Function Definition	void SPI_EnableInt(uint8_t inttype)
Function Description	Setup SPI interrupt
Input Parameters	Inttype: combination of 
					SPI_RX_FIFO_FULL	1
					SPI_RX_FIFO_NOT_EMPTY	2
					SPI_RX_FIFO_HALF_FULL	4
					SPI_TX_FIFO_HALF_EMPTY	8
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_EnableInt(uint8_t inttype)
{
	SPI->IMSC |= inttype;
	return;
}
/*****************************************************************************
Function Name	SPI_DisableInt
Function Definition	void SPI_DisableInt(uint8_t inttype)
Function Description	Setup SPI interrupt
Input Parameters	Inttype: combination of 
					SPI_RX_FIFO_FULL	1
					SPI_RX_FIFO_NOT_EMPTY	2
					SPI_RX_FIFO_HALF_FULL	4
					SPI_TX_FIFO_HALF_EMPTY	8
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SPI_DisableInt(uint8_t inttype)
{
	SPI->IMSC &= ~inttype;
	
	return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
