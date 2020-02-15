#include "lk_board.h"

void checkMotor(void)
{ 
	rt_kprintf("motor double run 30% \r\n");
	MOTOR_RUN_MAX1000(300);
}

MSH_CMD_EXPORT(checkMotor, k51 hardware motor check);
