#include "CMSDK_CM0.h"
#include "pwm.h"
#include "gpio.h"
#include "timer.h"
#include "sys.h"
#include "ioconfig.h"
#include "buzz.h"

#define BEN_OFF					PC->SET_b.SET15=1
#define BEN_ON					PC->CLR_b.CLR15=1
extern uint32_t SystemCoreClock;
MusicCtrl_TypeDef MusicCtrl;
const int song1[1][3]={{2320,3,370} };
const int song2[2][3]={{2320,5,370},{1920,60,3000}};
int dec=0;
//·äÃùÆ÷³õÊ¼»¯
void BuzzInit( void )
{
	PC->DIR_b.DIR15=1;
	BEN_OFF;
	PA_7_INIT(PA_7_PWM1); //setup buzz output
	
	PWM_Init(5,PWM_DEPENDENT,PWM_EDGE_ALIGN,PWM_POSITIVE);
	PWM_SetRiseDeadZone(0);
	PWM_SetFallDeadZone(0);

	TIM0_Init(TIM0,10000);
	TIM0_ConfigMatch(TIM0,10,TIM_MATCH_TRIGGER_INT|TIM_MATCH_RESET_COUNTER);
	TIM0_EnableInt(TIM0);
	NVIC_EnableIRQ(TIM0_IRQn);

}

void StartMusic(char  musicsel)
{
	MusicCtrl.musicStart=0x01;
	MusicCtrl.tempo=0x00;
	MusicCtrl.playPt=0x00;
		
	if(musicsel==1)
	{
		MusicCtrl.musicPt = song1;
		MusicCtrl.length = sizeof(song1)/12;
	}
	else if(musicsel==2)
	{
		MusicCtrl.musicPt = song2;
		MusicCtrl.length = sizeof(song2)/12;
	}
	PWM->CMOD = SystemCoreClock/MusicCtrl.musicPt[MusicCtrl.playPt][0];
	PWM1_VAL = PWM->CMOD>>1;
	BEN_ON;
	//Start PWM timer
	PWM_Start();

	TIM0->TCR=1;
	return;
	
}

//void MusicControl()
void TIM0_IRQHandler()
{
	if( MusicCtrl.musicStart==0x01 )
	{
		MusicCtrl.tempo++;
		if(MusicCtrl.tempo>=MusicCtrl.musicPt[MusicCtrl.playPt][1])
			BEN_OFF;

		if(MusicCtrl.tempo>=MusicCtrl.musicPt[MusicCtrl.playPt][2])
		{
			MusicCtrl.tempo=0;
			MusicCtrl.playPt++;
			if(MusicCtrl.playPt>=MusicCtrl.length)
			{
				MusicCtrl.musicStart=0x00;
				MusicCtrl.playPt=0x00;
				PWM_Stop();
				BEN_OFF;
			}
			else
			{
				PWM->CMOD = SystemCoreClock/MusicCtrl.musicPt[MusicCtrl.playPt][0];
				PWM->VAL1 = PWM->CMOD>>1;
				BEN_ON;	
			}
		}
	
	}	
	TIM0->IR=1;
}

void MusicStop()
{
	BEN_OFF;
	PWM_Stop();
}








