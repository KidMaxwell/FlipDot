/*
 * FlipDot.h
 *
 *  Created on: 06.08.2017
 *      Author: paul, alex
 */

#ifndef FLIPDOT_H_
#define FLIPDOT_H_
#include <iostream>
#include <string>
#include "Dot.h"
#include "DigitalWatch.h"
//#include "SnakeSingle.h"
#include "Tetris.h"
#include "Screen.h"

class FlipDot {
public:
	FlipDot();
	void consoleMenu();
	void modeChange();
	void modeChangeAll();
private:
	Screen *screen_p;
};

#endif /* FLIPDOT_H_ */
