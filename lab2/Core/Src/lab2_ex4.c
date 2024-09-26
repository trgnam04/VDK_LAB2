/*
 * lab2_ex4.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#include "lab2_ex4.h"

#define BUFFER_SIZE 4
#define BLINKY_TIME 100
#define CLOCK_FREQ	50


static uint8_t buffer_7seg[BUFFER_SIZE] = {1, 2, 3, 4};
static uint8_t led_blinky = BLINKY_TIME;
static uint8_t clock_freq = CLOCK_FREQ;
static uint8_t state = 0;
static uint8_t sec = 0;
static uint8_t min = 0;
static uint8_t hour = 0;



void setTime(uint8_t Sec, uint8_t Min, uint8_t Hour){
	if(Sec > 59 || Min > 59 || Hour > 23 || (Sec * Min * Hour < 0)) return;
	sec = Sec;
	min = Min;
	hour = Hour;
}

void blinkLed(void){
	led_blinky--;
	if(led_blinky <= 0){
		led_blinky = BLINKY_TIME;
		HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
	}
}

void updateTime(void){
	sec++;
	if(sec == 60){
		sec = 0;
		min++;
	}
	if(min == 60){
		min = 0;
		hour++;
	}
	if(hour == 24){
		hour = 0;
	}
}
void display_Led7seg(int counter) {
    // Reset all segments
    HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, SET);

    switch(counter) {
        case 0: // Display '0'
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin, RESET);
            break;
        case 1: // Display '1'
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin, RESET);
            break;
        case 2: // Display '2'
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG3_Pin | SEG4_Pin | SEG6_Pin, RESET);
            break;
        case 3: // Display '3'
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG6_Pin, RESET);
            break;
        case 4: // Display '4'
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin | SEG5_Pin | SEG6_Pin, RESET);
            break;
        case 5: // Display '5'
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin, RESET);
            break;
        case 6: // Display '6'
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, RESET);
            break;
        case 7: // Display '7'
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin, RESET);
            break;
        case 8: // Display '8'
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, RESET);
            break;
        case 9: // Display '9'
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin, RESET);
            break;
    }
}

void Clock_interface(void){
	switch(state){
	case 0:{
		display_Led7seg(min % 10);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin, SET);
		state = 1;
		break;
	}
	case 1:{
		display_Led7seg(min / 10);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN3_Pin, SET);
		state = 2;
		break;
	}
	case 2:{
		display_Led7seg(hour % 10);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN0_Pin|EN3_Pin, SET);
		state = 3;
		break;
	}
	case 3:{
		display_Led7seg(hour / 10);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN0_Pin, SET);
		state = 0;
		break;
	}
	}
}

void display_Clock(void){
	clock_freq--;
	if(clock_freq == 0){
		clock_freq = CLOCK_FREQ;
		Clock_interface();
	}
}


void update7SEG(int index){
	switch(index){
		case 0:{
			display_Led7seg(buffer_7seg[0]);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin, SET);
			break;
		}
		case 1:{
			display_Led7seg(buffer_7seg[1]);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN3_Pin, SET);
			break;
		}
		case 2:{
			display_Led7seg(buffer_7seg[2]);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN0_Pin|EN3_Pin, SET);
			break;
		}
		case 3:{
			display_Led7seg(buffer_7seg[3]);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN0_Pin, SET);
			break;
		}
		default:{
			break;
		}
		}
}
