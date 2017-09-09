/*
 * TetrisElement_L.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#ifndef TETRISELEMENT_L_H_
#define TETRISELEMENT_L_H_

class TetrisElement_L : public Segment{
public:
	TetrisElement_L();
	void rotate_Right();
	void rotate_Left();
};

#endif /* TETRISELEMENT_L_H_ */
