
/**
  ******************************************************************************
  * @file           : lk_433m.c
  * @author         : zjk
  * @version        : v1.1
  * 
  * @date           : 
  *                   2020-1-8    v1.1   
  * @brief          : 433无线遥控器解析驱动
  ******************************************************************************
  */
#include "lk_433m.h"

#include <stdlib.h>
#define REMOTE433_HEAD   11400 //头时间长度us
#define REMOTE433_HIGH   3000 //高电平时间us
#define REMOTE433_LOW    1000 //低电平时间us


#define HEAD_ALLOW_OFFSET   900 //帧头偏差
#define DATA_ALLOW_OFFSET   200 //数据偏差

uint16_t revData=0,revSize=0,oldRevData=0;    //接收到的数据
remoteCb remoteFunc[remoteMax]={NULL}; 
remotePressEnum_t pressKey = remotePressNone;
#define ERRO_433M   0  

typedef enum {remoteIdle=0,remoteData,remoteEnd}remoteStatuEnu_t;
remoteStatuEnu_t remoteStatu = remoteIdle;
bool ifComplete=false;
int my433M_anasys(uint16_t value)
{
  switch (remoteStatu)
  {
    case remoteIdle:
    { 

				if(abs(value-REMOTE433_HEAD) <= HEAD_ALLOW_OFFSET)
				{
						remoteStatu = remoteData;
				}
				else  remoteStatu = remoteIdle;	

    }break;
    case remoteData:
    {

      revData<<=1;
      if(abs(value-REMOTE433_HIGH) <= DATA_ALLOW_OFFSET)
      {
          revData = revData|0x01;
          revSize++;
      }
      else if(abs(value-REMOTE433_LOW) <= DATA_ALLOW_OFFSET)
      {
         revData = revData|0x00;
         revSize++;
      }
      else
      {
        remoteStatu = remoteIdle;
        revSize =0;
      }
      if(revSize ==16)
      {
        remoteStatu = remoteEnd; 
      }

    }break;
   case remoteEnd:
   {
      remoteStatu = remoteIdle;
      revSize =0;
      if(abs(value-REMOTE433_HEAD) <= HEAD_ALLOW_OFFSET)
      {
        if(oldRevData != revData)
				{
					oldRevData = revData;
           if((revData>0x69C0)&&(revData<=0x69DF))  
            {
              pressKey = pressMenu;
             if(remoteFunc[pressMenu] != NULL) remoteFunc[pressMenu](revData);
            }
           if((revData>0x69A0)&&(revData<=0x69BF))  
           {
             pressKey = pressLeft; 
            if(remoteFunc[pressLeft] != NULL) remoteFunc[pressLeft](revData);
           }        
           if((revData>0x6960)&&(revData<=0x697F))  
           {
             pressKey = pressRight;
            if(remoteFunc[pressRight] != NULL) remoteFunc[pressRight](revData);
           }
           if((revData>0x6920)&&(revData<=0x693F)) 
            {
              pressKey = pressUp;
             if(remoteFunc[pressUp] != NULL) remoteFunc[pressUp](revData);
            }          
           if((revData>0x6940)&&(revData<=0x695F))  
           {
             pressKey = pressDown;
             if(remoteFunc[pressDown] != NULL) remoteFunc[pressDown](revData);
           }  
				 }					 
			}
   }break;
  }

}









/**************************************************************************************************
 * @fn  void lk_remote_init(remoteCb *up,remoteCb *down,remoteCb *left,remoteCb *right,remoteCb *menu)
 *
 * @brief   433无线遥控初始化回调函数
 * input parameters
 *
 *@remoteCb up:     遥控器上键按压回调函数
 *@remoteCb down:   遥控器下键按压回调函数
 *@remoteCb left:   遥控器左键按压回调函数
 *@remoteCb right:  遥控器右键按压回调函数
 *@remoteCb menu:    遥控器菜单按压回调函数
 *
 * None
 * output parameters
 *
 * @return      None
 */
void lk_remote_init(remoteCb up,remoteCb down,remoteCb left,remoteCb right,remoteCb menu)
{
  remoteFunc[pressUp] = up;
  remoteFunc[pressLeft] = left;
  remoteFunc[pressRight] = right;
  remoteFunc[pressDown] = down; 
  remoteFunc[pressMenu] = menu;        
}