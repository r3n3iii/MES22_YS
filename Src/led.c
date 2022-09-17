/*
 * led.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Rene
 */
#include "led.h"

void led_Init(void)
{
	// Define a GPIO_InitTypeDef structure
	GPIO_InitTypeDef LED_InitStruct;

	// Enable clock for the port D
	  __HAL_RCC_GPIOD_CLK_ENABLE();

	// Configure GPIO pin Output Level as 0
	  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);

	// Configure GPIO pins : LED_BLUE|LED_GREEN|LED_ORANGE|LED_RED
	  LED_InitStruct.Pin = LED_BLUE|LED_GREEN|LED_ORANGE|LED_RED;
	  LED_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  LED_InitStruct.Pull = GPIO_NOPULL;
	  LED_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	  HAL_GPIO_Init(GPIOD, &LED_InitStruct);


}
void led_Toggle(uint16_t GPIO_Pin)
{
	HAL_GPIO_TogglePin(GPIOD, GPIO_Pin);
}

void led_Write(uint16_t GPIO_Pin, GPIO_PinState PinState)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_Pin, PinState);
}
