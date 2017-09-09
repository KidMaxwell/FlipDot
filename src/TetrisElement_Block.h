/*
 * TetrisElement_Block.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#ifndef TETRISELEMENT_BLOCK_H_
#define TETRISELEMENT_BLOCK_H_

class TetrisElement_Block : public Segment {
public:
	TetrisElement_Block();
	void rotate_Right();
	void rotate_Left();
};

#endif /* TETRISELEMENT_BLOCK_H_ */
