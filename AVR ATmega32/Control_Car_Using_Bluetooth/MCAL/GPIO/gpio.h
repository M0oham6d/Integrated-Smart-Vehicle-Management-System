/******************************************************************************
 * Module       : GPIO
 * File Name    : gpio.h
 * Author       : A7la Team :)
 * Created on   : 10/10/2024
 * Description  : Header file for the GPIO AVR driver
 *******************************************************************************/
#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_

#include "../../LIB/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           4  // Number of ports
#define NUM_OF_PINS_PER_PORT   8  // Number of pins per port

#define PORTA_ID               0  // Port A ID
#define PORTB_ID               1  // Port B ID
#define PORTC_ID               2  // Port C ID
#define PORTD_ID               3  // Port D ID

#define PIN0_ID                0  // Pin 0 ID
#define PIN1_ID                1  // Pin 1 ID
#define PIN2_ID                2  // Pin 2 ID
#define PIN3_ID                3  // Pin 3 ID
#define PIN4_ID                4  // Pin 4 ID
#define PIN5_ID                5  // Pin 5 ID
#define PIN6_ID                6  // Pin 6 ID
#define PIN7_ID                7  // Pin 7 ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
    PIN_INPUT, PIN_OUTPUT  // Pin direction types: Input or Output
} GPIO_PinDirectionType;

typedef enum
{
    PORT_INPUT, PORT_OUTPUT = 0xFF  // Port direction types: Input or Output
} GPIO_PortDirectionType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value);

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num);

#endif /* MCAL_GPIO_H_ */
