/***************************************************************************************************************
 * pir_sensor.h
 * Author: Muhammed Ayman
 * Module: PIR Sensor
 **************************************************************************************************************/

#ifndef HAL_IR_SENSOR_H_
#define HAL_IR_SENSOR_H_

#include "../Standard_Types/standard_types.h"
#include "../MCAL/gpio.h"
#define IR_PORT      PORTD_ID
#define IR0_PIN      PIN2_ID
#define IR1_PIN      PIN3_ID

uint8 IR_ReadValue (uint8 ir_port , uint8 ir_pin);

void IR_init (void);

#endif /* HAL_IR_SENSOR_H_ */
