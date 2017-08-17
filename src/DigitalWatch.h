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
	DigitalWatch();
	void runClock(Screen*);
	void init();
	void initDisplay();
private:
	ClockSegment seg_hour1, seg_hour2, seg_min1, seg_min2;
	ClockSegment seg_upperLine, seg_lowerLine;
	ClockSegment seg_doubleDots;
	ClockSegment seg_complete;
	int hour1, hour2, min1, min2;
	Screen* screen_p;
};

#endif /* DIGITALWATCH_H_ */
