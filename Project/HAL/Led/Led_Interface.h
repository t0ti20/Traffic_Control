#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
/* Include */
#include "Led_Configure.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer/Timer_Interface.h"
/* Functions */

void Led_VidInitialization(void);
void Led_VidNormal_Mode(void);
void Led_VidPedestrian_Mode (void);
void Private_VidToggle_Led(u32 Copy_u32Delay);

#endif
/* LED_INTERFACE_H_ */
