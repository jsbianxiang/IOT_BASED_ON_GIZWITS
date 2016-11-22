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
#include "OSAL_Nv.h"
#include "app_timer.h" 

/* Exported macro ------------------------------------------------------------*/
// �豸�洢��ַ
#define DEVICE_FIRSTWRITEKEY_ID                 (0x0202)
#define DEVICE_COORD_SAVE_ID                    (0x0210)
#define DEVICE_LIGHT_SAVE_ID                    (0x0210)
#define DEVICE_SOCKET_SAVE_ID                   (0x0210)
#define DEVICE_CURTAIN_SAVE_ID                  (0x0210)
#define DEVICE_DEVICE_TEMP_HUM_SENSOR_SAVE_ID   (0x0210)
//�豸ռ�ô洢�ռ��С
#define Cal_DataSize(data)                      ( sizeof(data) / sizeof(unsigned char) )
//#define DEVICE_COORD_DATA_SIZE                  (Cal_DataSize(DEVICE_COORD_SAVE_DATA))
//#define DEVICE_DEVICE_TEMP_HUM_SENSOR_DATA_SIZE (Cal_DataSize(DEVICE_TEMP_HUM_SENSOR_SAVE_DATA))
//�豸ID
//#define DEVICE_COORD_ID                         (0x00)
//#define DEVICE_LIGHT_ID                         (0x01)
//#define DEVICE_SOCKET_ID                        (0x02)
//#define DEVICE_CURTAIN_ID                       (0x03)
//#define DEVICE_DEVICE_TEMP_HUM_SENSOR_ID        (0x04)
// ����д��������Կ
#define DEVICE_FIRST_WRIYE_KEY (0x5A)
// ���������豸�Ķ�ʱ������
#define SIMPLE_DEVICE_TIMER_NUM (2)
/* Exported types ------------------------------------------------------------*/
// COORD �豸�洢����
typedef struct
{
    uint8 firstwritekey;
}DEVICE_BASE_SAVE_DATA;

// ���豸�洢����
typedef struct
{
    struct
    {
        uint8 now;
        uint8 last;
    }status;
    
    DEVICE_TIMER timer[SIMPLE_DEVICE_TIMER_NUM]; 
}SIMPLE_DEVICE_SAVE_DATA;

// ���豸�洢����
typedef struct
{
    uint8 device_status;
    
    struct
    {
        uint8 mode;
        uint8 active_data;
    }smart;
    
    DEVICE_TIMER normal_timer;
    DEVICE_TIMER cntdown_timer;  
}DEVICE_CURTAIN_SAVE_DATA;

//�豸�������� 
//typedef DEVICE_BASE_SAVE_DATA   DEVICE_COORD_SAVE_DATA;
//typedef DEVICE_BASE_SAVE_DATA   DEVICE_TEMP_HUM_SENSOR_SAVE_DATA;
//typedef SIMPLE_DEVICE_SAVE_DATA DEVICE_LIGHT_SAVE_DATA;
//typedef SIMPLE_DEVICE_SAVE_DATA DEVICE_SOCKET_SAVE_DATA;

typedef void (*load_flase_handler)(void);

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
//extern void Rst_DeviceSaveData( uint8 );
extern void Device_FirstWriteKey_Init( void );
extern bool Device_FirstWrite_Check( uint16 id, uint16 size );
extern bool Device_Load_LastData( uint16, uint16, void*, load_flase_handler );

#endif      /* __CC2530_FLASH_SAVE_H__ */

/**********************************END OF FILE*********************************/
