/*
 * miniproject4.c
 *
 *  Created on: Oct 11, 2024
 *      Author: SoO
 */

#include"Ultrasonic.h"
#include"lcd.h"
#include"buzzer.h"
#include"relay.h"
#include<util/delay.h>
int main(void){

	Ultrasonic_init();/*initialize the ultrasonic*/
	BUZZER_init();/*initialize the buzzer*/
	RELAY_init();/*initialize the relay*/
	LCD_init();/*initialize the LCD*/
	LCD_clearScreen();
	uint16 distance=Ultrasonic_readDistance();

	while(1){
		/*display the distance in cm*/
		LCD_displayStringRowColumn(0,0,"Distance=");
		LCD_displayStringRowColumn(0,12,"cm");
		distance=Ultrasonic_readDistance();

		/*move cursor to first row and then display the distance*/
		LCD_moveCursor(0,9);
		if(distance>=100){

			LCD_intgerToString(distance);

		}
		else if(distance>=10){

			LCD_intgerToString(distance);
			/* In case the digital value is two digits print space in the next digit place */
			LCD_displayCharacter(' ');

		}
		else{
			LCD_intgerToString(distance);
			/* In case the digital value is one digits print space in the next digit place */
			LCD_displayStringRowColumn(0,10,"  ");

		}
		/*if the distance is less than 5cm all leds and buzzer are flashing and the LCD displays stop*/
		if(distance<=10){

			LCD_displayStringRowColumn(1,0,"Dispensing     ");
			RELAY_on();

		}

		else{

			LCD_displayStringRowColumn(1,0,"Place Your Hand");
			RELAY_off();

		}


	}
}
