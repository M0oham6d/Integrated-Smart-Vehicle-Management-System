/*
 * adc.h
 * Author: Muhammed Ayman
 * Module: ADC
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#include <avr/io.h>
#include "../Standard_Types/standard_types.h"
#include "../Common_Macros/common_macros.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/
/*
 * Description:
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);

/*
 * Description:
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);


#endif /* MCAL_ADC_H_ */
