 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name:pwm.c
 *
 * Description: Header file for the PWM driver
 *
 * Author: Ahmed Nasr                */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_PORT  PORTB_ID
#define PWM_PIN    3
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * starts Timer0 in PWM mode and generate the output on pin PB3/OCO*/
void PWM_Timer0_Start(uint8 duty_cycle);
#endif /* PWM_H_ */
