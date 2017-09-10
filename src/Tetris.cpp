/*
 * Tetris.cpp
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "Tetris.h"

Tetris::Tetris(Screen* scr_p) :
		screen_p(scr_p) {
	elements_Array[0] = new TetrisElement_Block();
	elements_Array[1] = new TetrisElement_I();
	elements_Array[2] = new TetrisElement_L();
	elements_Array[3] = new TetrisElement_Stair();
	elements_Array[4] = new TetrisElement_T();
}

TetrisElement Tetris::createElement() {
	TetrisElement newElement = *(elements_Array[rand_min_max(0, 3)]);
	newElement.rotate_Right(rand_min_max(0, 3));
	return newElement;
}

int Tetris::rand_min_max(int min, int max) {
	srand((unsigned) time(NULL));
	return rand() % (max - min + 1) + min + 1;
}
