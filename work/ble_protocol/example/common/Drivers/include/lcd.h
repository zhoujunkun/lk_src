/*****************************************************************************
*   lcd.h:  Head file for lcd.c
*		ver 1.0
******************************************************************************/
#ifndef __LCD_H
#define __LCD_H


#include "CMSDK_CM0.h"

//LCD config	
#define LCD_MODE	0
#define LED_MODE 1
#define DUTY_1				    2						 /*!< 1/2 duty */
#define DUTY_2				    2						 /*!< 1/2 duty */
#define DUTY_3				    3					 /*!< 1/2 duty */
#define DUTY_4			    	4						 /*!< 1/2 duty */
#define DUTY_5						5					 /*!< 1/2 duty */
#define DUTY_6				    6						 /*!< 1/2 duty */
#define DUTY_7				    7					 /*!< 1/2 duty */
#define DUTY_8				    8		
#define LCD_BIAS_3			    	0					 /*!< 1/3 voltage */
#define LCD_BIAS_2				    1						 /*!< 1/2 voltage */
#define LED_ANODE	0
#define LED_CATHODE 1

#define COM0				    0x1						 /*!< 1/2 duty */
#define COM1				    0x2					 /*!< 1/2 duty */
#define COM2			    	0x4						 /*!< 1/2 duty */
#define COM3						0x8					 /*!< 1/2 duty */
#define COM4				    0x10					 /*!< 1/2 duty */
#define COM5				    0x20					 /*!< 1/2 duty */
#define COM6				    0x40					 /*!< 1/2 duty */
#define COM7				    0x80					 /*!< 1/2 duty */
#define SEG0			    	0x1					 /*!< 1/3 voltage */
#define SEG1				    0x2						 /*!< 1/2 voltage */
#define SEG2						0x4
#define SEG3		 				0x8
#define SEG4		 				0x10
#define SEG5		 				0x20	
#define SEG6		 				0x40	
#define SEG7		 				0x80	
#define SEG8	 					0x100	
#define SEG9	 					0x200	
#define SEG10	 					0x400	
#define SEG11	 					0x800	
#define SEG12	 					0x1000	
#define SEG13	 					0x2000	
#define SEG14	 					0x4000	
#define SEG15	 					0x8000	

/* Private variables ---------------------------------------------------------*/

void LCD_Init (uint8_t mode,uint8_t duty, uint8_t biasanode, uint8_t finhz);
void LCD_Deinit(void);
void LCD_EnableOutput(uint8_t comchannel, uint16_t segchannel);
void LCD_SetDot (uint8_t com, uint8_t segment);
void LCD_ResetDot (uint8_t com, uint8_t segment);
void LCD_SetComLine (uint8_t com, uint16_t segments);
void LCD_ResetComLine (uint8_t com, uint16_t segments);
void LCD_WriteComLine(uint8_t com, uint16_t data);
void LCD_ClearScreen(void);
void LCD_LightFullScreen(void);
void LCD_WriteMemMap(uint8_t offset, uint32_t data);
#endif /* end __LCD_H */


/* --------------------------------- End Of File ------------------------------ */

