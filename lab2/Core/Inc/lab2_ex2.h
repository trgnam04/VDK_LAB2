/*
 * lab2_ex2.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#ifndef INC_LAB2_EX2_H_
#define INC_LAB2_EX2_H_

#include "main.h"

void setTime(uint8_t Sec, uint8_t Min, uint8_t Hour);
void blinkLed(void);
void updateTime(void);
void display_Led7seg(int counter);
void display_Clock(void);
void update7SEG(int index);
void Clock_interface(void);

#endif /* INC_LAB2_EX2_H_ */
