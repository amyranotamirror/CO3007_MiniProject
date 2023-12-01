/*
 * uart.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Nhat Khai
 */

#include "uart.h"

extern UART_HandleTypeDef huart2;

void uartReport(void) {
	char str[40];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Time: %lu - Task: %u\r\n", HAL_GetTick(), SCH_Report()), 100);
}

void uartRedDuration(void) {
	char str[20];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!7SEG:%02lu#\r\n", trafficRedDuration / 1000), 100);
}

void uartGreenDuration(void) {
	char str[20];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!7SEG:%02lu#\r\n", trafficGreenDuration / 1000), 100);
}

void uartYellowDuration(void) {
	char str[20];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!7SEG:%02lu#\r\n", trafficYellowDuration / 1000), 100);
}

void uartCounter(void) {
	char str[20];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!7SEG:%02lu#\r\n", trafficCounters[0] / 1000), 100);
}
