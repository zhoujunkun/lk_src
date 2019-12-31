/**************************************************************************//**
 * $Id: system_CMSDK.c,
 *
 * @file     system_CMSDK.c
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Source File
 * @version  ver 1.0 
 * @date      
 * @author   
 *
 * @note
 *
 * @par

 ******************************************************************************/

#include <stdint.h>
#include "system_CMSDK.h"
#include "CMSDK_CM0.h"


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define __WDT_OSC_CLK     (32000UL)     /* Internal WDT oscillator frequency */
#define __IRC_OSC_CLK_40MHZ     (40000000UL)     /* Internal RC oscillator frequency 40M*/
#define __IRC_OSC_CLK_48MHZ     (48000000UL)     /* Internal RC oscillator frequency 48M*/
/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/

uint32_t SystemCoreClock = __IRC_OSC_CLK_40MHZ>>1 ; /*!< System Clock Frequency (Core Clock) after reset*/
uint32_t MainClock = __IRC_OSC_CLK_40MHZ;  /*!< Main Clock Frequency (Main Clock) after reset*/
/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
  //Get MainClock source
	switch (SYSCON->MAINCLKSEL_b.SEL )
	{
		case 0: //0x0 IRC oscillator
				if ((SYSCON->IRCCTRL)==(DIA->IRCTRIM48))
					MainClock = __IRC_OSC_CLK_48MHZ;
				else
					MainClock = __IRC_OSC_CLK_40MHZ;
				break;
		case 2: //0x2 WDT oscillator
				MainClock = __WDT_OSC_CLK;
				break;
		default: 
				break;
	}
  
  	SystemCoreClock = MainClock/SYSCON->SYSAHBCLKDIV_b.DIV;  /* Update SystemCoreClock */
	
	return;
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
	//your code here
}

