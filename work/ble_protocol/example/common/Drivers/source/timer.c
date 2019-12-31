/*****************************************************************************
*   timer.c:  source file for timer 
*		ver 1.0
******************************************************************************/

#include "CMSDK_CM0.h"

#include "timer.h"
#include "sys.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	TIM0_Init
Function Definition	void TIM0_Init(TIM0_Type *ct, uint32_t tickpersecond)
Function Description	Initial basic timer
Input Parameters	*ct: pointer to TIM0/TIM1
tickpersecond: timer count frequency, less than system clock
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM0_Init(TIM0_Type *ct, uint32_t tickpersecond)
{

	if (ct == TIM0)
	{
		SYSCON->SYSAHBCLKCTRL_b.TIM0_CLK=1;
		SYSCON->PRESETCTRL_b.TIM0_RST_N=0;
		SYSCON->PRESETCTRL_b.TIM0_RST_N=1;
	}
	else if (ct == TIM1)
	{
		SYSCON->SYSAHBCLKCTRL_b.TIM1_CLK=1;
		SYSCON->PRESETCTRL_b.TIM1_RST_N=0;
		SYSCON->PRESETCTRL_b.TIM1_RST_N=1;
	}	else 	if (ct == TIM2)
	{
		SYSCON->SYSAHBCLKCTRL_b.TIM2_CLK=1;
		SYSCON->PRESETCTRL_b.TIM2_RST_N=0;
		SYSCON->PRESETCTRL_b.TIM2_RST_N=1;
	}
	else if (ct == TIM3)
	{
		SYSCON->SYSAHBCLKCTRL_b.TIM3_CLK=1;
		SYSCON->PRESETCTRL_b.TIM3_RST_N=0;
		SYSCON->PRESETCTRL_b.TIM3_RST_N=1;
	}	else return;
	
	if (tickpersecond>SystemCoreClock)
			tickpersecond=SystemCoreClock;
	ct->PR_b.PRVAL=SystemCoreClock/tickpersecond;
	
	return;
}
/*****************************************************************************
Function Name	TIM0_ConfigMatch
Function Definition	void TIM0_ConfigMatch(TIM0_Type *ct, uint16_t ticks, uint8_t action)
Function Description	Setup Match
Input Parameters	*ct: pointer to TIM0/TIM1
ticks: match value
action: combination of following action when counter reach match value
	TIM_MATCH_TRIGGER_INT 0x1
	TIM_MATCH_RESET_COUNTER 0x2
	TIM_MATCH_STOP_COUNTER 0x4
	TIM_MATCH_DO_NOTHING 0x0
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM0_ConfigMatch(TIM0_Type *ct, uint16_t ticks, uint8_t action)
{
	ct->MR0_b.MATCH=ticks;
	ct->MCR=action;
	return;
}
/*****************************************************************************
Function Name	TIM0_SetTimerCounter
Function Definition	void TIM0_SetTimerCounter(TIM0_Type *ct, uint16_t tick)
Function Description	*ct: pointer to TIM0/TIM1
tick: set current value
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void TIM0_SetTimerCounter(TIM0_Type *ct, uint16_t tick)
{
	ct->PC_b.PCVAL=tick;
	return;
}
/*****************************************************************************
Function Name	TIM0_ResetTimerCounter
Function Definition	void TIM0_ResetTimerCounter(TIM0_Type *ct)
Function Description	Reset Timer Counter value
Input Parameters	*ct: pointer to TIM0/TIM1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM0_ResetTimerCounter(TIM0_Type *ct)
{
	ct->PC_b.PCVAL=0;
	return;
}
/*****************************************************************************
Function Name	TIM0_GetTimerCounter
Function Definition	uint16_t TIM0_GetTimerCounter(TIM0_Type *ct)
Function Description	Get current timer counter value
Input Parameters	*ct: pointer to TIM0/TIM1
Return Value	Timer Counter value
Condition	No
Function called	-

*****************************************************************************/
uint16_t TIM0_GetTimerCounter(TIM0_Type *ct)
{
	return ct->TC_b.TC;
}
/*****************************************************************************
Function Name	TIM0_ClearIntFlag
Function Definition	void TIM0_ClearIntFlag(TIM0_Type *ct)
Function Description	Clear Match event interrupt
Input Parameters	*ct: pointer to TIM0/TIM1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM0_ClearIntFlag(TIM0_Type *ct)
{
	ct->IR_b.MR0INT=1;
	return;
}
/*****************************************************************************
Function Name	TIM0_ClearIntFlag
Function Definition	void TIM0_ClearIntFlag(TIM0_Type *ct)
Function Description	Clear Match event interrupt
Input Parameters	*ct: pointer to TIM0/TIM1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM0_EnableInt(TIM0_Type *ct)
{
	ct->MCR_b.MR0I=1;
	NVIC_EnableIRQ(TIM0_IRQn);
	return;
}
/*****************************************************************************
Function Name	TIM0_DisableInt
Function Definition	void TIM0_DisableInt(TIM0_Type *ct)
Function Description	Disable Match event interrupt
Input Parameters	*ct: pointer to TIM0/TIM1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM0_DisableInt(TIM0_Type *ct)
{
	ct->MCR_b.MR0I=0;
	NVIC_DisableIRQ(TIM0_IRQn);
	return;	
}
/*****************************************************************************
Function Name	TIM6_Init
Function Definition	void TIM6_Init(TIM6_Type *ct, uint32_t tickpersecond)
Function Description	Initial timer
Input Parameters	*ct: pointer to TIM6/TIM7
tickpersecond: timer count frequency, less than system clock
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_Init(TIM6_Type *ct, uint32_t tickpersecond)
{
	if (ct == TIM6)
	{
		SYSCON->SYSAHBCLKCTRL_b.TIM6_CLK=1;
		SYSCON->PRESETCTRL_b.TIM6_RST_N=0;
		SYSCON->PRESETCTRL_b.TIM6_RST_N=1;
	}
	else if (ct == TIM7)
	{
		SYSCON->SYSAHBCLKCTRL_b.TIM7_CLK=1;
		SYSCON->PRESETCTRL_b.TIM7_RST_N=0;
		SYSCON->PRESETCTRL_b.TIM7_RST_N=1;
	}	else return;
	
	if (tickpersecond>SystemCoreClock)
			tickpersecond=SystemCoreClock;
	ct->PR_b.PCVAL=SystemCoreClock/tickpersecond-1;
	
	return;
}
/*****************************************************************************
Function Name	TIM6_SetCTType
Function Definition	void TIM6_SetCTType(TIM6_Type *ct, uint8_t mode)
Function Description	Initial timer/counter mode
Input Parameters	*ct: pointer to TIM6/TIM7
mode: counter/timer mode
			000 	Timer Mode, every PCLK
			001 	Counter Mode, Primary select signal rise edge
			010 	Counter Mode, Primary select signal fall edge 
			011 	Edge Count Mode  
			100	Quadrature mode
			101	Trigger count mode.
			110	Signed count mode.
			111	Gate count mode.
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_SetCTType(TIM6_Type *ct, uint8_t mode)
{
	ct->CTCR_b.CTM=mode;
	return;
}
/*****************************************************************************
Function Name	TIM6_SelectTimerClearSignal
Function Definition	void TIM6_SelectTimerClearSignal(TIM6_Type *ct, uint8_t capsignal, uint8_t edge)
Function Description	Select capture event to clear timer
Input Parameters	*ct: pointer to TIM6/TIM7
capsignal: capture signal
					0, CAP0
					1, CAP1
					2, CAP2
					4, CAP3
					5, Other Timer CAP0
					6, Other Timer CAP1
					7, Other Timer CAP2
					8, Other Timer CAP3
Edge: RISE_EDGE/FALL_EDGE
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_SelectTimerClearSignal(TIM6_Type *ct, uint8_t capsignal, uint8_t edge)
{
	//set counter clear singal
	ct->CTCR_b.SELCC=capsignal<<1;
	if (edge==FALL_EDGE)
			ct->CTCR_b.SELCC++;
	//enable counter clear action
	ct->CTCR_b.ENCC=1;
	return;
}	
/*****************************************************************************
Function Name	TIM6_SelectPriSrc
Function Definition	void TIM6_SelectPriSrc(TIM6_Type *ct, uint8_t clksrc)
Function Description	Initial basic timer
Input Parameters	*ct: pointer to TIM6/TIM7
clksrc: clock source
				0000	CAP0 pin
				0001	CAP1 pin
				0010	CAP2 pin
				0011	CAP3 pin
				0100	PWM Event
				0101	TIM6_MAT0./ TIM7_MAT0
				0110	Reserved
				0111	Reserved.
				1xxx	Prescale counter
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_SelectPriSrc(TIM6_Type *ct, uint8_t clksrc)
{
	ct->CTCR_b.PRISEL=clksrc;
	return;
}
/*****************************************************************************
Function Name	TIM6_SelectPriSrc
Function Definition	void TIM6_SelectSecSrc (TIM6_Type *ct, uint8_t clksrc, uint8_t polarity)
Function Description	Initial basic timer
Input Parameters	*ct: pointer to TIM6/TIM7
clksrc: clock source
				0000	CAP0 pin
				0001	CAP1 pin
				0010	CAP2 pin
				0011	CAP3 pin
				0100	PWM Event
				0101	TIM6_MAT0./ TIM7_MAT0
				0110	Reserved
				0111	Reserved.
				1xxx	Prescale counter
polarity: inverse clock source

Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_SelectSecSrc (TIM6_Type *ct, uint8_t clksrc, uint8_t polarity)
{
	ct->CTCR_b.SECSEL=clksrc;
	ct->CTCR_b.IPS=polarity;
	return;
}
/*****************************************************************************
Function Name	TIM6_ConfigMatch0
Function Definition	void TIM6_ConfigMatch0(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction)
Function Description	Setup timer match 0 and internal action when match even occurs
Input Parameters	*ct: pointer to TIM6/TIM7
ticks: match 0 value
internalaction: combination of following action when counter reach match value
               TIM_MATCH_TRIGGER_INT 0x1
               TIM_MATCH_RESET_COUNTER 0x2
               TIM_MATCH_STOP_COUNTER 0x4
               TIM_MATCH_DO_NOTHING 0x0 
externalaction: one of following action when counter reach match value
               TIM_MATCH_OUT_DO_NOTHING 0x0
               TIM_MATCH_OUT_RESET 0x1
               TIM_MATCH_OUT_SET	 0x2
               TIM_MATCH_OUT_TRIGGER_PLUS	 0x3

Return Value	No
Condition	No
Function called	-

Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ConfigMatch0(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction)
{
	ct->MR0_b.MATCH=ticks;
	
	ct->MCR=(ct->MCR&(~0x7))|(internalaction&0x7);
	
	ct->EMR_b.EMC0=externalaction;
	ct->EMR_b.EM0=1;	
	return;
}
/*****************************************************************************
Function Name	TIM6_ConfigMatch1
Function Definition	void TIM6_ ConfigMatch1(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction)
Function Description	Setup timer match 1 and internal action and TIM6_MAT1/ TIM6_MAT1 output external action when match even occurs
Input Parameters	*ct: pointer to TIM6/TIM7
ticks: match 1 value
internalaction: combination of following action when counter reach match value
			TIM_MATCH_TRIGGER_INT 0x1
			TIM_MATCH_RESET_COUNTER 0x2
			TIM_MATCH_STOP_COUNTER 0x4
			TIM_MATCH_DO_NOTHING 0x0 
externalaction: one of following action when counter reach match value
			TIM_MATCH_OUT_DO_NOTHING 0x0
			TIM_MATCH_OUT_RESET 0x1
			TIM_MATCH_OUT_SET	 0x2
			TIM_MATCH_OUT_TRIGGER_PLUS	 0x3
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ConfigMatch1(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction)
{
	ct->MR1_b.MATCH=ticks;
	ct->MCR=(ct->MCR&(~(0x7<<3)))|((internalaction&0x7)<<3);

	ct->EMR_b.EMC1=externalaction;
	ct->EMR_b.EM1=1;	
	return;
}	
/*****************************************************************************
Function Name	TIM6_ConfigMatch2
Function Definition	void TIM6_ConfigMatch2(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction)
Function Description	Setup timer match 2 and internal action and TIM6_MAT2/ TIM6_MAT2 output external action when match even occurs
Input Parameters	*ct: pointer to TIM6/TIM7
ticks: match 2 value
internalaction: combination of following action when counter reach match value
		TIM_MATCH_TRIGGER_INT 0x1
		TIM_MATCH_RESET_COUNTER 0x2
		TIM_MATCH_STOP_COUNTER 0x4
		TIM_MATCH_DO_NOTHING 0x0 
externalaction: one of following action when counter reach match value
		TIM_MATCH_OUT_DO_NOTHING 0x0
		TIM_MATCH_OUT_RESET 0x1
		TIM_MATCH_OUT_SET	 0x2
		TIM_MATCH_OUT_TRIGGER_PLUS	 0x3
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ConfigMatch2(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction)
{
	ct->MR2_b.MATCH=ticks;
	ct->MCR=(ct->MCR&(~(0x7<<6)))|((internalaction&0x7)<<6);
	
	ct->EMR_b.EMC2=externalaction;
	ct->EMR_b.EM2=1;		
	return;
}
/*****************************************************************************
Function Name	TIM6_ConfigMatch3
Function Definition	void TIM6_ConfigMatch3(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction)
Function Description	Setup timer match 3 and internal action and TIM6_MAT3/ TIM6_MAT3 output external action when match even occurs
Input Parameters	*ct: pointer to TIM6/TIM7
ticks: match 3 value
internalaction: combination of following action when counter reach match value
		TIM_MATCH_TRIGGER_INT 0x1
		TIM_MATCH_RESET_COUNTER 0x2
		TIM_MATCH_STOP_COUNTER 0x4
		TIM_MATCH_DO_NOTHING 0x0 
externalaction: one of following action when counter reach match value
		TIM_MATCH_OUT_DO_NOTHING 0x0
		TIM_MATCH_OUT_RESET 0x1
		TIM_MATCH_OUT_SET	 0x2
		TIM_MATCH_OUT_TRIGGER_PLUS	 0x3
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ConfigMatch3(TIM6_Type *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction)
{
	ct->MR1_b.MATCH=ticks;
	ct->MCR=(ct->MCR&(~(0x7<<9)))|((internalaction&0x7)<<9);
	
	ct->EMR_b.EMC3=externalaction;
	ct->EMR_b.EM3=1;			
	return;
}

/*****************************************************************************
Function Name	TIM6_ConfigCapture0
Function Definition	void TIM6_ConfigCapture0 (TIM6_Type *ct, uint8_t edge, uint8_t intreq)
Function Description	Set up Capture 0 
Input Parameters	*ct: pointer to TIM6/TIM7
edge: CAP0 signal edge, RISE_EDGE/FALL_EDGE/BOTH_EDGE. Deifned in sys.h
intreq: interrupt request
			TIM_CAPTURE_DO_NOTHING
			TIM_CAPTURE_TRIGGER_INT
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ConfigCapture0(TIM6_Type *ct, uint8_t edge, uint8_t intreq)
{
	switch(edge)
	{
		case RISE_EDGE:
				ct->CCR_b.CAP0RE=1;
				ct->CCR_b.CAP0FE=0;
			break;
		case FALL_EDGE:
				ct->CCR_b.CAP0RE=0;
				ct->CCR_b.CAP0FE=1;
			break;
		case BOTH_EDGE:
				ct->CCR_b.CAP0RE=1;
				ct->CCR_b.CAP0FE=1;
			break;
		default:
			break;
	}
	if (intreq==TIM_CAPTURE_TRIGGER_INT)
		ct->CCR_b.CAP0I=1;
	else
		ct->CCR_b.CAP0I=0;
	return;
}
/*****************************************************************************
Function Name	TIM6_ConfigCapture1
Function Definition	void TIM6_ConfigCapture1 (TIM6_Type *ct, uint8_t edge, uint8_t intreq)
Function Description	Set up Capture 1 
Input Parameters	*ct: pointer to TIM6/TIM7
edge: CAP0 signal edge, RISE_EDGE/FALL_EDGE/BOTH_EDGE. Deifned in sys.h
intreq: interrupt request
			TIM_CAPTURE_DO_NOTHING
			TIM_CAPTURE_TRIGGER_INT
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ConfigCapture1(TIM6_Type *ct, uint8_t edge, uint8_t intreq)
{
	switch(edge)
	{
		case RISE_EDGE:
				ct->CCR_b.CAP1RE=1;
				ct->CCR_b.CAP1FE=0;
			break;
		case FALL_EDGE:
				ct->CCR_b.CAP1RE=0;
				ct->CCR_b.CAP1FE=1;
			break;
		case BOTH_EDGE:
				ct->CCR_b.CAP1RE=1;
				ct->CCR_b.CAP1FE=1;
			break;
		default:
			break;
	}
	if (intreq==TIM_CAPTURE_TRIGGER_INT)
		ct->CCR_b.CAP1I=1;
	else
		ct->CCR_b.CAP1I=0;
	return;
}
/*****************************************************************************
Function Name	TIM6_ConfigCapture2
Function Definition	void TIM6_ConfigCapture2 (TIM6_Type *ct, uint8_t edge, uint8_t intreq)
Function Description	Set up Capture 2 
Input Parameters	*ct: pointer to TIM6/TIM7
edge: CAP0 signal edge, RISE_EDGE/FALL_EDGE/BOTH_EDGE. Deifned in sys.h
intreq: interrupt request
			TIM_CAPTURE_DO_NOTHING
			TIM_CAPTURE_TRIGGER_INT
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ConfigCapture2(TIM6_Type *ct, uint8_t edge, uint8_t intreq)
{
	switch(edge)
	{
		case RISE_EDGE:
				ct->CCR_b.CAP2RE=1;
				ct->CCR_b.CAP2FE=0;
			break;
		case FALL_EDGE:
				ct->CCR_b.CAP2RE=0;
				ct->CCR_b.CAP2FE=1;
			break;
		case BOTH_EDGE:
				ct->CCR_b.CAP2RE=1;
				ct->CCR_b.CAP2FE=1;
			break;
		default:
			break;
	}
	if (intreq==TIM_CAPTURE_TRIGGER_INT)
		ct->CCR_b.CAP2I=1;
	else
		ct->CCR_b.CAP2I=0;
	return;
}
/*****************************************************************************
Function Name	TIM6_ConfigCapture3
Function Definition	void TIM6_ConfigCapture3 (TIM6_Type *ct, uint8_t edge, uint8_t intreq)
Function Description	Set up Capture 3 
Input Parameters	*ct: pointer to TIM6/TIM7
edge: CAP0 signal edge, RISE_EDGE/FALL_EDGE/BOTH_EDGE. Deifned in sys.h
intreq: interrupt request
			TIM_CAPTURE_DO_NOTHING
			TIM_CAPTURE_TRIGGER_INT
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ConfigCapture3(TIM6_Type *ct, uint8_t edge, uint8_t intreq)
{
	switch(edge)
	{
		case RISE_EDGE:
				ct->CCR_b.CAP3RE=1;
				ct->CCR_b.CAP3FE=0;
			break;
		case FALL_EDGE:
				ct->CCR_b.CAP3RE=0;
				ct->CCR_b.CAP3FE=1;
			break;
		case BOTH_EDGE:
				ct->CCR_b.CAP3RE=1;
				ct->CCR_b.CAP3FE=1;
			break;
		default:
			break;
	}
	if (intreq==TIM_CAPTURE_TRIGGER_INT)
		ct->CCR_b.CAP3I=1;
	else
		ct->CCR_b.CAP3I=0;
	return;
}
/*****************************************************************************
Function Name	TIM6_GetCapture0Value
Function Definition	void TIM6_GetCapture0Value(TIM6_Type *ct)
Function Description	Return timer Capture 0 register value
Input Parameters	*ct: pointer to TIM6/TIM7
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
uint16_t TIM6_GetCapture0Value (TIM6_Type *ct)
{
	return ct->CR0_b.CAP;
}
/*****************************************************************************
Function Name	TIM6_GetCapture1Value
Function Definition	void TIM6_GetCapture1Value(TIM6_Type *ct)
Function Description	Return timer Capture 1 register value
Input Parameters	*ct: pointer to TIM6/TIM7
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
uint16_t TIM6_GetCapture1Value (TIM6_Type *ct)
{
	return ct->CR1_b.CAP;
}
/*****************************************************************************
Function Name	TIM6_GetCapture2Value
Function Definition	void TIM6_GetCapture2Value(TIM6_Type *ct)
Function Description	Return timer Capture 2 register value
Input Parameters	*ct: pointer to TIM6/TIM7
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
uint16_t TIM6_GetCapture2Value (TIM6_Type *ct)
{
	return ct->CR2_b.CAP;
}
/*****************************************************************************
Function Name	TIM6_GetCapture3Value
Function Definition	void TIM6_GetCapture3Value(TIM6_Type *ct)
Function Description	Return timer Capture 3 register value
Input Parameters	*ct: pointer to TIM6/TIM7
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
uint16_t TIM6_GetCapture3Value (TIM6_Type *ct)
{
	return ct->CR3_b.CAP;
}
/*****************************************************************************
Function Name	TIM6_SetTimerCounter
Function Definition	void TIM6_SetTimerCounter(TIM6_Type *ct, uint16_t ticks)
Function Description	Set timer counter current value
Input Parameters	*ct: pointer to TIM6/TIM7
tick: value to be set to current counter
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_SetTimerCounter(TIM6_Type *ct, uint16_t ticks)
{
	ct->TC_b.TC=ticks;
	return;
}
/*****************************************************************************
Function Name	TIM6_ResetTimerCounter
Function Definition	void TIM6_ResetTimerCounter(TIM6_Type *ct)
Function Description	Reset timer counter current value
Input Parameters	*ct: pointer to TIM6/TIM7
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ResetTimerCounter(TIM6_Type *ct)
{
	ct->TCR_b.CRST=1;
	return;
}
/*****************************************************************************
Function Name	TIM6_GetTimerCounter
Function Definition	uint16_tTIM6_GetTimerCounter (TIM6_Type *ct)
Function Description	Get timer counter current value
Input Parameters	*ct: pointer to TIM6/TIM7
Return Value	Current counter value
Condition	No
Function called	-

*****************************************************************************/
uint16_t TIM6_GetTimerCounter (TIM6_Type *ct)
{
	return ct->TC_b.TC;
}
/*****************************************************************************
Function Name	TIM6_ClearIntFlag
Function Definition	void TIM6_ClearIntFlag(TIM6_Type *ct)
Function Description	Clear interrupt
Input Parameters	*ct: pointer to TIM0/TIM1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_ClearIntFlag(TIM6_Type *ct)
{
	ct->IR=0xFF;
	return;
}
/*****************************************************************************
Function Name	TIM6_EnableInt
Function Definition	void TIM6_EnableInt(TIM6_Type *ct, uint8_t intbit)
Function Description	Enable event interrupt
Input Parameters	*ct: pointer to TIM6/TIM7
intbit: bit0~7 related match0~match3,capture0~capture3
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_EnableInt(TIM6_Type *ct, uint8_t intbit)
{
		ct->MCR_b.MR0I |= (intbit&1);
		ct->MCR_b.MR1I |= ((intbit>>1)&1);
		ct->MCR_b.MR2I |= ((intbit>>2)&1);
		ct->MCR_b.MR3I |= ((intbit>>3)&1);
		ct->CCR_b.CAP0I |= ((intbit>>4)&1);
		ct->CCR_b.CAP1I |= ((intbit>>5)&1);
		ct->CCR_b.CAP2I |= ((intbit>>6)&1);
		ct->CCR_b.CAP3I |= ((intbit>>7)&1);
}
/*****************************************************************************
Function Name	TIM6_DisableInt
Function Definition	void TIM6_DisableInt(TIM6_Type *ct, uint8_t intbit)
Function Description	Disable event interrupt
Input Parameters	*ct: pointer to TIM6/TIM7
intbit: bit0~7 related match0~match3,capture0~capture3
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TIM6_DisableInt(TIM6_Type *ct, uint8_t intbit)
{
		ct->MCR_b.MR0I &= ~(intbit&1);
		ct->MCR_b.MR1I &= ~((intbit>>1)&1);
		ct->MCR_b.MR2I &= ~((intbit>>2)&1);
		ct->MCR_b.MR3I &= ~((intbit>>3)&1);
		ct->CCR_b.CAP0I &= ~((intbit>>4)&1);
		ct->CCR_b.CAP1I &= ~((intbit>>5)&1);
		ct->CCR_b.CAP2I &= ~((intbit>>6)&1);
		ct->CCR_b.CAP3I &= ~((intbit>>7)&1);
}

uint8_t TIM6_GetIntStatus(TIM6_Type *ct)
{
	return (uint8_t)ct->IR;
}
void TIM6_PWMInit(TIM6_Type *ct, uint32_t pwmfreqinhz)
{
	uint32_t pwmmod;
	pwmmod=SystemCoreClock/(ct->PR_b.PCVAL*pwmfreqinhz);
	TIM6_ConfigMatch3(ct,pwmmod,TIM_MATCH_TRIGGER_INT|TIM_MATCH_RESET_COUNTER,TIM_MATCH_OUT_DO_NOTHING); 
}
void TIM6_EnablePWMOutput(TIM6_Type *ct, uint8_t pwmchannels)
{
	ct->PWMC |= (pwmchannels|1); //PWM0 must be enable
	
	return;
}
void TIM6_DisablePWM(TIM6_Type *ct, uint8_t pwmchannels)
{
	ct->PWMC &= ~pwmchannels;
	
	return;
}
void TIM6_SetPWM0Duty(TIM6_Type *ct, uint8_t duty)
{
	if (duty>100) return;
	if (duty==0)
		ct->MR0_b.MATCH=ct->MR3_b.MATCH+1;
	else if (duty==100)
		ct->MR0_b.MATCH=0;
	else
		ct->MR0_b.MATCH=ct->MR3_b.MATCH*(100-duty);
}
void TIM6_SetPWM1Duty(TIM6_Type *ct, uint8_t duty)
{
	if (duty>100) return;
	if (duty==0)
		ct->MR1_b.MATCH=ct->MR3_b.MATCH+1;
	else if (duty==100)
		ct->MR1_b.MATCH=0;
	else
		ct->MR1_b.MATCH=ct->MR3_b.MATCH*(100-duty);
}
void TIM6_SetPWM2Duty(TIM6_Type *ct, uint8_t duty)
{
	if (duty>100) return;
	if (duty==0)
		ct->MR2_b.MATCH=ct->MR3_b.MATCH+1;
	else if (duty==100)
		ct->MR2_b.MATCH=0;
	else
		ct->MR2_b.MATCH=ct->MR3_b.MATCH*(100-duty)/100;
}

