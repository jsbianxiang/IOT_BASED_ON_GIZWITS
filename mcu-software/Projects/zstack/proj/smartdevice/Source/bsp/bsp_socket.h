/**
 ******************************************************************************
  * @file       bsp_socket.h
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
#ifndef __SMART_DEVICE_SOCKET_H__
#define __SMART_DEVICE_SOCKET_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"
#include "myprotocol.h"
#include "bsp_key.h"

/* Exported macro ------------------------------------------------------------*/
#if MYPROTOCOL_DEVICE_IS_SOCKET
#define bspDeviceInit() bspSocketInit()
#define deviceMessageHandler socketMessageHandler
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void bspSocketInit( void );
extern void setSocketState( uint8 );
extern uint8 getSocketState( void );
extern void socketControlHandler( uint8 );
extern void socketSwitchHandler( void );

#if MYPROTOCOL_DEVICE_IS_SOCKET
#define socketSwitchKeyHandler key1_handler
#define socketRstKeyHandler    key2_handler
#endif

extern void socketSwitchKeyHandler( key_message_t );
extern void socketRstKeyHandler( key_message_t );

extern void socketWorkingHandler( void );
extern bool socketMessageHandler( MYPROTOCOL_FORMAT_t *recPacket );

#endif      /* __SMART_DEVICE_socket_H__ */

/**********************************END OF FILE*********************************/
