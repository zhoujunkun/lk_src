#ifndef __LK_BOARD_H
#define __LK_BOARD_H
#include "lk_config.h"

/*USART*/
#define LK_USART          USART3
#define LK_BAUD_RATE         115200

#define LK_UART_TX_PIN   GPIO_Pins_10
#define LK_UART_RX_PIN   GPIO_Pins_11
#define LK_UART_GPIO     GPIOB
#define LK_UART_IRQ      USART3_IRQn
#define LK_UART_RCC      RCC_APB1PERIPH_USART3
#define LK_UART_Handle   USART3_IRQHandler

/*EXTI 433M*/
#define LK_EXTI_433M_LINE  EXTI_Line3
#define LK_EXTI_433M_PIN   GPIO_Pins_3
#define LK_EXTI_433M_GPIO  GPIOB
#define LK_EXTI_433M_SOURCE_GPIO GPIO_PortSourceGPIOB
#define LK_EXTI_433M_SOURCE_PIN  GPIO_PinsSource3
#define LK_EXTI_433M_RCC       RCC_APB2PERIPH_GPIOB
#define LK_EXTI_433M_AFIO     RCC_APB2PERIPH_AFIO

#define  LK_EXTI_433M_IQR        EXTI3_IRQn
#define  LK_EXTI_433M_IRQ_Handle  EXTI3_IRQHandler

/*timer cnt*/
#define LK_TIMER_CNT     TMR2
#define LK_TIMER_CNT_RCC RCC_APB1PERIPH_TMR2
#define LK_TIMER_CNT_FREQ 1000000   //1MHZ
void lk_borad_init(void);
#endif
