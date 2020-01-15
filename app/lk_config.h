#ifndef __LK_CONFIG_H
#define __LK_CONFIG_H
#include "lk_global.h"

#define BLE_ENABLE   1              //蓝牙



  #if  BLE_ENABLE   
    #include "lk_ble_ops.h"
  #endif

  #if REMOTE_433M_ENABLE
    #include "lk_433m.h"
  #endif
 


#endif

