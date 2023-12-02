/*
 * buzzer.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Nhat Khai
 */

#include "buzzer.h"

extern TIM_HandleTypeDef htim3;

void buzzer0Set(void) {
	uint32_t pulseWidth = 0;
	if (pedestrianCounters[0] > BUZZER_TIMEOUT) {
    	pulseWidth = BUZZER_MAX * BUZZER_RATIO * 10 / 100;
	}
	else {
		pulseWidth = BUZZER_MAX * BUZZER_RATIO * (BUZZER_VOLUME_AUTO + (BUZZER_VOLUME_MAX - BUZZER_VOLUME_AUTO) * (BUZZER_TIMEOUT - pedestrianCounters[1]) / BUZZER_TIMEOUT) / 100;
	}
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulseWidth);
}

void buzzer0On(void) {
	uint32_t period = 0;
	uint32_t delay = 0;
	if (pedestrianCounters[0] > BUZZER_TIMEOUT) {
		period = 200;
		delay = 100;
	}
	else {
		period = pedestrianCounters[0] / 20;
		delay = period / 2;
	}
	SCH_AddTask(buzzer0Set, 0, 0);
	SCH_AddTask(buzzer0Off, delay, 0);
	if (period > 0) {
		SCH_AddTask(buzzer0On, period, 0);
	}
}

void buzzer1Set(void) {
	uint32_t pulseWidth = 0;
	if (pedestrianCounters[1] > BUZZER_TIMEOUT) {
    	pulseWidth = BUZZER_MAX * BUZZER_RATIO * 10 / 100;
	}
	else {
		pulseWidth = BUZZER_MAX * BUZZER_RATIO * (BUZZER_VOLUME_AUTO + (BUZZER_VOLUME_MAX - BUZZER_VOLUME_AUTO) * (BUZZER_TIMEOUT - pedestrianCounters[1]) / BUZZER_TIMEOUT) / 100;
	}
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pulseWidth);
}

void buzzer1On(void) {
	uint32_t period = 0;
	uint32_t delay = 0;
	if (pedestrianCounters[1] > BUZZER_TIMEOUT) {
		period = 200;
		delay = 100;
	}
	else {
		period = pedestrianCounters[1] / 20;
		delay = period / 2;
	}
	SCH_AddTask(buzzer1Set, 0, 0);
	SCH_AddTask(buzzer1Off, delay, 0);
	if (period > 0) {
		SCH_AddTask(buzzer1On, period, 0);
	}
}

void buzzer0Off(void) {
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
}

void buzzer1Off(void) {
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
}
