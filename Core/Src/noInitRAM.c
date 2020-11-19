/*
 * noInitRam.c
 *
 *  Created on: Nov 19, 2020
 *      Author: Ahmed.Wahdan
 */

#include "noInitRAM.h"
#include "Helper.h"
#include <stdint.h>




 __attribute__ ((section (".noinit")))
 uint32_t g_NoInitVar;
 __attribute__ ((section (".noinit")))
 uint32_t g_IsFirstTime;


void NoInitRAM_Demonestration(void )
{
	if(g_IsFirstTime != FIRST_TIME_PATTERN)
	{
		g_IsFirstTime = FIRST_TIME_PATTERN;
		g_NoInitVar = 0;
	}

	if(g_NoInitVar == MAX_VAR_VALUE)
	{
		/* Red LED ON */
		Red_LED_On();
		while(1);
	}
	else
	{
		g_NoInitVar++;
		/* Request Software Reset */
		System_Reset();
	}
}
