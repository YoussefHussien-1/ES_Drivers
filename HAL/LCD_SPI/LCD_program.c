#ifndef     LCD_PROGRAM_C_
#define     LCD_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "GPIO_interface.h"



void HLCD_voidInit(void){
    Spi_init();
}

void itoa(s32 Copy_s32Number, u8 *Add_u8String, u8 Copy_u8Base) {
    // 1. Variables
    u8 i = 0;
    u8 isNegative = 0;

    // أ- التعامل مع الأرقام السالبة
    if (Copy_s32Number < 0) {
        isNegative = 1;
        Copy_s32Number = -Copy_s32Number; // خليه موجب عشان نشتغل عليه
    }

    // ب- تقطيع الرقم واستخراج الحروف (بالشقلوب)
    do {
        // باقي القسمة بيجيب آخر رقم
        u8 rem = Copy_s32Number % Copy_u8Base;
        // تحويل الرقم لحرف (لو أكبر من 9 بيبقى حرف A, B.. عشان الـ Hexadecimal)
        Add_u8String[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        Copy_s32Number = Copy_s32Number / Copy_u8Base;
    } while (Copy_s32Number != 0);

    // ج- إضافة علامة السالب لو كان الرقم سالب
    if (isNegative) {
        Add_u8String[i++] = '-';
    }

    Add_u8String[i] = '\0'; // قفل النص بـ Null Terminator

    // د- عكس النص (لأننا طلعناه من اليمين للشمال)
    // هنبدل أول حرف بآخر حرف وهكذا
    u8 start = 0;
    u8 end = i - 1;
    while (start < end) {
        u8 temp = Add_u8String[start];
        Add_u8String[start] = Add_u8String[end];
        Add_u8String[end] = temp;
        start++;
        end--;
    }
}

void HLED_voidSetColor(u8 Copy_u8Red, u8 Copy_u8Green, u8 Copy_u8Blue){
    GPIO_SetPinValue(GPIO_PortA, GPIO_PIN5,GPIO_HIGH);

    Spi_u8Transmit(Copy_u8Red);
    Spi_u8Transmit(Copy_u8Green);
    Spi_u8Transmit(Copy_u8Blue);

    GPIO_SetPinValue(GPIO_PortA, GPIO_PIN5,GPIO_LOW);
}

void ftoa(f32 Copy_f32Value, u8 *Add_u8String, u8 Copy_u8DecimalPlaces){
    s32 Local_s32IntegarPart = Copy_f32Value;
    itoa(Local_s32IntegarPart , Add_u8String, 10);
    u8 i = 0;
    while (Add_u8String[i] != '\0') { i++; } // بنمشي لغاية آخر النص
    Add_u8String[i] = '.';                   // بنحط النقطة
    Add_u8String[i + 1] = '\0';              // بنقفل النص مؤقتاً
    f32 Local_f32Fraction = Copy_f32Value - (f32)Local_s32IntegarPart; // النتيجة: 0.45
    for (u8 j = 0; j < Copy_u8DecimalPlaces; j++) {
        Local_f32Fraction *= 10;
    }

    // هـ- تحويل الكسر اللي بقى صحيح (45) لنص وضمه للمخزن الرئيسي
    itoa((s32)Local_f32Fraction, Add_u8String + i + 1, 10);
}



void HLCD_voidPrintString(char *string) {

    if (string != '\0') {

        while (*string != '\0') {
            HLCD_voidSendChar(*string); 
            string++; 
        }
    }
}




#endif