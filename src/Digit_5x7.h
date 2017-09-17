/*
 * Digit_5x7.h
 *
 *  Created on: 17.09.2017
 *      Author: alexander
 */

#include <iostream>
#include <string>
#include "Segment.h"
#include "Screen.h"

#ifndef DIGIT_5X7_H_
#define DIGIT_5X7_H_

class Digit_5x7: public Segment {
public:
	Digit_5x7(int col_start, int row_start);
	void choseDigit(std::string digit);
private:
	void show0();
	void show1();
	void show2();
	void show3();
	void show4();
	void show5();
	void show6();
	void show7();
	void show8();
	void show9();
	void showDoubleDots();
};

#endif /* DIGIT_5X7_H_ */
