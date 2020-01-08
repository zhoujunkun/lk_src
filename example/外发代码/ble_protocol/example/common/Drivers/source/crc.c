/*****************************************************************************
*   crc.h:  source file for crc module
*		ver 1.0
******************************************************************************/

#include "CMSDK_CM0.h"
#include "crc.h"
#include "sys.h"
/*****************************************************************************
Function Name	CRC_CCITT
Function Definition	Int16_t CRC_CCITT(uint8_t * str, uint16_t strlen,uint32_t crcseed);
Function Description	CRC CCITT Calculate
Input Parameters	*str: pointer to string
strlen: length of string
crcseed: seed of CRC. seed=0->xModen;seed=0xffff->standard;seed=0x1d0f->0x1d0f
Return Value	CRC calculation result
Condition	No
Function called	-

*****************************************************************************/
uint16_t CRC_CCITT(uint8_t * str, uint16_t strlen,uint32_t crcseed)
{
	uint16_t crcvalue;
	//initial CRC
	SYSCON->SYSAHBCLKCTRL_b.CRC_CLK = 1;
	SYSCON->PRESETCTRL_b.CRC_RST_N =0;
	SYSCON->PRESETCTRL_b.CRC_RST_N =1;
	CRC->SEED = crcseed; 
	CRC->MODE_b.SEED_OP =1;
	CRC->MODE_b.CRC_POLY=0;
	CRC->MODE_b.SEED_SET=1;

	//calculate CRC
	while ( strlen != 0)
	{
		 CRC->DATA_8BIT = *str++;
		 strlen --;
	}
	crcvalue=(uint16_t) CRC->SUM;
	
	SYSCON->SYSAHBCLKCTRL_b.CRC_CLK = 0;
	
	return crcvalue;
}
/*****************************************************************************
Function Name	CRC_16
Function Definition	uint16_t CRC_16(uint8_t * str, uint16_t strlen,uint32_t crcseed);
Function Description	CRC 16 Calculate
Input Parameters	*str: pointer to string
strlen: length of string
crcseed: seed of CRC. seed=0->standard;seed=0xffff->Modbus
Return Value	CRC calculation result
Condition	No
Function called	-

*****************************************************************************/
uint16_t CRC_16(uint8_t * str, uint16_t strlen,uint32_t crcseed)
{
	uint16_t crcvalue;
	//initial CRC
	SYSCON->SYSAHBCLKCTRL_b.CRC_CLK = 1;
	SYSCON->PRESETCTRL_b.CRC_RST_N =0;
	SYSCON->PRESETCTRL_b.CRC_RST_N =1;
	CRC->SEED = crcseed; 
	CRC->MODE_b.CRC_POLY=1;
	CRC->MODE_b.BIT_RVS_WR=1;
	CRC->MODE_b.BIT_RVS_SUM=1;
	CRC->MODE_b.SEED_OP =1;
	CRC->MODE_b.SEED_SET=1;

	//calculate CRC
	while ( strlen != 0)
	{
		 CRC->DATA_8BIT = *str++;
		 strlen --;
	}
	crcvalue=(uint16_t) CRC->SUM;
	
	SYSCON->SYSAHBCLKCTRL_b.CRC_CLK = 0;
	
	return crcvalue;
}
/*****************************************************************************
Function Name	CRC_32
Function Definition	uint32_t CRC_32(uint8_t * str, uint16_t strlen);
Function Description	CRC 32 Calculate
Input Parameters	*str: pointer to string
strlen: length of string
Return Value	CRC calculation result
Condition	No
Function called	-

*****************************************************************************/
uint32_t CRC_32(uint8_t * str, uint16_t strlen)
{
	uint32_t crcvalue;
	//initial CRC
	SYSCON->SYSAHBCLKCTRL_b.CRC_CLK = 1;
	SYSCON->PRESETCTRL_b.CRC_RST_N =0;
	SYSCON->PRESETCTRL_b.CRC_RST_N =1;
	CRC->MODE_b.CRC_POLY=2; 
	CRC->MODE_b.BIT_RVS_WR=1;
	CRC->MODE_b.BIT_RVS_SUM =1;
	CRC->MODE_b.CMPL_SUM =1;
	CRC->MODE_b.SEED_SET=1;

	//calculate CRC
	while ( strlen != 0)
	{
		 CRC->DATA_8BIT = *str++;
		 strlen --;
	}
	crcvalue=CRC->SUM;
	
	SYSCON->SYSAHBCLKCTRL_b.CRC_CLK = 0;
	
	return crcvalue;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
