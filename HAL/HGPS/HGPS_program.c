#ifndef         HGPS_PROGRAM_C_
#define         HGPS_PROGRAM_C_

#include <stdlib.h> 
/*********************<LIB>********************* */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************<HAL>********************* */
#include "HGPS_interface.h"
#include "HGPS_private.h"
#include "HGPS_config.h"

/*********************<interfaces>**************  */
#include "UART_interface.h"
/*********************<privates>**************  */
#include "UART_private.h"

/*********************<CODE>********************* */

void HGPS_voidInit(){
    MUSART_voidInit(UART2, 9600 );
}

void HGPS_voidGetFullSentence(u8 *Copy_u8Buffer)
{
    u8 Local_u8ReceivedChar = 0;
    u8 i = 0;

    while (UART_u8Receive(UART2) != '$');

    WHILE(1){
        Local_u8ReceivedChar = UART_u8Receive(UART2);
        if (UART_u8Receive(UART2) == '\n' || '*')
        {
            Copy_u8Buffer[i] = '\0';
            break;
        }
        Copy_u8Buffer[i] = Local_u8ReceivedChar;
        i++;
        
    }
    
}

f32 HGPS_f32GetAltitude(u8 *Copy_u8FullSentence) {
    u8 Local_u8CommaCounter = 0;
    u8 Local_u8AltBuffer[12]; 
    u8 i = 0; 
    u8 j = 0; 
    f32 Local_f32AltitudeValue = 0;

    for (i = 0; Copy_u8FullSentence[i] != '\0'; i++) {
        if (Copy_u8FullSentence[i] == ',') {
            Local_u8CommaCounter++;
        }
        
        if (Local_u8CommaCounter == 9 && Copy_u8FullSentence[i] != ',') {
            Local_u8AltBuffer[j] = Copy_u8FullSentence[i];
            j++;
        }
        
        if (Local_u8CommaCounter == 10) {
            break;
        }
    }

    Local_u8AltBuffer[j] = '\0';

  
    Local_f32AltitudeValue = atof((char*)Local_u8AltBuffer);

    return Local_f32AltitudeValue;
}

#endif