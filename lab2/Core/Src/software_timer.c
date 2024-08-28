/*
 * software_timer.c
 *
 *  Created on: Aug 28, 2024
 *      Author: ASUS
 */

#include "software_timer.h"

int timer2_counter = 0;
int timer2_flag = 0;
const int TIMER_CYCLE = 10;

void setTimer2(int duration){
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag = 0;
}

void timer_run(){
	if(timer2_counter > 0){
		timer2_counter--;
	}
	if(timer2_counter == 0) timer2_flag = 1;
}
