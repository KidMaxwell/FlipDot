/*
 * Segment.h
 *
 *  Created on: 09.08.2017
 *      Author: paul, alex
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_
#include <vector>
#include <iostream>
#include "HAL_HardwareDefines.h"

class Segment {
public:
	Segment(int col_start, int row_start, int col_max,
			int row_max);
	void change(int seg_row, int seg_column, bool newState);
	void changeRow(int seg_row, bool newState);
	void changeColumn(int seg_column, bool newState);
	void changeAll(bool newState);
	//Getter
	int get_seg_row_start();
	int get_seg_row_hight();
	int get_seg_column_start();
	int get_seg_column_width();
	bool get_state(int seg_row, int seg_column);
protected:
	bool checkValues();
	const int seg_column_start, seg_row_start, seg_column_width, seg_row_hight;
	bool newState;
	std::vector< std::vector<bool> > vec_dots;
};

#endif /* SEGMENT_H_ */
