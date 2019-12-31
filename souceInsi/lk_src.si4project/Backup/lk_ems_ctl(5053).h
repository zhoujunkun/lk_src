#ifndef __LK_EMS_CTL_H
#define __LK_EMS_CTL_H
#include "lk_global.h"


extern void emsA_to_B_PNAlter_P(u32 pulse);  ////   A_u->B_d   B_u->A_d  
extern void emsA_to_B_PNAlter_N(u32 pulse);  ///  B_u->A_d	A_u->B_d
extern void emsA_to_B_Single_P(u32 pulse);  //// A_u->B_d  
extern void emsA_to_B_Single_N(u32 pulse); ///  B_u->A_d
extern void emsA_to_B_Double(u32 pulse);  ///  四管同开




#endif