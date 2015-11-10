/**
  ******************************************************************************
  * @file		Template/USER_Src/delay.c
  * @auther		elbow
  * @version	V1.0.0
  * @date		2015/9/16
  * @brief		Delay us/ms/.. based on STM32F10x
  ******************************************************************************
  */
  
/* Include ********************************************************************/
#include "delay.h"
/* Private Typedef ************************************************************/
/* Private Define *************************************************************/
/* Private Variables **********************************************************/
static __IO u32 TimingDelay;
/* Extern Variables ***********************************************************/
/* Private Functions **********************************************************/

/**
  * @brief		delay init
  * @param		None
  * @retval		None
  */
void delay_init(void)
{
	// SystemFrequency / 1000     1ms中断一次
	// SystemFrequency / 100000	 10us中断一次
	// SystemFrequency / 1000000  1us中断一次
	/* 配置滴答计时器中断 */
	if (SysTick_Config(SystemCoreClock / 1000000))	// 1us中断 ST3.5.0库版本
	{ 
		/* Capture error */
		while (1);
	}
}

/**
  * @brief		delay nTime us
  * @param		u32 nTime
  * @retval		None
  */
void delay_us(__IO u32 nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);
}

/**
  * @brief		delay nTime ms
  * @param		u32 nTime
  * @retval		None
  */
void delay_ms(__IO u32 nTime)
{
	TimingDelay = nTime * 1000;		/* us * 1000 */
	while(TimingDelay != 0);
}

/**
  * @brief		SysTick Interrupt ISR
  * @param		None
  * @retval		None
  */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}

/**
  * @}
  */

/**
  * @}
  */

/**************************** (C) COPYRIGHT elbow ***********END OF FILE******/
