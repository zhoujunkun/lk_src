#include "lk_board.h"

extern void enable_433m(void);
extern uint8_t upCnts,downCnts,rightCnts,leftCnts,menuCnts;
void check433(void)
{
    rt_kprintf("433M start working...\r\n");
    enable_433m();
    while(1)
    {
        rt_thread_mdelay(100);
        rt_kprintf("upCnts=%d ,downCnts=%d ,rightCnts=%d ,leftCnts=%d ,menuCnts=%d \r\n",upCnts,downCnts,rightCnts,leftCnts,menuCnts);

    }
}
MSH_CMD_EXPORT(check433,k51 433M check);