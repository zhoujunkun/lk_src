/*****************************************************************************
*   sys.c:  source file for system control
*		ver 2.0
******************************************************************************/

#include "CMSDK_CM0.h"
#include "system_CMSDK.h"
#include "sys.h"
#include "ioconfig.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	SYS_SystemInitial
Function Definition	void SYS_SystemInitial(void)
Function Description	Initial system-configure as needed
Input Parameters	None
Return Value	None
Condition	No
Function called	-

*****************************************************************************/
void SYS_SystemInitial(void)
{
	//Patch
	//40MHZ
	if (DIA->IRCTRIM!=0xFFFFFFFF)
	SYSCON->IRCCTRL=DIA->IRCTRIM; //Redo trim to IRC to make sure IRC working on right frequency in debug mode
	//48MHZ
//	if (DIA->IRCTRIM48!=0xFFFFFFFF)
//	SYSCON->IRCCTRL=DIA->IRCTRIM48; //Redo trim to IRC to make sure IRC working on right frequency in debug mode


	TOUCH->CTRL |=0x10; //select internal touch resister, remove effect to PA_15 and PB_3
	LCD->LCDOUTEN0=0;
	LCD->LCDOUTEN1=0;	
	//Configure WDT clock if need

}
/*****************************************************************************
Function Name	SYS_IRCTrimto40M
Function Definition	void SYS_SYS_IRCTrimto40M(void)
Function Description	Setup IRC 40Mhz Trim value
Input Parameters	None
Return Value	None
Condition	No
Function called	-

*****************************************************************************/
void SYS_IRCTrimto40M(void)
{
	uint32_t i=0xFFFF;
	if (DIA->IRCTRIM!=0xFFFFFFFF)
	{
		SYSCON->IRCCTRL=DIA->IRCTRIM; 
		SystemCoreClockUpdate ();
	}
	while(i--==0);
}
/*****************************************************************************
Function Name	SYS_IRCTrimto48M
Function Definition	void SYS_SYS_IRCTrimto48M(void)
Function Description	Setup IRC 40Mhz Trim value
Input Parameters	None
Return Value	None
Condition	No
Function called	-

*****************************************************************************/
void SYS_IRCTrimto48M(void)
{
	uint32_t i=0xFFFF;
	if (DIA->IRCTRIM48!=0xFFFFFFFF)
	{
		SYSCON->IRCCTRL=DIA->IRCTRIM48; 
		SystemCoreClockUpdate ();
	}
	while(i--==0);
}

/*****************************************************************************
Function Name	SYS_SelectMainClkSrc
Function Definition	Void SYS_SelectMainClkSrc(uint8_t src)
Function Description	Select Main clcok source
Input Parameters	src:IRC_CLK
								WDT_CLK
								PLL_CLK
Other are invalid
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_SelectMainClkSrc(uint8_t src)
{
	//switch main clk source
	SYSCON->MAINCLKUEN_b.ENA= 1;					//disable main clk update
	//switch main clk source to Specifyed source
	if (src==IRC_CLK)
		SYSCON->MAINCLKSEL_b.SEL=0;
	else if (src==WATCHDOG_CLK)
		SYSCON->MAINCLKSEL_b.SEL=2; 
		else if (src==PLL_CLK)
			SYSCON->MAINCLKSEL_b.SEL=1; 
			
	SYSCON->MAINCLKUEN_b.ENA=0; 						//enable main clk update
	
	SystemCoreClockUpdate ();
	return;
}
/*****************************************************************************
Function Name	SYS_SetAHBClkDivider
Function Definition	Void SYS_SetAHBClkDivider (uint8_t div)
Function Description	Set divider, that divides the main clock to provide the system clock to the core, memories,and the peripherals.
Input Parameters	div:1~255, 0 is forbidented
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_SetAHBClkDivider (uint8_t div)
{
	//setup flash access speed if SystemCoreClock is going tomore than 30MHz
 	if ((SYSCON->MAINCLKSEL_b.SEL==0)&&(div<2))
 			FMC->FLASH_RDCYC = 1;
	//setup ahb clock divider
	SYSCON->SYSAHBCLKDIV_b.DIV = div;
	//update MainClock and SystemCoreClock
	SystemCoreClockUpdate ();   
	return;
}
/*****************************************************************************
Function Name	SYS_SelectWDTClkSrc
Function Definition	Void SYS_SelectWDTClkSrc(uint8_t src)
Function Description	Select clock source as WDT counter clock.
Input Parameters	src:IRC_CLK
											WDT_CLK
Other are invalid
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_SelectWDTClkSrc(uint8_t src)
{
	if (src==IRC_CLK)
		SYSCON->WDTOSCCTRL_b.WDTCLKSRC = 0;
	else if (src==WATCHDOG_CLK)
		SYSCON->WDTOSCCTRL_b.WDTCLKSRC = 1;
 
	return;
}

/*****************************************************************************
Function Name	SYS_SelectClkOutSrc
Function Definition	SYS_SelectClkOutSrc(uint8_t src)
Function Description	Select clock source as clock output
Input Parameters	src:IRC_CLK
											SYS_CLK
											WDT_CLK
											MAIN_CLK
											RTC_CLK
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_SelectClkOutSrc(uint8_t src)
{
	switch (src)
	{
		case IRC_CLK:
			src=0;
		break;
		case SYS_CLK:
			src=1;
		break;
		case WATCHDOG_CLK:
			src=2;
		break;
		case MAIN_CLK:
			src=3;
		break;

		default:
			return;
	}
	//switch clock
	SYSCON->CLKOUTUEN_b.ENA = 1;
	SYSCON->CLKOUTCLKSEL_b.SEL = src; 	//select clk out source
	SYSCON->CLKOUTUEN_b.ENA = 0;
 
	return;
}

/*****************************************************************************
Function Name	SYS_SetClkOutDivider
Function Definition	SYS_SetClkOutDivider(uint8_t src)
Function Description	Select clock source as clock output
Input Parameters	div:Clock output divider, valid 1~255 
											0: clock is disable
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_SetClkOutDivider(uint8_t div)
{
	SYSCON->CLKOUTDIV_b.DIV = div;
 
	return;
}

/*****************************************************************************
Function Name	SYS_EnableClkOut
Function Description	Enable clock output
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_EnableClkOut(void)
{
	PC_13_INIT(PC_13_CLKOUT);   							//enable clock out pin 
//	PC_8_INIT(PC_8_CLKOUT);   							//enable clock out pin 
	return;
}

/*****************************************************************************
Function Name	SYS_DisableClkOut
Function Definition	Void SYS_DisableClkOut(void)
Function Description	Disable clock output
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_DisableClkOut(void)
{
	SYSCON->CLKOUTDIV_b.DIV = 0;						//disable clock out
	PC_13_INIT(PC_13_GPIO);   							//recover IO pin to GPIO 
 
	return;
}
/*****************************************************************************
Function Name	SYS_SetIOFilter
Function Definition	Void SYS_SetIOFilter(uint8_t ticks)
Function Description	Set IO filter 
Input Parameters	Ticks: 	1~255, every ticks sample IO input, SystemCoreClock tick
													0, no sample
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_SetIOFilter(uint8_t ticks)
{
	SYSCON->IOCONFIGCLKDIV_b.DIV = ticks;
 
	return;
}
/*****************************************************************************
Function Name	SYS_PowerDownAngIP
Function Definition	SYS_PowerDownAngIP(uint32_t angips)
Function Description	Shut down specific analog IPs power supply
Input Parameters	Angips: analog IPs bit
Valid bit values are PD_IRC, PD_BOD, PD_ADC, PD_WDTOSC, PD_LCD, PD_TOUCH
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_PowerDownAngIP(uint32_t angips)
{
	SYSCON->PDRUNCFG |= angips;
 
	return;
}
/*****************************************************************************
Function Name	SYS_PowerUpAngIP
Function Definition	SYS_PowerUpAngIP(uint32_t angips)
Function Description	Power up specific analog IPs power supply
Input Parameters	Angips: analog IPs bit 
Valid bit values are PD_IRC, PD_BOD, PD_ADC,  PD_WDTOSC, PD_LCD, PD_TOUCH
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_PowerUpAngIP(uint32_t angips)
{
	SYSCON->PDRUNCFG &= ~angips;
 
	return;
}
/*****************************************************************************
Function Name	SYS_EnablePhrClk
Function Definition	void SYS_EnablePhrClk(uint32_t phrs)
Function Description	Enable specific peripherals clock
Input Parameters	phrs: peripherals clock bit 
Valid bit values are AHB_TWS, AHB_CRC, AHB_TIM0, AHB_TIM1, AHB_TIM6, 
	AHB_TIM7, AHB_SPI, AHB_UART0, AHB_UART1,AHB_ADC, AHB_WDT, AHB_IOCON, 
	AHB_PWM,AHB_LCD, AHB_RTC,AHB_TOUCH 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_EnablePhrClk(uint32_t phrs)
{
	SYSCON->SYSAHBCLKCTRL |= phrs;
 
	return;
}
/*****************************************************************************
Function Name	SYS_DisablePhrClk
Function Definition	void SYS_DisablePhrClk(uint32_t phrs)
Function Description	Disable specific peripherals clock
Input Parameters	phrs: peripherals clock bit 
Valid bit values are AHB_TWS, AHB_CRC, AHB_TIM0, AHB_TIM1, AHB_TIM6, 
AHB_TIM7, AHB_SPI, AHB_UART0, AHB_UART1,AHB_ADC, AHB_WDT, AHB_IOCON, 
AHB_PWM,AHB_LCD, AHB_RTC,AHB_TOUCH 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_DisablePhrClk(uint32_t phrs)
{
	SYSCON->SYSAHBCLKCTRL &= ~phrs;
 
	return;
}
/*****************************************************************************
Function Name	SYS_ResetPhr
Function Definition	void SYS_ResetPhr(uint32_t phrs)
Function Description	Reset specific peripherals 
Input Parameters	phrs: peripherals clock bit 
Valid bit values are RTS_TWS, RST_CRC, RST_TIM0, RST_TIM1,RST_TIM2, RST_TIM3, RST_TIM6, 
RST_TIM7, RST_SPI, RST_UART0, RST_UART1,RST_ADC, RST_WDT, 
RST_IOCON, RST_PWM,RST_LCD, RST_TOUCH 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_ResetPhr(uint32_t phrs)
{
	SYSCON->PRESETCTRL &= ~phrs;
	SYSCON->PRESETCTRL |= phrs;
	return;
}
/*****************************************************************************
Function Name	SYS_ResetSystem
Function Definition	void SYS_ResetSystem(void)
Function Description	Software Reset system
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_ResetSystem(void)
{
	NVIC_SystemReset();
}
/*****************************************************************************
Function Name	SYS_BODResetSystem
Function Definition	void SYS_BODResetSystem (uint8_t bodsel)
Function Description	Enable BOD and config BOD Reset option
Input Parameters	Bodsel: 
BOD_INT
BOD_RESET
Other values are invalid
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_BODResetSystem (uint8_t bodsel)
{
	if (bodsel==BOD_RESET)
	{
		SYSCON->BODCTRL_b.BODRSTEN=1 ;
	}
	else
	{
		SYSCON->BODCTRL_b.BODRSTEN = 0 ;
		SYSCON->BODCTRL_b.BODINTCLR = 1;
	}
	return;
}

/*****************************************************************************
Function Name	SYS_EnterSleep
Function Definition	void SYS_EnterSleep (void)
Function Description	Enter sleep mode
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_EnterSleep (void)
{
	//Sleep
	PMU->PCON_b.DPDEN = 0;			//sleep
	SCB->SCR &= ~(1<<2);							//sleep
	
	//issue sleep command
	__WFI();	//enter sleep
	return;
}
void SYS_EnterDeepSleep (void)
{
	volatile uint32_t loops;
	
	SYSCON->PDRUNCFG_b.WDTOSC_PD=0; //power up WDT 32K OSC
	loops=0xFF;
	while(loops--);
	//shutdown analog
	SYSCON->PDRUNCFG_b.LCD_PD=1;
	SYSCON->PDRUNCFG_b.ADC_PD=1;
	SYSCON->PDRUNCFG_b.BOD_PD=1;
	SYSCON->PDRUNCFG_b.TOUCH_PD=1;
	SYSCON->PDRUNCFG|=0x200;
	SYSCON->PDRUNCFG&=~(0x20);
	//mainclock switch to wdt 32k clock
	SYSCON->MAINCLKUEN_b.ENA=1;
	SYSCON->MAINCLKSEL_b.SEL=2;
	SYSCON->MAINCLKUEN_b.ENA=0;
	//shutdown IRC
	SYSCON->PDRUNCFG_b.IRC_PD=1;
	//prepare sleep
	PMU->PCON_b.DPDEN = 0;			
	SCB->SCR &= ~(1<<2);			
	//issue sleep command
	__WFI();	//enter sleep
	//mainclock switch back to IRC
	SYSCON->PDRUNCFG_b.IRC_PD=0;
	loops=0xFF;
	while(loops--);	
	SYSCON->MAINCLKUEN_b.ENA=1;
	SYSCON->MAINCLKSEL_b.SEL=0;
	SYSCON->MAINCLKUEN_b.ENA=0;
		
	return;
}
/*****************************************************************************
Function Name	SYS_EnterPowerDown
Function Definition	void SYS_EnterPowerDown (void)
Function Description	Enter sleep mode
Input No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_EnterPowerDown(void)
{
	//Power Down
	PMU->PCON_b.DPDEN = 1;
	
	SCB->SCR |= (1<<2);	//Power Down	
	
	__WFI();	//enter power down
}
/*****************************************************************************
Function Name	SYS_DelaymS
Function Definition	void SYS_DelaymS(uint32_t ms)
Function Description	Delay n mS
Input No. of mS
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_DelaymS(uint32_t ms)
{
	uint32_t i;
	i=ms*(SystemCoreClock/7870); 
	while(i--!=0);
}
/*****************************************************************************
Function Name	SYS_DelayuS
Function Definition	void SYS_DelayuS(uint32_t us)
Function Description	Delay n uS
Input No. of uS
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void SYS_DelayuS(uint32_t us)
{
	uint32_t i;
	if (us<=100)
		i=us*(SystemCoreClock)/7900000;
	else
		i=us*(SystemCoreClock/7820000);
	while(i--!=0);
}
/*****************************************************************************
Function Name	SYS_Delay
Function Definition	void SYS_Delay(uint32_t loops)
Function Description	Delay 
Input No. of loops
Return Value	No
Condition	No
Function called	-

*****************************************************************************/	
void SYS_Delay(uint32_t loops)
{
	while(loops--!=0);
}
/*****************************************************************************
Function Name	SYS_ExtOSCSetup
Function Definition	Void SYS_ExtOSCSetup(uint32_t extoscfreq,uint32_t plloutputfreq)
Function Description	Set External OSC and PLL
Input Parameters	extoscfreq:external input OSC frequency 6~60Mhz
									plloutputfreq:PLL output frequency 3~60Mhz
Other are invalid
Return Value	0: OK; 1: FAIL
Condition	No
Function called	-
Fout=Fin*(M/N)*(1/2OD)
Fin/N shall be in 6~20Mhz
Fin*M/N shall be in 24~60Mhz
*****************************************************************************/
uint8_t SYS_ExtOSCSetup(uint32_t extoscfreq,uint32_t plloutputfreq)
{
	if ((extoscfreq>60000000)||(extoscfreq<6000000)||(plloutputfreq>60000000)||(plloutputfreq<3000000))
		return 1;
	//powerup ext osc
	SYSCON->PDRUNCFG_b.EXTOSC_PD=1;
	//power up pll
	SYSCON->PLLCFG_b.PLL_PD=1;
	SYS_DelaymS(1);
	//setup pll
	SYSCON->PLLCFG_b.M=5;
	SYSCON->PLLCFG_b.N=1;
	SYSCON->PLLCFG_b.OD=0;
	SYSCON->PLLCFG_b.OEN=1;
	SYSCON->PLLCFG_b.BP=0;
	while(SYSCON->PLLLK!=1);
	return 0;
}
