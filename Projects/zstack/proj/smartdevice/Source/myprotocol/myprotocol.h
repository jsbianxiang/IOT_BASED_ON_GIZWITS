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
#ifndef __MY_IOT_PROTOCOL_H__
#define __MY_IOT_PROTOCOL_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"

/* Exported macro ------------------------------------------------------------*/
/** ������Ժ� */
#define USE_MYPROTOCOL_DEBUG 1

/** ����֧���豸�嵥 */
#define MYPROTOCOL_DEVICE_COORD     (0x00)
#define MYPROTOCOL_DEVICE_LIGHT     (0x01)
#define MYPROTOCOL_DEVICE_SOCKET    (0x02)
#define MYPROTOCOL_DEVICE_CURTAIN   (0x03)
#define MYPROTOCOL_DEVICE_HT_SENSOR (0x04)

/** ���嵱ǰ�豸���� */
#define SMART_DEVICE_TYPE MYPROTOCOL_DEVICE_COORD

/**
 * @name ����ͨ����ز���
 * @{
 */
/** ���ݰ���ռ�ڴ�ռ� */
#define MYPROTOCOL_PACKET_SIZE                   (sizeof(MYPROTOCOL_FORMAT_t)/sizeof(uint8))

/** �豸��Ϣ��ռ�ڴ�ռ� */
#define MYPROTOCOL_DEVICE_INFO_SIZE              (sizeof(MYPROTOCOL_DEVICE_INFO_t)/sizeof(uint8))

/** ����user_data��MYPROTOCOL_FORMAT_t�е�ƫ���� */
#define MYPROTOCOL_USER_DATA_OFFSET              ((uint8)(&((MYPROTOCOL_FORMAT_t *)(0))->user_data))

/** ����cmd��MYPROTOCOL_USER_DATA_t�е�ƫ���� */
#define MTPROTOCOL_USER_CMD_OFFSET               ((uint8)(&((MYPROTOCOL_USER_DATA_t *)(0))->user_data.cmd))

/** ����len��MYPROTOCOL_USER_DATA_t�е�ƫ���� */
#define MYPROTOCOL_USER_DATA_LEN_OFFSET          ((uint8)(&((MYPROTOCOL_USER_DATA_t *)(0))->user_data.len))

/** ����data��MYPROTOCOL_USER_DATA_t�е�ƫ���� */
#define MYPROTOCOL_USER_DATA_DATA_OFFSET         ((uint8)(&((MYPROTOCOL_USER_DATA_t *)(0))->user_data.data))

/** ����user_data��ռ�ڴ�ռ��С user_dataΪMYPROTOCOL_USER_DATA_t���͵Ľṹ��ָ��*/
#define MYPROTOCOL_CAL_USER_DATA_SIZE(user_data) ((uint8)(MYPROTOCOL_USER_DATA_LEN_OFFSET \
                                                          + ((MYPROTOCOL_USER_DATA_t *)(user_data))->len))

/** ����user_message��ռ�ڴ�ռ��С user_dataΪMYPROTOCOL_USER_DATA_t���͵Ľṹ��ָ��*/                                                          
#define MYPROTOCOL_CAL_USER_MSG_SIZE(user_data)  ((uint8)((uint8)MYPROTOCOL_DEVICE_INFO_SIZE \
                                                          + MYPROTOCOL_USER_DATA_LEN_OFFSET \
                                                          + ((MYPROTOCOL_USER_DATA_t *)(user_data))->len))

/** ͨѶ��ʽ �û����ݴ�С */
#define MYPROTOCOL_USER_DATA_SIZE   (18)

/** ͨѶ��ʽ MAC��ַ��С */
#define MYPROTOCOL_MAC_ADDR_SIZE    (8)

/** ����ͨѶ���� */
// #define MYPROTOCOL_COMM_END          (0x00)
// #define MYPROTOCOL_W2D_WAIT			(0x01)
// #define MYPROTOCOL_W2D_ACK			(0x02)
// #define MYPROTOCOL_D2W_WAIT			(0x03)
// #define MYPROTOCOL_D2W_ACK			(0x04)
// #define MYPROTOCOL_H2S_WAIT			(0x05)
// #define MYPROTOCOL_H2S_ACK			(0x06)
// #define MYPROTOCOL_S2H_WAIT			(0x07)
// #define MYPROTOCOL_S2H_ACK			(0x08)
// #define MYPROTOCOL_COMM_ERROR		(0x09)

/** �����豸ͨ������ */
#define MYPROTOCOL_TICK_CMD         (0x00)
#define MYPROTOCOL_RESET_CMD        (0x01)
#define MYPROTOCOL_REBOOT_CMD       (0x02)
#define MYPROTOCOL_UPDATE_TIME_CMD  (0x03)
#define MYPROTOCOL_RD_TIME_CMD      (0x04)
#define MYPROTOCOL_WR_TIME_CMD      (0x05)
/**@} */

/* Exported types ------------------------------------------------------------*/
/**
 * @name MYPROTOCOL��ع��ܽӿڶ���
 * @{
 */
typedef bool (*packet_type)(void *ctx, void *packet);
typedef bool (*send_type)(void *ctx, void *packet);
typedef bool (*receive_type)(void *ctx, void *packet);
/**@} */

/**
 * @name MYPROTOCOL���ݰ���ʽ����
 * @{
 */
/** ͨѶ���� */
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
}MYPROTOCOL_COMMTYPE_t;

/** �豸��Ϣ */
typedef struct
{
    uint8 device;
    uint8 mac[MYPROTOCOL_MAC_ADDR_SIZE];
}MYPROTOCOL_DEVICE_INFO_t;

/** �û����� */
typedef struct
{
    uint8 cmd;
    uint8 len;
    uint8 data[MYPROTOCOL_USER_DATA_SIZE];
}MYPROTOCOL_USER_DATA_t;
    
/** �豸Ӧ�� */
typedef struct
{
    uint8 id;
    MYPROTOCOL_DEVICE_INFO *info;
}MYPROTOCOL_DEVCICE_ACK_t;

/** �û���Ϣ */
typedef struct
{
    MYPROTOCOL_DEVICE_INFO deviceInfo;
    MYPROTOCOL_USER_DATA   userData;
}MYPROTOCOL_USER_MESSAGE_t;

/** MYPROTOCOL ��ʽ */
typedef struct
{
    MYPROTOCOL_COMMTYPE    commtype;
    uint8                  sn;
    MYPROTOCOL_DEVICE_INFO device;
    MYPROTOCOL_USER_DATA   user_data;
    uint8                  sum;
}MYPROTOCOL_FORMAT_t;

/**@} */

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/**
 * @name Ӳ����ʼ������ �궨��
 * @{
 */
#if USE_MYPROTOCOL_DEBUG
extern bool HalMyprotocolInit( uint8* );
#else
extern void HalMyprotocolInit( uint8* );
#endif
/**@} */

/**
 * @name ���������Ϣ���� �궨��
 * @note ��ʹ�ú� MYPROTOCOL_LOG ���������Ϣ
 * @{
 */
#if USE_MYPROTOCOL_DEBUG
extern void MyprotocolPutLog( uint8*, uint16 );
#define MYPROTOCOL_LOG(n) MyprotocolPutLog(n,sizeof(n))
#else
#define MYPROTOCOL_LOG(n)
#endif
/**@} */

/**
 * @name ��������API
 * @note ����ʹ�ú���MyprotocolSendData��������
 * @{
 */
extern bool MyprotocolD2DSendData( void*, void* );
extern bool MyprotocolD2WSendData( void*, void* );
extern bool MyprotocolForwardData( void*, void*, send_type );
extern bool MyprotocolSendData( void*, void*, packet_type, send_type );
/**@} */

/**
 * @name                  ��������API
 * @param ctx             ���յ������ݰ�
 * @param receive_func    ���ݰ�������
 * @note                  ����ʹ�ú���MyprotocolReceiveData���ս�������
 * @{
 */
#define MyprotocolW2DReceiveData( ctx, receive_func ) receive_func(ctx)
#define MyprotocolD2DReceiveData( ctx, receive_func ) receive_func(ctx)

extern bool MyprotocolReceiveData( void*, void*, receive_type, receive_type );
/**@} */

/**
 * @name    ���ݰ�����
 * @{
 */
extern bool CommErrorPacket( void*, void* );
extern bool DeviceTickPacket( void*, void* );
extern bool DeviceTickAckPacket( void*, void* );
extern bool S2HWaitPacket( void*, void* );
extern bool S2HAckPacket( void*, void* );
extern bool H2SWaitPacket( void*, void* );
extern bool H2SAckPacket( void*, void* );
extern bool D2WWaitPacket( void*, void* );
extern bool D2WAckPacket( void*, void* );
extern bool W2DWaitPacket( void*, void* );
extern bool W2DAckPacket( void*, void* );
/**@} */

#ifdef __cplusplus
}
#endif

#endif      /** __MY_IOT_PROTOCOL_H__ */

/**********************************END OF FILE*********************************/
