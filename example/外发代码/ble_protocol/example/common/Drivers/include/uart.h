/*****************************************************************************
*   uart.h:  Header file for uart.c
*		ver 1.0	
******************************************************************************/
//#define __UART0

#ifndef __UART_H 
#define __UART_H
#include "CMSDK_CM0.h"
//stauts and int bit
#define UART_NO_PARITY 0x0 
#define UART_EVEN_PARITY 0x1
#define UART_ODD_PARITY 0x2
#define UART_RX_NO_INT 0x0
#define UART_TX_EMPTY 0x1
#define UART_RX_NOT_EMPTY 0x2
#define UART_TX_FULL 0x4 
#define UART_RX_FULL 0x8
#define UART_TX_HALF_FULL 0x10 
#define UART_RX_HALF_FULL 0x20
#define UART_PARIERRINT 0x40 
#define UART_OVERRUNINT 0x80


void UART_Open(UART0_Type *uart, uint32_t baudrate, uint8_t parityoption, uint8_t rxinttriggerlevel);
void UART_Close(UART0_Type *uart);
uint8_t UART_ByteRead(UART0_Type *uart, uint8_t *data);
void UART_Read(UART0_Type *uart, uint8_t * rxbuf, uint8_t *readBytes);
uint8_t UART_ByteWrite(UART0_Type *uart, uint8_t data);
uint8_t UART_Write(UART0_Type *uart, uint8_t * txbuf, uint8_t writebytes);
void UART_Send(UART0_Type *uart, uint8_t * txbuf, uint32_t sendbytes);
void UART_PutString (UART0_Type *uart, uint8_t * str);
void UART_PutHex (UART0_Type *uart, uint32_t data);
void UART_EnableInt(UART0_Type *uart, uint32_t intcon);
void UART_DisableInt(UART0_Type *uart);
void UART_ClearIntFlag(UART0_Type *uart);
uint8_t UART_GetStatus(UART0_Type*uart);
void UART_ClearFIFO(UART0_Type *uart);

#endif /* end __UART_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
