/*****************************************************************************
*   timer.h:  Header file for timer.c
*		ver 1.0
******************************************************************************/
#ifndef __TIMER_H 
#define __TIMER_H
#include "CMSDK_CM0.h"

//Int Status
#define TIM_MATCH_0_INT 0x1
#define TIM_MATCH_1_INT 0x2
#define TIM_MATCH_2_INT 0x4
#define TIM_MATCH_3_INT 0x8
#define TIM_CAPTURE_0_INT 0x10
#define TIM_CAPTURE_1_INT 0x20
#define TIM_CAPTURE_2_INT 0x40
#define TIM_CAPTURE_3_INT	 0x80

//Capture control
#define TIM_CAPTURE_DO_NOTHING 0x0
#define TIM_CAPTURE_RISE_EDGE 0x1
#define TIM_CAPTURE_FALL_EDGE 0x2
#define TIM_CAPTURE_TRIGGER_INT	 0x4

//Match Control
#define TIM_MATCH_TRIGGER_INT 0x1
#define TIM_MATCH_RESET_COUNTER 0x2
#define TIM_MATCH_STOP_COUNTER 0x4
#define TIM_MATCH_DO_NOTHING 0x0

//Match Output Control
#define TIM_MATCH_OUT_DO_NOTHING 0x0
#define TIM_MATCH_OUT_RESET 0x1
#define TIM_MATCH_OUT_SET	 0x2
#define TIM_MATCH_OUT_TOGGLE	 0x3

//Match PWM Output Channel
#define TIM_PWM0_ON_MAT0 0x1
#define TIM_PWM1_ON_MAT1 0x2
#define TIM_PWM2_ON_MAT2 0x4

//Macros
#define TIM0_START  (TIM0->TCR_b.CEN = 1)
#define TIM1_START  (TIM1->TCR_b.CEN = 1)
#define TIM0_STOP  (TIM0->TCR_b.CEN = 0)
#define TIM1_STOP  (TIM1->TCR_b.CEN = 0)
#define TIM0_RESET_COUNTER  (TIM0->TCR_b.CRST = 1)
#define TIM1_RESET_COUNTER  (TIM1->TCR_b.CRST = 1)
#define TIM2_START  (TIM2->TCR_b.CEN = 1)
#define TIM3_START  (TIM3->TCR_b.CEN = 1)
#define TIM2_STOP  (TIM2->TCR_b.CEN = 0)
#define TIM3_STOP  (TIM3->TCR_b.CEN = 0)
#define TIM2_RESET_COUNTER  (TIM2->TCR_b.CRST = 1)
#define TIM3_RESET_COUNTER  (TIM3->TCR_b.CRST = 1)

#define TIM6_START  (TIM6->TCR_b.CEN = 1)
#define TIM7_START  (TIM7->TCR_b.CEN = 1)
#define TIM6_STOP  (TIM6->TCR_b.CEN = 0)
#define TIM7_STOP  (TIM7->TCR_b.CEN = 0)
#define TIM6_RESET_COUNTER  (TIM6->TCR_b.CRST = 1)
#define TIM7_RESET_COUNTER  (TIM7->TCR_b.CRST = 1)


void TIM0_Init(TIM0_Type *ct, uint32_t tickpersecond);
void TIM0_ConfigMatch(TIM0_Type *ct, uint16_t ticks, uint8_t action);
void TIM0_SetTimerCounter(TIM0_Type *ct, uint16_t tick);
void TIM0_ResetTimerCounter(TIM0_Type *ct);
uint16_t TIM0_GetTimerCounter(TIM0_Type *ct);
void TIM0_ClearIntFlag(TIM0_Type *ct);
void TIM0_EnableInt(TIM0_Type *ct);
void TIM0_DisableInt(TIM0_Type *ct);

void TIM6_Init(TIM6_Type *ct, uint32_t tickpersecond);
void TIM6_SetCTType(TIM6_Type *ct, uint8_t mode);
void TIM6_SelectTimerClearSignal(TIM6_Type *ct, uint8_t capsignal, uint8_t edge);
void TIM6_SelectPriSrc(TIM6_Type *ct, uint8_t clksrc);
void TIM6_SelectSecSrc (TIM6_Type *ct, uint8_t clksrc, uint8_t polarity);
void TIM6_ConfigMatch0(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction);
void TIM6_ConfigMatch1(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction);
void TIM6_ConfigMatch2(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction);
void TIM6_ConfigMatch3(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction);
void TIM6_ConfigCapture0(TIM6_Type *ct, uint8_t edge, uint8_t intreq);
void TIM6_ConfigCapture1(TIM6_Type *ct, uint8_t edge, uint8_t intreq);
void TIM6_ConfigCapture2(TIM6_Type *ct, uint8_t edge, uint8_t intreq);
void TIM6_ConfigCapture3(TIM6_Type *ct, uint8_t edge, uint8_t intreq);
uint16_t TIM6_GetCapture0Value (TIM6_Type *ct);
uint16_t TIM6_GetCapture1Value (TIM6_Type *ct);
uint16_t TIM6_GetCapture2Value (TIM6_Type *ct);
uint16_t TIM6_GetCapture3Value (TIM6_Type *ct);
void TIM6_SetTimerCounter(TIM6_Type *ct, uint16_t ticks);
void TIM6_ResetTimerCounter(TIM6_Type *ct);
uint16_t TIM6_GetTimerCounter (TIM6_Type *ct);
void TIM6_ClearIntFlag(TIM6_Type *ct);
void TIM6_EnableInt(TIM6_Type *ct, uint8_t intbit);
void TIM6_DisableInt(TIM6_Type *ct, uint8_t intbit);
uint8_t TIM6_GetIntStatus(TIM6_Type *ct);
void TIM6_PWMInit(TIM6_Type *ct, uint32_t pwmfreqinhz);
void TIM6_EnablePWMOutput(TIM6_Type *ct, uint8_t pwmchannels);
void TIM6_DisablePWM(TIM6_Type *ct, uint8_t pwmchannels);
void TIM6_SetPWM0Duty(TIM6_Type *ct, uint8_t duty);
void TIM6_SetPWM1Duty(TIM6_Type *ct, uint8_t duty);
void TIM6_SetPWM2Duty(TIM6_Type *ct, uint8_t duty);
#endif /* end __TIMER_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
