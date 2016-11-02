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

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
// �ƵĿ����ر�����
#define SOCKET_ON_CMD  ( 255 )
#define SOCKET_OFF_CMD ( 0 )

/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void bsp_socket_init( void );
extern void set_socket_value( uint8 );
extern uint8 get_socket_value( void );
extern void socket_control_handler( uint8 );
extern void socket_switch_headler( void );
extern void socket_working_headler( void );
extern bool socket_cmd_resolve( MYPROTOCOL_USER_DATA *data );

#endif      /* __SMART_DEVICE_socket_H__ */

/**********************************END OF FILE*********************************/
