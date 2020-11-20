/*
 * Helper.c
 *
 *  Created on: Nov 19, 2020
 *      Author: Ahmed.Wahdan
 */

#include "Helper.h"
#include "stm32f4xx.h"
#include "main.h"

void Set_Red_LED(void)
{
	HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
}

void Toggle_Green_LED(uint32_t counter)
{
	if(counter%2)
	{
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET);
	}

	HAL_Delay(1000);
}

void System_Reset(void)
{
	__enable_irq();
	NVIC_SystemReset();
}
