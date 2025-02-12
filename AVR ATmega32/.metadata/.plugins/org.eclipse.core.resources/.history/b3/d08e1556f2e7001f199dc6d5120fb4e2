/******************************************************************************
 * Module       : UART
 * File Name    : uart.h
 * Author       : A7la Team :)
 * Created on   : 26/10/2024
 * Description  : Header file for the UART AVR driver
 *******************************************************************************/
#ifndef UART_H_
#define UART_H_

#include "../../LIB/std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
    UART_Parity_NONE, UART_Parity_EVEN = 2, UART_Parity_ODD = 3  // UART parity configurations
} UART_Parity;

typedef enum
{
    UART_STOP_1_BIT, UART_STOP_2_BIT  // UART stop bit configurations
} UART_StopBit;

typedef enum
{
    MODE_FIVE_BIT, MODE_SIX_BIT, MODE_SEVEN_BIT, MODE_EIGHT_BIT  // UART data bit modes
} UART_BitDataType;

typedef struct
{
    uint32 baudRate;  // UART baud rate
    UART_Parity Parity_Configurations;  // UART parity configuration
    UART_StopBit StopBit_Configurations;  // UART stop bit configuration
    UART_BitDataType bit_data;  // UART data bit mode
} UART_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the UART device by:
 * 1. Setting up the frame format like number of data bits, parity bit type, and number of stop bits.
 * 2. Enabling the UART.
 * 3. Setting up the UART baud rate.
 */
void UART_init(const UART_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for sending a byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Function responsible for receiving a byte from another UART device.
 */
uint8 UART_receiveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str);  // Receive until #

/*
 * Description :
 * Send the required array through UART to the other UART device.
 */
void UART_sendArray(const uint8 *a_ptr, uint8 size);

/*
 * Description :
 * Receive the required array until the '#' symbol through UART from the other UART device.
 */
void UART_receiveArray(uint8 *a_ptr);

#endif /* UART_H_ */
