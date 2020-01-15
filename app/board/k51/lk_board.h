#ifndef __LK_BOARD_H
#define __LK_BOARD_H
#include "lk_config.h"
#include "at32f4xx.h"
#define ENABLE_MOTOR                  1        //使能电机
#define ENABLE_POWER_CTL              0        //使能电源开关
#define ENABLE_BLE                    1        //使能蓝牙
#define ENABLE_REMOTE_433M            1        //433 遥控器


#if  ENABLE_BLE   
  #include "lk_ble_ops.h"
#endif
#if  ENABLE_REMOTE_433M   
   #include "lk_433m.h"
#endif


/*ble USART*/
#define LK_BLE_USART                   USART3
#define LK_BLE_BAUD_RATE               115200             
#define LK_BLE_UART_TX_PIN             GPIO_Pins_10
#define LK_BLE_UART_RX_PIN             GPIO_Pins_11
#define LK_BLE_UART_GPIO               GPIOB
#define LK_BLE_UART_IRQ                USART3_IRQn
#define LK_BLE_UART_RCC                RCC_APB1PERIPH_USART3
#define LK_BLE_UART_Handle             USART3_IRQHandler

/*EXTI 433M*/
#define LK_EXTI_433M_LINE              EXTI_Line3
#define LK_EXTI_433M_PIN               GPIO_Pins_3
#define LK_EXTI_433M_GPIO              GPIOB     
#define LK_EXTI_433M_SOURCE_GPIO       GPIO_PortSourceGPIOB
#define LK_EXTI_433M_SOURCE_PIN        GPIO_PinsSource3
#define LK_EXTI_433M_RCC               RCC_APB2PERIPH_GPIOB
#define LK_EXTI_433M_AFIO              RCC_APB2PERIPH_AFIO
    
#define LK_EXTI_433M_IQR               EXTI3_IRQn
#define LK_EXTI_433M_IRQ_Handle        EXTI3_IRQHandler

/*timer counter 用于外部捕获计时*/
#define ENABLE_EXTI_COUNTER             1
#define LK_EXTI_TIMER_CNT              TMR2
#define LK_EXTI_TIMER_CNT_RCC          RCC_APB1PERIPH_TMR2
#define LK_EXTI_TIMER_CNT_FREQ         1000000   //1MHZ
#define LK_GET_COUNTER()               TMR_GetCounter(LK_EXTI_TIMER_CNT)  //获取计数值
/*power key*/

#define POWER_KEY_PIN                  GPIO_Pins_5
#define POWER_KEY_GPIO                 GPIOB
/*motor*/    
#define MOTOR_TIM                      TMR3
#define MOTOR_TIM_RCC                  RCC_APB1PERIPH_TMR3
#define MOTOR_PORTA_PIN                GPIO_Pins_6
#define MOTOR_PORTA_GPIO               GPIOA
#define MOTOR_PORTB_PIN                GPIO_Pins_7
#define MOTOR_PORTB_GPIO               GPIOA
/*定时器用于任务*/     
#define TASK_1MS_IRQ                   TMR1_BRK_TMR9_IRQHandler       //1ms定时器    
#define TASK_TIMER                     TMR9                           //计数器定时器
#define TASK_TIMER_RCC                 RCC_APB2PERIPH_TMR9            //计数器定时器时钟
#define TASK_TIMER_NVIC                TMR1_BRK_TMR9_IRQn



#define LK_BOARD_APB1_RCC  LK_EXTI_TIMER_CNT_RCC|LK_BLE_UART_RCC|MOTOR_TIM_RCC
void lk_borad_init(void);
/*motor*2*/

#endif
