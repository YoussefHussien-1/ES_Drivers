/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : EXTI_program.C               *********************/
/*********************************************************************************/


/************************************< LIB >************************************/
#include "STD_TYPES.h"      // Standard data types definitions
#include "BIT_MATH.h"       // Bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT)
/************************************< MCAL >***********************************/
#include "EXTI_interface.h" // NVIC interface header (API exposed to user)
#include "EXTI_private.h"   // NVIC private registers and bit definitions
#include "EXTI_config.h"    // NVIC user configuration (system clock settings)
/*******************************************************************************/


Std_ReturnType EXTI_vEnableLine(u8 Copy_Line)
{
    Std_ReturnType Local_Function = E_OK;
    if(Copy_Line <= 15){
        SET_BIT(EXTI->IMR, Copy_Line);
    }else{
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
}

Std_ReturnType EXTI_vDisableLine(u8 Copy_Line)
{
    Std_ReturnType Local_Function = E_OK;
    if(Copy_Line <= 15){
        CLR_BIT(EXTI->IMR, Copy_Line);
    }else{
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
}

Std_ReturnType EXTI_vSetSignalLatch(u8 Copy_Line, u8 Copy_Mode){
    Std_ReturnType Local_Function = E_OK;

    if (Copy_Line <=15)
    {
        /* code */
        switch (Copy_Mode)
        {
        case EXTI_RTSR:
            SET_BIT(EXTI->RTSR, Copy_Line);
            CLR_BIT(EXTI->FTSR, Copy_Line);
            break;
        case EXTI_FTSR:
            SET_BIT(EXTI->FTSR, Copy_Line);
            CLR_BIT(EXTI->RTSR, Copy_Line);
            break;
        case EXTI_ON_CHANGE:
            SET_BIT(EXTI->RTSR, Copy_Line);
            SET_BIT(EXTI->FTSR, Copy_Line);
            break;
        default:
            Local_Function = E_NOT_OK;
            break;
        }
    }else{
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
    
}


Std_ReturnType EXTI_vSoftwareTrigger(u8 Copy_Line){
    Std_ReturnType Local_Function = E_OK;
    
    if (Copy_Line<=15)
    {
        /* code */
        SET_BIT(EXTI->SWIER, Copy_Line);
    }else{
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
}


Std_ReturnType EXTI_vClearPendingFlag(u8 Copy_Line)
{
    Std_ReturnType Local_Function = E_OK;

    if (Copy_Line <=15)
    {
        SET_BIT(EXTI->PR , Copy_Line);
    }else{
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
    
}


