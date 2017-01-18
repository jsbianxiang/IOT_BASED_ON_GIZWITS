/**
 ******************************************************************************
  * @file       devicelist.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      devicelist ͷ�ļ�
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
#ifndef __MY_DEVICE_LIST_H__
#define __MY_DEVICE_LIST_H__

#ifdef __cplusplus
extern "C" 
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"
#include "myprotocol.h"

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef struct
{
    MYPROTOCOL_DEVICE_INFO_t device;
	uint8 tick;
}listInfo_t;

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/**
 * @defgroup �б�������API
 * @{
 */
extern bool addDeviceToList( MYPROTOCOL_DEVICE_INFO_t* );
extern bool clrDeviceInList( MYPROTOCOL_DEVICE_INFO_t * );
extern uint8 deviceNumGet( void );
extern bool deviceIsExists( MYPROTOCOL_DEVICE_INFO_t* );
extern bool deviceInfoGet( uint8, MYPROTOCOL_DEVICE_INFO_t** );
extern bool addDeviceTick( MYPROTOCOL_DEVICE_INFO_t * );
extern bool allDeviceTickClr( void );
extern bool allZombieDeviceClr( void );
/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif

#endif      /* __MY_DEVICE_LIST_H__ */

/**********************************END OF FILE*********************************/
