#ifndef __LK_TM8211_H
#define __LK_TM8211_H

#include "lk_tm8211_ops.h"



typedef struct 
{
  int size;  /* data */
  const int *buf;
}tm8211_data_t;

void tm8211_init(void);
void tm8211_writeSingle(int L,int R);

#endif


