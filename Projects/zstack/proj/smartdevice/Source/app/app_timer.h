/**
 ******************************************************************************
  * @file       app_timer.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      ds1302 ����ͷ�ļ�
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
/* Exported types ------------------------------------------------------------*/
// �豸��ʱ������ģʽ
typedef struct
{
    uint16 TIMER_Working_Once      : 1;
    uint16 TIMER_Working_EveryDay  : 1;
    uint16 TIMER_Working_Custom    : 1;
    uint16 TIMER_Working_Monday    : 1;
    uint16 TIMER_Working_Tuesday   : 1;
    uint16 TIMER_Working_Wednesday : 1;
    uint16 TIMER_Working_Thursday  : 1;
    uint16 TIMER_Working_Friday    : 1;
    uint16 TIMER_Working_Saturday  : 1;
    uint16 TIMER_Working_Sunday    : 1;
}DEVICE_TIMER_MODE;
// �豸��ʱ������
typedef struct
{
    // res
    uint8 timer_type;
    // use
    DEVICE_TIMER_MODE mode;
    uint8 device_status;
    uint8 statr_hour;
    uint8 start_minute;
    uint8 stop_hour;
    uint8 stop_minute;
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

#endif      /* __APP_USER_TIMER_H__ */

/**********************************END OF FILE*********************************/
