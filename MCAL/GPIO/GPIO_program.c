/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 6 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : GPIO_program.c               *********************/
/*********************************************************************************/


#ifndef GPIO_PROGRAM_C_
#define GPIO_PROGRAM_C_

/************************************< LIB >************************************/
#include "STD_TYPES.h"      // Standard data types definitions
#include "BIT_MATH.h"       // Bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT)
/************************************< MCAL >***********************************/
#include "GPIO_interface.h" // RCC interface header (API exposed to user)
#include "GPIO_private.h"   // RCC private registers and bit definitions
#include "GPIO_config.h"    // RCC user configuration (system clock settings)
/*******************************************************************************/


Std_ReturnType GPIO_SetPinMode(u8 Copy_PortId , u8 Copy_PinId, u8 Copy_PinMode){
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_PortId)
    {
    case GPIO_PortA:
        if(Copy_PinId >= 0 && Copy_PinId <= 7){

            GPIOPA_CRL &= ~((0b1111) << (Copy_PinId*4));
            GPIOPA_CRL |= (Copy_PinMode << (Copy_PinId*4));

        }else if(Copy_PinId >= 8 && Copy_PinId <= 15){
            GPIOPA_CRH &= ~((0b1111) << ((Copy_PinId-8)*4));
            GPIOPA_CRH |= (Copy_PinMode << ((Copy_PinId-8)*4));
        }else{
            Local_FuncitonStatus = E_NOT_OK;
        }
        Local_FunctionStatus = E_OK;
        break;
    

    case GPIO_PortB:
        if(Copy_PinId >= 0 && Copy_PinId <= 7){
            GPIOPB_CRL &= ~((0b1111) << (Copy_PinId*4));
            GPIOPB_CRL |= (Copy_PinMode << (Copy_PinId*4));
        }else if(Copy_PinId >= 8 && Copy_PinId <= 15){
            GPIOPB_CRH &= ~((0b1111) << ((Copy_PinId-8)*4));
            GPIOPB_CRH |= (Copy_PinMode << ((Copy_PinId-8)*4));
        }else{
            Local_FunctionStatus = E_NOT_OK;
        }
        Local_FunctionStatus = E_OK;
        break;


    case GPIO_PortC:
        if(Copy_PinId >= 0 && Copy_PinId <= 7){
            GPIOPC_CRL &= ~((0b1111) << (Copy_PinId*4));
            GPIOPC_CRL |= (Copy_PinMode << (Copy_PinId*4));
        }else if(Copy_PinId >= 8 && Copy_PinId <= 15){
            GPIOPC_CRH &= ~((0b1111) << ((Copy_PinId-8)*4));
            GPIOPC_CRH |= (Copy_PinMode << ((Copy_PinId-8)*4));
        }else{
            Local_FunctionStatus = E_NOT_OK;
        }
        Local_FunctionStatus = E_OK;
        break;


    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }



    return Local_FunctionStatus;
}



Std_ReturnType GPIO_SetPinValue(u8 Copy_PortId , u8 Copy_PinId, u8 Copy_PinValue)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_PortId)
    {
    case GPIO_PortA:
        if(Copy_PinValue == GPIO_HIGH){
            SET_BIT(GPIOPA_ODR , Copy_PinId);
        }
        else{
            CLR_BIT(GPIOPA_ODR, Copy_PinId);
        }
        Local_FunctionStatus = E_OK;
        break;
    

    case GPIO_PortB:
        if(Copy_PinValue == GPIO_HIGH){
            SET_BIT(GPIOPB_ODR , Copy_PinId);
        }
        else{
            CLR_BIT(GPIOPB_ODR, Copy_PinId);
        }
        Local_FunctionStatus = E_OK;
        break;


    case GPIO_PortC:
        if(Copy_PinValue == GPIO_HIGH){
            SET_BIT(GPIOPC_ODR , Copy_PinId);
        }
        else{
            CLR_BIT(GPIOPC_ODR, Copy_PinId);
        }
        Local_FunctionStatus = E_OK;
        break;


    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }



    return Local_FunctionStatus;

}






Std_ReturnType GPIO_GetPinValue(u8 Copy_PortId , u8 Copy_PinId, u8 *Copy_PinReturnValue)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_PinReturnValue != NULL && Copy_PinId <= 15){
            switch (Copy_PortId)
            {
                
            case GPIO_PortA:
                *Copy_PinReturnValue = GET_BIT(GPIOPA_IDR , Copy_PinId);
                Local_FunctionStatus = E_OK;
                break;
            

            case GPIO_PortB:
                *Copy_PinReturnValue = GET_BIT(GPIOPB_IDR , Copy_PinId);
                Local_FunctionStatus = E_OK;
                break;


            case GPIO_PortC:
                *Copy_PinReturnValue = GET_BIT(GPIOPC_IDR , Copy_PinId);
                Local_FunctionStatus = E_OK;
                break;


            default:
                Local_FunctionStatus = E_NOT_OK;
                break;
            }
    }

    



    return Local_FunctionStatus;

}

#endif /**< GPIO_PROGRAM_C_ */