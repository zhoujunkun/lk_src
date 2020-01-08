/**
  ******************************************************************************
  * @file           : lk_button.c
  * @author         : zjk
  * @version        : v1.0
  * @date           : 2020-1-3
  * @brief          : 按键组合识别
  ******************************************************************************
  */
#include "lk_button.h"
#define BUTTON_TASK_TIM 10   //20ms调用
#define BUTTON_DELAY_TIM 2   //消抖时间
#define MAX_BUTTON_NUMS  16  //最大按键个数

typedef enum {btnIdle=0,button_1=0x01,button_2=0x02,button_3=0x04,button_4=0x04,button_5=0x10}btnEnu_t;





lk_buttonHandle_t *btnHead=NULL;
uint16_t btnRstData=0xffff;
uint8_t  btnNumbs=0; //按键数量
uint16_t keyData=0xffff;

uint16_t buttonStatu=0;

int i;
uint16_t trig=0,cont=0;
/**************************************************************************************************
 * @fn  void button_read(void)
 *
 * @brief   组合按键状态读取
 * input parameters
 *
 * @None
 * 
 * output parameters
 * @return  None.
 */
uint16_t button_read(void)
{
    lk_buttonHandle_t *target=NULL;
    uint8_t btnRead=0;
	  uint16_t read_data=0;
    keyData = btnRstData;
   for(target =btnHead,i=0;(target != NULL) && (target->read != NULL);target = target->next, i ++)
   {
       btnRead = target->read();
       keyData=keyData | (target->pressLogicLevel == 1 ? (!btnRead<<i) :(btnRead<<i) ) ;
   }
    read_data = keyData^0xFFFF;
    trig = read_data & (read_data ^ cont);
    cont = read_data; 
    return cont; 
}


/**************************************************************************************************
 * @fn  int button_register(lk_buttonHandle_t *btn)
 *
 * @brief  注册按键
 * input parameters
 *
 * @btn： 按键句柄
 * 
 * output parameters
 * @return  int
 */
int button_register(lk_buttonHandle_t *btn)
{

   if((btn==NULL)|(btnNumbs > MAX_BUTTON_NUMS))
   {
       return 0;
   }
   btn->next= btnHead;
   btnHead = btn;
   btnRstData<<=1;
   btnNumbs++;
   return 1;
}
typedef enum{runOnce=1,IDLE} runEnu_t;
runEnu_t runStatu=runOnce;
void button_process(void)
{  
	lk_buttonHandle_t *target=NULL;
 switch(runStatu)
 {
     case runOnce:
     {
        for(target =btnHead,i=0;(target != NULL) && (target->read != NULL);target = target->next, i ++)
        {
            target->cb();
        }
        runStatu = IDLE;
     }break;
     case IDLE:
     {
         
     }break;
 }

}

/**************************************************************************************************
 * @fn  void button_1ms_callBack(void)
 *
 * @brief  注册按键
 * input parameters
 *
 * @btn： 按键句柄
 * 
 * output parameters
 * @return  int
 */

void button_1ms_callBack(void)
{ 
  static int cnt=0,keyPressTime=0;
  static uint16_t btnStatu=0,btnBit=0,btnCns;
  cnt++;
  if(cnt >= BUTTON_TASK_TIM)
  {
      cnt =0;
    btnStatu =  button_read();
  }
  if(btnStatu)
    {
        btnCns++;
        if(btnCns >=BUTTON_DELAY_TIM) 
        {
            btnBit=button_read();
            buttonStatu = btnBit&btnStatu;
            button_process();
            btnCns = 0;
        }
    } 
		else buttonStatu=0;
}


