/*****************************************************************************
*   spi.h:  Header file for spi.c
*		ver 1.0
******************************************************************************/
#ifndef __SPI_H 
#define __SPI_H

#include "CMSDK_CM0.h"

#define SPI_FRAME	0
#define SSI_FRAME	1

#define SPI_RX_FIFO_FULL	1
#define SPI_RX_FIFO_NOT_EMPTY	2
#define SPI_RX_FIFO_HALF_FULL	4
#define SPI_TX_FIFO_HALF_EMPTY	8

#define SPI_MODE0	0
#define SPI_MODE1	1
#define SPI_MODE2	2
#define SPI_MODE3	3
#define SPI_MASTER	0
#define SPI_SLAVE	1


#define SPI_Set_SSEL_High (SPI->CR1_b.CSFL = 0)
#define SPI_Reset_SSEL_Low (SPI->CR1_b.CSFL = 1)
#define SPI_Write_FIFO(data) (SPI->DR=data)
#define SPI_TX_FIFO_Not_Empty ((SPI->SR&0x11)!=1)
#define SPI_Read_FIFO(data) (data=SPI->DR)
//#define SPI_CLR_FIFO (SPI->CR1_b.RSFR =1; SPI->CR1_b.RSFR =0)

void SPI_Open(uint8_t framemode, uint8_t bitwidth, uint8_t master, uint8_t spionlymode);
void SPI_Close(void);
void SPI_SetClk(uint32_t freq);
void SPI_ClearFIFO(void);
void SPI_SingleWriteRead(uint16_t *data);
void SPI_Write (uint8_t *src, uint8_t noofdata);
void SPI_Read (uint8_t *dst, uint8_t noofdata);
void SPI_ClrInt(void);
void SPI_EnableInt(uint8_t inttype);


#endif /* end __SPI_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/

