/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Feb 2026                  *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : RCC_config.h                 *********************/
/*********************************************************************************/


#ifndef     RCC_CONFIG_H_
#define     RCC_CONFIG_H_ 

/*=================================================================================
  @Module: RCC Configuration
  @Description: This header file contains user-configurable settings for the
                Reset and Clock Control (RCC) module. The user can select the
                system clock source and related options here.
=================================================================================*/

/*------------------- System Clock Selection -------------------*/
#define RCC_SYSCLK       RCC_HSE
/* 
   Select the system clock source:
   Options:
   - RCC_HSE : High-Speed External clock (from crystal/oscillator)
   - RCC_HSI : High-Speed Internal clock (internal RC oscillator)
   - RCC_PLL : Phase-Locked Loop output (can multiply frequency)
*/

/*------------------- HSE Specific Configuration -------------------*/
#if RCC_SYSCLK == RCC_HSE
#define RCC_CLK_BYPASS      RCC_RC_CLK_
/**<
   If using HSE, you can configure whether to use an external oscillator
   or an external RC clock.
   - RCC_RC_CLK_: Use external RC clock
   - RCC_XTAL_CLK_: Use external crystal
*/
#endif // RCC_SYSCLK == RCC_HSE

#endif // RCC_CONFIG_H_