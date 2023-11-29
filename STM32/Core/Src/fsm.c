/*
 * fsm.c
 *
 *  Created on: Nov 29, 2023
 *      Author: Nhat Khai
 */

#include "fsm.h"

#define FSM_AUTO_TASK 7
#define FSM_MANUAL_TASK 1
#define FSM_TUNNING_TASK 1

static enum FSM_STATE fsmState = FSM_AUTO;

static uint8_t fsmAutoIDs[FSM_AUTO_TASK] = {};
static uint8_t fsmManualIDs[FSM_MANUAL_TASK] = {};
static uint8_t fsmTunningIDs[FSM_TUNNING_TASK] = {};

void fsmAuto(void) {
	if (buttonPressed(1)) {
		switch (trafficStates[0]) {
		case TRAFFIC_RED:
			SCH_AddTask(pedestrian0Green, 0, 0);
			break;
		case TRAFFIC_YELLOW:
		case TRAFFIC_GREEN:
			SCH_AddTask(pedestrian0Red, 0, 0);
			break;
		default:
			break;
		}
	}
	if (buttonPressed(2)) {
		switch (trafficStates[1]) {
		case TRAFFIC_RED:
			SCH_AddTask(pedestrian1Green, 0, 0);
			break;
		case TRAFFIC_YELLOW:
		case TRAFFIC_GREEN:
			SCH_AddTask(pedestrian1Red, 0, 0);
			break;
		default:
			break;
		}
	}
}

void fsmInitAuto(void) {
	SCH_AddTask(pedestrian0Off, 0, 0);
	SCH_AddTask(pedestrian1Off, 0, 0);
	fsmAutoIDs[0] = SCH_AddTask(traffic0Red, 0, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[1] = SCH_AddTask(traffic0Green, trafficRedDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[2] = SCH_AddTask(traffic0Yellow, trafficRedDuration + trafficYellowDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[3] = SCH_AddTask(traffic1Green, 0, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[4] = SCH_AddTask(traffic1Yellow, trafficGreenDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[5] = SCH_AddTask(traffic1Red, trafficGreenDuration + trafficYellowDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[6] = SCH_AddTask(fsmAuto, 10, 10);
}

void fsmManual(void) {
	if (buttonPressed(1)) {
		switch (trafficStates[0]) {
		case TRAFFIC_RED:
			SCH_AddTask(traffic0Green, 0, 0);
			SCH_AddTask(pedestrian0Red, 0, 0);
			break;
		case TRAFFIC_GREEN:
			SCH_AddTask(traffic0Yellow, 0, 0);
			break;
		case TRAFFIC_YELLOW:
			SCH_AddTask(traffic0Red, 0, 0);
			SCH_AddTask(pedestrian0Green, 0, 0);
			break;
		default:
			break;
		}
	}
	if (buttonPressed(2)) {
		switch (trafficStates[1]) {
		case TRAFFIC_RED:
			SCH_AddTask(traffic1Green, 0, 0);
			SCH_AddTask(pedestrian1Red, 0, 0);
			break;
		case TRAFFIC_GREEN:
			SCH_AddTask(traffic1Yellow, 0, 0);
			break;
		case TRAFFIC_YELLOW:
			SCH_AddTask(traffic1Red, 0, 0);
			SCH_AddTask(pedestrian1Green, 0, 0);
			break;
		default:
			break;
		}
	}
}

void fsmInitManual(void) {
	SCH_AddTask(traffic0Red, 0, 0);
	SCH_AddTask(traffic1Green, 0, 0);
	SCH_AddTask(pedestrian0Green, 0, 0);
	SCH_AddTask(pedestrian1Red, 0, 0);
	fsmManualIDs[0] = SCH_AddTask(fsmManual, 10, 10);
}

void fsmTunning(void) {}

void fsmInitTunning(void) {
	fsmTunningIDs[0] = SCH_AddTask(fsmTunning, 10, 10);
}

void fsmInit(void) {
	SCH_AddTask(traffic0Off, 0, 0);
	SCH_AddTask(traffic1Off, 0, 0);
	SCH_AddTask(pedestrian0Off, 0, 0);
	SCH_AddTask(pedestrian1Off, 0, 0);
	SCH_AddTask(fsmInitAuto, 0, 0);
}

void fsmProcessing(void) {
	if (buttonPressed(0)) {
		switch (fsmState) {
		case FSM_AUTO:
			for (uint8_t i = 0; i < FSM_AUTO_TASK; i ++) {
				SCH_DeleteTask(fsmAutoIDs[i]);
			}
			SCH_AddTask(fsmInitManual, 0, 0);
			fsmState = FSM_MANUAL;
			break;
		case FSM_MANUAL:
			for (uint8_t i = 0; i < FSM_MANUAL_TASK; i ++) {
				SCH_DeleteTask(fsmManualIDs[i]);
			}
			SCH_AddTask(fsmInitTunning, 0, 0);
			fsmState = FSM_TUNNING;
			break;
		case FSM_TUNNING:
			for (uint8_t i = 0; i < FSM_TUNNING_TASK; i ++) {
				SCH_DeleteTask(fsmTunningIDs[i]);
			}
			SCH_AddTask(fsmInitAuto, 0, 0);
			fsmState = FSM_AUTO;
			break;
		default:
			break;
		}
	}
}
