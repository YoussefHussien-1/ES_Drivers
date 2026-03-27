/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 26 Mar 2026                   *********************/
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



#define SCB_AIRCR (* (volatile u32 *) (0xE000ED00 + 0x0C))


/* تقسيم الـ 4 بت بتوع الـ Priority في STM32F103:
   بنسجل القيمة دي في Bits [10:8] في ريجيستر AIRCR
*/

// 16 Group (0..15) | 0 Sub-priority (كلهم يقطعوا بعض)
#define NVIC_GROUP_4_SUB_0    0x05FA0300 

// 8 Groups (0..7)  | 2 Sub-priority (0..1)
#define NVIC_GROUP_3_SUB_1    0x05FA0400 

// 4 Groups (0..3)  | 4 Sub-priority (0..3)
#define NVIC_GROUP_2_SUB_2    0x05FA0500 

// 2 Groups (0..1)  | 8 Sub-priority (0..7)
#define NVIC_GROUP_1_SUB_3    0x05FA0600 

// 0 Groups         | 16 Sub-priority (0..15) (محدش يقطع حد)
#define NVIC_GROUP_0_SUB_4    0x05FA0700


#endif /**< NVIC_PRIVATE_H_*/
