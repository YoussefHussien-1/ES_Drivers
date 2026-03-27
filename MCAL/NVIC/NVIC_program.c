/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 6 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : NVIC_program.c               *********************/
/*********************************************************************************/
#ifndef NVIC_PROGRAM_C_
#define NVIC_PROGRAM_C_



/************************************< LIB >************************************/
#include "STD_TYPES.h"      // Standard data types definitions
#include "BIT_MATH.h"       // Bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT)
/************************************< MCAL >***********************************/
#include "NVIC_interface.h" // NVIC interface header (API exposed to user)
#include "NVIC_private.h"   // NVIC private registers and bit definitions
#include "NVIC_config.h"    // NVIC user configuration (system clock settings)
/*******************************************************************************/


Std_ReturnType NVIC_EnableIRQ(IRQn_t IRQn)
{
    // code
    Std_ReturnType Local_Function = E_OK;
    if(IRQn <=240){
        NVIC_ISER[IRQn/32] = (1 << (IRQn % 32));
    }
    else
    {
        Local_Function = E_NOT_OK;
    }


    return Local_Function;
}

Std_ReturnType NVIC_DisableIRQ(IRQn_t IRQn)
{
    Std_ReturnType Local_Function = E_OK;
    if(IRQn <= 240){
        NVIC_ICER[IRQn /32] = (1 << (IRQn %32));
    }else{
        Local_Function = E_NOT_OK;
    }

    return Local_Function;
}

Std_ReturnType NVIC_GetPendingIRQ(IRQn_t IRQn)
{
    Std_ReturnType Local_u8Status = E_NOT_OK;
    
    if(IRQn <=240){
        Local_u8Status = GET_BIT(NVIC_ISPR[IRQn/32], (IRQn % 32));
    }
    return Local_u8Status;
 
}

Std_ReturnType NVIC_SetPendingIRQ(IRQn_t IRQn){
    Std_ReturnType Local_Function = E_OK;
    if(IRQn <= 240){
        NVIC_ISPR[IRQn/32] =(1 << (IRQn %32));
    }else{
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
}

Std_ReturnType NVIC_ClearPendingIRQ(IRQn_t IRQn)
{
    Std_ReturnType Local_Function = E_OK;

    if(IRQn <= 240){
        NVIC_ICPR[IRQn/32] = (1 <<  (IRQn %32));
    }else{
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
}


Std_ReturnType NVIC_GetActive(IRQn_t IRQn)
{
    Std_ReturnType Local_u8Status = E_NOT_OK;
    
    if(IRQn <=240){
        Local_u8Status = GET_BIT(NVIC_IABR[IRQn/32], (IRQn % 32));
    }
    return Local_u8Status;
}


Std_ReturnType NVIC_SetPriority(IRQn_t IRQn, u32 Copy_Priority)
{
    Std_ReturnType Local_Function = E_OK;
    if(IRQn <= 240){
        NVIC_IPR[IRQn / 4] &= ~( (0xFF) << ((IRQn % 4) * 8) );

        NVIC_IPR[IRQn/4] |= (Copy_Priority << (((IRQn % 4)* 8)+4));
    }

    else
    {
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
    
}






Std_ReturnType NVIC_GetPriority(IRQn_t IRQn,u8 Copy_pu8Priority)
{
    Std_ReturnType Local_Function = E_OK;
    if (IRQn <= 240 && (Copy_pu8Priority != NULL))
    {
        /* code */

        *Copy_pu8Priority = (NVIC_IPR[IRQn / 4] >> (((IRQn % 4) * 8) + 4)) & 0x0F;
    }
    else{
        Local_Function = E_NOT_OK;
    }
    return Local_Function;
}



Std_ReturnType NVIC_SetPriorityGrouping(u32 priority_grouping)
{
    
    SCB_AIRCR = priority_grouping;
    
}



Std_ReturnType NVIC_SystemReset(void)
{
    SCB_AIRCR = 0x05FA0004;


    while(1);
}

#endif // NVIC_PROGRAM_C_

