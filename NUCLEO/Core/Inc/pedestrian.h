/*
 * pedestrian.h
 *
 *  Created on: Nov 29, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_PEDESTRIAN_H_
#define INC_PEDESTRIAN_H_

#include "main.h"
#include "buzzer.h"
#include "traffic.h"

#define PEDESTRIAN_NUMBER 2

enum PEDESTRIAN_STATE {PEDESTRIAN_OFF, PEDESTRIAN_RED, PEDESTRIAN_GREEN};

extern enum PEDESTRIAN_STATE pedestrianStates[PEDESTRIAN_NUMBER];
extern uint32_t pedestrianCounters[PEDESTRIAN_NUMBER];

void pedestrian0On(void);
void pedestrian1On(void);
void pedestrian0Off(void);
void pedestrian1Off(void);

#endif /* INC_PEDESTRIAN_H_ */
