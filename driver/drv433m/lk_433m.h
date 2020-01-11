#ifndef __LK_433M_H
#define __LK_433M_H
#include "lk_global.h"


int my433M_anasys(uint16_t value);

typedef enum {pressUp=0,pressLeft,pressRight,pressDown,pressMenu,remoteMax,remotePressNone}remotePressEnum_t;
typedef void (*remoteCb)(uint16_t remoteData);  //remoteData 按压键值


void lk_remote_init(remoteCb up,remoteCb down,remoteCb left,remoteCb right,remoteCb menu);
#endif
