/*
 * Car_Parking_Sensor.h
 * Author: Muhammed Ayman
 * Module: Car Parking Sensor
 */

#ifndef APPLICATION_CAR_PARKING_SENSOR_H_
#define APPLICATION_CAR_PARKING_SENSOR_H_

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Function to initialize all modules.
 */
void Inits(void);

/*
 * Function to make an alert.
 */
void Alert(void);

/*
 * Function to read the distance and display it on LCD.
 * Distance <= 5 cm: All LEDs are flashing (Red, Green, Blue), Buzzer sounds, LCD shows "Stop."
 * 6 cm <= Distance <= 10 cm: All LEDs ON (Red, Green, Blue), No buzzer.
 * 11 cm <= Distance <= 15 cm: Red and Green LEDs ON, Blue LED OFF.
 * 16 cm <= Distance <= 20 cm: Only Red LED ON, others OFF.
 * Distance > 20 cm: All LEDs OFF, Buzzer OFF.
 */
void Read_Distance_and_Display_on_LCD(void);

#endif /* APPLICATION_CAR_PARKING_SENSOR_H_ */
