#ifndef     UART_PRIVATE_H_
#define     UART_PRIVATE_H_




#define    UART2_BASE_ADDRESS       0x40004400
#define    UART3_BASE_ADDRESS       0x40004800
#define    UART4_BASE_ADDRESS       0x40004C00
#define    UART5_BASE_ADDRESS       0x40005000

typedef struct 
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;
}UART_t;

#define UART2 ((volatile UART_t *)UART2_BASE_ADDRESS)
#define UART3 ((volatile UART_t *)UART3_BASE_ADDRESS)
#define UART4 ((volatile UART_t *)UART4_BASE_ADDRESS)
#define UART5 ((volatile UART_t *)UART5_BASE_ADDRESS)


#endif