#ifndef __LK_AW8695_H
#define __LK_AW8695_H
#include "lk_global.h"


#define AW8695_ADDRESS    0x5A
#define AW8695_CHIP_ID    0x95
#define AW8695_RSTN_PIN   13

/********************************************
 * Register List
 *******************************************/
#define AW8695_REG_SYSINTM       0x03
#define AW8695_REG_SYSCTRL       0x04

#define AW8695_REG_BASE_ADDRH    0x21
#define AW8695_REG_BASE_ADDRL    0x22
#define AW8695_REG_RAMADDRH      0x40
#define AW8695_REG_RAMADDRL      0x41
#define AW8695_REG_RAMDATA       0x42

#define AW8695_REG_WAVSEQ1       0x07
#define AW8695_REG_WAVSEQ2       0x08
#define AW8695_REG_WAVLOOP1      0x0f

#define AW8695_REG_DATDBG        0x39
#define AW8695_REG_BSTDBG4       0x3a
#define AW8695_REG_GO            0x05

#define AW8695_REG_GLB_STATE     0x46
/******************************************************
 * Register Detail
 *****************************************************/

#define AW8695_BIT_SYSCTRL_WORK_MODE_MASK        (~(1<<0))
#define AW8695_BIT_SYSCTRL_STANDBY               (1<<0)
#define AW8695_BIT_SYSCTRL_RAMINIT_MASK          (~(1<<5))
#define AW8695_BIT_SYSCTRL_RAMINIT_EN            (1<<5)
#define AW8695_BIT_SYSCTRL_RAMINIT_OFF           (0<<5)
#define AW8695_BIT_SYSCTRL_PLAY_MODE_MASK        (~(3<<2))
#define AW8695_BIT_SYSCTRL_PLAY_MODE_RAM         (0<<2)
#define AW8695_BIT_SYSCTRL_ACTIVE                (0<<0)
#define AW8695_BIT_SYSINTM_UVLO_MASK             (~(1<<5))
#define AW8695_BIT_SYSINTM_UVLO_OFF              (1<<5)

#define AW8695_BIT_BSTDBG4_BSTVOL_MASK              (~(31<<1))

#define AW8695_BIT_GO_MASK                       (~(1<<0))
#define AW8695_BIT_GO_ENABLE                     (1<<0)
#define AW8695_BIT_GO_DISABLE                    (0<<0)
// ram data
#define AW8695_RAM_BASE_ADDRH       0x08
#define AW8695_RAM_BASE_ADDRL       0x00


void aw8695_loop(void);

#endif


