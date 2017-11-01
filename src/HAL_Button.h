/*
 * HAL_Button.h
 *
 *  Created on: 10.09.2017
 *      Author: alexander
 */
#include <iostream>
#include <wiringPi.h>
#include "HAL_HardwareDefines.h"
#include "TetrisDefines.h"

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
};

#endif /* HAL_BUTTON_H_ */
