#ifndef         HGPS_INTERFACE_H_
#define         HGPS_INTERFACE_H_

void HGPS_voidInit(void);
void HGPS_voidGetFullSentence(u8 *Copy_u8Buffer);
f32 HGPS_f32GetAltitude(u8 *Copy_u8FullSentence);


#endif
