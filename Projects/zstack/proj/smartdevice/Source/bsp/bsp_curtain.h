/**
 ******************************************************************************
  * @file       bsp_curtain.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      �������� ͷ�ļ�
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
#ifndef __SMART_DEVICE_CURTAIN_H__
#define __SMART_DEVICE_CURTAIN_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"
#include "myprotocol.h"
#include "bsp_key.h"

/* Exported macro ------------------------------------------------------------*/
#if MYPROTOCOL_DEVICE_IS_CURTAIN
#define bspDeviceInit        bspCurtainInit
#define deviceMessageHandler curtainMessageHandler
#endif
  
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void bspCurtainInit( void );
extern bool curtainControlCmd( uint8 );
#if MYPROTOCOL_DEVICE_IS_CURTAIN
#define curtainSwitchKeyHandler key1_handler
#define curtainRainKeyHandler   key2_handler
#endif
extern void curtainSwitchKeyHandler( key_message_t );
extern void curtainRainKeyHandler( key_message_t );

extern void curtainWorkingHandler( void );
extern bool curtainMessageHandler( MYPROTOCOL_FORMAT_t *recPacket );

#ifdef __cplusplus
}
#endif

#endif      /* __SMART_DEVICE_CURTAIN_H__ */

/**********************************END OF FILE*********************************/
