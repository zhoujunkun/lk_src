/*****************************************************************************
*   i2c.h:  Header file for i2c.c
*		ver 1.0
******************************************************************************/
#ifndef __I2C_H
#define __I2C_H
#include "CMSDK_CM0.h"

//I2C mode

//I2C status	
#define I2C_IDLE				    0
#define I2C_STARTED				    1
#define I2C_RESTARTED			    2
#define I2C_REPEATED_START			3
#define DATA_ACK				    4
#define DATA_NACK				    5
#define I2C_BUSY				    6
#define I2C_NO_DATA				    7
#define I2C_NACK_ON_ADDRESS			8
#define I2C_NACK_ON_DATA		 	9
#define I2C_ARBITRATION_LOST  		10
#define I2C_TIME_OUT			    11
#define I2C_OK					    12
#define I2C_NACK		 	13

/* Private variables ---------------------------------------------------------*/
static uint8_t I2CMasterBuffer[8];
static uint8_t I2CSlaveBuffer[8];
static uint8_t I2CMasterState = I2C_IDLE;
static uint32_t I2CReadLength, I2CWriteLength;
static uint32_t RdIndex = 0;
static uint32_t WrIndex = 0;
static uint32_t Restart = 0;
static uint8_t Re_Start;

#define I2C_CONSET_TXRX			((uint8_t)(0x01))	/*!< Transmit/Receive flag */
#define I2C_CONSET_MASL			((uint8_t)(0x02))	/*!< Master/Slave flag */
#define I2C_CONSET_AA			((uint8_t)(0x04))	/*!< Assert acknowledge flag */
#define I2C_CONSET_SI			((uint8_t)(0x08)) 	/*!< I2C interrupt flag */
#define I2C_CONSET_STO			((uint8_t)(0x10)) 	/*!< STOP flag */
#define I2C_CONSET_STA			((uint8_t)(0x20)) 	/*!< START flag */
#define I2C_CONSET_I2EN			((uint8_t)(0x40)) 	/*!< I2C interface enable */
#define PARAM_I2C_CONSET(I2C_CONSET) 		((((I2C_CONSET) & (uint8_t)0x83) == 0x00) && ((I2C_CONSET) != 0x00))


#define I2C_CONCLR_TXRXC			((uint8_t)(0x01))  	/*!< Transmit/Receive Clear bit */
#define I2C_CONCLR_MASLC			((uint8_t)(0x02))	/*!< Master/Slave Clear bit */
#define I2C_CONCLR_AAC			((uint8_t)(0x04))  	/*!< Assert acknowledge Clear bit */
#define I2C_CONCLR_SIC			((uint8_t)(0x08))	/*!< I2C interrupt Clear bit */
#define I2C_CONCLR_STAC			((uint8_t)(0x20))	/*!< START flag Clear bit */
#define I2C_CONCLR_I2ENC			((uint8_t)(0x40))	/*!< I2C interface Disable bit */
#define PARAM_I2C_CONCLR(I2C_CONCLR) 		((((I2C_CONCLR) & (uint8_t)0x93) == 0x00) && ((I2C_CONCLR) != 0x00))
						

#define I2C_M_TX_START				0x01		/*!< A start condition has been transmitted */
#define I2C_M_TX_RESTART			0x10	 	/*!< A repeat start condition has been transmitted */
#define I2C_M_TX_SLAW_ACK			0x0B	 	/*!< SLA+W has been transmitted, ACK has been received */
#define I2C_M_TX_SLAW_NACK		0x4B	  /*!< SLA+W has been transmitted, NACK has been received */
#define I2C_M_TX_DAT_ACK			0x14		/*!< Data has been transmitted, ACK has been received */
#define I2C_M_TX_ARB_LOST			0x54	 	/*!< Arbitration lost in SLA+R/W or Data bytes */
 

#define I2C_M_RX_START				0x01		/*!< A start condition has been transmitted */
#define I2C_M_RX_RESTART			0x22		/*!< A repeat start condition has been transmitted */
#define I2C_M_RX_SLAR_ACK			0x0B		/*!< SLA+R has been transmitted, ACK has been received */
#define I2C_M_RX_SLAR_NACK		0x4B 		/*!< SLA+R has been transmitted, NACK has been received */
#define I2C_M_RX_DAT_ACK			0x1D	  	/*!< Data has been received, ACK has been returned */
#define I2C_M_RX_DAT_NACK			0x5D	 	/*!< Data has been received, NACK has been return */  

uint8_t I2C_GetI2CStatus( void );
uint8_t I2C_ReadFlag( uint8_t I2C_CONSET );
void I2C_SetFlag( uint8_t I2C_CONSET );
void I2C_ClearFlag( uint8_t CONCLR );
void I2C_SendByte( uint8_t DataByte );
uint8_t I2C_GetByte( void );

void I2C_Init(uint8_t Mode, uint32_t ClockRate, uint32_t SlaveAddress);
//void I2CMasterTransmitReceiver(uint8_t *MasterBuffer, uint8_t WriteLength,uint8_t ReadLength);		



void I2C_ReadArray(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t Lenth, uint8_t *Buffer);
uint8_t I2C_WriteByte(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t Value);
uint8_t I2C_WriteArray(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t *Buff, uint8_t Length);
uint8_t I2C_ReadByte(uint8_t SlaveAddress, uint8_t SubAddr);
uint8_t I2C_Write_Busy_Polling(uint8_t SlaveAddress);
#endif 

/* --------------------------------- End Of File ------------------------------ */

