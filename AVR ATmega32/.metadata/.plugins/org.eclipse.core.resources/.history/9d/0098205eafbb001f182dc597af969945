/***************************************************************************************************************
 * pwm.h
 * Author: Muhammed Ayman
 * Module: PWM
 **************************************************************************************************************/

#ifndef MCAL_PWM_H_
#define MCAL_PWM_H_

#include "../Standard_Types/standard_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NON_INVERTING = 2, INVERTING
}PWM_Mode;

typedef enum
{
	NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024
}Timer_ClockType;

typedef struct
{
	PWM_Mode mode;
	Timer_ClockType timer_clock;
	uint8 duty_cycle;
}Timer_ConfigType;

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Function to initialize Timer0 with Fast PWM mode.
 */
void PWM_Timer0_Start(const Timer_ConfigType * Config_Ptr);

#endif /* MCAL_PWM_H_ */
