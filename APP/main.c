/**< lib includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< mcal includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "UART_private.h"
/**< HALS include */
#include "HGPS_interface.h"
#include "LCD_interface.h"


int main(void){
    // RCC INIT
    Rcc_InitSysClock();
    Rcc_EnablePeripheral(2 ,RCC_APB2);// gpio
    Rcc_EnablePeripheral(17, RCC_APB1); // uart
    Rcc_EnablePeripheral(12, RCC_APB2);

    GPIO_SetPinMode(GPIO_PortA , GPIO_PIN2, GPIO_OUTPUT_10MHZ_AF_PUSH_PULL);        //  TX pin
    GPIO_SetPinMode(GPIO_PortA , GPIO_PIN3, GPIO_INPUT_FLOATING);                   //  RX pin
    GPIO_SetPinMode(GPIO_PortA, GPIO_PIN5, GPIO_OUTPUT_10MHZ_PUSH_PULL);
    // init prepheral UART
    MUSART_voidInit(UART2, 9600);
    // init GPS (HAL)
    HGPS_voidInit();
    // init HLCD
    HLCD_voidInit();



    u8 GPS_u8Buffer[100];
    f32 Current_Altitude = 0;
    u8 Alt_Text[20];
    
    while(true){
        HGPS_voidGetFullSentence(GPS_u8Buffer);

        Current_Altitude = HGPS_f32GetAltitude(GPS_u8Buffer);


        ftoa(Current_Altitude, Alt_Text, 2);
        HLCD_voidPrintString(Alt_Text);
        
    }
}