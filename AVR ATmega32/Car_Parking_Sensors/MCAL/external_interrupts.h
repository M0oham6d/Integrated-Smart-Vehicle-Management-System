/***************************************************************************************************************
 * external_interrupts.h
 * Author: Muhammed Ayman
 * Module: External Interrupts
 **************************************************************************************************************/

#ifndef MCAL_EXTERNAL_INTERRUPTS_H_
#define MCAL_EXTERNAL_INTERRUPTS_H_

#include "../Standard_Types/standard_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/* Enum to define the external interrupt types. */
typedef enum
{
    INT_0, INT_1, INT_2
} EXT_INT_Type;

/* Enum to define the sense control for external interrupts. */
typedef enum
{
    FALLING_EDGE = 2, RISING_EDGE, FALLING_EDGE_INT2 = 0, RISING_EDGE_INT2
} EXT_INT_Sense;

/* Structure to configure the external interrupt. */
typedef struct
{
    EXT_INT_Type INT_ID;    /* Interrupt ID (INT0, INT1, INT2) */
    EXT_INT_Sense INT_Sense; /* Interrupt sense control (Falling, Rising) */
} EXT_INT_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function to initialize the external interrupt.
 * This function configures the interrupt sense control and enables the interrupt.
 */
void external_interrupt_init(const EXT_INT_ConfigType * a_ptr);

/*
 * Function to disable external interrupt via INT_ID.
 * This function disables the specified external interrupt.
 */
void external_interrupt_deinit(EXT_INT_Type INT_ID);

/*
 * Function to set the Call Back function address to the required external interrupt.
 * This function assigns the callback function to be called when the specified interrupt occurs.
 */
void external_interrupt_setCallBack(void(*a_ptr)(void), EXT_INT_Type INT_ID);

#endif /* MCAL_EXTERNAL_INTERRUPTS_H_ */
