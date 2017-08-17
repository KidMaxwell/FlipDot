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

class Segment {
public:
	Segment();
	void init(int, int, int, int);
	void change(Screen* ,int, int, bool);
	void changeIfDifferent(Dot, bool);
	void changeRow(Screen*, int, bool);
	void changeColumn(Screen*, int, bool);
	void changeAll(Screen*, bool);
private:
	HAL_Addr addr;
	int seg_column_start, seg_row_start, seg_column_width, seg_row_hight;
	bool newState;
	// TODO !!! dynamisch modifizierbares Array
	Dot dots[28][16];
	static Screen screen;
};

#endif /* SEGMENT_H_ */
