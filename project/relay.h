/*
 * relay.h
 *
 *  Created on: Oct 4, 2024
 *      Author: SoO
 *
 * Module: relay
 *
 * File Name: relay.h
 *
 * Description: header file for the relay driver
 */

#ifndef RELAY_H_
#define RELAY_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define RELAY_PORT PORTC_ID
#define RELAY_PIN  PIN4_ID
#define RELAY_OFF  LOGIC_LOW
#define RELAY_ON   LOGIC_HIGH



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the relay.
 */
void RELAY_init();

/*
 * Description :
 * Function responsible for turning the relay on.
 */
void RELAY_on();

/*
 * Description :
 * Function responsible for turning a led off.
 */
void RELAY_off();
#endif /* RELAY_H_ */
