/*
 * counter.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Nhat Khai
 */

#include "counter.h"

void counterRun(void) {
	if (trafficCounters[0] > TIMER_TICK) {
		trafficCounters[0] -= TIMER_TICK;
	}
	else {
		trafficCounters[0] = 0;
	}
	if (trafficCounters[1] > TIMER_TICK) {
		trafficCounters[1] -= TIMER_TICK;
	}
	else {
		trafficCounters[1] = 0;
	}
	if (pedestrianCounters[0] > TIMER_TICK) {
		pedestrianCounters[0] -= TIMER_TICK;
	}
	else {
		pedestrianCounters[0] = 0;
	}
	if (pedestrianCounters[1] > TIMER_TICK) {
		pedestrianCounters[1] -= TIMER_TICK;
	}
	else {
		pedestrianCounters[1] = 0;
	}
}

void counterReset(void) {
	trafficCounters[0] = 0;
	trafficCounters[1] = 0;
	pedestrianCounters[0] = 0;
	pedestrianCounters[1] = 0;
}
