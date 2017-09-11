/*
 * Tetris.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Screen.h"
#include "TetrisElement.h"
#include "HAL_Button.h"

#ifndef TETRIS_H_
#define TETRIS_H_

class Tetris {
public:
	Tetris(Screen* scr_p);
	void menuTetris();
	void runTetris();
private:
	void moveElement();
	void moveElement_Direction(std::string direction, int amount);
	TetrisElement createElement();
	bool check_hitBuilt();
	int rand_min_max(int min, int max);
	Screen* screen_p;
	Segment* seg_built;
	TetrisElement* elements_Array[5];
	TetrisElement* newElement_p;
	HAL_Button* buttons;
	HAL_Button::buttonHits_Tetris button_hits;
	unsigned int speed, highscore;

};

#endif /* TETRIS_H_ */
