/*
 * TetrisElement_T.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement.h"

#ifndef TETRISELEMENT_T_H_
#define TETRISELEMENT_T_H_

class TetrisElement_T: public TetrisElement {
public:
	TetrisElement_T();
	void rotate_Right(int amount);
	void rotate_Left(int amount);
};

#endif /* TETRISELEMENT_T_H_ */
