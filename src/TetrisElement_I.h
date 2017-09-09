/*
 * TetrisElement_I.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#ifndef TETRISELEMENT_I_H_
#define TETRISELEMENT_I_H_

class TetrisElement_I : public Segment{
public:
	TetrisElement_I();
	void rotate_Right();
	void rotate_Left();
};

#endif /* TETRISELEMENT_I_H_ */
