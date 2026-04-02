/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 2 Apr 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : SPI_interface.h              *********************/
/*********************************************************************************/
#ifndef     SPI_INTERFACE_H_
#define     SPI_INTERFACE_H_

Std_ReturnType Spi_init(void);
u8 Spi_u8Transmit(u8 Copy-u8Data);
u8 Spi_u8Receive(void);
#endif