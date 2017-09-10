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
#include "TetrisElement_Block.h"
#include "TetrisElement_I.h"
#include "TetrisElement_L.h"
#include "TetrisElement_Stair.h"
#include "TetrisElement_T.h"
#include "HAL_HardwareDefines.h"
#include "TetrisDefines.h"
#include "HAL_Button.h"

#ifndef TETRIS_H_
#define TETRIS_H_

class Tetris {
public:
	Tetris(Screen* scr_p);
	void runTetris(int speed);
	void move_Down(TetrisElement* newElement);
	void move_Right(TetrisElement* newElement);
	void move_Left(TetrisElement* newElement);
	int countButtonHits();
	TetrisElement createElement();
	int rand_min_max(int min, int max);
private:
	Screen* screen_p;
	TetrisElement* elements_Array[5];
	TetrisElement newElement;
	TetrisElement* newElement_p;
	HAL_Button* buttons;
	int speed;

};

#endif /* TETRIS_H_ */
