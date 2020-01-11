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

/* Includes ------------------------------------------------------------------*/
#include "at32f4xx.h"
#include "at32_board.h"
#include <stdio.h>

//lk include
#include "lk_ble_ops.h"
#include "lk_433m.h"



/** @addtogroup AT32F415_StdPeriph_Examples
  * @{
  */
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
	
	#define LKTMR TMR2               

void lk_pwm_init(void)
{
	//GPIO
  GPIO_InitType GPIO_InitStructure;
	TMR_TimerBaseInitType  TMR_TMReBaseStructure;
	TMR_OCInitType  TMR_OCInitStructure;
  /* GPIOA Configuration:push-pull */
  GPIO_InitStructure.GPIO_Pins = GPIO_Pins_0 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	


	  /* TMR2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1PERIPH_TMR2, ENABLE);
  /* Compute the prescaler value */
  /* TMRe base configuration */
  TMR_TimeBaseStructInit(&TMR_TMReBaseStructure);
  TMR_TMReBaseStructure.TMR_Period = 500;
  TMR_TMReBaseStructure.TMR_DIV = (uint16_t) (SystemCoreClock / 1000000) - 1;
	
  TMR_TMReBaseStructure.TMR_ClockDivision = 0;
  TMR_TMReBaseStructure.TMR_CounterMode = TMR_CounterDIR_Up;

  TMR_TimeBaseInit(LKTMR, &TMR_TMReBaseStructure);	
	
	  /* PWM1 Mode configuration: Channel1 */
  TMR_OCStructInit(&TMR_OCInitStructure);
  TMR_OCInitStructure.TMR_OCMode = TMR_OCMode_PWM1;
  TMR_OCInitStructure.TMR_OutputState = TMR_OutputState_Enable;
  TMR_OCInitStructure.TMR_Pulse = 200;
  TMR_OCInitStructure.TMR_OCPolarity = TMR_OCPolarity_High;

  TMR_OC1Init(LKTMR, &TMR_OCInitStructure);

  TMR_OC1PreloadConfig(LKTMR, TMR_OCPreload_Enable);
  /* TMR enable counter */
  TMR_Cmd(LKTMR, ENABLE);
}

/** @addtogroup USART_Printf
  * @{
  */ 
	uint8_t rxbuf[50] ={0};
	uint32_t cnt;
	uint16_t rxta=0;
	void USART2_IRQHandler(void)
{
  if(USART_GetITStatus(USART2, USART_INT_RDNE) != RESET)
  {
	  	rxta = USART_ReceiveData(USART2);
			frameHandle.ble->push(rxta);  //数据接收
		 rxbuf[cnt++]= rxta;
		 if(cnt >= 50) cnt=0;
	}
}

void usart2_send(uint8_t *buf,uint8_t size )
{
	for(int i=0;i<size;i++)
	{
	  USART_SendData(USART2,(uint16_t)buf[i]);
		while ( USART_GetFlagStatus(USART2, USART_FLAG_TRAC) == RESET );  
	}
  
}


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

/**
  * @brief  Configures the nested vectored interrupt controller.
  * @param  None
  * @retval None
  */
void NVIC_Configuration(void)
{
  NVIC_InitType NVIC_InitStructure;

  /* Configure the NVIC Preemption Priority Bits */  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
  /* Enable the USART2 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
  /* Enable the TMR3 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TMR3_GLOBAL_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /* Enable USART2 Clock */
  RCC_APB1PeriphClockCmd(RCC_APB1PERIPH_USART2, ENABLE);
	
	
}

void usart2_init(void)
{
	//GPIO
	GPIO_InitType GPIO_InitStructure;
	USART_InitType USART_InitStructure;
	  /* Configure USART2 Rx as input floating */
  GPIO_InitStructure.GPIO_Pins = GPIO_Pins_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	  /* Configure USART2 Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pins = GPIO_Pins_2;
  GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//usart
	
  USART_StructInit(&USART_InitStructure);
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    /* Configure USART2 */
  USART_Init(USART2, &USART_InitStructure);
	
	 USART_INTConfig(USART2, USART_INT_RDNE, ENABLE);
	
  /* Enable the USART2 */
  USART_Cmd(USART2, ENABLE);	
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
  /* Enable GPIO clock */
  RCC_APB2PeriphClockCmd(RCC_APB2PERIPH_GPIOA | RCC_APB2PERIPH_GPIOC | RCC_APB2PERIPH_AFIO, ENABLE);

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
	
	NVIC_Configuration();
	
	usart2_init();
	
	Delay_init();
  /* USART1 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
	
	
  UART_Print_Init(115200);

  /* Output a message on Hyperterminal using printf function */
 // lk_pwm_init();
  lk_cap_init();
	//lk init
//	ble_init(usart2_send); //蓝牙初始化
  while (1)
  {
	//	Delay_ms(1000);
		// erroType = frameHandle.ble->myAnasysProcess(); //协议解析
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
  {}
}

#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2018 ArteryTek *****END OF FILE****/ 
