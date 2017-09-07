/*
 * DigitalWatch.cpp
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */

#include "DigitalWatch.h"

using namespace std;

DigitalWatch::DigitalWatch(Screen* scr_p) :
		screen_p(scr_p), seg_complete(
				new ClockSegment(screen_p, 0, 0, COL_MAX, ROW_MAX)), seg_upperLine(
				new ClockSegment(screen_p, 0, 1, COL_MAX, 1)), seg_lowerLine(
				new ClockSegment(screen_p, 0, 13, COL_MAX, 1)), seg_doubleDots(
				new ClockSegment(screen_p, 13, 5, 2, 5)), seg_hour1(
				new ClockSegment(screen_p, 1, 4, 5, 7)), seg_hour2(
				new ClockSegment(screen_p, 7, 4, 5, 7)), seg_min1(
				new ClockSegment(screen_p, 16, 4, 5, 7)), seg_min2(
				new ClockSegment(screen_p, 22, 4, 5, 7)) {
	// Obere Linie init.
	seg_upperLine->changeAll(true);
	// Untere Linie init;
	seg_lowerLine->changeAll(true);
	// Doppelpunkte init.	-> FUNKTIONIERT
	seg_doubleDots->change(0, 0, true);
	seg_doubleDots->change(0, 1, true);
	seg_doubleDots->change(1, 0, true);
	seg_doubleDots->change(1, 1, true);
	seg_doubleDots->change(3, 0, true);
	seg_doubleDots->change(3, 1, true);
	seg_doubleDots->change(4, 0, true);
	seg_doubleDots->change(4, 1, true);
	// Ziffern komplett gelb zeigen
	seg_hour1->changeAll(true);
	seg_hour2->changeAll(true);
	seg_min1->changeAll(true);
	seg_min2->changeAll(true);
	screen_p->showScreen_Display();
	screen_p->showScreen_Console();
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
		cout << "---Test---  Zeit: " << hour1 << hour2 << " : " << min1 << min2
				<< endl;
		// Änderung des Displays nur bei Änderung der Zeit
		if (min2_prev != min2) {
			// Darstellen der Ziffern
			seg_hour1->choseNumber(hour1);
			seg_hour2->choseNumber(hour2);
			seg_min1->choseNumber(min1);
			seg_min2->choseNumber(min2);
			// Anzeigen auf des Soll-Displays auf Konsole
			screen_p->showSollScreen_Console();
			// Anzeigen auf Screen
			screen_p->showScreen_Display();
			// --- TEST ---
			// Anzeigen auf des Ist-Displays auf Konsole
			// muss mit Soll-Screen uebereinstimmen
			screen_p->showIstScreen_Console();
			min2_prev = min2;
		}
	}
}
