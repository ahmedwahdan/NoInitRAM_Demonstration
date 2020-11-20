/*
 * noInitRam.c
 *
 *  Created on: Nov 19, 2020
 *      Author: Ahmed.Wahdan
 */

#include "noInitRAM.h"
#include "Helper.h"
#include <stdint.h>


/*
    Global and static variable initialization at startup
 ----- Flash -------------  RAM ---------
 |---------------------------------------
 |      Var1       |        Var1        |
 |---------------------------------------
 |      Var1       |        Var1        |
 |---------------------------------------
 |      Var1       |        Var1        |
 |---------------------------------------
 |      Var1       |        Var1        |
 |---------------------------------------
 */

 uint32_t var1 = 0x05;
 uint32_t var2 = 0x0A;
 uint32_t var3 = 0x0C;
 uint32_t var4 = 0x0F;

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
        var1 = 0;
        var2 = 0;
        var3 = 0;
        var4 = 0;

    }

    g_NoInitVar++;
    Toggle_Green_LED(g_NoInitVar);

    if(g_NoInitVar == MAX_VAR_VALUE)
    {
        /* Red LED ON */
        Set_Red_LED();
        while(1);
    }
    else
    {
        /* Request Software Reset */
        System_Reset();
    }
}
