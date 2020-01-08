/**
  ******************************************************************************
  * @file           : lk_ble.c
  * @author         : zjk
  * @version        : v1.1
  * 
  * @date           : 2019-12-23  v1.0   第一版
  *                   2020-1-8    v1.1   
  * @brief          : 通信协议解析实现
  ******************************************************************************
  */
#include "lk_ble.h"

rxData_t   rxData;   //接收数据缓存
rxFrame_t frameBuf;   //帧缓存
SqQueue bleQueue;  //ble缓存
typedef enum {frame_head=0,frame_length,frame_func,frame_data,frame_checkSum}frame_enum_t;

frame_enum_t frame_enum=frame_head;

uint8_t fist_check=0;
#define CHECK_SUM(now,last)  (now^last)  //dat1^dat2^dat3^dat4....

#define CHECK_STRING(now,last) (now^last)



char checkConnected[] ={BLE_CONNECTED};
char checkDisConnected[] ={BLE_DISCONNECTED};

uint8_t nowCheckStrConect = 'C',strCnt;
uint8_t nowCheckStrDisConect = 'D',strDisCnt;


void check_connectdStatu(uint8_t data)
{
#if 0
 if (CHECK_STRING(data,nowCheckStrConect) == 0)
	{
	     strCnt++;
      nowCheckStrConect = checkConnected[strCnt];
	    if(strCnt == (sizeof(checkConnected)-1) )
       {
			   ble_handle.ifBleConnected= true; 
				 ble_handle.ifBleDisConnected=false;
				 strCnt = 0;
				 nowCheckStrConect = checkConnected[0];
				 strDisCnt = 0;
				 nowCheckStrDisConect = checkDisConnected[0];
			 }
	}else 
	{
		strCnt =0;
	  nowCheckStrConect = checkConnected[0];
	}

 if (CHECK_STRING(data,nowCheckStrDisConect) == 0)
	{
	     strDisCnt++;
      nowCheckStrDisConect = checkDisConnected[ strDisCnt];
	    if(strDisCnt == (sizeof(checkDisConnected)-1)) 
       {
           ble_handle.ifBleConnected = false;
			    ble_handle.ifBleDisConnected= true; 
				 strDisCnt = 0;
				 nowCheckStrDisConect = checkDisConnected[0];
				 strCnt = 0;
				 nowCheckStrConect = checkConnected[0];
			 }
	}else 
	{
		strDisCnt =0;
	  nowCheckStrDisConect = checkDisConnected[0];
	}

#endif
}



uint8_t strSize =0;

uint8_t lk_ble_checkSum(uint8_t data)
{   
	 static uint8_t cnt=0,rxDatCnt=0,checksum=0,lastData=0;	 
    uint16_t head=0xABBC;
    
    rxData.buf[rxDatCnt++] = data;
    cnt++;
    checksum = CHECK_SUM(data,lastData);
    lastData = data;
     check_connectdStatu(data);

    switch (frame_enum)
    {
        case frame_head:
        {
           if (cnt==2 )
           {
               if(head == (uint16_t)(rxData.buf[0]<<8|rxData.buf[1]))
               {
                   frame_enum = frame_length;
               } else
               {
                 cnt = rxDatCnt =0;       
                 lastData = 0;        
                  return FRAME_HEAD_ERRO;
               }      
           }
        }break;
        case frame_length:
        {
             cnt = 0;
             rxData.length = rxData.buf[2];
             frame_enum = frame_func;
        }break;
        case frame_func:
        {
            cnt = 0;
				   	frame_enum = frame_data;
            rxData.func =  rxData.buf[3];
        }break;
        case frame_data:
        {
            if(cnt == rxData.length-5 )
            {
                frame_enum = frame_checkSum;
                cnt = 0;
            }
            if(cnt > BLE_RXBUFF_SIZE) //超过最大缓存大小
            {
                cnt = rxDatCnt =0; 
                return FEAME_SIZE_ERRO;
            }
        }break;
        case frame_checkSum:
        {
            cnt = rxDatCnt =0; 
            lastData=0;           
            if(checksum == rxData.buf[rxData.length-1] )
            {
                 frame_enum = frame_head;
                 return FRAME_RCV_OK;
            }
            else
            {
                return  FRAME_CHECK_ERRO  ;
            }

        }break;
    }
		return FRAME_ANYS_ING;
}



/**************************************************************************************************
 * @fn     ble_anasys(uint8_t data,delegate callback)
 *
 * @brief   数据接收解析校验
 * input parameters
 *
 * @data：需要解析的数据
 * @callback :解析成功回调函数
 * output parameters
 *
 * @return      uint8_t 返回当前解析状态
 */
uint8_t  ble_anasys(uint8_t data,delegate callback)
{
     uint8_t erroType=0;
     erroType = lk_ble_checkSum(data);
    if(erroType == FRAME_RCV_OK)
    {
        frameBuf.func = rxData.func;
        frameBuf.length = rxData.length-5;//帧头部+type+length+checkSum = 5
       for(int i=0;i<frameBuf.length;i++) 
       {
           frameBuf.buf[i]=rxData.buf[4+i];
       }
       callback(&frameBuf);
    }
    return erroType;
}
extern mybleOps_t mybleOps[];
/**************************************************************************************************
 * @fn   static void myBlefunc(rxFrame_t *frame)
 *
 * @brief   ble命令执行函数
 * input parameters
 *
 * @frame: 帧数据结构
 * output parameters
 *
 * None.
 *
 * @return      None.
 */
void myBlefunc(rxFrame_t *frame)
{
    uint8_t cmd;
    mybleOps_t *myble =NULL;
    cmd =frame->func;
   for (myble =mybleOps ; myble!=NULL; myble++)
   {
      if (myble->cmd == cmd)
      {
         myble->invoke(frame); /* code */
         break;
      }
   }
   
}

/**************************************************************************************************
 * @fn   static void ble_anysys_process(SqQueue *q)
 *
 * @brief   ble缓存解析函数,将对应缓存中的协议解析
 * input parameters
 *
 * @frame: 帧数据结构
 * output parameters
 *
 * None.
 *
 * @return      int 返回协议解析错误类型
 *  #define FRAME_HEAD_ERRO    0x01    //头错误
 *  #define FRAME_CHECK_ERRO   0x02   //校验错误
 *  #define FRAME_CMD_ERRO     0x03  //无对应命令 
 *  #define FEAME_SIZE_ERRO    0x04  //超过最大缓存大小
 *  #define FRAME_ANYS_ING     0X05   //解析中
 *  #define FRAME_RCV_OK       0xff   //接收数据成功
 */
int  ble_anysys_process(void)
{
	uint8_t data=0;
   int erroType=0;
	if(ringQueue_ops.getLength(&bleQueue)>=1)
	{
	     ringQueue_ops.pop(&bleQueue,&data);
       erroType = ble_anasys(data,myBlefunc);
	}

   return erroType;
}

int ble_queuePush(uint8_t data)
{
  return  ringQueue_ops.push(&bleQueue,data);
}



ble_handle_t  ble_handle=
{
    .ifBleConnected = false,
		.ifBleDisConnected = false,
    .myAnasysProcess = ble_anysys_process,
		.push=ble_queuePush,
};


