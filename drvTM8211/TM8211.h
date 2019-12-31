#ifndef __TM8211_H
#define __TM8211_H
#include "lk_global.h"

#include "main.h"
void tm8211_init(void);
void tm8211_write(int temp);
void tm8211_test(void);
#endif