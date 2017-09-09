/*
 * TetrisElement_Stair.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#ifndef TETRISELEMENT_STAIR_H_
#define TETRISELEMENT_STAIR_H_

class TetrisElement_Stair : public Segment{
public:
	TetrisElement_Stair();
	void rotate_Right();
	void rotate_Left();
};

#endif /* TETRISELEMENT_STAIR_H_ */
