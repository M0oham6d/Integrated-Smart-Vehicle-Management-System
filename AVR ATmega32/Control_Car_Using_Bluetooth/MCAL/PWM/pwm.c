/******************************************************************************
 * Module       : PWM
 * File Name    : pwm.c
 * Author       : A7la Team :)
 * Created on   : 15/11/2024
 * Description  : Source file for the PWM AVR driver
 *******************************************************************************/
#include "pwm.h"
#include <avr/io.h>

/*******************************************************************************
 *                       Functions Definitions                                 *
 *******************************************************************************/

/*
 * Function to initialize Timer0 with Fast PWM mode.
 */
void PWM_Timer0_Start(const Timer_ConfigType * Config_Ptr)
{
    TCNT0 = 0;  /* Set Timer Initial value. */

    OCR0  = (Config_Ptr->duty_cycle * 255) / 100;  /* Set Compare Value for duty cycle. */

    DDRB  = DDRB | (1<<PB3);  /* Set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC. */

    /* Configure timer control register
     * 1. Fast PWM mode FOC0=0
     * 2. Fast PWM Mode WGM01=1 & WGM00=1
     * 3. Clear OC0 when match occurs (non-inverted mode) COM00=0 & COM01=1
     * 4. Set clock source as per Config_Ptr->timer_clock
     */
    TCCR0 = (1<<WGM00) | (1<<WGM01) | ((Config_Ptr->mode)<<COM00) | ((Config_Ptr->timer_clock)<<CS00);
}

/*
 * Function to initialize Timer2 with Fast PWM mode.
 */
void PWM_Timer2_Start(const Timer_ConfigType * Config_Ptr)
{
    TCNT2 = 0;  /* Set Timer Initial value. */

    OCR2  = (Config_Ptr->duty_cycle * 255) / 100;  /* Set Compare Value for duty cycle. */

    DDRD  = DDRD | (1<<PD7);  /* Set PD7/OC2 as output pin --> pin where the PWM signal is generated. */

    /* Configure Timer/Counter Control Register for Timer2
     * 1. Fast PWM mode FOC2=0
     * 2. Fast PWM Mode WGM21=1 & WGM20=1
     * 3. Clear OC2 on compare match (non-inverted mode) COM20=0 & COM21=1
     * 4. Set clock source as per Config_Ptr->timer_clock
     */
    TCCR2 = (1<<WGM20) | (1<<WGM21) | ((Config_Ptr->mode)<<COM20) | ((Config_Ptr->timer_clock)<<CS20);
}
