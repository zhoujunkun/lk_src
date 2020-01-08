/**
  ******************************************************************************
  * @file           : lk_tm8211.c
  * @author         : zjk
  * @version        : v1.0
  * @date           : 2020-1-3
  * @brief          : tm8211 DAC 芯片驱动代码
  ******************************************************************************
  */

#include "lk_tm8211.h"

void tm8211_write(tm8211_data_t *L,tm8211_data_t *R);

//======================================================
/**************************************************************************************************
 * @fn  tm8211_register(int temp)
 *
 * @brief   tm8211 写入寄存器数据
 * input parameters
 *
 * @temp: 含有符号位的数据
 * output parameters
 * @return      None.
 */
static void tm8211_register(int temp)
{    
  	tm8211_ops.Bck(ioLow);
	  tm8211_ops.Din(ioLow);
    for(int i=0;i<16;i++)
    {
		tm8211_ops.Bck(ioLow);
        if(temp&0x8000)
        {
						tm8211_ops.Din(ioHigh);
        }
        else 
				{
					tm8211_ops.Din(ioLow);
				}
        tm8211_ops.Bck(ioHigh);
        temp<<=1;
    }
}

void tm8211_init(void)
{
	 tm8211_ops.Ws(ioLow);
}
int contL=0,contR=0,miniMum=-32767;
/**************************************************************************************************
 * @fn   void tm8211_write(tm8211_data_t *L,tm8211_data_t *R)
 *
 * @brief   tm8211 写入结构数据函数
 * input parameters
 *
 * @*L: 写入LCH结构数据指针
 * @*R: 写入RCH结构数据指针
 * output parameters
 * @return      None.
 */
void tm8211_write(tm8211_data_t *L,tm8211_data_t *R)
{
	 //LCH输出
	if(L !=NULL)
	{
	 tm8211_ops.Ws(ioHigh);				
	 tm8211_register(L->buf[contL++]);
	 if(contL == L->size) contL=0;
  }
	else
	{
	   tm8211_ops.Ws(ioHigh);
     tm8211_register(miniMum);		
	}
	 //RCH输出
	if(R !=NULL)
	{
	 tm8211_ops.Ws(ioLow);				
	 tm8211_register(R->buf[contR++]);
	 if(contR == R->size) contR=0;	
	}
	else
	{
	   tm8211_ops.Ws(ioLow);
	   tm8211_register(miniMum);
	}
}

/**************************************************************************************************
 * @fn  void tm8211_writeSingle(int L,int R)
 *
 * @brief   tm8211 写入单个数据函数
 * input parameters
 *
 * @L: 写入LCH数据
 * @R: 写入RCH数据
 * output parameters
 * @return      None.
 */
void tm8211_writeSingle(int L,int R)
{
	 //LCH输出
	 tm8211_ops.Ws(ioHigh);				
	 tm8211_register(L);

	 //RCH输出
	 tm8211_ops.Ws(ioLow);				
	 tm8211_register(R);	
}

