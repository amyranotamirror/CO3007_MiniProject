/*
 * fsm.h
 *
 *  Created on: Nov 29, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "scheduler.h"
#include "button.h"
#include "traffic.h"
#include "pedestrian.h"

enum FSM_STATE {FSM_AUTO, FSM_MANUAL, FSM_TUNNING};

void fsmInit(void);
void fsmProcessing(void);

#endif /* INC_FSM_H_ */
