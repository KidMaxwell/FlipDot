/*
 * DigitalWatch.h
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */
#include "Segment.h"
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
	Segment seg_hour1, seg_hour2, seg_min1, seg_min2;
	Segment seg_upperLine, seg_lowerLine;
	Segment seg_doubleDots;
	Segment seg_complete;
	int hour1, hour2, min1, min2;
	Screen* screen_p;
};

#endif /* DIGITALWATCH_H_ */
