/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Feb 2026                  *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : RCC_program.c                *********************/
/*********************************************************************************/


#ifndef     RCC_PROGRAM_C_
#define     RCC_PROGRAM_C_ 

/************************************< LIB >************************************/
#include "STD_TYPES.h"      // Standard data types definitions
#include "BIT_MATH.h"       // Bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT)
/************************************< MCAL >***********************************/
#include "RCC_interface.h" // RCC interface header (API exposed to user)
#include "RCC_private.h"   // RCC private registers and bit definitions
#include "RCC_config.h"    // RCC user configuration (system clock settings)


/*=================================================================================
  @Function: Rcc_InitSysClock
  @Description: Initializes the system clock based on RCC_CONFIG settings.
                Supports HSE, HSI, and PLL system clock sources.
  @Parameters: None
  @Return: Std_ReturnType
           - E_OK: Clock successfully initialized
           - E_NOT_OK: Initialization failed
=================================================================================*/



Std_ReturnType Rcc_InitSysClock(void){

    Std_ReturnType Local_FuncitonStatus = E_NOT_OK;

    #if RCC_SYSCLK == RCC_HSE
        
        /**< Select Which External Clock will be entered into the system */
        #if RCC_CLK_BYPASS == RCC_RC_CLK_
        SET_BIT(RCC_CR , RCC_CR_HSEBYP);
        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
        CLR_BIT(RCC_CR , RCC_CR_HSEBYP);


        #else
            #error "Wrong set of clock !"

        #endif // RCC_CLK_BYPASS
        /**< Enable HSE*/
        SET_BIT(RCC_CR, RCC_CR_HSEON);

        /**< wait until the CLK be stable */
        while(!GET_BIT(RCC_CR , RCC_CR_HSERDY));

        /**< select the external clk to be the system clock */

        RCC_CFGR = 0x00000001;

        Local_FuncitonStatus = E_OK;


    #elif RCC_SYSCLK == RCC_HSI
        /**< Enable */
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< wait until the CLK be stable */
        while(!GET_BIT(RCC_CR , RCC_CR_HSIRDY));

        /**< select the external clk to be the system clock */

        RCC_CFGR = 0x00000000;

        Local_FuncitonStatus = E_OK;



    #elif RCC_SYSCLK == RCC_PLL
        /**< Enable */
        SET_BIT(RCC_CR, RCC_CR_PLLON);

        /**< wait until the CLK be stable */
        while(!GET_BIT(RCC_CR , RCC_CR_PLLRDY));

        /**< select the external clk to be the system clock */

        RCC_CFGR = 0x00000010;


        Local_FuncitonStatus = E_OK;

    #else
        #error "WRONG SYSTEM CLOCK YOU MUST ENTER A CLK SYSTEM BETWEEN THESE SYSTEMS (HSI, HSE , PLL)"
    #endif // RCC_SYSCLK


    return Local_FuncitonStatus;
}



/*=================================================================================
  @Function: Rcc_EnablePeripheral
  @Description: Enables the clock for a specific peripheral on a specified bus.
  @Parameters:
     - Copy_PeripheralId: Peripheral identifier (as defined in RCC_interface.h)
     - Copy_BusId: Bus identifier (RCC_AHB, RCC_APB1, RCC_APB2)
  @Return: Std_ReturnType
           - E_OK: Peripheral clock enabled successfully
           - E_NOT_OK: Invalid bus or peripheral ID
=================================================================================*/


Std_ReturnType Rcc_EnablePeripheral(u8 Copy_PeripheralId , u8 Copy_BusId){
    Std_ReturnType Local_FuncitonStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    case RCC_AHB:
        SET_BIT(RCC_AHBENR , Copy_PeripheralId);
        Local_FuncitonStatus = E_OK;

        break;


    case RCC_APB1: 
        SET_BIT(RCC_APB1ENR , Copy_PeripheralId);
        Local_FuncitonStatus = E_OK;

        break;


    case RCC_APB2:
        SET_BIT(RCC_APB2ENR , Copy_PeripheralId);
        Local_FuncitonStatus = E_OK;

        break;


    default:
        Local_FuncitonStatus = E_NOT_OK;
        break;
    }

    return Local_FuncitonStatus;
 
}

/*=================================================================================
  @Function: Rcc_DisablePeripheral
  @Description: Disables the clock for a specific peripheral on a specified bus.
  @Parameters:
     - Copy_PeripheralId: Peripheral identifier (as defined in RCC_interface.h)
     - Copy_BusId: Bus identifier (RCC_AHB, RCC_APB1, RCC_APB2)
  @Return: Std_ReturnType
           - E_OK: Peripheral clock disabled successfully
           - E_NOT_OK: Invalid bus or peripheral ID
=================================================================================*/


Std_ReturnType Rcc_DisablePeripheral(u8 Copy_PeripheralId , u8 Copy_BusId){
    Std_ReturnType Local_FuncitonStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    case RCC_AHB:
        CLR_BIT(RCC_AHBENR , Copy_PeripheralId);
        Local_FuncitonStatus = E_OK;

        break;


    case RCC_APB1: 
        CLR_BIT(RCC_APB1ENR , Copy_PeripheralId);
        Local_FuncitonStatus = E_OK;

        break;


    case RCC_APB2:
        CLR_BIT(RCC_APB2ENR , Copy_PeripheralId);
        Local_FuncitonStatus = E_OK;

        break;

        
    default:
        Local_FuncitonStatus = E_NOT_OK;
        break;
    }

    return Local_FuncitonStatus;
}




#endif // RCC_PROGRAM_C_