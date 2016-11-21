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
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void bsp_light_init( void );
extern void set_light_brightness( uint8 );
extern uint8 get_light_brightness( void );
extern void light_control_handler( uint8 );
extern void light_switch_handler( void );
#if (SMART_DEVICE_TYPE) == (MYPROTOCOL_DEVICE_LIGHT)
extern void key_switch_handler( key_message_t );
#endif
extern void light_working_handler( void );
extern bool light_cmd_resolve( MYPROTOCOL_USER_DATA *data );

#endif      /* __SMART_DEVICE_LIGHT_H__ */

/**********************************END OF FILE*********************************/
