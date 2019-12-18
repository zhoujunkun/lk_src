#ifndef __LK_PWM_OPS_H
#define __LK_PWM_OPS_H

typedef struct 
{
   void (*start)(void);
   void (*stop)(void);
   void (*init)(void);
   void (*set_feq)(uint16_t freq);
}pwm_ops_t;






#endif