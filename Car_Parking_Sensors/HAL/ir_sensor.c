/***************************************************************************************************************
 * pir_sensor.c
 * Author: Muhammed Ayman
 * Module: IR Sensor
 **************************************************************************************************************/
#include "ir_sensor.h"

#include <avr/io.h>
#include "../MCAL/gpio.h"

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

uint8 IR_ReadValue(uint8 ir_port, uint8 ir_pin) {
    return (GPIO_readPin(ir_port, ir_pin));
}

void IR_init(void) {
    GPIO_setupPinDirection(IR_PORT, IR0_PIN, PIN_INPUT);
    GPIO_setupPinDirection(IR_PORT, IR1_PIN, PIN_INPUT);
}
