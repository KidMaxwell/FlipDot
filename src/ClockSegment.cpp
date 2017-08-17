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

ClockSegment::ClockSegment() {
	// Evtl. eine Art super-Aufruf im Konstruktor
}

void ClockSegment::choseNumber(Screen* screen_p, int number) {
	switch (number) {
	case (0):
		show0(screen_p);
		break;
	case (1):
		show1(screen_p);
		break;
	case (2):
		show2(screen_p);
		break;
	case (3):
		show3(screen_p);
		break;
	case (4):
		show4(screen_p);
		break;
	case (5):
		show5(screen_p);
		break;
	case (6):
		show6(screen_p);
		break;
	case (7):
		show7(screen_p);
		break;
	case (8):
		show8(screen_p);
		break;
	case (9):
		show9(screen_p);
		break;
	}
}

void ClockSegment::show0(Screen* screen_p) {
	change(screen_p, 0, 1, true);
	change(screen_p, 0, 2, true);
	change(screen_p, 0, 3, true);
	change(screen_p, 1, 0, true);
	change(screen_p, 1, 4, true);
	change(screen_p, 2, 0, true);
	change(screen_p, 2, 4, true);
	change(screen_p, 3, 0, true);
	change(screen_p, 3, 4, true);
	change(screen_p, 4, 0, true);
	change(screen_p, 4, 4, true);
	change(screen_p, 5, 0, true);
	change(screen_p, 5, 4, true);
	change(screen_p, 6, 1, true);
	change(screen_p, 6, 2, true);
	change(screen_p, 6, 3, true);
}

void ClockSegment::show1(Screen* screen_p) {
	changeColumn(screen_p, 2, true);
}

void ClockSegment::show2(Screen* screen_p) {
	change(screen_p, 0, 1, true);
	change(screen_p, 0, 2, true);
	change(screen_p, 0, 3, true);
	change(screen_p, 1, 0, true);
	change(screen_p, 1, 4, true);
	change(screen_p, 2, 3, true);
	change(screen_p, 3, 2, true);
	change(screen_p, 4, 1, true);
	change(screen_p, 1, 4, true);
	changeRow(screen_p, 6, true);
}

void ClockSegment::show3(Screen* screen_p) {
	change(screen_p, 0, 0, true);
	change(screen_p, 0, 1, true);
	change(screen_p, 0, 2, true);
	change(screen_p, 0, 3, true);
	change(screen_p, 1, 4, true);
	change(screen_p, 2, 4, true);
	change(screen_p, 3, 1, true);
	change(screen_p, 3, 2, true);
	change(screen_p, 3, 3, true);
	change(screen_p, 4, 4, true);
	change(screen_p, 5, 4, true);
	change(screen_p, 6, 0, true);
	change(screen_p, 6, 1, true);
	change(screen_p, 6, 2, true);
	change(screen_p, 6, 3, true);
}

void ClockSegment::show4(Screen* screen_p) {
	change(screen_p, 0, 0, true);
	change(screen_p, 1, 0, true);
	change(screen_p, 2, 0, true);
	change(screen_p, 3, 0, true);
	change(screen_p, 3, 2, true);
	changeRow(screen_p, 4, true);
	change(screen_p, 5, 2, true);
	change(screen_p, 6, 2, true);
}

void ClockSegment::show5(Screen* screen_p) {
	changeRow(screen_p, 0, true);
	change(screen_p, 1, 0, true);
	change(screen_p, 2, 0, true);
	change(screen_p, 3, 0, true);
	change(screen_p, 3, 1, true);
	change(screen_p, 3, 2, true);
	change(screen_p, 3, 3, true);
	change(screen_p, 3, 4, true);
	change(screen_p, 4, 5, true);
	change(screen_p, 5, 5, true);
	change(screen_p, 6, 0, true);
	change(screen_p, 6, 1, true);
	change(screen_p, 6, 2, true);
	change(screen_p, 6, 3, true);
}

void ClockSegment::show6(Screen* screen_p) {
	change(screen_p, 0, 0, true);
	change(screen_p, 0, 1, true);
	change(screen_p, 0, 2, true);
	change(screen_p, 0, 3, true);
	change(screen_p, 1, 0, true);
	change(screen_p, 2, 0, true);
	change(screen_p, 3, 0, true);
	change(screen_p, 3, 1, true);
	change(screen_p, 3, 2, true);
	change(screen_p, 3, 3, true);
	change(screen_p, 4, 0, true);
	change(screen_p, 4, 4, true);
	change(screen_p, 5, 0, true);
	change(screen_p, 5, 4, true);
	change(screen_p, 6, 1, true);
	change(screen_p, 6, 2, true);
	change(screen_p, 6, 3, true);
}

void ClockSegment::show7(Screen* screen_p) {
	change(screen_p, 0, 0, true);
	change(screen_p, 0, 1, true);
	change(screen_p, 0, 2, true);
	change(screen_p, 0, 3, true);
	change(screen_p, 1, 3, true);
	change(screen_p, 2, 3, true);
	change(screen_p, 3, 3, true);
	change(screen_p, 4, 2, true);
	change(screen_p, 4, 3, true);
	change(screen_p, 4, 4, true);
	change(screen_p, 5, 3, true);
	change(screen_p, 6, 3, true);
	change(screen_p, 7, 3, true);
}

void ClockSegment::show8(Screen* screen_p) {
	change(screen_p, 0, 1, true);
	change(screen_p, 0, 2, true);
	change(screen_p, 0, 3, true);
	change(screen_p, 1, 0, true);
	change(screen_p, 1, 4, true);
	change(screen_p, 2, 0, true);
	change(screen_p, 2, 4, true);
	change(screen_p, 3, 1, true);
	change(screen_p, 3, 2, true);
	change(screen_p, 3, 3, true);
	change(screen_p, 4, 0, true);
	change(screen_p, 4, 4, true);
	change(screen_p, 5, 0, true);
	change(screen_p, 5, 4, true);
	change(screen_p, 6, 1, true);
	change(screen_p, 6, 2, true);
	change(screen_p, 6, 3, true);
}

void ClockSegment::show9(Screen* screen_p) {
	change(screen_p, 0, 1, true);
	change(screen_p, 0, 2, true);
	change(screen_p, 0, 3, true);
	change(screen_p, 1, 0, true);
	change(screen_p, 1, 4, true);
	change(screen_p, 2, 0, true);
	change(screen_p, 2, 4, true);
	change(screen_p, 3, 1, true);
	change(screen_p, 3, 2, true);
	change(screen_p, 3, 3, true);
	change(screen_p, 4, 4, true);
	change(screen_p, 5, 4, true);
	change(screen_p, 6, 1, true);
	change(screen_p, 6, 2, true);
	change(screen_p, 6, 3, true);
}
