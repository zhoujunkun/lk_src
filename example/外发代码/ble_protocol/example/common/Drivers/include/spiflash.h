/*****************************************************************************
*   spiflash.h:  Header file for spi flash access
******************************************************************************/
#ifndef __SPIFLASH_H 
#define __SPIFLASH_H
#include "CMSDK_CM0.h"

void SPIFlashInit(void);
uint8_t SPIFlashID(void);
uint8_t SPIFlashStatus(void);
void SPIFlashWriteEnable(void);
void SPIFlashSecErase(uint32_t addr);
void SPIFlashRead(uint32_t addr, uint8_t * dst, uint32_t noofdata);
void SPIFlashWrite(uint32_t addr, uint8_t * src, uint8_t noofdata);
#endif /* end __SPIFLASH_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
