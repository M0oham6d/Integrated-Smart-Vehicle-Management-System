/***************************************************************************************************************
 * motor.c
 * Author: A7la Team
 * Module: DC Motor
 **************************************************************************************************************/

#include "motor.h"
#include "../MCAL/gpio.h"
#include "../MCAL/pwm.h"
#include <util/delay.h>

/*******************************************************************************
 *                        Functions Definitions                                *
 *******************************************************************************/
uint8 max_Speed = 0;

/*
 * Description:
 * Helper function to handle the maximum speed setting.
 */
static void Handel_Max_Speed(uint8 speed)
{
	max_Speed = speed;
}

/*
 * Function to initialize DC motor.
 */
void DcMotor_Init(uint8 MAXSPEED)
{
	/*
	 * Setup pin direction for INT1 & INT2 as output.
	 * Setup pin direction for Enable as output.
	 */
	/* For motor 1 */
	Handel_Max_Speed(MAXSPEED);

	GPIO_setupPinDirection(MOTOR_PORT_CONNECTION, PIN_INT1, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_CONNECTION, PIN_INT2, PIN_OUTPUT);
	GPIO_setupPinDirection(ENABLE1_PORT_CONNECTION, ENABLE1_PIN, PIN_OUTPUT);

	/* For motor 2 */
	GPIO_setupPinDirection(MOTOR_PORT_CONNECTION, PIN_INT3, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_CONNECTION, PIN_INT4, PIN_OUTPUT);
	GPIO_setupPinDirection(ENABLE2_PORT_CONNECTION, ENABLE2_PIN, PIN_OUTPUT);

	/* Stop the motor at the beginning. */
	GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT1, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT2, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT3, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT4, LOGIC_LOW);
}

/*
 * Function to rotate the motor.
 * Rotate in CW or CCW or STOP the motor.
 * Control the motor speed using PWM.
 */
void DcMotor1_Rotate(DcMotor_State state, uint8 speed)
{
	Timer_ConfigType configrations = {NON_INVERTING, F_CPU_CLOCK, speed};
	PWM_Timer0_Start(&configrations);

	switch (state)
	{
	case STOP:
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT1, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT2, LOGIC_LOW);
		break;

	case CW:
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT1, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT2, LOGIC_LOW);
		break;
	case CCW:
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT1, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT2, LOGIC_HIGH);
		break;
	}
}

/*
 * Function to rotate the second motor.
 * Rotate in CW or CCW or STOP the motor.
 * Control the motor speed using PWM.
 */
void DcMotor2_Rotate(DcMotor_State state, uint8 speed)
{
	Timer_ConfigType configrations = {NON_INVERTING, F_CPU_CLOCK, speed};
	PWM_Timer2_Start(&configrations);

	switch (state)
	{
	case STOP:
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT3, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT4, LOGIC_LOW);
		break;

	case CW:
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT3, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT4, LOGIC_LOW);
		break;
	case CCW:
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT3, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_CONNECTION, PIN_INT4, LOGIC_HIGH);
		break;
	}
}

/*
 * Description:
 * Function to move the car forward.
 */
void Forward(void)
{
	for(int i = 0; i <= max_Speed; i += 10)
	{
		DcMotor1_Rotate(CW, i);
		DcMotor2_Rotate(CW, i);
		_delay_ms(30);
	}
}

/*
 * Description:
 * Function to move the car backward.
 */
void Backward(void)
{
	for(int i = 0; i <= max_Speed; i += 10)
	{
		DcMotor1_Rotate(CCW, i);
		DcMotor2_Rotate(CCW, i);
		_delay_ms(30);
	}
}

/*
 * Description:
 * Function to stop the car.
 */
void Stop(void)
{
	DcMotor1_Rotate(STOP, 0);
	DcMotor2_Rotate(STOP, 0);
}

/*
 * Description:
 * Function to turn the car right while moving forward.
 */
void Right_Forward(void)
{
	for(int i = 0; i <= max_Speed; i += 10)
	{
		DcMotor1_Rotate(STOP, 0);
		DcMotor2_Rotate(CW, i);
		_delay_ms(30);
	}
}

/*
 * Description:
 * Function to turn the car left while moving forward.
 */
void Left_Forward(void)
{
	for(int i = 0; i <= max_Speed; i += 10)
	{
		DcMotor1_Rotate(CW, i);
		DcMotor2_Rotate(STOP, 0);
		_delay_ms(30);
	}
}
