 /******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name:dc_motor.c
 *
 * Description: Source file for the DC_MOTOR driver
 *
 * Author: Ahmed Nasr                */
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "gpio.h"
#include "dc_motor.h"
#include "pwm.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 /* Description :
 * Initialize the DC_MOTOR:
 * 1. Setup the MOTOR pins directions by use the GPIO driver.*/
void DcMotor_Init(void){
	/*Set the 2 pins of the motor to output pins*/
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_PIN1,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_PIN2,PIN_OUTPUT);
	/*Initialize the output of the 2 pins with zeros*/
	GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT,MOTOR_PIN2,LOGIC_LOW);
}
/* Description :
* Control the DC_MOTOR rotation
* Setup and starts Timer0 pwm signal by the use of pwm driver*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	/*check the state needed of the motor (0=Motor on clockwise rotation) or
	 (1=Motor off)*/
	if(state==0){
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,LOGIC_HIGH);
	}
	else if(state==1){
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN2,LOGIC_LOW);
	}
/*start the pwm signal using the speed input as the duty cycle (0-100) by the use of pwm driver*/
	PWM_Timer0_Start(speed);

}
