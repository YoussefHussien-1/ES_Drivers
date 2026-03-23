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


/**<. define the pins number */
#define GPIO_PIN0        0
#define GPIO_PIN1        1
#define GPIO_PIN2        2
#define GPIO_PIN3        3
#define GPIO_PIN4        4
#define GPIO_PIN5        5
#define GPIO_PIN6        6
#define GPIO_PIN7        7
#define GPIO_PIN8        8
#define GPIO_PIN9        9
#define GPIO_PIN10       10
#define GPIO_PIN11       11
#define GPIO_PIN12       12
#define GPIO_PIN13       13
#define GPIO_PIN14       14
#define GPIO_PIN15       15


/**<. define the MODES */

#define GPIO_INPUT_ANALOG                  0b0000
#define GPIO_INPUT_FLOATING                0b0100
#define GPIO_INPUT_PULL_UP_OR_DOWN         0b1000


#define GPIO_OUTPUT_10MHZ_PUSH_PULL        0b0001
#define GPIO_OUTPUT_10MHZ_OPEN_DRAIN       0b0101
#define GPIO_OUTPUT_10MHZ_AF_PUSH_PULL     0b1001
#define GPIO_OUTPUT_10MHZ_AF_OPEN_DRAIN    0b1101




#define GPIO_OUTPUT_2MHZ_PUSH_PULL          0b0010
#define GPIO_OUTPUT_2MHZ_OPEN_DRAIN         0b0110
#define GPIO_OUTPUT_2MHZ_AF_PUSH_PULL       0b1010
#define GPIO_OUTPUT_2MHZ_AF_OPEN_DRAIN      0b1110




#define GPIO_OUTPUT_50MHZ_PUSH_PULL         0b0011
#define GPIO_OUTPUT_50MHZ_OPEN_DRAIN        0b0111
#define GPIO_OUTPUT_50MHZ_AF_PUSH_PULL      0b1011
#define GPIO_OUTPUT_50MHZ_AF_OPEN_DRAIN     0b1111



/**< define the high and low */
#define GPIO_LOW    0
#define GPIO_HIGH   1



Std_ReturnType GPIO_SetPinMode(u8 Copy_PortId , u8 Copy_PinId, u8 Copy_PinMode);

#endif /**< GPIO_CONFIG_H_ */