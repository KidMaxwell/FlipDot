/*
 * TetrisElement.h
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include <iostream>
#include <string>
#include <vector>
#include "Segment.h"

#ifndef TETRISELEMENT_H_
#define TETRISELEMENT_H_

class TetrisElement : public Segment {
public:
	TetrisElement(std::string type, int seg_size);
	Segment* move_Down(int move_amount);
	Segment* move_Right(int move_amount);
	Segment* move_Left(int move_amount);
	void rotate(int amount);
	Segment::koordinates get_lowestDot();
private:
	int element_size;
};

#endif /* TETRISELEMENT_H_ */
