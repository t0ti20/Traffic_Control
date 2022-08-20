/* Include */
#include "app.h"
/****************** MAIN *********************/
int main(void)
{
	APP_startVid();
}
/*************** APP_startVid *****************/
void APP_startVid(void)
{
	Button_VidInitialization();
	Led_VidInitialization();
	DIO_VidGlobal_Interrupt_Enable();
	while(TRUE)
	{
		Led_VidNormal_Mode();
	}
}
