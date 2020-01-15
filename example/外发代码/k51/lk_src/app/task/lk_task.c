
/**
  ******************************************************************************
  * @file           : lk_task.c
  * @author         : zjk
  * @version        : v1.1
  * 
  * @date           : 
  *                   
  * @brief          : 
  ******************************************************************************
  */
#include "task/lk_task.h"

 /*delay variable*/
static __IO float fac_us;
static __IO float fac_ms;
/*delay macros*/
#define STEP_DELAY_MS	500


#define SHAKE_ONCE_TIME 200
#define SHAKE_TWICE_TIME 200

#define SHAKE_LOW_PWM()       MOTOR_TIM->CC1=800
#define SHAKE_MID_PWM()       MOTOR_TIM->CC1=500
#define SHAKE_HIGH_PWM()      MOTOR_TIM->CC1=200
#define SHAKE_CLOSE_PWM()     MOTOR_TIM->CC1=0

#define SHAKE_PWM_SET(DATA)   MOTOR_TIM->CC1=DATA
#define MOTOR_ARRY_SIZE 64


#define motor_shakeOnce_trig()  motorShakeOnece.ifStart =true
#define motor_shakeTwice_trig() motorShakeTwice.ifStart =true    

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





//任务定时器初始化
void lk_taskTime_init(void)
{
    TMR_TimerBaseInitType  TMR_TMReBaseStructure;

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


//电机震动控制
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
  #if ENABLE_MOTOR
     motor_shake(&motorShakeOnece);
     motor_shake(&motorShakeTwice);
//    timesCnt ++;      
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
  #endif
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
/**********************************433m remote****************************************/

uint8_t upCnts,downCnts=0,rightCnts=0,leftCnts=0,menuCnts=0;
/*433上按键回调函数*/
void remote433_up_callBack(uint16_t remoteData)
{
  motorShakeOnece.ifStart =true;
  upCnts++;
}
/*433下按键回调函数*/
void remote433_down_callBack(uint16_t remoteData)
{
  motorShakeTwice.ifStart = true;
  downCnts++;
}
/*433右按键回调函数*/
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

/*433上按键回调函数*/
void remote433_left_callBack(uint16_t remoteData)
{
  leftCnts++;
}
/*433功能按键回调函数*/
void remote433_menu_callBack(uint16_t remoteData)
{
  menuCnts++;
}
/**********************************433m remote end****************************************/
/*电源开关按键*/
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
   GPIO_WriteBit(GPIOB,GPIO_Pins_5, Bit_SET);   //Power on
}

/*初始化*/
void lk_task_init(void)
{ 
  lk_borad_init();           /*board init*/      
   
  lk_taskTime_init();   

  #if ENABLE_POWER_CTL
    powerKey_ctl();
  #endif     
    
  #if ENABLE_REMOTE_433M
  lk_remote_init(remote433_up_callBack,remote433_down_callBack,remote433_left_callBack,remote433_right_callBack,remote433_menu_callBack);
  #endif    


}
int erroType=0;
void ble_task(void)
{
 erroType = frameHandle.ble->myAnasysProcess(); //协议解析
}

/**
  * @brief  initialize Delay function   
  * @param  None
  * @retval None
  */		   
void Delay_init()
{
  /*Config Systick*/
  SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
  fac_us=(float)SystemCoreClock/(8 * 1000000);
  fac_ms=fac_us*1000;
}

/**
  * @brief  Inserts a delay time.
  * @param  nus: specifies the delay time length, in microsecond.
  * @retval None
  */
void Delay_us(u32 nus)
{
  u32 temp;
  SysTick->LOAD = (u32)(nus*fac_us);
  SysTick->VAL = 0x00;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ;
  do
  {
    temp = SysTick->CTRL;
  }while((temp & 0x01) &&! (temp & (1<<16)));

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->VAL = 0X00;
}
 
/**
  * @brief  Inserts a delay time.
  * @param  nms: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay_ms(u16 nms)
{
  u32 temp;
  while(nms)
  {
    if(nms > STEP_DELAY_MS)
    {
      SysTick->LOAD = (u32)(STEP_DELAY_MS * fac_ms);
      nms -= STEP_DELAY_MS;
    }
    else
    {
      SysTick->LOAD = (u32)(nms * fac_ms);
      nms = 0;
    }
    SysTick->VAL = 0x00;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    do
    {
      temp = SysTick->CTRL;
    }while( (temp & 0x01) && !(temp & (1<<16)) );

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL = 0X00;
  }
}

/**
  * @brief  Inserts a delay time.
  * @param  sec: specifies the delay time length, in seconds.
  * @retval None
  */
void Delay_sec(u16 sec)
{
  u16 i;
  for(i=0; i<sec; i++)
  {
    Delay_ms(500);
    Delay_ms(500);
  }
}

