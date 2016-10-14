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

/** ���ܵ������豸ID */
#define SmartLight_ProfileID           (0x0001)
/** ���ܿ��������豸ID */
#define SmartSwitch_ProfileID          (0x0002)
/** ���ܴ��������豸ID */
#define SmartCurtain_ProfileID         (0x0003)
/** ��ʪ�ȴ����������豸ID*/
#define SmartHumitureSensor_ProfileID  (0x0004)
// ��δ����������豸ID */
#define SmartRainSensor_ProfileID      (0x0005)
/** ���ܼҾ������豸ID */
#define SmartHome_ProfileID            (0x00FA)

#define SmartDevice_ProfileID SmartLight_ProfileID

/** �豸ID */
#define SmartDevice_DeviceID (0x0001)
/** �豸�汾�� */
#define SmartDevice_Version  (0x00)
#define SmartDevice_Flags    (0)
/** �ص����� */
#define SamrtDevice_ClustersNum (sizeof(zclSmartDevice_InClusterList)/sizeof(zclSmartDevice_InClusterList[0]))
#define SmartDevice_Comm_ClustersID  (0x0001)

#define SMART_DEVICE_TIME       (3000)

/** �������¼����� */
#define SMART_DEVICE_TIMER_EVEN (0x0002)

/** �豸�ϱ�ʱ�� */
#define DEVICE_TICK_TIME (3000)
/** �豸�ϱ��¼� */
//#define SmartDevice_Report_Enent (0x0008)

///** �����ƶ�ʱ����ʱʱ�� */
#define GIZWITS_TIMER_TIME (1)
///** �����ƶ�ʱ���¼� */
//#define Gizwits_Timer_Enent (0x0004)
//
///** �������¼�����ʱ�� */
#define GIZWITS_HANDLER_TIME (50)
///** �������¼����� */
//#define Gizwits_Handler_Enent (0x0002)
#define CLEAR_ZOMBIE_DEVICE_TIME (30000)

#define SmartDevice_InCoord  (1)
#define SmartDevice_InRouter (2)
#define SmartDevice_InEnd    (3)

#define SmartDevice_Status SmartDevice_InCoord

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
