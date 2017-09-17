/*
 * Digit_5x7.cpp
 *
 *  Created on: 17.09.2017
 *      Author: alexander
 */

#include "Digit_5x7.h"

using namespace std;

Digit_5x7::Digit_5x7(int col_start, int row_start) :
		Segment(col_start, row_start, 5, 7) {
}

void Digit_5x7::choseDigit(string digit) {
	changeAll(false);
	if(digit == "0"){
		show0();
	}
	else if (digit == "1") {
		show1();
	}
	else if (digit == "2") {
			show2();
		}
	else if (digit == "3") {
			show3();
		}
	else if (digit == "4") {
			show4();
		}
	else if (digit == "5") {
			show5();
		}
	else if (digit == "6") {
			show6();
		}
	else if (digit == "7") {
			show7();
		}
	else if (digit == "8") {
			show8();
		}
	else if (digit == "9") {
			show9();
		}
	else if (digit == ":") {
			showDoubleDots();
		}
	else{
		cout << "Fehler: nicht darstellbares Zeichen eingegeben" << endl;
	}
}

void Digit_5x7::show0() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit_5x7::show1() {
	changeColumn(2, true);
}

void Digit_5x7::show2() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 3, true);
	change(3, 2, true);
	change(4, 1, true);
	change(5, 0, true);
	changeRow(6, true);
}

void Digit_5x7::show3() {
	change(0, 0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 4, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit_5x7::show4() {
	change(0, 0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 2, true);
	changeRow(4, true);
	change(5, 2, true);
	change(6, 2, true);
}

void Digit_5x7::show5() {
	changeRow(0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit_5x7::show6() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit_5x7::show7() {
	change(0, 0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 3, true);
	change(2, 3, true);
	change(3, 2, true);
	change(3, 3, true);
	change(3, 4, true);
	change(4, 3, true);
	change(5, 3, true);
	change(6, 3, true);
}

void Digit_5x7::show8() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit_5x7::show9() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(3, 4, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit_5x7::showDoubleDots(){
	change(0, 0, true);
	change(0, 1, true);
	change(1, 0, true);
	change(1, 1, true);
	change(3, 0, true);
	change(3, 1, true);
	change(4, 0, true);
	change(4, 1, true);
}
