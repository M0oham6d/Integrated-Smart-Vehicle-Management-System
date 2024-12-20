/*
 * adc.c
 * Author: Muhammed Ayman
 * Module: ADC
 */

#include "adc.h"

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

void ADC_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 11 to choose to connect Internal 2.56V Voltage Reference with external capacitor at AREF pin

	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (1<<REFS0) | (1<<REFS1);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/8 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; 		/* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; 				/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX |= channel_num; 		/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA, ADSC); 		/* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA, ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); 		/* Clear ADIF by write '1' to it :) */
	return ADC; 				/* Read the digital value from the data register */
}
