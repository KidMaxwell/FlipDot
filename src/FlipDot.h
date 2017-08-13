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
#include "Screen.h"

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
	// TODO Fuer allg. Nutzung als Liste! Hier nur POC
	Segment seg_complete;
	Screen screen;
	Screen* screen_p;
};

#endif /* FLIPDOT_H_ */
