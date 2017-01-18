/**
 ******************************************************************************
  * @file       myprotocol.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      myprotocol ͷ�ļ�
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

#if defined ( USE_GIZWITS_MOD )

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_PROTOCOL_H__
#define __MY_PROTOCOL_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"

/* Exported macro ------------------------------------------------------------*/
/** ͨѶ��ʽ �û����ݴ�С */
#define MYPROTOCOL_USER_DATA_SIZE (24)
/** ͨѶ��ʽ MAC��ַ��С */
#define MYPROTOCOL_MAC_ADDR_SIZE  (6)

#define MYPROTOCOL_TICK_CMD (0x00)

/* Exported types ------------------------------------------------------------*/
typedef enum
{
    MYPROTOCOL_COMM_END = 0x00,
    MYPROTOCOL_W2D_READ_WAIT,
    MYPROTOCOL_W2D_READ_ACK,
    MYPROTOCOL_W2D_WRITE_WAIT,
    MTPROTOCOL_W2D_WRITE_ACK,
    MYPROTOCOL_D2W_READ_WAIT,
    MYPROTOCOL_D2W_READ_ACK,
    MYPROTOCOL_D2W_REPORT_WAIT,
    MYPROTOCOL_D2W_REPORT_ACK,
    MYPROTOCOL_COMM_ERROR,
    MYPROTOCOL_COMM_TICK,
}myprotocol_commtype;

typedef enum
{
    MYPROTOCOL_DEVICE_COORD = 0x00,
    MYPROTOCOL_DEVICE_LIGHT,
    MYPROTOCOL_DEVICE_SOCKET,
    MYPROTOCOL_DEVICE_CURTAIN,
    MYPROTOCOL_DEVICE_HT_SENSOR,
    MYPROTOCOL_DEVICE_END,
}MYPROTOCOL_DEVICE;

typedef struct
{
    MYPROTOCOL_DEVICE device;
    uint16 addr;
}MYPROTOCOL_DEVICE_INFO;

typedef struct
{
    uint8 cmd;
    uint8 len;
    uint8 data[MYPROTOCOL_USER_DATA_SIZE];
}MYPROTOCOL_USER_DATA;

typedef struct
{
    myprotocol_commtype    commtype;
    uint8                  sn;
    MYPROTOCOL_DEVICE_INFO device;
    MYPROTOCOL_USER_DATA   user_data;
    uint8                  check_sum;
}MYPROTOCOL_FORMAT;

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void myprotocol_init( void );

extern void myprotocol_packet_handler( uint8 *report_data, uint8 *packet_data );

extern uint8 myprotocol_compute_checksum( uint8 *packet );

#endif      /* __myprotocol_H__ */

#endif

/**********************************END OF FILE*********************************/
