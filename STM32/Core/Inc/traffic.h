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

#define TRAFFIC_NUMBER 2

enum TRAFFIC_STATE {TRAFFIC_OFF, TRAFFIC_RED, TRAFFIC_YELLOW, TRAFFIC_GREEN};

extern int trafficRedDuration;
extern int trafficYellowDuration;
extern int trafficGreenDuration;
extern enum TRAFFIC_STATE trafficState[TRAFFIC_NUMBER];

void traffic0Off(void);
void traffic0Red(void);
void traffic0Yellow(void);
void traffic0Green(void);

void traffic1Off(void);
void traffic1Red(void);
void traffic1Yellow(void);
void traffic1Green(void);

void trafficAuto(void);
void trafficStop(void);

#endif /* INC_TRAFFIC_H_ */
