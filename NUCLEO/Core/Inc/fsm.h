/*
 * fsm.h
 *
 *  Created on: Nov 29, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "button.h"
#include "buzzer.h"
#include "counter.h"
#include "pedestrian.h"
#include "scheduler.h"
#include "test.h"
#include "traffic.h"
#include "uart.h"

enum FSM_STATE {FSM_INIT, FSM_AUTO, FSM_MANUAL, FSM_TUNNING};
extern enum FSM_STATE fsmState;

void fsmInit(void);
void fsmProcessing(void);

#endif /* INC_FSM_H_ */
