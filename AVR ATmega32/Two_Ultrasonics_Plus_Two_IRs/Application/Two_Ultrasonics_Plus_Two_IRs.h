/******************************************************************************
 * File Name	: Two_Ultrasonics_Plus_Two_IRs.h
 * Author		: A7la Team :)
 * Created on	: 13/11/2024
 * Description	: Header file for the APP
 *******************************************************************************/
#ifndef APPLICATION_TWO_ULTRASONICS_PLUS_TWO_IRS_H_
#define APPLICATION_TWO_ULTRASONICS_PLUS_TWO_IRS_H_

/*******************************************************************
 *                      	Includes                               *
 *******************************************************************/
#include "../HAL/ULTRASONIC/ultrasonic.h"
#include "../HAL/BUZZER/buzzer.h"
#include "../HAL/LED/led.h"
#include "../HAL/LCD/lcd.h"
#include "../HAL/IR/ir.h"
#include <util/delay.h>
#include <avr/io.h>

/*******************************************************************
 *                      	Functions Prototypes                   *
 *******************************************************************/

/*
 * Description:
 * Function to initialize all modules.
 */
void Inits(void);

/*
 * Description:
 * Function to make an alert.
 */
void Alert(void);

/*
 * Description:
 * Function to read the distance and display it on LCD.
 * Distance <= 5 cm: All LEDs are flashing (Red, Green, Blue), Buzzer sounds, LCD shows "Stop."
 * 6 cm <= Distance <= 10 cm: All LEDs ON (Red, Green, Blue), No buzzer.
 * 11 cm <= Distance <= 15 cm: Red and Green LEDs ON, Blue LED OFF.
 * 16 cm <= Distance <= 20 cm: Only Red LED ON, others OFF.
 * Distance > 20 cm: All LEDs OFF, Buzzer OFF.
 */
void Read_Distance_and_Display_on_LCD(void);

#endif /* APPLICATION_TWO_ULTRASONICS_PLUS_TWO_IRS_H_ */
