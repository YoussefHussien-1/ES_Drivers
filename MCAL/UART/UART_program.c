#ifndef     UART_PROGRAM_C_
#define     UART_PROGRAM_C_
/*********************<LIB>********************* */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************<MCAL>******************** */
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
/*********************************************** */

void MUSART_voidInit(UART_t *UARTx, u32 Copy_u32BaudRate){
    UARTx->BRR = Copy_u32BaudRate;
    // reciever enable
    SET_BIT(UARTx->CR1, 2);
    // transmite enable
    SET_BIT(UARTx->CR1, 3);

    // UART enable
    SET_BIT(UARTx->CR1, 13);
}


void UART_voidTransmit(UART_t *UARTx, u8 Copy_u8Data ){
    // wait to pin 7 to return 1 to send the new data to register DR
    while (GET_BIT(UARTx->SR, 7) == 0);
    // sending the data to register DR
    UARTx->DR = Copy_u8Data;    
}

u8 UART_u8Receive(UART_t *UARTx){
    // waiting to recieve the data
    while(GET_BIT(UARTx->SR, 5) == 0 );
    // return the data
    return UARTx->DR;

}

void MUSART1_voidSendString(UART_t *UARTx ,u8 *Copy_ptrString){
    u8 i = 0;
    while (Copy_ptrString[i] != '\0')
    {
        /* code */
        UART_voidTransmit(UARTx, Copy_ptrString[i]);
        i++;
    }
    
}


#endif