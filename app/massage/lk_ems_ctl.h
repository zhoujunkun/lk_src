#ifndef __LK_EMS_CTL_H
#define __LK_EMS_CTL_H
#include "lk_global.h"


 void emsA_to_B_PNAlter_P(uint32_t pulse);  ////   A_u->B_d   B_u->A_d  
 void emsA_to_B_PNAlter_N(uint32_t pulse);  ///  B_u->A_d	A_u->B_d
 void emsA_to_B_Single_P(uint32_t pulse);  //// A_u->B_d  
 void emsA_to_B_Single_N(uint32_t pulse); ///  B_u->A_d
 void emsA_to_B_Double(uint32_t pulse);  ///  四管同开

 void ems_io_init(void);



#endif

