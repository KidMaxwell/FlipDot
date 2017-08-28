/*
 * Segment.h
 *
 *  Created on: 09.08.2017
 *      Author: paul, alex
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_
#include "Dot.h"
#include "HAL_Addr.h"
#include "Screen.h"
#include <vector>

class Segment {
public:
	Segment(Screen* scr_p, int col_start, int row_start, int col_max,
			int row_max);
	bool checkValues();
	void change(int, int, bool);
	void changeIfDifferent(Dot, bool);
	void changeRow(int, bool);
	void changeColumn(int, bool);
	void changeAll(bool);
protected:
	HAL_Addr *addr;
	const int seg_column_start, seg_row_start, seg_column_width, seg_row_hight;
	bool newState;
	std::vector< std::vector<Dot> > vec_dots;
	Screen *screen_p;
};

#endif /* SEGMENT_H_ */
