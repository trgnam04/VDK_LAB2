/*
 * lab2_ex7.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#ifndef INC_LAB2_EX7_H_
#define INC_LAB2_EX7_H_

#include "main.h"

void setTime(uint8_t Sec, uint8_t Min, uint8_t Hour);
void updateTime(void);

void blinkLed(void);

void display_Led7seg(int counter);
void update7SEG(int index);
void updateClockBuffer(void);



#endif /* INC_LAB2_EX7_H_ */
