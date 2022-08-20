/*------------------------------- INCLUDE -------------------------------*/
#include "Led_Interface.h"
/*------------------------------- Global -------------------------------*/
u8 Global_u8Car_State=GREEN;
u8 Global_u8Toggle_Flag=FALSE;
u8 Global_u8Interrupt_Flag=FALSE;
/*------------------------- Led_INIT -------------------------*/
void Led_VidInitialization(void)
{
	DIO_VidSet_Pin_Value(P_Port, P_RED, HI);
	DIO_VidSet_Pin_Direction(C_Port, C_RED, OUTPUT);
	DIO_VidSet_Pin_Direction(C_Port, C_GRN, OUTPUT);
	DIO_VidSet_Pin_Direction(C_Port, C_YEL, OUTPUT);
	DIO_VidSet_Pin_Direction(P_Port, P_RED, OUTPUT);
	DIO_VidSet_Pin_Direction(P_Port, P_GRN, OUTPUT);
	DIO_VidSet_Pin_Direction(P_Port, P_YEL, OUTPUT);
}

/*------------------------- Toggle_Yellow -------------------------*/
void Private_VidToggle_Led(u32 Copy_u32Delay)
{
	u32 Local_u8Flag=FALSE;
	DIO_VidSet_Pin_Value(C_Port, C_YEL, LOW);
	DIO_VidSet_Pin_Value(P_Port, P_YEL, LOW);
	for(Local_u8Flag=Copy_u32Delay/500;Local_u8Flag;Local_u8Flag--)
	{
		Timer_2_VidBusy_Wait_ms(500);
		if(Global_u8Toggle_Flag)DIO_VidToggle_Pin_Value(P_Port,P_YEL);
		DIO_VidToggle_Pin_Value(C_Port,C_YEL);
		if(Global_u8Interrupt_Flag)
		{
			Global_u8Car_State=GREEN;
			Global_u8Interrupt_Flag=FALSE;
			break;
		}
	}
	DIO_VidSet_Pin_Value(C_Port, C_YEL, LOW);
	DIO_VidSet_Pin_Value(P_Port, P_YEL, LOW);
}
/*------------------------- Pedestrian_Mode -------------------------*/
void Led_VidPedestrian_Mode()
{
	u8 Local_u8Flag=FALSE;
	Timer_2_VidBusy_Wait_ms(1000);
	DIO_VidGet_Pin_Value(Port_D, Pin_2,&Local_u8Flag);
	if(Local_u8Flag)
	{
		if(Global_u8Car_State==DEFAULT)
		{
			DIO_VidSet_Pin_Value(P_Port, P_RED, LOW);
			DIO_VidSet_Pin_Value(P_Port, P_GRN, HI);
			Timer_2_VidBusy_Wait_ms(5000);
			DIO_VidSet_Pin_Value(C_Port, C_RED, LOW);
			Global_u8Toggle_Flag=TRUE;
			Private_VidToggle_Led(5000);
			Global_u8Toggle_Flag=FALSE;
			DIO_VidSet_Pin_Value(P_Port, P_GRN, LOW);
			DIO_VidSet_Pin_Value(P_Port, P_RED, HI);
			Global_u8Interrupt_Flag=TRUE;

		}
		else if(Global_u8Car_State==YELLOW)
		{
			DIO_VidSet_Pin_Value(C_Port, C_GRN, LOW);
			Global_u8Toggle_Flag=TRUE;
			Private_VidToggle_Led(5000);
			Global_u8Toggle_Flag=FALSE;
			DIO_VidSet_Pin_Value(P_Port, P_RED, LOW);
			DIO_VidSet_Pin_Value(P_Port, P_GRN, HI);
			DIO_VidSet_Pin_Value(C_Port, C_RED, HI);
			Timer_2_VidBusy_Wait_ms(5000);
			DIO_VidSet_Pin_Value(C_Port, C_RED, LOW);
			Global_u8Toggle_Flag=TRUE;
			Private_VidToggle_Led(5000);
			Global_u8Toggle_Flag=FALSE;
			DIO_VidSet_Pin_Value(P_Port, P_GRN, LOW);
			DIO_VidSet_Pin_Value(P_Port, P_RED, HI);
			Global_u8Interrupt_Flag=TRUE;
		}
		else
		{
			Global_u8Toggle_Flag=TRUE;
			Private_VidToggle_Led(5000);
			Global_u8Toggle_Flag=FALSE;
			DIO_VidSet_Pin_Value(P_Port, P_RED, LOW);
			DIO_VidSet_Pin_Value(P_Port, P_GRN, HI);
			DIO_VidSet_Pin_Value(C_Port, C_RED, HI);
			Timer_2_VidBusy_Wait_ms(5000);
			DIO_VidSet_Pin_Value(C_Port, C_RED, LOW);
			Global_u8Toggle_Flag=TRUE;
			Private_VidToggle_Led(5000);
			Global_u8Toggle_Flag=FALSE;
			DIO_VidSet_Pin_Value(P_Port, P_GRN, LOW);
			DIO_VidSet_Pin_Value(P_Port, P_RED, HI);
			Global_u8Interrupt_Flag=TRUE;
		}
	}
}
/*------------------------- Normal_Mode -------------------------*/
void Led_VidNormal_Mode()
{
	switch(Global_u8Car_State)
	{
		case GREEN:
			Global_u8Car_State=YELLOW;
			DIO_VidSet_Pin_Value(C_Port, C_GRN, HI);
			Timer_2_VidBusy_Wait_ms(5000);
			DIO_VidSet_Pin_Value(C_Port, C_GRN, LOW);
			break;
		case YELLOW:
			Global_u8Car_State=RED;
			DIO_VidSet_Pin_Value(C_Port, C_YEL, HI);
			Private_VidToggle_Led(5000);
			DIO_VidSet_Pin_Value(C_Port, C_YEL, LOW);
			break;
		case RED:
			Global_u8Car_State=DEFAULT;
			DIO_VidSet_Pin_Value(C_Port, C_RED, HI);
			Timer_2_VidBusy_Wait_ms(5000);
			DIO_VidSet_Pin_Value(C_Port, C_RED, LOW);
			break;
		default:
			Global_u8Car_State=GREEN;
			DIO_VidSet_Pin_Value(C_Port, C_YEL, HI);
			Private_VidToggle_Led(5000);
			DIO_VidSet_Pin_Value(C_Port, C_YEL, LOW);
			break;
	}
}
/*------------------------- OPTIONS FOR SINGLE BIN -------------------------*/
