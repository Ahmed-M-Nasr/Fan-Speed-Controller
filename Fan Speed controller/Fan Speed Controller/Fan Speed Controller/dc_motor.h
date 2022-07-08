 /******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name:dc_motor.h
 *
 * Description: Header file for the DC_MOTOR driver
 *
 * Author: Ahmed Nasr                */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
typedef uint8 DcMotor_State;

#define MOTOR_PORT              PORTB_ID
#define MOTOR_PIN1              0
#define MOTOR_PIN2              1
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* Description :
* Initialize the DC_MOTOR:
* 1. Setup the MOTOR pins directions by use the GPIO driver.*/
void DcMotor_Init(void);
/* Description :
* Control the DC_MOTOR rotation
* Setup and starts Timer0 pwm signal by the use of pwm driver*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
