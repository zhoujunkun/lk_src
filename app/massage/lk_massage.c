#include "lk_massage.h"

massageHandle_t massageHandle;
typedef struct {
	uint16_t pluse ;
  uint16_t freq;	/* 频率 */
  uint16_t repeatCnts;	//pwm重复个数 
  waveDir_t 	dir;
}massageRunStatu_t;

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

//舒缓模式
waveParamCfg(easeMode_83Hz,35,83,100); //83hz
waveParamCfg(easeMode_idle,0,2,2);        //1/2*2 = 1s
waveParamCfg(easeMode_122Hz,35,122,100);
waveParamCfg(easeMode_166Hz,35,166,100);	
	
massageWaveCfg_t easyModeArray[]=
{
  {&easeMode_83Hz,dirNormal},
	{&easeMode_idle,dirIdle},
	{&easeMode_83Hz,dirNormal},
	{&easeMode_idle,dirIdle},
	{&easeMode_83Hz,dirNormal},
	{&easeMode_idle,dirIdle},
};


//智能模式



massageWave_array_t waveArray[]=
{
	{easyModeArray,sizeof(easyModeArray)/sizeof(massageWaveCfg_t)}, //舒缓模式
};


void  extendSliceExtNo_func(massageRunStatu_t *waveRun)
{
 static uint8_t funcNormalIndx=0,funcNumbers;
	switch (waveRun->dir)
		{
			case dirNormal:
				{
				  funcNumbers = sizeof(emsDirNormalOps)/sizeof(emsDirFunc);
					emsDirNormalOps[funcNormalIndx++](waveRun->pluse);
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

void  extendSlicextFour_func(massageRunStatu_t *waveRun)
{
  


}


void waveCtl(extendSlicexType_enum    extendSlicexType, massageRunStatu_t *waveRun)
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

/**************************************************************************************************
 * @fn  void massage_init(void)
 *
 * @brief   按摩初始化
 * input parameters
 *
 * None
 * output parameters
 *
 * @return      None
 */

void massage_init(void)
{
	 ems_io_init();
   massageHandle.hpwm = &pwm_ops;
}

void wave_copy(massageWaveCfg_t *wave,massageRunStatu_t *waveRun)
{
   waveRun->dir = wave->dir;
	 waveRun->freq = wave->param->freq;
	 waveRun->pluse = wave->param->pulse;
	 waveRun->repeatCnts = wave->param->repeatCnts;
}

void massageWave_ctl(massageHandle_t *massage)
{
  static massageRunStatu_t waveOld;
  static uint16_t waveModeNext=0,waveModeInexMax=0;

  massageWaveCfg_t *wave_p,*waveNext; //运行参数
  massageRunStatu_t waveRun;
  wave_p =  waveArray[massage->mode].waveCfg; //波形地址
  if(wave_p == NULL) return;
  wave_copy(wave_p,&waveRun);      
  waveModeInexMax = waveArray[massage->mode].waveNumbers;
  massage->hpwm->stop(); //停止
  
  if(--waveRun.repeatCnts == 0)  //重复次数
  {
    waveNext=wave_p;
	  waveModeNext++; //下一个模式
	  if(waveModeNext >= waveModeInexMax )
	  {
		   waveModeNext = 0;
	  }
	  wave_p = (massageWaveCfg_t *)(waveNext+waveModeNext);
		
  }
  if(waveOld.dir !=waveRun.dir)
  {
      waveOld.dir = waveRun.dir;
	    massage->hpwm->set_feq(waveRun.freq);  //设置波形频率
  }
  waveCtl(massage->sliceType, &waveRun);
  massage->hpwm->start(); //启动
}


