#include "tm8211.h"

#define tm8211_WSHigh()     HAL_GPIO_WritePin(GPIOA, TM8211_WS_Pin, GPIO_PIN_SET)
#define tm8211_WSLow()      HAL_GPIO_WritePin(GPIOA, TM8211_WS_Pin, GPIO_PIN_RESET)

#define tm8211_clk_high()       HAL_GPIO_WritePin(GPIOA, TM8211_BCK_Pin, GPIO_PIN_SET)
#define tm8211_clk_low()        HAL_GPIO_WritePin(GPIOA, TM8211_BCK_Pin, GPIO_PIN_RESET)

#define tm8211_idle() tm8211_clk_low()
#define tm8211_din_high()       HAL_GPIO_WritePin(GPIOA, TM8211_DIN_Pin, GPIO_PIN_SET)
#define tm8211_din_low()        HAL_GPIO_WritePin(GPIOA, TM8211_DIN_Pin, GPIO_PIN_RESET)
#define tm8211_din_idle()       tm8211_din_low()  
uint8_t test=0;

#define DELAY_TIME   500

//======================================================
int *intR;
int *intL;

//======================================================
 int tab16[]={

0, 		   //*32767
1029, 
2057,
3084,
4107,
5126, 
6140, 
7148, 
8149, 
9142, 
10126, 
11099, 
12062, 
13013, 
13952, 
14876, 
15786, 
16680, 
17557, 
18418, 
19260, 
20083, 
20886, 
21669, 
22431,
23170, 
23886, 
24579, 
25247, 
25891, 
26509, 
27101, 
27666, 
28204, 
28714, 
29196, 
29648, 
30072, 
30466, 
30830, 
31163, 
31466, 
31738, 
31978, 
32187, 
32364, 
32509, 
32622, 
32702, 
32751, 
32767, 
32751, 
32702, 
32622, 
32509, 
32364, 
32187,
31978,
31738, 
31466, 
31163, 
30830, 
30466, 
30072, 
29648, 
29196, 
28714, 
28204, 
27666, 
27101, 
26509, 
25891, 
25247, 
24579, 
23886, 
23170, 
22431, 
21669, 
20886, 
20083, 
19260, 
18418, 
17557, 
16680, 
15786, 
14876, 
13952, 
13013, 
12062, 
11099, 
10126, 
9142,
8149, 
7148, 
6140, 
5126, 
4107, 
3084, 
2057, 
1029, 
0 	,
-1029, 
-2057, 
-3084, 
-4107, 
-5126, 
-6140, 
-7148, 
-8149, 
-9142, 
-10126, 
-11099, 
-12062, 
-13013, 
-13952, 
-14876, 
-15786, 
-16680, 
-17557, 
-18418, 
-19260, 
-20083, 
-20886, 
-21669, 
-22431, 
-23170, 
-23886, 
-24579, 
-25247, 
-25891, 
-26509, 
-27101, 
-27666, 
-28204, 
-28714, 
-29196, 
-29648, 
-30072, 
-30466, 
-30830, 
-31163, 
-31466, 
-31738, 
-31978, 
-32187, 
-32364, 
-32509, 
-32622, 
-32702, 
-32751, 
-32767, 
-32751, 
-32702, 
-32622,
-32509, 
-32364, 
-32187, 
-31978, 
-31738, 
-31466, 
-31163, 
-30830, 
-30466, 
-30072, 
-29648, 
-29196, 
-28714, 
-28204, 
-27666, 
-27101, 
-26509, 
-25891, 
-25247, 
-24579, 
-23886, 
-23170, 
-22431, 
-21669, 
-20886, 
-20083, 
-19260, 
-18418, 
-17557, 
-16680, 
-15786, 
-14876, 
-13952, 
-13013, 
-12062, 
-11099, 
-10126, 
-9142, 
-8149, 
-7148, 
-6140, 
-5126, 
-4107, 
-3084, 
-2057, 
-1029 	
};




#if 0

void tm8211_write(uint16_t data)
{    
    for(int i=15;i>=0;i--)
    {
        tm8211_clk_low();
		  	test =data>>i;
        if(test&0x01)
        {
            tm8211_din_high();
        }
        else 
				{
					tm8211_din_low();
				}
//				delay(DELAY_TIME);
        tm8211_clk_high();
//				delay(DELAY_TIME);
//				tm8211_clk_low();
//				delay(DELAY_TIME);
    }
//		tm8211_idle();
//		tm8211_din_idle();
}
#endif
#if 1
void tm8211_write(int temp)
{    
    tm8211_clk_low();
  	tm8211_din_low();
    for(int i=0;i<16;i++)
    {
        tm8211_clk_low();
        if(temp&0x8000)
        {
            tm8211_din_high();
        }
        else 
				{
					tm8211_din_low();
				}
        tm8211_clk_high();
        temp<<=1;
    }
}
#endif


#if 0
uint16_t cntTime=0,cntTime2=0xff;


void tm8211_test(void)
{
	tm8211_selectLow(); 
	cntTime+=0xff;
	cntTime2-=1;
  tm8211_write(cntTime);
	if(cntTime >= 0xffff) cntTime =0;
	if(cntTime2 <= 0) cntTime2 =0x0f;
	tm8211_selectHigh();
		HAL_Delay(1);
	tm8211_write(0xffff);

	tm8211_selectLow();


}

#endif

uint8_t phase =0;
void tm8211_init(void)
{
   tm8211_WSLow();
}

uint16_t cnts=0;
int j1,j2;
void tm8211_test(void)
{
  while(1)
	{
		intL=tab16;
		j2=0;
		for(j1=0;j1<200;j1++)
		{		
				intL=tab16+j1;
				tm8211_WSHigh();				 //LCH输出
				//tm8211_write((*intL));  
				tm8211_write(-32751);  
				j2=(j1+phase)%200;
			
				intR=tab16+j2;
				tm8211_WSLow();				 //RCH输出
				tm8211_write(*(intR));
		
		}
	  phase++;
	  if(phase>=200)
	  phase=0;
	
	}
}