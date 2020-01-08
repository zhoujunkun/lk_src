//usr button
#include "lk_key.h"
#include "main.h"


lk_buttonHandle_t usrkey[KEY_MAX];

uint8_t key0_read(void)
{
   return HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin);
}

uint8_t key1_read(void)
{
   return HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
}

void key1_process(void)
{

}
void key0_process(void)
{
   
}

void lk_key_init(void)
{
   usrkey[KEY1].read = key1_read;
   usrkey[KEY1].pressLogicLevel = 0;
   usrkey[KEY1].cb = key1_process;
   button_register(&usrkey[KEY1]);
	
	 usrkey[KEY0].read = key0_read;
   usrkey[KEY0].pressLogicLevel = 0;
   usrkey[KEY0].cb = key0_process;
   button_register(&usrkey[KEY0]);
}


_btnUser_t lk_key_process(void)
{
//   if(getBtnStatu() == 0x01)  //key1
//   {
//       return KEY1;
//   }
//   if(getBtnStatu() == 0x02)  //key2
//   {
//       return KEY2; 
//   }
   return KEY_NONE;
}

