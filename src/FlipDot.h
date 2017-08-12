/*
 * FlipDot.h
 *
 *  Created on: 06.08.2017
 *      Author: paul, alex
 */

#ifndef FLIPDOT_H_
#define FLIPDOT_H_

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
//	Segment segments;
	Segment seg_complete;
	ShiftRegister SR;
	Dot screen[28][16];
};



#endif /* FLIPDOT_H_ */
