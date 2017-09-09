/*
 * Tetris.cpp
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "Tetris.h"

Tetris::Tetris(Screen* scr_p) :
		screen_p(scr_p) {
	elements_Array = { new TetrisElement_Block(), new TetrisElement_I(),
			new TetrisElement_L(), new TetrisElement_Stair(),
			new TetrisElement_T() };
}

Segment* Tetris::createElement(){

}


