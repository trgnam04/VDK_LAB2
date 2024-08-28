/*
 * software_timer.c
 *
 *  Created on: Aug 28, 2024
 *      Author: ASUS
 */

#include "software_timer.h"

int timer2_counter = 10;
unsigned char timer2_flag = 0;

void timer2Init();
void setTimer2(int duration){
	timer2_counter = duration;
	timer2_flag =  0;
}
