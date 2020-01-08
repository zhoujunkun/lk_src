/*****************************************************************************
*   gpiospi.h:  Header file for gpiospi.c
*		ver 1.0
******************************************************************************/
#ifndef __GPIOSPI_H 
#define __GPIOSPI_H

#include "CMSDK_CM0.h"

#define GPIO_SPI_CS_PIN_INIT (PC->DIR |= 0x100) //PC_8
#define GPIO_SPI_CS_HIGH (PC->SET = 0x100)
#define GPIO_SPI_CS_LOW (PC->CLR = 0x100)

#define GPIO_SPI_CLK_PIN_INIT (PA->DIR |= 0x8000) //PA_15
#define GPIO_SPI_CLK_HIGH (PA->SET = 0x8000)
#define GPIO_SPI_CLK_LOW (PA->CLR = 0x8000)

#define GPIO_SPI_MOSI_PIN_INIT (PA->DIR |= 0x2) //PA_1
#define GPIO_SPI_MOSI_HIGH (PA->SET = 0x2)
#define GPIO_SPI_MOSI_LOW (PA->CLR = 0x2)

#define GPIO_SPI_MISO (PB->PIN&0x1) //PB_0

void GPIO_SPI_Init(void);
uint8_t GPIO_SPI_Byte_Read(void);
void GPIO_SPI_Byte_Write(uint8_t data);
uint8_t GPIO_SPI_Byte_ReadWrite(uint8_t data);


#endif /* end __GPIOSPI_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/

