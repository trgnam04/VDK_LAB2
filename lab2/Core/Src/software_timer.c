/*
 * software_timer.c
 *
 *  Created on: Aug 28, 2024
 *      Author: ASUS
 */

#include "software_timer.h"

uint8_t timer1_flag = 0;
uint8_t timer2_flag = 0;
int timer2_counter = 0;
int timer1_counter = 0;




void setTimer1(int duration){
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}


void setTimer2(int duration){
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag = 0;
}

void timer_run(){
	if(timer1_counter > 0){
		timer1_counter--;
	}
	if(timer1_counter == 0) timer1_flag = 1;

	if(timer2_counter > 0){
		timer2_counter--;
	}
	if(timer2_counter == 0) timer2_flag = 1;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		timer_run();
	}
}

