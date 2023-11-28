/*
 * scheduler.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Nhat Khai
 */

#include "scheduler.h"

SCH_Task tasks[SCH_TASKNUMBER];

void SCH_Init(void) {
    for (uint8_t i = 0; i < SCH_TASKNUMBER; i ++) {
        tasks[i].functionPointer = 0;
        tasks[i].id = SCH_TASKNUMBER - i - 1;
        tasks[i].delay = 0;
        tasks[i].period = 0;
        tasks[i].flag = 0;
    }
}

void SCH_Update(void) {
    if (tasks[0].functionPointer == 0) return;
	if (tasks[0].delay > 0) {
		if (tasks[0].delay > SCH_TIMERTICK) {
			tasks[0].delay -= SCH_TIMERTICK;
		}
		else {
			tasks[0].delay = 0;
		}
	}
	if (tasks[0].delay == 0) {
		tasks[0].flag = 1;
	}
}

void SCH_Dispatch(void) {
	if (tasks[0].functionPointer == 0 || tasks[0].flag == 0) return;
	(*tasks[0].functionPointer)();
	tasks[0].flag = 0;
	SCH_Task newTask = tasks[0];
	SCH_DeleteTask(tasks[0].id);
	if (newTask.period > 0) {
		SCH_AddTask(newTask.functionPointer, newTask.period, newTask.period);
	}
}

uint8_t SCH_AddTask(void (*functionPointer)(void), uint32_t delay, uint32_t period) {
    if (tasks[SCH_TASKNUMBER - 1].functionPointer != 0) return SCH_TASKNUMBER;
    uint8_t currentID = tasks[SCH_TASKNUMBER - 1].id;
    uint32_t currentDelay = 0;
    for (uint8_t i = 0; i < SCH_TASKNUMBER; i ++) {
        currentDelay += tasks[i].delay;
        if (currentDelay > delay || tasks[i].functionPointer == 0) {
            for (uint8_t j = SCH_TASKNUMBER - 1; j > i; j --) {
                tasks[j] = tasks[j - 1];
            }
            tasks[i].functionPointer = functionPointer;
            tasks[i].id = currentID;
            tasks[i].period = period;
            tasks[i].flag = 0;
            if (currentDelay > delay) {
                int newDelay = currentDelay - delay;
                tasks[i].delay = tasks[i + 1].delay - newDelay;
                if (tasks[i].delay == 0) {
                    tasks[i].flag = 1;
                }
                tasks[i + 1].delay = newDelay;
                if (tasks[i + 1].delay == 0) {
                    tasks[i + 1].flag = 1;
                }
            }
            else {
                tasks[i].delay = delay - currentDelay;
                if (tasks[i].delay == 0) {
                    tasks[i].flag = 1;
                }
            }
            return tasks[i].id;
        }
    }
    return SCH_TASKNUMBER;
}

unsigned char SCH_DeleteTask(uint8_t id) {
    for (uint8_t i = 0; i < SCH_TASKNUMBER; i ++) {
        if (tasks[i].id == id) {
            uint8_t currentID = tasks[i].id;
            if (tasks[i + 1].functionPointer != 0) {
                tasks[i + 1].delay += tasks[i].delay;
            }
            for (uint8_t j = i; j < SCH_TASKNUMBER - 1; j ++) {
                tasks[j] = tasks[j + 1];
            }
            tasks[SCH_TASKNUMBER - 1].functionPointer = 0;
            tasks[SCH_TASKNUMBER - 1].id = currentID;
            tasks[SCH_TASKNUMBER - 1].delay = 0;
            tasks[SCH_TASKNUMBER - 1].period = 0;
            tasks[SCH_TASKNUMBER - 1].flag = 0;
            return tasks[SCH_TASKNUMBER - 1].functionPointer == 0;
        }
    }
    return 0;
}
