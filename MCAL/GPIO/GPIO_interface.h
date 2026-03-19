/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 6 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : GPIO_interface.h             *********************/
/*********************************************************************************/


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#define GPIO_OUTPUT                0
#define GPIO_INPUT                 1



/**< define the port of GPIO */

#define GPIO_PortA       0
#define GPIO_PortB       1
#define GPIO_PortC       2

Std_ReturnType GPIO_SetPinMode(u8 Copy_PortId , u8 Copy_PinId, u8 Copy_PinMode);

#endif /**< GPIO_CONFIG_H_ */