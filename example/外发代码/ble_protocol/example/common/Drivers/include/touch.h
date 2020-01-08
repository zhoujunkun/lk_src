/*****************************************************************************
*   touch.h:  Header file for touch.c
*		ver 1.0
******************************************************************************/

#ifndef __TOUCH_H 
#define __TOUCH_H
#include "CMSDK_CM0.h"

//Touch pin
#define TOUCH0  0x1
#define TOUCH1  0x2
#define TOUCH2  0x4
#define TOUCH3  0x8
#define TOUCH4  0x10
#define TOUCH5  0x20
#define TOUCH6  0x40
#define TOUCH7  0x80
#define TOUCH8  0x100
#define TOUCH9  0x200
#define TOUCH10 0x400
#define TOUCH11 0x800
#define TOUCH12 0x1000
#define TOUCH13 0x2000
#define TOUCH14 0x4000
#define TOUCH15 0x8000
#define TOUCH16 0x10000
#define TOUCH17 0x20000
#define TOUCH18 0x40000
#define TOUCH19 0x80000
#define TOUCH20 0x100000
#define TOUCH21 0x200000

#define TOUCH_SENSE_CLK_5000 0
#define TOUCH_SENSE_CLK_2000	1
#define TOUCH_SENSE_CLK_800	2
#define TOUCH_SENSE_CLK_500	3
#define TOUCH_SENSE_CLK_EXT	4

void TOUCH_Init(void);
void TOUCH_Deinit(void);
void TOUCH_SelSenseClk (uint8_t clkfreq);
void TOUCH_EnableTouchCHN(uint32_t channels);
void TOUCH_SetScanTime(uint32_t minisec);
void TOUCH_SetWaterMark(uint32_t level);
void TOUCH_EnableScanInt(void);
void TOUCH_DisableScanInt(void);
void TOUCH_GetScanVal(uint8_t *channel, uint32_t *val);
void TOUCH_GetTouchedVal (uint8_t *channel, uint32_t *val);
void TOUCH_ClearIntFlag (void);

#endif /* end __TOUCH_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
