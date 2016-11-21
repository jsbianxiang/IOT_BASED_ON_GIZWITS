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

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void bsp_curtain_init( void );
extern bool curtain_cmd_resolve( MYPROTOCOL_USER_DATA *data );

#ifdef __cplusplus
}
#endif

#endif      /* __SMART_DEVICE_CURTAIN_H__ */

/**********************************END OF FILE*********************************/
