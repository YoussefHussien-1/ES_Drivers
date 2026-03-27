/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 6 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : NVIC_private.h               *********************/
/*********************************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS       0xE000E100

#define NVIC_ISER (*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x000))


#define NVIC_ICER (*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x080))


#define NVIC_ISPR (*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x100))


#define NVIC_ICPR (*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x180))



#define NVIC_IABR (*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x200))



#define NVIC_IPR (*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x300))





#endif /**< NVIC_PRIVATE_H_*/
