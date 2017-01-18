/**
 ******************************************************************************
  * @file       app_time.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      ʱ��Ӧ��ͷ�ļ�
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
#ifndef __APP_USER_TIME_H__
#define __APP_USER_TIME_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"
#include "app_save.h"
#include "myprotocol.h"

/* Exported macro ------------------------------------------------------------*/
#define deviceUpdateNTPTime() MyprotocolSendData(NULL,NULL,createDeviceGetNTPPacket,MyprotocolD2WSendData)

/* Exported types ------------------------------------------------------------*/
/**
 *******************************************************************************
 * @brief       �û�ʱ��ṹ��
 * @note        ���Ը���Ӳ�������ݴ���˳�������
 *******************************************************************************
 */
typedef struct
{
    uint8 second;
    uint8 minute;
    uint8 hour;
    uint8 day;
    uint8 month;
    uint8 week;
    uint16 year;
}user_time;

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void app_time_init( void );
extern void app_time_update( user_time* );
extern user_time app_get_time( void );
extern bool clrTimeUpdateFlag( void );
extern bool IsLeapYear( uint16 );
extern uint32 TimeConverTimeStamp( user_time* );
extern user_time TimeStampConverTime( uint32 );
extern uint8 app_cal_week( user_time* );

#endif      /* __APP_USER_TIME_H__ */

/**********************************END OF FILE*********************************/
