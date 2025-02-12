/******************************************************************************
 * Module       : UART
 * File Name    : uart.h
 * Author       : A7la Team :)
 * Created on   : 26/10/2024
 * Description  : Header file for the UART AVR driver
 *******************************************************************************/
#ifndef UART_H_
#define UART_H_

#include "../../LIB/std_types.h"  /* Include standard types header file */

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/* Enum to define UART parity configurations */
typedef enum
{
    UART_Parity_NONE,   	/* No parity bit */
    UART_Parity_EVEN = 2, 	/* Even parity bit */
    UART_Parity_ODD = 3   	/* Odd parity bit */
} UART_Parity;

/* Enum to define UART stop bit configurations */
typedef enum
{
    UART_STOP_1_BIT,  /* 1 stop bit */
    UART_STOP_2_BIT   /* 2 stop bits */
} UART_StopBit;

/* Enum to define UART data bit modes */
typedef enum
{
    MODE_FIVE_BIT,  /* 5-bit data mode */
    MODE_SIX_BIT,   /* 6-bit data mode */
    MODE_SEVEN_BIT, /* 7-bit data mode */
    MODE_EIGHT_BIT  /* 8-bit data mode */
} UART_BitDataType;

/* Structure to hold UART configuration parameters */
typedef struct
{
    uint32 baudRate;  /* UART baud rate (e.g., 9600, 115200) */
    UART_Parity Parity_Configurations;  /* Parity configuration (None, Even, Odd) */
    UART_StopBit StopBit_Configurations;  /* Stop bit configuration (1 or 2 bits) */
    UART_BitDataType bit_data;  /* Data bit mode (5, 6, 7, or 8 bits) */
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
 * Parameters  :
 * - Config_Ptr: Pointer to the UART configuration structure.
 */
void UART_init(const UART_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for sending a byte to another UART device.
 * Parameters  :
 * - data: The byte to be sent.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Function responsible for receiving a byte from another UART device.
 * Returns     :
 * - The received byte.
 */
uint8 UART_receiveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 * Parameters  :
 * - Str: Pointer to the string to be sent.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 * Parameters  :
 * - Str: Pointer to the buffer where the received string will be stored.
 */
void UART_receiveString(uint8 *Str);  // Receive until #

/*
 * Description :
 * Send the required array through UART to the other UART device.
 * Parameters  :
 * - a_ptr: Pointer to the array to be sent.
 * - size: Size of the array.
 */
void UART_sendArray(const uint8 *a_ptr, uint8 size);

/*
 * Description :
 * Receive the required array until the '#' symbol through UART from the other UART device.
 * Parameters  :
 * - a_ptr: Pointer to the buffer where the received array will be stored.
 */
void UART_receiveArray(uint8 *a_ptr);

#endif /* UART_H_ */
