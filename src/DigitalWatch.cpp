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

DigitalWatch::DigitalWatch(Screen* scr_p) :
		screen_p(scr_p),
		seg_complete(new ClockSegment(screen_p, 0, 0, COL_MAX, ROW_MAX)),
		seg_upperLine(new ClockSegment(screen_p, 0, 13, COL_MAX, 1)),
		seg_lowerLine(new ClockSegment(screen_p, 0, 1, COL_MAX, 1)),
		seg_doubleDots(new ClockSegment(screen_p, 12, 5, 2, 5)),
		seg_hour1(new ClockSegment(screen_p, 1, 4, 5, 7)),
		seg_hour2(new ClockSegment(screen_p, 7, 4, 5, 7)),
		seg_min1(new ClockSegment(screen_p, 16, 4, 5, 7)),
		seg_min2(new ClockSegment(screen_p, 22, 4, 5, 7))
		{
//	seg_complete = new ClockSegment(screen_p, 0, 0, COL_MAX, ROW_MAX);
//	seg_complete->changeAll(false);
	// Obere Linie init.
//	seg_upperLine = ClockSegment(screen_p, 0, 15, COL_MAX, 1);
//	seg_upperLine->changeAll(true);
	// Untere Linie init;
//	seg_lowerLine = ClockSegment(screen_p, 0, 1, COL_MAX, 1);
//	seg_lowerLine->changeAll(true);
	// Doppelpunkte init.
//	seg_doubleDots = ClockSegment(screen_p, 12, 5, 2, 5);
	seg_doubleDots->change(5, 12, true);
	seg_doubleDots->change(5, 13, true);
	seg_doubleDots->change(6, 12, true);
	seg_doubleDots->change(6, 13, true);
	seg_doubleDots->change(8, 12, true);
	seg_doubleDots->change(8, 13, true);
	seg_doubleDots->change(9, 12, true);
	seg_doubleDots->change(9, 13, true);
	// Ziffern komplett gelb zeigen
//	seg_hour1 = ClockSegment(screen_p, 1, 4, 5, 7);
//	seg_hour1->changeAll(true);
//	seg_hour2 = ClockSegment(screen_p, 7, 4, 5, 7);
//	seg_hour2->changeAll(true);
//	seg_min1 = ClockSegment(screen_p, 16, 4, 5, 7);
//	seg_min1->changeAll(true);
//	seg_min2 = ClockSegment(screen_p, 22, 4, 5, 7);
//	seg_min2->changeAll(true);
	screen_p->showScreen();
}

void DigitalWatch::runClock() {
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
		// Darstellen der Ziffern
		seg_hour1->choseNumber(hour1);
		seg_hour2->choseNumber(hour2);
		seg_min1->choseNumber(min1);
		seg_min2->choseNumber(min2);
		// Anzeigen auf Screen
		screen_p->showScreen();
	}
}
