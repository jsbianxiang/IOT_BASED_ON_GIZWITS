/**
 ******************************************************************************
  * @file       timer_config.h
  * @author     yearnext
  * @version    1.0.0
  * @date       2016��9��17��
  * @brief      CC2530 ��ʱ������ͷ�ļ�
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
#ifndef __CC2530_TIMER_CONFIG_H__
#define __CC2530_TIMER_CONFIG_H__

/* Includes ------------------------------------------------------------------*/
#include "comdef.h"
#include <ioCC2530.h>

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
// ��ʱ��3ռ�ձȸ���
#define TIM3_CH0_UpdateDuty( n ) ( T3CC0 = (n) )
#define TIM3_CH1_UpdateDuty( n ) ( T3CC1 = (n) )

#define Get_TIM3_CH0_Duty()      ( T3CC0 )
#define Get_TIM3_CH1_Duty()      ( T3CC1 )
// ��ʱ��4ռ�ձȸ���
#define TIM4_CH0_UpdateDuty( n ) ( T4CC0 = (n) )
#define TIM4_CH1_UpdateDuty( n ) ( T4CC1 = (n) )

#define Get_TIM4_CH0_Duty()      ( T4CC0 )
#define Get_TIM4_CH1_Duty()      ( T4CC1 )
// Timer3_PWM_Init�����Ĳ���
#define TIM3_CH0_PORT_P1_3 (1)
#define TIM3_CH0_PORT_P1_6 (2)
#define TIM3_CH1_PORT_P1_4 (3)
#define TIM3_CH1_PORT_P1_7 (4)
// Timer4_PWM_Init�����Ĳ���
#define TIM4_CH0_PORT_P1_0 (1)
#define TIM4_CH0_PORT_P2_0 (2)
#define TIM4_CH1_PORT_P1_1 (3)
#define TIM4_CH1_PORT_P2_1 (4)

/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
extern void Timer3_Init( void );
extern bool Timer3_PWM_Init( uint8 CHANNEL_PIN );
extern void Timer4_Init( void );
extern bool Timer4_PWM_Init( uint8 );

#endif      /* __CC2530_TIMER_CONFIG_H__ */

/**********************************END OF FILE*********************************/
