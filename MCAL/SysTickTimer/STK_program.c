/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Feb 2026                  *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : STK_program.c                *********************/
/*********************************************************************************/


#ifndef     STK_PROGRAM_C_
#define     STK_PROGRAM_C_

/************************************< LIB >************************************/
#include "STD_TYPES.h"      // Standard data types definitions
#include "BIT_MATH.h"       // Bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT)
/************************************< MCAL >***********************************/
#include "STK_interface.h" // SysTick interface header (API exposed to user)
#include "STK_private.h"   // SysTick private registers and bit definitions
#include "STK_config.h"    // SysTick user configuration (system clock settings)
/*******************************************************************************/

void STK_vInit(u8 Copy_u8ClkSource)
{
    if (Copy_u8ClkSource == STK_AHB_DIV_8)
    {
        /* صفر البت رقم 2 في CTRL عشان تختار AHB/8 */
        CLR_BIT(STK->CTRL, 2); 
    }
    else
    {
        /* خلي البت رقم 2 بـ 1 عشان تختار AHB (سرعة المعالج) */
        SET_BIT(STK->CTRL, 2);
    }
    
    /* تأكيد إن الـ Interrupt والـ Timer مقفولين في البداية */
    CLR_BIT(STK->CTRL, 0); // Disable Timer
    CLR_BIT(STK->CTRL, 1); // Disable Interrupt
}



u32 STK_u32GetElapsedTime(void){
    u32 Local_u32GetElapsedTime;
    Local_u32GetElapsedTime = (STK->LOAD)- (STK->VAL);

    return Local_u32GetElapsedTime;
}

void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    /* 1. Load the ticks into LOAD register */
    STK->LOAD = Copy_u32Ticks;
    
    /* 2. Start the timer (Enable) */
    SET_BIT(STK->CTRL, ENABLE);
    
    /* 3. Wait until the COUNTFLAG is set to 1 */
    while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);
    
    /* 4. Stop the timer */
    CLR_BIT(STK->CTRL , ENABLE);
    STK->LOAD = 0;
    STK->VAL  = 0;
}

u32 STK_u32GetRemainingTime(void){
    u32 Local_u32GetRemainingTime;
    Local_u32GetRemainingTime = STK->VAL;
    return Local_u32GetRemainingTime;
}


#endif