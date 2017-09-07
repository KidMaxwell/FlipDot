/*
 * ClockSegment.h
 *
 *  Created on: 17.08.2017
 *      Author: alexander, paul
 */
#include "Segment.h"
#include "Screen.h"

#ifndef CLOCKSEGMENT_H_
#define CLOCKSEGMENT_H_

class ClockSegment: public Segment {
public:
	ClockSegment(int col_start, int row_start, int col_max, int row_max);
	void choseNumber(int number);
	void show0();
	void show1();
	void show2();
	void show3();
	void show4();
	void show5();
	void show6();
	void show7();
	void show8();
	void show9();
};

#endif /* CLOCKSEGMENT_H_ */
