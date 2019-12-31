/*****************************************************************************
*   gpiospi.c:  Source file for gpio spi simulation
*		ver 1.0
******************************************************************************/

#include "CMSDK_CM0.h"
#include "gpiospi.h"

//#define GPIO_SPI_CS_PIN_INIT (PC->DIR = 0x100) //PC_8
//#define GPIO_SPI_CS_HIGH (PC->SET = 0x100)
//#define GPIO_SPI_CS_LOW (PC->CLR = 0x100)

//#define GPIO_SPI_CLK_PIN_INIT (PA->DIR = 0x8000) //PA_15
//#define GPIO_SPI_CLK_HIGH (PA->SET = 0x8000)
//#define GPIO_SPI_CLK_LOW (PA->CLR = 0x8000)

//#define GPIO_SPI_MOSI_PIN_INIT (PC->DIR = 0x2) //PA_1
//#define GPIO_SPI_MOSI_HIGH (PC->SET = 0x2)
//#define GPIO_SPI_MOSI_LOW (PC->CLR = 0x2)

//#define GPIO_SPI_MISO (PB->PIN&0x1) //PB_0

void GPIO_SPI_Init(void)
{
	GPIO_SPI_CS_PIN_INIT;
	GPIO_SPI_CS_HIGH;
	GPIO_SPI_CLK_PIN_INIT;
	GPIO_SPI_CLK_LOW;
	GPIO_SPI_MOSI_PIN_INIT;
	
}
uint8_t GPIO_SPI_Byte_Read(void)
{
	uint32_t indata=0,i;
	
	for (i=0;i<8;i++)
	{
		GPIO_SPI_CLK_HIGH;
		GPIO_SPI_CLK_HIGH;
		indata=indata<<1;
		GPIO_SPI_CLK_LOW;
		if (GPIO_SPI_MISO)
			indata|=1;
	}
	return indata;
}
void GPIO_SPI_Byte_Write(uint8_t data)
{
	uint32_t i,cmpdata=0x80;

	for (i=0;i<8;i++)
	{
		GPIO_SPI_CLK_HIGH;
		if (cmpdata&data)
			GPIO_SPI_MOSI_HIGH;
		else
			GPIO_SPI_MOSI_LOW;
		
		GPIO_SPI_CLK_LOW;
		cmpdata=cmpdata>>1;
	}
}
uint8_t GPIO_SPI_Byte_ReadWrite(uint8_t data)
{
	uint32_t indata=0,i,cmpdata=0x80;

	for (i=0;i<8;i++)
	{
		GPIO_SPI_CLK_HIGH;
		if (cmpdata&data)
			GPIO_SPI_MOSI_HIGH;
		else
			GPIO_SPI_MOSI_LOW;
		
		GPIO_SPI_CLK_LOW;
		indata=indata<<1;
		if (GPIO_SPI_MISO)
			indata|=1;
		cmpdata=cmpdata>>1;
	}
	return indata;
}


/*****************************************************************************
**                            End Of File
******************************************************************************/

