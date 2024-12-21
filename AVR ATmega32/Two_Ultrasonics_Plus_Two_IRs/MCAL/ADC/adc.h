/******************************************************************************
 * Module		: ADC
 * File Name	: adc.h
 * Author		: A7la Team :)
 * Created on	: 21/11/2024
 * Description	: Header file for the ADC AVR Driver
 *******************************************************************************/
#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"
#include <avr/io.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023  /* Maximum value for ADC conversion */
#define ADC_REF_VOLT_VALUE   2.56  /* Reference voltage for ADC */

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for initializing the ADC driver.
 */
void ADC_init(void);

/*
 * Description:
 * Function responsible for reading analog data from a certain ADC channel
 * and converting it to digital using the ADC driver.
 * channel_num: The ADC channel number to read from.
 * Returns: The digital value corresponding to the analog input.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* MCAL_ADC_H_ */
