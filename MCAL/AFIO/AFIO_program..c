#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void AFIO_vSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8Port)
{
    u8 Local_u8RegIndex = 0;
    
    /* 1. حدد إحنا في أنهي ريجيستر من الـ 4 (كل ريجيستر فيه 4 خطوط) */
    Local_u8RegIndex = Copy_u8Line / 4;
    
    /* 2. حدد مكان الـ 4 بت بتوع الخط ده جوه الريجيستر */
    u8 Local_u8Shift = (Copy_u8Line % 4) * 4;
    
    /* 3. صفر الـ 4 بت القدام عشان نحط القيمة الجديدة (Masking) */
    AFIO->EXTICR[Local_u8RegIndex] &= ~( (0x0F) << Local_u8Shift );
    
    /* 4. حط قيمة البورت (A أو B أو C) في المكان المظبوط */
    AFIO->EXTICR[Local_u8RegIndex] |=  ( (Copy_u8Port) << Local_u8Shift );
}