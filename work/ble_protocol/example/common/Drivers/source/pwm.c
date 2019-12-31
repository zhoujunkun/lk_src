/*****************************************************************************
*   pwm.c:  source file for PWM module
*		ver 2.0
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "CMSDK_CM0.h"
#include "sys.h"
#include "pwm.h"
#include "ioconfig.h"

extern uint32_t SystemCoreClock;

/*****************************************************************************
** Function name:		PWM_Init
**
** Descriptions:		Init PWM Module
**
** parameters:			
**                	freq: PWM Frequency  
**									pair: PWM_COMPLEMENT,PWM_DEPENDENT
**									align: PWM_CENTER,PWM_EDGE
**                  polarity: PWM_POSITIVE,PWM_NEGATIVE
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_Init(uint32_t freq,uint8_t pair, uint8_t align, uint8_t polarity)
{
	uint32_t prescaler =0; //00 PWM Operation Clock Frequency;
													//01 PWM Operation Clock Frequency /2
													//10 PWM Operation Clock Frequency /4
													//11 PWM Operation Clock Frequency /8
	uint32_t minfreq;
	
	minfreq = SystemCoreClock/0xFFFF;
	
	if (!align)
		freq=freq<<1;
	
//	if ((minfreq>>3)>freq)
//		freq=minfreq; //fail to set freq
	
	//enable PWM clk
	SYSCON->SYSAHBCLKCTRL_b.PWM_CLK = 1;
	//reset PWM
	SYSCON->PRESETCTRL_b.PWM_RST_N=0;
	SYSCON->PRESETCTRL_b.PWM_RST_N=1;
	
	//Config 0-1,2-3,4-5,6-7 pair
	PWM->CNFG_b.NDEP01 = pair;
	PWM->CNFG_b.NDEP23 = pair;
	PWM->CNFG_b.NDEP45 = pair;
	PWM->CNFG_b.NDEP67 = pair;
	if (pair==PWM_COMPLEMENT)
	{
		//0-1,2-3,4-5 pair
		PWM->CTRL_b.IPOL0 = 0;	// VAL0
		PWM->CTRL_b.IPOL1 = 0;	// VAL2
		PWM->CTRL_b.IPOL2 = 0;	// VAL4
		PWM->CTRL_b.IPOL3 = 0;	// VAL6	
		PWM->DTIM0 = 0;					// Dead time is 0
		PWM->DTIM1 = 0;					// Dead time is 0
	}
	
	PWM->CNFG_b.TOPNEG01 = polarity;
	PWM->CNFG_b.BOTNEG01 = 0;
	PWM->CNFG_b.TOPNEG23 = polarity;
	PWM->CNFG_b.BOTNEG23 = 0;
	PWM->CNFG_b.TOPNEG45 = polarity;
	PWM->CNFG_b.BOTNEG45 = 0;
	PWM->CNFG_b.TOPNEG67 = polarity;
	PWM->CNFG_b.BOTNEG67 = 0;	
	//Cofig PMW as Center-Aligned or Edge-Aligned
	PWM->CNFG_b.EDG = align;

	//set modulu register, to generate freq Hz wave form
	//Set prescaler
	while (minfreq>freq)
	{
		freq =freq<<1;
		prescaler++;
	}
	PWM->PRESC =prescaler;
//	PWM->CMOD = SystemCoreClock/freq;
	PWM->CMOD = (*(uint32_t*)0x1fff141c)/(freq*SYSCON->SYSAHBCLKDIV);
	if ((*(uint32_t*)0x1fff141c-freq*PWM->CMOD)>(freq>>1))
		PWM->CMOD=PWM->CMOD+1;
	
	//Complement,define PWM out pair
	PWM->PSCR_b.CINV0 = polarity;
	PWM->PSCR_b.CINV1 = polarity;
	PWM->PSCR_b.CINV2 = polarity;
	PWM->PSCR_b.CINV3 = polarity;
	PWM->PSCR_b.CINV4 = polarity;
	PWM->PSCR_b.CINV5 = polarity;
	PWM->PSCR_b.CINV6 = polarity;
	PWM->PSCR_b.CINV7 = polarity;	

	//Intial phase
	PWM->CNTRINI_b.INITVAL = 0;
	
	//Load Value
	PWM->CTRL_b.LDOK = 1;
}

/*****************************************************************************
** Function name:		PWM_DeInit
**
** Descriptions:		De_Initial PWM module
**
** parameters:			none
**                	
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_DeInit(void)
{
	//Disable PWM clk
	SYSCON->SYSAHBCLKCTRL_b.PWM_CLK = 0;
}

/*****************************************************************************
** Function name:		PWM_SetRelaodFreq
**
** Descriptions:		set PWM reload frequency
**
** parameters:			
**                	  
**									everytimes: how much time to reload
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_SetRelaodFreq(uint8_t everytimes)
{
	PWM->CTRL_b.LDFQ = everytimes;
}

/*****************************************************************************
** Function name:		PWM_SetRelaodFreq
**
** Descriptions:		Set PWM Duty
** parameters:			
**                	channelindex: PWM0~PWM7 
**									dutyval: 0-100
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_SetDuty(uint8_t channelindex, uint16_t dutyinpercentage)
{
	uint8_t i;
	uint32_t temp;
	
	temp=PWM->CMOD;
	
	for (i=0;i<8;i++)
	{
		if ((channelindex & (1<<i)) != 0)
		{
			switch (i)
			{
				case 0:
					PWM->VAL0 = (temp*dutyinpercentage)/100;
					break;
				case 1:
					PWM->VAL1 = (temp*dutyinpercentage)/100;
					break;
				case 2:
					PWM->VAL2 = (temp*dutyinpercentage)/100;
					break;
				case 3:
					PWM->VAL3 = (temp*dutyinpercentage)/100;
					break;
				case 4:
					PWM->VAL4 = (temp*dutyinpercentage)/100;
					break;
				case 5:
					PWM->VAL5 = (temp*dutyinpercentage)/100;
					break;
				case 6:
					PWM->VAL6 = (temp*dutyinpercentage)/100;
					break;
				case 7:
					PWM->VAL7 = (temp*dutyinpercentage)/100;
					break;
				default:
					break;
			}
		}
	}
	
	PWM->CTRL_b.LDOK = 1;
}

/*****************************************************************************
** Function name:		PWM_SetRiseDeadZone
**
** Descriptions:		odd channel on rising edge
**
** parameters:			
**                	
**									us: deadtime us
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_SetRiseDeadZone(uint16_t us)
{
	uint32_t temp;
	
	temp=SystemCoreClock>>PWM->CTRL_b.PRSC;
	PWM->DTIM0 = (temp*us)/1000000;
}


/*****************************************************************************
** Function name:		PWM_SetFallDeadZone
**
** Descriptions:		odd channel on falling edge
**
** parameters:			
**                	
**									rdtimeticks: deadtime us
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_SetFallDeadZone(uint16_t us)
{
	uint32_t temp;
	
	temp=SystemCoreClock>>PWM->CTRL_b.PRSC;
	PWM->DTIM1 = (temp*us)/1000000;;
}

/*****************************************************************************
** Function name:		PWM_EnableFaultProtect
**
** Descriptions:		Set PWM fault type and  interrupt
**
** parameters:			
**                	
**										faults: 		PWMFAULT, ADCFAULT, SWFAULT
**										cleartype:	PWM_MANUAL, PWM_AUTOMATIC
**										faultint:		DISINT, ENINT
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_EnableFaultProtect(uint8_t faults, uint8_t cleartype, uint8_t faultint)
{
	switch(faults)
	{
		case 0:
			PWM->FCTRL_b.FMODE0 = cleartype;
			PWM->FCTRL_b.FIE0 = faultint;
			break;
		case 1:
			PWM->FCTRL_b.FMODE1 = cleartype;
			PWM->FCTRL_b.FIE1 = faultint;
			break;
		case 2:
			PWM->FCTRL_b.FMODE2 = cleartype;
			PWM->FCTRL_b.FIE2 = faultint;
			break;
		default:
			break;
	}
}

/*****************************************************************************
** Function name:		PWM_ClearFault
**
** Descriptions:		Clear PWM fault signal 
**
** parameters:			
**                	
**										none
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_ClearFault(void)
{
	PWM->FLTACK_b.FTACK0 = 1;
	PWM->FLTACK_b.FTACK1 = 1;
	PWM->FLTACK_b.FTACK2 = 1;
}

/*****************************************************************************
** Function name:		PWM_Start
**
** Descriptions:		Enable PWM output
**
** parameters:			
**                	
**										none
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_Start(void)
{
	// Enable PWM
	PWM->CTRL_b.PWMEN = 1;

	//enable PWM0_0~7 pwm pad output
	PWM->ICCTRL_b.PAD_EN = 1;
	
	//Load value
	PWM->CTRL_b.LDOK = 1;
}

/*****************************************************************************
** Function name:		PWM_Stop
**
** Descriptions:		Disable PWM output
**
** parameters:			
**                	
**										none
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_Stop(void)
{
	// Disable PWM
	PWM->CTRL_b.PWMEN = 0;

	//Disable PWM0_0~7 pwm pad output
	PWM->ICCTRL_b.PAD_EN = 0;
}

/*****************************************************************************
** Function name:		PWM_Stop
**
** Descriptions:		Enable PWM Relaod Interrupt
**
** parameters:			
**                	
**										inttype: PWM_FULLINT, PWM_HALFINT
**
** Returned value:		none
** 
*****************************************************************************/
void	PWM_EnableInt(uint8_t inttype)
{
	PWM->CTRL_b.PWMRIE = 1;
	PWM->CTRL_b.HALF = inttype;
}


/******************************************************************************
**                            End Of File
******************************************************************************/
