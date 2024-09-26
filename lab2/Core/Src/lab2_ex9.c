/*
 * lab2_ex8.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#include "lab2_ex9.h"

#define MAX_LED_MATRIX 8

uint8_t matrix_buffer[8] = { 0x18, 0x3C, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66 }; //A

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
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
}

void updateLEDMatrix(int index){
	switch(index){
	case 0:{
		clearLEDMatrix();
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
		displayLEDMatrix(matrix_buffer[0]);
		break;
	}
	case 1:{
		clearLEDMatrix();
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
		displayLEDMatrix(matrix_buffer[1]);
		break;
	}
	case 2:{
		clearLEDMatrix();
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
		displayLEDMatrix(matrix_buffer[2]);
		break;
	}
	case 3:{
		clearLEDMatrix();
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
		displayLEDMatrix(matrix_buffer[3]);
		break;
	}
	case 4:{
		clearLEDMatrix();
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
		displayLEDMatrix(matrix_buffer[4]);
		break;
	}
	case 5:{
		clearLEDMatrix();
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
		displayLEDMatrix(matrix_buffer[5]);
		break;
	}
	case 6:{
		clearLEDMatrix();
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
		displayLEDMatrix(matrix_buffer[6]);
		break;
	}
	case 7:{
		clearLEDMatrix();
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
		displayLEDMatrix(matrix_buffer[7]);
		break;
	}
	default:{
		break;
	}
	}
}
