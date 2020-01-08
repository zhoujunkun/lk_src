/**
  ******************************************************************************
  * @file           : lk_tm8211_ops.c
  * @author         : zjk
  * @version        : v1.0
  * @date           : 2020-1-3
  * @brief          : tm8211 硬件接口用户编写
  ******************************************************************************
  */

#include "lk_tm8211_ops.h"

#define tm8211_ws_high()     HAL_GPIO_WritePin(GPIOA, TM8211_WS_Pin, GPIO_PIN_SET);
#define tm8211_ws_low()      HAL_GPIO_WritePin(GPIOA, TM8211_WS_Pin, GPIO_PIN_RESET);

#define tm8211_din_high()    HAL_GPIO_WritePin(GPIOA, TM8211_DIN_Pin, GPIO_PIN_SET);
#define tm8211_din_low()     HAL_GPIO_WritePin(GPIOA, TM8211_DIN_Pin, GPIO_PIN_RESET);

#define tm8211_bck_high()    HAL_GPIO_WritePin(GPIOA, TM8211_BCK_Pin, GPIO_PIN_SET);
#define tm8211_bck_low()     HAL_GPIO_WritePin(GPIOA, TM8211_BCK_Pin, GPIO_PIN_RESET);

void tms8211_Ws(tmIoStatuEnum_t statu)
{
   switch (statu)
   {
   case ioLow:
       {
           tm8211_ws_low();
       }break;
   case ioHigh:
       {
					 tm8211_ws_high()
       }break;
   }
}



void tms8211_Bck(tmIoStatuEnum_t statu)
{
    switch (statu)
   {
   case ioLow:
       {
           tm8211_bck_low();
       }break;
   case ioHigh:
       {
           tm8211_bck_high();
       }break;
   }   
}




void tms8211_Din(tmIoStatuEnum_t statu)
{
     switch (statu)
   {
   case ioLow:
       {
           tm8211_din_low();
       }break;
   case ioHigh:
       {
           tm8211_din_high();
       }break;
   }  
}







//tm8211 ops
lk_tm8211_ops_t tm8211_ops =
{
    .Ws = tms8211_Ws,
    .Bck = tms8211_Bck,
    .Din = tms8211_Din,
};