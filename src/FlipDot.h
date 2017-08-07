/*
 * FlipDot.h
 *
 *  Created on: 06.08.2017
 *      Author: paul
 */

#ifndef FLIPDOT_H_
#define FLIPDOT_H_


namespace FlipDot {

	void Init();
	void start();
	void changeIfDifferent(Dot, bool);
	void changeAll(bool);
	void change(int, int, bool);
	void loadSR(int, int, bool);
	void enable();

	Dot dots[16][28];
	ShiftRegister SR;
	int row, column, newStateI;
	bool newState;

}



#endif /* FLIPDOT_H_ */
