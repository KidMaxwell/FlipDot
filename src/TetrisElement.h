/*
 * TetrisElement.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "Segment.h"

#ifndef TETRISELEMENT_H_
#define TETRISELEMENT_H_

class TetrisElement : public Segment {
public:
	TetrisElement(int col_start, int row_start, int col_max,
			int row_max);
	void rotate_Right(int amount);
	void rotate_Left(int amount);
};

#endif /* TETRISELEMENT_H_ */
