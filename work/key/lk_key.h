#ifndef __LK_KEY_H
#define __LK_KEY_H

typedef struct 
{
  uint8_t (*readStatu)(void); // 读取按键状态
}lk_keyHandle_t;



#endif
