/*
 * main.c
 *
 *  Created on: May 25, 2022
 *      Author: Ahmed Nasr
 */
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "pwm.h"
int main(void)
{
	uint8 state=1;
	ADC_ConfigType * ADC;
	ADC->ref_volt=REFERENCE_VOLTAGE;
	uint8 temp;
	DcMotor_Init();/* initialize DC_MOTOR driver */
	LCD_init(); /* initialize LCD driver */
	ADC_init(ADC); /* initialize ADC driver */
	/* Display this string "Fan is   " only once on LCD at the first row */
	LCD_displayString("Fan is    ");
	/* Display this string "Temp =   C" only once on LCD at the Second row */
	LCD_displayStringRowColumn(1,0,"Temp =    C");

    while(1)
    {

    	temp = LM35_getTemperature();
    	if(temp<30){
    		state=1;
    		DcMotor_Rotate(state,0);
    	}
    	else if(temp>=30 && temp<60){
    		state=0;
    		DcMotor_Rotate(state,25);
    	}
    	else if(temp>=60 && temp<90){
    		state=0;
    		DcMotor_Rotate(state,50);
    	}
    	else if(temp>=90 && temp<120){
    		state=0;
    		DcMotor_Rotate(state,75);
    	}
    	else if(temp>=120){
    		state=0;
    		DcMotor_Rotate(state,100);
    	}
    	LCD_moveCursor(0,7);
    			if(state==1)
    			{
    				LCD_displayString("OFF");
    			}
    			else
    			{
    				LCD_displayString("ON");
    				/* In case the digital value is two or one digits print space in the next digit place */
    				LCD_displayCharacter(' ');
    			}
		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,7);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
    }
}


