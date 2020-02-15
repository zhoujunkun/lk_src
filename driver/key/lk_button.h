#ifndef __LK_BUTTON_H
#define __LK_BUTTON_H
#include "lk_global.h"
typedef struct lk_buttonHandle
{
  uint8_t pressLogicLevel;
  uint8_t (*read)(void);
  void (*cb)(void);
   struct lk_buttonHandle *next;
}lk_buttonHandle_t;

void button_1ms_callBack(void);
int button_register(lk_buttonHandle_t *btn);
uint16_t getBtnStatu(void);


#endif