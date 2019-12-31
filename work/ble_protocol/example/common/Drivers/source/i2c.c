/*****************************************************************************
*   I2C.c:  Sourse file for I2C comunication
*		ver 1.1 Modify I2C interrupt handler for write NACK
******************************************************************************/

#include "CMSDK_CM0.h"
#include "sys.h"
#include "i2c.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
** Function name:		I2C initial
**
** Descriptions:		I2C initial function
**
** parameters:      Mode: 1---Master 0---Slave
**                  ClockRate: unit in KHz
**                  SlaveAddress: Slave address in slave mode
**                  I2CInterrupt: 1---Enable I2C Interrupt 0---Disable I2C Interrupt
**
** Returned value:	None
** 
*****************************************************************************/
void I2C_Init(uint8_t Mode, uint32_t ClockRate, uint32_t SlaveAddress)
{
	/*---  Enable I2C clock and de-assert reset  ---*/
    SYSCON->PRESETCTRL_b.I2C_RST_N |= 1;
    SYSCON->SYSAHBCLKCTRL_b.I2C_CLK |= 1;

	/*---  I2C I/O config  ---*/    
//    IOCON->PIO1_10 = 0x01 + (1<<10);  // I2C SCL I/O config, PIO1_10-->SCL
//    IOCON->PIO1_11 = 0x01 + (1<<10);  // I2C SDA I/O config, PIO1_11-->SDA
    
	/*--- Clear flags ---*/
	I2C->CONCLR = 0xFF;   

	/*--- Set Clock rate ---*/
	I2C->SCLH_b.SCLH= SystemCoreClock/ClockRate;
	I2C->SCLL_b.SCLL = SystemCoreClock/ClockRate;

	if (!Mode)
	{
		I2C->ADR0 = SlaveAddress; // Slave address
	}
	    
	if (Mode)
	{
		
		I2C->CONSET = 0x42; // Master mode
	} 
	else
	{
		I2C->CONSET = 0x40; // Slave mode
	}

	/* Enable the I2C Interrupt */

	NVIC_EnableIRQ(I2C_IRQn);
}


/*****************************************************************************
** Function name:		I2C_GetI2CStatus
**
** Descriptions:		Get I2C Status
**
** parameters:      None
**
** Returned value:	None
** 
*****************************************************************************/
uint8_t I2C_GetI2CStatus( void )
{
	return (I2C->STAT);
}

/*****************************************************************************
** Function name:		I2C_ReadFlag
**
** Descriptions:		Read I2C Flag
**
** parameters:      Read bit
**
** Returned value:	None
** 
*****************************************************************************/
uint8_t I2C_ReadFlag( uint8_t I2C_CONSET )
{
	return(I2C->CONSET & I2C_CONSET);      /* retuen flag */
}

/*****************************************************************************
** Function name:		I2C_SetFlag
**
** Descriptions:		Set I2C Flag
**
** parameters:      Set bit
**
** Returned value:	None
** 
*****************************************************************************/
void I2C_SetFlag( uint8_t I2C_CONSET )
{
	I2C->CONSET = I2C_CONSET;      /* Set flag */
}

/*****************************************************************************
** Function name:		I2C_ClearFlag
**
** Descriptions:		Clear I2C Flag
**
** parameters:      Clear bit
**
** Returned value:	None
** 
*****************************************************************************/
void I2C_ClearFlag( uint8_t I2C_CONCLR )
{
	I2C->CONCLR = I2C_CONCLR;      /* Clear flag */
}

/*****************************************************************************
** Function name:		I2C_SendByte
**
** Descriptions:		Send Byte
**
** parameters:      Send data
**
** Returned value:	None
** 
*****************************************************************************/
void I2C_SendByte( uint8_t DataByte )
{
	I2C->DAT = DataByte; 
}


/*****************************************************************************
** Function name:		I2C_GetByte
**
** Descriptions:		Get I2C Byte
**
** parameters:      None
**
** Returned value:	I2C Data
** 
*****************************************************************************/

uint8_t I2C_GetByte( void )
{
	return(I2C->DAT);
}

/*****************************************************************************
* Function name:    I2C_IRQHandler
*
* Descriptions:     Use status to control process
*
* parameters:       None
* Returned value:   None
* 
*****************************************************************************/
void I2C_IRQHandler(void) 
{
	uint8_t StatValue;
	
	StatValue = I2C_GetI2CStatus();
	// 0x4B--SLA+W transmitted but no ACK 
	// 0x54--Data byte in DAT transmitted;no ACK received.
	if 	((StatValue == 0x4B) || (StatValue == 0x54))
	{
			I2C_SetFlag(I2C_CONSET_STO);				// Set Stop flag
			I2CMasterState = I2C_NACK;//I2C_OK;
			I2C_ClearFlag(I2C_CONCLR_SIC| I2C_CONCLR_STAC |I2C_CONCLR_TXRXC );
			return;	
	}
	StatValue &= ~(0x40); 
	switch ( StatValue )
	{
		case I2C_M_TX_START:				/* 0x01: A Start condition is issued. */
			if (Restart == 1)
			{
				//RX SLAD I2C_M_TX_RESTART:
				Restart = 0;
				RdIndex = 0;
				I2C_SendByte(I2CMasterBuffer[0] + 1); 			/* Send SLA with R bit set */
				WrIndex++;
				I2C_ClearFlag(I2C_CONCLR_SIC | I2C_CONCLR_STAC |I2C_CONCLR_TXRXC);
			}
			else
			{
				// Start master transmit process
				WrIndex = 0;
				RdIndex = 0;
				I2C_SetFlag(I2C_CONSET_TXRX); 		 // Set tx flag
				I2C_SendByte(I2CMasterBuffer[0]);  // Transmit address first 
				WrIndex++;
				I2C_ClearFlag(I2C_CONCLR_SIC | I2C_CONCLR_STAC);
			}
			break;
		
		case I2C_M_TX_RESTART:			/* 0x10: A repeated started is issued */
			RdIndex = 0;
			I2C_SendByte(I2CMasterBuffer[WrIndex++]); 			/* Send SLA with R bit set */
			I2C_ClearFlag(I2C_CONCLR_SIC | I2C_CONCLR_STAC);
			break;
		
		case I2C_M_TX_SLAW_ACK:			/* 0x0B: Regardless, it's a ACK */
			if ((I2C->CONSET & 0x1)==0x1) // Transmit
			{
				if (I2CWriteLength == 1)
				{
					I2C_SetFlag(I2C_CONSET_STO);      			// Set Stop flag
					I2CMasterState = I2C_NO_DATA;
				}
				else
				{
					I2C_SendByte(I2CMasterBuffer[WrIndex++]); // Transmit
				}
				I2C_ClearFlag(I2C_CONCLR_SIC);
			}
			else
			{
				if ( (RdIndex + 1) < I2CReadLength ) // Read form slave device
				{
					/* Will go to State 0x50 */
					I2C_SetFlag(I2C_CONSET_AA);					/* assert ACK after data is received */
				}
				else
				{
					/* Last byte will no ack, Will go to State 0x58 */
					I2C_ClearFlag(I2C_CONCLR_AAC);				/* assert NACK after data is received */
				}
				I2C_ClearFlag(I2C_CONCLR_SIC | I2C_CONCLR_STAC);
			}
			break;	
		
		case I2C_M_TX_DAT_ACK:			/* 0x14: Data byte has been transmitted, regardless ACK or NACK */
			if ( WrIndex < I2CWriteLength )
			{   
				I2C_SendByte(I2CMasterBuffer[WrIndex++]);	
			}
			else		/* this should be the last one */
			{
				if ( I2CReadLength != 0 )	  
				{
					Restart = 0;
					RdIndex = 0;
					if(Re_Start)
					{
						I2C_SendByte(I2CMasterBuffer[0] + 1); 			/* Send SLA with R bit set */
						I2C_SetFlag(I2C_CONSET_STA);				/* Set Repeated-start flag */
					}

					else
					{
						I2C_SendByte(I2CMasterBuffer[0] + 1); 			/* Send SLA with R bit set */
					}

					I2C_ClearFlag(I2C_CONCLR_SIC  |I2C_CONCLR_TXRXC);
					break;
				}
				else
				{
					I2C_SetFlag(I2C_CONSET_STO);				/* Set Stop flag */
					I2CMasterState = I2C_OK;
				}
			}
			I2C_ClearFlag(I2C_CONCLR_SIC);
			break;			
		
		case I2C_M_RX_DAT_ACK:			/* 0x1D, 0x5D: Data byte has been received, regardless following ACK or NACK */
			I2CSlaveBuffer[RdIndex++] = I2C_GetByte();
			if ( (RdIndex + 1) < I2CReadLength )
			{   
				I2C_SetFlag(I2C_CONSET_AA);					/* assert ACK after data is received */
				I2C_ClearFlag(I2C_CONCLR_SIC);
			}
			else
			{
				if ((I2C->CONSET &0x04)==0x04)
					I2C_ClearFlag(I2C_CONCLR_AAC | I2C_CONCLR_SIC);
				else 
			   {
					 I2CMasterState = I2C_OK;
					 I2C_SetFlag(I2C_CONSET_STO);	/* assert NACK on last byte */
					 I2C_ClearFlag(I2C_CONCLR_SIC);
				 }
			}
			break;
			
		default:
			I2CMasterState = I2C_ARBITRATION_LOST;
			I2C_ClearFlag(I2C_CONCLR_SIC);	
			break;
	}
	return;
}
/*****************************************************************************
* Function name:    I2C_WriteByte
*
* Descriptions:     Write byte to slave chip
*
* parameters:       SlaveAddress: Slave chip address
					SubAddr:  Slave chip register address
					Value :   Value write to slave chip register address
* Returned value:   None
* 
*****************************************************************************/

uint8_t I2C_WriteByte(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t Value)
{
	uint8_t i;
	I2CMasterBuffer[0] = SlaveAddress; // Slave chip address
	I2CMasterBuffer[1] = SubAddr;	   // Chip register address
	I2CMasterBuffer[2] = Value;
	
	Re_Start = 0;

	I2CReadLength = 0; // Read length
	I2CWriteLength = 3;	// Write length


	I2C_SetFlag(I2C_CONSET_STA); //Set start signal

	I2CMasterState = I2C_IDLE;
	while(( I2CMasterState != I2C_OK )&&( I2CMasterState != I2C_NACK )); // Wait for finished

	i = 0xFF;
	while(i--);
	return I2CMasterState;
}
/*****************************************************************************
* Function name:    I2C_Write_Busy_Polling
*
* Descriptions:     Poll I2C slave availbilty for I2C write
*
* parameters:       SlaveAddress: Slave chip address
*
* Returned value:   I2C_NO_DATA for ACK and I2C_NACK for NO ACK
* 
*****************************************************************************/
uint8_t I2C_Write_Busy_Polling(uint8_t SlaveAddress)
{
	uint8_t i;
	I2CMasterBuffer[0] = SlaveAddress; // Slave chip address
	
	Re_Start = 0;

	I2CReadLength = 0; // Read length
	I2CWriteLength = 1;	// Write length


	I2C_SetFlag(I2C_CONSET_STA); //Set start signal

	I2CMasterState = I2C_IDLE;
	while(( I2CMasterState != I2C_NO_DATA )&&( I2CMasterState != I2C_NACK )); // Wait for finished

	i = 0xFF;
	while(i--);
	return I2CMasterState;
}


/*****************************************************************************
* Function name:    I2C_WriteArray
*
* Descriptions:     Write array value to slave chip
*
* parameters:       SlaveAddress: Slave chip address
					SubAddr:  Slave chip register address
					Buff: 	  Write value pointer
					Length:   Length to write
* Returned value:   None
* 
*****************************************************************************/
uint8_t I2C_WriteArray(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t *Buff, uint8_t Length)
{
	uint8_t i;
	I2CMasterBuffer[0] = SlaveAddress; // Slave chip address
	I2CMasterBuffer[1] = SubAddr;

	for( i = 0; i < Length; i++ )
	{
	 	I2CMasterBuffer[i+2] = *( Buff + i ); // Write value to slave chip register  		
	}
	
	Re_Start = 0;
	I2CReadLength = 0;
	I2CWriteLength = Length+2; // Write Length
	I2C_SetFlag(I2C_CONSET_STA); // Start

	I2CMasterState = I2C_IDLE;
	while(( I2CMasterState != I2C_OK )&&( I2CMasterState != I2C_NACK ));// Wait for finished

	i = 0xFF;
	while(i--);
	
	return I2CMasterState;
}

/*****************************************************************************
* Function name:    I2C_ReadByte
*
* Descriptions:     Read byte from slave chip
*
* parameters:       SlaveAddress: Slave chip address
					SubAddr:  Slave chip register address
* Returned value:   return read value
* 
*****************************************************************************/
uint8_t I2C_ReadByte(uint8_t SlaveAddress, uint8_t SubAddr)
{
	uint8_t i;
	I2CMasterBuffer[0] = SlaveAddress; // Slave chip address
	I2CMasterBuffer[1] = SubAddr;

	I2CWriteLength = 2;
	I2CReadLength = 1;
	
	Re_Start = 1;
	I2C_SetFlag(I2C_CONSET_STA); // Start

	I2CMasterState = I2C_IDLE;
	while(( I2CMasterState != I2C_OK )&&( I2CMasterState != I2C_NACK )); // Wait for finished

	i = 0xFF;
	while(i--);
	
	return(I2CSlaveBuffer[0]);
}

/*****************************************************************************
* Function name:    I2C_ReadArray
*
* Descriptions:     Read array value from slave chip
*
* parameters:       SlaveAddress: Slave chip address
					SubAddr:  Slave chip register address
					Length:   Length for reading
					Buffer:   Read value pointer
* Returned value:   None
* 
*****************************************************************************/
void I2C_ReadArray(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t Lenth, uint8_t *Buffer)
{
	uint8_t i;
	I2CMasterBuffer[0] = SlaveAddress; // Slave chip address
	I2CMasterBuffer[1] = SubAddr;

	I2CWriteLength = 2;
	I2CReadLength = Lenth;
	
	Re_Start = 1;
	I2C_SetFlag(I2C_CONSET_STA); // Start

	I2CMasterState = I2C_IDLE;
	while( I2CMasterState != I2C_OK ); // Wait for finished
	
	for(i = 0; i < Lenth; i++)
	{
		*(Buffer+i) = I2CSlaveBuffer[i]; // Get pointer value
	}

	i = 0xFF;
	while(i--);
}


/* --------------------------------- End Of File ------------------------------ */
