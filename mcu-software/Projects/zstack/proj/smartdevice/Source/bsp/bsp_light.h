/**
 ******************************************************************************
  * @file       bsp_light.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      ���ܵ������ͷ�ļ�
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
#ifndef __SMART_DEVICE_LIGHT_H__
#define __SMART_DEVICE_LIGHT_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"
#include "myprotocol.h"
#include "bsp_key.h"

/* Exported macro ------------------------------------------------------------*/
#if MYPROTOCOL_DEVICE_IS_LIGHT
#define bspDeviceInit()      bspLightInit()
#define deviceMessageHandler lightMessageHandler
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void bspLightInit( void );
extern void setLightBrightness( uint8 );
extern uint8 getLightBrightness( void );
extern void lightControlHandler( uint8 );
extern void lightSwitchHandler( void );

#if MYPROTOCOL_DEVICE_IS_LIGHT
//#define lightSwitchKeyHandler key1_handler
//#define lightRstKeyHandler    key2_handler
#define lightSwitchKeyHandler key2_handler
#define lightRstKeyHandler    key1_handler
#endif

extern void lightSwitchKeyHandler( key_message_t );
extern void lightRstKeyHandler( key_message_t );

extern void lightWorkingHandler( void );
extern bool lightMessageHandler( MYPROTOCOL_FORMAT_t *recPacket );

#endif      /* __SMART_DEVICE_LIGHT_H__ */

/**********************************END OF FILE*********************************/
