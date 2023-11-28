/*
 * button.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdint.h>
#include "main.h"
#include "scheduler.h"

#define BUTTON_NUMBER 4
#define BUTTON_PRESSED_DURATION 1000
#define BUTTON_HOLDING_DURATION 500
#define BUTTON_PRESSED GPIO_PIN_RESET
#define BUTTON_RELEASED GPIO_PIN_SET

void buttonReading(void);
unsigned char buttonPressed(uint8_t index);

#endif /* INC_BUTTON_H_ */
