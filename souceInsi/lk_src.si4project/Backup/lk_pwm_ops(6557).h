#ifndef __LK_PWM_OPS_H
#define __LK_PWM_OPS_H
#include "lk_pwm_ops.h"
#include "lk_global.h"
#define SystemClkFreq 24000000   //24MHZ
#define TimeFreqPSC   256        //freq


typedef enum
{
   dirForward,
   dirReverse,
   dirAlternate,/// 交替切换
   dirIdle
}pwm_dir_t;


typedef struct
{
  uint16_t pulse;  /* 脉宽 */
  uint16_t freq;  /* 频率 */
  uint16_t repeatCnts;  //pwm重复个数 
}pwm_param_t;


typedef struct 
{
  pwm_param_t param; //参数
  pwm_dir_t pwmDir;  //方向
}pwm_wave_t; //pwm 波形参数

typedef struct 
{
   pwm_wave_t *wave;   //波形
   pwm_ops_t *h_ops; /*pwm 硬件接口 */
}lk_pwm_handle_t;



#endif