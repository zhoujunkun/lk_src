/*****************************************************************************
*   crc.h:  Header file for crc.c
*		ver 1.0
******************************************************************************/
/*****************************************************************************
CRC-CCITT set-up
		Polynomial = x16 + x12 + x5 + 1
		Seed Value = 0xFFFF
		Bit order reverse for data input: NO
		1's complement for data input: NO
		Bit order reverse for CRC sum: NO
		1's complement for CRC sum: NO
		CRC_MODE = 0x0000 0000
		CRC_SEED = 0x0000 FFFF
CRC-16 set-up
		Polynomial = x16 + x15 + x2 + 1
		Seed Value = 0x0000
		Bit order reverse for data input: YES
		1's complement for data input: NO
		Bit order reverse for CRC sum: YES
		1's complement for CRC sum: NO
		CRC_MODE = 0x0000 0015
		CRC_SEED = 0x0000 0000
CRC-32 set-up
		Polynomial = x32+ x26 + x23 + x22 + x16 + x12 + x11 + x10 + x8 + x7 + x5 + x4 + x2 + x + 1
		Seed Value = 0xFFFF FFFF
		Bit order reverse for data input: YES
		1's complement for data input: NO
		Bit order reverse for CRC sum: YES
		1's complement for CRC sum: YES
		CRC_MODE = 0x0000 0036
		CRC_SEED = 0xFFFF FFFF
*****************************************************************************/
#ifndef __CRC_H 
#define __CRC_H
#include "CMSDK_CM0.h"

uint16_t CRC_CCITT(uint8_t * str, uint16_t strlen,uint32_t crcseed);
uint16_t CRC_16(uint8_t * str, uint16_t strlen,uint32_t crcseed);
uint32_t CRC_32(uint8_t * str, uint16_t strlen);

#endif /* end __CRC_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
