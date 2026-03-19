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
    Std_ReturnType Local_FuncitonStatus = E_NOT_OK;

    switch (Copy_PortId)
    {
    case GPIO_PortA:
        if(Copy_PinId >= 0 && Copy_PinId <= 7){

        }else if(Copy_PinId >= 8 && Copy_PinId <= 15){

        }else{
            #error "Unvalid Pin the range SHOULD BE BETWEEN 0 to 15";
            Local_FuncitonStatus = E_NOT_OK;
        }

        break;
    

    case GPIO_PortB:
        if(Copy_PinId >= 0 && Copy_PinId <= 7){

        }else if(Copy_PinId >= 8 && Copy_PinId <= 15){

        }else{
            #error "Unvalid Pin the range SHOULD BE BETWEEN 0 to 15";
            Local_FuncitonStatus = E_NOT_OK;
        }

        break;


    case GPIO_PortC:
        if(Copy_PinId >= 0 && Copy_PinId <= 7){

        }else if(Copy_PinId >= 8 && Copy_PinId <= 15){

        }else{
            #error "Unvalid Pin the range SHOULD BE BETWEEN 0 to 15";
            Local_FuncitonStatus = E_NOT_OK;
        }

        break;


    default:
        Local_FuncitonStatus = E_NOT_OK
        break;
    }



    return Local_FuncitonStatus;
}



#endif /**< GPIO_PROGRAM_C_ */