/*
 * fsm.c
 *
 *  Created on: Nov 29, 2023
 *      Author: Nhat Khai
 */

#include "fsm.h"

static uint8_t fsmAutoIDs[6] = {};

void fsmProcessing(void) {
}

void fsmAuto(void) {
	fsmAutoIDs[0] = SCH_AddTask(traffic0Red, 0, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[1] = SCH_AddTask(traffic0Green, trafficRedDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[2] = SCH_AddTask(traffic0Yellow, trafficRedDuration + trafficYellowDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[3] = SCH_AddTask(traffic1Green, 0, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[4] = SCH_AddTask(traffic1Yellow, trafficGreenDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[5] = SCH_AddTask(traffic1Red, trafficGreenDuration + trafficYellowDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
}
