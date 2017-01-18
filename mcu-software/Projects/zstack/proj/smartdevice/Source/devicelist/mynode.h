/**
 ******************************************************************************
  * @file       mynode.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      mynode ͷ�ļ�
  * @par        ����ƽ̨                                  
  *                  CC2530
  * @par        ����Ƶ��                                  
  *                  32MHz
  * @par        ����ƽ̨									                          
  * 				 IAR
 ******************************************************************************
  * @note
  * ����һ��ͨ�õ��������ģ���ܹ�ʵ����������ӡ�ɾ���Ȳ�����                  						                      
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_NODE_H__
#define __MY_NODE_H__

#ifdef __cplusplus
extern "C" 
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/**
 * @defgroup ����ڵ��������
 * @{
 */
/** ����ڵ����� */
typedef struct _USER_NODE_
{
	struct _USER_NODE_ *next;
	void *data;
}myNODE_t, *myList_t, **myListHand_t;

/** ����ڵ���ʺ������� */
typedef bool(*node_func)(void **, void **, void **);

/**
 * @}
 */

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/**
 * @defgroup �ڵ�������API
 * @{
 */
extern bool nodeTraverse(void**, node_func, void**, void**);
extern bool nodeAddOpera(void**, void**, void**);
extern bool nodeClrOpera(void**, void**, void**);
extern bool nodeGetNum(void**, void**, void**);
extern bool nodeIsExists(void**, void**, void**);
/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif

#endif      /* __MY_DEVICE_LIST_H__ */

/**********************************END OF FILE*********************************/
