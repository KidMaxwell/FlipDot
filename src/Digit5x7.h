/*
 * Digit5x7.h
 *
 *  Created on: 08.10.2017
 *      Author: paul
 */

#ifndef DIGIT5X7_H_
#define DIGIT5X7_H_

#include <iostream>
#include <string>
#include "Segment.h"

class Digit5x7 : public Segment{
public:
	Digit5x7(int col_start, int row_start);
	void chooseDigit(std::string digit);
private:
	void showa();
	void showA();
	void showb();
	void showB();
	void showc();
	void showC();
	void showd();
	void showD();
	void showe();
	void showE();
	void showf();
	void showF();
	void showg();
	void showG();
	void showh();
	void showH();
	void showi();
	void showI();
	void showj();
	void showJ();
	void showk();
	void showK();
	void showl();
	void showL();
	void showm();
	void showM();
	void shown();
	void showN();
	void showo();
	void showO();
	void showp();
	void showP();
	void showq();
	void showQ();
	void showr();
	void showR();
	void shows();
	void showS();
	void showt();
	void showT();
	void showu();
	void showU();
	void showv();
	void showV();
	void showw();
	void showW();
	void showx();
	void showX();
	void showy();
	void showY();
	void showz();
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
	void showDoubleDots();
	void showQM();
	void showFS();
	void showComma();
	void showEM();
	void showDP();
	void showSemCol();
	void showError();
	void showPi();
};

#endif /* DIGIT5X7_H_ */
