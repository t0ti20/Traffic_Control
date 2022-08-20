/*------------------------------- INCLUDE -------------------------------*/
#include "Button_Interface.h"
/*------------------------- BUTTON_INIT -------------------------*/
void Button_VidInitialization(void)
{
	DIO_VidInternal_Pin_Bull_Up(BUTTON_PORT, BUTTON_PIN);
	External_Interrupt_0(Led_VidPedestrian_Mode);
	External_Interrupt_VidInitialization(Interrupt_0,Falling_Edge);
}
/*------------------------- OPTIONS FOR SINGLE BIN -------------------------*/
