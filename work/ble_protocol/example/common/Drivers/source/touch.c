/*****************************************************************************
*   touch.c:  source file for touch module
*		ver 1.0
******************************************************************************/

#include "CMSDK_CM0.h"
#include "sys.h"
#include "touch.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	TOUCH_Init
Function Definition	void TOUCH_Init(void)
Function Description	Initial Cap Touch module, default sense clock selection is 0x01(~1.3MHz) 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_Init(void)
{
	SYSCON->PDRUNCFG_b.TOUCH_PD=0;
	SYSCON->SYSAHBCLKCTRL_b.TOUCH_CLK=1;
	SYSCON->PRESETCTRL_b.TOUCH_RST_N=0;
	SYSCON->PRESETCTRL_b.TOUCH_RST_N=1;
	
	#if OLD_VERSION
		TOUCH->CTRL_b.EXTRSEL=1;
	#else
		TOUCH->CTRL_b.EXTRSEL=0;
	#endif

	TOUCH->CTRL_b.INTERNALRSET=TOUCH_SENSE_CLK_800; //seleect 800KHZ as default
	TOUCH->CTRL_b.OSCEN=1;
	TOUCH->CTRL_b.CAPTEN=1;
	return;
}
/*****************************************************************************
Function Name	TOUCH_Deinit
Function Definition	void TOUCH_Deinit(void)
Function Description	Shut down Cap Touch module
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_Deinit(void)
{
	TOUCH->CTRL_b.OSCEN=0;
	TOUCH->CTRL_b.CAPTEN=0;
	SYSCON->PDRUNCFG_b.TOUCH_PD=1;
	SYSCON->SYSAHBCLKCTRL_b.TOUCH_CLK=0;

	return;
}
/*****************************************************************************
Function Name	TOUCH_SelSenseClk
Function Definition	void TOUCH_SelSenseClk (uint8_t clkfreq)
Function Description	Select sense clock fequency
Input Parameters	Clkfreq: TOUCH_SENSE_CLK_3600 0
													TOUCH_SENSE_CLK_1400	1
													TOUCH_SENSE_CLK_600	2
													TOUCH_SENSE_CLK_350	3
													TOUCH_SENSE_CLK_EXT	4
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_SelSenseClk (uint8_t clkfreq)
{
	if (clkfreq==TOUCH_SENSE_CLK_EXT)
		TOUCH->CTRL_b.EXTRSEL=1;
	else
	{
		TOUCH->CTRL_b.EXTRSEL=0;
		TOUCH->CTRL_b.INTERNALRSET=clkfreq; 
	}

	return;
}
/*****************************************************************************
Function Name	TOUCH_EnableTouchCHN
Function Definition	void TOUCH_EnableTouchCHN(uint32_t channels)
Function Description	Enable scan selected channel. The unselected channel scanning is ignored. 
Input Parameters	Channels: combination of TOUCH0~TOUCH21
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_EnableTouchCHN(uint32_t channels)
{
	TOUCH->CTRL_b.CHNEN|=channels;
	
	return;
}
/*****************************************************************************
Function Name	TOUCH_SetScanTime
Function Definition	void TOUCH_SetScanTime(uint32_t minisec)
Function Description	Setup sensing time for each touch pin
Input Parameters	minisec: mini seconds
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_SetScanTime(uint32_t minisec)
{
		TOUCH->SENSTM=SystemCoreClock*minisec/1000;
	return;

}
/*****************************************************************************
Function Name	TOUCH_SetWaterMark
Function Definition	void TOUCH_SetWaterMark(uint32_t level)
Function Description	Setup sensing threshold for touched pin
Input Parameters	Level: counter number. If Cap Touch counter number lower than level, 
the interrupt is triggered. if level is 0, disable watermark function.
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_SetWaterMark(uint32_t level)
{
	TOUCH->CTRL_b.INTEN=1;
	TOUCH->WATMK=level;

	return;

}
/*****************************************************************************
Function Name	TOUCH_EnableScanInt
Function Definition	void TOUCH_EnableScanInt(void)
Function Description	Enable interrupt for each touch pin scan completed
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_EnableScanInt(void)
{
	TOUCH->CTRL_b.SCANINTEN=1;
	TOUCH->CTRL_b.INTEN=1;
	return;

}
/*****************************************************************************
Function Name	TOUCH_DisableScanInt
Function Definition	void TOUCH_DisableScanInt(void)
Function Description	Disable interrupt for each touch pin scan completed
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_DisableScanInt(void)
{
	TOUCH->CTRL_b.SCANINTEN=0;
	return;

}
/*****************************************************************************
Function Name	TOUCH_GetScanVal
Function Definition	void TOUCH_GetScanVal(uint8_8 * channel, uint32_t *val)
Function Description	Get channel number and counter value of last completed scan 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_GetScanVal(uint8_t * channel, uint32_t *val)
{
	*channel=TOUCH->SCANCHN_b.CHN;
	*val=TOUCH->SCANCNT;
	return;

}
/*****************************************************************************
Function Name	TOUCH_GetTouchedVal
Function Definition	void TOUCH_GetTouchedVal (uint8_t * channel, uint32_t *val)
Function Description	Get channel number and counter value when touch is sensed 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_GetTouchedVal (uint8_t * channel, uint32_t *val)
{
	*channel=TOUCH->TOUCHCHN_b.CHN;
	*val=TOUCH->TOUCHCNT;
	return;

}
/*****************************************************************************
Function Name	TOUCH_ClearIntFlag
Function Definition	void TOUCH_ClearIntFlag(void)
Function Description	Clear Cap Touch interrupt flag
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_ClearIntFlag(void)
{
	TOUCH->RAWSTAT=0x3;
	return;

}
/******************************************************************************
**                            End Of File
******************************************************************************/
