/***************************************************************************************************************
 * pwm.c
 * Author: Muhammed Ayman
 * Module: PWM
 **************************************************************************************************************/

#include "pwm.h"
#include <avr/io.h>

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Function to initialize Timer0 with Fast PWM mode.
 */
void PWM_Timer0_Start(const Timer_ConfigType * Config_Ptr)
{
	TCNT0 = 0; 							/* Set Timer Initial value. */

	OCR0  = (Config_Ptr->duty_cycle * 255) / 100; 	/* Set Compare Value. */

	DDRB  = DDRB | (1<<PB3); 			/* set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC. */

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | ((Config_Ptr->mode)<<COM00) | ((Config_Ptr->timer_clock)<<CS00);
}
