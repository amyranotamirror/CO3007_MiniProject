/*
 * buzzer.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include <stdint.h>
#include "main.h"
#include "pedestrian.h"

#define BUZZER_NUMBER 2
#define BUZZER_RATIO 100 / 100
#define BUZZER_MIN 0
#define BUZZER_MAX htim3.Init.Period
#define BUZZER_TIMEOUT 2000

#define BUZZER_VOLUME_MIN 0		// Min volume: virtual num
#define BUZZER_VOLUME_MAX 100	// Max volume: virtual num
#define BUZZER_VOLUME_AUTO 0	// Auto volume: virtual num

extern uint8_t buzzerVolumes[BUZZER_NUMBER];

void buzzer0On(void);
void buzzer0Off(void);
void buzzer1On(void);
void buzzer1Off(void);

#endif /* INC_BUZZER_H_ */
