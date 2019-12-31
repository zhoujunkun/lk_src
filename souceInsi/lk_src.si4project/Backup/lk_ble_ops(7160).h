#ifndef __LK_BLE_OPS_H
#define __LK_BLE_OPS_H
#include "lk_ble.h"
#include "stdbool.h"

//ble   V1.2  ---》510,520
#define BLE_HEART              0x02u   //心跳包
#define BLE_QUIT_WEIXING       0x04u //退出小程序微信
#define BLE_MASSAHE_MODE       0x31u   //按摩模式
#define BLE_HEAT_GEAR          0x33u   //加热档位
#define BLE_RUN_TIME           0x3Au   //设计按摩时间
#define BLE_MASSAGE_GEAR       0x32u    //设计按摩档位
#define BLE_MASSAGE_OVER       0x39u    //按摩结束
#define BLE_NULL                0xFF   //无效
#define BLE_CONNECTED          "+CONNECTED"
#define BLE_DISCONNECTED       "+DISCONNECT"

//操作设备实时时间
typedef struct
{
  uint8_t year; //年
  uint8_t month; //月
  uint8_t day;  //天
  uint8_t hour; // 小时
  uint8_t minute; //分钟
  uint8_t second; //秒钟
}bleRealTime_t;


//操作设备当前状态

typedef struct
{
	uint8_t runStatu; //0:待机; 1：运行;  2: 充电中;  3：充满
	uint16_t runTime; //已运行秒数 
    uint8_t cfgMinute; //定时分钟数
    uint8_t currentMode; //当前模式
    uint8_t currentGears; //当前档位
    uint8_t currentHeatStatu;//当前加热状态
    uint8_t currentVoiceStatu; //当前语音状态
    uint8_t electric;  //电量
    uint8_t adornStatu; //配搭状态
    uint16_t product;    //产品型号
}bleDeviceStatu_t;


typedef struct
{
  uint16_t head;
  uint8_t func; 
  uint8_t size;
  bleDeviceStatu_t statu;
  uint8_t checkSum;
}bleHeartFrame_t;


typedef union
{

  uint8_t sendBuf[19] ;  //占用空间
  bleHeartFrame_t frame;

}bleHeartFrameUnion_t;
typedef void (*bleSend)(uint8_t *data,uint8_t size);

typedef struct 
{
  uint8_t   gears;  // 按摩挡位 0~255 ;代表挡位0~255
  uint8_t   mode;   //按摩模式： 0x01 模式1；0x02 模式2；。。。
  bool      ifOver; //按摩是否结束 
  uint8_t   runtime; //按摩时间  分钟数
}ble_massage_t;


typedef enum {heatClose=0x00,heatLowGear=0x10,heatMiddleGear=0x20,heatHighGeae=0x30}heatGears_enum_t;

typedef enum{masterMcu=0x01,masterWeixing=0x02,masterRemote=0x03}masterId_enum_t;
struct frame_handle_s
{
	ringQueue_ops_t *queueInvoke; //缓存操作函数
  int (*anasys)(SqQueue *bleQueue);  //解析
  ble_massage_t massage; //按摩
  heatGears_enum_t   heatGears ; //加热挡位 关闭：0x00;低挡：0x10;中档：0x20;高档：0x30
  masterId_enum_t   masterId;      //操作发起端 mcu ,weixing,遥控器
  bleRealTime_t    realTime;    //实时时间
  bool ifQuitWeixing; // 退出小程序,true:退出
  bleDeviceStatu_t deviceStatu; //设备状态
};
   
typedef struct frame_handle_s frame_handle_t;

#define bleQueueName(name)   SqQueue name


//usr 
void ble_init(bleSend sendCallBack); 
void ble_heart_ack(bleDeviceStatu_t *devstatu);
void ble_massageGears_ack(void);

extern frame_handle_t frameHandle;

#endif

