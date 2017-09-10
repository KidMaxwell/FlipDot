/*
 * TetrisElement_I.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement.h"

#ifndef TETRISELEMENT_I_H_
#define TETRISELEMENT_I_H_

class TetrisElement_I: public TetrisElement {
public:
	TetrisElement_I();
	void rotate_Right(int amount);
	void rotate_Left(int amount);
};

#endif /* TETRISELEMENT_I_H_ */
