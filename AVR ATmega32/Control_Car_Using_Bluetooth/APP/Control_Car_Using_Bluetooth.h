/******************************************************************************
 * File Name    : Control_Car_Using_Bluetooth.h
 * Author       : A7la Team :)
 * Created on   : 22/11/2024
 * Description  : Header file for the APP
 *******************************************************************************/
#ifndef APP_CONTROL_CAR_USING_BLUETOOTH_H_
#define APP_CONTROL_CAR_USING_BLUETOOTH_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../HAL/MOTOR/motor.h"  // Include motor control header
#include "../MCAL/UART/uart.h"   // Include UART communication header
#include "../LIB/std_types.h"    // Include standard types header
#include <util/delay.h>          // Include delay utility

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
UART_ConfigType uart_configratoin = {9600, UART_Parity_NONE, UART_STOP_1_BIT, MODE_EIGHT_BIT};  // UART configuration structure

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
uint8 motorSpeed(uint8 speed);  // Prototype for motor speed function

#endif /* APP_CONTROL_CAR_USING_BLUETOOTH_H_ */
