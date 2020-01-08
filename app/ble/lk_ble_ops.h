#ifndef __LK_BLE_OPS_H
#define __LK_BLE_OPS_H

#include "lk_ble.h"

//ble   V1.0  ---》510,520
#define BLE_DEVICE_SHUNDOWN              0x01u   //关机

#define BLE_HEART              0x02u   //心跳包
#define BLE_QUIT_WEIXING       0x04u //退出小程序微信
#define BLE_MASSAHE_MODE       0x31u   //按摩模式
#define BLE_HEAT_GEAR          0x33u   //加热档位
#define BLE_RUN_TIME           0x3Au   //设计按摩时间
#define BLE_MASSAGE_GEAR       0x32u    //设计按摩档位
#define BLE_MASSAGE_OVER       0x39u    //按摩结束
#define BLE_NULL                0xFF   //无效



typedef enum {heatClose=0x00,heatLowGear=0x10,heatMiddleGear=0x20,heatHighGeae=0x30}heatGears_enum_t;

typedef enum{masterMcu=0x01,masterWeixing=0x02,masterRemote=0x03}masterId_enum_t;

//舒缓模式,智能模式,活力模式,强劲模式
typedef enum{smartMode=0x01,easeMode=0x02,vitalityMode=0x03,powerfulMode=0x04}massageMode_enum_t;//




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
#pragma pack (1) /*指定按1字节对齐*/
typedef struct
{
	uint8_t runStatu; //0:待机; 1：运行;  2: 充电中;  3：充满
	uint16_t runSeconds; //已运行秒数 
    uint8_t cfgMinute; //定时分钟数
    uint8_t currentMode; //当前模式
    uint8_t currentGears; //当前档位
    uint8_t currentHeatStatu;//当前加热状态
    uint8_t currentVoiceStatu; //当前语音状态
    uint8_t electric;  //电量
    uint8_t adornStatu; //配搭状态
    uint8_t noUse1;    //未使用
	uint8_t noUse2;    //未使用
    uint16_t product;    //产品型号
}bleDeviceStatu_t;
#pragma pack () /*取消指定对齐，恢复缺省对齐*/


typedef struct
{
  uint16_t head;
  uint8_t size;  //字节大小
  uint8_t func; //功能码
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
  massageMode_enum_t   mode;   //按摩模式： 0x01 模式1；0x02 模式2；。。。
  bool      ifOver; //按摩是否结束 
  uint8_t   runtime; //按摩时间  分钟数
}ble_massage_t;


struct frame_handle_s
{
  ble_handle_t *ble;
  ble_massage_t bleMassage; //按摩
  heatGears_enum_t   heatGears ; //加热挡位 关闭：0x00;低挡：0x10;中档：0x20;高档：0x30
  masterId_enum_t   masterId;      //操作发起端 mcu ,weixing,遥控器
  bleRealTime_t    realTime;    //实时时间
  bool ifQuitWeixing; // 退出小程序,true:退出
  bool ifShutDown;   //关机指令
  bleDeviceStatu_t devUpStatu; //设备上传状态
};
   
typedef struct frame_handle_s frame_handle_t;

#define bleQueueName(name)   SqQueue name

/*测试微信小程序心跳包应答和关机应答有效*/
//初始化
void ble_init(bleSend sendCallBack); 
//心跳应答
void ble_heart_ack(bleDeviceStatu_t *devstatu);
//按摩档位应答
void ble_massageGears_ack(void);
//加热档位应答
void ble_heatGears_ack(void);
//按摩结束应答
void ble_massageOver_ack(void);
//退出微信小程序应答
void ble_quitWeixing_ack(void);
//无佩戴关机应答------
void ble_noAdornShutDown_ack(void);
//关机应答
void ble_ShutDown_ack(void);
//设备上电应答
void ble_deviceOpenPower_ack(void);
//设置按摩时间应答
void ble_massageRuntime_ack(void);



extern frame_handle_t frameHandle;

#endif

