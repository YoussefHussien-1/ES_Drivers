/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 26 Mar 2026                   *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : NVIC_interface.h             *********************/
/*********************************************************************************/


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef u8      IRQn_t;

Std_ReturnType NVIC_SetPriorityGrouping(u32 priority_grouping);
Std_ReturnType NVIC_EnableIRQ(IRQn_t IRQn);
Std_ReturnType NVIC_DisableIRQ(IRQn_t IRQn);
Std_ReturnType NVIC_GetPendingIRQ(IRQn_t IRQn);
Std_ReturnType NVIC_SetPendingIRQ(IRQn_t IRQn);
Std_ReturnType NVIC_ClearPendingIRQ(IRQn_t IRQn);
Std_ReturnType NVIC_GetActive(IRQn_t IRQn);
Std_ReturnType NVIC_SetPriority(IRQn_t IRQn, u32 Copy_Priority);
Std_ReturnType NVIC_GetPriority(IRQn_t IRQn);
Std_ReturnType NVIC_SystemReset(void);


#endif //NVIC_INTERFACE_H_
