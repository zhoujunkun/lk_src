
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
#include "lk_board.h"

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
	
	/*外部中断*/
    NVIC_InitStructure.NVIC_IRQChannel = LK_EXTI_433M_IQR;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);                              ///
    EXTI_GenerateSWInt(LK_EXTI_433M_LINE); ///<Generate software interrupt: simulate a falling edge applied on EXTI line
    
}


void lk_rcc_config(void)
{  
   /* TMR clock enable */
  RCC_APB1PeriphClockCmd(LK_BOARD_APB1_RCC, ENABLE);
  /* GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2PERIPH_GPIOA | RCC_APB2PERIPH_GPIOB | RCC_APB2PERIPH_TMR9|
                         RCC_APB2PERIPH_GPIOC | RCC_APB2PERIPH_AFIO | RCC_APB2PERIPH_ADC1, ENABLE);

    /* ADCCLK = PCLK2/4 */
    RCC_ADCCLKConfig(RCC_APB2CLK_Div4);

    /* Enable peripheral clocks ------------------------------------------------*/
    /* Enable DMA1 clocks */
    RCC_AHBPeriphClockCmd(RCC_AHBPERIPH_DMA1, ENABLE);
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
    GPIO_InitStructure.GPIO_Pins = MOTOR_PORTA_PIN |MOTOR_PORTB_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);

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
    /*led*/
    GPIO_InitStructure.GPIO_Pins = LED_YELLOW_PIN | LED_BLUE_PIN ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT_PP;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_Init(LED_GPIO, &GPIO_InitStructure);   
    
    /* Configure USART Rx as input floating */
    GPIO_InitStructure.GPIO_Pins = LK_BLE_UART_RX_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(LK_BLE_UART_GPIO, &GPIO_InitStructure);
    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pins = LK_BLE_UART_TX_PIN;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;// GPIO_Mode_AF_PP;
    GPIO_Init(LK_BLE_UART_GPIO, &GPIO_InitStructure); 
    
    /*Exti 433*/
    GPIO_InitStructure.GPIO_Pins = LK_EXTI_433M_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_PD;
    GPIO_Init(LK_EXTI_433M_GPIO, &GPIO_InitStructure);       //<Configure PB3 pin as input floating
    GPIO_EXTILineConfig(LK_EXTI_433M_SOURCE_GPIO, LK_EXTI_433M_SOURCE_PIN); ///<Connect EXTI3 Line to PB3 pin
 

    /* ADC-------------------------*/
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pins = BOOST_FB_ADC_PIN | BAT_ADC_PIN ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_ANALOG;
    GPIO_Init(ADC_GPIO, &GPIO_InitStructure);
    
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pins = HEAT_ADC_PIN ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_ANALOG;
    GPIO_Init(HEAT_GPIO, &GPIO_InitStructure);
    
    //check IO statu
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pins = USB_CHECK_PIN ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_PD;
    GPIO_Init(USB_CHECK_GPIO, &GPIO_InitStructure);  
    //bat is full check
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pins = BAT_CHECK_PIN ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_PU;
    GPIO_Init(BAT_CHECK_GPIO, &GPIO_InitStructure); 
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
#ifndef RTE_USING_FINSH
    USART_INTConfig(LK_BLE_USART, USART_INT_RDNE, ENABLE);  //非空中断使能
#endif
    /* Enable the USART */
    USART_Cmd(LK_BLE_USART, ENABLE);
}
#ifdef RTE_USING_FINSH



char  rt_hw_console_getchar(void)
{
    int ch=-1;

    if( USART_GetFlagStatus(LK_BLE_USART,USART_FLAG_RDNE) ==SET )
    {
        ch = USART_ReceiveData(LK_BLE_USART);
    }
//	else
//	{
//	   if(IS_USART_FLAG(USART_FLAG_ORERR))
//	   {
//	     USART_ClearFlag(LK_BLE_USART,USART_FLAG_ORERR);
//	   }
//	   rt_thread_mdelay (10);
//	}

	return  ch;
}
uint16_t dat1=0,dat2=0;
void rt_hw_console_output(const char *str)
{
    rt_size_t i=0,size = 0;
    size = rt_strlen(str);
    char a = '\r';

    for (i = 0; i < size; i++)
    {
        if (*(str + i) == '\n')
        {
           USART_SendData(LK_BLE_USART,a);
            while ( USART_GetFlagStatus(LK_BLE_USART, USART_FLAG_TRAC) == RESET ); 
        }
        dat2 =*(uint8_t *)(str + i);
        USART_SendData(LK_BLE_USART, dat2);
        while ( USART_GetFlagStatus(LK_BLE_USART, USART_FLAG_TRAC) == RESET ); 
    }
}

#endif
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
	#ifndef RTE_USING_FINSH
    for(int i=0;i<size;i++)
    {
      USART_SendData(LK_BLE_USART,(uint16_t)buf[i]);
        while ( USART_GetFlagStatus(LK_BLE_USART, USART_FLAG_TRAC) == RESET );  
    }
   #endif
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
 * @brief  ADC 初始化
 * input parameters
 *
 * @None
 * output parameters
 *
 * None.
 *
 * @return None.
 */


void  lk_damAdc_init(uint16_t *adcBuf, uint8_t size)
{
    DMA_InitType DMA_InitStructure;
    ADC_InitType ADC_InitStructure;
    /* DMA1    channel1 configuration ----------------------------------------------*/
    DMA_Reset(DMA1_Channel1);
    DMA_DefaultInitParaConfig(&DMA_InitStructure);
    DMA_InitStructure.DMA_PeripheralBaseAddr    = (uint32_t)&ADC1->RDOR;
    DMA_InitStructure.DMA_MemoryBaseAddr        = (uint32_t)adcBuf;
    DMA_InitStructure.DMA_Direction             = DMA_DIR_PERIPHERALSRC;
    DMA_InitStructure.DMA_BufferSize            = size;
    DMA_InitStructure.DMA_PeripheralInc         = DMA_PERIPHERALINC_DISABLE;
    DMA_InitStructure.DMA_MemoryInc             = DMA_MEMORYINC_ENABLE;
    DMA_InitStructure.DMA_PeripheralDataWidth   = DMA_PERIPHERALDATAWIDTH_HALFWORD;
    DMA_InitStructure.DMA_MemoryDataWidth       = DMA_MEMORYDATAWIDTH_HALFWORD;
    DMA_InitStructure.DMA_Mode                  = DMA_MODE_CIRCULAR;
    DMA_InitStructure.DMA_Priority              = DMA_PRIORITY_HIGH;
    DMA_InitStructure.DMA_MTOM                  = DMA_MEMTOMEM_DISABLE;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    /* Enable DMA1 channel1 */
    DMA_ChannelEnable(DMA1_Channel1, ENABLE);
    

      
	/* ADC1 configuration ------------------------------------------------------*/
    ADC_StructInit(&ADC_InitStructure);
    ADC_InitStructure.ADC_Mode              = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanMode          = ENABLE;
    ADC_InitStructure.ADC_ContinuousMode    = ENABLE;
    ADC_InitStructure.ADC_ExternalTrig      = ADC_ExternalTrig_None;
    ADC_InitStructure.ADC_DataAlign         = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NumOfChannel      = 3;
    ADC_Init(ADC1, &ADC_InitStructure);

    /* ADC1 regular channels configuration */ 
    ADC_RegularChannelConfig(ADC1, BOOST_FB_ADC, 1, ADC_SampleTime_239_5);  
    ADC_RegularChannelConfig(ADC1, BAT_ADC, 2, ADC_SampleTime_239_5); 
    //ADC_RegularChannelConfig(ADC1, BOOST_VERF_VOLT, 3, ADC_SampleTime_239_5); 
    ADC_RegularChannelConfig(ADC1, HEAT_ADC, 3, ADC_SampleTime_239_5);        
    /* Enable ADC1 DMA */
    ADC_DMACtrl(ADC1, ENABLE);

    /* Enable ADC1 */
    ADC_Ctrl(ADC1, ENABLE);

    /* Enable ADC1 reset calibration register */   
    ADC_RstCalibration(ADC1);
    /* Check the end of ADC1 reset calibration register */
    while(ADC_GetResetCalibrationStatus(ADC1));

    /* Start ADC1 calibration */
    ADC_StartCalibration(ADC1);
    /* Check the end of ADC1 calibration */
    while(ADC_GetCalibrationStatus(ADC1));
    /* Start ADC1 Software Conversion */ 
    ADC_SoftwareStartConvCtrl(ADC1, ENABLE);
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
//定时器计时外部脉宽
    TMR_TimerBaseInitType  TMR_TMReBaseStructure;
    TMR_TimeBaseStructInit(&TMR_TMReBaseStructure);
    TMR_TMReBaseStructure.TMR_Period = 0xffff;
    TMR_TMReBaseStructure.TMR_DIV = (uint16_t) (SystemCoreClock / LK_EXTI_TIMER_CNT_FREQ) - 1;;
    TMR_TMReBaseStructure.TMR_ClockDivision = 0;
    TMR_TMReBaseStructure.TMR_CounterMode = TMR_CounterDIR_Up;

	TMR_TimeBaseInit(LK_EXTI_TIMER_CNT, &TMR_TMReBaseStructure);
	TMR_Cmd(LK_EXTI_TIMER_CNT, ENABLE);  //使能
    
    
    HARDWARE_433M_DISABLE; //不使能433M外部中断
}


void lk_motor_init(void)
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
   // TMR_Cmd(MOTOR_TIM, ENABLE);
    TMR_Cmd(MOTOR_TIM, DISABLE);
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
static int lk_borad_init(void)
{
    lk_rcc_config();
    lk_nvic_config();
    lk_gpio_init();

#if  ENABLE_REMOTE_433M
    lk_433m_hardInit();
#endif
    
#if  BLE_ENABLE
  
    ble_uart_init();
    ble_init(usart_send); //蓝牙初始化
   // ble_example_test();
#endif
    
#if  ENABLE_MOTOR
    lk_motor_init();
#endif
 
    return 0;
}


INIT_BOARD_EXPORT(lk_borad_init);


