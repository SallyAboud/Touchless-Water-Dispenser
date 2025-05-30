/*
 * Ultrasonic.c
 *
 *  Created on: Oct 11, 2024
 *      Author: SoO
 *
 * Module: Ultrasonic sensor
 *
 * File Name: Ultrasonic.c
 *
 * Description: source file for the ultrasonic sensor driver
 */

#include"Ultrasonic.h"
#include"icu.h"
#include"gpio.h"
#include<util/delay.h>
#include<avr/io.h>


uint16 g_time=0;
uint8 g_edgeCount=0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the ultrasonic sensor.
 */
void Ultrasonic_init(void){

	/* Create configuration structure for ICU driver */
	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Set the Call back function pointer in the ICU driver */
	ICU_setCallBack(Ultrasonic_edge_processing);

	/* Initialize the ICU driver */
	ICU_init(&ICU_Configurations);

	/*set the direction for the trigger pin as output through the GPIO driver*/
	GPIO_setupPinDirection(TRIGGER_PORT,TRIGGER_PIN,PIN_OUTPUT);

}

/*
 * Description :
 * Function responsible for sending the trigger pulse to the ultrasonic sensor.
 */
void Ultrasonic_Trigger(void){

	/*send the trigger pulse for 10us*/
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_LOW);
}

/*
 * Description :
 * Function responsible for:
 * 1.sending the trigger pulse by using the Ultrasonic_Trigger function.
 * 2.start the measurement process via the ICU driver.
 */
uint16 Ultrasonic_readDistance(void){
	uint16 dis;
	/*send the trigger pulse*/
	Ultrasonic_Trigger();
	dis=g_time/117.6;
	return dis;
}

/*
 * Description :
 * Function responsible for:
 * 1.the callback function called by the ICU driver.
 * 2.it calculates the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edge_processing(void){

	g_edgeCount++;
	if(g_edgeCount == 1){

		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2){
		/* Store the High time value */
		g_time = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount = 0;
	}

}
