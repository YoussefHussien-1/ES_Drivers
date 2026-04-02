/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 2 Apr 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : SPI_private.h                *********************/
/*********************************************************************************/


#ifndef     SPI_PRIVATE_H_
#define     SPI_PRIVATE_H_


#define SPI_BASE_ADDRESS        0x40013000


typedef struct 
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
}SPI_t;


#define     SPI     ((volatile SPI_t *)SPI_BASE_ADDRESS)




#endif