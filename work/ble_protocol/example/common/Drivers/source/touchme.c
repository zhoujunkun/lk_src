/*****************************************************************************
 *   itouch.c:  Source file for ME32F030
 *   
 *
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "CMSDK_CM0.h"
#include "SYS.h"
#include "touch.h"
#include "touchme.h"

touch itouch;
/*****************************************************************************
Function Name	itouch_init
Function Definition	void itouch_init(void)
Function Description	initial touch module and itouch parameters 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void itouch_init(uint32_t keys)
{
	uint16_t i,j=0;
	uint32_t validkeys=0;
	itouch.stime=1000000000; //1ms
	itouch.noise=1;
	itouch.hysteresis=5;
//	itouch.sensity=20; //sense 0.30pf, range 0~1000 to reprent 0.00~10pf
	itouch.keysensity[0]=10;
//	itouch.keysensity[1]=20;
	itouch.sensitysel=1; //select itouch.sensity
	itouch.kr=1386*8; //select 80KOhm internal resister
	for (i=0;i<22;i++)
	{
		if (keys&(1<<i))
		{
				validkeys |=1<<i;
				itouch.chnval[j]=0;
				itouch.chnmaxval[j]=0;
				itouch.ref[j]=0;
				itouch.threhold[j]=0;
				itouch.cap[j]=0;		
				itouch.mapping[i]=j++;
				if (j==TOUCH_KEYS_NUMBER)
					break;
		}
	}
	TOUCH_Init();
	TOUCH_SelSenseClk (TOUCH_SENSE_CLK_800);//TOUCH_SENSE_CLK_5000
//	TOUCH_SelSenseClk (TOUCH_SENSE_CLK_2000);
	TOUCH_SetScanTime(1); //sense time 1ms 
	TOUCH_EnableScanInt();
	NVIC_EnableIRQ(TOUCH_IRQn);
	TOUCH_EnableTouchCHN(validkeys);
}

/*****************************************************************************
Function Name	itouch_update
Function Definition	void itouch_update(void)
Function Description	update cap ref 
Input Parameters	none
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void itouch_update(void)
{
	uint32_t i;
	
	TOUCH_DisableScanInt();

	for (i=0;i<TOUCH_KEYS_NUMBER;i++)
	{
		if (itouch.chnval[i])
		{
			itouch.cap[i]=(itouch.stime/(itouch.kr*itouch.ref[i]))*10;
			if (itouch.sensitysel)
					itouch.threhold[i]=itouch.ref[i]-itouch.ref[i]*itouch.keysensity[i]/(itouch.cap[i]+itouch.keysensity[i]);
			else
				itouch.threhold[i]=itouch.ref[i]-itouch.ref[i]*itouch.sensity/(itouch.cap[i]+itouch.sensity);
		}
	}
	TOUCH_EnableScanInt();
}
/*****************************************************************************
Function Name	TOUCH_IRQHandler
Function Definition	void TOUCH_IRQHandler(void)
Function Description	Touch interrupt handler
Input Parameters	none
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void TOUCH_IRQHandler(void)
{
	
	uint32_t val;
	uint32_t cap;
	uint32_t chnindex;
	uint8_t chn;
	//get last touch scan value
	TOUCH_GetScanVal(&chn, &val);
	//return touch channel index 
	chnindex=itouch.mapping[chn];

	itouch.chnval[chnindex]=val;
	if (itouch.ref[chnindex]==0) //intial cap ref
	{
		cap=(itouch.stime/(itouch.kr*val))*10;
		if (itouch.sensitysel)
			itouch.threhold[chnindex]=val-val*itouch.keysensity[chnindex]/(cap+itouch.keysensity[chnindex]);
		else
			itouch.threhold[chnindex]=val-val*itouch.sensity/(cap+itouch.sensity);		
		itouch.ref[chnindex]=val;
		itouch.cap[chnindex]=cap;		
	}
	else{
		//trace cap ref
		if  (itouch.ref[chnindex]>val)
		{
			if (itouch.chnmaxval[chnindex]<val)
				itouch.chnmaxval[chnindex]=val;
		}
		else
			itouch.ref[chnindex]=val;
		
	}
	//check current cap and set key touch status, 1->touched; 0->no touch
	if (val<itouch.threhold[chnindex])
	{
		itouch.status |=1<<chn;	
		itouch.history|=itouch.status ;	
	}
	else if (val>itouch.threhold[chnindex]-itouch.hysteresis)
		itouch.status &=~(1<<chn);
	//fix Ref val
	if (itouch.counter == TOUCH_UPDATE_CYCLE_NUMBER )
	{
		if ((itouch.history&(1<<chn))==0)
			itouch.ref[chnindex]=itouch.chnmaxval[chnindex];
		itouch.chnmaxval[chnindex]=0;
	}
	if (chnindex==0)
	{
		itouch.counter ++;
		if (itouch.counter>TOUCH_UPDATE_CYCLE_NUMBER)
		{
			itouch.counter=0;
			itouch.history=0;
		}
	}
	//clear interrupt flag
	TOUCH_ClearIntFlag ();
}
