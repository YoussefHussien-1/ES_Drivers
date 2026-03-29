/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Feb 2026                  *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : STK_interface.h              *********************/
/*********************************************************************************/

#ifndef     STK_INTERFACE_H_
#define     STK_INTERFACE_H_


Std_ReturnType STK_vInit(u32 CopyValue);

/**
 * @brief       ENABLE
 *              TICKINT
 *              CLKSOURCE
 *              COUNTFLAG
 */
void STK_vInit(u8 CopyValue);
Std_ReturnType STK_vSetBusyWait(u32 CopyLoad);
Std_ReturnType STK_voidSetIntervalSingle(u32 Copy_);
u32 STK_u32GetElapsedTime();
u32 STK_u32GetRemainingTime();



#endif