/*
 * relay.c
 *
 *  Created on: Oct 4, 2024
 *      Author: SoO
 *
 * Module: relay
 *
 * File Name: relay.c
 *
 * Description: source file for the relay driver
 */

#include "relay.h"

#include"gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the relay:
 * 1. Setup the relay pins direction by using the GPIO driver.
 * 2. write logic low on the relay to turn it off.
 */
void RELAY_init(){

	GPIO_setupPinDirection(RELAY_PORT,RELAY_PIN,PIN_OUTPUT);//set the relay as output
	GPIO_writePin(RELAY_PORT,RELAY_PIN,RELAY_OFF);//turn relay off
}

/*
 * Description :
 * Function responsible for turning the relay on.
 */
void RELAY_on(){
	GPIO_writePin(RELAY_PORT,RELAY_PIN,RELAY_ON);//turn relay on
}

/*
 * Description :
 * Function responsible for turning the relay off.
 */
void RELAY_off(){
	GPIO_writePin(RELAY_PORT,RELAY_PIN,RELAY_OFF);//turn relay on
}
