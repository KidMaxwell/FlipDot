/*
 * DigitalWatch.cpp
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */

#include "DigitalWatch.h"

using namespace std;

DigitalWatch::DigitalWatch(Screen* scr_p) :
		screen_p(scr_p), seg_upperLine(new Segment(0, 1, COL_MAX, 1)), seg_lowerLine(
				new Segment(0, 13, COL_MAX, 1)), seg_doubleDots(
				new Digit_5x7(13, 5)), seg_hour1(new Digit_5x7(1, 4)), seg_hour2(
				new Digit_5x7(7, 4)), seg_min1(new Digit_5x7(16, 4)), seg_min2(
				new Digit_5x7(22, 4)) {
	// Display schwärzen
	screen_p->updateScreen_All(false);
	// Obere Linie init.
	seg_upperLine->changeAll(true);
	// Untere Linie init;
	seg_lowerLine->changeAll(true);
	// Doppelpunkte init.
	seg_doubleDots->choseDigit(":");
	// Ziffern komplett gelb zeigen
	seg_hour1->changeAll(true);
	seg_hour2->changeAll(true);
	seg_min1->changeAll(true);
	seg_min2->changeAll(true);
	screen_p->updateScreen_Segment(*seg_upperLine);
	screen_p->updateScreen_Segment(*seg_lowerLine);
	screen_p->updateScreen_Segment(*seg_doubleDots);
}

void DigitalWatch::runClock() {
	int min2_prev = 11;
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
		// Änderung des Displays nur bei Änderung der Zeit
		if (min2_prev != min2) {
			// Darstellen der Ziffern
			// TODO Testen, ob der Stream auch im vornherein beladen werden kann und dann nacheinander ausgegeben werden kann
			ostringstream Str;
			Str << hour1;
			seg_hour1->choseDigit(Str.str());
			Str << hour2;
			seg_hour2->choseDigit(Str.str());
			Str << min1;
			seg_min1->choseDigit(Str.str());
			Str << min2;
			seg_min2->choseDigit(Str.str());
			// Anzeigen auf Screen
			screen_p->updateScreen_Segment(*seg_hour1);
			screen_p->updateScreen_Segment(*seg_hour2);
			screen_p->updateScreen_Segment(*seg_min1);
			screen_p->updateScreen_Segment(*seg_min2);
			screen_p->showScreen_Display();
			screen_p->showScreen_Console();
			min2_prev = min2;
		}
	}
}
