/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 2 Apr 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : I2C_private.h                *********************/
/*********************************************************************************/

#ifndef     I2C_PRIVATE_H_
#define     I2C_PRIVATE_H_

#define I2C1_BASE_ADDRESS       0x40005400
#define I2C2_BASE_ADDRESS       0x40005800

typedef struct 
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 OAR1;
    volatile u32 OAR2;
    volatile u32 DR;
    volatile u32 SR1;
    volatile u32 SR2;
    volatile u32 CCR;
    volatile u32 TRISE;
}I2C_t;

#define I2C1 ((volatile I2C_t*)I2C1_BASE_ADDRESS)
#define I2C2 ((volatile I2C_t*)I2C2_BASE_ADDRESS)

#endif