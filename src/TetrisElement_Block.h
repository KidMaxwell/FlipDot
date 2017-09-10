/*
 * TetrisElement_Block.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement.h"

#ifndef TETRISELEMENT_BLOCK_H_
#define TETRISELEMENT_BLOCK_H_

class TetrisElement_Block : public TetrisElement {
public:
	TetrisElement_Block();
	void rotate_Right(int amount);
	void rotate_Left(int amount);
};

#endif /* TETRISELEMENT_BLOCK_H_ */
