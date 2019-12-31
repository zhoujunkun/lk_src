/*****************************************************************************
*   wdt.h:  Header file for wdt.c
*		ver 1.0
******************************************************************************/

#ifndef __WDT_H 
#define __WDT_H
#include "CMSDK_CM0.h"

#define WDT_Enable_Timer (WDT->MOD_b.WDEN=1)
#define WDT_Disable_Timer (WDT->MOD_b.WDEN=0)

void WDT_Init (void);
void WDT_Deinit(void);
void WDT_SetWindowValue (uint32_t intticks,uint32_t windowticks);
void WDT_Feed (void);
void WDT_SetIntervalinTick(uint32_t ticks);
void WDT_SetIntervalinMiliSec(uint32_t ms);
void WDT_EnableResetSystem(void);
void WDT_ClearIntFlag(void);
void WDT_GetIntStatus (void);
void WDT_EnableLock (void);


#endif /* end __TOUCH_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
