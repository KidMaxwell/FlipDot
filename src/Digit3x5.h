/*
 * Digit3x5.h
 *
 *  Created on: 09.09.2017
 *      Author: paul, alex
 */

#include "Segment.h"
#include <string>
#include <iostream>

using namespace std;

#ifndef DIGIT3X5_H_
#define DIGIT3X5_H_

class Digit3x5: public Segment {
public:
	Digit3x5(int col_start, int row_start);
	void chooseDigit(string digit);
//private:
	void showA();
	void showB();
	void showC();
	void showD();
	void showE();
	void showF();
	void showG();
	void showH();
	void showI();
	void showJ();
	void showK();
	void showL();
	void showM();
	void showN();
	void showO();
	void showP();
	void showQ();
	void showR();
	void showS();
	void showT();
	void showU();
	void showV();
	void showW();
	void showX();
	void showY();
	void showZ();
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
	void showQM();
	void showFS();
	void showEM();
	void showError();
};



#endif /* DIGIT3X5_H_ */
