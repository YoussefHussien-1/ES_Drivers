/**< LIB file calling */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/**< MCAL file calling */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

Rcc_InitSysClock();// this function to initiat the clock
Rcc_EnablePeripheral(RCC_APB2, 2); // enable gpio port a
Rcc_EnablePeripheral(RCC_APB2, 4); // enable gpio port c
Rcc_EnablePeripheral(RCC_APB2, 0); // enable afio

// define pins of gpio

GPIO_SetPinMode(GPIO_PortA , GPIO_PIN0, GPIO_INPUT_PULL_UP_OR_DOWN);
GPIO_SetPinValue(GPIO_PortA , GPIO_PIN0, GPIO_HIGH);


GPIO_SetPinMode(GPIO_PortC , GPIO_PIN13, GPIO_OUTPUT_2MHZ_PUSH_PULL);



AFIO_vSetEXTIConfiguration(EXTI_LINE0, AFIO_PORTA);


EXTI_vSetSignalLatch(EXTI_LINE0, EXTI_FTSR);
EXTI_vEnableLine(EXTI_LINE0);


NVIC_EnableIRQ(6);


while (1);


/* دالة الـ Interrupt (الـ Handler) */
void EXTI0_IRQHandler(void)
{
    // Toggle للـ LED
    static u8 flag = 0;
    if(flag == 0){
        GPIO_SetPinValue(GPIO_PortA , GPIO_PIN0, GPIO_LOW);
        flag = 1;
    }else{
        GPIO_SetPinValue(GPIO_PortA , GPIO_PIN0, GPIO_HIGH);
        flag = 0;
    }

    // مهم جداً: امسح العلم عشان ميفضلش يدخل هنا للأبد
    EXTI_vClearPendingFlag(EXTI_LINE0);

}

