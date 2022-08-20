#ifndef LED_CONFIGURE_H_
#define LED_CONFIGURE_H_
/* CAR Pin Connection */
#define C_Port	Port_A
#define C_RED	Pin_2
#define C_GRN	Pin_0
#define C_YEL	Pin_1
/* Pedestrian Pin Connection */
#define P_Port	Port_B
#define P_RED	Pin_2
#define P_GRN	Pin_0
#define P_YEL	Pin_1
/* Type_Def */
typedef enum {GREEN,YELLOW,RED,DEFAULT}Traffic;
#endif
/* LED_CONFIGURE_H_ */
