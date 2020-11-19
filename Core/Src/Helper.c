/*
 * Helper.c
 *
 *  Created on: Nov 19, 2020
 *      Author: Ahmed.Wahdan
 */

#include "Helper.h"
#include "stm32f4xx.h"
#include "main.h"

void Red_LED_On(void)
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
}
void System_Reset(void)
{
	__enable_irq();
	NVIC_SystemReset();
}
