//UART ECHO demo Main Program

#include "CMSDK_CM0.h"
#include "uart.h"
#include "sys.h"
#include "ioconfig.h"

//lk include
#include "lk_ble_ops.h"

 bleQueueName(bleQueue);   //定义ble 数据缓存结构
 int erroType =0;

 void delay(uint16_t cnt)
 {
   while(cnt--);
 }
 
 void uart_send(uint8_t *data, uint8_t size)
 {
    for(int i=0;i<size;i++)
	 {
			UART0->DATA=data[i];
		  delay(1000);
	 }
 }
 uint8_t testData[]={0x23,0x33,0x34,0x43,0x23};

int main(void)
{
	//system initial
	SYS_SystemInitial();
	//init UART pin
	PA_2_INIT(PA_2_TX0);
	PA_3_INIT(PA_3_RX0);
	//initial UART0
	UART_Open(UART0,115200,UART_NO_PARITY,UART_RX_NOT_EMPTY);
	UART_EnableInt(UART0,UART_RX_NOT_EMPTY);
	NVIC_EnableIRQ(UART0_IRQn);	
	//lk init
	ble_init(uart_send); //蓝牙初始化
	frameHandle.devUpStatu.adornStatu = 0x01; //主机佩戴
	frameHandle.devUpStatu.currentGears = 4; //当前档位
	frameHandle.devUpStatu.currentHeatStatu = heatMiddleGear;
	frameHandle.devUpStatu.currentMode = 1;
	frameHandle.devUpStatu.currentVoiceStatu = 0;
	frameHandle.devUpStatu.electric = 50; //电量%
	frameHandle.devUpStatu.product= 4099;  //产品型号
	frameHandle.devUpStatu.runSeconds = 500; //秒
	frameHandle.devUpStatu.cfgMinute = 9; //定时分钟数
	frameHandle.devUpStatu.runStatu = 0x01;
	

	//ble_massageGears_ack();
//	delay(2000);
//	ble_massageOver_ack();
//	delay(2000);
 // ble_quitWeixing_ack();
//	delay(2000);
//  ble_noAdornShutDown_ack();
//		delay(2000);
//	ble_ShutDown_ack();
//		delay(2000);
//	ble_deviceOpenPower_ack();
//		delay(2000);
	//ble_massageRuntime_ack();
		delay(2000);
	//Loop forever 
  //uart_send(testData,5);
//  ble_heart_ack(&bleDeviceStatu);
	
	//ble_massageGears_ack();
	while(1)
	{		
    erroType = frameHandle.anasys(&bleQueue); //协议解析
	}

}

/*****************************************************************************
** Function name:		UART0_IRQHandler
**
** Descriptions:		UART0 receive interrupt handler
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void UART0_IRQHandler(void)
{
	uint8_t cdata;
	//verify how many data received in rxbuf
	
	if (UART0->INTSTATUS_b.RXNEINT )		/* Received data interrupt pending */
	{
		cdata = UART0->DATA;
		UART0->DATA=cdata;
		frameHandle.queueInvoke->push(&bleQueue,cdata);  //数据接收
	}
	
	/*clean interrupt status */
	UART0->INTSTATUS = 0x0F;
}
