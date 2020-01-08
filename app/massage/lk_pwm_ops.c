#include "lk_pwm_ops.h"

//初始化
void pwm_init(void)
{


}


//设置频率
void pwm_set_feq(uint16_t frq)
{


}


//启动
void pwm_start(void)
{


}

//停止
void pwm_stop(void)
{


}

pwm_ops_t pwm_ops=
{
	.init = pwm_init,
  .set_feq = pwm_set_feq,
  .start = pwm_start,
  .stop = pwm_stop,
};

