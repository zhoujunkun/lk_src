
/****************************************************************************************************//**
 * @file     CMSDK_CM0.h
 *
 * @brief    CMSIS Cortex-M0 Peripheral Access Layer Header File for
 *           CMSDK_CM0 from .
 *
 * @version  V1.1
 * @date     28. August 2018
 *
 * @note     Generated with SVDConv V2.86d 
 *           from CMSIS SVD File 'ME32F030.svd' Version 1.1,
 *******************************************************************************************************/



/** @addtogroup (null)
  * @{
  */

/** @addtogroup CMSDK_CM0
  * @{
  */

#ifndef CMSDK_CM0_H
#define CMSDK_CM0_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* -------------------  Cortex-M0 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */
  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* --------------------  CMSDK_CM0 Specific Interrupt Numbers  -------------------- */
  WAKEUP_IRQn                   =   0,              /*!<   0  WAKEUP interrupt                                                 */
  PMWFAULT_IRQn                 =   1,              /*!<   1  PWM fault interrupt                                              */
  I2C_IRQn                      =   2,              /*!<   2  I2C interrupt                                                    */
  TIM0_IRQn                     =   3,              /*!<   3  TIM0 interrupt                                                   */
  TIM1_IRQn                     =   4,              /*!<   4  TIM1 interrupt                                                   */
  TIM6_IRQn                     =   5,              /*!<   5  TIM6 interrupt                                                   */
  TIM7_IRQn                     =   6,              /*!<   6  TIM7 interrupt                                                   */
  UART0_IRQn                    =   7,              /*!<   7  UART0 interrupt                                                  */
  UART1_IRQn                    =   8,              /*!<   8  UART1 interrupt                                                  */
  ADC_IRQn                      =   9,              /*!<   9  ADC interrupt                                                    */
  WDT_IRQn                      =  10,              /*!<  10  WDT interrupt                                                    */
  BOD_IRQn                      =  11,              /*!<  11  BOD interrupt                                                    */
  PA_IRQn                       =  12,              /*!<  12  PA interrupt                                                     */
  PB_IRQn                       =  13,              /*!<  13  PB interrupt                                                     */
  PC_IRQn                       =  14,              /*!<  14  PC interrupt                                                     */
  SPI_IRQn                      =  16,              /*!<  16  SPI interrupt                                                    */
  PWM_IRQn                      =  17,              /*!<  17  PWM Event interrupt                                              */
  TOUCH_IRQn                    =  18,              /*!<  18  CAP TOUCH interrupt                                              */
  PD_IRQn                       =  19,              /*!<  19  PD interrupt                                                     */
  TIM2_IRQn                     =  22,              /*!<  22  TIM2 interrupt                                                   */
  TIM3_IRQn                     =  23               /*!<  23  TIM3 interrupt                                                   */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M0 Processor and Core Peripherals---------------- */
#define __CM0_REV                 0x0000            /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __NVIC_PRIO_BITS               2            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0.h"                               /*!< Cortex-M0 processor and core peripherals                              */
#include "system_CMSDK.h"                       /*!< CMSDK_CM0 System                                                      */


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif



/* ================================================================================ */
/* ================                       DIA                      ================ */
/* ================================================================================ */


/**
  * @brief Device information array (DIA)
  */

typedef struct {                                    /*!< DIA Structure                                                         */
  __I  uint32_t  RESERVED;
  __I  uint32_t  FUNCDESC;                          /*!< Device function description                                           */
  __I  uint32_t  DID;                               /*!< Device ID                                                             */
  __I  uint32_t  VERID;                             /*!< Hardware version                                                      */
  __I  uint32_t  UNIQUEID0;                         /*!< Unique device serial no- low 32-bit                                   */
  __I  uint32_t  UNIQUEID1;                         /*!< Unique device serial no- high 32-bit                                  */
  __I  uint32_t  IRCTRIM;                           /*!< Internal IRC 40M trim value                                           */
  __I  uint32_t  IRC40;                             /*!< Internal IRC 40M True value                                           */
  __I  uint32_t  IRCTRIM48;                         /*!< Internal IRC 48MHz trim value                                         */
  __I  uint32_t  IRC48;                             /*!< Internal IRC 48MHz true value                                         */
} DIA_Type;


/* ================================================================================ */
/* ================                       I2C                      ================ */
/* ================================================================================ */


/**
  * @brief two wires serial communication interface (I2C)
  */

typedef struct {                                    /*!< I2C Structure                                                         */
  
  union {
    __IO uint32_t  CONSET;                          /*!< I2C control set bit register                                          */
    
    struct {
      __IO uint32_t  TXRX       :  1;               /*!< Transmit receive flag                                                 */
      __IO uint32_t  MASL       :  1;               /*!< Master/slave flag                                                     */
      __IO uint32_t  AA         :  1;               /*!< Assert acknowledge flag                                               */
      __IO uint32_t  SI         :  1;               /*!< I2C interrupt flag                                                    */
      __IO uint32_t  STO        :  1;               /*!< STOP flag                                                             */
      __IO uint32_t  STA        :  1;               /*!< START flag                                                            */
      __IO uint32_t  I2CEN      :  1;               /*!< I2C interface enable                                                  */
    } CONSET_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  STAT;                            /*!< I2C state register                                                    */
    
    struct {
      __I  uint32_t  STATUS     :  7;               /*!< These bits give the actual status information about the I2C
                                                         interface                                                             */
           uint32_t             :  1;
      __I  uint32_t  SLVADDMATCH:  1;               /*!< Slave address matched                                                 */
      __I  uint32_t  SLVRXBUFFULL:  1;              /*!< Slave receiver buffer is full                                         */
      __I  uint32_t  SLVTXBUFEMPTY:  1;             /*!< Slave transmitter buffer is empty                                     */
    } STAT_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAT;                             /*!< I2C data register                                                     */
    
    struct {
      __IO uint32_t  DATA       :  8;               /*!< This register holds data values that have been received or are
                                                         to be transmitted                                                     */
    } DAT_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADR0;                            /*!< I2C Slave Address Register 0                                          */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  ADDR       :  7;               /*!< The I2C device address for slave mode                                 */
    } ADR0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SCLH;                            /*!< Duty Cycle Register High Half Word                                    */
    
    struct {
      __IO uint32_t  SCLH       : 16;               /*!< Count for I2C high time period selection                              */
    } SCLH_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SCLL;                            /*!< Duty Cycle Register Low Half Word                                     */
    
    struct {
      __IO uint32_t  SCLL       : 16;               /*!< Count for I2C low time period selection                               */
    } SCLL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  CONCLR;                          /*!< I2C Control Clear Register                                            */
    
    struct {
      __O  uint32_t  TXRX       :  1;               /*!< TX/RX select Clear bit                                                */
      __O  uint32_t  MASL       :  1;               /*!< Master/slave select Clear bit                                         */
      __O  uint32_t  AAC        :  1;               /*!< Assert acknowledge Clear bit                                          */
      __O  uint32_t  SIC        :  1;               /*!< Interrupt Clear bit                                                   */
           uint32_t             :  1;
      __O  uint32_t  STAC       :  1;               /*!< START flag Clear bit                                                  */
      __O  uint32_t  I2CENC     :  1;               /*!< I2C interface Disable bit                                             */
    } CONCLR_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  ADR1;                            /*!< I2C Slave Address Register 1                                          */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  ADDR       :  7;               /*!< The I2C device address for slave mode                                 */
    } ADR1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADR2;                            /*!< I2C slave address register2                                           */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  ADDR       :  7;               /*!< The I2C device address for slave mode                                 */
    } ADR2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADR3;                            /*!< I2C slave address register3                                           */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  ADDR       :  7;               /*!< The I2C device address for slave mode                                 */
    } ADR3_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DATA_BUFFER;                     /*!< I2C data buffer register                                              */
    
    struct {
      __I  uint32_t  DATA       :  8;               /*!< This register holds contents of the 8 MSBs of the DAT shift
                                                         register                                                              */
    } DATA_BUFFER_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MASK0;                           /*!< I2C address mask register0                                            */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  MASK       :  7;               /*!< Mask bits                                                             */
    } MASK0_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MASK1;                           /*!< I2C address mask register1                                            */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  MASK       :  7;               /*!< Mask bits                                                             */
    } MASK1_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MASK2;                           /*!< I2C address mask register2                                            */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  MASK       :  7;               /*!< Mask bits                                                             */
    } MASK2_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MASK3;                           /*!< I2C address mask register3                                            */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  MASK       :  7;               /*!< Mask bits                                                             */
    } MASK3_b;                                      /*!< BitSize                                                               */
  };
} I2C_Type;


/* ================================================================================ */
/* ================                       WDT                      ================ */
/* ================================================================================ */


/**
  * @brief Watch dog (WDT)
  */

typedef struct {                                    /*!< WDT Structure                                                         */
  
  union {
    __IO uint32_t  MOD;                             /*!< WDT mode register                                                     */
    
    struct {
      __IO uint32_t  WDEN       :  1;               /*!< Watchdog enable bit                                                   */
      __IO uint32_t  WDRESET    :  1;               /*!< Watchdog reset enable bit                                             */
      __IO uint32_t  WDTOF      :  1;               /*!< Watchdog time-out flag                                                */
      __IO uint32_t  WDINT      :  1;               /*!< To be filled                                                          */
      __IO uint32_t  WDPROTECT  :  1;               /*!< Watchdog update mode                                                  */
      __IO uint32_t  WDLOCKCLK  :  1;               /*!< Watchdog clock lock bit                                               */
      __IO uint32_t  WDLOCKDP   :  1;               /*!< Power-down disable bit                                                */
      __IO uint32_t  WDLOCKEN   :  1;               /*!< Watchdog enables and reset lockout bit                                */
    } MOD_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TC;                              /*!< Watchdog timer constant register                                      */
    
    struct {
      __IO uint32_t  WDTC       : 24;               /*!< Watchdog time-out interval                                            */
    } TC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  FEED;                            /*!< Watchdog feed sequence register                                       */
    
    struct {
      __O  uint32_t  WDFEED     :  8;               /*!< Feed value should be 0xAA followed by 0x55                            */
    } FEED_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TV;                              /*!< Watchdog timer value register                                         */
    
    struct {
      __I  uint32_t  WDTV       : 24;               /*!< Counter timer value                                                   */
    } TV_b;                                         /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  WARNINT;                         /*!< Watchdog Warning Interrupt compares value                             */
    
    struct {
      __IO uint32_t  WARNINT    : 10;               /*!< Watchdog warning interrupt compare value                              */
    } WARNINT_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  WINDOW;                          /*!< Watchdog Window compares value                                        */
    
    struct {
      __IO uint32_t  WDWINDOW   : 24;               /*!< Watchdog window value                                                 */
    } WINDOW_b;                                     /*!< BitSize                                                               */
  };
} WDT_Type;


/* ================================================================================ */
/* ================                      UART0                     ================ */
/* ================================================================================ */


/**
  * @brief Universal asynchronous receiver/transmitter (UART0)
  */

typedef struct {                                    /*!< UART0 Structure                                                       */
  __IO uint32_t  DATA;                              /*!< RX TX Data Register                                                   */
  
  union {
    __IO uint32_t  STATE;                           /*!< State of current RX and TX FIFO                                       */
    
    struct {
      __IO uint32_t  TXE        :  1;               /*!< Transmit FIFO empty flag                                              */
      __IO uint32_t  RXNE       :  1;               /*!< Receiver FIFO not empty flag                                          */
      __IO uint32_t  TXF        :  1;               /*!< Transmit FIFO full flag                                               */
      __IO uint32_t  RXF        :  1;               /*!< Receiver FIFO full flag                                               */
      __IO uint32_t  TXHLF      :  1;               /*!< Transmit FIFO half full flag                                          */
      __IO uint32_t  RXHLF      :  1;               /*!< Receiver FIFO half full flag                                          */
      __IO uint32_t  PARIERR    :  1;               /*!< Receiver parity error flag                                            */
      __IO uint32_t  OVERRUN    :  1;               /*!< Receiver overrun error flag                                           */
    } STATE_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTRL;                            /*!< Control UART interrupt enable and disable                             */
    
    struct {
      __IO uint32_t  TXEIE      :  1;               /*!< TX FIFO empty interrupt enable                                        */
      __IO uint32_t  RXNEIE     :  1;               /*!< RX FIFO empty interrupt enable                                        */
      __IO uint32_t  TXFIE      :  1;               /*!< TX FIFO full interrupt enable                                         */
      __IO uint32_t  RXFIE      :  1;               /*!< RX FIFO full interrupt enable                                         */
      __IO uint32_t  TXHLFIE    :  1;               /*!< TX FIFO half full interrupt enable                                    */
      __IO uint32_t  RXHLFIE    :  1;               /*!< RX FIFO half full interrupt enable                                    */
      __IO uint32_t  PARIERRIE  :  1;               /*!< Parity error interrupt enable                                         */
      __IO uint32_t  OVERRUNIE  :  1;               /*!< Overrun interrupt enable                                              */
      __IO uint32_t  PARISEL    :  1;               /*!< Parity selection                                                      */
      __IO uint32_t  PARIEN     :  1;               /*!< Enable parity                                                         */
      __IO uint32_t  IRDEN      :  1;               /*!< Enable IrDN                                                           */
           uint32_t             : 11;
      __IO uint32_t  RXEN       :  1;               /*!< Enable UART RX                                                        */
      __IO uint32_t  TXEN       :  1;               /*!< Enable UART TX                                                        */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  INTSTATUS;                       /*!< UART RX/TX interrupt status                                           */
    
    struct {
      __IO uint32_t  TXEINT     :  1;               /*!< The interrupt occurs when data transmit completed.                    */
      __IO uint32_t  RXNEINT    :  1;               /*!< The interrupt occurs when received data.                              */
      __IO uint32_t  TXFINT     :  1;               /*!< The interrupt occurs when TX FIFO is full.                            */
      __IO uint32_t  RXFINT     :  1;               /*!< The interrupt occurs when TX FIFO is full.                            */
      __IO uint32_t  TXHLFINT   :  1;               /*!< The interrupt occurs when TX FIFO is half full.                       */
      __IO uint32_t  RXHLFINT   :  1;               /*!< The interrupt occurs when RX FIFO is half full.                       */
      __IO uint32_t  PARIERRINT :  1;               /*!< The interrupt occurs when RX parity check error is detected           */
      __IO uint32_t  OVERRUNINT :  1;               /*!< The interrupt occurs when RX overrun error is detected                */
    } INTSTATUS_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BAUDDIV;                         /*!< UART Baud rate divider                                                */
    
    struct {
      __IO uint32_t  BAUDDIV    : 20;               /*!< Baud-rate generation pre-scalar divisor value                         */
    } BAUDDIV_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  FIFOCLR;                         /*!< Clear TX and RX FIFO                                                  */
    
    struct {
      __O  uint32_t  TXFIFOCLR  :  1;               /*!< Write 1 to clear TX FIFO                                              */
      __O  uint32_t  RXFIFOCLR  :  1;               /*!< Write 1 to clear RX FIFO                                              */
    } FIFOCLR_b;                                    /*!< BitSize                                                               */
  };
} UART0_Type;


/* ================================================================================ */
/* ================                      TIM0                      ================ */
/* ================================================================================ */


/**
  * @brief 16 bits timer (TIM0)
  */

typedef struct {                                    /*!< TIM0 Structure                                                        */
  
  union {
    __IO uint32_t  IR;                              /*!< Interrupt register                                                    */
    
    struct {
      __IO uint32_t  MR0INT     :  1;               /*!< interrupt flag for match channel 0                                    */
    } IR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TCR;                             /*!< Timer control register                                                */
    
    struct {
      __IO uint32_t  CEN        :  1;               /*!< Counter enable                                                        */
      __IO uint32_t  CRST       :  1;               /*!< Counter reset                                                         */
    } TCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TC;                              /*!< Timer counter register                                                */
    
    struct {
      __IO uint32_t  TC         : 16;               /*!< Timer counter value                                                   */
    } TC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PR;                              /*!< Prescale register                                                     */
    
    struct {
      __IO uint32_t  PRVAL      : 16;               /*!< Prescale value                                                        */
    } PR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC;                              /*!< Prescale Counter register                                             */
    
    struct {
      __IO uint32_t  PCVAL      : 16;               /*!< Prescale counter value                                                */
    } PC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MCR;                             /*!< Match Control Register                                                */
    
    struct {
      __IO uint32_t  MR0I       :  1;               /*!< Interrupt on MR0                                                      */
      __IO uint32_t  MR0R       :  1;               /*!< Reset on MR0                                                          */
      __IO uint32_t  MR0S       :  1;               /*!< Stop on MR0                                                           */
    } MCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MR0;                             /*!< Match register0                                                       */
    
    struct {
      __IO uint32_t  MATCH      : 16;               /*!< Timer counter match value                                             */
    } MR0_b;                                        /*!< BitSize                                                               */
  };
} TIM0_Type;


/* ================================================================================ */
/* ================                      TIM6                      ================ */
/* ================================================================================ */


/**
  * @brief 16 bits timer (TIM6)
  */

typedef struct {                                    /*!< TIM6 Structure                                                        */
  
  union {
    __IO uint32_t  IR;                              /*!< Interrupt register                                                    */
    
    struct {
      __IO uint32_t  MR0INT     :  1;               /*!< Interrupt flag for match channel 0                                    */
      __IO uint32_t  MR1INT     :  1;               /*!< Interrupt flag for match channel 1                                    */
      __IO uint32_t  MR2INT     :  1;               /*!< Interrupt flag for match channel 2                                    */
      __IO uint32_t  MR3INT     :  1;               /*!< Interrupt flag for match channel 3                                    */
      __IO uint32_t  CR0INT     :  1;               /*!< Interrupt flag for capture channel 0 event                            */
      __IO uint32_t  CR1INT     :  1;               /*!< Interrupt flag for capture channel 1 event                            */
      __IO uint32_t  CR2INT     :  1;               /*!< Interrupt flag for capture channel 2 event                            */
      __IO uint32_t  CR3INT     :  1;               /*!< Interrupt flag for capture channel 3 event                            */
    } IR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TCR;                             /*!< Timer control register                                                */
    
    struct {
      __IO uint32_t  CEN        :  1;               /*!< Counter enable                                                        */
      __IO uint32_t  CRST       :  1;               /*!< Counter reset                                                         */
    } TCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TC;                              /*!< Timer counter register                                                */
    
    struct {
      __IO uint32_t  TC         : 16;               /*!< Timer counter value                                                   */
    } TC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PR;                              /*!< Prescale register                                                     */
    
    struct {
      __IO uint32_t  PCVAL      : 16;               /*!< Prescale value                                                        */
    } PR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC;                              /*!< Prescale Counter register                                             */
    
    struct {
      __IO uint32_t  PC         : 16;               /*!< Prescale counter value                                                */
    } PC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MCR;                             /*!< Match Control Register                                                */
    
    struct {
      __IO uint32_t  MR0I       :  1;               /*!< Interrupt on MR0                                                      */
      __IO uint32_t  MR0R       :  1;               /*!< Reset on MR0                                                          */
      __IO uint32_t  MR0S       :  1;               /*!< Stop on MR0                                                           */
      __IO uint32_t  MR1I       :  1;               /*!< Interrupt on MR1                                                      */
      __IO uint32_t  MR1R       :  1;               /*!< Reset on MR1                                                          */
      __IO uint32_t  MR1S       :  1;               /*!< Stop on MR1                                                           */
      __IO uint32_t  MR2I       :  1;               /*!< Interrupt on MR2                                                      */
      __IO uint32_t  MR2R       :  1;               /*!< Reset on MR2                                                          */
      __IO uint32_t  MR2S       :  1;               /*!< Stop on MR2                                                           */
      __IO uint32_t  MR3I       :  1;               /*!< Interrupt on MR3                                                      */
      __IO uint32_t  MR3R       :  1;               /*!< Reset on MR3                                                          */
      __IO uint32_t  MR3S       :  1;               /*!< Stop on MR3                                                           */
    } MCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MR0;                             /*!< Match register0                                                       */
    
    struct {
      __IO uint32_t  MATCH      : 16;               /*!< Timer counter match value                                             */
    } MR0_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MR1;                             /*!< Match register1                                                       */
    
    struct {
      __IO uint32_t  MATCH      : 16;               /*!< Timer counter match value                                             */
    } MR1_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MR2;                             /*!< Match register2                                                       */
    
    struct {
      __IO uint32_t  MATCH      : 16;               /*!< Timer counter match value                                             */
    } MR2_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MR3;                             /*!< Match register3                                                       */
    
    struct {
      __IO uint32_t  MATCH      : 16;               /*!< Timer counter match value                                             */
    } MR3_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CCR;                             /*!< Capture Control Register                                              */
    
    struct {
      __IO uint32_t  CAP0RE     :  1;               /*!< Capture on CT16Bn_CAP0 rising edge                                    */
      __IO uint32_t  CAP0FE     :  1;               /*!< Capture on CT16Bn_CAP0 falling edge                                   */
      __IO uint32_t  CAP0I      :  1;               /*!< Interrupt on CT16Bn_CAP0 event                                        */
      __IO uint32_t  CAP1RE     :  1;               /*!< Capture on CT16Bn_CAP1 rising edge                                    */
      __IO uint32_t  CAP1FE     :  1;               /*!< Capture on CT16Bn_CAP1 falling edge                                   */
      __IO uint32_t  CAP1I      :  1;               /*!< Interrupt on CT16Bn_CAP1 event                                        */
      __IO uint32_t  CAP2RE     :  1;               /*!< Capture on comparator n level output_rising edge                      */
      __IO uint32_t  CAP2FE     :  1;               /*!< Capture on comparator n level output_falling edge                     */
      __IO uint32_t  CAP2I      :  1;               /*!< Interrupt on comparator n level output event                          */
      __IO uint32_t  CAP3RE     :  1;               /*!< Capture on comparator n edge output_rising edge                       */
      __IO uint32_t  CAP3FE     :  1;               /*!< Capture on comparator n edge output_falling edge                      */
      __IO uint32_t  CAP3I      :  1;               /*!< Interrupt on comparator n edge output event                           */
    } CCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CR0;                             /*!< Capture register0                                                     */
    
    struct {
      __I  uint32_t  CAP        : 16;               /*!< Timer counter capture value                                           */
    } CR0_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CR1;                             /*!< Capture register1                                                     */
    
    struct {
      __I  uint32_t  CAP        : 16;               /*!< Timer counter capture value                                           */
    } CR1_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CR2;                             /*!< Capture register2                                                     */
    
    struct {
      __I  uint32_t  CAP        : 16;               /*!< Timer counter capture value                                           */
    } CR2_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CR3;                             /*!< Capture register3                                                     */
    
    struct {
      __I  uint32_t  CAP        : 16;               /*!< Timer counter capture value                                           */
    } CR3_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EMR;                             /*!< External match register                                               */
    
    struct {
      __IO uint32_t  EM0        :  1;               /*!< External match 0                                                      */
      __IO uint32_t  EM1        :  1;               /*!< External match 1                                                      */
      __IO uint32_t  EM2        :  1;               /*!< External match 2                                                      */
      __IO uint32_t  EM3        :  1;               /*!< External match 3                                                      */
      __IO uint32_t  EMC0       :  2;               /*!< External match Control 0                                              */
      __IO uint32_t  EMC1       :  2;               /*!< External match Control 1                                              */
      __IO uint32_t  EMC2       :  2;               /*!< External match Control 2                                              */
      __IO uint32_t  EMC3       :  2;               /*!< External match Control 3                                              */
    } EMR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[12];
  
  union {
    __IO uint32_t  CTCR;                            /*!< Counter control register                                              */
    
    struct {
      __IO uint32_t  CTM        :  3;               /*!< Counter/Timer Mode                                                    */
      __IO uint32_t  ENCC       :  1;               /*!< Enable SELCC slection to clear timer and prescaler                    */
      __IO uint32_t  SELCC      :  4;               /*!< Selection to clear timer and prescaler                                */
      __IO uint32_t  PRISEL     :  4;               /*!< Primary clock source select                                           */
      __IO uint32_t  SECSEL     :  4;               /*!< Secondary clock source select                                         */
      __IO uint32_t  IPS        :  1;               /*!< Secondary source input polarity select                                */
    } CTCR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PWMC;                            /*!< PWM Control Register                                                  */
    
    struct {
      __IO uint32_t  PWMEN0     :  1;               /*!< PWM mode enable for channel0                                          */
      __IO uint32_t  PWMEN1     :  1;               /*!< PWM mode enable for channel1                                          */
      __IO uint32_t  PWMEN2     :  1;               /*!< PWM mode enable for channel2                                          */
    } PWMC_b;                                       /*!< BitSize                                                               */
  };
} TIM6_Type;


/* ================================================================================ */
/* ================                       ADC                      ================ */
/* ================================================================================ */


/**
  * @brief Analog-to-Digital Converter (ADC)
  */

typedef struct {                                    /*!< ADC Structure                                                         */
  
  union {
    __IO uint32_t  CR;                              /*!< ADC control register                                                  */
    
    struct {
      __IO uint32_t  CNVEN      :  8;               /*!< Enable ADC conversion value to DR0~DR7                                */
      __IO uint32_t  CLKDIV     :  8;               /*!< APB clock (PCLK) divider                                              */
      __IO uint32_t  BURST      :  1;               /*!< Burst mode control                                                    */
           uint32_t             :  7;
      __IO uint32_t  START      :  4;               /*!< Conversion starts control                                             */
      __IO uint32_t  EDGE       :  1;               /*!< Start Edge control                                                    */
      __IO uint32_t  SCMODE     :  1;               /*!< ADC converter sample clock selection                                  */
    } CR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  GDR;                             /*!< ADC Global Data Register                                              */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Current ADC conversion results                                        */
      __IO uint32_t  CHN        :  3;               /*!< The ADC channel related to results                                    */
      __IO uint32_t  OVERRUN    :  1;               /*!< The conversion results has been overwritten                           */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } GDR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHSEL;                           /*!< Channel select control register                                       */
    
    struct {
      __IO uint32_t  DR0CHSEL   :  4;               /*!< The conversion result is saved in DR0 register                        */
      __IO uint32_t  DR1CHSEL   :  4;               /*!< The conversion result is saved in DR1 register                        */
      __IO uint32_t  DR2CHSEL   :  4;               /*!< The conversion result is saved in DR2 register                        */
      __IO uint32_t  DR3CHSEL   :  4;               /*!< The conversion result is saved in DR3 register                        */
      __IO uint32_t  DR4CHSEL   :  4;               /*!< The conversion result is saved in DR4 register                        */
      __IO uint32_t  DR5CHSEL   :  4;               /*!< The conversion result is saved in DR5 register                        */
      __IO uint32_t  DR6CHSEL   :  4;               /*!< The conversion result is saved in DR6 register                        */
      __IO uint32_t  DR7CHSEL   :  4;               /*!< The conversion result is saved in DR7 register                        */
    } CHSEL_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  INTEN;                           /*!< ADC Interrupt Enable Register                                         */
    
    struct {
      __IO uint32_t  INTEN      :  8;               /*!< These bits allow control over which A/D channels generate interrupts
                                                         for conversion completion.                                            */
      __IO uint32_t  GINTEN     :  1;               /*!< enables the global DONE flag in ADC DR to generate an interrupt.      */
    } INTEN_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR0;                             /*!< A/D Channel 0 Data Register                                           */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Conversion results                                                    */
           uint32_t             : 18;
      __IO uint32_t  OVERRUN    :  1;               /*!< Conversion results overwritten                                        */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } DR0_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR1;                             /*!< A/D Channel 1 Data Register                                           */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Conversion results                                                    */
           uint32_t             : 18;
      __IO uint32_t  OVERRUN    :  1;               /*!< Conversion results overwritten                                        */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } DR1_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR2;                             /*!< A/D Channel 2 Data Register                                           */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Conversion results                                                    */
           uint32_t             : 18;
      __IO uint32_t  OVERRUN    :  1;               /*!< Conversion results overwritten                                        */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } DR2_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR3;                             /*!< A/D Channel 3 Data Register                                           */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Conversion results                                                    */
           uint32_t             : 18;
      __IO uint32_t  OVERRUN    :  1;               /*!< Conversion results overwritten                                        */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } DR3_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR4;                             /*!< A/D Channel 4 Data Register                                           */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Conversion results                                                    */
           uint32_t             : 18;
      __IO uint32_t  OVERRUN    :  1;               /*!< Conversion results overwritten                                        */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } DR4_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR5;                             /*!< A/D Channel 5 Data Register                                           */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Conversion results                                                    */
           uint32_t             : 18;
      __IO uint32_t  OVERRUN    :  1;               /*!< Conversion results overwritten                                        */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } DR5_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR6;                             /*!< A/D Channel 6 Data Register                                           */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Conversion results                                                    */
           uint32_t             : 18;
      __IO uint32_t  OVERRUN    :  1;               /*!< Conversion results overwritten                                        */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } DR6_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR7;                             /*!< A/D Channel 7 Data Register                                           */
    
    struct {
      __IO uint32_t  RESULT     : 12;               /*!< Conversion results                                                    */
           uint32_t             : 18;
      __IO uint32_t  OVERRUN    :  1;               /*!< Conversion results overwritten                                        */
      __IO uint32_t  DONE       :  1;               /*!< This bit is set to 1 when an A/D conversion completes                 */
    } DR7_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  STAT;                            /*!< ADC Status Register                                                   */
    
    struct {
      __IO uint32_t  DONE       :  8;               /*!< These bits mirror the DONE status flags that appear in the result
                                                         register for each A/D channel.                                        */
      __IO uint32_t  OVERRUN    :  8;               /*!< These bits mirror the OVERRRUN status flags that appear in the
                                                         result register for each A/D channel.                                 */
      __IO uint32_t  ADINT      :  1;               /*!< A/D interrupt flag                                                    */
      __IO uint32_t  HILMTFLAG0 :  1;               /*!< Low limit 0 status                                                    */
      __IO uint32_t  HILMTFLAG1 :  1;               /*!< High limit 1 status                                                   */
      __IO uint32_t  LOLMTFLAG0 :  1;               /*!< Low limit 0 status                                                    */
      __IO uint32_t  LOLMTFLAG1 :  1;               /*!< Low limit 1 status                                                    */
      __IO uint32_t  ADCRDY     :  1;               /*!< ADC converter is ready to use                                         */
    } STAT_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HILMT;                           /*!< ADC High Limit Control Register                                       */
    
    struct {
      __IO uint32_t  HILMT0     : 12;               /*!< High Limit value 0                                                    */
      __IO uint32_t  CHNSEL0    :  3;               /*!< Select which channel to compare with the high limit value 0
                                                                                                                               */
      __IO uint32_t  INTEN0     :  1;               /*!< Enable interrupt for High Limit value 0                               */
      __IO uint32_t  HILMT1     : 12;               /*!< High Limit value 1                                                    */
      __IO uint32_t  CHNSEL1    :  3;               /*!< Select which channel to compare with the high limit value 1           */
      __IO uint32_t  INTEN1     :  1;               /*!< Enable interrupt for High Limit value 1                               */
    } HILMT_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  LOLMT;                           /*!< ADC Low Limit Control Register                                        */
    
    struct {
      __IO uint32_t  LOLMT0     : 12;               /*!< Low Limit value 0                                                     */
      __IO uint32_t  CHNSEL0    :  3;               /*!< Select which channel to compare with the low limit value 0            */
      __IO uint32_t  INTEN0     :  1;               /*!< Enable interrupt for Low Limit value 0                                */
      __IO uint32_t  LOLMT1     : 12;               /*!< Low Limit value 1                                                     */
      __IO uint32_t  CHNSEL1    :  3;               /*!< Select which channel to compare with the low limit value 1            */
      __IO uint32_t  INTEN1     :  1;               /*!< Enable interrupt for Low Limit value 1                                */
    } LOLMT_b;                                      /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  SSCR;                            /*!< ADC software trigger convert register                                 */
    
    struct {
      __IO uint32_t  ADCTRIG    :  1;               /*!< Trigger ADC to do one time conversion                                 */
    } SSCR_b;                                       /*!< BitSize                                                               */
  };
} ADC_Type;


/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */


/**
  * @brief Power management unit (PMU)
  */

typedef struct {                                    /*!< PMU Structure                                                         */
  
  union {
    __IO uint32_t  PCON;                            /*!< Power control register                                                */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  DPDEN      :  1;               /*!< Power-down mode enable                                                */
           uint32_t             :  6;
      __IO uint32_t  SLEEPFLAG  :  1;               /*!< Sleep mode flag                                                       */
           uint32_t             :  2;
      __IO uint32_t  DPDFLAG    :  1;               /*!< Power-down flag                                                       */
    } PCON_b;                                       /*!< BitSize                                                               */
  };
} PMU_Type;


/* ================================================================================ */
/* ================                       SPI                      ================ */
/* ================================================================================ */


/**
  * @brief Serial peripheral interface (SPI)
  */

typedef struct {                                    /*!< SPI Structure                                                         */
  
  union {
    __IO uint32_t  CR0;                             /*!< SPI control register0                                                 */
    
    struct {
      __IO uint32_t  DSS        :  4;               /*!< Data Size Select                                                      */
      __IO uint32_t  FRF        :  2;               /*!< Frame Format                                                          */
      __IO uint32_t  CPOL       :  1;               /*!< Clock Out Polarity                                                    */
      __IO uint32_t  CPHA       :  1;               /*!< Clock Out Phase                                                       */
    } CR0_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CR1;                             /*!< SPI control register1                                                 */
    
    struct {
      __IO uint32_t  LBM        :  1;               /*!< Loop Back Mode                                                        */
      __IO uint32_t  SSE        :  1;               /*!< SPI Enable                                                            */
      __IO uint32_t  MS         :  1;               /*!< Master/Slave Mode                                                     */
      __IO uint32_t  SOD        :  1;               /*!< Slave Output Disable                                                  */
      __IO uint32_t  CSFL       :  1;               /*!< SSEL control                                                          */
      __IO uint32_t  RSFR       :  1;               /*!< Clear receive FIFO                                                    */
      __IO uint32_t  FILTEN     :  1;               /*!< Enable SPI data line filter                                           */
    } CR1_b;                                        /*!< BitSize                                                               */
  };
  __IO uint32_t  DR;                                /*!< SPI data register                                                     */
  
  union {
    __I  uint32_t  SR;                              /*!< SPI status register                                                   */
    
    struct {
      __I  uint32_t  TFE        :  1;               /*!< Transmit FIFO Empty                                                   */
      __I  uint32_t  TNF        :  1;               /*!< Transmit FIFO Not Full                                                */
      __I  uint32_t  RNE        :  1;               /*!< Receive FIFO Not Empty                                                */
      __I  uint32_t  RFF        :  1;               /*!< Receive FIFO Full                                                     */
      __I  uint32_t  BSY        :  1;               /*!< Busy                                                                  */
    } SR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CPSR;                            /*!< SPI Clock Prescale Register                                           */
    
    struct {
      __IO uint32_t  CPSDVSR    :  8;               /*!< SPI Clock Prescale Register                                           */
    } CPSR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IMSC;                            /*!< SPI Interrupt Mask Set and Clear Register                             */
    
    struct {
      __IO uint32_t  RORIM      :  1;               /*!< Software should set this bit to enable interrupt when a Receive
                                                         Overrun occurs                                                        */
      __IO uint32_t  RTIM       :  1;               /*!< Software should set this bit to enable interrupt when a Receive
                                                         Time-out condition occurs                                             */
      __IO uint32_t  RXIM       :  1;               /*!< Software should set this bit to enable interrupt when the Rx
                                                         FIFO is at least half full                                            */
      __IO uint32_t  TXIM       :  1;               /*!< Software should set this bit to enable interrupt when the Tx
                                                         FIFO is at least half empty.                                          */
    } IMSC_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Raw Interrupt Status Register                                         */
    
    struct {
      __I  uint32_t  RORRIS     :  1;               /*!< This bit is 1 if another frame was completely received while
                                                         the Rx FIFO was full                                                  */
      __I  uint32_t  RTRIS      :  1;               /*!< This bit is 1 if the Rx FIFO is not empty, and has not been
                                                         read for a time-out period                                            */
      __I  uint32_t  RXRIS      :  1;               /*!< This bit is 1 if the Rx FIFO is at least half full                    */
      __I  uint32_t  TXRIS      :  1;               /*!< This bit is 1 if the Tx FIFO is at least half empty.                  */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  MIS;                             /*!< Masked Interrupt Status Register                                      */
    
    struct {
      __I  uint32_t  RORMIS     :  1;               /*!< This bit is 1 if another frame was completely received while
                                                         the RxFIFO was full, and this interrupt is enabled                    */
      __I  uint32_t  RTMIS      :  1;               /*!< This bit is 1 if the Rx FIFO is not empty, has not been read
                                                         for a time-out period, and this interrupt is enabled.                 */
      __I  uint32_t  RXMIS      :  1;               /*!< This bit is 1 if the Rx FIFO is at least half full, and this
                                                         interrupt is enabled                                                  */
      __I  uint32_t  TXMIS      :  1;               /*!< This bit is 1 if the Tx FIFO is at least half empty, and this
                                                         interrupt is enabled                                                  */
    } MIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  ICR;                             /*!< SPI Interrupt Clear Register                                          */
    
    struct {
      __O  uint32_t  RORIC      :  1;               /*!< Writing a 1 to this bit clears the frame was received when Rx
                                                         FIFO was full interrupt                                               */
      __O  uint32_t  RTIC       :  1;               /*!< Writing a 1 to this bit clears the Rx FIFO was not empty and
                                                         has not been read for a time-out period interrupt                     */
    } ICR_b;                                        /*!< BitSize                                                               */
  };
} SPI_Type;


/* ================================================================================ */
/* ================                      IOCON                     ================ */
/* ================================================================================ */


/**
  * @brief I/O configuration block (IOCON)
  */

typedef struct {                                    /*!< IOCON Structure                                                       */
  
  union {
    __IO uint32_t  PC_13;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_13_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_14;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_14_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_15;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_15_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_7;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_7_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_8;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_8_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_9;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_9_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_0;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_1;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_2;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_3;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_3_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_4;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_4_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_5;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_5_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_6;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_6_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_7;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_7_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_0;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_1;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_2;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_3;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_3_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[4];
  
  union {
    __IO uint32_t  PB_0;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_1;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_2;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_10;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_10_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_11;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_11_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_12;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_12_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_13;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_13_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_14;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_14_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_15;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_15_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_4;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_4_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_5;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_5_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_4;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_4_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_5;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_5_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_8;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_8_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_9;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_9_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_10;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_10_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_11;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_11_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_12;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_12_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_13;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_13_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_10;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_10_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_11;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_11_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_14;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_14_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PA_15;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PA_15_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_6;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_6_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_8;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_8_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_0;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_1;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_3;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_3_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_4;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_4_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_5;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_5_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_6;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_6_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_7;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_7_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC_12;                           /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PC_12_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_8;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_8_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PB_9;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PB_9_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_6;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_6_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_7;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_7_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_2;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PD_3;                            /*!< Pin config register                                                   */
    
    struct {
      __IO uint32_t  FUNC       :  3;               /*!< Selects pin function                                                  */
      __IO uint32_t  PDE        :  1;               /*!< Pull-down mode                                                        */
      __IO uint32_t  PUE        :  1;               /*!< Pull-up mode                                                          */
      __IO uint32_t  CSE        :  1;               /*!< Schmitt trigger enable                                                */
      __IO uint32_t  INV        :  1;               /*!< Invert input                                                          */
      __IO uint32_t  SRM        :  1;               /*!< Slew rate mode                                                        */
      __IO uint32_t  ADM        :  1;               /*!< Analog mode                                                           */
      __IO uint32_t  DRV        :  1;               /*!< Drive current mode (Normal-drive pin)                                 */
      __IO uint32_t  OD         :  1;               /*!< Open-drain mode                                                       */
      __IO uint32_t  S_MODE     :  1;               /*!< Sample mode                                                           */
      __IO uint32_t  INE        :  1;               /*!< Input Enable                                                          */
    } PD_3_b;                                       /*!< BitSize                                                               */
  };
} IOCON_Type;


/* ================================================================================ */
/* ================                     SYSCON                     ================ */
/* ================================================================================ */


/**
  * @brief System control register (SYSCON)
  */

typedef struct {                                    /*!< SYSCON Structure                                                      */
  
  union {
    __IO uint32_t  SYSMEMREMAP;                     /*!< System memory remap register                                          */
    
    struct {
      __IO uint32_t  MAP        :  2;               /*!< System memory remap                                                   */
    } SYSMEMREMAP_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PRESETCTRL;                      /*!< Peripheral reset control register                                     */
    
    struct {
      __IO uint32_t  SPI_RST_N  :  1;               /*!< SPI reset control                                                     */
      __IO uint32_t  I2C_RST_N  :  1;               /*!< I2C reset control                                                     */
      __IO uint32_t  UART0_RST_N:  1;               /*!< UART0 reset control                                                   */
      __IO uint32_t  UART1_RST_N:  1;               /*!< UART1 reset control                                                   */
           uint32_t             :  1;
      __IO uint32_t  TIM0_RST_N :  1;               /*!< 16 bits basic counter/timer 0 (TIM0) reset control                    */
      __IO uint32_t  TIM1_RST_N :  1;               /*!< 16-bit basic counter/timer 1 (TIM1) reset control                     */
      __IO uint32_t  TIM6_RST_N :  1;               /*!< 16-bit basic counter/timer 2 (TIM6) reset control                     */
      __IO uint32_t  TIM7_RST_N :  1;               /*!< 16-bit basic counter/timer 3 (TIM7) reset control                     */
      __IO uint32_t  PWM_RST_N  :  1;               /*!< 16-bit PWM counter/timer 1 (PWMCT) reset control                      */
      __IO uint32_t  CRC_RST_N  :  1;               /*!< CRC reset control                                                     */
      __IO uint32_t  TOUCH_RST_N:  1;               /*!< 24-bit Cap-sense timer 1 reset control                                */
      __IO uint32_t  ADC_RST_N  :  1;               /*!< ADC reset control                                                     */
      __IO uint32_t  LCD_RST_N  :  1;               /*!< LCD control                                                           */
           uint32_t             :  2;
      __IO uint32_t  TIM2_RST_N :  1;               /*!< 16-bit basic counter/timer 4 (TIM2) reset control                     */
      __IO uint32_t  TIM3_RST_N :  1;               /*!< 16-bit basic counter/timer 5 (TIM3) reset control                     */
    } PRESETCTRL_b;                                 /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[7];
  
  union {
    __IO uint32_t  WDTOSCCTRL;                      /*!< WDT oscillator control register                                       */
    
    struct {
      __IO uint32_t  DIVSEL     :  5;               /*!< Select divider for Fclkana                                            */
      __IO uint32_t  CTRIM      :  3;               /*!< Trim watchdog oscillator capacitor                                    */
      __IO uint32_t  RTRIM      :  4;               /*!< Trim watchdog oscillator resistor                                     */
      __IO uint32_t  WDTCLKSRC  :  1;               /*!< Watch dog timer clock source                                          */
    } WDTOSCCTRL_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IRCCTRL;                         /*!< Internal RC oscillator control register                               */
    
    struct {
      __IO uint32_t  TRIM       :  9;               /*!< Trim value                                                            */
    } IRCCTRL_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[17];
  
  union {
    __IO uint32_t  MAINCLKSEL;                      /*!< Main clock source select register                                     */
    
    struct {
      __IO uint32_t  SEL        :  2;               /*!< Clock source for main clock                                           */
    } MAINCLKSEL_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MAINCLKUEN;                      /*!< Main clock source update enable register                              */
    
    struct {
      __IO uint32_t  ENA        :  1;               /*!< Enable main clock source update                                       */
    } MAINCLKUEN_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SYSAHBCLKDIV;                    /*!< System AHB clock divider register                                     */
    
    struct {
      __IO uint32_t  DIV        :  8;               /*!< System AHB clock divider value                                        */
    } SYSAHBCLKDIV_b;                               /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  SYSAHBCLKCTRL;                   /*!< AHB clock control register                                            */
    
    struct {
      __IO uint32_t  SYS        :  1;               /*!< Enables clock for AHB to APB bridge                                   */
           uint32_t             :  1;
      __IO uint32_t  RAM        :  1;               /*!< Enables clock for RAM                                                 */
           uint32_t             :  2;
      __IO uint32_t  I2C_CLK    :  1;               /*!< Enables clock for I2C                                                 */
      __IO uint32_t  CRC_CLK    :  1;               /*!< Enables clock for CRC                                                 */
      __IO uint32_t  TIM0_CLK   :  1;               /*!< Enables clock for 16-bit basement counter/timer 0                     */
      __IO uint32_t  TIM1_CLK   :  1;               /*!< Enables clock for 16-bit basement counter/timer 1                     */
      __IO uint32_t  TIM6_CLK   :  1;               /*!< Enables clock for 16-bit basement counter/timer 6                     */
      __IO uint32_t  TIM7_CLK   :  1;               /*!< Enables clock for 16-bit basement counter/timer 7                     */
      __IO uint32_t  SPI_CLK    :  1;               /*!< Enables clock for SPI                                                 */
      __IO uint32_t  UART0_CLK  :  1;               /*!< Enables clock for UART0                                               */
      __IO uint32_t  UART1_CLK  :  1;               /*!< Enables clock for UART1                                               */
      __IO uint32_t  ADC_CLK    :  1;               /*!< Enables clock for ADC                                                 */
      __IO uint32_t  WDT_CLK    :  1;               /*!< Enables clock for WDT                                                 */
      __IO uint32_t  IOCON_CLK  :  1;               /*!< Enables clock for IO configuration block                              */
      __IO uint32_t  PWM_CLK    :  1;               /*!< Enables clock for 16-bit PWM timer                                    */
      __IO uint32_t  LCD_CLK    :  1;               /*!< Enables clock for LCD CTRL                                            */
           uint32_t             :  1;
      __IO uint32_t  TOUCH_CLK  :  1;               /*!< Enables clock for 24-bit Cap-sense timer                              */
           uint32_t             :  1;
      __IO uint32_t  TIM2_CLK   :  1;               /*!< Enables clock for 16-bit basement counter/timer 2                     */
      __IO uint32_t  TIM3_CLK   :  1;               /*!< Enables clock for 16-bit basement counter/timer 3                     */
           uint32_t             :  4;
      __IO uint32_t  PD_CLK     :  1;               /*!< Enables clock for GPIO port 0                                         */
      __IO uint32_t  PA_CLK     :  1;               /*!< Enables clock for GPIO port 0                                         */
      __IO uint32_t  PB_CLK     :  1;               /*!< Enables clock for GPIO port 1                                         */
      __IO uint32_t  PC_CLK     :  1;               /*!< Enables clock for GPIO port 2                                         */
    } SYSAHBCLKCTRL_b;                              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3[5];
  
  union {
    __IO uint32_t  UART0CLKDIV;                     /*!< UART0 clock divider register                                          */
    
    struct {
      __IO uint32_t  DIV        :  8;               /*!< Divider value                                                         */
    } UART0CLKDIV_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  UART1CLKDIV;                     /*!< UARTn Clock Divider Register                                          */
    
    struct {
      __IO uint32_t  DIV        :  8;               /*!< Divider value                                                         */
    } UART1CLKDIV_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4[16];
  
  union {
    __IO uint32_t  CLKOUTCLKSEL;                    /*!< Clockout clock source select register                                 */
    
    struct {
      __IO uint32_t  SEL        :  3;               /*!< CLKOUT clock source                                                   */
    } CLKOUTCLKSEL_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLKOUTUEN;                       /*!< Clockout clock source update enable register                          */
    
    struct {
      __IO uint32_t  ENA        :  3;               /*!< Enable CLKOUT clock source update                                     */
    } CLKOUTUEN_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLKOUTDIV;                       /*!< Clockout clock divider register                                       */
    
    struct {
      __IO uint32_t  DIV        :  8;               /*!< Divider value                                                         */
    } CLKOUTDIV_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED5[24];
  
  union {
    __IO uint32_t  IOCONFIGCLKDIV;                  /*!< IO input filter register                                              */
    
    struct {
      __IO uint32_t  DIV        :  8;               /*!< Divider value                                                         */
    } IOCONFIGCLKDIV_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BODCTRL;                         /*!< BOD power down control register                                       */
    
    struct {
           uint32_t             :  4;
      __IO uint32_t  BODRSTEN   :  1;               /*!< BOD reset enable                                                      */
           uint32_t             :  1;
      __IO uint32_t  BODINTCLR  :  1;               /*!< Clear interrupt signal                                                */
    } BODCTRL_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED6[8];
  
  union {
    __IO uint32_t  INTNMI;                          /*!< NMI interrupt source configuration control                            */
    
    struct {
      __IO uint32_t  NMISRC     :  6;               /*!< NMI interrupts source select                                          */
    } INTNMI_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED7[48];
  
  union {
    __IO uint32_t  PDRUNCFG;                        /*!< Power-down configuration register                                     */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  IRC_PD     :  1;               /*!< IRC oscillator power-down                                             */
           uint32_t             :  1;
      __IO uint32_t  BOD_PD     :  1;               /*!< BOD detector power-down                                               */
      __IO uint32_t  ADC_PD     :  1;               /*!< ADC power-down                                                        */
      __IO uint32_t  EXTOSC_PD  :  1;               /*!< External OSC power-down                                               */
      __IO uint32_t  WDTOSC_PD  :  1;               /*!< Watchdog oscillator power-down                                        */
      __IO uint32_t  LCD_PD     :  1;               /*!< RTC oscillator power-down                                             */
      __IO uint32_t  TOUCH_PD   :  1;               /*!< LCD Voltage generator power-down                                      */
    } PDRUNCFG_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED8[7];
  
  union {
    __IO uint32_t  PLLCFG;                          /*!< PLL Config configuration register                                     */
    
    struct {
      __IO uint32_t  LKOPT      :  2;               /*!< PLL LocK                                                              */
      __IO uint32_t  BP         :  1;               /*!< PLL BP                                                                */
      __IO uint32_t  OEN        :  1;               /*!< PLL OEN                                                               */
      __IO uint32_t  OD         :  2;               /*!< PLL OD                                                                */
      __IO uint32_t  N          :  6;               /*!< PLL N                                                                 */
      __IO uint32_t  M          :  6;               /*!< PLL M                                                                 */
      __IO uint32_t  PLL_PD     :  1;               /*!< PLL power-down                                                        */
    } PLLCFG_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  PLLLK;                           /*!< PLL Lock status register                                              */
    
    struct {
      __I  uint32_t  LK         :  1;               /*!< PLL LocK status                                                       */
    } PLLLK_b;                                      /*!< BitSize                                                               */
  };
} SYSCON_Type;


/* ================================================================================ */
/* ================                       PWM                      ================ */
/* ================================================================================ */


/**
  * @brief Pulse-Width Modulation (PWM)
  */

typedef struct {                                    /*!< PWM Structure                                                         */
  
  union {
    __IO uint32_t  CTRL;                            /*!< Control Register                                                      */
    
    struct {
      __IO uint32_t  PWMEN      :  1;               /*!< PWM enable                                                            */
      __IO uint32_t  LDOK       :  1;               /*!< Load vaule bit                                                        */
      __IO uint32_t  PWMF       :  1;               /*!< PWM reload flag bit                                                   */
      __IO uint32_t  PWMRIE     :  1;               /*!< PWMF interrupt control bit                                            */
           uint32_t             :  1;
      __IO uint32_t  PRSC       :  2;               /*!< PWM clock Pre frequency set bit                                       */
      __IO uint32_t  IPOL0      :  1;               /*!< Select the PWM value register for the PWM_0 and PWM_1 pins pair
                                                         in complementary mode                                                 */
      __IO uint32_t  IPOL1      :  1;               /*!< Select the PWM value register for the PWM_2 and PWM_3 pins pair
                                                         in complementary mode.                                                */
      __IO uint32_t  IPOL2      :  1;               /*!< Select the PWM value register for the PWM_4 and PWM_5 pins pair
                                                         in complementary mode.                                                */
      __IO uint32_t  IPOL3      :  1;               /*!< Select the PWM value register for the PWM_6 and PWM_7 pins pair
                                                         in complementary mode.                                                */
      __IO uint32_t  HALF       :  1;               /*!< Enable half-cycle reloads in Center-Aligned PWM mode                  */
      __IO uint32_t  LDFQ       :  4;               /*!< select the PWM load frequency                                         */
      __IO uint32_t  SOFTFAULT  :  1;               /*!< trigger a software fault to the PWM Fault protect mode                */
      __IO uint32_t  INIDIR     :  1;               /*!< Select initial count direction in center align mode                   */
           uint32_t             :  2;
      __IO uint32_t  TSCNT      :  2;               /*!< Trig signal output count register                                     */
      __IO uint32_t  TSSEL      :  2;               /*!< Trig signal select register                                           */
      __IO uint32_t  CH0OUTEN   :  1;               /*!< Output a signal when counter register of channel 0 equals to
                                                         VAL0                                                                  */
      __IO uint32_t  CH1OUTEN   :  1;               /*!< Output a signal when counter register of channel 1 equals to
                                                         VAL1                                                                  */
      __IO uint32_t  CH2OUTEN   :  1;               /*!< Output a signal when counter register of channel 2 equals to
                                                         VAL2                                                                  */
      __IO uint32_t  CH3OUTEN   :  1;               /*!< Output a signal when counter register of channel 3 equals to
                                                         VAL3                                                                  */
      __IO uint32_t  CH4OUTEN   :  1;               /*!< Output a signal when counter register of channel 4 equals to
                                                         VAL4                                                                  */
      __IO uint32_t  CH5OUTEN   :  1;               /*!< Output a signal when counter register of channel 5 equals to
                                                         VAL5                                                                  */
      __IO uint32_t  CH6OUTEN   :  1;               /*!< Output a signal when counter register of channel 6 equals to
                                                         VAL5                                                                  */
      __IO uint32_t  CH7OUTEN   :  1;               /*!< Output a signal when counter register of channel 5 equals to
                                                         VAL5                                                                  */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  FCTRL;                           /*!< Fault Control Register                                                */
    
    struct {
      __IO uint32_t  FMODE0     :  1;               /*!< Select automatic or manual clearing of FAULT0 pin faults              */
      __IO uint32_t  FIE0       :  1;               /*!< Enable the interrupt request generated by the PWM_FAULT0 pin          */
      __IO uint32_t  FMODE1     :  1;               /*!< Select automatic or manual clearing of Software faults                */
      __IO uint32_t  FIE1       :  1;               /*!< Enable the interrupt request generated by the Software fault          */
      __IO uint32_t  FMODE2     :  1;               /*!< Select automatic or manual clearing of ADC limit faults               */
      __IO uint32_t  FIE2       :  1;               /*!< Enable the interrupt request generated by the ADC limit fault         */
    } FCTRL_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  FLTACK;                          /*!< Fault Status/Acknowledge Register                                     */
    
    struct {
      __IO uint32_t  FTACK0     :  1;               /*!< PWM_FAULT pin error Acknowledge,Writing a Logic 1 to FTACK0
                                                         clears FFLAG0.                                                        */
      __IO uint32_t  FTACK1     :  1;               /*!< ADC limit error Acknowledge,Writing a Logic 1 to FTACK1 clears
                                                         FFLAG1.                                                               */
      __IO uint32_t  FTACK2     :  1;               /*!< Software error Acknowledge,Writing a Logic 1 to FTACK2 clears
                                                         FFLAG2                                                                */
           uint32_t             : 13;
      __IO uint32_t  FFLAG0     :  1;               /*!< PWM_FAULT pin fault flag                                              */
      __IO uint32_t  FPIN0      :  1;               /*!< PWM_FAULT pin state                                                   */
      __IO uint32_t  FLAG1      :  1;               /*!< ADC limit fault flag                                                  */
      __IO uint32_t  FPIN1      :  1;               /*!< ADC limit fault state                                                 */
      __IO uint32_t  FFLAG2     :  1;               /*!< SOFTFAULT flag                                                        */
    } FLTACK_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  OUTCTRL;                         /*!< Output Control Register                                               */
    
    struct {
      __IO uint32_t  OUT0       :  1;               /*!< PWM_0 control                                                         */
      __IO uint32_t  OUT1       :  1;               /*!< PWM_1 control                                                         */
      __IO uint32_t  OUT2       :  1;               /*!< PWM_2 control                                                         */
      __IO uint32_t  OUT3       :  1;               /*!< PWM_3 control                                                         */
      __IO uint32_t  OUT4       :  1;               /*!< PWM_4 control                                                         */
      __IO uint32_t  OUT5       :  1;               /*!< PWM_5 control                                                         */
      __IO uint32_t  OUT6       :  1;               /*!< PWM_6 control                                                         */
      __IO uint32_t  OUT7       :  1;               /*!< PWM_7 control                                                         */
      __IO uint32_t  OUTCTL0    :  1;               /*!< Software control enable to PWM_0                                      */
      __IO uint32_t  OUTCTL1    :  1;               /*!< Software control enable to PWM_1                                      */
      __IO uint32_t  OUTCTL2    :  1;               /*!< Software control enable to PWM_2                                      */
      __IO uint32_t  OUTCTL3    :  1;               /*!< Software control enable to PWM_3                                      */
      __IO uint32_t  OUTCTL4    :  1;               /*!< Software control enable to PWM_4                                      */
      __IO uint32_t  OUTCTL5    :  1;               /*!< Software control enable to PWM_5                                      */
      __IO uint32_t  OUTCTL6    :  1;               /*!< Software control enable to PWM_6                                      */
      __IO uint32_t  OUTCTL7    :  1;               /*!< Software control enable to PWM_7                                      */
    } OUTCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CNTR;                            /*!< Counter Register                                                      */
    
    struct {
      __I  uint32_t  CNT        : 16;               /*!< 16-bit PWM counter                                                    */
    } CNTR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CMOD;                            /*!< Counter Modulo Register                                               */
    
    struct {
      __IO uint32_t  CM         : 16;               /*!< PWM Counter Modulo value                                              */
    } CMOD_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  VAL0;                            /*!< Value Register 0                                                      */
    
    struct {
      __IO uint32_t  VAL        : 16;               /*!< PWM value                                                             */
    } VAL0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  VAL1;                            /*!< Value Register 1                                                      */
    
    struct {
      __IO uint32_t  VAL        : 16;               /*!< PWM value                                                             */
    } VAL1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  VAL2;                            /*!< Value Register 2                                                      */
    
    struct {
      __IO uint32_t  VAL        : 16;               /*!< PWM value                                                             */
    } VAL2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  VAL3;                            /*!< Value Register 3                                                      */
    
    struct {
      __IO uint32_t  VAL        : 16;               /*!< PWM value                                                             */
    } VAL3_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  VAL4;                            /*!< Value Register 4                                                      */
    
    struct {
      __IO uint32_t  VAL        : 16;               /*!< PWM value                                                             */
    } VAL4_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  VAL5;                            /*!< Value Register 5                                                      */
    
    struct {
      __IO uint32_t  VAL        : 16;               /*!< PWM value                                                             */
    } VAL5_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  VAL6;                            /*!< Value Register 6                                                      */
    
    struct {
      __IO uint32_t  VAL        : 16;               /*!< PWM value                                                             */
    } VAL6_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  VAL7;                            /*!< Value Register 7                                                      */
    
    struct {
      __IO uint32_t  VAL        : 16;               /*!< PWM value                                                             */
    } VAL7_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DTIM0;                           /*!< Deadtime Register 0                                                   */
    
    struct {
      __IO uint32_t  DTIM       : 16;               /*!< deadtime during 0 to 1 transitions                                    */
    } DTIM0_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DTIM1;                           /*!< Deadtime Register 1                                                   */
    
    struct {
      __IO uint32_t  DTIM       : 16;               /*!< deadtime during 1 to 0 transitions                                    */
    } DTIM1_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DMAP0;                           /*!< Disable Mapping Register0                                             */
    
    struct {
      __IO uint32_t  P0FLTMAP0  :  1;               /*!< Enables Fault pin 0 to protect PWM pin 0 output                       */
      __IO uint32_t  P0FLTMAP1  :  1;               /*!< Enables Software Fault to protect PWM pin 0 output                    */
      __IO uint32_t  P0FLTMAP2  :  1;               /*!< Enables ADC out of limit to protect PWM pin 0 output                  */
           uint32_t             :  5;
      __IO uint32_t  P1FLTMAP0  :  1;               /*!< Enables Fault pin 0 to protect PWM pin 1 output                       */
      __IO uint32_t  P1FLTMAP1  :  1;               /*!< Enables Software Fault to protect PWM pin 1 output                    */
      __IO uint32_t  P1FLTMAP2  :  1;               /*!< Enables ADC out of limit to protect PWM pin 1 output                  */
           uint32_t             :  5;
      __IO uint32_t  P2FLTMAP0  :  1;               /*!< Enables Fault pin 0 to protect PWM pin 2 output                       */
      __IO uint32_t  P2FLTMAP1  :  1;               /*!< Enables Software Fault to protect PWM pin 2 output                    */
      __IO uint32_t  P2FLTMAP2  :  1;               /*!< Enables ADC out of limit to protect PWM pin 2 output                  */
           uint32_t             :  5;
      __IO uint32_t  P3FLTMAP0  :  1;               /*!< Enables Fault pin 0 to protect PWM pin 3 output                       */
      __IO uint32_t  P3FLTMAP1  :  1;               /*!< Enables Software Fault to protect PWM pin 3 output                    */
      __IO uint32_t  P3FLTMAP2  :  1;               /*!< Enables ADC out of limit to protect PWM pin 3 output                  */
    } DMAP0_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DMAP1;                           /*!< Disable Mapping Register1                                             */
    
    struct {
      __IO uint32_t  P4FLTMAP0  :  1;               /*!< Enables Fault pin 0 to protect PWM pin 4 output                       */
      __IO uint32_t  P4FLTMAP1  :  1;               /*!< Enables Software Fault to protect PWM pin 4 output                    */
      __IO uint32_t  P4FLTMAP2  :  1;               /*!< Enables ADC out of limit to protect PWM pin 4 output                  */
           uint32_t             :  5;
      __IO uint32_t  P5FLTMAP0  :  1;               /*!< Enables Fault pin 0 to protect PWM pin 5 output                       */
      __IO uint32_t  P5FLTMAP1  :  1;               /*!< Enables Software Fault to protect PWM pin 5 output                    */
      __IO uint32_t  P5FLTMAP2  :  1;               /*!< Enables ADC out of limit to protect PWM pin 5 output                  */
           uint32_t             :  5;
      __IO uint32_t  P6FLTMAP0  :  1;               /*!< Enables Fault pin 0 to protect PWM pin 6 output                       */
      __IO uint32_t  P6FLTMAP1  :  1;               /*!< Enables Software Fault to protect PWM pin 6 output                    */
      __IO uint32_t  P6FLTMAP2  :  1;               /*!< Enables ADC out of limit to protect PWM pin 6 output                  */
           uint32_t             :  5;
      __IO uint32_t  P7FLTMAP0  :  1;               /*!< Enables Fault pin 0 to protect PWM pin 7 output                       */
      __IO uint32_t  P7FLTMAP1  :  1;               /*!< Enables Software Fault to protect PWM pin 7 output                    */
      __IO uint32_t  P7FLTMAP2  :  1;               /*!< Enables ADC out of limit to protect PWM pin 7 output                  */
    } DMAP1_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CNFG;                            /*!< Configure Register                                                    */
    
    struct {
      __IO uint32_t  WP         :  1;               /*!< Enables write-protection for all write-protectable registers          */
      __IO uint32_t  NDEP01     :  1;               /*!< independent PWMs or complementary PWM pairs selection                 */
      __IO uint32_t  NDEP23     :  1;               /*!< independent PWMs or complementary PWM pairs selection                 */
      __IO uint32_t  NDEP45     :  1;               /*!< independent PWMs or complementary PWM pairs selection                 */
      __IO uint32_t  NDEP67     :  1;               /*!< independent PWMs or complementary PWM pairs selection                 */
      __IO uint32_t  BOTNEG01   :  1;               /*!< polarity for the bottom-side PWMs selection                           */
      __IO uint32_t  BOTNEG23   :  1;               /*!< polarity for the bottom-side PWMs selection                           */
      __IO uint32_t  BOTNEG45   :  1;               /*!< polarity for the bottom-side PWMs selection                           */
      __IO uint32_t  BOTNEG67   :  1;               /*!< polarity for the bottom-side PWMs selection                           */
      __IO uint32_t  TOPNEG01   :  1;               /*!< polarity for the top-side PWMs selection                              */
      __IO uint32_t  TOPNEG23   :  1;               /*!< polarity for the top-side PWMs selection                              */
      __IO uint32_t  TOPNEG45   :  1;               /*!< polarity for the top-side PWMs selection                              */
      __IO uint32_t  TOPNEG67   :  1;               /*!< polarity for the top-side PWMs selection                              */
      __IO uint32_t  EDG        :  1;               /*!< Edge-Aligned or Center-Aligned wave forms selection                   */
    } CNFG_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CCTRL;                           /*!< Channel Control Register                                              */
    
    struct {
      __IO uint32_t  SWP01      :  1;               /*!< This bit is write-protected when ENHA is zero                         */
      __IO uint32_t  SWP23      :  1;               /*!< This bit is write-protected when ENHA is zero                         */
      __IO uint32_t  SWP45      :  1;               /*!< This bit is write-protected when ENHA is zero                         */
      __IO uint32_t  SWP67      :  1;               /*!< This bit is write-protected when ENHA is zero                         */
      __IO uint32_t  VLMODE     :  2;               /*!< To be filled                                                          */
      __IO uint32_t  MSK0       :  1;               /*!< The mask of the PWM logical channel 0                                 */
      __IO uint32_t  MSK1       :  1;               /*!< The mask of the PWM logical channel 1                                 */
      __IO uint32_t  MSK2       :  1;               /*!< The mask of the PWM logical channel 2                                 */
      __IO uint32_t  MSK3       :  1;               /*!< The mask of the PWM logical channel 3                                 */
      __IO uint32_t  MSK4       :  1;               /*!< The mask of the PWM logical channel 4                                 */
      __IO uint32_t  MSK5       :  1;               /*!< The mask of the PWM logical channel 5                                 */
      __IO uint32_t  MSK6       :  1;               /*!< The mask of the PWM logical channel 6                                 */
      __IO uint32_t  MSK7       :  1;               /*!< The mask of the PWM logical channel 7                                 */
           uint32_t             :  1;
      __IO uint32_t  ENHA       :  1;               /*!< Enable Hardware Acceleration                                          */
    } CCTRL_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PORT;                            /*!< Port Register                                                         */
    
    struct {
      __IO uint32_t  FAULTPORT  :  1;               /*!< PWM fault input value                                                 */
           uint32_t             :  7;
      __IO uint32_t  FAULTVAL0  :  1;               /*!< PWM0 output value when fault happen                                   */
      __IO uint32_t  FAULTVAL1  :  1;               /*!< PWM1 output value when fault happen                                   */
      __IO uint32_t  FAULTVAL2  :  1;               /*!< PWM2 output value when fault happen                                   */
      __IO uint32_t  FAULTVAL3  :  1;               /*!< PWM3 output value when fault happen                                   */
      __IO uint32_t  FAULTVAL4  :  1;               /*!< PWM4 output value when fault happen                                   */
      __IO uint32_t  FAULTVAL5  :  1;               /*!< PWM5 output value when fault happen                                   */
      __IO uint32_t  FAULTVAL6  :  1;               /*!< PWM6 output value when fault happen                                   */
      __IO uint32_t  FAULTVAL7  :  1;               /*!< PWM7 output value when fault happen                                   */
      __IO uint32_t  FPSEL0     :  1;               /*!< Enable PWM0 fault output FAULTVAL0                                    */
      __IO uint32_t  FPSEL1     :  1;               /*!< Enable PWM1 fault output FAULTVAL1                                    */
      __IO uint32_t  FPSEL2     :  1;               /*!< Enable PWM2 fault output FAULTVAL2                                    */
      __IO uint32_t  FPSEL3     :  1;               /*!< Enable PWM3 fault output FAULTVAL3                                    */
      __IO uint32_t  FPSEL4     :  1;               /*!< Enable PWM4 fault output FAULTVAL4                                    */
      __IO uint32_t  FPSEL5     :  1;               /*!< Enable PWM5 fault output FAULTVAL5                                    */
      __IO uint32_t  FPSEL6     :  1;               /*!< Enable PWM5 fault output FAULTVAL6                                    */
      __IO uint32_t  FPSEL7     :  1;               /*!< Enable PWM5 fault output FAULTVAL7                                    */
    } PORT_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ICCTRL;                          /*!< Internal Correction Control Register                                  */
    
    struct {
      __IO uint32_t  ICC0       :  1;               /*!< Select VAL0 or VAL1 to controls PWM0/PWM1 pair.                       */
      __IO uint32_t  ICC1       :  1;               /*!< Select VAL2 or VAL3 to controls PWM2/PWM3 pair.                       */
      __IO uint32_t  ICC2       :  1;               /*!< Select VAL4 or VAL5 to controls PWM4/PWM5 pair.                       */
      __IO uint32_t  ICC3       :  1;               /*!< Select VAL6 or VAL7 to controls PWM6/PWM7 pair.                       */
      __IO uint32_t  PAD_EN     :  1;               /*!< PWM pad output enable                                                 */
    } ICCTRL_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[2];
  
  union {
    __IO uint32_t  PSCR;                            /*!< Polarity Invert control Register                                      */
    
    struct {
      __IO uint32_t  CINV0      :  1;               /*!< This bit controls the polarity of PWM compare output 0                */
      __IO uint32_t  CINV1      :  1;               /*!< This bit controls the polarity of PWM compare output 1                */
      __IO uint32_t  CINV2      :  1;               /*!< This bit controls the polarity of PWM compare output 2                */
      __IO uint32_t  CINV3      :  1;               /*!< This bit controls the polarity of PWM compare output 3                */
      __IO uint32_t  CINV4      :  1;               /*!< This bit controls the polarity of PWM compare output 4                */
      __IO uint32_t  CINV5      :  1;               /*!< This bit controls the polarity of PWM compare output 5                */
      __IO uint32_t  CINV6      :  1;               /*!< This bit controls the polarity of PWM compare output 6                */
      __IO uint32_t  CINV7      :  1;               /*!< This bit controls the polarity of PWM compare output 7                */
    } PSCR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  CNTRINI;                         /*!< Counter Init Register                                                 */
    
    struct {
      __O  uint32_t  INITVAL    : 16;               /*!< PWM counter start value                                               */
    } CNTRINI_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  PRESC;                           /*!< CLK Divider Register                                                  */
    
    struct {
      __IO uint32_t  DIVIDER    : 16;               /*!< Divider value                                                         */
    } PRESC_b;                                      /*!< BitSize                                                               */
  };
} PWM_Type;


/* ================================================================================ */
/* ================                       LCD                      ================ */
/* ================================================================================ */


/**
  * @brief LCD driver (LCD)
  */

typedef struct {                                    /*!< LCD Structure                                                         */
  
  union {
    __IO uint32_t  LCDCTRL0;                        /*!< LCD driver enable                                                     */
    
    struct {
      __IO uint32_t  LCDEN      :  1;               /*!< Enable LCD driver                                                     */
      __IO uint32_t  LEDEN      :  1;               /*!< Enable LED driver                                                     */
      __IO uint32_t  LEDINV     :  1;               /*!< LED com output positive/negative selection                            */
      __IO uint32_t  LEDPS      :  1;               /*!< LED com output polar enable                                           */
    } LCDCTRL0_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  LCDCTRL1;                        /*!< LCD driver control register                                           */
    
    struct {
      __IO uint32_t  DUTY       :  4;               /*!< Set LCD driver duty                                                   */
      __IO uint32_t  BIAS       :  1;               /*!< Bias voltage select                                                   */
      __IO uint32_t  TOP        :  3;               /*!< LCD output high voltage adjustment                                    */
      __IO uint32_t  FREQDIV    : 20;               /*!< COM scan frequency divider                                            */
    } LCDCTRL1_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MEMMAP0;                         /*!< LCD data memory map0                                                  */
    
    struct {
      __IO uint32_t  SEG0TOCOM  :  8;               /*!< Segment 0 cross to Com0~5                                             */
      __IO uint32_t  SEG1TOCOM  :  8;               /*!< Segment 1 cross to Com0~5                                             */
      __IO uint32_t  SEG2TOCOM  :  8;               /*!< Segment 2 cross to Com0~5                                             */
      __IO uint32_t  SEG3TOCOM  :  8;               /*!< Segment 3 cross to Com0~5                                             */
    } MEMMAP0_b;                                    /*!< BitSize                                                               */
  
    __IO uint32_t LEDMEM0;                      /*!< (@ 0x00000008) LED data memory map0                                       */
    
    struct {
      __IO uint32_t COM0TOSEG   : 8;            /*!< (@ 0x00000000) Com0 cross to Segment0~7                                   */
      __I  uint32_t             : 8;
      __IO uint32_t COM1TOSEG   : 8;            /*!< (@ 0x00000010) Com1 cross to Segment0~7                                   */
    } LEDMEM0_b;
	};
  
  union {
    __IO uint32_t  MEMMAP1;                         /*!< LCD driver data memory map1                                           */
    
    struct {
      __IO uint32_t  SEG4TOCOM  :  8;               /*!< Segment 4 cross to Com0~5                                             */
      __IO uint32_t  SEG5TOCOM  :  8;               /*!< Segment 5 cross to Com0~5                                             */
      __IO uint32_t  SEG6TOCOM  :  8;               /*!< Segment 6 cross to Com0~5                                             */
      __IO uint32_t  SEG7TOCOM  :  8;               /*!< Segment 7 cross to Com0~5                                             */
    } MEMMAP1_b;                                    /*!< BitSize                                                               */

    __IO uint32_t LEDMEM1;                      /*!< (@ 0x0000000C) LED data memory map1                                       */
    
    struct {
      __IO uint32_t COM2TOSEG   : 8;            /*!< (@ 0x00000000) Com2 cross to Segment0~7                                   */
      __I  uint32_t             : 8;
      __IO uint32_t COM3TOSEG   : 8;            /*!< (@ 0x00000010) Com3 cross to Segment0~7                                   */
    } LEDMEM1_b;
  };
  
  union {
    __IO uint32_t  MEMMAP2;                         /*!< LCD driver data memory map2                                           */
    
    struct {
      __IO uint32_t  SEG8TOCOM  :  8;               /*!< Segment 8 cross to Com0~5                                             */
      __IO uint32_t  SEG9TOCOM  :  8;               /*!< Segment 9 cross to Com0~5                                             */
      __IO uint32_t  SEG10TOCOM :  8;               /*!< Segment 10 cross to Com0~5                                            */
      __IO uint32_t  SEG11TOCOM :  8;               /*!< Segment 11 cross to Com0~5                                            */
    } MEMMAP2_b;                                    /*!< BitSize                                                               */

    __IO uint32_t LEDMEM2;                      /*!< (@ 0x00000010) LED data memory map2                                       */
    
    struct {
      __IO uint32_t COM4TOSEG   : 8;            /*!< (@ 0x00000000) Com4 cross to Segment0~7                                   */
      __I  uint32_t             : 8;
      __IO uint32_t COM5TOSEG   : 8;            /*!< (@ 0x00000010) Com5 cross to Segment0~7                                   */
    } LEDMEM2_b;
  };
  
  union {
    __IO uint32_t  MEMMAP3;                         /*!< LCD driver data memory map3                                           */
    
    struct {
      __IO uint32_t  SEG12TOCOM :  8;               /*!< Segment 12 cross to Com0~5                                            */
      __IO uint32_t  SEG13TOCOM :  8;               /*!< Segment 13 cross to Com0~5                                            */
      __IO uint32_t  SEG14TOCOM :  8;               /*!< Segment 14 cross to Com0~5                                            */
      __IO uint32_t  SEG15TOCOM :  8;               /*!< Segment 15 cross to Com0~5                                            */
    } MEMMAP3_b;                                    /*!< BitSize                                                               */
 
    __IO uint32_t LEDMEM3;                      /*!< (@ 0x00000014) LED data memory map3                                       */
    
    struct {
      __IO uint32_t COM6TOSEG   : 8;            /*!< (@ 0x00000000) Com6 cross to Segment0~7                                   */
      __I  uint32_t             : 8;
      __IO uint32_t COM7TOSEG   : 8;            /*!< (@ 0x00000010) Com7 cross to Segment0~7                                   */
    } LEDMEM3_b;
	};
  __I  uint32_t  RESERVED[6];
  
  union {
    __IO uint32_t  LCDOUTEN0;                       /*!< LCD output enable 0                                                   */
    
    struct {
      __IO uint32_t  LCDCOMEN   :  6;               /*!< Com0~5 output enable                                                  */
    } LCDOUTEN0_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  LCDOUTEN1;                       /*!< LCD output enable 1                                                   */
    
    struct {
      __IO uint32_t  LCDSEGEN   : 16;               /*!< Segment 0~16 output enable                                            */
    } LCDOUTEN1_b;                                  /*!< BitSize                                                               */
  };
} LCD_Type;


/* ================================================================================ */
/* ================                      TOUCH                     ================ */
/* ================================================================================ */


/**
  * @brief Capacitance Touch Sense  (TOUCH)
  */

typedef struct {                                    /*!< TOUCH Structure                                                       */
  
  union {
    __IO uint32_t  INTSTAT;                         /*!< Interrupt status register                                             */
    
    struct {
      __IO uint32_t  WATSTAT    :  1;               /*!< Interrupt state flag trigger by water mark                            */
      __IO uint32_t  SCANSTAT   :  1;               /*!< Scan interrupt state flag                                             */
    } INTSTAT_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTRL;                            /*!< Cap Sense enable ctrl register                                        */
    
    struct {
      __IO uint32_t  CAPTEN     :  1;               /*!< Touch pad enable                                                      */
      __IO uint32_t  INTEN      :  1;               /*!< Touch pad interrupt enable                                            */
      __IO uint32_t  INTERNALRSET:  2;              /*!< Internal resister(frequency) select                                   */
      __IO uint32_t  EXTRSEL    :  1;               /*!< Select internal resister or external resister                         */
      __IO uint32_t  OSCEN      :  1;               /*!< Enable oscillator                                                     */
      __IO uint32_t  SCANINTEN  :  1;               /*!< Enable interrupt at every time a pad scanned                          */
           uint32_t             :  1;
      __IO uint32_t  CHNEN      : 22;               /*!< Touch pad channel enable                                              */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  __IO uint32_t  SENSTM;                            /*!< Touchpad sense Time register                                          */
  
  union {
    __IO uint32_t  RAWSTAT;                         /*!< Interrupt status RAW register                                         */
    
    struct {
      __IO uint32_t  RAWWATSTAT :  1;               /*!< Interrupt raw state flag trigger by water mark                        */
      __IO uint32_t  RAWSCANSTAT:  1;               /*!< Scan interrupt raw state flag                                         */
    } RAWSTAT_b;                                    /*!< BitSize                                                               */
  };
  __IO uint32_t  WATMK;                             /*!< Interrupt watermark register                                          */
  __I  uint32_t  RESERVED;
  
  union {
    __I  uint32_t  TOUCHCHN;                        /*!< Touched pad channel register                                          */
    
    struct {
      __I  uint32_t  CHN        :  5;               /*!< Touched pad channel number                                            */
    } TOUCHCHN_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  TOUCHCNT;                          /*!< Touched pad count value register                                      */
  
  union {
    __I  uint32_t  SCANCHN;                         /*!< Scanned pad channel register                                          */
    
    struct {
      __I  uint32_t  CHN        :  5;               /*!< Last scanned pad channel number                                       */
    } SCANCHN_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  SCANCNT;                           /*!< Scanned pad counter value register                                    */
} TOUCH_Type;


/* ================================================================================ */
/* ================                       PA                       ================ */
/* ================================================================================ */


/**
  * @brief General-purpose I/Os (PA)
  */

typedef struct {                                    /*!< PA Structure                                                          */
  
  union {
    __IO uint32_t  MASK;                            /*!< Pin value mask register                                               */
    
    struct {
      __IO uint32_t  MASK0      :  1;               /*!< GPIO pin PIOn_0 access control bit                                    */
      __IO uint32_t  MASK1      :  1;               /*!< GPIO pin PIOn_1 access control bit                                    */
      __IO uint32_t  MASK2      :  1;               /*!< GPIO pin PIOn_2 access control bit                                    */
      __IO uint32_t  MASK3      :  1;               /*!< GPIO pin PIOn_3 access control bit                                    */
      __IO uint32_t  MASK4      :  1;               /*!< GPIO pin PIOn_4 access control bit                                    */
      __IO uint32_t  MASK5      :  1;               /*!< GPIO pin PIOn_5 access control bit                                    */
      __IO uint32_t  MASK6      :  1;               /*!< GPIO pin PIOn_6 access control bit                                    */
      __IO uint32_t  MASK7      :  1;               /*!< GPIO pin PIOn_7 access control bit                                    */
      __IO uint32_t  MASK8      :  1;               /*!< GPIO pin PIOn_8 access control bit                                    */
      __IO uint32_t  MASK9      :  1;               /*!< GPIO pin PIOn_9 access control bit                                    */
      __IO uint32_t  MASK10     :  1;               /*!< GPIO pin PIOn_10 access control bit                                   */
      __IO uint32_t  MASK11     :  1;               /*!< GPIO pin PIOn_11 access control bit                                   */
      __IO uint32_t  MASK12     :  1;               /*!< GPIO pin PIOn_12 access control bit                                   */
      __IO uint32_t  MASK13     :  1;               /*!< GPIO pin PIOn_13 access control bit                                   */
      __IO uint32_t  MASK14     :  1;               /*!< GPIO pin PIOn_14 access control bit                                   */
      __IO uint32_t  MASK15     :  1;               /*!< GPIO pin PIOn_15 access control bit                                   */
    } MASK_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  PIN;                             /*!< Pin state register                                                    */
    
    struct {
      __I  uint32_t  PIN0       :  1;               /*!< GPIO pin PIOn pin PIOn_0 PIN value                                    */
      __I  uint32_t  PIN1       :  1;               /*!< GPIO pin PIOn_1 PIN value                                             */
      __I  uint32_t  PIN2       :  1;               /*!< GPIO pin PIOn_2 PIN value                                             */
      __I  uint32_t  PIN3       :  1;               /*!< GPIO pin PIOn_3 PIN value                                             */
      __I  uint32_t  PIN4       :  1;               /*!< GPIO pin PIOn_4 PIN value                                             */
      __I  uint32_t  PIN5       :  1;               /*!< GPIO pin PIOn_5 PIN value                                             */
      __I  uint32_t  PIN6       :  1;               /*!< GPIO pin PIOn_6 PIN value                                             */
      __I  uint32_t  PIN7       :  1;               /*!< GPIO pin PIOn_7 PIN value                                             */
      __I  uint32_t  PIN8       :  1;               /*!< GPIO pin PIOn_8 PIN value                                             */
      __I  uint32_t  PIN9       :  1;               /*!< GPIO pin PIOn_9 PIN value                                             */
      __I  uint32_t  PIN10      :  1;               /*!< GPIO pin PIOn_10 PIN value                                            */
      __I  uint32_t  PIN11      :  1;               /*!< GPIO pin PIOn_11 PIN value                                            */
      __I  uint32_t  PIN12      :  1;               /*!< GPIO pin PIOn_12 PIN value                                            */
      __I  uint32_t  PIN13      :  1;               /*!< GPIO pin PIOn_13 PIN value                                            */
      __I  uint32_t  PIN14      :  1;               /*!< GPIO pin PIOn_14 PIN value                                            */
      __I  uint32_t  PIN15      :  1;               /*!< GPIO pin PIOn pin PIOn_15 PIN value                                   */
    } PIN_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  OUT;                             /*!< Pin output value register                                             */
    
    struct {
      __IO uint32_t  OUT0       :  1;               /*!< GPIO pin PIOn pin PIOn_0 output value                                 */
      __IO uint32_t  OUT1       :  1;               /*!< GPIO pin PIOn pin PIOn_1 output value                                 */
      __IO uint32_t  OUT2       :  1;               /*!< GPIO pin PIOn pin PIOn_2 output value                                 */
      __IO uint32_t  OUT3       :  1;               /*!< GPIO pin PIOn pin PIOn_3 output value                                 */
      __IO uint32_t  OUT4       :  1;               /*!< GPIO pin PIOn pin PIOn_4 output value                                 */
      __IO uint32_t  OUT5       :  1;               /*!< GPIO pin PIOn pin PIOn_5 output value                                 */
      __IO uint32_t  OUT6       :  1;               /*!< GPIO pin PIOn pin PIOn_6 output value                                 */
      __IO uint32_t  OUT7       :  1;               /*!< GPIO pin PIOn pin PIOn_7 output value                                 */
      __IO uint32_t  OUT8       :  1;               /*!< GPIO pin PIOn pin PIOn_8 output value                                 */
      __IO uint32_t  OUT9       :  1;               /*!< GPIO pin PIOn pin PIOn_9 output value                                 */
      __IO uint32_t  OUT10      :  1;               /*!< GPIO pin PIOn pin PIOn_10 output value                                */
      __IO uint32_t  OUT11      :  1;               /*!< GPIO pin PIOn pin PIOn_11 output value                                */
      __IO uint32_t  OUT12      :  1;               /*!< GPIO pin PIOn pin PIOn_12 output value                                */
      __IO uint32_t  OUT13      :  1;               /*!< GPIO pin PIOn pin PIOn_13 output value                                */
      __IO uint32_t  OUT14      :  1;               /*!< GPIO pin PIOn pin PIOn_14 output value                                */
      __IO uint32_t  OUT15      :  1;               /*!< GPIO pin PIOn pin PIOn_15 output value                                */
    } OUT_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  SET;                             /*!< Pin output value set register                                         */
    
    struct {
      __O  uint32_t  SET0       :  1;               /*!< Set GPIO pin PIOn_0 output value                                      */
      __O  uint32_t  SET1       :  1;               /*!< Set GPIO pin PIOn_1 output value                                      */
      __O  uint32_t  SET2       :  1;               /*!< Set GPIO pin PIOn_2 output value                                      */
      __O  uint32_t  SET3       :  1;               /*!< Set GPIO pin PIOn_3 output value                                      */
      __O  uint32_t  SET4       :  1;               /*!< Set GPIO pin PIOn_4 output value                                      */
      __O  uint32_t  SET5       :  1;               /*!< Set GPIO pin PIOn_5 output value                                      */
      __O  uint32_t  SET6       :  1;               /*!< Set GPIO pin PIOn_6 output value                                      */
      __O  uint32_t  SET7       :  1;               /*!< Set GPIO pin PIOn_7 output value                                      */
      __O  uint32_t  SET8       :  1;               /*!< Set GPIO pin PIOn_8 output value                                      */
      __O  uint32_t  SET9       :  1;               /*!< Set GPIO pin PIOn_9 output value                                      */
      __O  uint32_t  SET10      :  1;               /*!< Set GPIO pin PIOn_10 output value                                     */
      __O  uint32_t  SET11      :  1;               /*!< Set GPIO pin PIOn_11 output value                                     */
      __O  uint32_t  SET12      :  1;               /*!< Set GPIO pin PIOn_12 output value                                     */
      __O  uint32_t  SET13      :  1;               /*!< Set GPIO pin PIOn_13 output value                                     */
      __O  uint32_t  SET14      :  1;               /*!< Set GPIO pin PIOn_14 output value                                     */
      __O  uint32_t  SET15      :  1;               /*!< Set GPIO pin PIOn_15 output value                                     */
    } SET_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  CLR;                             /*!< Pin output value clear register                                       */
    
    struct {
      __O  uint32_t  CLR0       :  1;               /*!< Clear GPIO pin PIOn_0 output value                                    */
      __O  uint32_t  CLR1       :  1;               /*!< Clear GPIO pin PIOn_1 output value                                    */
      __O  uint32_t  CLR2       :  1;               /*!< Clear GPIO pin PIOn_2 output value                                    */
      __O  uint32_t  CLR3       :  1;               /*!< Clear GPIO pin PIOn_3 output value                                    */
      __O  uint32_t  CLR4       :  1;               /*!< Clear GPIO pin PIOn_4 output value                                    */
      __O  uint32_t  CLR5       :  1;               /*!< Clear GPIO pin PIOn_5 output value                                    */
      __O  uint32_t  CLR6       :  1;               /*!< Clear GPIO pin PIOn_6 output value                                    */
      __O  uint32_t  CLR7       :  1;               /*!< Clear GPIO pin PIOn_7 output value                                    */
      __O  uint32_t  CLR8       :  1;               /*!< Clear GPIO pin PIOn_8 output value                                    */
      __O  uint32_t  CLR9       :  1;               /*!< Clear GPIO pin PIOn_9 output value                                    */
      __O  uint32_t  CLR10      :  1;               /*!< Clear GPIO pin PIOn_10 output value                                   */
      __O  uint32_t  CLR11      :  1;               /*!< Clear GPIO pin PIOn_11 output value                                   */
      __O  uint32_t  CLR12      :  1;               /*!< Clear GPIO pin PIOn_12 output value                                   */
      __O  uint32_t  CLR13      :  1;               /*!< Clear GPIO pin PIOn_13 output value                                   */
      __O  uint32_t  CLR14      :  1;               /*!< Clear GPIO pin PIOn_14 output value                                   */
      __O  uint32_t  CLR15      :  1;               /*!< Clear GPIO pin PIOn_13 output value                                   */
    } CLR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  NOT;                             /*!< Pin output value invert register                                      */
    
    struct {
      __O  uint32_t  NOT0       :  1;               /*!< Invert GPIO pin PIOn_0 output value                                   */
      __O  uint32_t  NOT1       :  1;               /*!< Invert GPIO pin PIOn_1 output value                                   */
      __O  uint32_t  NOT2       :  1;               /*!< Invert GPIO pin PIOn_2 output value                                   */
      __O  uint32_t  NOT3       :  1;               /*!< Invert GPIO pin PIOn_3 output value                                   */
      __O  uint32_t  NOT4       :  1;               /*!< Invert GPIO pin PIOn_4 output value                                   */
      __O  uint32_t  NOT5       :  1;               /*!< Invert GPIO pin PIOn_5 output value                                   */
      __O  uint32_t  NOT6       :  1;               /*!< Invert GPIO pin PIOn_6 output value                                   */
      __O  uint32_t  NOT7       :  1;               /*!< Invert GPIO pin PIOn_7 output value                                   */
      __O  uint32_t  NOT8       :  1;               /*!< Invert GPIO pin PIOn_8 output value                                   */
      __O  uint32_t  NOT9       :  1;               /*!< Invert GPIO pin PIOn_9 output value                                   */
      __O  uint32_t  NOT10      :  1;               /*!< Invert GPIO pin PIOn_10 output value                                  */
      __O  uint32_t  NOT11      :  1;               /*!< Invert GPIO pin PIOn_11 output value                                  */
      __O  uint32_t  NOT12      :  1;               /*!< Invert GPIO pin PIOn_12 output value                                  */
      __O  uint32_t  NOT13      :  1;               /*!< Invert GPIO pin PIOn_13 output value                                  */
      __O  uint32_t  NOT14      :  1;               /*!< Invert GPIO pin PIOn_14 output value                                  */
      __O  uint32_t  NOT15      :  1;               /*!< Invert GPIO pin PIOn_15 output value                                  */
    } NOT_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[2];
  
  union {
    __IO uint32_t  DIR;                             /*!< Data direction register                                               */
    
    struct {
      __IO uint32_t  DIR0       :  1;               /*!< Selects GPIO pin PIOn_0 as input or output                            */
      __IO uint32_t  DIR1       :  1;               /*!< Selects GPIO pin PIOn_1 as input or output                            */
      __IO uint32_t  DIR2       :  1;               /*!< Selects GPIO pin PIOn_2 as input or output                            */
      __IO uint32_t  DIR3       :  1;               /*!< Selects GPIO pin PIOn_3 as input or output                            */
      __IO uint32_t  DIR4       :  1;               /*!< Selects GPIO pin PIOn_4 as input or output                            */
      __IO uint32_t  DIR5       :  1;               /*!< Selects GPIO pin PIOn_5 as input or output                            */
      __IO uint32_t  DIR6       :  1;               /*!< Selects GPIO pin PIOn_6 as input or output                            */
      __IO uint32_t  DIR7       :  1;               /*!< Selects GPIO pin PIOn_7 as input or output                            */
      __IO uint32_t  DIR8       :  1;               /*!< Selects GPIO pin PIOn_8 as input or output                            */
      __IO uint32_t  DIR9       :  1;               /*!< Selects GPIO pin PIOn_9 as input or output                            */
      __IO uint32_t  DIR10      :  1;               /*!< Selects GPIO pin PIOn_10 as input or output                           */
      __IO uint32_t  DIR11      :  1;               /*!< Selects GPIO pin PIOn_11 as input or output                           */
      __IO uint32_t  DIR12      :  1;               /*!< Selects GPIO pin PIOn_12 as input or output                           */
      __IO uint32_t  DIR13      :  1;               /*!< Selects GPIO pin PIOn_13 as input or output                           */
      __IO uint32_t  DIR14      :  1;               /*!< Selects GPIO pin PIOn_14 as input or output                           */
      __IO uint32_t  DIR15      :  1;               /*!< Selects GPIO pin PIOn_15 as input or output                           */
    } DIR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IS;                              /*!< interrupt sense register                                              */
    
    struct {
      __IO uint32_t  ISENSE0    :  1;               /*!< Selects interrupt on pin PIOn_0 as level or edge sensitive            */
      __IO uint32_t  ISENSE1    :  1;               /*!< Selects interrupt on pin PIOn_1 as level or edge sensitive            */
      __IO uint32_t  ISENSE2    :  1;               /*!< Selects interrupt on pin PIOn_2 as level or edge sensitive            */
      __IO uint32_t  ISENSE3    :  1;               /*!< Selects interrupt on pin PIOn_3 as level or edge sensitive            */
      __IO uint32_t  ISENSE4    :  1;               /*!< Selects interrupt on pin PIOn_4 as level or edge sensitive            */
      __IO uint32_t  ISENSE5    :  1;               /*!< Selects interrupt on pin PIOn_5 as level or edge sensitive            */
      __IO uint32_t  ISENSE6    :  1;               /*!< Selects interrupt on pin PIOn_6 as level or edge sensitive            */
      __IO uint32_t  ISENSE7    :  1;               /*!< Selects interrupt on pin PIOn_7 as level or edge sensitive            */
      __IO uint32_t  ISENSE8    :  1;               /*!< Selects interrupt on pin PIOn_8 as level or edge sensitive            */
      __IO uint32_t  ISENSE9    :  1;               /*!< Selects interrupt on pin PIOn_9 as level or edge sensitive            */
      __IO uint32_t  ISENSE10   :  1;               /*!< Selects interrupt on pin PIOn_10 as level or edge sensitive           */
      __IO uint32_t  ISENSE11   :  1;               /*!< Selects interrupt on pin PIOn_11 as level or edge sensitive           */
      __IO uint32_t  ISENSE12   :  1;               /*!< Selects interrupt on pin PIOn_12 as level or edge sensitive           */
      __IO uint32_t  ISENSE13   :  1;               /*!< Selects interrupt on pin PIOn_13 as level or edge sensitive           */
      __IO uint32_t  ISENSE14   :  1;               /*!< Selects interrupt on pin PIOn_14 as level or edge sensitive           */
      __IO uint32_t  ISENSE15   :  1;               /*!< Selects interrupt on pin PIOn_15 as level or edge sensitive           */
    } IS_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IBE;                             /*!< Interrupt both edges register                                         */
    
    struct {
      __IO uint32_t  IBE0       :  1;               /*!< Selects interrupt on pin PIOn_0 to be triggered on both edges         */
      __IO uint32_t  IBE1       :  1;               /*!< Selects interrupt on pin PIOn_1 to be triggered on both edges         */
      __IO uint32_t  IBE2       :  1;               /*!< Selects interrupt on pin PIOn_2 to be triggered on both edges         */
      __IO uint32_t  IBE3       :  1;               /*!< Selects interrupt on pin PIOn_3 to be triggered on both edges         */
      __IO uint32_t  IBE4       :  1;               /*!< Selects interrupt on pin PIOn_4 to be triggered on both edges         */
      __IO uint32_t  IBE5       :  1;               /*!< Selects interrupt on pin PIOn_5 to be triggered on both edges         */
      __IO uint32_t  IBE6       :  1;               /*!< Selects interrupt on pin PIOn_6 to be triggered on both edges         */
      __IO uint32_t  IBE7       :  1;               /*!< Selects interrupt on pin PIOn_7 to be triggered on both edges         */
      __IO uint32_t  IBE8       :  1;               /*!< Selects interrupt on pin PIOn_8 to be triggered on both edges         */
      __IO uint32_t  IBE9       :  1;               /*!< Selects interrupt on pin PIOn_9 to be triggered on both edges         */
      __IO uint32_t  IBE10      :  1;               /*!< Selects interrupt on pin PIOn_10 to be triggered on both edges        */
      __IO uint32_t  IBE11      :  1;               /*!< Selects interrupt on pin PIOn_11 to be triggered on both edges        */
      __IO uint32_t  IBE12      :  1;               /*!< Selects interrupt on pin PIOn_12 to be triggered on both edges        */
      __IO uint32_t  IBE13      :  1;               /*!< Selects interrupt on pin PIOn_13 to be triggered on both edges        */
      __IO uint32_t  IBE14      :  1;               /*!< Selects interrupt on pin PIOn_14 to be triggered on both edges        */
      __IO uint32_t  IBE15      :  1;               /*!< Selects interrupt on pin PIOn_15 to be triggered on both edges        */
    } IBE_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IEV;                             /*!< Interrupt event register                                              */
    
    struct {
      __IO uint32_t  IEV0       :  1;               /*!< Selects interrupt on pin PIOn_0 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV1       :  1;               /*!< Selects interrupt on pin PIOn_1 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV2       :  1;               /*!< Selects interrupt on pin PIOn_2 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV3       :  1;               /*!< Selects interrupt on pin PIOn_3 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV4       :  1;               /*!< Selects interrupt on pin PIOn_4 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV5       :  1;               /*!< Selects interrupt on pin PIOn_5 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV6       :  1;               /*!< Selects interrupt on pin PIOn_6 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV7       :  1;               /*!< Selects interrupt on pin PIOn_7 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV8       :  1;               /*!< Selects interrupt on pin PIOn_8 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV9       :  1;               /*!< Selects interrupt on pin PIOn_9 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV10      :  1;               /*!< Selects interrupt on pin PIOn_10 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV11      :  1;               /*!< Selects interrupt on pin PIOn_11 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV12      :  1;               /*!< Selects interrupt on pin PIOn_12 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV13      :  1;               /*!< Selects interrupt on pin PIOn_13 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV14      :  1;               /*!< Selects interrupt on pin PIOn_14 to be triggered rising or falling
                                                         edges.                                                                */
      __IO uint32_t  IEV15      :  1;               /*!< Selects interrupt on pin PIOn_15 to be triggered rising or falling
                                                         edges.                                                                */
    } IEV_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Interrupt mask register                                               */
    
    struct {
      __IO uint32_t  MASK0      :  1;               /*!< Selects interrupt on pin PIOn_0 to be masked.                         */
      __IO uint32_t  MASK1      :  1;               /*!< Selects interrupt on pin PIOn_1 to be masked.                         */
      __IO uint32_t  MASK2      :  1;               /*!< Selects interrupt on pin PIOn_2 to be masked.                         */
      __IO uint32_t  MASK3      :  1;               /*!< Selects interrupt on pin PIOn_3 to be masked.                         */
      __IO uint32_t  MASK4      :  1;               /*!< Selects interrupt on pin PIOn_4 to be masked.                         */
      __IO uint32_t  MASK5      :  1;               /*!< Selects interrupt on pin PIOn_5 to be masked.                         */
      __IO uint32_t  MASK6      :  1;               /*!< Selects interrupt on pin PIOn_6 to be masked.                         */
      __IO uint32_t  MASK7      :  1;               /*!< Selects interrupt on pin PIOn_7 to be masked.                         */
      __IO uint32_t  MASK8      :  1;               /*!< Selects interrupt on pin PIOn_8 to be masked.                         */
      __IO uint32_t  MASK9      :  1;               /*!< Selects interrupt on pin PIOn_9 to be masked.                         */
      __IO uint32_t  MASK10     :  1;               /*!< Selects interrupt on pin PIOn_10 to be masked.                        */
      __IO uint32_t  MASK11     :  1;               /*!< Selects interrupt on pin PIOn_11 to be masked.                        */
      __IO uint32_t  MASK12     :  1;               /*!< Selects interrupt on pin PIOn_12 to be masked.                        */
      __IO uint32_t  MASK13     :  1;               /*!< Selects interrupt on pin PIOn_13 to be masked.                        */
      __IO uint32_t  MASK14     :  1;               /*!< Selects interrupt on pin PIOn_14 to be masked.                        */
      __IO uint32_t  MASK15     :  1;               /*!< Selects interrupt on pin PIOn_15 to be masked.                        */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Raw interrupt status register                                         */
    
    struct {
      __I  uint32_t  RAWST0     :  1;               /*!< Raw interrupt status on pin PIOn_0                                    */
      __I  uint32_t  RAWST1     :  1;               /*!< Raw interrupt status on pin PIOn_1                                    */
      __I  uint32_t  RAWST2     :  1;               /*!< Raw interrupt status on pin PIOn_2                                    */
      __I  uint32_t  RAWST3     :  1;               /*!< Raw interrupt status on pin PIOn_3                                    */
      __I  uint32_t  RAWST4     :  1;               /*!< Raw interrupt status on pin PIOn_4                                    */
      __I  uint32_t  RAWST5     :  1;               /*!< Raw interrupt status on pin PIOn_5                                    */
      __I  uint32_t  RAWST6     :  1;               /*!< Raw interrupt status on pin PIOn_6                                    */
      __I  uint32_t  RAWST7     :  1;               /*!< Raw interrupt status on pin PIOn_7                                    */
      __I  uint32_t  RAWST8     :  1;               /*!< Raw interrupt status on pin PIOn_8                                    */
      __I  uint32_t  RAWST9     :  1;               /*!< Raw interrupt status on pin PIOn_9                                    */
      __I  uint32_t  RAWST10    :  1;               /*!< Raw interrupt status on pin PIOn_10                                   */
      __I  uint32_t  RAWST11    :  1;               /*!< Raw interrupt status on pin PIOn_11                                   */
      __I  uint32_t  RAWST12    :  1;               /*!< Raw interrupt status on pin PIOn_12                                   */
      __I  uint32_t  RAWST13    :  1;               /*!< Raw interrupt status on pin PIOn_13                                   */
      __I  uint32_t  RAWST14    :  1;               /*!< Raw interrupt status on pin PIOn_14                                   */
      __I  uint32_t  RAWST15    :  1;               /*!< Raw interrupt status on pin PIOn_15                                   */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  MIS;                             /*!< Masked interrupt status register                                      */
    
    struct {
      __I  uint32_t  MASK0      :  1;               /*!< Selects interrupt on pin PIOn_0 to be masked                          */
      __I  uint32_t  MASK1      :  1;               /*!< Selects interrupt on pin PIOn_1 to be masked                          */
      __I  uint32_t  MASK2      :  1;               /*!< Selects interrupt on pin PIOn_2 to be masked                          */
      __I  uint32_t  MASK3      :  1;               /*!< Selects interrupt on pin PIOn_3 to be masked                          */
      __I  uint32_t  MASK4      :  1;               /*!< Selects interrupt on pin PIOn_4 to be masked                          */
      __I  uint32_t  MASK5      :  1;               /*!< Selects interrupt on pin PIOn_5 to be masked                          */
      __I  uint32_t  MASK6      :  1;               /*!< Selects interrupt on pin PIOn_6 to be masked                          */
      __I  uint32_t  MASK7      :  1;               /*!< Selects interrupt on pin PIOn_7 to be masked                          */
      __I  uint32_t  MASK8      :  1;               /*!< Selects interrupt on pin PIOn_8 to be masked                          */
      __I  uint32_t  MASK9      :  1;               /*!< Selects interrupt on pin PIOn_9 to be masked                          */
      __I  uint32_t  MASK10     :  1;               /*!< Selects interrupt on pin PIOn_10 to be masked                         */
      __I  uint32_t  MASK11     :  1;               /*!< Selects interrupt on pin PIOn_11 to be masked                         */
      __I  uint32_t  MASK12     :  1;               /*!< Selects interrupt on pin PIOn_12 to be masked                         */
      __I  uint32_t  MASK13     :  1;               /*!< Selects interrupt on pin PIOn_13 to be masked                         */
      __I  uint32_t  MASK14     :  1;               /*!< Selects interrupt on pin PIOn_14 to be masked                         */
      __I  uint32_t  MASK15     :  1;               /*!< Selects interrupt on pin PIOn_15 to be masked                         */
    } MIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Interrupt clear register                                              */
    
    struct {
      __O  uint32_t  CLR0       :  1;               /*!< Selects interrupt on pin PIOn_0 to be cleared                         */
      __O  uint32_t  CLR1       :  1;               /*!< Selects interrupt on pin PIOn_1 to be cleared                         */
      __O  uint32_t  CLR2       :  1;               /*!< Selects interrupt on pin PIOn_2 to be cleared                         */
      __O  uint32_t  CLR3       :  1;               /*!< Selects interrupt on pin PIOn_3 to be cleared                         */
      __O  uint32_t  CLR4       :  1;               /*!< Selects interrupt on pin PIOn_4 to be cleared                         */
      __O  uint32_t  CLR5       :  1;               /*!< Selects interrupt on pin PIOn_5 to be cleared                         */
      __O  uint32_t  CLR6       :  1;               /*!< Selects interrupt on pin PIOn_6 to be cleared                         */
      __O  uint32_t  CLR7       :  1;               /*!< Selects interrupt on pin PIOn_7 to be cleared                         */
      __O  uint32_t  CLR8       :  1;               /*!< Selects interrupt on pin PIOn_8 to be cleared                         */
      __O  uint32_t  CLR9       :  1;               /*!< Selects interrupt on pin PIOn_9 to be cleared                         */
      __O  uint32_t  CLR10      :  1;               /*!< Selects interrupt on pin PIOn_10 to be cleared                        */
      __O  uint32_t  CLR11      :  1;               /*!< Selects interrupt on pin PIOn11 to be cleared                         */
      __O  uint32_t  CLR12      :  1;               /*!< Selects interrupt on pin PIOn_12 to be cleared                        */
      __O  uint32_t  CLR13      :  1;               /*!< Selects interrupt on pin PIOn_13 to be cleared                        */
      __O  uint32_t  CLR14      :  1;               /*!< Selects interrupt on pin PIOn_14 to be cleared                        */
      __O  uint32_t  CLR15      :  1;               /*!< Selects interrupt on pin PIOn_15 to be cleared                        */
    } IC_b;                                         /*!< BitSize                                                               */
  };
} PA_Type;


/* ================================================================================ */
/* ================                       FMC                      ================ */
/* ================================================================================ */


/**
  * @brief Flash control block (FMC)
  */

typedef struct {                                    /*!< FMC Structure                                                         */
  __IO uint32_t  CMD;                               /*!< Flash programming command register                                    */
  __IO uint32_t  DATA;                              /*!< Flash programming data register                                       */
  __IO uint32_t  ADDR;                              /*!< Flash programming address register                                    */
  
  union {
    __IO uint32_t  FLASH_RDCYC;                     /*!< Flash read cycle register                                             */
    
    struct {
      __IO uint32_t  CYCLES     :  2;               /*!< Flash read cycle time                                                 */
    } FLASH_RDCYC_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[8];
  __IO uint32_t  FLASH_RNDEN;                       /*!< Flash RND Enable                                                      */
} FMC_Type;


/* ================================================================================ */
/* ================                       CRC                      ================ */
/* ================================================================================ */


/**
  * @brief Micro digital signal processor (CRC)
  */

typedef struct {                                    /*!< CRC Structure                                                         */
  
  union {
    __IO uint32_t  MODE;                            /*!< CRC mode register                                                     */
    
    struct {
      __IO uint32_t  CRC_POLY   :  2;               /*!< CRC polynomial                                                        */
      __IO uint32_t  BIT_RVS_WR :  1;               /*!< Data bit order                                                        */
      __IO uint32_t  CMPL_WR    :  1;               /*!< Data complement                                                       */
      __IO uint32_t  BIT_RVS_SUM:  1;               /*!< CRC sum bit order                                                     */
      __IO uint32_t  CMPL_SUM   :  1;               /*!< CRC sum complement                                                    */
      __IO uint32_t  SEED_OP    :  1;               /*!< CRC seed option set                                                   */
      __IO uint32_t  SEED_SET   :  1;               /*!< Write 1 to load seed to CRC generator                                 */
    } MODE_b;                                       /*!< BitSize                                                               */
  };
  __IO uint32_t  SEED;                              /*!< CRC seed register                                                     */
  
  union {
    __O  uint32_t  DATA;                            /*!< CRC data register                                                     */
    __I  uint32_t  SUM;                             /*!< CRC checksum register                                                 */
    __O  uint32_t DATA_32BIT;                       /*!< (@ 0x00000008) CRC data register                                          */
    __O  uint16_t DATA_16BIT;                       /*!< (@ 0x00000008) CRC data register                                          */
    __O  uint8_t DATA_8BIT;                         /*!< (@ 0x00000008) CRC data register                                          */
  };
} CRC_Type;


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif




/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define DIA_BASE                        0x1FFF1400UL
#define I2C_BASE                        0x40000000UL
#define WDT_BASE                        0x40004000UL
#define UART0_BASE                      0x40008000UL
#define UART1_BASE                      0x4000C000UL
#define TIM0_BASE                       0x40010000UL
#define TIM1_BASE                       0x40014000UL
#define TIM2_BASE                       0x40054000UL
#define TIM3_BASE                       0x40058000UL
#define TIM6_BASE                       0x40018000UL
#define TIM7_BASE                       0x4001C000UL
#define ADC_BASE                        0x40020000UL
#define PMU_BASE                        0x40038000UL
#define SPI_BASE                        0x40040000UL
#define IOCON_BASE                      0x40044000UL
#define SYSCON_BASE                     0x40048000UL
#define PWM_BASE                        0x4004C000UL
#define LCD_BASE                        0x40068000UL
#define TOUCH_BASE                      0x40078000UL
#define PA_BASE                         0x50000000UL
#define PB_BASE                         0x50010000UL
#define PC_BASE                         0x50020000UL
#define PD_BASE                         0x50030000UL
#define FMC_BASE                        0x50060000UL
#define CRC_BASE                        0x50070000UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define DIA                             ((DIA_Type                *) DIA_BASE)
#define I2C                             ((I2C_Type                *) I2C_BASE)
#define WDT                             ((WDT_Type                *) WDT_BASE)
#define UART0                           ((UART0_Type              *) UART0_BASE)
#define UART1                           ((UART0_Type              *) UART1_BASE)
#define TIM0                            ((TIM0_Type               *) TIM0_BASE)
#define TIM1                            ((TIM0_Type               *) TIM1_BASE)
#define TIM2                            ((TIM0_Type               *) TIM2_BASE)
#define TIM3                            ((TIM0_Type               *) TIM3_BASE)
#define TIM6                            ((TIM6_Type               *) TIM6_BASE)
#define TIM7                            ((TIM6_Type               *) TIM7_BASE)
#define ADC                             ((ADC_Type                *) ADC_BASE)
#define PMU                             ((PMU_Type                *) PMU_BASE)
#define SPI                             ((SPI_Type                *) SPI_BASE)
#define IOCON                           ((IOCON_Type              *) IOCON_BASE)
#define SYSCON                          ((SYSCON_Type             *) SYSCON_BASE)
#define PWM                             ((PWM_Type                *) PWM_BASE)
#define LCD                             ((LCD_Type                *) LCD_BASE)
#define TOUCH                           ((TOUCH_Type              *) TOUCH_BASE)
#define PA                              ((PA_Type                 *) PA_BASE)
#define PB                              ((PA_Type                 *) PB_BASE)
#define PC                              ((PA_Type                 *) PC_BASE)
#define PD                              ((PA_Type                 *) PD_BASE)
#define FMC                             ((FMC_Type                *) FMC_BASE)
#define CRC                             ((CRC_Type                *) CRC_BASE)


/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group CMSDK_CM0 */
/** @} */ /* End of group (null) */

#ifdef __cplusplus
}
#endif


#endif  /* CMSDK_CM0_H */

