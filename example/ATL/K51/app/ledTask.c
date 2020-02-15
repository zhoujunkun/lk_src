#include "lk_board.h"


void checkled(void)
{
    
    while(1)
    {
        LED_YELLOW_ON();
        LED_BLUE_ON();
        rt_thread_mdelay(500);
        LED_YELLOW_OFF();
        LED_BLUE_OFF();  
        rt_thread_mdelay(500); 
        rt_kprintf("led shake 1HZ\r\n");
    }
}
MSH_CMD_EXPORT(checkled, k51 led check);



