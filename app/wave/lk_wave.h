#ifndef __LK_WAVE_H
#define __LK_WAVE_H

#include "lk_tm8211.h"

#define  ENABLE_TM8211  0    //使能tm8211 驱动
#define  ENABLE_PWM_DAC  1   //使能pwm dac


#define WAVE_NUMBERS 17
typedef struct 
{
  uint8_t freq;   //波形频率
  uint8_t gears;  //波形挡位
  uint8_t select;   //中频手法
}lk_waveParam_t;

void wave_gearSelect(uint8_t gears);
int wave_1ms_callback(lk_waveParam_t *waveCfg);

#endif


