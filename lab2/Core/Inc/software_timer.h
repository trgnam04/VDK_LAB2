/*
 * software_timer.h
 *
 *  Created on: Aug 28, 2024
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer2_counter;
extern unsigned char timer2_flag;


void timer2Init();
void setTimer2(int duration);


#endif /* INC_SOFTWARE_TIMER_H_ */
