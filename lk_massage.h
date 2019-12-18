#ifndef __LK_MASSAGE_MODE_H
#define __LK_MASSAGE_MODE_H
#include "lk_pwm_handle.h"

#define SystemClkFreq 24000000   //24MHZ
#define TimeFreqPSC   256        //freq


#define defeqHz(d)   (SystemClkFreq)/(TimeFreqPSC*d)
#define depulse(d)    (d)
#define derepeat(d)    (d)

pwm_param_t AcupunctureeMode_to_83Hz=
{
   depulse(35), 
   defeqHz(83),
   derepeat(250),
};


pwm_param_t AcupunctureeMode_to_83Hz=
{
   depulse(35), 
   defeqHz(83),
   derepeat(150),
};

pwm_param_t AcupunctureeMode_to_166Hz=
{
   depulse(35), 
   defeqHz(166),
   derepeat(200),
};

pwm_param_t AcupunctureeMode_to_122Hz=
{
   depulse(35), 
   defeqHz(122),
   derepeat(24),
};


pwm_param_t AcupunctureeMode_toIDLE_2Hz_1S=
{
   depulse(0), 
   defeqHz(2),
   derepeat(2),
};



pwm_wave_t AcupunctureMode[]=  //波形定义
{
  {&AcupunctureeMode_to_83Hz,forward},
};





#define AcupunctureModeSize        (sizeof(AcupunctureMode)/sizeof(pwm_wave_t))

#endif