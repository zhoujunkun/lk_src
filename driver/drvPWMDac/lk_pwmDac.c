#include "lk_pwmDac.h"

#include "main.h"

extern TIM_HandleTypeDef htim1;
void pwmSet_compare(uint16_t value)
{
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,value);  
}