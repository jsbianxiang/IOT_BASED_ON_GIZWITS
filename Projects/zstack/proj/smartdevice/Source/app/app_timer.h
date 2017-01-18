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
//typedef enum
//{
//    TIMER_COUNTDOWN_TYPE = 0xA1,
//    TIMER_GENERAL_TYPE   = 0xA2,
//}TIMER_TYPE;

// ��ʱ������ģʽ
typedef enum
{
	TIMER_SLEEP_MODE = 0x00,
	TIMER_DOWNCNT_MODE_WAIT = 0xB1,
	TIMER_PERIOD_MODE_WAIT = 0xB2,
	TIMER_CUSTOM_MODE_WAIT = 0xB3,
	TIMER_DOWNCNT_MODE,
	TIMER_PERIOD_MODE ,
	TIMER_CUSTOM_MODE ,
}TIMER_MODE;

// ��ʱ���Զ��幤������
// ��ʱ���Զ��幤������
typedef struct
{
	const uint8 res : 1;
	uint8 monday     : 1;
	uint8 tuesday    : 1;
	uint8 wednesday  : 1;
	uint8 thursday   : 1;
	uint8 friday     : 1;
	uint8 saturday   : 1;
	uint8 sunday     : 1;
}TIMER_CUSTOM_PARAM;

// ��ʱ������ʱ��
typedef struct
{
	uint16 start;
	uint16 end;
}TIMER_WOKRING_TIME;

// ��ʱ������ʱ��
typedef struct
{
	uint8 start;
	uint8 end;
}TIMER_WOKRING_STATUS;

// �豸��ʱ������
typedef struct
{
	TIMER_MODE mode;
	TIMER_CUSTOM_PARAM custom;
	TIMER_WOKRING_TIME time;
	TIMER_WOKRING_STATUS status;
}DEVICE_TIMER;

// �豸״̬�ź�
typedef enum
{
    DEVICE_START_SIGNAL,
    DEVICE_STOP_SIGNAL,
    DEVICE_KEEP_SIGNAL,
}DEVICE_STATUS_SIGNAL;

// �豸���ƺ���
typedef void (*device_timer_func)(uint8);

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern bool device_timer_handler(DEVICE_TIMER*, device_timer_func);

#endif      /* __APP_USER_TIMER_H__ */

/**********************************END OF FILE*********************************/
