/**
  ******************************************************************************
  * @file    usbh_stdreq.h
  * @author  Artery Technology
  * @version V1.0.4
  * @date    2019-05-27
  * @brief   Header file for usbh_stdreq.c
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, ARTERYTEK SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2018 ArteryTek</center></h2>
  ******************************************************************************
  */   

/* Define to prevent recursive  ----------------------------------------------*/
#ifndef __USBH_STDREQ_H
#define __USBH_STDREQ_H

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"
#include "usb_hcd.h"
#include "usbh_core.h"
#include "usbh_def.h"

/** @addtogroup USBH_LIB
  * @{
  */

/** @addtogroup USBH_LIB_CORE
* @{
*/
  
/** @defgroup USBH_STDREQ
  * @brief This file is the 
  * @{
  */ 


/** @defgroup USBH_STDREQ_Exported_Defines
  * @{
  */
/*Standard Feature Selector for clear feature command*/
#define USB_FEATURE_SELECTOR_ENDPOINT         0X00
#define USB_FEATURE_SELECTOR_DEVICE           0X01


#define USB_INTERFACE_DESC_TYPE               0x04
#define USB_ENDPOINT_DESC_TYPE                0x05
//#define USB_INTERFACE_DESC_SIZE               0x09


#define USB_HOST_HID_CLASS                    0x03

/**
  * @}
  */ 


/** @defgroup USBH_STDREQ_Exported_Types
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USBH_STDREQ_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USBH_STDREQ_Exported_Variables
  * @{
  */ 
extern uint8_t USB_HOST_CfgDesc[512];
/**
  * @}
  */ 

/** @defgroup USBH_STDREQ_Exported_FunctionsPrototype
  * @{
  */
USB_HOST_Status USB_HOST_GetDescriptor(USB_OTG_CORE_HANDLE *pusbdev, 
                               USB_HOST           *phost,                                
                               uint8_t  req_type,
                               uint16_t value_idx, 
                               uint8_t* buff, 
                               uint16_t length );

USB_HOST_Status USB_HOST_Get_DevDesc(USB_OTG_CORE_HANDLE *pusbdev,
                             USB_HOST *phost,
                             uint8_t length);

USB_HOST_Status USB_HOST_Get_StringDesc(USB_OTG_CORE_HANDLE *pusbdev, 
                                USB_HOST           *phost,                                 
                                uint8_t string_index, 
                                uint8_t *buff, 
                                uint16_t length);

USB_HOST_Status USB_HOST_SetCfg(USB_OTG_CORE_HANDLE *pusbdev, 
                        USB_HOST *phost,
                        uint16_t configuration_value);

USB_HOST_Status USB_HOST_Get_CfgDesc(USB_OTG_CORE_HANDLE *pusbdev,
                             USB_HOST           *phost,                                 
                             uint16_t length);

USB_HOST_Status USB_HOST_SetAddress(USB_OTG_CORE_HANDLE *pusbdev, 
                            USB_HOST           *phost,                             
                            uint8_t DeviceAddress);

USB_HOST_Status USB_HOST_ClrFeature(USB_OTG_CORE_HANDLE *pusbdev,
                            USB_HOST           *phost,                             
                            uint8_t ept_num, uint8_t hc_num); 

USB_HOST_Status USB_HOST_SetInterface(USB_OTG_CORE_HANDLE *pusbdev, 
                        USB_HOST *phost,
                        uint8_t ept_num, uint8_t altSetting);

USB_HOST_Status USB_HOST_Issue_ClrFeature(USB_OTG_CORE_HANDLE *pusbdev, 
                                  USB_HOST           *phost, 
                                  uint8_t ept_num);

USBH_DescriptorHeader      *USB_HOST_GetNextDesc (uint8_t   *pbuf, 
                                                  uint16_t  *ptr);

USB_HOST_Status USB_HOST_SetDeviceFeature(USB_OTG_CORE_HANDLE *pusbdev, 
                                  USB_HOST *phost,
                                  uint8_t FeatureSelector, uint16_t wIndex);

USB_HOST_Status USB_HOST_ClearDeviceFeature(USB_OTG_CORE_HANDLE *pusbdev, 
                                    USB_HOST *phost,
                                    uint8_t FeatureSelector, uint16_t wIndex);

/**
  * @}
  */ 

#endif /* __USBH_STDREQ_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
* @}
*/ 

/************************ (C) COPYRIGHT Artery Technology *****END OF FILE****/

