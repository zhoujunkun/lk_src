/*****************************************************************************
*   lcd.c:  source file for lcd module
*		ver 1.0
******************************************************************************/
#include "lcd.h"
#include "sys.h"
extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	LCD_Init
Function Definition	void LCD_Init (uint8_t mode,uint8_t duty, uint8_t biasanode, uint8_t finhz)
Function Description	Initial module in LCD mode and configure bias voltage, common line scan frequency
Input Parameters	Mode: LCD/LED
Duty: 1~6 present duty 1, ½, 1/3, ¼, 1/5 and 1/6. For example, if 4 COM LCD display module is applied, duty shall be set to 4.
Biasanode:LCD mode: 0-1/2 VDD, 1-1/3 VDD;LED 0- common anode, 1-common cathode
Finhz: scan frequency in HZ
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void LCD_Init (uint8_t mode,uint8_t duty, uint8_t biasanode, uint8_t finhz)
{
	SYSCON->SYSAHBCLKCTRL_b.LCD_CLK=1;
	SYSCON->PRESETCTRL_b.LCD_RST_N=0;
	SYSCON->PRESETCTRL_b.LCD_RST_N=1;
	//disable output
	LCD->LCDOUTEN0=0;
	LCD->LCDOUTEN1=0;
	//set duty
	LCD->LCDCTRL1_b.DUTY=duty;
	
	if ((finhz>0)&&(duty>0))
		LCD->LCDCTRL1_b.FREQDIV=SystemCoreClock/(duty*finhz);
	if (mode==LCD_MODE)
	{
		SYSCON->PDRUNCFG_b.LCD_PD=0;
		LCD->LCDCTRL1_b.BIAS=biasanode;
		LCD->LCDCTRL0_b.LEDEN=0;
		LCD->LCDCTRL0_b.LCDEN=1;
		
	}else if (mode==LED_MODE)
	{
		SYSCON->PDRUNCFG_b.LCD_PD=1;
		LCD->LCDCTRL0_b.LCDEN=0;
		LCD->LCDCTRL0_b.LEDINV=biasanode;
		LCD->LCDCTRL0_b.LEDEN=1;
	}
	return;
}

/*****************************************************************************
Function Name	LCD_Deinit
Function Definition	void LCD_Deinit(void)
Function Description	De-Initial module
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void LCD_Deinit(void)
{
	SYSCON->PDRUNCFG_b.LCD_PD=1;
	SYSCON->SYSAHBCLKCTRL_b.LCD_CLK=0;
	return;
}

/*****************************************************************************
Function Name	LCD_ClearScreen(void)
Function Definition	void LCD_ClearScreen(void)
Function Description	turn off all dot 
Input Parameters	none

Return Value	None
Condition	No
Function called	-

*****************************************************************************/
void LCD_ClearScreen(void)
{
	LCD->MEMMAP0=0;
	LCD->MEMMAP1=0;
	LCD->MEMMAP2=0;
	LCD->MEMMAP3=0;
	return;
}
/*****************************************************************************
Function Name	LCD_LightFullScreen
Function Definition	void LCD_LightFullScreen(void)
Function Description	turn on all dot 
Input Parameters	none

Return Value	None
Condition	No
Function called	-

*****************************************************************************/
void LCD_LightFullScreen(void)
{
	LCD->MEMMAP0=0xFFFFFFFF;
	LCD->MEMMAP1=0xFFFFFFFF;
	LCD->MEMMAP2=0xFFFFFFFF;
	LCD->MEMMAP3=0xFFFFFFFF;
	return;
}

/*****************************************************************************
Function Name	LCD_WriteMemMap
Function Definition	void LCD_WriteMemMap(uint8_t offset, uint32_t data)
Function Description	Write LCD/LED memory map table value
Input Parameters	offset: memory table offset address
data: value of map 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void LCD_WriteMemMap(uint8_t offset, uint32_t data)
{
	*(	&(LCD->MEMMAP0)+(uint32_t)(offset))=data;
	return;
}
/*****************************************************************************
Function Name	LCD_EnableOutput
Function Definition	void LCD_EnableOutput(uint8_t comchannel, uint16_t segchannel)
Function Description	Enable COM and Seg output. This function is for LCD mode only.
Input Parameters	Comchannel: combination of COM0~COM5
Segchannel: combination of SEG0~SEG15
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void LCD_EnableOutput(uint8_t comchannel, uint16_t segchannel)
{
	LCD->LCDOUTEN0_b.LCDCOMEN=comchannel;
	LCD->LCDOUTEN1_b.LCDSEGEN=segchannel;
	return;
}
	
/*****************************************************************************
Function Name	LCD_SetDo
Function Definition	void LCD_SetDot (uint8_t com, uint8_t segment)
Function Description	Light the specific dot
Input Parameters	Comchannel: COM0~COM5
Segchannel: SEG0~SEG15
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void LCD_SetDot (uint8_t com, uint8_t segment)
{
	uint32_t seg=0,segcol=0;

	if ((segment==0)||(com==0))return;

	if (LCD->LCDCTRL0_b.LCDEN)
	{
		if (segment&0xFF00)
		{
			seg=2;
			segment=segment>>8;
		}
		if (segment&0xF0)
		{
			seg+=1;
			segment=segment>>4;
		}
		if (segment&0xC)
		{
			segcol=16;
			segment=segment>>2;
		}	
		if (segment&0x2)
		{
			segcol+=8;
		}			

	*(	&(LCD->MEMMAP0)+(uint32_t)(seg)) |= com<<segcol;
	}else if (LCD->LCDCTRL0_b.LEDEN)
	{
		*(	&(LCD->MEMMAP0)+(uint32_t)(com>>1)) |= (1<<(segment+16*(com&1)));
	}
	return;
}
	
/*****************************************************************************
Function Name	LCD_ResetDo
Function Definition	void LCD_ResetDot (uint8_t com, uint8_t segment)
Function Description	Turn off the specific dot
Input Parameters	Comchannel: COM0~COM5
Segchannel: SEG0~SEG15
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void LCD_ResetDot (uint8_t com, uint8_t segment)
{
	uint32_t seg=0,segcol=0;

	if ((segment==0)||(com==0)) return;

	if (LCD->LCDCTRL0_b.LCDEN)
	{
		if (segment&0xFF00)
		{
			seg=2;
			segment=segment>>8;
		}
		if (segment&0xF0)
		{
			seg+=1;
			segment=segment>>4;
		}
		if (segment&0xC)
		{
			segcol=16;
			segment=segment>>2;
		}	
		if (segment&0x2)
		{
			segcol+=8;
		}			

		*(	&(LCD->MEMMAP0)+(uint32_t)(seg)) &= ~(com<<segcol);
	}else if (LCD->LCDCTRL0_b.LEDEN)
	{
		*(	&(LCD->MEMMAP0)+(uint32_t)(com>>1)) &= ~(1<<(segment+16*(com&1)));
	}
	return;
}
