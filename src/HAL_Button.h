/*
 * HAL_Button.h
 *
 *  Created on: 10.09.2017
 *      Author: alexander
 */
#include <iostream>
#include <wiringPi.h>
#include "HAL_HardwareDefines.h"

#ifndef HAL_BUTTON_H_
#define HAL_BUTTON_H_

class HAL_Button {
public:
	HAL_Button();
	struct buttonHits_Tetris {
		int b_right;
		int b_left;
		int b_rotate;
		int b_movedown;
	};
	buttonHits_Tetris readButton(int speed);
	int readButtonLast();
private:
	HAL_Button::buttonHits_Tetris button_hits;
	int input_Array[4];
	int prev_input_Array[4];
	bool lastRight;
	bool lastLeft;
	bool lastTop;
	bool lastDown;
};

#endif /* HAL_BUTTON_H_ */
