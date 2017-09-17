/*
 * DigitalWatch.h
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */

#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <unistd.h>
#include "Screen.h"
#include "Digit_5x7.h"

#ifndef DIGITALWATCH_H_
#define DIGITALWATCH_H_

class DigitalWatch {
public:
	DigitalWatch(Screen* src_p);
	void runClock();
private:
	Screen *screen_p;
	Segment *seg_upperLine, *seg_lowerLine;
	Digit_5x7 *seg_doubleDots;
	Digit_5x7 *seg_hour1, *seg_hour2, *seg_min1, *seg_min2;
};

#endif /* DIGITALWATCH_H_ */
