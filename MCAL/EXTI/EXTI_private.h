/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : EXTI_private.h               *********************/
/*********************************************************************************/


#ifndef     EXTI_PRIVATE_H_
#define     EXTI_PRIVATE_H_



#define EXTI_BASE_ADDRESS           0x40010400


typedef struct
{
    /* data */
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define EXTI ((volatile EXTI_t *)EXTI_BASE_ADDRESS)


#endif //EXTI_PRIVATE_H_