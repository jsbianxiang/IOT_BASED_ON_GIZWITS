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
#include <stddef.h>
    
/* Exported macro ------------------------------------------------------------*/
/** ������Ժ� */
#define USE_MYPROTOCOL_DEBUG 1

/** ����֧���豸�嵥 */
#define MYPROTOCOL_DEVICE_PHONE     (0x00)
#define MYPROTOCOL_DEVICE_COORD     (0x00)
#define MYPROTOCOL_DEVICE_LIGHT     (0x01)
#define MYPROTOCOL_DEVICE_SOCKET    (0x02)
#define MYPROTOCOL_DEVICE_CURTAIN   (0x03)
#define MYPROTOCOL_DEVICE_HT_SENSOR (0x04)

/**
 * @name ����MYPROTOCOL�豸��Ϣ
 * @{
 */
/** ���嵱ǰ�豸���� */
#if defined (MYIOT_DEVICE_COORD)
#define MYPROTOCOL_DEVICE MYPROTOCOL_DEVICE_COORD
#elif defined (MYIOT_DEVICE_LIGHT)
#define MYPROTOCOL_DEVICE MYPROTOCOL_DEVICE_LIGHT
#elif defined (MYIOT_DEVICE_SOCKET)
#define MYPROTOCOL_DEVICE MYPROTOCOL_DEVICE_SOCKET
#elif defined (MYIOT_DEVICE_CURTAIN)
#define MYPROTOCOL_DEVICE MYPROTOCOL_DEVICE_CURTAIN
#elif defined (MYIOT_DEVICE_HT_SENSOR)
#define MYPROTOCOL_DEVICE MYPROTOCOL_DEVICE_HT_SENSOR
#else
#define MYPROTOCOL_DEVICE
#endif
  
/** �жϵ�ǰ�豸���ܺ� */
#define MYPROTOCOL_DEVICE_IS_COORD     ( MYPROTOCOL_DEVICE == MYPROTOCOL_DEVICE_COORD     )
#define MYPROTOCOL_DEVICE_IS_LIGHT     ( MYPROTOCOL_DEVICE == MYPROTOCOL_DEVICE_LIGHT     )
#define MYPROTOCOL_DEVICE_IS_SOCKET    ( MYPROTOCOL_DEVICE == MYPROTOCOL_DEVICE_SOCKET    )
#define MYPROTOCOL_DEVICE_IS_CURTAIN   ( MYPROTOCOL_DEVICE == MYPROTOCOL_DEVICE_CURTAIN   )
#define MYPROTOCOL_DEVICE_IS_HT_SENSOR ( MYPROTOCOL_DEVICE == MYPROTOCOL_DEVICE_HT_SENSOR )
   
/** �ж��Ƿ��������MYPROTOCOLЭ���豸�ĺ� */
#if MYPROTOCOL_DEVICE_IS_COORD \
    || MYPROTOCOL_DEVICE_IS_LIGHT \
    || MYPROTOCOL_DEVICE_IS_SOCKET \
    || MYPROTOCOL_DEVICE_IS_CURTAIN \
    || MYPROTOCOL_DEVICE_IS_HT_SENSOR
        
#define USE_MYPROTOCOL_DEVICE 1
        
#else
#define USE_MYPROTOCOL_DEVICE 0
        
#endif
        
/** �ж��Ƿ��������MYPROTOCOLЭ���豸�ĺ� */
#if MYPROTOCOL_DEVICE_IS_LIGHT \
    || MYPROTOCOL_DEVICE_IS_SOCKET \
    || MYPROTOCOL_DEVICE_IS_CURTAIN \
        
#define USE_MYPROTOCOL_TIME_DEVICE 1
        
#else
#define USE_MYPROTOCOL_TIME_DEVICE 0
        
#endif
        
/**
 * @}
 */  
        
/**
 * @name ����ͨ����ز���
 * @{
 */
/** ����ƫ���� */
//#define MYPROTOCOL_OFFSETOF(t,m)                 ((uint16)(&((t *)0)->m)) 
#define MYPROTOCOL_OFFSETOF(t,m)                 offsetof(t,m)
/** ���ݰ���ռ�ڴ�ռ� */
#define MYPROTOCOL_PACKET_SIZE                   (sizeof(MYPROTOCOL_FORMAT_t)/sizeof(uint8))
/** �豸��Ϣ��ռ�ڴ�ռ� */
#define MYPROTOCOL_DEVICE_INFO_SIZE              (sizeof(MYPROTOCOL_DEVICE_INFO_t)/sizeof(uint8))
/** ����user_data��MYPROTOCOL_FORMAT_t�е�ƫ���� */
#define MYPROTOCOL_USER_DATA_OFFSET              MYPROTOCOL_OFFSETOF(MYPROTOCOL_FORMAT_t,user_data)
/** ����user_data������Ա�ĵ�ƫ���� */
#define MYPROTOCOL_USER_DATA_M_OFFSET(m)         MYPROTOCOL_OFFSETOF(MYPROTOCOL_USER_DATA_t,m)
/** ����cmd��MYPROTOCOL_USER_DATA_t�е�ƫ���� */
#define MTPROTOCOL_USER_DATA_CMD_OFFSET          MYPROTOCOL_USER_DATA_M_OFFSET(cmd)
/** ����len��MYPROTOCOL_USER_DATA_t�е�ƫ���� */
#define MYPROTOCOL_USER_DATA_LEN_OFFSET          MYPROTOCOL_USER_DATA_M_OFFSET(len) 
/** ����data��MYPROTOCOL_USER_DATA_t�е�ƫ���� */
#define MYPROTOCOL_USER_DATA_DATA_OFFSET         MYPROTOCOL_USER_DATA_M_OFFSET(data) 
///** ����user_data��ռ�ڴ�ռ��С user_dataΪMYPROTOCOL_USER_DATA_t���͵Ľṹ��ָ��*/
//#define MYPROTOCOL_CAL_USER_DATA_SIZE(user_data) ( MYPROTOCOL_USER_DATA_LEN_OFFSET \
//                                                  + (((MYPROTOCOL_USER_DATA_t *)user_data)->len))  
/** ͨѶ��ʽ �û����ݴ�С */
#define MYPROTOCOL_USER_DATA_SIZE   (18)
/** ͨѶ��ʽ MAC��ַ��С */
#define MYPROTOCOL_MAC_ADDR_SIZE    (8)

/** ����ͨѶ���� */
// #define MYPROTOCOL_COMM_END                  (0x00)
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
    MYPROTOCOL_DEVICE_INFO_t *info;
}MYPROTOCOL_DEVCICE_ACK_t;

/** �û���Ϣ */
typedef struct
{
    MYPROTOCOL_DEVICE_INFO_t deviceInfo;
    MYPROTOCOL_USER_DATA_t   userData;
}MYPROTOCOL_USER_MESSAGE_t;

/** MYPROTOCOL ��ʽ */
typedef struct
{
    MYPROTOCOL_COMMTYPE_t    commtype;
    uint8                    sn;
    MYPROTOCOL_DEVICE_INFO_t device;
    MYPROTOCOL_USER_DATA_t   user_data;
    uint8                    sum;
}MYPROTOCOL_FORMAT_t;

/**@} */

/**
 * @name MYPROTOCOL��ع��ܽӿڶ���
 * @{
 */
typedef bool (*packet_type)(void *ctx, void *packet);
typedef bool (*send_type)(void *ctx, void *packet);
typedef bool (*receive_type)(MYPROTOCOL_FORMAT_t *ctx);
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
extern bool MyprotocolInit( uint8* );
#else
extern void MyprotocolInit( uint8* );
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
 * @name ���ݰ�У��� �궨��
 * @{
 */
extern bool MyprotocolPacketCheck( void* );
extern bool MyprotocolW2DRecDeviceCheck( MYPROTOCOL_FORMAT_t* );
extern bool MyprotocolD2DRecDeviceCheck( MYPROTOCOL_FORMAT_t* );
/**@} */

/**
 * @name �豸�����ص�����״̬API
 * @{
 */
extern bool MyprotocolDeviceConStatusUpdate( uint8 );
/**@} */

/**
 * @name ��������API
 * @note ����ʹ�ú���MyprotocolSendData��������
 * @{
 */
// ͨ�÷������ݰ�����
extern bool MyprotocolD2DSendData( void*, void* );
extern bool MyprotocolD2DBroadcastData( void*, void* );
extern bool MyprotocolForwardData( void*, void*, send_type );
extern bool MyprotocolSendData( void*, void*, packet_type, send_type );

// ר�÷������ݰ�����
extern bool MyprotocolReplyErrPacket( MYPROTOCOL_FORMAT_t* );

#if MYPROTOCOL_DEVICE_IS_COORD
extern bool MyprotocolD2WSendData( void*, void* );
#else
extern bool MyprotocolD2DSendData( void*, void* );
#define MyprotocolD2WSendData MyprotocolD2DSendData
#endif

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

extern bool MyprotocolReceiveData( void*, receive_type );
/**@} */

/**
 * @name    ���ݰ�����
 * @{
 */
extern bool createCommErrorPacket( void*, void* );
extern bool createCommEndPacket( void*, void* );
extern bool createDeviceTickPacket( void*, void* );
extern bool createDeviceTickAckPacket( void*, void* );
extern bool createS2HWaitPacket( void*, void* );
extern bool createS2HAckPacket( void*, void* );
extern bool createH2SWaitPacket( void*, void* );
extern bool createH2SAckPacket( void*, void* );
extern bool createD2WWaitPacket( void*, void* );
extern bool createD2WAckPacket( void*, void* );
extern bool createW2DWaitPacket( void*, void* );
extern bool createW2DAckPacket( void*, void* );
extern bool createDeviceGetNTPPacket( void*, void* );
extern bool createDeviceGetNTPAckPacket( void*, void* );
extern bool createDeviceWrNTPPacket( void*, void* );
extern bool createDeviceWrNTPAckPacket( void*, void* );
/**@} */

#ifdef __cplusplus
}
#endif

#endif      /** __MY_IOT_PROTOCOL_H__ */

/**********************************END OF FILE*********************************/
