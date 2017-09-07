/*
 * ClockSegment.cpp
 *
 *  Created on: 17.08.2017
 *      Author: alexander
 */

/*
 * Sub-Klasse von Segment
 * 	Implementiert die Methoden zum Anzeigen der Ziffern
 */
#include "ClockSegment.h"
#include <iostream>

ClockSegment::ClockSegment(Screen* scr_p, int col_start, int row_start,
		int col_max, int row_max):
		Segment(scr_p, col_start, row_start, col_max, row_max)
		{}

void ClockSegment::choseNumber(int number) {
	changeAll(false);
	switch (number) {
	case (0):
		show0();
		break;
	case (1):
		show1();
		break;
	case (2):
		show2();
		break;
	case (3):
		show3();
		break;
	case (4):
		show4();
		break;
	case (5):
		show5();
		break;
	case (6):
		show6();
		break;
	case (7):
		show7();
		break;
	case (8):
		show8();
		break;
	case (9):
		show9();
		break;
	}
}

void ClockSegment::show0() {
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
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show1() {
	changeColumn(2, true);
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show2() {
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
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show3() {
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
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show4() {
	change(0, 0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 2, true);
	changeRow(4, true);
	change(5, 2, true);
	change(6, 2, true);
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show5() {
	changeRow(0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(3, 4, true);
	change(4, 5, true);
	change(5, 5, true);
	change(6, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show6() {
	change(0, 0, true);
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
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show7() {
	change(0, 0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 3, true);
	change(2, 3, true);
	change(3, 3, true);
	change(4, 2, true);
	change(4, 3, true);
	change(4, 4, true);
	change(5, 3, true);
	change(6, 3, true);
	change(7, 3, true);
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show8() {
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
	screen_p->updateScreen_Segment(*this);
}

void ClockSegment::show9() {
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
	change(4, 4, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
	screen_p->updateScreen_Segment(*this);
}