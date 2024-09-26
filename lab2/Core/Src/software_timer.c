/*
 * software_timer.c
 *
 *  Created on: Aug 28, 2024
 *      Author: ASUS
 */

#include "software_timer.h"

#define TIMER_CYCLE 1


int timer2_counter = 0;
unsigned char timer2_flag = 0;

void timer2Init();

void setTimer2(int duration){
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag =  0;
}
