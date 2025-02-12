/*
 * led.c
 * Author: Muhammed Ayman
 * Module: LCDs
 */

#include "leds.h"

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Function to initialize LEDs.
 * Make all of them output pins.
 * If the connection is POSITIVE LOGIC, put logic zero at the beginning.
 * Else, put logic one at the beginning (NEGATIVE LOGIC CONNECTION).
 */
void LEDS_init(void)
{
	GPIO_setupPinDirection(LEDS_PORT_CONNECTION, RED_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(LEDS_PORT_CONNECTION, GREEN_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(LEDS_PORT_CONNECTION, BLUE_LED, PIN_OUTPUT);

#ifdef CONNECTION_POSITIVE_LOGIC
	GPIO_writePin(LEDS_PORT_CONNECTION, RED_LED, LOGIC_LOW);
	GPIO_writePin(LEDS_PORT_CONNECTION, GREEN_LED, LOGIC_LOW);
	GPIO_writePin(LEDS_PORT_CONNECTION, BLUE_LED, LOGIC_LOW);
#else
	GPIO_writePin(LEDS_PORT_CONNECTION, RED_LED, LOGIC_HIGH);
	GPIO_writePin(LEDS_PORT_CONNECTION, GREEN_LED, LOGIC_HIGH);
	GPIO_writePin(LEDS_PORT_CONNECTION, BLUE_LED, LOGIC_HIGH);
#endif
}

/*
 * Function to turn on a specific LED.
 * If the connection is POSITIVE LOGIC, put LOGIC HIGH to turn it on.
 * Else, put LOGIC LOW (NEGATIVE LOGIC CONNECTION).
 */
void LED_on(LED_ID id)
{
#ifdef CONNECTION_POSITIVE_LOGIC
	switch(id)
	{
	case red:
		GPIO_writePin(LEDS_PORT_CONNECTION, RED_LED, LOGIC_HIGH);
		break;
	case green:
		GPIO_writePin(LEDS_PORT_CONNECTION, GREEN_LED, LOGIC_HIGH);
		break;
	case blue:
		GPIO_writePin(LEDS_PORT_CONNECTION, BLUE_LED, LOGIC_HIGH);
		break;
	}
#else
	switch(id)
		{
		case red:
			GPIO_writePin(LEDS_PORT_CONNECTION, RED_LED, LOGIC_LOW);
			break;
		case green:
			GPIO_writePin(LEDS_PORT_CONNECTION, GREEN_LED, LOGIC_LOW);
			break;
		case blue:
			GPIO_writePin(LEDS_PORT_CONNECTION, BLUE_LED, LOGIC_LOW);
			break;
		}
#endif
}

/*
 * Function to turn off a specific LED.
 * If the connection is POSITIVE LOGIC, put LOGIC LOW to turn it off.
 * Else, put LOGIC HIGH (NEGATIVE LOGIC CONNECTION).
 */
void LED_off(LED_ID id)
{
#ifdef CONNECTION_POSITIVE_LOGIC
	switch(id)
	{
	case red:
		GPIO_writePin(LEDS_PORT_CONNECTION, RED_LED, LOGIC_LOW);
		break;
	case green:
		GPIO_writePin(LEDS_PORT_CONNECTION, GREEN_LED, LOGIC_LOW);
		break;
	case blue:
		GPIO_writePin(LEDS_PORT_CONNECTION, BLUE_LED, LOGIC_LOW);
		break;
	}
#else
	switch(id)
		{
		case red:
			GPIO_writePin(LEDS_PORT_CONNECTION, RED_LED, LOGIC_HIGH);
			break;
		case green:
			GPIO_writePin(LEDS_PORT_CONNECTION, GREEN_LED, LOGIC_HIGH);
			break;
		case blue:
			GPIO_writePin(LEDS_PORT_CONNECTION, BLUE_LED, LOGIC_HIGH);
			break;
		}
#endif
}
