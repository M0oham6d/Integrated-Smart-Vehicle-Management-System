/******************************************************************************
 * Module		: ULTRASONIC
 * File Name	: ultrasonic_sensor.h
 * Author		: A7la Team :)
 * Created on	: 21/11/2024
 * Description	: Header file for the Ultrasonic sensor
 *******************************************************************************/
#ifndef HAL_ULTRASONIC_SENSOR_H_
#define HAL_ULTRASONIC_SENSOR_H_

#include "../../MCAL/EXT_INT/external_interrupts.h"
#include "../../MCAL/TIMER/timer.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/ICU/icu.h"
#include "../../LIB/std_types.h"
#include <util/delay.h>

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
#define TRIGGER_PORT_CONNECTION1				PORTD_ID
#define TRIGGER_PIN1							PIN7_ID
#define TRIGGER_PORT_CONNECTION2				PORTB_ID
#define TRIGGER_PIN2							PIN1_ID
#define ECHO_PORT_CONNECTION					PORTD_ID
#define ECHO_PIN								PIN6_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/* Enum to define the usage of ICU or External Interrupt for Ultrasonic sensor */
typedef enum
{
	ICU, EXT_INT
} Ultrasonic_Use;

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Description:
 * Set up ICU Configuration.
 * Initialize ICU.
 * Set call back function.
 * use: Specifies whether to use ICU or External Interrupt.
 */
void Ultrasonic_init(Ultrasonic_Use use);

/*
 * Description:
 * Send the trigger pulse by using the Ultrasonic_Trigger function.
 * Start the measurement process via the ICU driver.
 * Returns: The measured distance in centimeters.
 * use: Specifies whether to use ICU or External Interrupt.
 */
uint16 Ultrasonic_readDistance(Ultrasonic_Use use);

#endif /* HAL_ULTRASONIC_SENSOR_H_ */
