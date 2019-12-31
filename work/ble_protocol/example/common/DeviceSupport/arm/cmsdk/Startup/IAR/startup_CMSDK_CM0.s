;/*****************************************************************************
; * @file:    startup_CMSDK_M0.s
; * @description: CMSIS Cortex-M0 Core Device Startup File 
; *           for the ME32F030 Device Series IAR compiler use only
; * @version: V1.0
; * @date:    2017/08/08
; *-----------------------------------------------------------------------------
;
;/*****************************************************************************/
;/* Startup.s: Startup file for ARM Cortex-M0 Device Family                   */
;/*****************************************************************************/



    MODULE  ?cstartup

    ;; Forward declaration of sections.
    SECTION CSTACK:DATA:NOROOT(3) ;; 8 bytes alignment

    SECTION .intvec:CODE:NOROOT(2);; 4 bytes alignment

    EXTERN  __iar_program_start
    ;EXTERN  HardFault_Handler
    PUBLIC  __vector_table

    DATA
__vector_table
    DCD     sfe(CSTACK)
    DCD     __iar_program_start

    DCD     NMI_Handler
    DCD     HardFault_Handler
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     SVC_Handler
    DCD     0
    DCD     0
    DCD     PendSV_Handler
    DCD     SysTick_Handler

    ; External Interrupts
    DCD     0         					; 16+ 0: 
    DCD     PMWFAULT_IRQHandler         		; 16+ 1: PWM Fault interrupt	Handler
    DCD     I2C_IRQHandler    				; 16+ 2: I2C	interrupt	Handler
    DCD     TIM0_IRQHandler               		; 16+3, 16-bit Timer0 Interrupt Handler 
    DCD     TIM1_IRQHandler               		; 16+4, 16-bit Timer1 Interrupt Handler
    DCD     TIM6_IRQHandler               		; 16+5,  16-bit Timer6 Interrupt Handler
    DCD     TIM7_IRQHandler               		; 16+6,  16-bit Timer7 Interrupt Handler
    DCD     UART0_IRQHandler                    ; 16+7,  UART0 Interrupt Handler   
    DCD     UART1_IRQHandler                    ; 16+8,  UART1 Interrupt Handler    
    DCD     ADC_IRQHandler                      ; 16+9,  A/D Converter Interrupt Handler
    DCD     WDT_IRQHandler                      ; 16+10,  Watchdog timer Interrupt Handler   
    DCD     BOD_IRQHandler                      ; 16+11, Brown Out Detect(BOD) Interrupt Handler
    DCD     PA_IRQHandler                    ; 16+12, External Interrupt GPIO Port A Interrupt Handler
    DCD     PB_IRQHandler                    ; 16+13, External Interrupt GPIO Port B Interrupt Handler
    DCD     PC_IRQHandler                    ; 16+14, External Interrupt GPIO Port C Interrupt Handler
    DCD     0                      ; 16+15,          
    DCD     SPI_IRQHandler                      ; 16+16, SSP Interrupt Handler           
    DCD     PWM_IRQHandler                	; 16+17, PWM Timer Interrupt Handler 
    DCD     TOUCH_IRQHandler         				; 16+18: Cap touch sense Handler                
    DCD     PD_IRQHandler          				; 16+19: External Interrupt GPIO Port D Interrupt Handler
    DCD     0           													; 16+20: Reserved              
    DCD     0           													; 16+21: Reserved
	DCD     TIM2_IRQHandler            ; 16+22: 16-bit Timer2 Interrupt Handler                
	DCD     TIM3_IRQHandler            ; 16+23: 16-bit Timer3 Interrupt Handler
    DCD     0				; 16+24: Reserved
    DCD     0          			; 16+25: Reserved
    DCD     0          			; 16+26: Reserved
    DCD     0          			; 16+27: Reserved
    DCD     0				; 16+28: Reserved
    DCD     0            													; 16+29: Reserved
    DCD     0            													; 16+30: Reserved
    DCD     0            													; 16+31: Reserved   

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
    THUMB
    PUBWEAK Reset_Handler   
    SECTION .text:CODE:REORDER(2)       ; 4 bytes alignment
Reset_Handler
             
        LDR      R0, =__iar_program_start
        BX       R0
        
    PUBWEAK NMI_Handler
    PUBWEAK HardFault_Handler
    PUBWEAK SVC_Handler       
    PUBWEAK PendSV_Handler    
    PUBWEAK SysTick_Handler         
    PUBWEAK PMWFAULT_IRQHandler 
    PUBWEAK I2C_IRQHandler
    PUBWEAK TIM0_IRQHandler
    PUBWEAK TIM1_IRQHandler
    PUBWEAK TIM6_IRQHandler
    PUBWEAK TIM7_IRQHandler
    PUBWEAK UART0_IRQHandler
    PUBWEAK UART1_IRQHandler
    PUBWEAK ADC_IRQHandler
    PUBWEAK WDT_IRQHandler
    PUBWEAK BOD_IRQHandler
    PUBWEAK PA_IRQHandler  
    PUBWEAK PB_IRQHandler 
    PUBWEAK PC_IRQHandler
    PUBWEAK SPI_IRQHandler
    PUBWEAK PWM_IRQHandler
    PUBWEAK TOUCH_IRQHandler
    PUBWEAK PD_IRQHandler
    PUBWEAK TIM2_IRQHandler
    PUBWEAK TIM3_IRQHandler

    SECTION .text:CODE:REORDER(2)

NMI_Handler       
SVC_Handler
HardFault_Handler
PendSV_Handler    
SysTick_Handler   
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
Default_Handler 

    B Default_Handler         



    
    END
;
