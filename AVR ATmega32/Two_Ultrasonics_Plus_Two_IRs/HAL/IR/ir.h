/******************************************************************************
 * Module		: IR Sensor
 * File Name	: ir.h
 * Author		: A7la Team :)
 * Created on	: 21/11/2024
 * Description	: Header file for the IR AVR driver
 *******************************************************************************/
#ifndef HAL_IR_SENSOR_H_
#define HAL_IR_SENSOR_H_

#include "../../MCAL/GPIO/gpio.h"
#include "../../LIB/std_types.h"
#include <avr/io.h>

/* IR sensor port and pin definitions */
#define IR_PORT      PORTD_ID
#define IR0_PIN      PIN2_ID
#define IR1_PIN      PIN3_ID

/*
 * Description:
 * Function to read the value from a specific IR sensor pin.
 * ir_port: The port number where the IR sensor is connected.
 * ir_pin: The pin number where the IR sensor is connected.
 * Returns: The value read from the IR sensor pin (0 or 1).
 */
uint8 IR_ReadValue(uint8 ir_port, uint8 ir_pin);

/*
 * Description:
 * Function to initialize the IR sensor.
 * This function sets up the necessary pin directions for the IR sensor.
 */
void IR_init(void);

#endif /* HAL_IR_SENSOR_H_ */
