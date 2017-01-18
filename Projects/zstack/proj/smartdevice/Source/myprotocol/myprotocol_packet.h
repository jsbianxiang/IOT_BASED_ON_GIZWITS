/**
 ******************************************************************************
  * @file       myprotocol_packet.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      myprotocol_packet ͷ�ļ�
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
#ifndef __MY_PROTOCOL_PACKET_H__
#define __MY_PROTOCOL_PACKET_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern bool create_tick_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_acktick_packet( void *ctx, MYPROTOCOL_FORMAT *packet );

extern bool create_errcode_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_commend_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_writeack_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_readack_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_devicenum_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_deviceinfo_packet( void *ctx, MYPROTOCOL_FORMAT *packet );

#endif      /* __myprotocol_packet_H__ */

/**********************************END OF FILE*********************************/
