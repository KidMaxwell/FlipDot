/*
 * Segment.h
 *
 *  Created on: 09.08.2017
 *      Author: paul, alex
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_
#include <vector>
#include "HAL_HardwareDefines.h"

class Segment {
public:
	Segment(int col_start, int row_start, int col_max,
			int row_max);
	struct koordinates{
		std::vector<int> row;
		std::vector<int> column;
	};
	void change(int seg_row, int seg_column, bool newState);
	void changeRow(int seg_row, bool newState);
	void changeColumn(int seg_column, bool newState);
	void changeAll(bool newState);
	void changeSegment(Segment* segment);
	//Getter
	int get_seg_row_start();
	int get_seg_row_hight();
	int get_seg_column_start();
	int get_seg_column_width();
	bool get_state(int seg_row, int seg_column);
	//Setter
	void set_seg_row_start(int row_start);
	void set_seg_row_hight(int row_hight);
	void set_seg_column_start(int column_start);
	void set_seg_column_width(int column_width);
protected:
	bool checkValues();
	int seg_column_start, seg_row_start, seg_column_width, seg_row_hight;
	bool newState;
// Test
public:
	std::vector< std::vector<bool> > vec_dots;
};

#endif /* SEGMENT_H_ */
