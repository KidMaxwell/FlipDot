/*
 * FlipDot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul, alex
 */

#include "Dot.h"
#include "ShiftRegister.h"
#include "Segment.h"
#include "DigitalWatch.h"
#include "FlipDot.h"
#include <string>
#include <wiringPi.h>
#include <iostream>

using namespace std;

#define dEnableP 0
#define dDP 1
#define clkP 2
#define serP 3
#define sEnableP 4

/* Konstruktor der Klasse FlipDot
 * initialisiert wiringPi und das 2D Array
 * setzt den pinMode von enableP auf OUTPUT
 */
FlipDot::FlipDot() {
	//cout << "Programm wird gestartet" << endl;
	wiringPiSetup();
	pinMode(dEnableP, OUTPUT);
	digitalWrite(dEnableP, 0);
	pinMode(dDP, OUTPUT);
	digitalWrite(dDP, 0);
	//alle Dots erstellen und in dots Array speichern
	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 28; c++) {
			dots[r][c].set(r, c, false);
		}
	}
	newStateI = 0;
	row = 0;
	column = 0;
	newState = false;
	SR.Init(clkP, serP, sEnableP);
}

/*
 * Nutzerkommunikation über Kosole
 * Dem Nutzer werden die einzelnen Modi vorgeschlagen und dieser kann dann auswählen
 * Noch im Aufbau: TODO Informationsanzeige
 * über Modus? können Informationen zu dem Modus angezeigt werden
 */
void FlipDot::consoleMenu() {
	string input = "0";
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
		//Test
		cout << "--Test-- Input:" << input << endl;
		// Funktioniert noch nicht!
		/*
		 if (input[1] == '?') {
		 switch (input[0]) {
		 case '1':
		 // TODO: Erklärung einfügen
		 break;
		 case '2':
		 // TODO: Erklärung einfügen
		 break;
		 case '3':
		 // TODO: Erklärung einfügen
		 break;
		 }
		 cout << endl << endl << "Bitte erneute Auswahl:" << endl << endl;
		 continue;
		 } else {
		 */
		//	switch (input[0]) {
		if(input=="1") {
			modeChange();
		}
		else if(input=="2") {
			modeChangeAll();
		}
		else if(input=="3") {
			DigitalWatch watch;
		}
		else {
			cout << endl << endl << "Bitte erneute Auswahl:" << endl << endl;
			continue;
		}
		//}
	}
}

/*
 * Führt das Ändern einzelner Dots aus
 * ist in einer Endlosschleife implementiert, die wiederholtes ändern ermöglicht
 * Rücksprung ins Hauptmenü durch Abbruch
 */
void FlipDot::modeChange() {
	showScreen();
	char abort = 'n';
	while (1) {
		cout << endl << "Abbruch? y/n: ";
		cin >> abort;
		if (abort == 'y')
			break;
		cout  << endl << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> column;
		cout << "NewState: ";
		cin >> newStateI;
		cout << endl << endl;
		newState = (bool) newStateI;
		change(row, column, newState);
		showScreen();
	}
}

/*
 * Führt das Ändern aller Dots aus
 * danach direkter Rücksprung ins Hauptmenü
 * TODO Dauert lange -- Zeitverzögerung?
 */
void FlipDot::modeChangeAll() {
	int value;
	value = 0;
	cout << "NewState: ";
	cin >> value;
	cout << endl;
	changeAll((bool) value);
	showScreen();
}

/*
 * Zeigt den derzeiten Zustand aller Dots
 */
void FlipDot::showScreen() {
	cout << "------------------------------" << endl;
	for (int r = 0; r < 16; r++) {
		cout << "|";
		for (int c = 0; c < 28; c++) {
			cout << dots[r][c].getState();
		}
		cout << "|" << endl;
	}
	cout << "------------------------------" << endl;
}

/*
 * Ändert den Zustand eines Dots, 1=gelb, 0=schwarz
 */

void FlipDot::change(int row, int column, bool newState) {
	this->newState = newState;
	dots[row][column].setState(newState);
	loadSR(row, column, newState);
	enable();
}

/*
 * Aendert den Zustand eines Dots unter der Bedingung dass sich der Soll Status vom Ist Status unterscheidet
 */

void FlipDot::changeIfDifferent(Dot d, bool newState) {
	bool oldState = d.getState();
	if (oldState != newState) {
		change(d.getRow(), d.getColumn(), newState);
	}
}

/*
 * Aendert den Zustand einer ganzen Zeile
 */

void FlipDot::changeRow(int r, bool newState){
	for (int c = 0; c < 28; c++) {
				change(r, c, newState);
			}
}

/*
 * Aendert den Zustand einer ganzen Spalte
 */

void FlipDot::changeCollum(int c, bool newState){
	for (int r = 0; r < 16; r++) {
		change(r, c, newState);
	}
}

/*
 * Aendert den Zustand aller Dots auf einen neuen Zustand
 */

void FlipDot::changeAll(bool newState) {
	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 28; c++) {
			change(r, c, newState);
		}
	}
}

/*
 * Methode zum Berechnen des Bit Arrays welches in die Schieberegister geschoben wird
 * Bit 0-7: Kodierung der Spalte
 * Bit 8-15: Enable der Zeilen Treiberstufe
 * Bit 16-31: Pegel der Zeilentreiber
 * Schreibt das Bit Array in die Schieberegister mit Hilfe der ShiftRegister.cpp
 */

void FlipDot::loadSR(int row, int column, bool newState) {
	bool inputArray[32];
	for (int i = 0; i < 32; i++) {
		inputArray[i] = false;
	}
// Auswählen der Zeile
	for (int i = 0; i < row; i++) {
		inputArray[16 + i] = !newState;
	}
	inputArray[16 + row] = newState;
	for (int i = (row + 1); i < 16; i++) {
		inputArray[16 + i] = !newState;
	}
// Zeilen Enable
	inputArray[8 + ((row) / 2)] = true;
// Auswählen der Spalte
	switch (column) {
	case 0:
		inputArray[0] = true;
		break;
	case 1:
		inputArray[1] = true;
		break;
	case 2:
		inputArray[0] = true;
		inputArray[1] = true;
		break;
	case 3:
		inputArray[2] = true;
		break;
	case 4:
		inputArray[0] = true;
		inputArray[2] = true;
		break;
	case 5:
		inputArray[1] = true;
		inputArray[2] = true;
		break;
	case 6:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[2] = true;
		break;
	case 7:
		inputArray[0] = true;
		inputArray[3] = true;
		break;
	case 8:
		inputArray[1] = true;
		inputArray[3] = true;
		break;
	case 9:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[3] = true;
		break;
	case 10:
		inputArray[2] = true;
		inputArray[3] = true;
		break;
	case 11:
		inputArray[0] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		break;
	case 12:
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		break;
	case 13:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		break;
	case 14:
		inputArray[0] = true;
		inputArray[4] = true;
		break;
	case 15:
		inputArray[1] = true;
		inputArray[4] = true;
		break;
	case 16:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[4] = true;
		break;
	case 17:
		inputArray[2] = true;
		inputArray[4] = true;
		break;
	case 18:
		inputArray[0] = true;
		inputArray[2] = true;
		inputArray[4] = true;
		break;
	case 19:
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[4] = true;
		break;
	case 20:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[4] = true;
		break;
	case 21:
		inputArray[0] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 22:
		inputArray[1] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 23:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 24:
		inputArray[2] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 25:
		inputArray[0] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 26:
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 27:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	default:
		break;
	}

	SR.loadnWrite(inputArray);
}

/*
 * Ist fuer das eigentliche Flippen Verantwortlich, Aktiviert alle noetigen enables und den Daten Pin des Decoders
 */

void FlipDot::enable() {
	SR.enableSR();
	digitalWrite(dDP, !newState);
	delay(1);
	digitalWrite(dEnableP, 1);
	delay(10);
	digitalWrite(dEnableP, 0);
	SR.disableSR();
}

/*
 * main Methode, erzeugt ein FlipDot objekt
 */

int main() {
	FlipDot f;
	f.consoleMenu();
	return 0;
}
