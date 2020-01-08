#ifndef __LK_KEY_H
#define __LK_KEY_H
#include "lk_button.h"


typedef enum {KEY0=0,KEY1,KEY2,KEY_MAX,KEY_NONE}_btnUser_t;
void lk_key_init(void);
_btnUser_t lk_key_process(void);
#endif
