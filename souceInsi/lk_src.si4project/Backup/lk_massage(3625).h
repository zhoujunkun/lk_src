#ifndef __LK_MASSAGE_MODE_H
#define __LK_MASSAGE_MODE_H
#include "lk_pwm_ops.h"
#include "lk_ble_ops.h"


typedef enum
{
	 dirNormal, //正常,波形一个上一个下
   dirForward,
   dirReverse,
   dirAlternate,/// 交替切换
   dirIdle
}waveDir_t;

typedef struct
{
  uint16_t pulse;  /* 脉宽 */
  uint16_t freq;  /* 频率 */
  uint16_t repeatCnts;  //pwm重复个数 
}waveParam_t;


typedef struct 
{
  waveParam_t *param; //参数
  waveDir_t dir;  //方向
}massageWaveCfg_t; //pwm 波形参数


typedef struct
{
	massageWaveCfg_t waveCfg;
	

}massageWave_handle_t;



#define waveParamCfg(name,hz,pulse,repeat)  waveParam_t name ={pulse,(SystemClkFreq)/(TimeFreqPSC*hz),repeat}



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





#define AcupunctureModeSize        (sizeof(AcupunctureMode)/sizeof(pwm_wave_t))

#endif
