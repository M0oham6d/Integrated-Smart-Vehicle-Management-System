/******************************************************************************
 * Module		: BUZZER
 * File Name	: buzzer.h
 * Author		: A7la Team :)
 * Created on	: 21/11/2024
 * Description	: Header file for the Buzzer AVR driver
 *******************************************************************************/
#ifndef HAL_BUZZER_H_
#define HAL_BUZZER_H_

#include "../../MCAL/GPIO/gpio.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/

#define BUZZER_PORT_CONNECTION			PORTC_ID
#define BUZZER_PIN_CONNECION			PIN5_ID

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Description:
 * Initializes the buzzer pin direction and turns off the buzzer.
 */
void Buzzer_init(void);

/*
 * Description:
 * Activates the buzzer.
 */
void Buzzer_on(void);

/*
 * Description:
 * Deactivates the buzzer.
 */
void Buzzer_off(void);

#endif /* HAL_BUZZER_H_ */
