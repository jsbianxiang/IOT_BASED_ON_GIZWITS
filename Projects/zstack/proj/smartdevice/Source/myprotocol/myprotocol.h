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
#define MYPROTOCOL_USER_DATA_SIZE  (18)
/** ͨѶ��ʽ MAC��ַ��С */
#define MYPROTOCOL_MAC_ADDR_SIZE   (8)
// �豸��������
#define MYPROTOCOL_TICK_CMD        (0x00)
// ��ȡ�豸��Ϣ����
#define W2D_DEVICE_LIST_UPDATE_CMD (0x10)
#define W2D_GET_DEVICE_NUM_CMD     (0x11)
#define W2D_GET_DEVICE_INFO_CMD    (0x12)

//�豸����
#define MYPROTOCOL_DEVICE_COORD     (0x00)
#define MYPROTOCOL_DEVICE_LIGHT     (0x01)
#define MYPROTOCOL_DEVICE_SOCKET    (0x02)
#define MYPROTOCOL_DEVICE_CURTAIN   (0x03)
#define MYPROTOCOL_DEVICE_HT_SENSOR (0x04)

/* Exported types ------------------------------------------------------------*/
// ͨѶ����
typedef enum
{
    MYPROTOCOL_COMM_END = 0x00,
    MYPROTOCOL_W2D_WAIT,
    MYPROTOCOL_W2D_ACK,
    MYPROTOCOL_D2W_WAIT,
    MYPROTOCOL_D2W_ACK,
    MYPROTOCOL_H2S_WAIT,
    MYPROTOCOL_H2S_ACK,
    MYPROTOCOL_S2H_WAIT,
    MYPROTOCOL_S2H_ACK,
    MYPROTOCOL_COMM_ERROR,
}myprotocol_commtype;

// �豸��Ϣ
typedef struct
{
    uint8 device;
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
    MYPROTOCOL_DIR_W2D,
    MYPROTOCOL_DIR_D2W,
    MYPROTOCOL_DIR_S2H,
    MYPROTOCOL_DIR_H2S,
    MYPROTOCOL_FORWORD_D2W,
    MYPROTOCOL_FORWORD_W2D,
}MYPROTOCOL_DATA_DIR;

// �������ݰ�����
typedef bool (*packet_func)(void *ctx, MYPROTOCOL_FORMAT *packet);

// �豸��������
typedef enum
{
    DEVICE_TICK   = 0x00,
    DEVICE_RESET  = 0x01,
    DEVICE_REBOOT = 0x02,
}DEVICE_BASE_CMD;

/* Exported variables --------------------------------------------------------*/
// �豸����
#define SMART_DEVICE_TYPE MYPROTOCOL_DEVICE_COORD

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
// MYPROTOCOL��ʼ������
extern void myprotocol_init( uint8 *task_id );

// ���ݰ���������
extern void SmartDevice_Message_Handler( afIncomingMSGPacket_t *pkt );
extern void Gizwits_Message_Handler( uint8 *report_data, uint8 *packet_data );

// ���ݰ����ͺ���
extern bool MYPROTOCO_S2H_MSG_SEND( packet_func, void * );
extern bool MYPROTOCO_H2S_MSG_SEND( MYPROTOCOL_DEVICE_INFO, packet_func, void* );
extern bool MYPROTOCOL_FORWARD_PACKET( MYPROTOCOL_DATA_DIR, MYPROTOCOL_FORMAT* );
extern bool MYPROTOCOL_D2W_SEND_MSG( MYPROTOCOL_FORMAT*, packet_func, void* );
extern bool MYPROTOCOL_SEND_MSG( MYPROTOCOL_DATA_DIR, MYPROTOCOL_FORMAT*, packet_func, void* );

// �������ݰ�����
extern bool create_tick_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_acktick_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_errcode_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_commend_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_w2d_ack_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_w2d_wait_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_d2w_ack_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_d2w_wait_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_devicenum_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_deviceinfo_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_devicelist_update_packet( void *ctx, MYPROTOCOL_FORMAT *packet );
extern bool create_report_packet( void *ctx, MYPROTOCOL_FORMAT *packet );

#endif      /* __myprotocol_H__ */

/**********************************END OF FILE*********************************/
