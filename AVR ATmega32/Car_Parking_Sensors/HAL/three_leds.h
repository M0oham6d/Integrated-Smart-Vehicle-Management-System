/*
 * led.c
 * Author: Muhammed Ayman
 * Module: LCDs
 */


#ifndef HAL_THREE_LEDS_H_
#define HAL_THREE_LEDS_H_

#include "../MCAL/gpio.h"

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
typedef enum
{
	red, green, blue
}LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function to initialize LEDs.
 * Make all of them output pins.
 * If the connection is POSITIVE LOGIC, put logic zero at the beginning.
 * Else, put logic one at the beginning (NEGATIVE LOGIC CONNECTION).
 */
void LEDS_init(void);

/*
 * Function to turn on a specific LED.
 * If the connection is POSITIVE LOGIC, put LOGIC HIGH to turn it on.
 * Else, put LOGIC LOW (NEGATIVE LOGIC CONNECTION).
 */
void LED_on(LED_ID id);

/*
 * Function to turn off a specific LED.
 * If the connection is POSITIVE LOGIC, put LOGIC LOW to turn it off.
 * Else, put LOGIC HIGH (NEGATIVE LOGIC CONNECTION).
 */
void LED_off(LED_ID id);

#endif /* HAL_THREE_LEDS_H_ */
