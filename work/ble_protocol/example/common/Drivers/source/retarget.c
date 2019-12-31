/**************************************************************************//**
 * @file     retarget.c
 * @version  V1.10
 * $Revision: 2 $
*****************************************************************************/ 
#include <stdio.h>
#include "UART.h"
#if defined ( __CC_ARM   )
#if (__ARMCC_VERSION < 400000)
#else
/* Insist on keeping widthprec, to avoid X propagation by benign code in C-lib */
#pragma import _printf_widthprec
#endif
#endif

/* Un-comment this line to disable all printf and getchar. getchar() will always return 0x00*/
//#define ENABLE_UART0

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

#if !(defined(__ICCARM__) && (__VER__ >= 6010000))
struct __FILE { int handle; /* Add whatever you need here */ };
#endif
FILE __stdout;
FILE __stdin;

enum { r0, r1, r2, r3, r12, lr, pc, psr};

void stackDump(uint32_t stack[])
{
	printf("r0  = 0x%x\n", stack[r0]);
	printf("r1  = 0x%x\n", stack[r1]);
	printf("r2  = 0x%x\n", stack[r2]);
	printf("r3  = 0x%x\n", stack[r3]);
	printf("r12 = 0x%x\n", stack[r12]);
	printf("lr  = 0x%x\n", stack[lr]);
	printf("pc  = 0x%x\n", stack[pc]);
	printf("psr = 0x%x\n", stack[psr]);
} 

void Hard_Fault_Handler(uint32_t stack[])
{     
    printf("In Hard Fault Handler\n");

    stackDump(stack);

    while(1);
}
# if defined(__ICCARM__)

/**
 * @brief    This HardFault handler is implemented to show r0, r1, r2, r3, r12, lr, pc, psr 
 *
 * @param    None
 *
 * @returns  None
 *
 * @details  This function is implement to print r0, r1, r2, r3, r12, lr, pc, psr.
 *
 */
void HardFault_Handler(void)
{
    asm("MOVS    r0, #4                        \n"
        "MOV     r1, LR                        \n"
        "TST     r0, r1                        \n"
        "BEQ     Stack_Use_MSP                 \n" 
        "MRS     R0, PSP                       \n" //; stack use PSP 
        "B       Get_LR_and_Branch             \n" 
        "Stack_Use_MSP:                        \n" 
        "MRS     R0, MSP                       \n" //; stack use MSP 
        "Get_LR_and_Branch:                    \n" 
        "MOV     R1, LR                        \n" //; LR current value 
        "B Hard_Fault_Handler                  \n" 
       );
     
    while(1);
}

# else

/**
 * @brief    This HardFault handler is implemented to show r0, r1, r2, r3, r12, lr, pc, psr
 *
 * @param    None
 *
 * @returns  None
 *
 * @details  This function is implement to print r0, r1, r2, r3, r12, lr, pc, psr
 *
 */
__asm int32_t HardFault_Handler(void)
{
    MOVS    r0, #4 
    MOV     r1, LR 
    TST     r0, r1 
    BEQ     Stack_Use_MSP 
    MRS     R0, PSP ;stack use PSP 
    B       Get_LR_and_Branch 
Stack_Use_MSP 
    MRS     R0, MSP ; stack use MSP 
Get_LR_and_Branch 
    MOV     R1, LR ; LR current value 
    LDR     R2,=__cpp(Hard_Fault_Handler) 
    BX      R2                  
}

#endif

/**
  * @brief  Write a char to UART.
  * @param  ch The character sent to UART.
  * @return None
  */

void SendChar_ToUART(int ch)
{
	while(UART0->STATE_b.TXF);
	UART0->DATA= ch;
	if(ch == '\n')
	{
		while(UART0->STATE_b.TXF);
		UART0->DATA= '\r';
	}
}


/**
  * @brief  Write a char to debug console.
  * @param  ch The character sent to debug console
  * @return None
  */

void SendChar(int ch)
{
   SendChar_ToUART(ch);
}


/**
  * @brief  Read a char from debug console.
  * @param  None
  * @return Received character from debug console
  * @note   This API waits until UART debug port or semihost input a character
  */

char GetChar(void)
{
	while (1)
	{
		if(UART0->STATE_b.RXNE)
			return (UART0->DATA);
	}     
}


/**
  * @brief  Check whether UART receive FIFO is empty or not.
  * @param  None
  * @return UART Rx FIFO empty status
  * @retval 1 Indicates at least one character is available in UART Rx FIFO
  * @retval 0 UART Rx FIFO is empty
  */
int kbhit(void)
{
   return UART0->STATE_b.RXNE;
}

/**
  * @brief  Check whether UART transmit FIFO is empty or not.
  * @param  None
  * @return UART Tx FIFO empty status
  * @retval 1 UART Tx FIFO is empty
  * @retval 0 UART Tx FIFO is not empty
  */
int IsDebugFifoEmpty(void)
{
   return (UART0->STATE_b.TXF) ? 1 : 0;
}

/*---------------------------------------------------------------------------------------------------------*/
/* C library retargetting                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
void _ttywrch(int ch)
{
  SendChar(ch);
  return;
}

int fputc(int ch, FILE *f)
{
  SendChar(ch);
  return ch;
}

int fgetc(FILE *f) {
   return (GetChar());
}


int ferror(FILE *f) {
  return EOF;
}

/*** (C) COPYRIGHT 2017 Mesilicon***/

