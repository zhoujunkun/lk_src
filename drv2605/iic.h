#ifndef __IIC_H
#define __IIC_H
#include "stdint.h"

#define iic_clk_high        
#define iic_clk_low         
#define iic_data_high       
#define iic_data_low        
#define iic_read_data       

typedef enum {      
    IIC_ACK,
    IIC_NACK,
}E_I2cAck;

extern void iic_init(uint8_t addr);
extern  bool ii2_write(uint8_t regAddr,uint8_t *pBuf,uint8_t nBytes);
extern bool ii2_read(uint8_t regAddr,uint8_t *pBuf,uint8_t nBytes);

#endif