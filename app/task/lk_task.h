#ifndef __LK_TASK_H
#define __LK_TASK_H
#include "lk_board.h"

void task_1ms_callBack(void);
void lk_task_init(void);


void Delay_us(u32 nus);
void Delay_ms(u16 nms);
void Delay_sec(u16 sec);
#endif
