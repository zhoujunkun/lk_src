/*****************************************************************************
*   iap.h:  Header file for iap.c
*		ver 1.0
******************************************************************************/
#ifndef __IAP_H 
#define __IAP_H
#include "CMSDK_CM0.h"

#define	SECTORSIZE 0x200  //512 bytes sector size
#define	IAPENTRYVECTOR			0x1FFF00FC

//IAP Command
#define	SECTORERASE			0x45		//擦除命令
#define	PROGFLASH			0x50		//写Flash
#define BSLVER			0x56		//读系统信息

//IAP RETURN CODE
#define CMD_SUCC		0x00
#define INVALID_ADDR	0x01
#define ERASE_FAILED	0x02
#define PROG_FAILED		0x03
#define NOT_BLANK		0x04
#define INVALID_CMD		0x05

typedef void (*IAP)(uint32_t *,uint32_t*);
//Flash access speed control
void FMC_SetFlashReadTime(uint8_t clocks);
#endif /* end __IAP_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
