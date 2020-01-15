/**
  ******************************************************************************
  * @file           : lk_ble_ops.c
  * @author         : zjk
  * @version        : v1.1
  * 
  * @date           : 2019-12-23  v1.0   第一版
  *                   2020-1-8    v1.1   
  * @brief          : 蓝牙通信解析成功后功能接口
  ******************************************************************************
  */
#include "lk_ble_ops.h"
frame_handle_t frameHandle;
bleSend sendFrame;
	_myDelegate myEvent[bleFuncMax];

//关机
void ble_shutdown(rxFrame_t *frame)
{
    frameHandle.ifShutDown=true;
}

//心跳
void ble_heart(rxFrame_t *frame)
{
    frameHandle.realTime.year = frame->buf[0];
    frameHandle.realTime.month = frame->buf[1];
    frameHandle.realTime.day = frame->buf[2];
    frameHandle.realTime.hour = frame->buf[3];
    frameHandle.realTime.minute = frame->buf[4];
    frameHandle.realTime.second = frame->buf[5];
    frameHandle.ble->ifBleConnected = true;
    frameHandle.ble->ifBleDisConnected = false;
    frameHandle.ifQuitWeixing =false;    
    if(myEvent[bleHeart] !=NULL)  myEvent[bleHeart](frame);
}
   uint8_t heatGears=0,master;
//加热档位
void ble_heat_gear(rxFrame_t *frame)
{
    frameHandle.heatGears= (heatGears_enum_t)(frame->buf[0]);
    frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);
    if(frameHandle.heatGears >=1) frameHandle.massage.ifOver = false;
    if(myEvent[bleHeatGear] !=NULL)  myEvent[bleHeatGear](frame);
}

//按摩时间
void ble_massage_time(rxFrame_t *frame)
{
    frameHandle.massage.runtime = frame->buf[0];
    frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);
    if(myEvent[bleRunTime] !=NULL)  myEvent[bleRunTime](frame);

}

//按摩档位
void ble_massage_gear(rxFrame_t *frame)
{
    frameHandle.massage.gears = frame->buf[0];
    if(frameHandle.massage.gears >=1) frameHandle.massage.ifOver = false;
    frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);
    if(myEvent[bleMassageGear] !=NULL)  myEvent[bleMassageGear](frame);
}

//按摩模式
void ble_massage_mode(rxFrame_t *frame)
{
    frameHandle.massage.mode = (massageMode_enum_t)(frame->buf[0]);
    frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);
    if(myEvent[bleMassgeMode] !=NULL)  myEvent[bleMassgeMode](frame);  
}


//按摩结束
void ble_massage_over(rxFrame_t *frame)
{
    frameHandle.massage.ifOver = true;
    frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);
    frameHandle.massage.gears = 0;
    frameHandle.heatGears = heatClose;
    if(myEvent[bleMassageOver] !=NULL)  myEvent[bleMassageOver](frame);
}


//退出微信小程序
void ble_quit_weixing(rxFrame_t *frame)
{
    frameHandle.ifQuitWeixing = true;
    frameHandle.masterId = (masterId_enum_t)(frame->buf[1]);
    frameHandle.ble->ifBleConnected = false;
    frameHandle.ble->ifBleDisConnected = true;
}



mybleOps_t mybleOps[]=
{
    {BLE_DEVICE_SHUNDOWN,ble_shutdown},      //关机
    {BLE_HEART,ble_heart},                  //心跳
    {BLE_QUIT_WEIXING,ble_quit_weixing},    //退出微信小程序
    {BLE_HEAT_GEAR,ble_heat_gear},          //加热档位
    {BLE_RUN_TIME,ble_massage_time},        //按摩时间
    {BLE_MASSAGE_GEAR,ble_massage_gear},    //按摩档位
    {BLE_MASSAGE_OVER,ble_massage_over},    //按摩结束
    {BLE_MASSAHE_MODE,ble_massage_mode},    //按摩模式
    {BLE_NULL,NULL},                        //无效
};


int my_strlen(char *str)
 {
     char *tmp = str;
     while (*str)
     {
         str++;
     }
     return str - tmp;
}
/**************************************************************************************************
 * @fn  void ble_init(bleSend sendCallBack)
 *
 * @brief   蓝牙初始化
 * input parameters
 *
 *@sendCallBack：串口发送回调函数,在ack应答会使用上
 *
 *
 * output parameters
 *
 * @return      None
 */
uint8_t  bleName[] = {"AT+NAME=SKG_4099\r\n"}; //蓝牙名称SKG_4099
void ble_init(bleSend sendCallBack)
{
    sendFrame = sendCallBack;
    frameHandle.ble = &ble_handle;
    sendCallBack(bleName,sizeof(bleName)-1);  
}


/**************************************************************************************************
 * @fn  void ble_myEvent_register(bleEventEnum_t event,_myDelegate cb)
 *
 * @brief   事件注册函数
 * input parameters
 *
 *@event：事件
 *
 *@cb    回调函数 
 * output parameters
 *
 * @return      None
 */
void ble_myEvent_register(bleEventEnum_t event,_myDelegate cb)
{
    myEvent[event] = cb;
}





static uint8_t  check_sum(uint8_t *data, uint8_t size)
{
    uint8_t checkSum=0;

    for(int i=0;i<size;i++)
    {
        
      checkSum = checkSum^data[i];
    }

    return checkSum; 
}


//心跳应答
void ble_heart_ack(bleDeviceStatu_t *devstatu)
{
    bleHeartFrameUnion_t bleSendHeartFrame;	
    uint8_t *pdata =NULL;
    volatile uint16_t daya=0;
    bleSendHeartFrame.frame.head=0xBCAB;
    bleSendHeartFrame.frame.func = 0x82;
    pdata = (uint8_t*)devstatu;
    bleSendHeartFrame.frame.size = sizeof(bleDeviceStatu_t)+5;
    daya	=devstatu->product;
    devstatu->product =(daya>>8)|((daya&0xFF)<<8);  //大小端问题
    daya = devstatu->runSeconds;
    devstatu->runSeconds = (daya>>8)|((daya&0xFF)<<8);
    for(int i=0;i<sizeof(bleDeviceStatu_t);i++)
    {
    bleSendHeartFrame.sendBuf[4+i] = *(pdata++);
    }
    bleSendHeartFrame.frame.checkSum = check_sum(bleSendHeartFrame.sendBuf,bleSendHeartFrame.frame.size-1);
    sendFrame(bleSendHeartFrame.sendBuf,bleSendHeartFrame.frame.size);
}



//按摩档位应答
void ble_massageGears_ack(void)
{
    uint8_t sendArray[8]={0xAB,0XBC};
    sendArray[2] = 8; //size
    sendArray[3] = 0XB2; //func
    sendArray[4] = 10;//frameHandle.massage.gears;; //  
    sendArray[7]= check_sum(sendArray,7);
    sendFrame(sendArray,8);
}

//加热档位应答
void ble_heatGears_ack(void)
{
    uint8_t sendArray[8]={0xAB,0XBC};
    sendArray[2] = 8; //size
    sendArray[3] = 0XB3; //func
    sendArray[4] =heatLowGear; //frameHandle.heatGears;; /  
    sendArray[7]= check_sum(sendArray,7);
    sendFrame(sendArray,8);
}


//按摩结束应答
void ble_massageOver_ack(void)
{
    uint8_t sendArray[8]={0xAB,0XBC};
    sendArray[2] = 8; //size
    sendArray[3] = 0XB9; //func
    sendArray[4] = 0; //  
    sendArray[7]= check_sum(sendArray,7);
    sendFrame(sendArray,8);
}

//退出微信小程序应答
void ble_quitWeixing_ack(void)
{
    uint8_t sendArray[8]={0xAB,0XBC};
    sendArray[2] = 8; //size
    sendArray[3] = 0X84; //func
    sendArray[4] = 0; //  
    sendArray[7]= check_sum(sendArray,7);
    sendFrame(sendArray,8);
}


//无佩戴关机通知
void ble_noAdornShutDown_ack(void)
{
    uint8_t sendArray[8]={0xAB,0XBC};
    sendArray[2] = 8;    //size
    sendArray[3] = 0X03; //func
    sendArray[4] = 0; 
    sendArray[7]= check_sum(sendArray,7);
    sendFrame(sendArray,8);
}


//关机应答
void ble_ShutDown_ack(void)
{
    uint8_t sendArray[8]={0xAB,0XBC};
    sendArray[2] = 8;    //size
    sendArray[3] = 0X81; //func
    sendArray[4] = 0; //  
    sendArray[7]= check_sum(sendArray,7);
    sendFrame(sendArray,8);
}


//设备上电应答
void ble_deviceOpenPower_ack(void)
 {
    uint8_t sendArray[8]={0xAB,0XBC};
    sendArray[2] = 8;     //size
    sendArray[3] = 0X02; //func
    sendArray[4] = 0; // 
    sendArray[7]= check_sum(sendArray,7);
    sendFrame(sendArray,8);
}


//设置按摩时间应答
void ble_massageRuntime_ack(void)
{
    uint8_t sendArray[8]={0xAB,0XBC};
    sendArray[2] = 8;    //size
    sendArray[3] = 0XBA; //func
    sendArray[4] = frameHandle.massage.runtime;
    sendArray[7]= check_sum(sendArray,7);
    sendFrame(sendArray,8);
}

