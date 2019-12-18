#include "iic.h"



/* ------------------------------------------------------------------------------------------------
 *                                       Local Variables
 * ------------------------------------------------------------------------------------------------
 */
static uint8_t i2cAddr;  // Target Slave address pre-shifted up by one leaving RD/WRn LSB as zero.

void iic_init(uint8_t addr)
{
    i2cAddr = addr << 1;
}



/***********************************************
*   I2C delay
************************************************/
void iic_delay(void)
{
    volatile uint8_t  nX;    //一定要加 volatile 不然会被优化掉
    nX = 20;
    while (nX)
    {
        nX--;
    }
}


/***********************************************
*   I2C start
************************************************/
void iic_start(void)
{
    iic_data_high();
    iic_clk_high();
    iic_delay();
    iic_data_low();
    iic_delay();
    iic_clk_low();

}

/***********************************************
*   I2C stop
************************************************/
void iic_stop(void)
{
    iic_data_low();
    iic_clk_high();
    iic_delay();
    iic_data_high();
    iic_delay();
}


/***********************************************
*   I2C wait ack
************************************************/
bool iic_wait_ack(void)
{
    bool flag;
    u16 TimeOut;

    iic_data_high();
    iic_delay();
    iic_clk_high();
    iic_delay();
    flag=FALSE;
    TimeOut=20000;
    do
    {
        if (!(iic_read_data()))       //变低了?
        {
            flag = TRUE;
            break;
        }
    }while (--TimeOut);
    iic_clk_low();
    iic_delay();
    
    return flag;
}


/***********************************************
*   I2C ack
************************************************/
void iic_ack(E_I2cAck ack)
{
    if(ack)
    {
        iic_data_high(); //NACK
    }
    else
    {
        iic_data_low(); //ACK
    }
    iic_delay();
    iic_clk_high();
    iic_delay();
    iic_clk_low();
    iic_delay();
}


/***********************************************
*   I2C send one byte
************************************************/
bool iic_send_8bits(uint8_t byte)
{
    u8 i;
    bool flag;
    flag=FALSE;
    i = 8;
    do
    {   
        if (byte&0x80){
            iic_data_high();
        }else{
            iic_data_low();
        }
        byte<<=1;
        iic_delay();
        iic_clk_high(); /*SCL=1,SDA保持稳定，SCL=0,SDA改变 */
        iic_delay();
        iic_clk_low();
    }while(--i);
    /* check ack */
    //I2C_DATA_INPUT;
    flag = I2cWaitAck();
    //I2C_DATA_OUTPUT;
    return flag;
}


/***********************************************
*   I2C receive one byte
************************************************/
u8 iic_rev_8bits(E_I2cAck ack)
{
    u8 i,byte;
    
    //I2C_DATA_INPUT;
    iic_data_high();
    i = 8;byte = 0;
    do
    {
        iic_clk_high(); /*SCL=1,SDA保持稳定，SCL=0,SDA改变 */
        iic_delay();
        byte <<= 1;
        if(iic_read_data())
        {
            byte |= 0x01;
        }
        iic_clk_low();
        iic_delay();
    }while(--i);
    /* ack & nack */
    //I2C_DATA_OUTPUT;
    iic_ack(ack);
    
    return byte;
}


/**************************************************************************************************
* @fn          ii2_write
* @brief       写入寄存器地址多个数据
*
* @param       addr - which register to write
* @param       pBuf - pointer to buffer containing data to be written
* @param       nBytes - number of bytes to write
*
* @return      TRUE if successful write 
*/
 bool ii2_write(uint8_t regAddr,uint8_t *pBuf,uint8_t nBytes)
{
    bool flag;
    
    iic_start();     //开始位
    if(iic_send_8bits(i2cAddr|0)) //从机地址
    {
        if(iic_send_8bits(regAddr))
        {
            flag = TRUE;
            for (int i = 0; i < nBytes; i++)
            {
                if(!iic_send_8bits(pBuf[i]))       //发送数据
                {
                    flag = FALSE;
                    break;
                }  
            }
            
        }
    }
    iic_stop();
    
    return flag;
}



/**************************************************************************************************
* @fn          ii2_read
* @brief      读寄存器地址多个数据
*
* @param       addr - which register to write
* @param       pBuf - pointer to buffer containing data to be written
* @param       nBytes - number of bytes to write
*
* @return      TRUE if successful write 
*/
 bool ii2_read(uint8_t regAddr,uint8_t *pBuf,uint8_t nBytes)
{
    bool flag = FALSE;

    iic_start();     //开始位
    if (iic_send_8bits(i2cAddr))      //发送地址
    {
        if (iic_send_8bits(regAddr)) //command
        {
            iic_start();
            if(iic_send_8bits(i2cAddr|0x01))  //发送读命令
            {
                while(--nBytes)
                {
                    *pBuf++ = iic_rev_8bits(IIC_ACK);
                }
                *pBuf = iic_rev_8bits(IIC_NACK);
                flag = TRUE;
            }
        }
    }
    iic_stop();
    return flag;
}

