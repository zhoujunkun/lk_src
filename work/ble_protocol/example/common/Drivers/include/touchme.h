/*****************************************************************************
 *   itouch.h:  Header file for touch application
 *
******************************************************************************/
#include "CMSDK_CM0.h"
#define TOUCH_KEYS_NUMBER 1 //Number of touch keys applied in application
#define TOUCH_UPDATE_CYCLE_NUMBER 500 //Ref update time, about 1S
typedef struct {
	uint32_t stime; //miniseconds X 10^9
	uint32_t kr; //1386*Rc/10K, example select Rc 80K, KR=1386*8
	uint32_t status;
	uint32_t history;
	uint16_t chnval[TOUCH_KEYS_NUMBER];
	uint16_t chnmaxval[TOUCH_KEYS_NUMBER];
	uint16_t ref[TOUCH_KEYS_NUMBER];
	uint16_t threhold[TOUCH_KEYS_NUMBER];
	uint16_t cap[TOUCH_KEYS_NUMBER];
	uint16_t keysensity[TOUCH_KEYS_NUMBER];
	uint8_t mapping[22];		
	uint16_t sensity; //1~1000 related 0.01 to 10pf
	uint16_t sensitysel; //0, select varible sensity; 1, select keysensity
	uint16_t noise; //system noise range, less 3
	uint16_t lastchn;
	uint16_t lastval;
	uint16_t hysteresis;
	uint16_t index;
	uint16_t counter;
	
}touch;

void itouch_init(uint32_t keys);

void itouch_update(void);
