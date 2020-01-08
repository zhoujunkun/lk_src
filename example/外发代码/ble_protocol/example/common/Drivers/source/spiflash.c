/*----------- This drive is for Winbond W25Q16BV serial flash ----------------*/
/* Includes ------------------------------------------------------------------*/
#include "CMSDK_CM0.h"
#include "spiflash.h"
#include "sys.h"
#include "spi.h"

//flash command
#define WREN  6		 //write enable
#define WRDI  4		 //write disable
#define RDSR  5		 //read status register 1
#define WRSR  1		 //write status register
#define READ  3		 //read data
#define FAST_READ 0xb//fast read
#define PP    2		 //page program
#define SE4    0x20 //4K block erase
#define SE32    0x52 //32K block erase
#define SE64    0xd8 //64K block erase
#define DP    0xb9	 //power down
#define RES   0xab	 //release power down and device ID
//flash status
#define FLASH_BUSY   0x1	 //indication of flash programming in progress
/*****************************************************************************
** Function name:		SPIFlashInit
**
** Descriptions:		initial SPI interface
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void SPIFlashInit(void)
{
	//initial SPI
	SPI_Open(SPI_FRAME, 8, SPI_MASTER, SPI_MODE0);
	SPI_SetClk(1000000);
	return;	
}
/*****************************************************************************
** Function name:		SPIFlashID
**
** Descriptions:		get flash device ID
**
** parameters:			None
** Returned value:		Flash ID
** 
*****************************************************************************/
uint8_t SPIFlashID(void)
{
	uint16_t data;
	SPI_Reset_SSEL_Low; //force cs single low during access SPI flash
	SPI_Write_FIFO(RES);//isssue release power down and device ID command
	SPI_Write_FIFO(0); //isssue dummy clock
	SPI_Write_FIFO(0); //isssue dummy clock
	SPI_Write_FIFO(0); //isssue dummy clock
 	SPI_SingleWriteRead(&data); //get device id 
	SPI_Set_SSEL_High; //set cs signal

	return (uint8_t)data;
}
/*****************************************************************************
** Function name:		SPIFlashStatus
**
** Descriptions:		get flash status  S7-S0
**
** parameters:			sr1 pointer
** Returned value:		None
** 
*****************************************************************************/
uint8_t SPIFlashStatus(void)
{
	uint16_t data;
	SPI_Reset_SSEL_Low; //force cs single low during access SPI flash
	SPI_Write_FIFO(RDSR);//isssue read status register 1 command
	SPI_SingleWriteRead(&data); //get device id 
	SPI_Set_SSEL_High; //set cs signal
	return (uint8_t) data;;
}
/*****************************************************************************
** Function name:		SPIFlashWriteEnable
**
** Descriptions:		enable flash write
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void SPIFlashWriteEnable(void)
{
	SPI_Reset_SSEL_Low; //force cs single low during access SPI flash
	SPI_Write_FIFO(WREN);//isssue write enable command
	while(SPI_TX_FIFO_Not_Empty);  //wait SPI not busy & transmit fifo empty 
	SPI_Set_SSEL_High; //set cs signal

	return;		
}
/*****************************************************************************
** Function name:		SPIFlashRead
**
** Descriptions:		read data from specfic address
**
** parameters:			data address, return data pointer,number data to read
** Returned value:		None
** 
*****************************************************************************/
void SPIFlashRead(uint32_t addr, uint8_t * dst, uint32_t noofdata)
{
	uint16_t data;

	SPI_Reset_SSEL_Low; //force cs single low during access SPI flash
	SPI_Write_FIFO(READ);		 //isssue Read command
	SPI_Write_FIFO(addr>>16);		 //isssue Read  command addr A23-A16
	SPI_Write_FIFO((addr & 0xFF00)>>8);		 //isssue Read  command addr A15-A8
	SPI_Write_FIFO(addr & 0xFF);		 //isssue Read  command addr A7-A0

	//Receive data from flash
//	while (noofdata-->0)
//	{
//		SPI_SingleWriteRead(&data); //get one data 
//		*dst++=(uint8_t) data;
//	}
	SPI_Read(dst,noofdata);
	SPI_Set_SSEL_High; //set cs signal

	return;
}
/*****************************************************************************
** Function name:		SPIFlashRead
**
** Descriptions:		program data to flash
**
** parameters:			flash address, data pointer,number data to program
** Returned value:		None
** 
*****************************************************************************/
void SPIFlashWrite(uint32_t addr, uint8_t * src, uint8_t noofdata)
{
	uint16_t data;
	//enable flash write
	SPIFlashWriteEnable();
	//issue flash programming cmd	
	SPI_Reset_SSEL_Low; //force cs single low during access SPI flash
	SPI_Write_FIFO(PP);		 //isssue PP command
	SPI_Write_FIFO(addr>>16);		 //isssue Read  command addr A23-A16
	SPI_Write_FIFO((addr & 0xFF00)>>8);		 //isssue Read  command addr A15-A8
	SPI_Write_FIFO(addr & 0xFF);		 //isssue Read  command addr A7-A0

	//Receive data from flash
//	while (noofdata-->0)
//	{
//		data=*src++;
//		SPI_SingleWriteRead(&data); //write one data 
//	}
	SPI_Write (src, noofdata);
	SPI_Set_SSEL_High; //set cs signal
	//wait untile programming done
	while(SPIFlashStatus()&FLASH_BUSY);
	return;	
}
/*****************************************************************************
** Function name:		SPIFlashSecErase
**
** Descriptions:		flash sector erase
**
** parameters:			flash address
** Returned value:		None
** 
*****************************************************************************/
void SPIFlashSecErase(uint32_t addr)
{
	//enable flash write
	SPIFlashWriteEnable();
	//issue flash erase cmd
	SPI_Reset_SSEL_Low; //force cs single low during access SPI flash
	SPI_Write_FIFO(SE4);		 //isssue Erase SE4/SE32/SE64 command
	SPI_Write_FIFO(addr>>16);		 //isssue Read  command addr A23-A16
	SPI_Write_FIFO((addr & 0xFF00)>>8);		 //isssue Read  command addr A15-A8
	SPI_Write_FIFO(addr & 0xFF);		 //isssue Read  command addr A7-A0
	while(SPI_TX_FIFO_Not_Empty);  //wait SPI not busy & transmit fifo empty 
	SPI_Set_SSEL_High; //set cs signal
	//wait untile erase done
	while(SPIFlashStatus()&FLASH_BUSY);
	return;	
}
	  

/******************************************************************************
**                            End Of File
******************************************************************************/
