#ifndef __LK_MASSAGE_MODE_H
#define __LK_MASSAGE_MODE_H
#include "lk_pwm_ops.h"
#include "lk_ems_ctl.h"
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
  const uint16_t pulse;  /* 脉宽 */
  const uint16_t freq;  /* 频率 */
  const uint16_t repeatCnts;  //pwm重复个数 
}waveParam_t;


typedef struct 
{
  waveParam_t *param; //参数
 const waveDir_t dir;  //方向
}massageWaveCfg_t; //pwm 波形参数


typedef struct
{
   massageWaveCfg_t *waveCfg;
	uint16_t waveNumbers;

}massageWave_array_t;






#define waveParamCfg(name,pulse,hz,repeat)  waveParam_t name ={pulse,hz,repeat}


typedef enum  //按摩模式
{
  massageEaseMode=0,     //舒缓模式
  massageSmartMode,    //智能模式
  massageVitalityMode, //活力模式
  massagePowerfulMode, //强劲模式
  massage3DAcupuncture,
  massage3DMalaxation,
  massage3Dscraping,
  massage3DKnock,
}massageModeType_t;

typedef enum   //扩展电极片类型
{
  extendSliceExtNo,
  extendSlicextFour,
}extendSlicexType_enum;


typedef struct
{
	extendSlicexType_enum sliceType; //电极片类型
	massageModeType_t mode; //按摩模式 
	pwm_ops_t *hpwm;
}massageHandle_t;



typedef struct
{
	massageHandle_t *massage;

}lk_controlHandle_t;









void massage_init(void);
void massageWave_ctl(massageHandle_t *massage);

extern massageHandle_t massageHandle;

#endif
