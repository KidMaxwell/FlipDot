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

#ifndef TETRIS_H_
#define TETRIS_H_

class Tetris {
public:
	Tetris(Screen* scr_p);
	TetrisElement createElement();
	int rand_min_max(int min, int max);
private:
	Screen* screen_p;
	TetrisElement* elements_Array[5];
	TetrisElement* newElement;

};

#endif /* TETRIS_H_ */
