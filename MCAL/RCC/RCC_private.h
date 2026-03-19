/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Feb 2026                  *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : RCC_private.h                *********************/
/*********************************************************************************/


#ifndef     RCC_PRIVATE_H_
#define     RCC_PRIVATE_H_ 

/*=================================================================================
  @Module: RCC Private Definitions
  @Description: This header file contains the private register definitions,
                bit positions, and constants for the Reset and Clock Control (RCC)
                module. These are hardware-specific and should not be modified
                by the user directly.
=================================================================================*/

/*------------------- RCC Registers Base Address -------------------*/
#define RCC_CR       (*(volatile u32 *)(0x40021000 + 0x00))  // Control register
#define RCC_CFGR     (*(volatile u32 *)(0x40021000 + 0x04))  // Clock configuration register
#define RCC_CIR      (*(volatile u32 *)(0x40021000 + 0x08))  // Clock interrupt register
#define RCC_APB2RSTR (*(volatile u32 *)(0x40021000 + 0x0C))  // APB2 peripheral reset register
#define RCC_APB1RSTR (*(volatile u32 *)(0x40021000 + 0x10))  // APB1 peripheral reset register
#define RCC_AHBENR   (*(volatile u32 *)(0x40021000 + 0x14))  // AHB peripheral clock enable register
#define RCC_APB2ENR  (*(volatile u32 *)(0x40021000 + 0x18))  // APB2 peripheral clock enable register
#define RCC_APB1ENR  (*(volatile u32 *)(0x40021000 + 0x1C))  // APB1 peripheral clock enable register
#define RCC_BDCR     (*(volatile u32 *)(0x40021000 + 0x20))  // Backup domain control register
#define RCC_CSR      (*(volatile u32 *)(0x40021000 + 0x24))  // Control/status register

/*------------------- RCC_CR Register Bit Positions -------------------*/
#define RCC_CR_HSION    0   // Internal High-Speed clock enable
#define RCC_CR_HSERDY   17  // HSE clock ready flag
#define RCC_CR_HSEON    16  // HSE clock enable
#define RCC_CR_HSEBYP   18  // HSE clock bypass
#define RCC_CR_HSIRDY   1   // HSI clock ready flag
#define RCC_CR_PLLON    24  // PLL enable
#define RCC_CR_PLLRDY   25  // PLL clock ready flag

/*------------------- Clock Source Identifiers -------------------*/
#define RCC_HSI     0   // High-Speed Internal oscillator
#define RCC_HSE     1   // High-Speed External oscillator
#define RCC_PLL     2   // Phase-Locked Loop

/*------------------- HSE Clock Source Type -------------------*/
#define RCC_CRYSTAL_CLK_    0   // External crystal oscillator
#define RCC_RC_CLK_         1   // External RC oscillator

#endif // RCC_PRIVATE_H_