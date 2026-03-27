#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

/* الـ Ports اللي الـ User هيختار منها */
#define AFIO_PORTA    0b0000
#define AFIO_PORTB    0b0001
#define AFIO_PORTC    0b0010

/* الدالة الوحيدة اللي محتاجينها للـ EXTI */
void AFIO_vSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8Port);

#endif