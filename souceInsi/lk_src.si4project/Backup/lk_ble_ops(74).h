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



typedef struct 
{
  uint8_t   gears;  // 按摩挡位 0~255 ;代表挡位0~255
  uint8_t   mode;   //按摩模式： 0x01 模式1；0x02 模式2；。。。
  bool      ifOver; //按摩是否结束 
  uint8_t   runtime; //按摩时间  分钟数
}ble_massage_t;





struct frame_handle_s
{
	ringQueue_ops_t *queueInvoke; //缓存操作函数
  int (*frameAnasys)(SqQueue *bleQueue);  //解析
  ble_massage_t massage; //按摩
  uint8_t   heatGears ; //加热挡位 关闭：0x00;低挡：0x10;中档：0x20;高档：0x30
  uint8_t   masterId;      //发送主机端口 
  bool ifQuitWeixing; // 退出小程序,true:退出

};
   
typedef struct frame_handle_s frame_handle_t;

#define bleQueueName(name)   SqQueue name


//usr 
void ble_init(void); 
extern frame_handle_t frameHandle;

#endif

