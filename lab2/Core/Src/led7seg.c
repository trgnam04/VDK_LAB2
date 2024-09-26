/*
 * led7seg.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */
#include "led7seg.h"


void Display_leg7seg(uint8_t counter){
	//led display number 0 by enable 6 ports as follow (reset state)
		if (counter == 0) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
		}
		//led display number 1 by enable 2 ports as follow (reset state)
		if (counter == 1) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin, RESET);
		}
		//led display number 2 by enable 5 ports as follow (reset state)
		if (counter == 2) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin|SEG5_Pin, SET);
		}
		//led display number 3 by enable 5 ports as follow (reset state)
		if (counter == 3) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin|SEG3_Pin, RESET);
		}
		//led display number 4 by enable 4 ports as follow (reset state)
		if (counter == 4) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin|SEG5_Pin|SEG6_Pin, RESET);
		}
		//led display number 5 by enable 5 ports as follow (reset state)
		if (counter == 5) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG4_Pin, SET);
		}
		//led display number 6 by enable 6 ports as follow (reset state)
		if (counter == 6) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
		}
		//led display number 7 by enable 3 ports as follow (reset state)
		if (counter == 7) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, SET);
		}
		//led display number 8 by enable 7 ports as follow (reset state)
		if (counter == 8) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, RESET);
		}
		//led display number 9 by enable 6 ports as follow (reset state)
		if (counter == 9) {
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
		}
}
