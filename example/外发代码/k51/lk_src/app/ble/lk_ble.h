#ifndef  __LK_BLE_H
#define __LK_BLE_H
#include "lk_global.h"
#include "queue/ringQueue.h" 

#define BLE_RXBUFF_SIZE   20     //接收缓存数字大小

//状态
#define FRAME_HEAD_ERRO    0x01    //头错误
#define FRAME_CHECK_ERRO   0x02    //校验错误
#define FRAME_CMD_ERRO     0x03    //无对应命令 
#define FEAME_SIZE_ERRO    0x04    //超过最大缓存大小
#define FRAME_ANYS_ING     0X05    //解析中
#define FRAME_RCV_OK       0xff    //接收数据成功


#define FRAME_CONNECTED          0xEE   //蓝牙模块连接成功
#define FRAME_DISCONNECTED       0xEF   //蓝牙模块连接断开



#define BLE_CONNECTED          "CONNECTED"
#define BLE_DISCONNECTED       "DISCONNECT"


void ble_checksum(uint8_t *data, uint8_t size );

//结构体

typedef struct 
{
	uint8_t buf[BLE_RXBUFF_SIZE]; /* data */
	uint8_t length;
	uint8_t func;
	uint8_t checkSum;
}rxData_t;


typedef struct 
{
	uint8_t buf[BLE_RXBUFF_SIZE]; /* data */
	uint8_t length;
	uint8_t func;
}rxFrame_t;


typedef void (*_myDelegate)(rxFrame_t *frame);

typedef struct  
{
	uint8_t cmd; 
	_myDelegate  invoke;
}mybleOps_t;



typedef struct 
{
	bool ifBleConnected ;  
	bool ifBleDisConnected ;
	int (*push)(uint8_t data);    //缓存操作函数

	int (*myAnasysProcess)(void);
	
}ble_handle_t;



extern ble_handle_t  ble_handle;
#endif


