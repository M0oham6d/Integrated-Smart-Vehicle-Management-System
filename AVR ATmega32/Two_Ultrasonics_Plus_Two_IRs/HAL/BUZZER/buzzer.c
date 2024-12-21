/******************************************************************************
 * Module		: BUZZER
 * File Name	: buzzer.c
 * Author		: A7la Team :)
 * Created on	: 21/11/2024
 * Description	: Source file for the Buzzer AVR driver
 *******************************************************************************/
#include "buzzer.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Initializes the buzzer pin direction and turns off the buzzer.
 */
void Buzzer_init(void)
{
	GPIO_setupPinDirection(BUZZER_PORT_CONNECTION, BUZZER_PIN_CONNECION, PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_CONNECTION, BUZZER_PIN_CONNECION, LOGIC_LOW);
}

/*
 * Description:
 * Activates the buzzer.
 */
void Buzzer_on(void)
{
	GPIO_writePin(BUZZER_PORT_CONNECTION, BUZZER_PIN_CONNECION, LOGIC_HIGH);
}

/*
 * Description:
 * Deactivates the buzzer.
 */
void Buzzer_off(void)
{
	GPIO_writePin(BUZZER_PORT_CONNECTION, BUZZER_PIN_CONNECION, LOGIC_LOW);
}
