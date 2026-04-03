#ifndef     LCD_INTERFACE_H_
#define     LCD_INTERFACE_H_

void HLCD_voidInit(void);
void HLED_voidSetColor(u8 Copy_u8Red, u8 Copy_u8Green, u8 Copy_u8Blue);
void ftoa(f32 Copy_f32Value, u8 *Add_u8String, u8 Copy_u8DecimalPlaces);
void HLCD_voidPrintString(u8 *string);


#endif