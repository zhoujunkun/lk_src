/*****************************************************************************
*   gpio.h:  Header file for gpio.c
*		ver 1.0
******************************************************************************/
#ifndef __GPIO_H 
#define __GPIO_H

#include "CMSDK_CM0.h"

void GPIO_ConfigPinsAsInput(PA_Type *port, uint16_t pins);
void GPIO_ConfigPinsAsOutput(PA_Type*port, uint16_t pins);
void GPIO_SetPin (PA_Type*port, uint16_t pin);
void GPIO_ResetPin (PA_Type*port, uint16_t pin);
void GPIO_InvertOutPin(PA_Type*port, uint16_t pin);
uint8_t GPIO_GetPinState(PA_Type*port, uint16_t pin);
uint16_t GPIO_GetPortState(PA_Type*port);
void GPIO_SetPortMask(PA_Type*port, uint16_t pins);
void GPIO_ResetPortMask(PA_Type*port, uint16_t pins);
uint16_t GPIO_ReadPort(PA_Type*port);
void GPIO_WritePort(PA_Type*port, uint16_t data);
void GPIO_EnableInt(PA_Type*port, uint16_t pin, uint8_t triggeredge);


#endif /* end __GPIO_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
