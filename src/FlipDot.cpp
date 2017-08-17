/*
 * FlipDot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul, alex
 */
#include "FlipDot.h"
#include "HAL_HardwareDefines.h"
#include <string>
#include <iostream>

using namespace std;

/*
 * Konstruktor der Klasse FlipDot
 * Initialisiert den Screen (Array, das in der Komandozeile angezeigt wird)
 */
FlipDot::FlipDot() {
	screen_p = &screen;
	seg_complete.init(0, 0, COL_MAX, ROW_MAX);
}

/*
 * Nutzerkommunikation über Kosole
 * Dem Nutzer werden die einzelnen Modi vorgeschlagen und dieser kann dann auswählen
 * Noch im Aufbau: TODO Informationsanzeige
 * über Modus? können Informationen zu dem Modus angezeigt werden
 */
void FlipDot::consoleMenu() {
	char input = '0';
	cout << "Hallo und Herzlich Willkommen in der Welt der flippenden Dots"
			<< endl << "Es gibt folgende Modi:" << endl << endl;
	while (1) {
		cout << "\t1: Einzelauswahl" << endl << "\t2: Gesamtauswahl" << endl
				<< "\t3: Digitaluhr" << endl << endl
				<< "Auswahl durch eintippen der Auswahlnummer und Bestaetigung mittels Enter"
				<< endl
				<< "Fuer weitere Erlaeuterungen: Auswahlnummer? eingeben und bestaetigen"
				<< endl;
		cin >> input;
		// Funktioniert noch nicht!
		/*
		 if (input[1] == '?') {
		 switch (input[0]) {
		 case '1':
		 // Erklärung einfügen
		 break;
		 case '2':
		 // Erklärung einfügen
		 break;
		 case '3':
		 // Erklärung einfügen
		 break;
		 }
		 cout << endl << endl << "Bitte erneute Auswahl:" << endl << endl;
		 continue;
		 } else {
		 */
		//	switch (input[0]) {
		switch (input) {
		case '1':
			modeChange();
			break;
		case '2':
			modeChangeAll();
			break;
		case '3':
			DigitalWatch watch;
			watch.runClock(screen_p);
			break;
		}
		cout << endl << endl << "Bitte erneute Auswahl:" << endl << endl;
		continue;
		//}
	}
}

/*
 * Führt das Ändern einzelner Dots aus
 * ist in einer Endlosschleife implementiert, die wiederholtes ändern ermöglicht
 * Rücksprung ins Hauptmenü durch Abbruch
 */
void FlipDot::modeChange() {
	int row = 0;
	int column = 0;
	int newStateI = 0;
	bool newState = false;
	screen_p->showScreen();
	char abort = 'n';
	while (1) {
		cout << endl << "Abbruch? y/n: ";
		cin >> abort;
		if (abort == 'y')
			break;
		cout << "Reihe: ";
		cin >> row;
		cout << "Spalte: ";
		cin >> column;
		cout << "Neuer Status: ";
		cin >> newStateI;
	cout << endl << endl;
		newState = (bool) newStateI;
		seg_complete.change(screen_p, row, column, newState);
		screen_p->showScreen();
	}
}

/*
 * Führt das Ändern aller Dots aus
 * danach direkter Rücksprung ins Hauptmenü
 */
void FlipDot::modeChangeAll() {
	int value = 0;
	cout << "NewState: ";
	cin >> value;
	cout << endl;
	seg_complete.changeAll(screen_p, (bool) value);
	screen_p->showScreen();
}

int main() {
	FlipDot f;
	f.consoleMenu();
	return 0;
}
