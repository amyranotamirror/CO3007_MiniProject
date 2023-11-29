/*
 * traffic.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

#include <stdint.h>
#include "main.h"
#include "scheduler.h"
#include "pedestrian.h"

#define TRAFFIC_NUMBER 2

enum TRAFFIC_STATE {TRAFFIC_OFF, TRAFFIC_RED, TRAFFIC_GREEN, TRAFFIC_YELLOW};

extern int trafficRedDuration;
extern int trafficGreenDuration;
extern int trafficYellowDuration;
extern enum TRAFFIC_STATE trafficStates[TRAFFIC_NUMBER];

void trafficToggle(uint8_t index, enum TRAFFIC_STATE state);

void traffic0Off(void);
void traffic0Red(void);
void traffic0Green(void);
void traffic0Yellow(void);

void traffic1Off(void);
void traffic1Red(void);
void traffic1Green(void);
void traffic1Yellow(void);

void trafficRedToggle(void);
void trafficGreenToggle(void);
void trafficYellowToggle(void);

#endif /* INC_TRAFFIC_H_ */
