#include "lk_ems_ctl.h"

#include "ioconfig.h"
#include "CMSDK_CM0.h"


#define ems_AU_IO_high()         PB->SET_b.SET3=1
#define ems_AU_IO_low()          PB->SET_b.SET3=0
#define ems_AD_IO_high()         PA->SET_b.SET15=1
#define ems_AD_IO_low()   			 PA->SET_b.SET15=0 	

#define ems_BU_IO_high()         PB->SET_b.SET5=1
#define ems_BU_IO_low()          PB->SET_b.SET5=0
#define ems_BD_IO_high()         PB->SET_b.SET4=1
#define ems_BD_IO_low()          PB->SET_b.SET4=0


#define ems_CU_IO_high()         PB->SET_b.SET6=1
#define ems_CU_IO_low()          PB->SET_b.SET6=0
#define ems_CD_IO_high()         PB->SET_b.SET7=1 
#define ems_CD_IO_low()          PB->SET_b.SET7=0




#define ems_DU_IO_high()        PB->SET_b.SET8=1
#define ems_DU_IO_low()         PB->SET_b.SET8=0
#define ems_DD_IO_high()        PB->SET_b.SET9=1
#define ems_DD_IO_low()         PB->SET_b.SET9=0
#define DeadZonePulse 5

void delayus(uint32_t us)
{
  for(int i=0;i<1000;i++)
  {
	   for(int i=0;i<1000;i++)
	  {
	   
		}
	}

}



void ems_io_init(void)
{	
	//config io function
	PB_3_INIT(PB_3_GPIO);
	//remove pullup
	PB_3_PULLUP(IOCONFIG_DISABLE);
	//set GPIO PB_9 as output pin 
	PB->DIR_b.DIR3=1;    
  PB->SET_b.SET3=0;

	//config io function
	PA_15_INIT(PB_15_GPIO);
	//remove pullup
	PB_15_PULLUP(IOCONFIG_DISABLE);
	//set GPIO PB_9 as output pin 
	PA->DIR_b.DIR15=1;    
  PA->SET_b.SET15=0;	
}



void emsA_to_B_PNAlter_P(uint32_t pulse)  ////   A_u->B_d   B_u->A_d  
{
	ems_AU_IO_high();
	ems_BD_IO_high();
	delayus(pulse);
	ems_AU_IO_low();
	ems_BD_IO_low();

	delayus(DeadZonePulse);
	
	ems_AD_IO_high();
	ems_BU_IO_high();
	delayus(pulse);
	ems_AD_IO_low();
	ems_BU_IO_low();

}

void emsA_to_B_PNAlter_N(uint32_t pulse)  ///  B_u->A_d	A_u->B_d
{


}

void emsA_to_B_Single_P(uint32_t pulse)  //// A_u->B_d  

{



}

void emsA_to_B_Single_N(uint32_t pulse) ///  B_u->A_d

{




}


