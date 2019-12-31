/*****************************************************************************
*   gpio.c:  source file for GPIO
*		ver 1.0
******************************************************************************/
#include "gpio.h"
#include "sys.h"

/*****************************************************************************
Function Name	GPIO_SetPinsAsInput
Function Definition	void GPIO_SetPinsAsInput(PA_Type *port, uint16_t pins)
Function Description	Setup GPIO pins as digital input
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Pins: combination of IO_PIN0~IO_PIN15, predefine in sys.h
Return Value	No
Condition	#include sys.h
Function called	-

*****************************************************************************/
void GPIO_ConfigPinsAsInput(PA_Type *port, uint16_t pins)
{
	port->DIR &= ~pins;
	return;
}
/*****************************************************************************
Function Name	GPIO_SetPinsAsOutput
Function Definition	void GPIO_SetPinsAsOutput(PA_Type *port, uint16_t pins)
Function Description	Setup GPIO pins as digital Output
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Pins: combination of IO_PIN0~IO_PIN15, predefine in sys.h
Return Value	No
Condition	#include sys.h
Function called	-

*****************************************************************************/
void GPIO_ConfigPinsAsOutput(PA_Type *port, uint16_t pins)
{
	port->DIR|=pins;
	return;
}

/*****************************************************************************
Function Name	GPIO_SetPin
Function Definition	void GPIO_SetPin (PA_Type *port, uint16_t pin)
Function Description	Set GPIO pin Output as 1
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Pin: IO_PIN0~IO_PIN15, predefine in sys.h
Return Value	No
Condition	#include sys.h
Function called	-

*****************************************************************************/
void GPIO_SetPin(PA_Type *port, uint16_t pin)
{
	port->SET |= pin;
	return;
}

/*****************************************************************************
Function Name	GPIO_ResetPin
Function Definition	void GPIO_ResetPin (PA_Type *port, uint16_t pin)
Function Description	Reset GPIO pin Output as 0
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Pin: IO_PIN0~IO_PIN15, predefine in sys.h
Return Value	No
Condition	#include sys.h
Function called	-

*****************************************************************************/
void GPIO_ResetPin (PA_Type *port, uint16_t pin)
	{
	port->CLR |= pin;
	return;
}
	
/*****************************************************************************
Function Name	GPIO_InvertOutPin
Function Definition	void GPIO_InvertOutPin (PA_Type *port, uint16_t pin)
Function Description	Invert GPIO pin Output 
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Pin: IO_PIN0~IO_PIN15, predefine in sys.h
Return Value	No
Condition	#include sys.h
Function called	-

*****************************************************************************/
void GPIO_InvertOutPin (PA_Type *port, uint16_t pin)
{
	port->NOT |= pin;
	return;
}
	
/*****************************************************************************
Function Name	GPIO_GetPinState
Function Definition	uint8_t GPIO_GetPinState(PA_Type *port, uint16_t pin)
Function Description	get GPIO pin state
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Pin: IO_PIN0~IO_PIN15, predefine in sys.h
Return Value	GPIO pin state, 0 is low and 1is high
Condition	#include sys.h
Function called	-

*****************************************************************************/
uint8_t GPIO_GetPinState(PA_Type *port, uint16_t pin)
{
	if (port->PIN & pin)
		return 1;
	else
		return 0;
}

/*****************************************************************************
Function Name	GPIO_GetPortState
Function Definition	uint16_t GPIO_GetPortState(PA_Type *port)
Function Description	get GPIO port state
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Return Value	GPIO port state value
Condition	-
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
uint16_t GPIO_GetPortState(PA_Type *port)
{
	return (uint16_t)port->PIN;
}


/*****************************************************************************
Function Name	GPIO_SetPortMask
Function Definition	void GPIO_SetPortMask(PA_Type *port, uint16_t pins)
Function Description	Set GPIO port IO mask
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Pins: combination of IO_PIN0~IO_PIN15, predefine in sys.h
Return Value	No
Condition	#include sys.h
Function called	-

*****************************************************************************/
void GPIO_SetPortMask(PA_Type *port, uint16_t pins)
{
	port->MASK |= pins;
	return;
}
/*****************************************************************************
Function Name	GPIO_ResetPortMask
Function Definition	void GPIO_ResetPortMask(PA_Type *port, uint16_t pins)
Function Description	Remove GPIO port IO mask
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Pins: combination of IO_PIN0~IO_PIN15, predefine in sys.h
Return Value	No
Condition	#include sys.h
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void GPIO_ResetPortMask(PA_Type *port, uint16_t pins)
{
	port->MASK &= ~pins;
	return;
}

/*****************************************************************************
Function Name	GPIO_ReadPort
Function Definition	uint16_t GPIO_ReadPort(PA_Type *port)
Function Description	Read GPIO port value
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Return Value	Return GPIO port value
Condition	#include sys.h
Function called	-

*****************************************************************************/
uint16_t GPIO_ReadPort(PA_Type *port)
{
	return (uint16_t) port->PIN;
}

/*****************************************************************************
Function Name	GPIO_WritePort
Function Definition	void GPIO_WritePort(PA_Type *port, uint16_t data)
Function Description	Write value to GPIO port
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
Data: data to be write to GPIO port
Return Value	No
Condition	#include sys.h
Function called	-

*****************************************************************************/
void GPIO_WritePort(PA_Type *port, uint16_t data)
{
	port->OUT=data;
	return;
}

/*****************************************************************************
Function Name	GPIO_EnableInt
Function Definition	void GPIO_EnableInt(PA_Type *port, uint16_t pin, uint8_t triggeredge)
Function Description	Setup GPIO pin interrupt
Input Parameters	* port : pointer to GPIO device, PA/GPIO1/GPIO2
pin: IO_PIN0~IO_PIN15, predefine in sys.h
triggeredge: RISE_EDGE/FALL_EDGE/BOTH_EDGE
Return Value	Return GPIO port value
Condition	#include sys.h
Function called	-

*****************************************************************************/
void GPIO_EnableInt(PA_Type *port, uint16_t pin, uint8_t triggeredge)
{
	port->IS &= ~pin;
	port->IE |= pin;
	switch(triggeredge)
	{
		case RISE_EDGE:
			port->IBE &= ~pin;
			port->IEV |= pin;
			break;
		case FALL_EDGE:
			port->IBE &= ~pin;
			port->IEV &= ~pin;
			break;
		case BOTH_EDGE:
			port->IBE |= pin;
			break;
		default:
			break;
	}
	return;
}

