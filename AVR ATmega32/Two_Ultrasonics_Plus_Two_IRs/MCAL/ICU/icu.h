/******************************************************************************
 * Module		: ICU
 * File Name	: icu.h
 * Author		: A7la Team :)
 * Created on	: 21/11/2024
 * Description	: Header file for the ICU AVR Driver
 *******************************************************************************/
#ifndef MCAL_ICU_ICU_H_
#define MCAL_ICU_ICU_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"
#include <avr/interrupt.h>
#include <avr/io.h>

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/* Enum to define ICU clock sources */
typedef enum
{
	ICU_NO_CLOCK, ICU_F_CPU_CLOCK, ICU_F_CPU_8, ICU_F_CPU_64, ICU_F_CPU_256, ICU_F_CPU_1024
} ICU_ClockType;

/* Enum to define ICU edge detection types */
typedef enum
{
	FALLING, RAISING
} ICU_EdgeType;

/* Structure to configure the ICU */
typedef struct
{
	ICU_ClockType clock;  /* Clock source for the ICU */
	ICU_EdgeType edge;    /* Edge detection type */
} ICU_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 * Config_Ptr: Pointer to the ICU configuration structure.
 */
void ICU_init(const ICU_ConfigType * Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 * a_ptr: Pointer to the callback function.
 */
void ICU_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 * edgeType: The edge detection type to be set.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured.
 * Returns: The value stored at Input Capture Register ICR1.
 */
uint16 ICU_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO.
 */
void ICU_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver.
 */
void ICU_deInit(void);

#endif /* MCAL_ICU_ICU_H_ */
