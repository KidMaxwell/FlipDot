/*
 * DigitalWatch.h
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */
#include "ClockSegment.h"
#include "Screen.h"
#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>


#ifndef DIGITALWATCH_H_
#define DIGITALWATCH_H_

class DigitalWatch {
public:
	DigitalWatch(Screen* src_p);
	void runClock();
private:
	Screen *screen_p;
	Segment *seg_upperLine, *seg_lowerLine;
	Segment *seg_doubleDots;
	ClockSegment *seg_hour1, *seg_hour2, *seg_min1, *seg_min2;
};

#endif /* DIGITALWATCH_H_ */
