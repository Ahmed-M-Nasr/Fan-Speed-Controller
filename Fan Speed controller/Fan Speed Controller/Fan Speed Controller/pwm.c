 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name:pwm.c
 *
 * Description: Source file for the PWM driver
 *
 * Author: Ahmed Nasr                */


#include "pwm.h"
#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void PWM_Timer0_Start(uint8 duty_cycle){
	float32 set_duty_cycle;
	/*uses the input in percentage (0-100) and calculate the pwm signal (0-255)*/
	set_duty_cycle=(duty_cycle*255)/100;
	TCNT0 = 0; //Set Timer Initial value
	OCR0  = set_duty_cycle; // Set Compare Value

	GPIO_setupPinDirection(PWM_PORT,PWM_PIN,PIN_OUTPUT);//set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
