/*****************************************************************************
*   wdt.c:  source file for WDT module
*		ver 
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "CMSDK_CM0.h"
#include "sys.h"
#include "wdt.h"
extern uint32_t MainClock;
/*****************************************************************************
Function Name	WDT_Init
Function Definition	void WDT_Init (void)
Function Description	Initial WDT module
Input Parameters	No 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_Init (void)
{
	//enable WDT PCLK
	SYSCON->SYSAHBCLKCTRL_b.WDT_CLK =1;
	//initial WDT to trigger interrupt
	WDT->MOD_b.WDRESET=1;
	return;
}
/*****************************************************************************
Function Name	WDT_Deinit
Function Definition	void WDT_Deinit (void)
Function Description	De-Initial WDT module
Input Parameters	No 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_Deinit(void)
{
	//disable WDT PCLK
	SYSCON->SYSAHBCLKCTRL_b.WDT_CLK=0;	
	return;
}
/*****************************************************************************
Function Name	WDT_SetWindowValue
Function Definition	void WDT_SetWindowValue (uint32_t intticks,uint32_t windowticks)
Function Description	Set WDT two windows value. 
Input Parameters	intticks: if WDT counter decrease to intticks value, the interrupt is generated
windowticks: if WDT counter decrease to windowticks value, no more feed valid. 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_SetWindowValue (uint32_t intticks,uint32_t windowticks)
{
	WDT->WARNINT_b.WARNINT=intticks;
	WDT->WINDOW_b.WDWINDOW=windowticks;
	return;
}

/*****************************************************************************
Function Name	WDT_Feed
Function Definition	void WDT_Feed (void)
Function Description	Watchdog feed
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_Feed (void)
{
	WDT->FEED_b.WDFEED  = 0xAA;
	WDT->FEED_b.WDFEED  = 0x55;
	return;	
}
/*****************************************************************************
Function Name	WDT_SetIntervalinTick
Function Definition	void WDT_SetIntervalinTick (uint32_t ticks)
Function Description	Setup WDT time out interval
Input Parameters	ticks: time interval in WDT tick
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_SetIntervalinTick(uint32_t ticks)
{
	WDT->TC_b.WDTC=ticks;
	
	return;
}
/*****************************************************************************
Function Name	WDT_SetIntervalinMiliSec
Function Definition	void WDT_SetIntervalinMiliSec(uint32_t ms)
Function Description	Setup WDT time out interval
Input Parameters	ms: time interval in mili second
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_SetIntervalinMiliSec(uint32_t ms)
{
	volatile uint32_t ticks;
	//limit WDT interval to 10s
	if (ms>10000)
		ms=10000;
	//Apply IRC clk
	SYSCON->WDTOSCCTRL_b.WDTCLKSRC=0;
	SYSCON->WDTOSCCTRL_b.DIVSEL=ms/1600+1;
	
	ticks=MainClock/(1000*SYSCON->WDTOSCCTRL_b.DIVSEL);
	//convert mili second to ticks
	ticks=(ticks*ms)>>2;
	if (ticks>0xFFFFFF)
		ticks=0xFFFFFF;
	//set WDT timeout interval
	WDT->TC_b.WDTC=ticks;
	ticks=0;
	while(ticks++<0xFFF);
	return;
}
/*****************************************************************************
Function Name	WDT_EnableResetSystem
Function Definition	void WDT_EnableResetSystem(void)
Function Description	Enable system reset after WDT timeout occurs
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_EnableResetSystem(void)
{
	WDT->MOD_b.WDRESET=1;
	return;
}
/*****************************************************************************
Function Name	WDT_ClearlntFlag
Function Definition	void WDT_ClearIntFlag(void)
Function Description	Clear WDT interrupt flag
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_ClearIntFlag(void)
{
	//clr time out flag
	WDT->MOD_b.WDTOF=0;
	//clr window int flag
	WDT->MOD_b.WDINT=1;
}
/*****************************************************************************
Function Name	WDT_ClearlntFlag
Function Definition	uint32_t WDT_GetCounterValue (void)
Function Description	Return WDT counter value
Input Parameters	No
Return Value	WDT counter value
Condition	No
Function called	-

*****************************************************************************/
uint32_t WDT_GetCounterValue (void)
{
	return WDT->TV;
}
/*****************************************************************************
Function Name	WDT_EnableLock
Function Definition	void WDT_EnableLock (void)
Function Description	Lock WDT Setting. Once WDT is locked, you can not do any changing to WDT, 
including enable/disable timer, changing of WDT timer out interval, and reset system setting when time out.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void WDT_EnableLock (void)
{
	WDT->MOD_b.WDLOCKCLK=1;
	WDT->MOD_b.WDLOCKDP=1;
	WDT->MOD_b.WDLOCKEN=1;
	
	return;
}
 
