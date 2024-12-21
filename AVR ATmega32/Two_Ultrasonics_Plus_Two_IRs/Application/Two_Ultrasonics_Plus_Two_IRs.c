/*****************************************************************
 * File Name	: Two_Ultrasonics_Plus_Two_IRs.c
 * Author		: A7la Team :)
 * Created on	: 13/11/2024
 * Description	: Source file for the APP
 *****************************************************************/
#include "Two_Ultrasonics_Plus_Two_IRs.h"

/*****************************************************************
 *                  	 Global Variables                        *
 *****************************************************************/
uint16 g_distance1 = 0;
uint16 g_distance2 = 0;

int main(void)
{
	Inits();			/* Initialize all modules. */

	while(1)
	{
		Read_Distance_and_Display_on_LCD();		/* Read the distance and display it on LCD. */
		Read_IR_and_Display_on_LCD();           /* Read the IR sensor values and display them on LCD. */
	}
	return 0;
}

/*
 * Description:
 * Function to initialize all modules.
 */
void Inits(void)
{
	SREG |= (1<<7);          /* Enable global interrupts. */
	Ultrasonic_init(ICU);    /* Initialize the ultrasonic sensor using ICU. */
	Ultrasonic_init(EXT_INT);/* Initialize the ultrasonic sensor using external interrupt. */
	LCD_init();              /* Initialize the LCD. */
	LEDS_init();             /* Initialize the LEDs. */
	Buzzer_init();           /* Initialize the buzzer. */
	IR_init();               /* Initialize the IR sensors. */
}

/*
 * Description:
 * Function to make an alert.
 */
void Alert(void)
{
	LED_on(red);
	LED_on(green);
	LED_on(blue);
	Buzzer_on();
	_delay_ms(200);

	LED_off(red);
	LED_off(green);
	LED_off(blue);
	Buzzer_off();
	_delay_ms(200);
}

/*
 * Description:
 * Function to read the distance and display it on LCD.
 * Distance <= 5 cm: All LEDs are flashing (Red, Green, Blue), Buzzer sounds, LCD shows "Stop."
 * 6 cm <= Distance <= 10 cm: All LEDs ON (Red, Green, Blue), No buzzer.
 * 11 cm <= Distance <= 15 cm: Red and Green LEDs ON, Blue LED OFF.
 * 16 cm <= Distance <= 20 cm: Only Red LED ON, others OFF.
 * Distance > 20 cm: All LEDs OFF, Buzzer OFF.
 */
void Read_Distance_and_Display_on_LCD(void)
{
	g_distance1 = Ultrasonic_readDistance(ICU);
	g_distance2 = Ultrasonic_readDistance(EXT_INT);

	LCD_displayStringRowColumn(0, 0, "D1=");
	LCD_intgerToString(g_distance1);

	LCD_displayStringRowColumn(0, 8, ",D2=");
	LCD_intgerToString(g_distance2);

	/*
	 * If distance is < 10, clear the next pixel in LCD.
	 */
	if(g_distance1 < 10)
	{
		LCD_displayStringRowColumn(0, 4, "cm ");
	}
	else
	{
		LCD_displayStringRowColumn(0, 5, "cm ");
	}

	if(g_distance2 < 10)
	{
		LCD_displayStringRowColumn(0, 13, "cm ");
	}
	else
	{
		LCD_displayStringRowColumn(0, 14, "cm ");
	}

	if(g_distance1 <= 5 || g_distance2 <= 5)
	{
		Alert();
	}
	else if((g_distance1 >= 6 && g_distance1 <= 10) || (g_distance2 >= 6 && g_distance2 <= 10))
	{
		Buzzer_off();
		LED_on(red);
		LED_on(green);
		LED_on(blue);
	}
	else if((g_distance1 >= 11 && g_distance1 <= 15) || (g_distance2 >= 11 && g_distance2 <= 15))
	{
		LED_on(red);
		LED_on(green);
		LED_off(blue);
	}
	else if((g_distance1 >= 16 && g_distance1 <= 20) || (g_distance2 >= 16 && g_distance2 <= 20))
	{
		LED_on(red);
		LED_off(green);
		LED_off(blue);
	}
	else
	{
		LED_off(red);
		LED_off(green);
		LED_off(blue);
	}
}

/*
 * Description:
 * Function to read the IR sensor values and display them on LCD.
 */
void Read_IR_and_Display_on_LCD(void)
{
	uint8 read_ir1, read_ir2;
	read_ir1 = IR_ReadValue(PORTD_ID, PIN2_ID);
	LCD_displayStringRowColumn(1, 0, "IR1=");
	LCD_intgerToString(read_ir1);
	read_ir2 = IR_ReadValue(PORTD_ID, PIN3_ID);
	LCD_displayStringRowColumn(1, 7, ",IR2=");
	LCD_intgerToString(read_ir2);
}
