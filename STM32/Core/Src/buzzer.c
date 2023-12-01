/*
 * buzzer.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Nhat Khai
 */

#include "buzzer.h"

extern TIM_HandleTypeDef htim3;

void buzzer0Set(uint8_t volume){
	// Ensure volume stays in the range: 0% - 100%
	if (volume < BUZZER_VOLUME_MIN) {
		volume = BUZZER_VOLUME_MIN;
	}
	if (volume > BUZZER_VOLUME_MAX) {
        volume = BUZZER_VOLUME_MAX;
	}

    // Calculate and set PWM to Buzzer
    uint32_t pulseWidth = BUZZER_MAX * BUZZER_RATIO * volume / 100;
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulseWidth);
}

void buzzer1Set(uint8_t volume){
    // Ensure volume stays in the range: 0% - 100%
	if (volume < BUZZER_VOLUME_MIN) {
		volume = BUZZER_VOLUME_MIN;
	}
	if (volume > BUZZER_VOLUME_MAX) {
        volume = BUZZER_VOLUME_MAX;
	}

    // Calculate and set PWM to Buzzer
    uint32_t pulseWidth = BUZZER_MAX * BUZZER_RATIO * volume / 100;
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pulseWidth);
}

void buzzer0On(void) {
	if (pedestrianCounters[0] > BUZZER_TIMEOUT) {
		buzzer0Set(BUZZER_VOLUME_AUTO);
	}
	else {
		buzzer0Set(BUZZER_VOLUME_AUTO + (BUZZER_VOLUME_MAX - BUZZER_VOLUME_AUTO) * (BUZZER_TIMEOUT - pedestrianCounters[0]) / BUZZER_TIMEOUT);
	}
}

void buzzer0Off(void) {
	buzzer0Set(0);
}

void buzzer1On(void) {
	if (pedestrianCounters[1] > BUZZER_TIMEOUT) {
		buzzer1Set(BUZZER_VOLUME_AUTO);
	}
	else {
		buzzer1Set(BUZZER_VOLUME_AUTO + (BUZZER_VOLUME_MAX - BUZZER_VOLUME_AUTO) * (BUZZER_TIMEOUT - pedestrianCounters[1]) / BUZZER_TIMEOUT);
	}
}

void buzzer1Off(void) {
	buzzer1Set(0);
}
