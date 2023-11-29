/*
 * traffic.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Nhat Khai
 */

#include "traffic.h"

int trafficRedDuration = 5000;
int trafficGreenDuration = 3000;
int trafficYellowDuration = 2000;
enum TRAFFIC_STATE trafficStates[TRAFFIC_NUMBER] = {};

static GPIO_TypeDef* trafficRedPorts[TRAFFIC_NUMBER] = {TRAFFIC0_RED_GPIO_Port, TRAFFIC1_RED_GPIO_Port};
static GPIO_TypeDef* trafficGreenPorts[TRAFFIC_NUMBER] = {TRAFFIC0_GREEN_GPIO_Port, TRAFFIC1_GREEN_GPIO_Port};
static GPIO_TypeDef* trafficYellowPorts[TRAFFIC_NUMBER] = {TRAFFIC0_YELLOW_GPIO_Port, TRAFFIC1_YELLOW_GPIO_Port};

static uint16_t trafficRedPins[TRAFFIC_NUMBER] = {TRAFFIC0_RED_Pin, TRAFFIC1_RED_Pin};
static uint16_t trafficGreenPins[TRAFFIC_NUMBER] = {TRAFFIC0_GREEN_Pin, TRAFFIC1_GREEN_Pin};
static uint16_t trafficYellowPins[TRAFFIC_NUMBER] = {TRAFFIC0_YELLOW_Pin, TRAFFIC1_YELLOW_Pin};

void trafficToggle(uint8_t index, enum TRAFFIC_STATE state) {
	switch (state) {
	case TRAFFIC_OFF:
		HAL_GPIO_WritePin(trafficRedPorts[index], trafficRedPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(trafficYellowPorts[index], trafficYellowPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(trafficGreenPorts[index], trafficGreenPins[index], GPIO_PIN_SET);
		trafficStates[index] = TRAFFIC_OFF;
		if (pedestrianStates[index] != PEDESTRIAN_OFF) {
			pedestrianToggle(index, PEDESTRIAN_OFF);
		}
		break;
	case TRAFFIC_RED:
		HAL_GPIO_WritePin(trafficRedPorts[index], trafficRedPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(trafficYellowPorts[index], trafficYellowPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(trafficGreenPorts[index], trafficGreenPins[index], GPIO_PIN_SET);
		trafficStates[index] = TRAFFIC_RED;
		if (pedestrianStates[index] != PEDESTRIAN_OFF) {
			pedestrianToggle(index, PEDESTRIAN_GREEN);
		}
		break;
	case TRAFFIC_GREEN:
		HAL_GPIO_WritePin(trafficRedPorts[index], trafficRedPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(trafficYellowPorts[index], trafficYellowPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(trafficGreenPorts[index], trafficGreenPins[index], GPIO_PIN_RESET);
		trafficStates[index] = TRAFFIC_GREEN;
		if (pedestrianStates[index] != PEDESTRIAN_OFF) {
			pedestrianToggle(index, PEDESTRIAN_OFF);
		}
		break;
	case TRAFFIC_YELLOW:
		HAL_GPIO_WritePin(trafficRedPorts[index], trafficRedPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(trafficYellowPorts[index], trafficYellowPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(trafficGreenPorts[index], trafficGreenPins[index], GPIO_PIN_SET);
		trafficStates[index] = TRAFFIC_YELLOW;
		break;
	default:
		break;
	}
}

void traffic0Off(void) {
	trafficToggle(0, TRAFFIC_OFF);
}
void traffic0Red(void) {
	trafficToggle(0, TRAFFIC_RED);
}
void traffic0Green(void) {
	trafficToggle(0, TRAFFIC_GREEN);
}
void traffic0Yellow(void) {
	trafficToggle(0, TRAFFIC_YELLOW);
}

void traffic1Off(void) {
	trafficToggle(1, TRAFFIC_OFF);
}
void traffic1Red(void) {
	trafficToggle(1, TRAFFIC_RED);
}
void traffic1Green(void) {
	trafficToggle(1, TRAFFIC_GREEN);
}
void traffic1Yellow(void) {
	trafficToggle(1, TRAFFIC_YELLOW);
}

void trafficRedToggle(void) {
	SCH_AddTask(traffic0Red, 0, 0);
	SCH_AddTask(traffic1Red, 0, 0);
	SCH_AddTask(traffic0Off, 500, 0);
	SCH_AddTask(traffic1Off, 500, 0);
}
void trafficGreenToggle(void) {
	SCH_AddTask(traffic0Green, 0, 0);
	SCH_AddTask(traffic1Green, 0, 0);
	SCH_AddTask(traffic0Off, 500, 0);
	SCH_AddTask(traffic1Off, 500, 0);
}
void trafficYellowToggle(void) {
	SCH_AddTask(traffic0Yellow, 0, 0);
	SCH_AddTask(traffic1Yellow, 0, 0);
	SCH_AddTask(traffic0Off, 500, 0);
	SCH_AddTask(traffic1Off, 500, 0);
}
