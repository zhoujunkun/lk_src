#include "lk_aw8695.h"
#include "iic.h"
int aw8695_ram_len=287;
char aw8695_ram_data[287] = {
0x85,0x08,0x05,0x09,0x1e,0x00,0x01,0x02,0x03,0x05,0x06,0x07,0x09,0x0a,0x0b,0x0c,
0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x18,0x19,0x1a,0x1a,0x1b,
0x1b,0x1c,0x1c,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1c,
0x1c,0x1b,0x1b,0x1a,0x1a,0x19,0x18,0x17,0x16,0x16,0x15,0x14,0x13,0x12,0x11,0x0f,
0x0e,0x0d,0x0c,0x0b,0x09,0x08,0x07,0x06,0x04,0x03,0x02,0x00,0x00,0xff,0xfd,0xfc,
0xfb,0xf9,0xf8,0xf7,0xf6,0xf4,0xf3,0xf2,0xf1,0xf0,0xef,0xed,0xec,0xec,0xeb,0xea,
0xe9,0xe8,0xe7,0xe7,0xe6,0xe5,0xe5,0xe4,0xe4,0xe4,0xe3,0xe3,0xe3,0xe3,0xe3,0xe3,
0xe3,0xe3,0xe3,0xe3,0xe3,0xe4,0xe4,0xe4,0xe5,0xe5,0xe6,0xe7,0xe7,0xe8,0xe9,0xea,
0xeb,0xec,0xed,0xee,0xef,0xf0,0xf1,0xf2,0xf3,0xf5,0xf6,0xf7,0xf8,0xfa,0xfb,0xfc,
0xfe,0xff,0x00,0x01,0x02,0x03,0x05,0x06,0x07,0x08,0x0a,0x0b,0x0c,0x0d,0x0f,0x10,
0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x17,0x18,0x19,0x1a,0x1a,0x1b,0x1b,0x1c,0x1c,
0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1c,0x1c,0x1b,0x1b,
0x1a,0x1a,0x19,0x18,0x17,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0f,0x0d,0x0c,
0x0b,0x0a,0x08,0x07,0x06,0x05,0x03,0x02,0x01,0x00,0xff,0xfe,0xfc,0xfb,0xfa,0xf8,
0xf7,0xf6,0xf5,0xf3,0xf2,0xf1,0xf0,0xef,0xee,0xed,0xec,0xeb,0xea,0xe9,0xe8,0xe7,
0xe7,0xe6,0xe5,0xe5,0xe4,0xe4,0xe4,0xe3,0xe3,0xe3,0xe3,0xe3,0xe3,0xe3,0xe3,0xe3,
0xe3,0xe3,0xe4,0xe4,0xe4,0xe5,0xe5,0xe6,0xe7,0xe7,0xe8,0xe9,0xea,0xeb,0xec,0xed,
0xee,0xef,0xf0,0xf1,0xf2,0xf3,0xf4,0xf6,0xf7,0xf8,0xf9,0xfb,0xfc,0xfd,0xff,
};

bool test_write=false,test_read=false;
//aw8695 write byte
int aw8695_i2c_write(unsigned char ucRegAddress, char cValue)
{
  iic_init(AW8695_ADDRESS); // start transmission to device 
   test_write = ii2_write(ucRegAddress,(uint8_t *)&cValue,1);
}


/* Try to read 1 byte from the AW8695 register at 'regAddress'.
 * The read value is stored in *pcValue
 * Returns 0 on success or -1 on failure.
 */
int aw8695_i2c_read(unsigned char ucRegAddress, unsigned char* pcValue)
{
  test_read = ii2_read(ucRegAddress,(uint8_t *)pcValue,1);
}


//aw8695 write bits
int aw8695_i2c_write_bits(unsigned char addr, unsigned char mask, unsigned char value)
{
    unsigned char reg_val;

    aw8695_i2c_read(addr, &reg_val);
    reg_val &= mask;
    reg_val |= value;
    aw8695_i2c_write(addr, reg_val);
}


//hw init
 unsigned  char reg_val_z = 0;
int aw8695_hw_init(void)
{
    int ret = 0;
   

    HAL_GPIO_WritePin(AW8695_RSTN__GPIO_Port, AW8695_RSTN__Pin, GPIO_PIN_RESET);
    HAL_Delay(1);//1ms
    HAL_GPIO_WritePin(AW8695_RSTN__GPIO_Port, AW8695_RSTN__Pin, GPIO_PIN_SET);
    HAL_Delay(5);//5ms
     while(1) {aw8695_i2c_read(0x00, &reg_val_z);}
    if(aw8695_i2c_read(0x00, &reg_val_z) == 0)
		{
        ret = 0;
    } else {

        ret = 1;
    }

    return ret;  
}

//haptic start play
int aw8695_haptic_play(void)
{
    int ret = 0;
    unsigned int wav_index = 0x01;
    unsigned char wav_loop = 0xf0;
    unsigned char bst_vol = 0x11;
    unsigned char gain = 0x80;

    /* Seq 1 */
    aw8695_i2c_write(AW8695_REG_WAVSEQ1, wav_index);
    aw8695_i2c_write(AW8695_REG_WAVSEQ2, 0x00);

    /* Loop 1 */
    aw8695_i2c_write(AW8695_REG_WAVLOOP1, wav_loop);

    /* Bst Vol */
    aw8695_i2c_write_bits(AW8695_REG_BSTDBG4, AW8695_BIT_BSTDBG4_BSTVOL_MASK, (bst_vol<<1));

    /* Gain */
    aw8695_i2c_write(AW8695_REG_DATDBG, gain);

    /* Play Mode */
    aw8695_i2c_write_bits(AW8695_REG_SYSCTRL, AW8695_BIT_SYSCTRL_PLAY_MODE_MASK, AW8695_BIT_SYSCTRL_PLAY_MODE_RAM);

    /* Haptic Play */
    aw8695_i2c_write_bits(AW8695_REG_SYSCTRL, AW8695_BIT_SYSCTRL_WORK_MODE_MASK, AW8695_BIT_SYSCTRL_ACTIVE);
    aw8695_i2c_write_bits(AW8695_REG_GO, AW8695_BIT_GO_MASK, AW8695_BIT_GO_ENABLE);

    return ret;
}


int aw8695_haptic_stop_delay(void)
{
  unsigned char reg_val = 0;
  unsigned int cnt = 100;

  while (cnt--) {
    aw8695_i2c_read(AW8695_REG_GLB_STATE, &reg_val);
   // Serial.print("wait for standby, reg glb_state=0x");
   // Serial.println(reg_val,HEX);
    if ((reg_val & 0x0f) == 0x00)
      return 0;
    HAL_Delay(2);
  }
 // Serial.print("do not enter standby automatically\n");

  return 0;
}

//haptic init
int aw8695_haptic_init(void)
{
    int ret = 0;

    aw8695_i2c_write_bits(AW8695_REG_SYSCTRL, AW8695_BIT_SYSCTRL_WORK_MODE_MASK, AW8695_BIT_SYSCTRL_STANDBY);

    return ret;
}

//ram init
int aw8695_ram_init(void)
{
    int ret = 0;
    int i = 0;

    /* RAMINIT Enable */
    aw8695_i2c_write_bits(AW8695_REG_SYSCTRL, AW8695_BIT_SYSCTRL_RAMINIT_MASK, AW8695_BIT_SYSCTRL_RAMINIT_EN);

    /* RAM Base Addr */
    aw8695_i2c_write(AW8695_REG_BASE_ADDRH, AW8695_RAM_BASE_ADDRH);
    aw8695_i2c_write(AW8695_REG_BASE_ADDRL, AW8695_RAM_BASE_ADDRL);

    /* ram */
    aw8695_i2c_write(AW8695_REG_RAMADDRH, AW8695_RAM_BASE_ADDRH);
    aw8695_i2c_write(AW8695_REG_RAMADDRL, AW8695_RAM_BASE_ADDRL);
    for(i=0; i<aw8695_ram_len; i++) {
        aw8695_i2c_write(AW8695_REG_RAMDATA, aw8695_ram_data[i]);
    }

    /* RAMINIT Disable */
    aw8695_i2c_write_bits(AW8695_REG_SYSCTRL, AW8695_BIT_SYSCTRL_RAMINIT_MASK, AW8695_BIT_SYSCTRL_RAMINIT_OFF);

    return ret;
}

//haptic stop
int aw8695_haptic_stop(void)
{
    aw8695_i2c_write_bits(AW8695_REG_GO, AW8695_BIT_GO_MASK, AW8695_BIT_GO_DISABLE);
    aw8695_haptic_stop_delay();
    aw8695_i2c_write_bits(AW8695_REG_SYSINTM, AW8695_BIT_SYSINTM_UVLO_MASK, AW8695_BIT_SYSINTM_UVLO_OFF);
    aw8695_i2c_write_bits(AW8695_REG_SYSCTRL, AW8695_BIT_SYSCTRL_WORK_MODE_MASK, AW8695_BIT_SYSCTRL_STANDBY);
    
    return 0;
}


void aw8695_init(void)
{
   
}


void aw8695_loop(void)
{
  aw8695_hw_init();

  aw8695_haptic_init();
  aw8695_ram_init();

  while(1) {
     
      aw8695_haptic_play();
      HAL_Delay(2000);
    
      aw8695_haptic_stop();
      HAL_Delay(1000);
  }

}