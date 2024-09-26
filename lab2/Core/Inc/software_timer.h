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

extern uint8_t timer1_flag;
extern uint8_t timer2_flag;

extern void setTimer1(int duration);
extern void setTimer2(int duration);

void timer_run();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);


#endif /* INC_SOFTWARE_TIMER_H_ */
