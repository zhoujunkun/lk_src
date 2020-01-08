#ifndef __IIC_H
#define __IIC_H
#include "lk_global.h"
#include "main.h"
#define iic_clk_high()          HAL_GPIO_WritePin(AW8695_CLK_GPIO_Port, AW8695_CLK_Pin, GPIO_PIN_SET)
#define iic_clk_low()           HAL_GPIO_WritePin(AW8695_CLK_GPIO_Port, AW8695_CLK_Pin, GPIO_PIN_RESET)
#define iic_data_high()         HAL_GPIO_WritePin(AW8695_SDA_GPIO_Port, AW8695_SDA_Pin, GPIO_PIN_SET)
#define iic_data_low()          HAL_GPIO_WritePin(AW8695_SDA_GPIO_Port, AW8695_SDA_Pin, GPIO_PIN_RESET)
#define iic_read_data()         HAL_GPIO_ReadPin(AW8695_SDA_GPIO_Port, AW8695_SDA_Pin)

typedef enum {      
    IIC_ACK,
    IIC_NACK,
}E_I2cAck;

 void iic_init(uint8_t addr);
  bool ii2_write(uint8_t regAddr,uint8_t *pBuf,uint8_t nBytes);
 bool ii2_read(uint8_t regAddr,uint8_t *pBuf,uint8_t nBytes);

#endif