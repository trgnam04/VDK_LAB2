/*
 * lab2_ex7.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#include "lab2_ex7.h"

#define BUFFER_SIZE 4


static uint8_t buffer_7seg[BUFFER_SIZE] = {1, 2, 3, 4};
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
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
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

void updateClockBuffer(void){
	buffer_7seg[0] = min % 10;
	buffer_7seg[1] = min / 10;
	buffer_7seg[2] = hour % 10;
	buffer_7seg[3] = hour / 10;
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


void displayLEDMatrix(int num){
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, !(num & 0x01));
	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, !(num & 0x02));
	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, !(num & 0x04));
	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, !(num & 0x08));
	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, !(num & 0x10));
	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, !(num & 0x20));
	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, !(num & 0x40));
	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, !(num & 0x80));
}

void clearLEDMatrix(){
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, ROW1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, ROW2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, ROW3_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, ROW4_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, ROW5_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, ROW6_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, ROW7_Pin, SET);
}
