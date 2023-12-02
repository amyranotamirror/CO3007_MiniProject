/*
 * pedestrian.c
 *
 *  Created on: Nov 29, 2023
 *      Author: Nhat Khai
 */

#include "pedestrian.h"

enum PEDESTRIAN_STATE pedestrianStates[PEDESTRIAN_NUMBER] = {};
uint32_t pedestrianCounters[PEDESTRIAN_NUMBER];

static GPIO_TypeDef* pedestrianRedPorts[PEDESTRIAN_NUMBER] = {PEDESTRIAN0_RED_GPIO_Port, PEDESTRIAN1_RED_GPIO_Port};
static GPIO_TypeDef* pedestrianGreenPorts[PEDESTRIAN_NUMBER] = {PEDESTRIAN0_GREEN_GPIO_Port, PEDESTRIAN1_GREEN_GPIO_Port};

static uint16_t pedestrianRedPins[PEDESTRIAN_NUMBER] = {PEDESTRIAN0_RED_Pin, PEDESTRIAN1_RED_Pin};
static uint16_t pedestrianGreenPins[PEDESTRIAN_NUMBER] = {PEDESTRIAN0_GREEN_Pin, PEDESTRIAN1_GREEN_Pin};
//uint8_t test;
void pedestrianToggle(uint8_t index, enum PEDESTRIAN_STATE state) {
	switch (state) {
	case PEDESTRIAN_OFF:
		HAL_GPIO_WritePin(pedestrianRedPorts[index], pedestrianRedPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(pedestrianGreenPorts[index], pedestrianGreenPins[index], GPIO_PIN_SET);
		pedestrianStates[index] = PEDESTRIAN_OFF;
		break;
	case PEDESTRIAN_RED:
		HAL_GPIO_WritePin(pedestrianRedPorts[index], pedestrianRedPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(pedestrianGreenPorts[index], pedestrianGreenPins[index], GPIO_PIN_SET);
		pedestrianStates[index] = PEDESTRIAN_RED;
		switch (trafficStates[index]) {
		case TRAFFIC_GREEN:
			pedestrianCounters[index] = trafficCounters[index] + trafficYellowDuration;
			break;
		case TRAFFIC_YELLOW:
			pedestrianCounters[index] = trafficCounters[index];
			break;
		default:
			break;
		}
		break;
	case PEDESTRIAN_GREEN:
		HAL_GPIO_WritePin(pedestrianRedPorts[index], pedestrianRedPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(pedestrianGreenPorts[index], pedestrianGreenPins[index], GPIO_PIN_RESET);
		pedestrianStates[index] = PEDESTRIAN_GREEN;
		pedestrianCounters[index] = trafficCounters[index];
		break;
	default:
		break;
	}
}

unsigned char buzzer0Flag = 0;
void pedestrian0On(void) {
	switch (trafficStates[0]) {
	case TRAFFIC_RED:
		pedestrianToggle(0, PEDESTRIAN_GREEN);
		if (buzzer0Flag == 0) {
			buzzer0On();
			buzzer0Flag = 1;
		}
		break;
	case TRAFFIC_YELLOW:
	case TRAFFIC_GREEN:
		pedestrianToggle(0, PEDESTRIAN_RED);
		buzzer0Off();
		break;
	default:
		break;
	}
}

unsigned char buzzer1Flag = 0;
void pedestrian1On(void) {
	switch (trafficStates[1]) {
	case TRAFFIC_RED:
		pedestrianToggle(1, PEDESTRIAN_GREEN);
		if (buzzer1Flag == 0) {
			buzzer1On();
			buzzer1Flag = 1;
		}
		break;
	case TRAFFIC_YELLOW:
	case TRAFFIC_GREEN:
		pedestrianToggle(1, PEDESTRIAN_RED);
		buzzer1Off();
		break;
	default:
		break;
	}
}

void pedestrian0Off(void) {
	pedestrianToggle(0, PEDESTRIAN_OFF);
	buzzer0Off();
	buzzer0Flag = 0;
}

void pedestrian1Off(void) {
	pedestrianToggle(1, PEDESTRIAN_OFF);
	buzzer1Off();
	buzzer1Flag = 0;
}
