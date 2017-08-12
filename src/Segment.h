/*
 * Segment.h
 *
 *  Created on: 09.08.2017
 *      Author: paul, alex
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_
//Warum brauche ich das??? -> Anders geht es irgendwie nicht..
#include "FlipDot.h"

class Segment {
public:
	Segment();
	void init(FlipDot*, int, int, int, int);
	int getR_start();
	int getC_start();
	int getHight();
	int getWidth();
	void change(int, int, bool);
	void changeIfDifferent(Dot, bool);
	void changeRow(int, bool);
	void changeCollum(int, bool);
	void changeAll(bool);
	// TODO Wie implementiere ich hier ein modifizierbares Array?
	Dot dots[28][16];
private:
	FlipDot f;
	int c_start, r_start, width, hight;
	bool newState;
};

#endif /* SEGMENT_H_ */
