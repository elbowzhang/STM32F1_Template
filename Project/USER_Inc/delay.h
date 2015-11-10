/**
  ******************************************************************************
  * @file    Template/USER_Inc/delay.h
  * @author  elbow
  * @version V1.0.0
  * @date    2015/9/16
  * @brief   Header for delay.c based on STM32F10x
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DELAY_H_
#define __DELAY_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void delay_init(void);
void delay_us(__IO u32 nTime);
void delay_ms(__IO u32 nTime);

#endif /* __delay_H_ */

/************************ (C) COPYRIGHT elbow *****END OF FILE****/
