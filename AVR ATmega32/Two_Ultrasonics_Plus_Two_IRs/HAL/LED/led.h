/******************************************************************************
 * Module		: LED
 * File Name	: led.h
 * Author		: A7la Team :)
 * Created on	: 21/11/2024
 * Description	: Header file for the LED AVR driver
 *******************************************************************************/

#ifndef HAL_LED_H_
#define HAL_LED_H_

#include "../../MCAL/GPIO/gpio.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
#define CONNECTION_POSITIVE_LOGIC

#define RED_PORT_CONNECTION				PORTC_ID
#define RED_LED							PIN0_ID
#define GREEN_PORT_CONNECTION			PORTC_ID
#define GREEN_LED						PIN1_ID
#define BLUE_PORT_CONNECTION			PORTC_ID
#define BLUE_LED						PIN2_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Enum to define LED IDs */
typedef enum
{
	red, green, blue
} LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function to initialize LEDs.
 * Make all of them output pins.
 * If the connection is POSITIVE LOGIC, put logic zero at the beginning.
 * Else, put logic one at the beginning (NEGATIVE LOGIC CONNECTION).
 */
void LEDS_init(void);

/*
 * Description:
 * Function to turn on a specific LED.
 * If the connection is POSITIVE LOGIC, put LOGIC HIGH to turn it on.
 * Else, put LOGIC LOW (NEGATIVE LOGIC CONNECTION).
 * id: The ID of the LED to turn on.
 */
void LED_on(LED_ID id);

/*
 * Description:
 * Function to turn off a specific LED.
 * If the connection is POSITIVE LOGIC, put LOGIC LOW to turn it off.
 * Else, put LOGIC HIGH (NEGATIVE LOGIC CONNECTION).
 * id: The ID of the LED to turn off.
 */
void LED_off(LED_ID id);

#endif /* HAL_LED_H_ */
