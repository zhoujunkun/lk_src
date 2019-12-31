/*****************************************************************************
*   pwm.h:  Header file for pwm.c
*		ver 2.0
******************************************************************************/

#ifndef __PWM_H 
#define __PWM_H
#include "CMSDK_CM0.h"

// PWM out pair
#define	PWM_COMPLEMENT							0
#define	PWM_DEPENDENT								1

// Align type
#define	PWM_CENTER_ALIGN						0
#define	PWM_EDGE_ALIGN							1

// PWM polarity
#define	PWM_POSITIVE								0
#define	PWM_NEGATIVE								1

// PWM PIN assignment
#define PWM0		0x01
#define PWM1 		0x02
#define PWM2 		0x04
#define PWM3		0x08
#define PWM4 		0x10
#define PWM5 		0x20
#define PWM6 		0x40
#define PWM7 		0x80
// interrupt type
#define	PWM_FULLINT									0
#define	PWM_HALFINT									1

// PWM fault type
#define	PWM_FAULT										0
#define	PWM_ADC_FAULT								1
#define	PWM_SW_FAULT								2

//PWM fault clear type
#define	PWM_FAULT_MANUAL_CLR				0
#define	PWM_FAULT_AUTO_CLR					1

//Interrupt Enable or Disble
#define	PWM_DISABLE_INT							0
#define	PWM_ENABLE_INT							1
//Duty vale
#define	PWM0_VAL 										(PWM->VAL0)
#define	PWM1_VAL 										(PWM->VAL1)
#define	PWM2_VAL 										(PWM->VAL2)
#define	PWM3_VAL 										(PWM->VAL3)
#define	PWM4_VAL 										(PWM->VAL4)
#define	PWM5_VAL 										(PWM->VAL5)
#define	PWM6_VAL 										(PWM->VAL6)
#define	PWM7_VAL 										(PWM->VAL7)

//PWM Trigger Signal Config
#define EVERY_TRIG_SIGNAL 					0
#define EVERY_TWO_TRIG_SIGNAL 			1
#define EVERY_THREE_TRIG_SIGNAL 		2
#define EVERY_FOUR_TRIG_SIGNAL 			3
#define TRIGGER_AT_RELOAD 					0
#define TRIGGER_AT_CH_RISE_EDGE 		1
#define TRIGGER_AT_HALF_RELOAD 			2
#define TRIGGER_AT_CH_FALL_EDGE 		3

#define SelectPWMTriggerFreq(freq) 	(PWM->CTRL_b.TSCNT=freq)
#define SelectPWMTriggerMode(mode) 	(PWM->CTRL_b.TSSEL=mode)
#define EnablePWM0Trigger 					(PWM->CTRL_b.CH0OUTEN=1)
#define DisablePWM0Trigger 					(PWM->CTRL_b.CH0OUTEN=0)
#define EnablePWM1Trigger 					(PWM->CTRL_b.CH1OUTEN=1)
#define DisablePWM1Trigger 					(PWM->CTRL_b.CH1OUTEN=0)
#define EnablePWM2Trigger 					(PWM->CTRL_b.CH2OUTEN=1)
#define DisablePWM2Trigger 					(PWM->CTRL_b.CH2OUTEN=0)
#define EnablePWM3Trigger 					(PWM->CTRL_b.CH3OUTEN=1)
#define DisablePWM3Trigger 					(PWM->CTRL_b.CH3OUTEN=0)
#define EnablePWM4Trigger 					(PWM->CTRL_b.CH4OUTEN=1)
#define DisablePWM4Trigger 					(PWM->CTRL_b.CH4OUTEN=0)
#define EnablePWM5Trigger 					(PWM->CTRL_b.CH5OUTEN=1)
#define DisablePWM5Trigger 					(PWM->CTRL_b.CH5OUTEN=0)
#define EnablePWM6Trigger 					(PWM->CTRL_b.CH6OUTEN=1)
#define DisablePWM6Trigger 					(PWM->CTRL_b.CH6OUTEN=0)
#define EnablePWM7Trigger 					(PWM->CTRL_b.CH7OUTEN=1)
#define DisablePWM7Trigger 					(PWM->CTRL_b.CH7OUTEN=0)
#define EnablePWM0Output   					(PWM->CCTRL_b.MSK0=0)
#define EnablePWM1Output   					(PWM->CCTRL_b.MSK1=0)
#define EnablePWM2Output   					(PWM->CCTRL_b.MSK2=0)
#define EnablePWM3Output   					(PWM->CCTRL_b.MSK3=0)
#define EnablePWM4Output   					(PWM->CCTRL_b.MSK4=0)
#define EnablePWM5Output   					(PWM->CCTRL_b.MSK5=0)
#define EnablePWM6Output   					(PWM->CCTRL_b.MSK6=0)
#define EnablePWM7Output   					(PWM->CCTRL_b.MSK7=0)
#define DisablePWM0Output   				(PWM->CCTRL_b.MSK0=1)
#define DisablePWM1Output   				(PWM->CCTRL_b.MSK1=1)
#define DisablePWM2Output   				(PWM->CCTRL_b.MSK2=1)
#define DisablePWM3Output   				(PWM->CCTRL_b.MSK3=1)
#define DisablePWM4Output   				(PWM->CCTRL_b.MSK4=1)
#define DisablePWM5Output   				(PWM->CCTRL_b.MSK5=1)
#define DisablePWM6Output   				(PWM->CCTRL_b.MSK6=1)
#define DisablePWM7Output   				(PWM->CCTRL_b.MSK7=1)

void PWM_IO_Init(void);
void PWM_Init(uint32_t freq,uint8_t pair, uint8_t align, uint8_t polarity);
void PWM_DeInit(void);
void PWM_SetRelaodFreq(uint8_t everytimes);
void PWM_SetDuty(uint8_t channelindex, uint16_t dutyval);
void PWM_SetRiseDeadZone(uint16_t rdtimeticks);
void PWM_SetFallDeadZone(uint16_t rdtimeticks);
void PWM_EnableFaultProtect(uint8_t faults, uint8_t cleartype, uint8_t faultint);
void PWM_ClearFault(void);
void PWM_Start(void);
void PWM_Stop(void);
void PWM_EnableInt(uint8_t inttype);

#endif /* end __PWM_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
