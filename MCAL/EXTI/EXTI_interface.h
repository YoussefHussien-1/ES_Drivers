/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : EXTI_interface.h             *********************/
/*********************************************************************************/


#ifndef     EXTI_INTERFACE_H_
#define     EXTI_INTERFACE_H_
#include "LIB/STD_TYPES.h"




/* Prototypes */
Std_ReturnType EXTI_vEnableLine(u8 Copy_Line);
Std_ReturnType EXTI_vDisableLine(u8 Copy_Line);
Std_ReturnType EXTI_vSetSignalLatch(u8 Copy_Line, u8 Copy_Mode);
Std_ReturnType EXTI_vSoftwareTrigger(u8 Copy_Line);
Std_ReturnType EXTI_vClearPendingFlag(u8 Copy_Line);


#endif //EXTI_INTERFACE_H_