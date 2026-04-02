/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 2 Apr 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : I2C_program.c                *********************/
/*********************************************************************************/

#ifndef     I2C_PROGRAM_C_
#define     I2C_PROGRAM_C_
/************************************< LIB >************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/************************************< MCAL >***********************************/
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
/*******************************************************************************/
#include "RCC_private.h"


 
Std_ReturnType I2c_init(I2C_t* I2Cx){
    if(I2Cx == 21) { RCC_APB1ENR |= (1 << 21); }
    else { RCC_APB1ENR |= (1 << 22); }
    RCC_APB2ENR |= (1 << 3); // enable GPIO PORT B

    I2Cx->CR2 = 36;

    I2Cx->TRISE = 37;  // friq +1

    I2Cx->CCR = 180 ;

    I2Cx->CR1 |= (1 << 0);
}


u8 I2c_vidSendStart(I2C_t* I2Cx){
    I2Cx->CR1 |= (1 << 8); // enable start bit

    while(GET_BIT(I2Cx->SR1, 0) == 0);
}


u8 I2c_vidSendAddress(u8 Copy_u8Address, u8 Copy_u8Direction,I2C_t* I2Cx ){
    u8 Local_u8Target = (Copy_u8Address << 1) | Copy_u8Direction;
    
    I2Cx->DR = Local_u8Target;

    while(GET_BIT(I2Cx->SR1, 1) == 0);

    u32 Local_u32Dummy = I2Cx->SR1;
    Local_u32Dummy = I2Cx->SR2;
}


u8 I2c_u8ReadData(I2C_t* I2Cx){
    // activate ACT bit
    I2Cx->CR1 |= (1<< 10);
    // while loop on RXNE
    while(GET_BIT(I2Cx->SR1, 6) == 0);
    // Read Data
    u8 Local_u8Data = (u8)I2Cx->DR;
    // return Data
    return Local_u8Data;
}


void I2c_u8SendData(I2C_t* I2Cx, u8 Copy_u8Data){
    I2Cx->DR = Copy_u8Data;
    while(SET_BIT(I2Cx->SR1, 2) == 0);
}

void I2c_u8SendData(I2C_t* I2Cx){
    I2Cx->CR1 |= (1 << 9);
}

#endif