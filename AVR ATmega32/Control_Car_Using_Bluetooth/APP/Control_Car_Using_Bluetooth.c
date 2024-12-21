/******************************************************************************
 * File Name    : Control_Car_Using_Bluetooth.c
 * Author       : A7la Team :)
 * Created on   : 22/11/2024
 * Description  : Source file for the APP
 *******************************************************************************/
#include "Control_Car_Using_Bluetooth.h"

/*******************************************************************************
 *                              Functions Deceleration                           *
 *******************************************************************************/

/* Main function */
int main(void)
{
    uint8 recievedMSG;  // Variable to store received message

    UART_init(&uart_configratoin);  // Initialize UART with configuration

    DcMotor_Init(motorSpeed(UART_receiveByte()));  // Initialize DC motor with speed received from UART

    while(1)
    {
        recievedMSG = UART_receiveByte();  // Receive a byte from UART

        switch(recievedMSG)
        {
        case 'F':
            Forward();  // Move forward
            break;
        case 'B':
            Backward();  // Move backward
            break;
        case 'S':
            Stop();  // Stop movement
            break;
        case 'R':
            Right_Forward();  // Turn right and move forward
            break;
        case 'L':
            Left_Forward();  // Turn left and move forward
            break;
        case 'M':
            DcMotor_Init(motorSpeed(UART_receiveByte()));  // Reinitialize motor with new speed
            break;
        }
    }
    return 0;
}

/* Function to determine motor speed based on received speed value */
uint8 motorSpeed(uint8 speed)
{
    switch(speed)
    {
        case '1':
            return MOTOR_SPEED_ONE;  // Speed level 1
            break;
        case '2':
            return MOTOR_SPEED_TWO;  // Speed level 2
            break;
        case '3':
            return MOTOR_MAX_SPEED;  // Speed level 3
            break;
    }

    return 100;  // Default speed
}
