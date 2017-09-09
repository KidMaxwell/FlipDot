/*
 * TetrisElement_T.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#ifndef TETRISELEMENT_T_H_
#define TETRISELEMENT_T_H_

class TetrisElement_T : public Segment{
public:
	TetrisElement_T();
	void rotate_Right();
	void rotate_Left();
};

#endif /* TETRISELEMENT_T_H_ */
