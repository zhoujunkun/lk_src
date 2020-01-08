#include "drv2605.h"
void Haptics_RunAutoCal_LRA(void);
#define I2C_HAPTICS_ADDRESS 0x5A     

/**
*	Haptics_initI2C
*/
void Haptics_initI2C(uint8_t addr)
{
    iic_init(addr);
}

//使能
void Haptics_enable(void)
{
   HAPTICS_PIN_HIGTH();
}


void Haptics_init(void)
{
    Haptics_initI2C(I2C_HAPTICS_ADDRESS);
    Haptics_enable();
   //Set Defaults
  ii2_write(DRV2605_MODE, ACTIVE);    // Come out of STANDBY,Waveforms are fired by setting the GO bit in register 0x0C.
  ii2_write(DRV2605_WAVEFORMSEQ1, 0x01);
  ii2_write(DRV2605_WAVEFORMSEQ2, 0x00);
  ii2_write(DRV2605_ODT, 0x00);
  ii2_write(DRV2605_SPT, 0x00);
  ii2_write(DRV2605_SNT, 0x00);
  ii2_write(DRV2605_BRT, 0x00);
  ii2_write(0x13, 0x64);  //A2H Max Peak
  
  Haptics_RunAutoCal_LRA();

}



void Haptics_RunAutoCal_LRA(void)
{

  // Enable Amplifier
  
  // Run AutoCal LRA
  ii2_write(DRV2605_RATED_VOLTAGE, RatedVoltage_1p8); //额定电压
  ii2_write(DRV2605_OD_CLAMP, RatedVoltage_3p0);
  ii2_write(DRV2605_FEEDBACK_CONTROL, LRA_MODE | FBBrakeFactor_2x | LoopResponse_Medium);
  ii2_write(DRV2605_MODE, Auto_Calibration);
  ii2_write(DRV2605_AUTOCAL_MEMIF, AutoCalTime_500MS);
  ii2_write(DRV2605_GO, GO);
  /*
  //Poll GO every X seconds until ready
  while(I2C_ReadSingleByte(DRV2605_GO) == GO)
  Haptics_WaitUs(20000);
  
  // Read AutoCal Results
  RatedVoltage = I2C_ReadSingleByte(DRV2605_RATED_VOLTAGE);
  ODClamp = I2C_ReadSingleByte(DRV2605_OD_CLAMP);
  AutoCal_Comp = I2C_ReadSingleByte(DRV2605_AUTOCAL_COMP);
  AutoCal_BEMF = I2C_ReadSingleByte(DRV2605_AUTOCAL_BEMF);
  AutoCal_FB = I2C_ReadSingleByte(DRV2605_FEEDBACK_CONTROL);
  
  //Check if AutoCal was Successful
  AutoCal_Result = I2C_ReadSingleByte(DRV2605_STATUS);
  AutoCal_Result = (AutoCal_Result & 0x08) >> 3;
  
  //Haptics_WaitUs(10000);
  I2C_WriteSingleByte(DRV2605_MODE, ACTIVE);
  //osal_start_timerEx(Haptics_TaskID,AUTOCAL_LRA_EVENT,250);
  //	Haptics_DisableAmplifier();
  //Haptics_Disable();
  */

}