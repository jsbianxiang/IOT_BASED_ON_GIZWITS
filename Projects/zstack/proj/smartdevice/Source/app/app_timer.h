/**
 ******************************************************************************
  * @file       app_timer.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      ��ʱ��Ӧ��ͷ�ļ�
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
#ifndef __APP_USER_TIMER_H__
#define __APP_USER_TIMER_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"

/* Exported macro ------------------------------------------------------------*/
//// ��ʱ����������
//#define TIMER_COUNTDOWN_TYPE (0xA1)
//#define TIMER_GENERAL_TYPE   (0xA2)
//// ��ʱ������ģʽ
//#define TIMER_SIGNAL_MODE    (0xF1)
//#define TIMER_CUSTOM_MODE    (0xF2)

/* Exported types ------------------------------------------------------------*/
// ��ʱ������
typedef enum
{
    TIMER_COUNTDOWN_TYPE = 0xA1,
    TIMER_GENERAL_TYPE   = 0xA2,
}TIMER_TYPE;

// ��ʱ������ģʽ
typedef enum
{
    TIMER_SLEEP_MODE  = 0xB0,
    TIMER_SIGNAL_MODE = 0xB1,
    TIMER_CUSTOM_MODE = 0xB2,
}TIMER_MODE;

// ��ʱ���Զ��幤������
typedef struct
{
    uint8 status    : 1;
    uint8 monday    : 1;
    uint8 tuesday   : 1;
    uint8 wednesday : 1;
    uint8 thursday  : 1;
    uint8 friday    : 1;
    uint8 saturday  : 1;
    uint8 sunday    : 1;
}TIMER_CUSTOM_PARAM;

// ��ʱ������ʱ��
typedef struct
{
    uint8 start_hour;
    uint8 start_minute;
    uint8 stop_hour;
    uint8 stop_minute;
}TIMER_WOKRING_TIME;

// �豸��ʱ������
typedef struct
{
    TIMER_TYPE type;
    TIMER_MODE mode;
    TIMER_CUSTOM_PARAM custom;
    TIMER_WOKRING_TIME time;
    uint8 device_status;
}DEVICE_TIMER;

// �豸״̬�ź�
typedef enum
{
    DEVICE_START_SIGNAL,
    DEVICE_STOP_SIGNAL,
    DEVICE_KEEP_SIGNAL,
}DEVICE_STATUS_SIGNAL;

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern DEVICE_STATUS_SIGNAL device_timer_check( DEVICE_TIMER timer );

#endif      /* __APP_USER_TIMER_H__ */

/**********************************END OF FILE*********************************/
