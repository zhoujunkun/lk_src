;/*****************************************************************************
; * @file:    startup_CMSDK_M0.s
; * @description: CMSIS Cortex-M0 Core Device Startup File 
; *           for the ME32F030 Device Series ARM CC compiler only
; * @version: V1.0
; * @date:    2017/08/08
; *-----------------------------------------------------------------------------
;
;/*****************************************************************************/
;/* Startup.s: Startup file for ARM Cortex-M0 Device Family                   */
;/*****************************************************************************/


;// <h> Stack Configuration
;//   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Heap_Size       EQU     0x00000100

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler
                ; External Interrupts
                DCD     0         ; 16+ 0: Wake
                DCD     PMWFAULT_IRQHandler       ; 16+ 1: PWM Fault interrupt	Handler
                DCD     I2C_IRQHandler    		; 16+ 2: I2C	interrupt	Handler
				DCD     TIM0_IRQHandler               ; 16+3, 16-bit Timer0 Interrupt Handler 
				DCD     TIM1_IRQHandler               ; 16+4, 16-bit Timer1 Interrupt Handler
				DCD     TIM6_IRQHandler               ; 16+5,  16-bit Timer6 Interrupt Handler
				DCD     TIM7_IRQHandler               ; 16+6,  16-bit Timer7 Interrupt Handler
				DCD     UART0_IRQHandler                    ; 16+7,  UART0 Interrupt Handler   
				DCD     UART1_IRQHandler                    ; 16+8,  UART1 Interrupt Handler    
				DCD     ADC_IRQHandler                      ; 16+9,  A/D Converter Interrupt Handler
				DCD     WDT_IRQHandler                      ; 16+10,  Watchdog timer Interrupt Handler   
				DCD     BOD_IRQHandler                      ; 16+11, Brown Out Detect(BOD) Interrupt Handler
				DCD     PA_IRQHandler                    ; 16+12, External Interrupt GPIO port A Interrupt Handler
				DCD     PB_IRQHandler                    ; 16+13, External Interrupt GPIO port B Interrupt Handler
				DCD     PC_IRQHandler                    ; 16+14, External Interrupt GPIO port C Interrupt Handler
				DCD     0                      ; 16+15,           
				DCD     SPI_IRQHandler                      ; 16+16, SPI Interrupt Handler           
				DCD     PWM_IRQHandler                ; 16+17, PWM Timer Interrupt Handler 
				DCD     TOUCH_IRQHandler         ; 16+18: Cap touch sense Handler                
                DCD     PD_IRQHandler          ; 16+19: External Interrupt GPIO port D Interrupt Handler
                DCD     0           ; 16+20: Reserved              
                DCD     0           ; 16+21: Reserved
                DCD     TIM2_IRQHandler            ; 16+22: 16-bit Timer2 Interrupt Handler                
                DCD     TIM3_IRQHandler            ; 16+23: 16-bit Timer3 Interrupt Handler
                DCD     0						  ; 16+24: Reserved
                DCD     0          ; 16+25: Reserved
                DCD     0          ; 16+26: Reserved
                DCD     0          ; 16+27: Reserved
                DCD     0			; 16+28: Reserved
                DCD     0            ; 16+29: Reserved
                DCD     0            ; 16+30: Reserved
                DCD     0            ; 16+31: Reserved   

__Vectors_End

__Vectors_Size         EQU     __Vectors_End - __Vectors
                AREA    |.text|, CODE, READONLY
 
; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  __main
                LDR     R0, =__main
                BX      R0
                ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler    PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
               EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP
Default_Handler PROC
                EXPORT  NMI_Handler               [WEAK]
				EXPORT  PMWFAULT_IRQHandler           [WEAK]
				EXPORT  I2C_IRQHandler           [WEAK]
                EXPORT  TIM0_IRQHandler      [WEAK]
                EXPORT  TIM1_IRQHandler      [WEAK]
                EXPORT  TIM6_IRQHandler      [WEAK]
                EXPORT  TIM7_IRQHandler      [WEAK]
                EXPORT  UART0_IRQHandler          [WEAK]
                EXPORT  UART1_IRQHandler          [WEAK]
				EXPORT  ADC_IRQHandler           [WEAK]
                EXPORT  WDT_IRQHandler            [WEAK]
                EXPORT  BOD_IRQHandler            [WEAK]
                EXPORT	PA_IRQHandler          [WEAK]
                EXPORT	PB_IRQHandler          [WEAK]
                EXPORT  PC_IRQHandler          [WEAK]
				EXPORT  SPI_IRQHandler            [WEAK]
                EXPORT  PWM_IRQHandler            [WEAK]
                EXPORT  TOUCH_IRQHandler            [WEAK]
				EXPORT  PD_IRQHandler            [WEAK]
                EXPORT  TIM2_IRQHandler      [WEAK]
                EXPORT  TIM3_IRQHandler      [WEAK]


PMWFAULT_IRQHandler 
I2C_IRQHandler
TIM0_IRQHandler
TIM1_IRQHandler
TIM6_IRQHandler
TIM7_IRQHandler
UART0_IRQHandler
UART1_IRQHandler
ADC_IRQHandler
WDT_IRQHandler
BOD_IRQHandler
PA_IRQHandler  
PB_IRQHandler 
PC_IRQHandler
SPI_IRQHandler
PWM_IRQHandler
TOUCH_IRQHandler
PD_IRQHandler
TIM2_IRQHandler
TIM3_IRQHandler

				B   .   
				ENDP

                ALIGN
  
; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF

                END

