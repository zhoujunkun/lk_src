/*****************************************************************************
*   sys.h:  Header file for sys.c
*		ver 1.0
******************************************************************************/
#ifndef __SYS_H 
#define __SYS_H
#include "CMSDK_CM0.h"

#define IRC_CLK 						0x0
#define MAIN_CLK 						0x1
#define SYS_CLK 						0x2
#define WATCHDOG_CLK 				0x3
#define PLL_CLK 						0x4

#define AHB_I2C 						0x00000020
#define AHB_CRC 						0x00000040
#define AHB_TIM0 						0x00000080 
#define AHB_TIM1 						0x00000100 
#define AHB_TIM6 						0x00000200 
#define AHB_TIM7 						0x00000400
#define AHB_SPI 						0x00000800
#define AHB_UART0 					0x00001000 
#define AHB_UART1 					0x00002000
#define AHB_ADC 						0x00004000
#define AHB_WDT 						0x00008000
#define AHB_IOCON 					0x00010000
#define AHB_PWM 						0x00020000
#define AHB_LCD 						0x00040000
#define AHB_TOUCH 					0x00100000
#define AHB_TIM2 						0x00400000 
#define AHB_TIM3 						0x00800000 
#define AHB_PD 							0x10000080 
#define AHB_PA 							0x20000100 
#define AHB_PB 							0x40000080 
#define AHB_PC 							0x80000100 

#define PD_IRC 							0x00000002
#define PD_BOD 							0x00000008
#define PD_ADC 							0x00000010
#define PD_WDTOSC 					0x00000040
#define PD_LCD							0x00000080
#define PD_TOUCH 						0x00000100
#define PD_EXTOSC						0x00000200
#define PD_PLL							0x00000400

#define RST_SPI 						0x00000001
#define RST_TWS 						0x00000002
#define RST_UART0 					0x00000004 
#define RST_UART1 					0x00000008
#define RST_TIM0 						0x00000020 
#define RST_TIM1 						0x00000040 
#define RST_TIM6 						0x00000080 
#define RST_TIM7 						0x00000100
#define RST_PWM 						0x00000200
#define RST_CRC 						0x00000400
#define RST_TOUCH 					0x00000800
#define RST_ADC 						0x00001000
#define RST_LCD 						0x00002000
#define RST_TIM2 						0x00010000 
#define RST_TIM3 						0x00020000 

#define BOD_INT 						0
#define BOD_RESET 					1

#define IO_PIN0 						0x00000001
#define IO_PIN1 						0x00000002
#define IO_PIN2 						0x00000004
#define IO_PIN3 						0x00000008
#define IO_PIN4 						0x00000010
#define IO_PIN5 						0x00000020
#define IO_PIN6 						0x00000040
#define IO_PIN7 						0x00000080
#define IO_PIN8  						0x00000100
#define IO_PIN9  						0x00000200
#define IO_PIN10 						0x00000400
#define IO_PIN11 						0x00000800
#define IO_PIN12 						0x00001000
#define IO_PIN13 						0x00002000
#define IO_PIN14 						0x00004000
#define IO_PIN15 						0x00008000

#define FALL_EDGE 					0
#define RISE_EDGE 					1
#define BOTH_EDGE 					2

#define SYS_MemRemaptoBSL 			(SYSCON->SYSMEMREMAP_b.MAP=0)
#define SYS_MemRemaptoSRAM 			(SYSCON->SYSMEMREMAP_b.MAP=1)
#define SYS_MemRemaptoFlash 		(SYSCON->SYSMEMREMAP_b.MAP=2)

void SYS_SystemInitial(void);
void SYS_IRCTrimto40M(void);
void SYS_IRCTrimto48M(void);
void SYS_SelectMainClkSrc(uint8_t src);
void SYS_SetAHBClkDivider (uint8_t div);
void SYS_SelectWDTClkSrc(uint8_t src);
void SYS_SelectClkOutSrc(uint8_t src);
void SYS_SetClkOutDivider(uint8_t div);
void SYS_EnableClkOut(void);
void SYS_DisableClkOut(void);
void SYS_SetIOFilter(uint8_t ticks);
void SYS_PowerUpAngIP(uint32_t angips);
void SYS_PowerDownAngIP(uint32_t angips);
void SYS_EnablePhrClk(uint32_t phrs);
void SYS_DisablePhrClk(uint32_t phrs);
void SYS_ResetPhr(uint32_t phrs);
void SYS_ResetSystem(void);
void SYS_BODConfigure(uint8_t bodsel);
void SYS_EnterSleep (void);
void SYS_EnterDeepSleep (void);
void SYS_EnterPowerDown (void);
void SYS_DelaymS(uint32_t ms);
void SYS_DelayuS(uint32_t us);
void SYS_Delay(uint32_t loops);
uint8_t SYS_ExtOSCSetup(uint32_t extoscfreq,uint32_t plloutputfreq);

#endif /* end __SYS__H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
