/*
 * DigitalWatch.h
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */
#include "ClockSegment.h"
#include "Screen.h"

#ifndef DIGITALWATCH_H_
#define DIGITALWATCH_H_

class DigitalWatch {
public:
	DigitalWatch(Screen* src_p);
	void runClock();
private:
	Screen *screen_p;
	ClockSegment *seg_complete;
	ClockSegment *seg_upperLine, *seg_lowerLine;
	ClockSegment *seg_doubleDots;
	ClockSegment *seg_hour1, *seg_hour2, *seg_min1, *seg_min2;
};

#endif /* DIGITALWATCH_H_ */
