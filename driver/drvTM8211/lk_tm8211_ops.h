#ifndef __LK_TM8211_OPS_H
#define __LK_TM8211_OPS_H
#include "lk_global.h"



//user include 
#include "main.h"
typedef enum {ioLow=0,ioHigh=1}tmIoStatuEnum_t;;
typedef void (*_writeFuc)(tmIoStatuEnum_t statu);

typedef struct 
{
  _writeFuc Ws;
  _writeFuc Bck;
  _writeFuc Din;  
}lk_tm8211_ops_t;

extern lk_tm8211_ops_t tm8211_ops;
#endif

