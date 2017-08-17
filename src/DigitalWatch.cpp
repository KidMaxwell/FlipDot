/*
 * DigitalWatch.cpp
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */

#include "DigitalWatch.h"
#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>

using namespace std;

DigitalWatch::DigitalWatch() {
	this->screen_p = 0;
	this->hour1 = 0;
	this->hour2 = 0;
	this->min1 = 0;
	this->min2 = 0;
}

void DigitalWatch::init() {
	seg_hour1.init(1, 4, 5, 7);
	seg_hour2.init(7, 4, 5, 7);
	seg_min1.init(16, 4, 5, 7);
	seg_min2.init(22, 4, 5, 7);
	seg_lowerLine.init(0, 1, COL_MAX, 1);
	seg_upperLine.init(0, 1, COL_MAX, 1);
	seg_doubleDots.init(12, 5, 2, 5);
	seg_complete.init(0, 0, COL_MAX, ROW_MAX);
}

void DigitalWatch::initDisplay() {
	seg_complete.changeAll(screen_p, false);
	// Obere Linie init.
	seg_upperLine.changeAll(screen_p, true);
	// Untere Linie init;
	seg_lowerLine.changeAll(screen_p, true);
	// Doppelpunkte init.
	seg_doubleDots.change(screen_p, 5, 12, true);
	seg_doubleDots.change(screen_p, 5, 13, true);
	seg_doubleDots.change(screen_p, 6, 12, true);
	seg_doubleDots.change(screen_p, 6, 13, true);
	seg_doubleDots.change(screen_p, 8, 12, true);
	seg_doubleDots.change(screen_p, 8, 13, true);
	seg_doubleDots.change(screen_p, 9, 12, true);
	seg_doubleDots.change(screen_p, 9, 13, true);
	// Ziffern komplett gelb zeigen
	seg_hour1.changeAll(screen_p, true);
	seg_hour2.changeAll(screen_p, true);
	seg_min1.changeAll(screen_p, true);
	seg_min2.changeAll(screen_p, true);
	screen_p->showScreen();
}

void DigitalWatch::runClock(Screen* screen_p) {
	this->screen_p = screen_p;
	init();
	initDisplay();
	time_t rawtime;
	struct tm* time_local;		// allg. Zeitstruct
	/*
	 * Zeit auslesen funktioniert!
	 * einzelne Segmente werden am falschen Ort falsch angezeigt
	 * -> liegt wahrscheinlich am noch nicht modifizierten Array
	 */
	while (1) {
		sleep(1);
		// Zeit holen und konvertieren
		time(&rawtime);
		time_local = localtime(&rawtime);
		// einzelne Ziffern extrahieren
		int hour1 = (time_local->tm_hour) / 10;
		int hour2 = (time_local->tm_hour) % 10;
		int min1 = (time_local->tm_min) / 10;
		int min2 = (time_local->tm_min) % 10;
		cout << "---Test---  Zeit: " << hour1 << hour2 << " : " << min1 << min2
				<< endl;
		/*
		 * Darstellen der Ziffern
		 * 		I know it's ugly...
		 */
		// erste Ziffer
		switch (hour1) {
		case (0):
			seg_hour1.show0(screen_p);
			break;
		case (1):
			seg_hour1.show1(screen_p);
			break;
		case (2):
			seg_hour1.show2(screen_p);
			break;
		case (3):
			seg_hour1.show3(screen_p);
			break;
		case (4):
			seg_hour1.show4(screen_p);
			break;
		case (5):
			seg_hour1.show5(screen_p);
			break;
		case (6):
			seg_hour1.show6(screen_p);
			break;
		case (7):
			seg_hour1.show7(screen_p);
			break;
		case (8):
			seg_hour1.show8(screen_p);
			break;
		case (9):
			seg_hour1.show9(screen_p);
			break;
		}

		// zweite Ziffer
		switch (hour2) {
		case (0):
			seg_hour2.show0(screen_p);
			break;
		case (1):
			seg_hour2.show1(screen_p);
			break;
		case (2):
			seg_hour2.show2(screen_p);
			break;
		case (3):
			seg_hour2.show3(screen_p);
			break;
		case (4):
			seg_hour2.show4(screen_p);
			break;
		case (5):
			seg_hour2.show5(screen_p);
			break;
		case (6):
			seg_hour2.show6(screen_p);
			break;
		case (7):
			seg_hour2.show7(screen_p);
			break;
		case (8):
			seg_hour2.show8(screen_p);
			break;
		case (9):
			seg_hour2.show9(screen_p);
			break;
		}

		// Dritte Ziffer
		switch (min1) {
		case (0):
			seg_min1.show0(screen_p);
			break;
		case (1):
			seg_min1.show1(screen_p);
			break;
		case (2):
			seg_min1.show2(screen_p);
			break;
		case (3):
			seg_min1.show3(screen_p);
			break;
		case (4):
			seg_min1.show4(screen_p);
			break;
		case (5):
			seg_min1.show5(screen_p);
			break;
		case (6):
			seg_min1.show6(screen_p);
			break;
		case (7):
			seg_min1.show7(screen_p);
			break;
		case (8):
			seg_min1.show8(screen_p);
			break;
		case (9):
			seg_min1.show9(screen_p);
			break;
		}

		// vierte Ziffer
		switch (min2) {
		case (0):
			seg_min2.show0(screen_p);
			break;
		case (1):
			seg_min2.show1(screen_p);
			break;
		case (2):
			seg_min2.show2(screen_p);
			break;
		case (3):
			seg_min2.show3(screen_p);
			break;
		case (4):
			seg_min2.show4(screen_p);
			break;
		case (5):
			seg_min2.show5(screen_p);
			break;
		case (6):
			seg_min2.show6(screen_p);
			break;
		case (7):
			seg_min2.show7(screen_p);
			break;
		case (8):
			seg_min2.show8(screen_p);
			break;
		case (9):
			seg_min2.show9(screen_p);
			break;
		}
		screen_p->showScreen();
	}
}
