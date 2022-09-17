/*
 * led.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Rene
 */

#ifndef LED_H_
#define LED_H_

#include "main.h"

#define LED_GREEN		GPIO_PIN_12
#define LED_ORANGE		GPIO_PIN_13
#define LED_RED			GPIO_PIN_14
#define LED_BLUE		GPIO_PIN_15
#define HIGH			1
#define LOW				0

void led_Init(void);
void led_Toggle(uint16_t GPIO_Pin);
void led_Write(uint16_t GPIO_Pin, GPIO_PinState PinState);

#endif /* LED_H_ */
