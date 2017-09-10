/*
 * TetrisElement_L.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement.h"

#ifndef TETRISELEMENT_L_H_
#define TETRISELEMENT_L_H_

class TetrisElement_L: public TetrisElement {
public:
	TetrisElement_L();
	void rotate_Right(int amount);
	void rotate_Left(int amount);
};

#endif /* TETRISELEMENT_L_H_ */
