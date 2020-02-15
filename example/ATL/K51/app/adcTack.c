#include "lk_board.h"

#define ADC_SAMPLE_SIZE      4
#define ADC_CHANNEL_NUMBERS  3 
#define SAMPLE_NUMBERS (ADC_SAMPLE_SIZE * ADC_CHANNEL_NUMBERS) //

uint16_t smapleBuf[ADC_SAMPLE_SIZE][ADC_CHANNEL_NUMBERS]={0};

#define ADC_NORMAL_CAL(val)          ((val * 3300) / (4095))
// Boost反馈电压采样算法
#define ADC_SAMPLE_FB(val)           ((val * 3300 * 52) / (4095))

// BAT电压采样算法
#define ADC_SAMPLE_BAT(val)          ((val * 6000) / (4095))

typedef enum 
{
   sample_boost_fb=0,
   sample_bat,
   sample_heat,
}sampleADC_ID_enum_t;

float value=0,calValue=0;
float filterSampleValue(sampleADC_ID_enum_t id)
{
    
    
    uint32_t sum=0;

    for(int i=0;i<ADC_SAMPLE_SIZE; i++)
    {
       sum += smapleBuf[i][id];
    }   
     value = sum/ ADC_SAMPLE_SIZE;
    
    
    switch(id)
    {
        case sample_boost_fb:
        {
            calValue = ADC_NORMAL_CAL(value);
        }break;
        case sample_bat:
        {
            calValue = ADC_NORMAL_CAL(value);
        }break;
        case sample_heat:
        {
            calValue = ADC_NORMAL_CAL(value);
        }break;
    }    
    sum = 0;
  return    calValue;
}
 uint32_t Boot=0,Heat=0,Bat=0;
void checkADC(void)
{  
    uint16_t value =0;
    lk_damAdc_init(smapleBuf[0],SAMPLE_NUMBERS);    
    while(1)
    {
      rt_thread_mdelay(800); 
      Boot = filterSampleValue(sample_boost_fb);
      Heat = filterSampleValue(sample_heat);
      Bat = filterSampleValue(sample_bat);
      rt_kprintf("boot vol=%dmv, heat vol=%dmv, bat vol=%dmv \r\n",Boot,Heat,Bat);
    }
}

MSH_CMD_EXPORT(checkADC, k51 ADC check);