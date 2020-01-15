/**
  ******************************************************************************
  * @file    USART/Printf/main.c 
  * @author  Artery Technology 
  * @version V1.1.2
  * @date    2019-01-04
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, ARTERYTEK SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2018 ArteryTek</center></h2>
  ******************************************************************************
  */ 
#if 1
/* Includes ------------------------------------------------------------------*/
#include "at32f4xx.h"
#include "at32_board.h"
#include <stdio.h>

//lk include
#include "lk_board.h"
#include  "lk_task.h"
#define CAPTURE_TIM_EABLE  0





//irq
#if LK_DEBUG
#define led_on()  GPIO_WriteBit(GPIOA,GPIO_Pins_1, Bit_RESET)
#define led_off() GPIO_WriteBit(GPIOA,GPIO_Pins_1, Bit_SET) 
#endif


void TMR1_BRK_TMR9_IRQHandler(void)                                  
{
     task_1ms_callBack();
}



#if CAPTURE_TIM_EABLE
	
__IO uint16_t IC3ReadValue1 = 0, IC3ReadValue2 = 0;
__IO uint32_t Capture = 0;	
__IO uint16_t CaptureNumber = 0;
__IO uint32_t TMR3Freq = 0;
/**
  * @brief  This function handles TMR3 global interrupt request.
  * @param  None
  * @retval None
  */
	uint32_t testCnt=0;
	bool ifHead=false,ifdata=false;
void TMR3_GLOBAL_IRQHandler(void)
{ 
  if(TMR_GetINTStatus(TMR3, TMR_INT_CC2) == SET) 
  {
    /* Clear TMR3 Capture compare interrupt pending bit */
    TMR_ClearITPendingBit(TMR3, TMR_INT_CC2);
		#if 1
    if(CaptureNumber == 0)
    {
      /* Get the Input Capture value */
      IC3ReadValue1 = TMR_GetCapture2(TMR3);
      CaptureNumber = 1;
    }
    else if(CaptureNumber == 1)
    {
      /* Get the Input Capture value */
      IC3ReadValue2 = TMR_GetCapture2(TMR3); 
      
      /* Capture computation */
      if (IC3ReadValue2 > IC3ReadValue1)
      {
        Capture = (IC3ReadValue2 - IC3ReadValue1); 
      }
      else
      {
        Capture = ((0xFFFF - IC3ReadValue1) + IC3ReadValue2); 
      }
      /* Frequency computation */ 
      //TMR3Freq = (uint32_t) 1000000 / Capture;
      CaptureNumber = 0;
			#endif
			//IC3ReadValue1 = TMR3->CC2;
				
			my433M_anasys(Capture);
			 
    }
		
  }

}	
#endif



  















#if CAPTURE_TIM_EABLE
#define LKTMR TMR2               
uint16_t PrescalerValue = 0;
void lk_cap_init(void)
{
	//GPIO
  GPIO_InitType GPIO_InitStructure;
	TMR_TimerBaseInitType  TMR_TMReBaseStructure;
	TMR_ICInitType  TMR_ICInitStructure;
	TMR_OCInitType  TMR_OCInitStructure;
  /* TMR3 channel 2 pin (PA.07) configuration */
  GPIO_InitStructure.GPIO_Pins =  GPIO_Pins_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_PU;
  GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);
	


	/* TMRe base configuration */
  TMR_TimeBaseStructInit(&TMR_TMReBaseStructure);
  TMR_TMReBaseStructure.TMR_Period = 0xffff;
  TMR_TMReBaseStructure.TMR_DIV = (uint16_t) (SystemCoreClock / 1000000)-1;;
	
  TMR_TMReBaseStructure.TMR_ClockDivision = 0;
  TMR_TMReBaseStructure.TMR_CounterMode = TMR_CounterDIR_Up;

  TMR_TimeBaseInit(TMR3, &TMR_TMReBaseStructure);
  TMR_ICStructInit(&TMR_ICInitStructure);
  TMR_ICInitStructure.TMR_Channel = TMR_Channel_2;
  TMR_ICInitStructure.TMR_ICPolarity = TMR_ICPolarity_Rising;
  TMR_ICInitStructure.TMR_ICSelection = TMR_ICSelection_DirectTI;
  TMR_ICInitStructure.TMR_ICDIV = TMR_ICDIV_DIV1;
  TMR_ICInitStructure.TMR_ICFilter = 0x0;

  TMR_ICInit(TMR3, &TMR_ICInitStructure);
  
  /* TMR enable counter */
  TMR_Cmd(TMR3, ENABLE);

  /* Enable the CC2 Interrupt Request */
  TMR_INTConfig(TMR3, TMR_INT_CC2, ENABLE);
}


#endif



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */
void RCC_Configuration(void)
{  
#if 0    
  /*clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1PERIPH_TMR3 | RCC_APB1PERIPH_USART3 |RCC_APB1PERIPH_TMR2, ENABLE);	
  /* Enable GPIO clock */
  RCC_APB2PeriphClockCmd(RCC_APB2PERIPH_GPIOA | RCC_APB2PERIPH_GPIOB|RCC_APB2PERIPH_GPIOC | RCC_APB2PERIPH_AFIO, ENABLE);
#endif

   /* TMR3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1PERIPH_TMR3 | RCC_APB1PERIPH_TMR2 | RCC_APB1PERIPH_USART3 , ENABLE);    //| RCC_APB1PERIPH_USART3

  /* GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2PERIPH_GPIOA | RCC_APB2PERIPH_GPIOB |
                         RCC_APB2PERIPH_GPIOC | RCC_APB2PERIPH_AFIO, ENABLE);
}

int erroType=0;
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{  
    RCC_Configuration();
 //   NVIC_Configuration();
    Delay_init();
  /* USART1 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */

   // UART_Print_Init(115200);
    lk_task_init();
      
  

    while (1)
  {
   //Delay_ms(200);
   erroType = frameHandle.ble->myAnasysProcess(); //协议解析
    //	printf("\n\rcapture=%d, cnt=%d\n\r",Capture,testCnt);
  }
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
	  
	}
}

#endif

/**
  * @}
  */ 

/**
  * @}
  */ 
#endif


#if 0
 #include "at32f4xx.h"

/** @addtogroup AT32F415_StdPeriph_Examples
  * @{
  */

/** @addtogroup TMR_PWM_Output
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TMR_TimerBaseInitType  TMR_TMReBaseStructure;
TMR_OCInitType  TMR_OCInitStructure;
uint16_t CCR1_Val = 333;
uint16_t CCR2_Val = 249;
uint16_t CCR3_Val = 166;
uint16_t CCR4_Val = 83;
uint16_t PrescalerValue = 0;

/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void GPIO_Configuration(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       file (startup_at32f413_xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_at32f4xx.c file
     */

  /* System Clocks Configuration */
  RCC_Configuration();

  /* GPIO Configuration */
  GPIO_Configuration();

  /* -----------------------------------------------------------------------
    TMR3 Configuration: generate 4 PWM signals with 4 different duty cycles:
    The TMR3CLK frequency is set to SystemCoreClock (Hz), to get TMR3 counter
    clock at 24 MHz the Prescaler is computed as following:
     - Prescaler = (TMR3CLK / TMR3 counter clock) - 1

    The TMR3 is running at 36 KHz: TMR3 Frequency = TMR3 counter clock/(ARR + 1)
                                                  = 24 MHz / 666 = 36 KHz
    TMR3 Channel1 duty cycle = (TMR3_CCR1/ TMR3_ARR)* 100 = 50%
    TMR3 Channel2 duty cycle = (TMR3_CCR2/ TMR3_ARR)* 100 = 37.5%
    TMR3 Channel3 duty cycle = (TMR3_CCR3/ TMR3_ARR)* 100 = 25%
    TMR3 Channel4 duty cycle = (TMR3_CCR4/ TMR3_ARR)* 100 = 12.5%
  ----------------------------------------------------------------------- */
  /* Compute the prescaler value */
  PrescalerValue = (uint16_t) (SystemCoreClock / 24000000) - 1;
  /* TMRe base configuration */
  TMR_TimeBaseStructInit(&TMR_TMReBaseStructure);
  TMR_TMReBaseStructure.TMR_Period = 665;
  TMR_TMReBaseStructure.TMR_DIV = PrescalerValue;
	
  TMR_TMReBaseStructure.TMR_ClockDivision = 0;
  TMR_TMReBaseStructure.TMR_CounterMode = TMR_CounterDIR_Up;

  TMR_TimeBaseInit(TMR3, &TMR_TMReBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
  TMR_OCStructInit(&TMR_OCInitStructure);
  TMR_OCInitStructure.TMR_OCMode = TMR_OCMode_PWM1;
  TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
  TMR_OCInitStructure.TMR_Pulse = CCR1_Val;
  TMR_OCInitStructure.TMR_OCPolarity = TMR_OCPolarity_High;

  TMR_OC1Init(TMR3, &TMR_OCInitStructure);

  TMR_OC1PreloadConfig(TMR3, TMR_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel2 */
  TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
  TMR_OCInitStructure.TMR_Pulse = CCR2_Val;

  TMR_OC2Init(TMR3, &TMR_OCInitStructure);

  TMR_OC2PreloadConfig(TMR3, TMR_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel3 */
  TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
  TMR_OCInitStructure.TMR_Pulse = CCR3_Val;

  TMR_OC3Init(TMR3, &TMR_OCInitStructure);

  TMR_OC3PreloadConfig(TMR3, TMR_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel4 */
  TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
  TMR_OCInitStructure.TMR_Pulse = CCR4_Val;

  TMR_OC4Init(TMR3, &TMR_OCInitStructure);

  TMR_OC4PreloadConfig(TMR3, TMR_OCPreload_Enable);

  TMR_ARPreloadConfig(TMR3, ENABLE);

  /* TMR3 enable counter */
  TMR_Cmd(TMR3, ENABLE);

  while (1)
  {}
}

/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */
void RCC_Configuration(void)
{
  /* TMR3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1PERIPH_TMR3, ENABLE);

  /* GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2PERIPH_GPIOA | RCC_APB2PERIPH_GPIOB |
                         RCC_APB2PERIPH_GPIOC | RCC_APB2PERIPH_AFIO, ENABLE);
}

/**
  * @brief  Configure the TMR3 Ouput Channels.
  * @param  None
  * @retval None
  */
void GPIO_Configuration(void)
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

    GPIO_InitStructure.GPIO_Pins = GPIO_Pins_0 | GPIO_Pins_1;
    GPIO_Init(GPIOB, &GPIO_InitStructure);    
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  while (1)
  {}
}

#endif
#endif

/******************* (C) COPYRIGHT 2018 ArteryTek *****END OF FILE****/ 
