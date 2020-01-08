/**************************************************************************//**
 * $Id: system_CMSDK.h,v   $
 *
 * @file     system_CMSDK.h
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Source File
 *           for the ME32F030 Device Series
 * @version  v 1.0 
 * @date     2017/08/08 
 * @author   Mesilicon
 *
 * @note
 * Copyright (C) 2017 Mesilicon. All rights reserved.
 *
 * @par

 ******************************************************************************/

#ifndef __SYSTEM_CMSDK_H
#define __SYSTEM_CMSDK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */
extern uint32_t MainClock;          /*!< Main Clock Frequency (Main Clock) */

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_CMSDK_H */
