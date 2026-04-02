/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 2 Apr 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : SPI_program.c                *********************/
/*********************************************************************************/
#ifndef     SPI_PROGRAM_C_
#define     SPI_PROGRAM_C_

/************************************< LIB >************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/************************************< MCAL >***********************************/
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
/*******************************************************************************/
Std_ReturnType Spi_init(void){

    // Resetting the registry
    SPI->CR1 = 0x0000;
    //          enable master        speed        internal slave      sw slave
    SPI->CR1 |= (1 << SPI_MSTR) | (3 << SPI_BR) | (1 << SPI_SSI) | (1 << SPI_SSM) ;
    // enable prephral
    SPI->CR1 |= (1 << SPI_SPE);

}


/****************************<Transmit function>*****************************/

u8 Spi_u8Transmit(u8 Copy_u8Data){
    // what TXE Bit to be empty
    while(GET_BIT(SPI->SR, SPI_TXE_FLAG) == 0);
    // send the data to DR register
    SPI->DR = Copy_u8Data;
    // check if the Bit 7 (BSY)  is not busy
    while(GET_BIT(SPI->SR , SPI_BSY_FLAG) == 1);
    // return the data
    return (u8)SPI->DR;
}
/****************************<Receive function>*****************************/
u8 Spi_u8Receive(void){
    SPI->DR = 0xFF;
    while (GET_BIT(SPI->SR ,SPI_RXNE_BUFFER) == 0);
    // read the data and return it
    return (u8)SPI->DR;
    
}


#endif