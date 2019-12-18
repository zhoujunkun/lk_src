#include "lk_ble_ops.h"
frame_handle_t frameHandle;
//心跳
void ble_heart(rxFrame_t *frame)
{
  frameHandle.realTime.year = frame->buf[0];
  frameHandle.realTime.month = frame->buf[1];
  frameHandle.realTime.day = frame->buf[2];
  frameHandle.realTime.hour = frame->buf[3];
  frameHandle.realTime.minute = frame->buf[4];
  frameHandle.realTime.second = frame->buf[5];

  
}
   uint8_t heatGears=0,master;
//加热档位
void ble_heat_gear(rxFrame_t *frame)
{
	frameHandle.heatGears= (heatGears_enum_t)(frame->buf[0]);
	frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);
}

//按摩时间
void ble_massage_time(rxFrame_t *frame)
{
   frameHandle.massage.runtime = frame->buf[0];
   frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);


}

//按摩档位
void ble_massage_gear(rxFrame_t *frame)
{
	frameHandle.massage.gears = frame->buf[0];
	frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);

}

//按摩模式
void ble_massage_mode(rxFrame_t *frame)
{
	frameHandle.massage.mode = frame->buf[0];
	frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);
}


//按摩结束
void ble_massage_over(rxFrame_t *frame)
{
	frameHandle.massage.ifOver = true;
	frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);

}


//退出微信小程序
void ble_quit_weixing(rxFrame_t *frame)
{
    frameHandle.ifQuitWeixing = true;
	frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);

}



mybleOps_t mybleOps[]=
{
 {BLE_HEART,ble_heart},    //心跳
 {BLE_QUIT_WEIXING,ble_quit_weixing},  //退出微信小程序
 {BLE_HEAT_GEAR,ble_heat_gear},   // 加热档位
 {BLE_RUN_TIME,ble_massage_time}, //按摩时间
 {BLE_MASSAGE_GEAR,ble_massage_gear},    //按摩档位
 {BLE_MASSAGE_OVER,ble_massage_over},   //按摩结束
 {BLE_MASSAHE_MODE,ble_massage_mode},   //按摩模式
 {BLE_NULL,NULL},  //无效
};


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
 * @fn   static void ble_anysys_queue(SqQueue *q)
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
int  ble_anysys_queue(SqQueue *bleQueue)
{
	uint8_t data=0;
   int erroType=0;
	if(frameHandle.queueInvoke->getLength(bleQueue)>=1)
	{
	     frameHandle.queueInvoke->pop(bleQueue,&data);
       erroType = ble_handle.myanasys(data,myBlefunc);
	}

   return erroType;
}


/**************************************************************************************************
 * @fn   void ble_init(void)
 *
 * @brief   蓝牙初始化
 * input parameters
 *
 * None
 * output parameters
 *
 * @return      None
 */
void ble_init(void)
{
	 frameHandle.queueInvoke = &ringQueue_ops;
   frameHandle.anasys = ble_anysys_queue;
}

bleHeartFrame_t bleHeartFrame;

static uint8_t  check_sum(uint8_t *data, uint8_t size)
{
	uint8_t checkSum=0;
	
    for(int i=0;i<size;i++)
	{
		
	  checkSum = checkSum^data[i];
	}
    
   return checkSum; 
}


void ble_heart_ack(bleDeviceStatu_t *devstatu,bleSend sendCallBack)
{
   bleHeartFrame.head=0XABBC;
   bleHeartFrame.length = 19;
   bleHeartFrame.func = 0x82;
   for(int i=0;i<sizeof(devstatu);i++)
   {
       bleHeartFrame.sendBuf[4+i] = *((uint8_t *)devstatu++);
   }
   bleHeartFrame.checkSum = check_sum((uint8_t*)(&bleHeartFrame),sizeof(bleHeartFrame_t));
   sendCallBack((uint8_t*)(&bleHeartFrame),sizeof(bleHeartFrame_t));
}



