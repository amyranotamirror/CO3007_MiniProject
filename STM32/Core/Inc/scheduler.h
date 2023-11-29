/*
 * scheduler.h
 *
 *  Created on: Nov 27, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdio.h>
#define SCH_TASKNUMBER 16
#define SCH_TIMERTICK 10

typedef struct {
    void (*functionPointer)(void);
    uint8_t id;
    uint32_t delay;
    uint32_t period;
    unsigned char flag;
} SCH_Task;

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch(void);

uint8_t SCH_AddTask(void (*functionPointer)(void), uint32_t delay, uint32_t period);
unsigned char SCH_DeleteTask(uint8_t id);
unsigned char SCH_RefreshTask(void);

uint8_t SCH_Report(void);

#endif /* INC_SCHEDULER_H_ */
