#include "lk_massage.h"
typedef struct
{
	extendSlicexType_enum SlicexType;
	void (*ctl)(waveDir_t dir,uint32_t pluse);
}wave_ops_t;




typedef void (*emsDirFunc)(uint32_t pluse);

emsDirFunc emsDirNormalOps[]={
	  emsA_to_B_PNAlter_P,
		emsA_to_B_PNAlter_N,
		emsA_to_B_Single_P,
		emsA_to_B_Single_N,
	};

void  extendSliceExtNo_func(massageWaveCfg_t *waveRun)
{
 static uint8_t funcNormalIndx=0,funcNumbers;
	switch (waveRun->dir)
		{
			case dirNormal:
				{
				  funcNumbers = sizeof(emsDirNormalOps)/sizeof(emsDirFunc);
					emsDirNormalOps[funcNormalIndx++](waveRun->param->pulse);
					if(funcNormalIndx >= funcNumbers) funcNormalIndx = 0;
			  }break;
			case dirForward:
				{
			
				}break;
			case dirReverse:
				{
			
				}break;
			case dirAlternate:
				{
			
				}break;
			case dirIdle:
				{
			
				}break;				
		}


}

void  extendSlicextFour_func(massageWaveCfg_t *waveRun)
{



}


void waveCtl(extendSlicexType_enum    extendSlicexType, massageWaveCfg_t *waveRun)
{
	switch (extendSlicexType)
		{
			 case extendSliceExtNo:
			 	{
               extendSliceExtNo_func(waveRun);
				}break;
				case extendSlicextFour:
				 {
							extendSlicextFour_func(waveRun);
				 }break;				
		}
  
}


void massageWave_ctl(lk_controlHandle_t *ctl)
{
  static massageWaveCfg_t waveOld;
  static uint16_t waveModeNext=0,waveModeInexMax=0;
  massageWaveCfg_t *waveRun,*wave_next,*wave; //运行参数

  wave = waveArray[ctl->massage->mode -massageIDLE].waveCfg; //波形地址
  waveModeInexMax = waveArray[ctl->massage->mode -massageIDLE].waveNumbers;
  ctl->massage->hpwm->stop(); //停止
  
  if(--waveRun->param->repeatCnts == 0)  //重复次数
  {
	  waveModeNext++; //下一个模式
	  if(waveModeNext >= waveModeInexMax )
	  {
		   waveModeNext = 0;	
	  }
	  wave_next = (massageWaveCfg_t *)(waveRun+waveModeNext);
	  waveRun->dir = wave_next->dir;
	  waveRun->param->freq = wave_next->param->freq;
	  waveRun->param->pulse = wave_next->param->pulse;
	  waveRun->param->repeatCnts = wave_next->param->repeatCnts;	  
  }
  if(waveOld.dir !=waveRun->dir)
  {
      waveOld.dir = waveRun->dir;
	    ctl->massage->hpwm->set_feq(waveRun->param->freq);  //设置波形频率
  }
  waveCtl(ctl->massage->sliceType, waveRun);
  ctl->massage->hpwm->start(); //启动
}


