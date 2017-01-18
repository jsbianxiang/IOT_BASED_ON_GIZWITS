/**
 ******************************************************************************
  * @file       app_save.c
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      Flash �洢����Դ�ļ�
  * @par        ����ƽ̨                                  
  *                  CC2530
  * @par        ����Ƶ��                                  
  *                  32MHz
  * @par        ����ƽ̨									                          
  * 				 IAR
 ******************************************************************************
  * @note
  * 1.�����Flash��ַ��ΧΪ0x0201-0x0FFF                						                      
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CC2530_FLASH_SAVE_H__
#define __CC2530_FLASH_SAVE_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"
#include "osal_nv.h"

/* Exported macro ------------------------------------------------------------*/
// �豸�洢��ַ
#define DEVICE_FIRSTWRITEKEY_ID                 (0x0202)
#define DEVICE_COORD_SAVE_ID                    (0x0210)
#define DEVICE_LIGHT_SAVE_ID                    (0x0210)
#define DEVICE_SOCKET_SAVE_ID                   (0x0210)
#define DEVICE_CURTAIN_SAVE_ID                  (0x0210)
#define DEVICE_DEVICE_TEMP_HUM_SENSOR_SAVE_ID   (0x0210)

//�豸ռ�ô洢�ռ��С
#define calSaveDataSize(data)                   ( sizeof(data) / sizeof(unsigned char) )

//���ݱ���ʹ�ܱ�־
#define USE_DATA_SAVE                           (0)

// ����д��������Կ
#define DEVICE_FIRST_WRIYE_KEY                  (0x5A)

// ���������豸�Ķ�ʱ������
#define SIMPLE_DEVICE_TIMER_NUM                 (2)

/* Exported types ------------------------------------------------------------*/
//�������ݴ�����
typedef void (*load_flase_handler)(void);

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
#if USE_DATA_SAVE
extern bool deviceSaveData( uint16 id, uint16 size, void *ctx );
extern bool deviceLoadData( uint16, uint16, void*, load_flase_handler );

#else
#define deviceSaveData(a,b,c) 
#define deviceLoadData(a,b,c,d)

#endif

#endif      /* __CC2530_FLASH_SAVE_H__ */

/**********************************END OF FILE*********************************/
