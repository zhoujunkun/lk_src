/*****************************************************************************
*   iap.c:  source file for IAP
*		ver 1.0
******************************************************************************/

#include "CMSDK_CM0.h"
#include "iap.h"

/*****************************************************************************
Function Name	FMC_SetFlashReadTime
Function Definition	void FMC_SetFlashReadTime(uint8_t clocks)
Function Description	Set Read flash cycle
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void FMC_SetFlashReadTime(uint8_t clocks)
{
	FMC->FLASH_RDCYC = clocks;
}
