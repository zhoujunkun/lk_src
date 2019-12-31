#ifndef __LK_PWM_OPS_H
#define __LK_PWM_OPS_H
#include "lk_global.h"
#define SystemClkFreq 24000000   //24MHZ
#define TimeFreqPSC   256        //freq

typedef struct
{
  void (*init)(void);
  void (*set_feq)(uint16_t frq);
  void (*start)();
  void (*stop)();	
}pwm_ops_t;

extern pwm_ops_t pwm_ops;
#endif

