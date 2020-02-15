#include "lk_board.h"

uint8_t usbCheckIsOld = 0; 
typedef enum {firstRun=1, ioIsCheck,ioNocheck} ioRunStatu_enum_t;

typedef struct
{
   ioRunStatu_enum_t ioRunStatu;// io运行状态
   uint8_t checkMs; // 消抖时间ms
   uint8_t logicStatu;  //按下逻辑状态
   uint8_t (*read)(void); //读取io状态函数
   void (*ioIsCheckFunc)(void); // io被检测到运行一次函数
   void (*ioIsNoCheckFunc)(void); // io没有被检测到运行一次函数
}ioCheckStruct_t;

ioCheckStruct_t usbCheckStruct;
ioCheckStruct_t batChargeCheckStruct;
ioCheckStruct_t batChargeFullStruct;

uint8_t  usbRead(void)
{
    return USB_GPIO_Read();
}

void usbIsCheck(void)
{
    rt_kprintf("usb in\r\n");
}

void usbIsNoCheck(void)
{
    rt_kprintf("usb out\r\n");

}

void usbIoStatuCheck_init(void)
{
   usbCheckStruct.read = usbRead;
   usbCheckStruct.checkMs = 10;
   usbCheckStruct.ioRunStatu = firstRun;
   usbCheckStruct.logicStatu = Bit_SET;  /*高电平检测*/
   usbCheckStruct.ioIsCheckFunc = usbIsCheck;
   usbCheckStruct.ioIsNoCheckFunc = usbIsNoCheck;
}

///////////BAT charge///////////////
//正在充电
// uint8_t  batChargeRead(void)
// {
//     return USB_GPIO_Read();
// }

// void batChargeIsCheck(void)
// {
//     rt_kprintf("usb in\r\n");
// }

// void batChargeIsNoCheck(void)
// {
//     rt_kprintf("usb out\r\n");

// }
// void batChargeCheck_init(void)
// {
//    batChargeCheckStruct.read = batChargeRead;
//    batChargeCheckStruct.checkMs = 10;
//    batChargeCheckStruct.ioRunStatu = firstRun;
//    batChargeCheckStruct.logicStatu = Bit_RESET;  /*低电平*/
//    batChargeCheckStruct.ioIsCheckFunc = batChargeIsCheck;
//    batChargeCheckStruct.ioIsNoCheckFunc = batChargeIsNoCheck;
// }

//充满

uint8_t  batCharFullgeRead(void)
{
    return BAT_GPIO_Read();
}

void batChargeFullIsCheck(void)
{
    rt_kprintf("BAT Charge full\r\n");
}

void batChargeFullIsNoCheck(void)
{
    rt_kprintf("BAT Charge \r\n");

}
void batStandbyCheck_init(void)
{
   batChargeFullStruct.read = batCharFullgeRead;
   batChargeFullStruct.checkMs = 10;
   batChargeFullStruct.ioRunStatu = firstRun;
   batChargeFullStruct.logicStatu = Bit_RESET;  /*低电平*/
   batChargeFullStruct.ioIsCheckFunc = batChargeFullIsCheck;
   batChargeFullStruct.ioIsNoCheckFunc = batChargeFullIsNoCheck;   
}



void  ioCheckProcessLoop(ioCheckStruct_t *ioStruct)
{
    switch(ioStruct->ioRunStatu)
    {
        case firstRun:
        {
            if( ioStruct->read() == ioStruct->logicStatu) 
            {  
                rt_thread_mdelay(ioStruct->checkMs);
                if(ioStruct->read()== ioStruct->logicStatu )
                {
                    ioStruct->ioIsCheckFunc();
                    ioStruct->ioRunStatu = ioIsCheck;
                }          
            }
            if ( ioStruct->read() == !(ioStruct->logicStatu) )
            {
                rt_thread_mdelay(ioStruct->checkMs);
                if(ioStruct->read()== !(ioStruct->logicStatu) )
                {
                    ioStruct->ioIsNoCheckFunc();
                    ioStruct->ioRunStatu = ioNocheck;
                }
            }
        }break;
        case ioIsCheck:
        {
            if ( ioStruct->read() == !(ioStruct->logicStatu))
            {
                rt_thread_mdelay(ioStruct->checkMs);
                if(ioStruct->read()== !(ioStruct->logicStatu) )
                {
                    ioStruct->ioIsNoCheckFunc();
                    ioStruct->ioRunStatu = ioNocheck;
                }
            }     
        }break;
        case ioNocheck:
        {
            if( ioStruct->read() == (ioStruct->logicStatu)) 
            {  
                rt_thread_mdelay(ioStruct->checkMs);
                if(ioStruct->read()== (ioStruct->logicStatu) )
                {
                    ioStruct->ioIsCheckFunc();
                    ioStruct->ioRunStatu = ioIsCheck;
                }          
            }
        }break;            
    }    
}


void checkUSB(void)
{
    usbIoStatuCheck_init();
    while(1)
    {
       ioCheckProcessLoop(&usbCheckStruct);  
       rt_thread_mdelay(5);  
    }
}
MSH_CMD_EXPORT(checkUSB, k51 hardware usb check);


void checkBAT(void)
{
    batStandbyCheck_init();
    while(1)
    {
      ioCheckProcessLoop(&batChargeFullStruct);
      rt_thread_mdelay(5);
    }
}

MSH_CMD_EXPORT(checkBAT, k51 hardware bat check);