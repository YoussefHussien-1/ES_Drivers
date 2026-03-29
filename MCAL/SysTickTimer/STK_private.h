/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Feb 2026                  *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : STK_private.h                *********************/
/*********************************************************************************/



#ifndef     STK_PRIVATE_H_
#define     STK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS    0xE000E010

typedef struct 
{
    /* data */
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}SysTickTimer_t;

#define STK ((volatile SysTickTimer_t*)SYSTICK_BASE_ADDRESS)



#endif