/*
 * pedestrian.c
 *
 *  Created on: Nov 29, 2023
 *      Author: Nhat Khai
 */

#include "pedestrian.h"

static GPIO_TypeDef* pedestrianRedPorts[PEDESTRIAN_NUMBER] = {PEDESTRIAN0_RED_GPIO_Port, PEDESTRIAN1_RED_GPIO_Port};
static GPIO_TypeDef* pedestrianGreenPorts[PEDESTRIAN_NUMBER] = {PEDESTRIAN0_GREEN_GPIO_Port, PEDESTRIAN1_GREEN_GPIO_Port};

static uint16_t pedestrianRedPins[PEDESTRIAN_NUMBER] = {PEDESTRIAN0_RED_Pin, PEDESTRIAN1_RED_Pin};
static uint16_t pedestrianGreenPins[PEDESTRIAN_NUMBER] = {PEDESTRIAN0_GREEN_Pin, PEDESTRIAN1_GREEN_Pin};

void pedestrianToggle(uint8_t index, enum PEDESTRIAN_STATE state) {
	switch (state) {
	case PEDESTRIAN_OFF:
		HAL_GPIO_WritePin(pedestrianRedPorts[index], pedestrianRedPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(pedestrianGreenPorts[index], pedestrianGreenPins[index], GPIO_PIN_SET);
		break;
	case PEDESTRIAN_RED:
		HAL_GPIO_WritePin(pedestrianRedPorts[index], pedestrianRedPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(pedestrianGreenPorts[index], pedestrianGreenPins[index], GPIO_PIN_SET);
		break;
	case PEDESTRIAN_GREEN:
		HAL_GPIO_WritePin(pedestrianRedPorts[index], pedestrianRedPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(pedestrianGreenPorts[index], pedestrianGreenPins[index], GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}

void pedestrian0Off(void) {
	pedestrianToggle(0, PEDESTRIAN_OFF);
}
void pedestrian0Red(void) {
	pedestrianToggle(0, PEDESTRIAN_RED);
}
void pedestrian0Green(void) {
	pedestrianToggle(0, PEDESTRIAN_GREEN);
}

void pedestrian1Off(void) {
	pedestrianToggle(1, PEDESTRIAN_OFF);
}
void pedestrian1Red(void) {
	pedestrianToggle(1, PEDESTRIAN_RED);
}
void pedestrian1Green(void) {
	pedestrianToggle(1, PEDESTRIAN_GREEN);
}
