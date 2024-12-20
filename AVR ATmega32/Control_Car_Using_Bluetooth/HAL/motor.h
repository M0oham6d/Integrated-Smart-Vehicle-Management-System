/***************************************************************************************************************
 * motor.h
 * Author: A7la Team
 * Module: DC Motor
 **************************************************************************************************************/

#ifndef HAL_MOTOR_H_
#define HAL_MOTOR_H_

#include "../Standard_Types/standard_types.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
#define MOTOR_STOP                    	(0)
#define MOTOR_MINIMUM_SPEED            	(25)
#define MOTOR_SECOND_SPEED            	(50)
#define MOTOR_THIRD_SPEED            	(75)
#define MOTOR_MAX_SPEED                	(100)

#define MOTOR_PORT_CONNECTION        	PORTA_ID
#define PIN_INT1                    	PIN0_ID
#define PIN_INT2                    	PIN1_ID
#define PIN_INT3                    	PIN2_ID
#define PIN_INT4                    	PIN3_ID

#define ENABLE1_PORT_CONNECTION        	PORTB_ID
#define ENABLE1_PIN                    	PIN3_ID

#define ENABLE2_PORT_CONNECTION        	PORTD_ID
#define ENABLE2_PIN                    	PIN7_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	STOP, CW, CCW
}DcMotor_State;

/*******************************************************************************
 *                        Functions Prototypes                                 *
 *******************************************************************************/

/*
 * Function to initialize DC motor.
 */
void DcMotor_Init(uint8 MAXSPEED);

/*
 * Function to rotate the motor.
 * Rotate in CW or CCW or STOP the motor.
 * Control the motor speed using PWM.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

void Forward(void);

void Backward(void);

void Stop(void);

void Right_Forward(void);

void Left_Forward(void);

#endif /* HAL_MOTOR_H_ */
