/*
 * pedestrian.h
 *
 *  Created on: Nov 29, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_PEDESTRIAN_H_
#define INC_PEDESTRIAN_H_

#include "main.h"

#define PEDESTRIAN_NUMBER 2

enum PEDESTRIAN_STATE {PEDESTRIAN_OFF, PEDESTRIAN_RED, PEDESTRIAN_GREEN};

extern enum PEDESTRIAN_STATE pedestrianStates[PEDESTRIAN_NUMBER];

void pedestrianToggle(uint8_t index, enum PEDESTRIAN_STATE state);

void pedestrian0Off(void);
void pedestrian0Red(void);
void pedestrian0Green(void);

void pedestrian1Off(void);
void pedestrian1Red(void);
void pedestrian1Green(void);

#endif /* INC_PEDESTRIAN_H_ */
