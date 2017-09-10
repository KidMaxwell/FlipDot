/*
 * Tetris.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "TetrisElement.h"
#include "HAL_HardwareDefines.h"
#include "TetrisDefines.h"
#include "HAL_Button.h"

#ifndef TETRIS_H_
#define TETRIS_H_

class Tetris {
public:
	Tetris(Screen* scr_p);
	void runTetris(int speed);
	void move_Down(TetrisElement* newElement, int move_amount);
	void move_Right(TetrisElement* newElement, int move_amount);
	void move_Left(TetrisElement* newElement, int move_amount);
	int countButtonHits();
	TetrisElement createElement();
	int rand_min_max(int min, int max);
private:
	Screen* screen_p;
	TetrisElement* elements_Array[5];
	TetrisElement* newElement_p;
	HAL_Button* buttons;
	HAL_Button::buttonHits_Tetris button_hits;
	unsigned int speed;

};

#endif /* TETRIS_H_ */
