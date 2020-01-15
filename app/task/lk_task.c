#include "lk_task.h"
 #include "at32_board.h"
/*计数器*/
#define TASK_1MS_IRQ       TMR1_BRK_TMR9_IRQHandler       //1ms定时器    
#define TASK_TIMER         TMR9                           //计数器定时器
#define TASK_TIMER_RCC     RCC_APB2PERIPH_TMR9            //计数器定时器时钟
#define TASK_TIMER_NVIC    TMR1_BRK_TMR9_IRQn

#define MOTOR_TIM         TMR3
#define MOTOR_TIM_RCC     RCC_APB1PERIPH_TMR3
#define MOTOR_PORTA_PIN   GPIO_Pins_6
#define MOTOR_PORTA_GPIO  GPIOA

#define MOTOR_PORTB_PIN   GPIO_Pins_7
#define MOTOR_PORTB_GPIO  GPIOA

#define LKTMR_MOTOR TMR3  

#define SHAKE_ONCE_TIME 200
#define SHAKE_TWICE_TIME 200

#define SHAKE_LOW_PWM()       LKTMR_MOTOR->CC1=800
#define SHAKE_MID_PWM()       LKTMR_MOTOR->CC1=500
#define SHAKE_HIGH_PWM()      LKTMR_MOTOR->CC1=200
#define SHAKE_CLOSE_PWM()     LKTMR_MOTOR->CC1=0

#define SHAKE_PWM_SET(DATA)   LKTMR_MOTOR->CC1=DATA

#define MOTOR_ARRY_SIZE 64

 bool ifPowerOn=false,powerKeyPress=false;
uint16_t sinMotor[]={ //正弦波 
1,0,0,1,2,5,8,12,17,23,
31,40,50,61,75,90,107,126,147,170,
196,223,251,281,312,342,372,401,427,450,
470,485,495,500,499,492,480,464,443,418,
391,362,331,301,270,241,213,187,162,140,
119,101,84,70,57,46,36,28,21,15,
11,7,4,2,};
uint16_t sawtooth_motor[]={ // 
0,8,16,24,32,40,48,56,63,71,
79,87,95,103,111,119,127,135,143,151,
159,167,175,183,190,198,206,214,222,230,
238,246,254,262,270,278,286,294,302,310,
317,325,333,341,349,357,365,373,381,389,
397,405,413,421,429,437,444,452,460,468,
476,484,492,0,};
uint16_t triangle_motor[]={ //三角 
0,16,32,48,63,79,95,111,127,143,
159,175,190,206,222,238,254,270,286,302,
317,333,349,365,381,397,413,429,444,460,
476,492,492,476,460,444,429,413,397,381,
365,349,333,317,302,286,270,254,238,222,
206,190,175,159,143,127,111,95,79,63,
48,32,16,0,};
uint16_t ladder_motor[]={ //阶梯 
125,125,125,125,125,125,125,125,125,125,
125,125,125,125,125,125,250,250,250,250,
250,250,250,250,250,250,250,250,250,250,
250,250,375,375,375,375,375,375,375,375,
375,375,375,375,375,375,375,375,500,500,
500,500,500,500,500,500,500,500,500,500,
500,500,500,500,};

bool ifShakeLowStart=false,ifShakeMidStart=false,ifShakeHighStart=false;
/*震动电机*/
typedef enum {motorRun=0,motorStop,motorIdle}motorEnm_t;
motorEnm_t motorRunStatu = motorRun;
 typedef struct
{
    bool       ifStart;    /*是否启动*/
    uint32_t   cnts;       /*计时*/
    uint16_t   runTime;    /*运行时间*/      
    uint16_t   stopTime;   /*停止时间*/      
    uint16_t   pluse;      /*脉宽*/
    uint8_t    freq;       /*频率*/     

}motorRun_t;

motorRun_t motorShakeOnece=  
{
    .runTime  = 100,         
    .stopTime = 0,
    .pluse    = 500,
    .freq     = 1,
};

motorRun_t motorShakeTwice=
{
    .runTime  = 100,     //ms  
    .stopTime = 100,
    .pluse    = 500,
    .freq     = 2,
};


void lk_pwm_init(void)
{
    TMR_TimerBaseInitType  TMR_TMReBaseStructure;
    TMR_OCInitType  TMR_OCInitStructure;
    /* TMRe base configuration */
    TMR_TimeBaseStructInit(&TMR_TMReBaseStructure);
    TMR_TMReBaseStructure.TMR_Period = 1000;
    TMR_TMReBaseStructure.TMR_DIV = (uint16_t) (SystemCoreClock / 1000000) - 1;
    TMR_TMReBaseStructure.TMR_ClockDivision = 0;
    TMR_TMReBaseStructure.TMR_CounterMode = TMR_CounterDIR_Up;
    TMR_TimeBaseInit(LKTMR_MOTOR, &TMR_TMReBaseStructure);

      /* PWM1 Mode configuration: Channel1 */
    TMR_OCStructInit(&TMR_OCInitStructure);
    TMR_OCInitStructure.TMR_OCMode = TMR_OCMode_PWM1;
    TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
    TMR_OCInitStructure.TMR_Pulse = 0;
    TMR_OCInitStructure.TMR_OCPolarity = TMR_OCPolarity_High;
    TMR_OC1Init(LKTMR_MOTOR, &TMR_OCInitStructure);
    TMR_OC1PreloadConfig(LKTMR_MOTOR, TMR_OCPreload_Enable);
    
    
      /* PWM1 Mode configuration: Channel2 */
    TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
    TMR_OCInitStructure.TMR_Pulse = 0;
    TMR_OC2Init(LKTMR_MOTOR, &TMR_OCInitStructure);
    TMR_OC2PreloadConfig(LKTMR_MOTOR, TMR_OCPreload_Enable);   

   TMR_ARPreloadConfig(TMR3, ENABLE);
    /* TMR enable counter */
    TMR_Cmd(LKTMR_MOTOR, ENABLE);
}


void lk_taskTime_init(void)
{
    TMR_TimerBaseInitType  TMR_TMReBaseStructure;
    //RCC
    RCC_APB2PeriphClockCmd(TASK_TIMER_RCC,ENABLE);    
   
    //NVIC
    NVIC_InitType NVIC_InitStructure;

    /* Enable the TMR2 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TASK_TIMER_NVIC;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    


    /* TMRe base configuration */
    TMR_TimeBaseStructInit(&TMR_TMReBaseStructure);
    TMR_TMReBaseStructure.TMR_Period = 1000;
    TMR_TMReBaseStructure.TMR_DIV = (uint16_t) (144-1);;
    TMR_TMReBaseStructure.TMR_ClockDivision = 0;
    TMR_TMReBaseStructure.TMR_CounterMode = TMR_CounterDIR_Up;

    TMR_TimeBaseInit(TASK_TIMER, &TMR_TMReBaseStructure);

    /* TMR IT enable */
    TMR_INTConfig(TASK_TIMER, TMR_INT_Overflow, ENABLE);

    /* TMR enable counter */
    TMR_Cmd(TASK_TIMER, ENABLE);
}


void motor_shake(motorRun_t *motor)
{
   static uint8_t freq=0;
   if(motor->ifStart)
   {
       motor->cnts++;
       switch(motorRunStatu)
       {
           case motorIdle:
           {   
               MOTOR_TIM->CC1 = 0;
               if(motor->ifStart)   motorRunStatu = motorRun;
           }
           case motorRun:
           {
             MOTOR_TIM->CC1 = motor->pluse;
             if(motor->cnts >=motor->runTime)
             {
                 motorRunStatu = motorStop;
                  motor->cnts = 0;
             }
           
           }break;
           case motorStop:
           {
             MOTOR_TIM->CC1 = 0;
             if(motor->cnts >=motor->stopTime)
             {
                 freq++;
                 if(motor->freq == freq)
                 {
                   motorRunStatu = motorIdle;
                   motor->ifStart =false;
                   freq =0;
                 }
                 else
                 {
                    motorRunStatu =motorRun;          
                 }    
                 motor->cnts = 0;
                
             }           
           
           }break;       
        }   
   
   
   }

}

void task_1ms_callBack(void)
{
  static uint32_t timesCnt=0,arryIndex=0,pressTimeCnt=0;  
  if (TMR_GetINTStatus(TASK_TIMER, TMR_INT_Overflow) != RESET)
  {
     TMR_ClearITPendingBit(TASK_TIMER, TMR_INT_Overflow);  
     timesCnt ++;
     motor_shake(&motorShakeOnece);
     motor_shake(&motorShakeTwice);
//     if(timesCnt == 20)
//    {
//        timesCnt = 0;
//        if(motorShakeOnece.ifStart)
//        {
//          SHAKE_PWM_SET(sinMotor[arryIndex++]);
//           if (arryIndex >= MOTOR_ARRY_SIZE)  arryIndex =0;
//        }


//        #if LK_DEBUG
//        runStatu=1-runStatu;
//        if(runStatu == 0) led_on();
//        else   led_off();
//        #endif
//    }  
 #if ENABLE_POWER_CTL    
      if(powerKeyPress == true)
      {
        pressTimeCnt++;
        if(pressTimeCnt >=2000)
        {
           if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pins_4 )== Bit_SET)
           {
              ifPowerOn = true;
           }
        }
      }
  #endif
   }

   
}

uint8_t upCnts,downCnts=0,rightCnts=0,leftCnts=0,menuCnts=0;
void remote433_up_callBack(uint16_t remoteData)
{
  motorShakeOnece.ifStart =true;
  upCnts++;
}

void remote433_down_callBack(uint16_t remoteData)
{
  motorShakeTwice.ifStart = true;
  downCnts++;
}

void remote433_right_callBack(uint16_t remoteData)
{
  rightCnts++;
  if(rightCnts ==1) 
  {
      ifShakeLowStart=true;
  }
  else if(rightCnts ==2) 
  {
      ifShakeMidStart = true;
  }
  else if(rightCnts == 3) 
  {
      ifShakeHighStart = true;
  }
  else if(rightCnts == 4) 
  { SHAKE_CLOSE_PWM();  rightCnts=0;   } 
}


void remote433_left_callBack(uint16_t remoteData)
{
  leftCnts++;
}

void remote433_menu_callBack(uint16_t remoteData)
{
  menuCnts++;
}

void  powerKey_ctl(void)
{
    uint8_t bitKey=0;

   while(ifPowerOn != true)
   {
       bitKey = GPIO_ReadInputDataBit(GPIOB,GPIO_Pins_4);
       if(bitKey == Bit_SET)
       {
           Delay_ms(50);
           if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pins_4) == Bit_SET)
           {
              powerKeyPress = true;
           }
           
       }   
   };

   powerKeyPress=false;
   ifPowerOn=false; 
   GPIO_WriteBit(GPIOB,GPIO_Pins_5, Bit_SET);   //Power on
}


void lk_task_init(void)
{
  /*board init*/
  lk_borad_init();
  lk_pwm_init();
  lk_taskTime_init();
  lk_remote_init(remote433_up_callBack,remote433_down_callBack,remote433_left_callBack,remote433_right_callBack,remote433_menu_callBack);  
 #if ENABLE_POWER_CTL
  powerKey_ctl();
 #endif 


}





