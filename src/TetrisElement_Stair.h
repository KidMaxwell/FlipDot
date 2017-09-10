/*
 * TetrisElement_Stair.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement.h"

#ifndef TETRISELEMENT_STAIR_H_
#define TETRISELEMENT_STAIR_H_

class TetrisElement_Stair: public TetrisElement {
public:
	TetrisElement_Stair();
	void rotate_Right(int amount);
	void rotate_Left(int amount);
};

#endif /* TETRISELEMENT_STAIR_H_ */
