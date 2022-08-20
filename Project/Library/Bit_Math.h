/*MACROS*/
#ifndef _MACROS_
#define _MACROS_
/*-------------- File Guard ------------------*/

/* BIT MATH.H */
#define Set_Bit(Reg,Bit_Num)  Reg|=1<<Bit_Num		/* Set Bit */
#define Clear_Bit(Reg,Bit_Num)  Reg&=~(1<<Bit_Num)	/* Clear Bit */
#define Toggle_Bit(Reg,Bit_Num)  Reg^=(1<<Bit_Num)	/* Toggle Bit */
#define Get_Bit(Reg,Bit_Num)   ((Reg>>Bit_Num)&1)		/* Get_Bit */

/*-------------- File Guard ------------------*/
#endif