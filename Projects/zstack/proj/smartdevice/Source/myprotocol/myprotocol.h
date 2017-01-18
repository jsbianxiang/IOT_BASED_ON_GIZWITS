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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_PROTOCOL_H__
#define __MY_PROTOCOL_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"
#include "AF.h"

/* Exported macro ------------------------------------------------------------*/
/** ͨѶ��ʽ �û����ݴ�С */
#define MYPROTOCOL_USER_DATA_SIZE (18)
/** ͨѶ��ʽ MAC��ַ��С */
#define MYPROTOCOL_MAC_ADDR_SIZE  (8)
// �豸��������
#define MYPROTOCOL_TICK_CMD (0x00)
// ��ȡ�豸��Ϣ����
#define W2D_GET_DEVICE_NUM_CMD  (0x01)
#define W2D_GET_DEVICE_INFO_CMD (0x02)

/* Exported types ------------------------------------------------------------*/
// ͨѶ����
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
//�豸����
typedef enum
{
    MYPROTOCOL_DEVICE_COORD = 0x00,
    MYPROTOCOL_DEVICE_LIGHT,
    MYPROTOCOL_DEVICE_SOCKET,
    MYPROTOCOL_DEVICE_CURTAIN,
    MYPROTOCOL_DEVICE_HT_SENSOR,
    MYPROTOCOL_DEVICE_END,
}MYPROTOCOL_DEVICE;
// �豸��Ϣ
typedef struct
{
    MYPROTOCOL_DEVICE device;
    uint8 mac[MYPROTOCOL_MAC_ADDR_SIZE];
}MYPROTOCOL_DEVICE_INFO;
// �û�����
typedef struct
{
    uint8 cmd;
    uint8 len;
    uint8 data[MYPROTOCOL_USER_DATA_SIZE];
}MYPROTOCOL_USER_DATA;
// �豸Ӧ��
typedef struct
{
    uint8 id;
    MYPROTOCOL_DEVICE_INFO *info;
}MYPROTOCOL_DEVCICE_ACK;
// MYPROTOCOL ��ʽ
typedef struct
{
    myprotocol_commtype    commtype;
    uint8                  sn;
    MYPROTOCOL_DEVICE_INFO device;
    MYPROTOCOL_USER_DATA   user_data;
    uint8                  check_sum;
}MYPROTOCOL_FORMAT;
// ���ݷ��ͷ���
typedef enum
{
    MYPROTOCOL_DIR_D2W,
    MYPROTOCOL_DIR_D2D,
}MYPROTOCOL_DATA_DIR;
// ���ݰ�����
typedef bool (*packet_func)(void *ctx, MYPROTOCOL_FORMAT *packet);

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void myprotocol_init( uint8 endpoint, uint8 *task_id );
extern void SmartDevice_Message_Headler( afIncomingMSGPacket_t *pkt );
extern void Gizwits_Message_Headler( uint8 *report_data, uint8 *packet_data );
extern bool MYPROTOCOL_SEND_MSG( MYPROTOCOL_DATA_DIR, MYPROTOCOL_FORMAT *, packet_func, void * );

#endif      /* __myprotocol_H__ */

/**********************************END OF FILE*********************************/
