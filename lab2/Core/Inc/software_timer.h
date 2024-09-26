/*
 * software_timer.h
 *
 *  Created on: Aug 28, 2024
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define TIMER_CYCLE 1

extern int timer1_flag;
extern int timer2_flag;


extern void setTimer1(int duration);
extern void setTimer2(int duration);
extern void timer_run();

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_SOFTWARE_TIMER_H_ */
