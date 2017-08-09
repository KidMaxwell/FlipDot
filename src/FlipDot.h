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
	void start();
	void consoleMenu();
	void modeChange();
	void modeChangeAll();
	void showScreen();
	void change(int, int, bool);
	void changeIfDifferent(Dot, bool);
	void changeRow(int, bool);
	void changeCollum(int, bool);
	void changeAll(bool);
	void loadSR(int, int, bool);
	void enable();
private:
	Dot dots[16][28];
	ShiftRegister SR;
	int row, column, newStateI;
	bool newState;

};



#endif /* FLIPDOT_H_ */
