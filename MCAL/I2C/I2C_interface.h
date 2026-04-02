/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 2 Apr 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : I2C_interface.h              *********************/
/*********************************************************************************/

#ifndef     I2C_INTERFACE_H_
#define     I2C_INTERFACE_H_



Std_ReturnType I2c_init(u8 I2Cx);
u8 I2c_vidSendStart(void);
u8 I2c_vidSendAddress(u8 Copy_u8Address, u8 Copy_u8Direction);
u8 I2c_u8ReadData(I2C_t* I2Cx);
void I2c_u8SendData(I2C_t* I2Cx, u8 Copy_u8Data);
void I2c_u8SendData(I2C_t* I2Cx);




#endif