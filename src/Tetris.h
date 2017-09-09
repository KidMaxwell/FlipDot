/*
 * Tetris.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include <iostream>
#include "Screen.h"
#include "Random.h"
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
	Segment* createElement();
private:
	Screen* screen_p;
	Segment* elements_Array[5];

};

#endif /* TETRIS_H_ */
