
/**
  ******************************************************************************
  * @file           : lk_board.c
  * @author         : zjk
  * @version        : v1.1
  * 
  * @date           : 
  *                   
  * @brief          : 初始化bsp板上资源
  ******************************************************************************
  */
#include "k51/lk_board.h"

EXTI_InitType   EXTI_InitStructure;
GPIO_InitType   GPIO_InitStructure;

/**
  * @brief  Configures the nested vectored interrupt controller.
  * @param  None
  * @retval None
  */
void lk_nvic_config(void)
{
    NVIC_InitType NVIC_InitStructure;
    /* Configure the NVIC Preemption Priority Bits */  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    /* Enable the USART Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = LK_BLE_UART_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    /* Enable the TMR2 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TASK_TIMER_NVIC;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);    
    
}


void lk_rcc_config(void)
{  
   /* TMR clock enable */
  RCC_APB1PeriphClockCmd(LK_BOARD_APB1_RCC, ENABLE);
  /* GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2PERIPH_GPIOA | RCC_APB2PERIPH_GPIOB | RCC_APB2PERIPH_TMR9|
                         RCC_APB2PERIPH_GPIOC | RCC_APB2PERIPH_AFIO, ENABLE);
}

/**************************************************************************************************
 * @fn  void lk_gpio_init(void)
 *
 * @brief   GPIO初始化
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */
void lk_gpio_init(void)
{
      GPIO_InitType GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pins = GPIO_Pins_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT_PP;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);  

    /* GPIOA Configuration:push-pull */
    GPIO_InitStructure.GPIO_Pins = GPIO_Pins_6 |GPIO_Pins_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

  #if ENABLE_POWER_CTL
    /* GPIO Configuration:push-pull */
    GPIO_InitStructure.GPIO_Pins = POWER_KEY_PIN ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT_PP;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_Init(POWER_KEY_GPIO, &GPIO_InitStructure);
   #endif
    /* GPIO Configuration:push-pull */
    GPIO_InitStructure.GPIO_Pins = GPIO_Pins_4 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_PD;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);    
    
    /* Configure USART Rx as input floating */
    GPIO_InitStructure.GPIO_Pins = LK_BLE_UART_RX_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(LK_BLE_UART_GPIO, &GPIO_InitStructure);
    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pins = LK_BLE_UART_TX_PIN;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;// GPIO_Mode_AF_PP;
    GPIO_Init(LK_BLE_UART_GPIO, &GPIO_InitStructure);
    
    
    
}


/**************************************************************************************************
 * @fn  void ble_uart_init(void)
 *
 * @brief   串口初始化
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */
void ble_uart_init(void)
{
    USART_InitType USART_InitStructure;
    //usart
    USART_StructInit(&USART_InitStructure);
    USART_InitStructure.USART_BaudRate = LK_BLE_BAUD_RATE;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    /* Configure USART */
    USART_Init(LK_BLE_USART, &USART_InitStructure);

    USART_INTConfig(LK_BLE_USART, USART_INT_RDNE, ENABLE);

    /* Enable the USART */
    USART_Cmd(LK_BLE_USART, ENABLE);
}
/**************************************************************************************************
 * @fn void usart_send(uint8_t *buf,uint8_t size )
 *
 * @brief   串口发送接口
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */
void usart_send(uint8_t *buf,uint8_t size )
{
    for(int i=0;i<size;i++)
    {
      USART_SendData(LK_BLE_USART,(uint16_t)buf[i]);
        while ( USART_GetFlagStatus(LK_BLE_USART, USART_FLAG_TRAC) == RESET );  
    }
  
}

uint32_t cnt;
uint16_t rxta=0;
/**************************************************************************************************
 * @fn void LK_UART_Handle(void)
 *
 * @brief   串口中断
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */
void LK_BLE_UART_Handle(void)
{
  if(USART_GetITStatus(LK_BLE_USART, USART_INT_RDNE) != RESET)
  {
     rxta = USART_ReceiveData(LK_BLE_USART);
     frameHandle.ble->push(rxta);  //数据接收
  }
}



/**************************************************************************************************
 * @fn void lk_timerCnt_init(void)
 *
 * @brief  定时器初始化
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */
void lk_timerCnt_init(void)
{
  #if ENABLE_EXTI_COUNTER
  TMR_TimerBaseInitType  TMR_TMReBaseStructure;
  TMR_TimeBaseStructInit(&TMR_TMReBaseStructure);
  TMR_TMReBaseStructure.TMR_Period = 0xffff;
  TMR_TMReBaseStructure.TMR_DIV = (uint16_t) (SystemCoreClock / LK_EXTI_TIMER_CNT_FREQ) - 1;;
  TMR_TMReBaseStructure.TMR_ClockDivision = 0;
  TMR_TMReBaseStructure.TMR_CounterMode = TMR_CounterDIR_Up;

  TMR_TimeBaseInit(LK_EXTI_TIMER_CNT, &TMR_TMReBaseStructure);
  TMR_Cmd(LK_EXTI_TIMER_CNT, ENABLE);
  #endif
}


uint32_t get_tim_counter(void)
{
  return   TMR_GetCounter(LK_EXTI_TIMER_CNT);
}


__IO uint16_t readValue1 = 0, readValue2 = 0;
__IO uint32_t capture = 0;
__IO uint16_t captureNumber = 0;

/**************************************************************************************************
 * @fn void LK_EXTI_433M_IRQ_Handle(void)
 *
 * @brief  433M外部中断
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */
void LK_EXTI_433M_IRQ_Handle(void)
{

    if(EXTI_GetIntStatus(LK_EXTI_433M_PIN) != RESET)
    {
         if(captureNumber == 0)
    {   
    readValue1 = LK_GET_COUNTER();
    captureNumber = 1;
    EXTI_InitStructure.EXTI_Line = LK_EXTI_433M_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineEnable = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    }
    else if(captureNumber == 1)
    {
        EXTI_InitStructure.EXTI_Line = LK_EXTI_433M_LINE;
        EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
        EXTI_InitStructure.EXTI_LineEnable = ENABLE;
        EXTI_Init(&EXTI_InitStructure);  
        readValue2 = LK_GET_COUNTER();  
          /* Capture computation */
        if (readValue2 > readValue1)
        {
        capture = (readValue2 - readValue1); 
        }
        else
        {
        capture = ((0xFFFF - readValue1) + readValue2); 
        }
        captureNumber = 0;
        my433M_anasys(capture);
    }
    EXTI_ClearIntPendingBit(LK_EXTI_433M_LINE);  ///<Clear the  EXTI line 3 pending bit
  }
}

/**************************************************************************************************
 * @fnlk_433m_hardInit(void)
 *
 * @brief  433M外部中断初始化
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */
void lk_433m_hardInit(void)
{
     NVIC_InitType NVIC_InitStructure;   
    GPIO_InitType GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(LK_EXTI_433M_RCC, ENABLE);        ///<Enable  clock
    GPIO_InitStructure.GPIO_Pins = LK_EXTI_433M_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_PD;
    GPIO_Init(LK_EXTI_433M_GPIO, &GPIO_InitStructure);       //<Configure PB3 pin as input floating

    RCC_APB2PeriphClockCmd(LK_EXTI_433M_AFIO, ENABLE);         ///<Enable AFIO clock
    GPIO_EXTILineConfig(LK_EXTI_433M_SOURCE_GPIO, LK_EXTI_433M_SOURCE_PIN); ///<Connect EXTI3 Line to PB3 pin

    EXTI_InitStructure.EXTI_Line = LK_EXTI_433M_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_InitStructure.EXTI_LineEnable = ENABLE;
    EXTI_Init(&EXTI_InitStructure);                              ///<Configure EXTI3 line

    NVIC_InitStructure.NVIC_IRQChannel = LK_EXTI_433M_IQR;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);                              ///
    EXTI_GenerateSWInt(LK_EXTI_433M_LINE); ///<Generate software interrupt: simulate a falling edge applied on EXTI line
}


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
    TMR_TimeBaseInit(MOTOR_TIM, &TMR_TMReBaseStructure);

      /* PWM1 Mode configuration: Channel1 */
    TMR_OCStructInit(&TMR_OCInitStructure);
    TMR_OCInitStructure.TMR_OCMode = TMR_OCMode_PWM1;
    TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
    TMR_OCInitStructure.TMR_Pulse = 0;
    TMR_OCInitStructure.TMR_OCPolarity = TMR_OCPolarity_High;
    TMR_OC1Init(MOTOR_TIM, &TMR_OCInitStructure);
    TMR_OC1PreloadConfig(MOTOR_TIM, TMR_OCPreload_Enable);
    
    
      /* PWM1 Mode configuration: Channel2 */
    TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
    TMR_OCInitStructure.TMR_Pulse = 0;
    TMR_OC2Init(MOTOR_TIM, &TMR_OCInitStructure);
    TMR_OC2PreloadConfig(MOTOR_TIM, TMR_OCPreload_Enable);   

   TMR_ARPreloadConfig(MOTOR_TIM, ENABLE);
    /* TMR enable counter */
    TMR_Cmd(MOTOR_TIM, ENABLE);
}


void  ble_example_test(void)
{
    frameHandle.devUpStatu.adornStatu = 0x01;     //主机佩戴
    frameHandle.devUpStatu.currentGears = 4;      //当前档位
    frameHandle.devUpStatu.currentHeatStatu =     heatMiddleGear;
    frameHandle.devUpStatu.currentMode = 1;
    frameHandle.devUpStatu.currentVoiceStatu = 0;
    frameHandle.devUpStatu.electric = 50;        //电量%
    frameHandle.devUpStatu.product= 4099;        //产品型号
    frameHandle.devUpStatu.runSeconds = 500;     //秒
    frameHandle.devUpStatu.cfgMinute = 9;        //定时分钟数
    frameHandle.devUpStatu.runStatu = 0x01;
    ble_heart_ack(&frameHandle.devUpStatu);
}


/**************************************************************************************************
 * @   lk_borad_init(void)
 *
 * @brief  设备初始化
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */
void lk_borad_init(void)
{
    lk_rcc_config();
    lk_nvic_config();
    lk_gpio_init();

#if  ENABLE_REMOTE_433M
    lk_timerCnt_init();
    lk_433m_hardInit();
#endif
    
#if  ENABLE_BLE
    ble_uart_init();
    ble_init(usart_send); //蓝牙初始化
   // ble_example_test();
#endif
    
#if  ENABLE_MOTOR
    lk_pwm_init();
#endif
}





