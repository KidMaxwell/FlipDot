/*
 * TetrisElement_L.cpp
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement_L.h"

TetrisElement_L::TetrisElement_L() :
		TetrisElement(0, 7, 3, 2) {
	changeRow(1, true);
	change(0, 2, true);
}

void TetrisElement_L::rotate_Right(int amount) {

}

void TetrisElement_L::rotate_Left(int amount) {

}
