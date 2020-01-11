#include "lk_board.h"
#include "at32f4xx.h"


EXTI_InitType   EXTI_InitStructure;
GPIO_InitType   GPIO_InitStructure;
NVIC_InitType NVIC_InitStructure;
TMR_TimerBaseInitType  TMR_TMReBaseStructure;
/**
  * @brief  Configures the nested vectored interrupt controller.
  * @param  None
  * @retval None
  */
void lk_nvic_config(void)
{
    /* Configure the NVIC Preemption Priority Bits */  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    /* Enable the USART Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = LK_UART_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
/**************************************************************************************************
 * @fn  void lk_uart_init(void)
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
void lk_uart_init(void)
{
 
    /* Enable USART Clock */
    RCC_APB1PeriphClockCmd(LK_UART_RCC, ENABLE);
    RCC_APB2PeriphClockCmd( RCC_APB2PERIPH_GPIOB| RCC_APB2PERIPH_AFIO, ENABLE);

    //GPIO
    GPIO_InitType GPIO_InitStructure;
    USART_InitType USART_InitStructure;
      /* Configure USART Rx as input floating */
    GPIO_InitStructure.GPIO_Pins = LK_UART_RX_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
      /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pins = LK_UART_TX_PIN;
    GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(LK_UART_GPIO, &GPIO_InitStructure);

    //usart
    USART_StructInit(&USART_InitStructure);
    USART_InitStructure.USART_BaudRate = LK_BAUD_RATE;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    /* Configure USART */
    USART_Init(LK_USART, &USART_InitStructure);

     USART_INTConfig(LK_USART, USART_INT_RDNE, ENABLE);

    /* Enable the USART */
    USART_Cmd(LK_USART, ENABLE);
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
      USART_SendData(LK_USART,(uint16_t)buf[i]);
        while ( USART_GetFlagStatus(LK_USART, USART_FLAG_TRAC) == RESET );  
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
void LK_UART_Handle(void)
{
  if(USART_GetITStatus(LK_USART, USART_INT_RDNE) != RESET)
  {
     rxta = USART_ReceiveData(LK_USART);
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
    /* TMR clock enable */
  RCC_APB1PeriphClockCmd(LK_TIMER_CNT_RCC, ENABLE);

  TMR_TimeBaseStructInit(&TMR_TMReBaseStructure);
  TMR_TMReBaseStructure.TMR_Period = 0xffff;
  TMR_TMReBaseStructure.TMR_DIV = (uint16_t) (SystemCoreClock / LK_TIMER_CNT_FREQ) - 1;;
  TMR_TMReBaseStructure.TMR_ClockDivision = 0;
  TMR_TMReBaseStructure.TMR_CounterMode = TMR_CounterDIR_Up;

  TMR_TimeBaseInit(LK_TIMER_CNT, &TMR_TMReBaseStructure);
  TMR_Cmd(LK_TIMER_CNT, ENABLE);
}


uint32_t get_tim_counter(void)
{
  return   TMR_GetCounter(LK_TIMER_CNT);
}

__IO uint16_t readValue1 = 0, readValue2 = 0;
__IO uint32_t capture = 0;
__IO uint16_t captureNumber = 0;
uint32_t bufArray[20] = {0},nums=0;
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
    readValue1 = TMR_GetCounter(LK_TIMER_CNT);
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
        readValue2 = TMR_GetCounter(LK_TIMER_CNT);  
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
    GPIO_InitType GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(LK_EXTI_433M_RCC, ENABLE);        ///<Enable  clock
    GPIO_InitStructure.GPIO_Pins = LK_EXTI_433M_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_PD;
    GPIO_Init(LK_EXTI_433M_GPIO, &GPIO_InitStructure);                       ///<Configure PB3 pin as input floating

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
void lk_exti_init(void)
{
    #if  REMOTE_433M_ENABLE
     lk_433m_hardInit();
    #endif
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
    lk_nvic_config();
    lk_uart_init();
    lk_exti_init();
    lk_timerCnt_init();
    #if  BLE_ENABLE
    ble_init(usart_send); //蓝牙初始化
    #endif

}
