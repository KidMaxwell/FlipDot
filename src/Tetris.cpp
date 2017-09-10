/*
 * Tetris.cpp
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "Tetris.h"

Tetris::Tetris(Screen* scr_p) :
		screen_p(scr_p), newElement_p(0), buttons(new HAL_Button()) {
	elements_Array[0] = new TetrisElement_Block();
	elements_Array[1] = new TetrisElement_I();
	elements_Array[2] = new TetrisElement_L();
	elements_Array[3] = new TetrisElement_Stair();
	elements_Array[4] = new TetrisElement_T();
}

void Tetris::runTetris(int speed) {
	this->speed = speed;
	while (1) {
		newElement = createElement();
		// Implementiert auch das Warten
		buttons->readButton(speed);
	}
}

TetrisElement Tetris::createElement() {
	TetrisElement newElement = *(elements_Array[rand_min_max(0, 3)]);
	newElement.rotate_Right(rand_min_max(0, 3));
	return newElement;
}

void Tetris::move_Down(TetrisElement* newElement) {
	int newColumn_start = (newElement->get_seg_row_start());
	newColumn_start++;
	newElement->set_seg_column_start(newColumn_start);
}

void Tetris::move_Right(TetrisElement* newElement) {
	if (newElement->get_seg_row_start() > ROW_MIN) {
		int newRow_start = newElement->get_seg_row_start();
		newRow_start--;
		newElement->set_seg_row_start(newRow_start);
	}
}
void Tetris::move_Left(TetrisElement* newElement) {
	if ((newElement->get_seg_row_start() + newElement->get_seg_row_hight())
			< (ROW_MAX - 1)) {
		int newRow_start = newElement->get_seg_row_start();
		newRow_start++;
		newElement->set_seg_row_start(newRow_start);
	}
}

int Tetris::rand_min_max(int min, int max) {
	srand((unsigned) time(NULL));
	return rand() % (max - min + 1) + min + 1;
}
