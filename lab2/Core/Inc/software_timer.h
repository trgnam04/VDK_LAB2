/*
 * software_timer.h
 *
 *  Created on: Aug 28, 2024
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer2_counter;
extern int timer2_flag;
extern const int TIMER_CYCLE;

extern void setTimer2(int duration);
extern void timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
