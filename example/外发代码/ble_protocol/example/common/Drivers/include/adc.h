/*****************************************************************************
*   adc.h:  Header file for adc.c
*		verr 1.1 add adc 8~11
******************************************************************************/

#ifndef __ADC_H 
#define __ADC_H

#include "CMSDK_CM0.h"

//AD channel sel
#define AD0 	0x0F
#define AD1 	0x01
#define AD2 	0x02
#define AD3 	0x03
#define AD4 	0x04
#define AD5 	0x05
#define AD6 	0x06
#define AD7 	0x07
#define AD8 	0x08
#define AD9 	0x09
#define AD10 	0x0A
#define AD11 	0x0B

//DR select
#define ADC_DR0SEL 	0
#define ADC_DR1SEL 	4
#define ADC_DR2SEL 	8
#define ADC_DR3SEL 	12
#define ADC_DR4SEL 	16
#define ADC_DR5SEL 	20
#define ADC_DR6SEL 	24
#define ADC_DR7SEL 	28

//DR int
#define ADC_DR0INT 	0x1
#define ADC_DR1INT 	0x2
#define ADC_DR2INT 	0x4
#define ADC_DR3INT 	0x8
#define ADC_DR4INT 	0x10
#define ADC_DR5INT 	0x20
#define ADC_DR6INT 	0x40
#define ADC_DR7INT 	0x80
#define ADC_GINT 		0x100

//DR index
#define ADC_DR0 	0x0
#define ADC_DR1 	0x1
#define ADC_DR2 	0x2
#define ADC_DR3 	0x3
#define ADC_DR4 	0x4
#define ADC_DR5 	0x5
#define ADC_DR6 	0x6
#define ADC_DR7 	0x7

//ADC mode
#define TRIGGERMODE 	0x0
#define BURSTMODE 		0x1

//ADC trigger option
#define ADC_NONE_START 0x0 							//No start (this value should be used when clearing PDN to 0).
#define ADC_START_BY_SOFTWAER 0x1 			//Start conversion now.
#define ADC_START_BY_TIM6_CAP0 0x2 		//Start conversion when the edge selected by bit 28 occurs on TIM6_CAP0.
#define ADC_START_BY_TIM6_CAP1 0x3 		//Start conversion when the edge selected by bit 28 occurs on TIM6_CAP1.
#define ADC_START_BY_TIM6_MAT0 0x4 		//Start conversion when the edge selected by bit 28 occurs on TIM6_MAT0.
#define ADC_START_BY_TIM6_MAT1 0x5 		//Start conversion when the edge selected by bit 28 occurs on TIM6_MAT1.
#define ADC_START_BY_TIM7_MAT0 0x6 		//Start conversion when the edge selected by bit 28 occurs on TIM7_MAT0.
#define ADC_START_BY_TIM7_MAT1 0x7 		//Start conversion when the edge selected by bit 28 occurs on TIM7_MAT1.
#define ADC_START_BY_PWM 0x8 						//Start conversion when PWM1 cycle Reload,

//ADC trigger signal edge
#define ADC_TRIGGER_RISE_EDGE 0x0
#define ADC_TRIGGER_FALL_EDGE 0x1

#define   ADC_IssueSoftTrigger 		(ADC->SSCR_b.ADCTRIG = 1)
#define   ADC_EnableHighCmp0Int 	(ADC->HILMT_b.INTEN0 = 1)
#define   ADC_EnableHighCmp1Int 	(ADC->HILMT_b.INTEN1 = 1)
#define   ADC_EnableLowCmp0Int 		(ADC->LOLMT_b.INTEN0 = 1)
#define   ADC_EnableLowCmp1Int 		(ADC->LOLMT_b.INTEN1 = 1)
#define   ADC_DisableHighCmp0Int 	(ADC->HILMT_b.INTEN0 = 0)
#define   ADC_DisableHighCmp1Int 	(ADC->HILMT_b.INTEN1 = 0)
#define   ADC_DisableLowCmp0Int 	(ADC->LOLMT_b.INTEN0 = 0)
#define   ADC_DisableLowCmp1Int 	(ADC->LOLMT_b.INTEN1 = 0)

void ADC_Init(uint32_t conversionrate);
void ADC_DeInit(void);
void ADC_SetupChannels (uint32_t channelassign, uint32_t triggermode);
void ADC_SetTrigger(uint8_t triggersrc, uint8_t edge);
void ADC_SetHighCmp0(uint32_t val, uint8_t selchannel);
void ADC_SetHighCmp1(uint32_t val, uint8_t selchannel);
void ADC_SetLowCmp0 (uint32_t val, uint8_t selchannel);
void ADC_SetLowCmp1 (uint32_t val, uint8_t selchannel);
void ADC_EnableConversionInt(uint32_t inttype);
uint32_t ADC_GetConversionData(uint8_t dr);


#endif /* end __ADC_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
