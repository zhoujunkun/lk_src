/*****************************************************************************
*   uart.c:  source file for UART
*		ver 1.0
******************************************************************************/

#include "CMSDK_CM0.h"
#include "uart.h"
#include "sys.h"

extern uint32_t MainClock;
/*****************************************************************************
Function Name	UART_Open
Function Definition	void UART_Open(UART0_Type *uart, uint32_t baudrate, uint8_t parityoption, uint8_t rxinttriggerlevel);
Function Description	Initial UART 
Input Parameters	*uart : pointer to UART device, UART0/UART1
									Baudrate: baudrate value
									Parityoption: NO_PARITY, EVEN_PARITY, ODD_PARITY
									Rxinttriggerlevel; 1(not empty), 8(half full), 16(full)
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_Open(UART0_Type *uart, uint32_t baudrate, uint8_t parityoption, uint8_t rxinttriggerlevel)
{
	uint32_t volatile delays;
  
	if (uart==UART0)
	{
		//disable UART0 IRQ during setup
		NVIC_DisableIRQ(UART0_IRQn);
		//Enable UART clock
		SYSCON->SYSAHBCLKCTRL_b.UART0_CLK=1;	//enable UART0 PCLK
		SYSCON->UART0CLKDIV_b.DIV = 0x1;     /* divided by 1 */
		//reset UART
		SYSCON->PRESETCTRL_b.UART0_RST_N=0;
		SYSCON->PRESETCTRL_b.UART0_RST_N=1;
	}else if (uart==UART1)
	{
		//disable UART0 IRQ during setup
		NVIC_DisableIRQ(UART1_IRQn);
		/* Enable UART clock */
		SYSCON->SYSAHBCLKCTRL_b.UART1_CLK=1;	//enable UART1 PCLK
		SYSCON->UART1CLKDIV_b.DIV = 0x1;     /* divided by 1 */
		//reset UART
		SYSCON->PRESETCTRL_b.UART1_RST_N=0;
		SYSCON->PRESETCTRL_b.UART1_RST_N=1;
	}else return ;
	
  //set up baudrate
  uart->BAUDDIV_b.BAUDDIV = MainClock/baudrate;
	
	//set parity
	if (parityoption==UART_ODD_PARITY)
		uart->CTRL_b.PARISEL=1;
	if (parityoption!=UART_NO_PARITY)
		uart->CTRL_b.PARIEN=1;
	
	//setup rx int trigger level
	if (rxinttriggerlevel==UART_RX_NOT_EMPTY)
		uart->CTRL_b.RXNEIE=1;
	if (rxinttriggerlevel==UART_RX_HALF_FULL)
		uart->CTRL_b.RXHLFIE=1;
	if (rxinttriggerlevel==UART_RX_FULL)
		uart->CTRL_b.RXFIE=1;
	
	//enable rx,tx function
  uart->CTRL_b.TXEN=1; 
	uart->CTRL_b.RXEN=1;
	//insert delay
	SYS_DelaymS(1);
	//clr FIFO
	uart->FIFOCLR=0xFF;
  return;	
}
/*****************************************************************************
Function Name	UART_Close
Function Definition	void UART_Close(UART0_Type *uart);
Function Description	close UART
Input Parameters	*uart : pointer to UART device, UART0/UART1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_Close(UART0_Type *uart)
{
	if (uart==UART0)
	{
		//disable UART0 IRQ during setup
		NVIC_DisableIRQ(UART0_IRQn);
		//Disable UART clock
		SYSCON->SYSAHBCLKCTRL_b.UART0_CLK=0;	
	}else if (uart==UART1)
	{
		//disable UART0 IRQ during setup
		NVIC_DisableIRQ(UART1_IRQn);
		//Disable UART clock
		SYSCON->SYSAHBCLKCTRL_b.UART1_CLK=0;
	}else return ;	
	//Disable UART int
	UART_DisableInt(uart);
	UART_ClearIntFlag(uart);	
	
	return;
}
/*****************************************************************************
Function Name	UART_ByteRead
Function Definition	Uint8_t UART_ByteRead(UART0_Type *uart, uint8_t *data);
Function Description	Read one byte from UART
Input Parameters	*uart : pointer to UART device, UART0/UART1
*data: if RX FIFO is not empty, return value
Return Value	If read success, return 0; otherwise return 1.
Condition	No
Function called	-

*****************************************************************************/
uint8_t UART_ByteRead(UART0_Type *uart, uint8_t *data)
{
	if (uart->STATE_b.RXNE)
	{
		*data=uart->DATA;
		return 0;
	}else
		return 1;
}
/*****************************************************************************
Function Name	UART_Read
Function Definition	Uint8_t UART_Read(UART0_Type *uart, uint8_t * rxbuf, uint8_t *readbytes);
Function Description	Read data bytes from UART
Input Parameters	*uart : pointer to UART device, UART0/UART1
*rxbuf: data buffer used to store data from UART
*readbytes: number of read data in byte. return no of bytes got.
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_Read(UART0_Type *uart, uint8_t * rxbuf, uint8_t *readbytes)
{
	uint8_t temp=0;
	//get all data
	while ((uart->STATE_b.RXNE)&&((*readbytes)--))
	{
		*rxbuf++=uart->DATA;
		temp++;
	}
	//return number of read
	*readbytes=temp;
	return;
}
/*****************************************************************************
Function Name	UART_ByteWrite
Function Definition	Uint8_t UART_ByteWrite(UART0_Type *uart, uint8_t data);
Function Description	Write one byte to UART
Input Parameters	*uart : pointer to UART device, UART0/UART1
Data: data write to TX FIFO of UART
Return Value	If write success, return 0; otherwise return 1.
Condition	No
Function called	-

*****************************************************************************/
uint8_t UART_ByteWrite(UART0_Type *uart, uint8_t data)
{
	if (uart->STATE_b.TXF)
		return 1;
	
	uart->DATA=data;
	return 0;
}
/*****************************************************************************
Function Name	UART_Write
Function Definition	Uint8_t UART_Write(UART0_Type *uart, uint8_t * txbuf, uint8_t writebytes);
Function Description	Write bytes to UART FIFO
Input Parameters	*uart : pointer to UART device, UART0/UART1
*txbuf: data buffer to UART
*writebytes: number of read data in byte. Maxum is 16. if TX FIFO is not empty, function return fail.
Return Value	If write success, return 0; otherwise return 1.
Condition	No
Function called	-

*****************************************************************************/
uint8_t  UART_Write(UART0_Type *uart, uint8_t * txbuf, uint8_t writebytes)
{
	if ((uart->STATE_b.TXF)||(writebytes>16))
		return 1;
	while (writebytes--)
	{
		uart->DATA=*txbuf++;
	}
	return 0;
}	

/*****************************************************************************
Function Name	UART_Send
Function Definition	void UART_Send(UART0_Type *uart, uint8_t * txbuf, uint32_t sendbytes);
Function Description	Send bytes data via UART 
Input Parameters	*uart : pointer to UART device, UART0/UART1
*txbuf: data buffer to UART
sendbytes: number of data in byte to be sent 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_Send(UART0_Type *uart, uint8_t * txbuf, uint32_t sendbytes)
{
	while (sendbytes--)
	{
		while (uart->STATE_b.TXF);
		uart->DATA=*txbuf++;
	}
	return;
}	
/*****************************************************************************
Function Name	UART_PutString
Function Definition	void UART_PutString (UART0_Type *uart, uint8_t * str);
Function Description	Send data string via UART 
Input Parameters	*uart : pointer to UART device, UART0/UART1
*str: data string 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_PutString (UART0_Type *uart, uint8_t * str)
{
	while (!(* str=='\0'))
	{
		while (uart->STATE_b.TXF);
		uart->DATA=*str++;
	}
	return;
}
/*****************************************************************************
Function Name	UART_PutHex
Function Definition	void UART_PutHex (UART0_Type *uart, uint32_t data);
Function Description	Send data in hex format via UART 
Input Parameters	*uart : pointer to UART device, UART0/UART1
data: data to send 
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_PutHex (UART0_Type *uart, uint32_t data)
{
	uint8_t hex;
	uint8_t len=7;
	do
	{
		hex=(data & 0xF0000000)>>28;
		if (hex>9)
			hex=hex+'A'-10;
		else
			hex+='0';
		while (uart->STATE_b.TXF);
		uart->DATA=hex;
		data=data<<4;
	}while (len--);
	return;
}	
/*****************************************************************************
Function Name	UART_EnableInt
Function Definition	void UART_EnableInt(UART0_Type *uart, uint32_t intcon);
Function Description	Set UART interrupt type 
Input Parameters	*uart : pointer to UART device, UART0/UART1
intcon: interrupt type combination: TXEINT, RXNEINT, TXFINT, RXFINT, TXHLFINT, RXHLFINT, PARIERRINT, OVERRUNINT
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_EnableInt(UART0_Type *uart, uint32_t intcon)
{
	uart->CTRL |= intcon;
	return;
}
/*****************************************************************************
Function Name	UART_DisableInt
Function Definition	void UART_DisableInt(UART0_Type *uart);
Function Description	Disable UART interrupt 
Input Parameters	*uart : pointer to UART device, UART0/UART1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_DisableInt(UART0_Type *uart)
{
	uart->CTRL &= 0xFFFFFF00;
	return;
}
/*****************************************************************************
Function Name	UART_ClearIntFlag
Function Definition	void UART_ClearIntFlag(UART0_Type *uart);
Function Description	Clear UART interrupt flag
Input Parameters	*uart : pointer to UART device, UART0/UART1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_ClearIntFlag(UART0_Type *uart)
{
	uart->INTSTATUS |= 0xFF;
	return;
}
/*****************************************************************************
Function Name	UART_GetStatus
Function Definition	void UART_GetStatus (UART0_Type *uart);
Function Description	Get UART Status 
Input Parameters	*uart : pointer to UART device, UART0/UART1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
uint8_t UART_GetStatus(UART0_Type*uart)
{
	return (uint8_t) uart->STATE;
}
/*****************************************************************************
Function Name	UART_ClearFIFO
Function Definition	void UART_ClearFIFO(UART0_Type *uart,);
Function Description	Clear UART FIFO
Input Parameters	*uart : pointer to UART device, UART0/UART1
Return Value	No
Condition	No
Function called	-

*****************************************************************************/
void UART_ClearFIFO(UART0_Type *uart)
{
	uart->FIFOCLR=0xFF;
	return ;
}


/******************************************************************************
**                            End Of File
******************************************************************************/
