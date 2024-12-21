/******************************************************************************
 * Module		: IR Sensor
 * File Name	: ir.c
 * Author		: A7la Team :)
 * Created on	: 21/11/2024
 * Description	: Source file for the IR AVR driver
 *******************************************************************************/
#include "ir.h"

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Description:
 * Function to read the value from a specific IR sensor pin.
 * ir_port: The port number where the IR sensor is connected.
 * ir_pin: The pin number where the IR sensor is connected.
 * Returns: The value read from the IR sensor pin (0 or 1).
 */
uint8 IR_ReadValue(uint8 ir_port, uint8 ir_pin) {
    return (GPIO_readPin(ir_port, ir_pin));
}

/*
 * Description:
 * Function to initialize the IR sensor.
 * This function sets up the necessary pin directions for the IR sensor.
 */
void IR_init(void) {
    GPIO_setupPinDirection(IR_PORT, IR0_PIN, PIN_INPUT);
    GPIO_setupPinDirection(IR_PORT, IR1_PIN, PIN_INPUT);
}
