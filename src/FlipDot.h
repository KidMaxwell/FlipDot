/*
 * FlipDot.h
 *
 *  Created on: 06.08.2017
 *      Author: paul, alex
 */

#ifndef FLIPDOT_H_
#define FLIPDOT_H_
#include "Segment.h"
#include "Dot.h"
#include "DigitalWatch.h"
#include "SnakeSingle.h"
#include "Screen.h"
#include "HAL_HardwareDefines.h"
#include <iostream>
#include <string>

class FlipDot {
public:
	FlipDot();
	void consoleMenu();
	void modeChange();
	void modeChangeAll();
	void updateScreen();
	void showScreen();
	void loadSR(int, int, bool);
	void enable(bool);
private:
	Segment *seg_FlipDotDisplay;
	Screen *screen_p;
};

#endif /* FLIPDOT_H_ */
