/*
 * TetrisElement_T.cpp
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement_T.h"

TetrisElement_T::TetrisElement_T() :
// TODO Segment deklarieren
		TetrisElement(0, 7, 3, 3) {
	changeColumn(1, true);
	changeRow(1, true);
}

void TetrisElement_T::rotate_Right(int amount) {

}

void TetrisElement_T::rotate_Left(int amount) {

}
