#include "lk_ble.h"

rxData_t   rxData;   //接收数据缓存
rxFrame_t frameBuf;   //帧缓存

typedef enum {frame_head=0,frame_length,frame_func,frame_data,frame_checkSum}frame_enum_t;

frame_enum_t frame_enum=frame_head;

uint8_t fist_check=0;
#define CHECK_SUM(now,last)  (now^last)  //dat1^dat2^dat3^dat4....

#define CHECK_STRING(now,last) (now^last)


void check_connectdStatu(char *str)

{





}




char checkConnected[] ={BLE_CONNECTED};
uint8_t nowCheckStrConect = 'C';
uint8_t nowCheckStrDisConect = 'D',strCnt;
bool ifConnected = false;
uint8_t lk_ble_checkSum(uint8_t data)
{   
	 static uint8_t cnt=0,rxDatCnt=0,checksum=0,lastData=0;
   static char* charConted =BLE_CONNECTED;
	 
    uint16_t head=0xABBC;
    
    rxData.buf[rxDatCnt++] = data;
    cnt++;
    checksum = CHECK_SUM(data,lastData);
    lastData = data;
	
	if (CHECK_STRING(data,nowCheckStrConect) == 0)
	{
		  strCnt++;
      nowCheckStrConect = checkConnected[strCnt];
	    if(strCnt == 9) 
       {
			   ifConnected = true; 
				 strCnt = 0;
				 nowCheckStrConect = checkConnected[0];
			 }
	}else 
	{
		strCnt =0;
	  nowCheckStrConect = checkConnected[0];
	}
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




ble_handle_t  ble_handle=
{
    .myanasys = ble_anasys, 
};


