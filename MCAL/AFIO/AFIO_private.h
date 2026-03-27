#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

#define AFIO_BASE_ADDRESS    0x40010000

typedef struct {
    volatile u32 EVCR;      
    volatile u32 MAPR;      
    volatile u32 EXTICR[4]; // أهم ريجيسترات (EXTICR1 to EXTICR4)
    volatile u32 MAPR2;     
} AFIO_t;

#define AFIO    ((volatile AFIO_t*)AFIO_BASE_ADDRESS)

#endif