/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 6 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : GPIO_private.h               *********************/
/*********************************************************************************/



#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/**< Base Addresses */
#define GPIO_PORTA_BASE_ADDRESS     0x40010800
#define GPIO_PORTB_BASE_ADDRESS     0x40010C00
#define GPIO_PORTC_BASE_ADDRESS     0x40011000

/**< Offset of GPIO PORT A*/
#define GPIOPA_CRL    (* (volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x00))
#define GPIOPA_CRH    (* (volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x04))
#define GPIOPA_IDR     (* (volatile u32 *) (GPIO_PORTA_BASE_ADDRESS +0x08))
#define GPIOPA_ODR    (* (volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x0C))
#define GPIOPA_BSRR   (* (volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x10))
#define GPIOPA_BRR    (* (volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x14))
#define GPIOPA_LCKR   (* (volatile u32 *) (GPIO_PORTA_BASE_ADDRESS + 0x18))

/**< Offset of GPIO PORT B*/
#define GPIOPB_CRL    (* (volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x00))
#define GPIOPB_CRH    (* (volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x04))
#define GPIOPB_IDR     (* (volatile u32 *) (GPIO_PORTB_BASE_ADDRESS +0x08))
#define GPIOPB_ODR    (* (volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x0C))
#define GPIOPB_BSRR   (* (volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x10))
#define GPIOPB_BRR    (* (volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x14))
#define GPIOPB_LCKR   (* (volatile u32 *) (GPIO_PORTB_BASE_ADDRESS + 0x18))


/**< Offset of GPIO PORT C*/
#define GPIOPC_CRL    (* (volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x00))
#define GPIOPC_CRH    (* (volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x04))
#define GPIOPC_IDR     (* (volatile u32 *) (GPIO_PORTC_BASE_ADDRESS +0x08))
#define GPIOPC_ODR    (* (volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x0C))
#define GPIOPC_BSRR   (* (volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x10))
#define GPIOPC_BRR    (* (volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x14))
#define GPIOPC_LCKR   (* (volatile u32 *) (GPIO_PORTC_BASE_ADDRESS + 0x18))







#endif /**< GPIO_PRIVATE_H_ */