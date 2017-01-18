/**
 ******************************************************************************
  * @file       smart_device.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      smart_device ͷ�ļ�
  * @par        ����ƽ̨                                  
  *                  CC2530
  * @par        ����Ƶ��                                  
  *                  32MHz
  * @par        ����ƽ̨									                          
  * 				 IAR
 ******************************************************************************
  * @note
  * 1.XXXXX                  						                      
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SMART_DEVICE_H__
#define __SMART_DEVICE_H__

/* Includes ------------------------------------------------------------------*/
#include "ZComDef.h"

/* Exported macro ------------------------------------------------------------*/
/** �豸�˵� */
#define SmartDevice_EndPoint   (20)
/** �豸ID */
#define SmartDevice_DeviceID (0x0001)
/** �豸�汾�� */
#define SmartDevice_Version  (0x00)
#define SmartDevice_Flags    (0)

//#define SmartDevice_InCoord  (1)
//#define SmartDevice_InRouter (2)
//#define SmartDevice_InEnd    (3)
//
//#define SmartDevice_Status SmartDevice_InCoord

/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void SmartDevice_Init( byte task_id );

extern uint16 SamrtDevice_ProcessEven( uint8 task_id, uint16 events );
#endif      /* __SMART_LIGHT_H__ */

/**********************************END OF FILE*********************************/
