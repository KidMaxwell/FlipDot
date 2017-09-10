/*
 * TetrisElement_Stair.cpp
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement_Stair.h"

TetrisElement_Stair::TetrisElement_Stair() :
		TetrisElement(0, 7, 2, 3) {
	change(0, 0, true);
	change(1, 0, true);
	change(1, 1, true);
	change(2, 1, true);
}

void TetrisElement_Stair::rotate_Right(int amount) {

}

void TetrisElement_Stair::rotate_Left(int amount) {

}
