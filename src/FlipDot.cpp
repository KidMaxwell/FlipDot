/*
 * FlipDot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul, alex
 */
#include "FlipDot.h"

using namespace std;

/*
 * Konstruktor der Klasse FlipDot
 * Initialisiert den Screen (Array, das in der Komandozeile angezeigt wird)
 */
FlipDot::FlipDot() {
	screen_p = new Screen();
	screen_p->showBlackScreen_Display();
}

/*
 * Nutzerkommunikation über Kosole
 * Dem Nutzer werden die einzelnen Modi vorgeschlagen und dieser kann dann auswählen
 * über Modus? können Informationen zu dem Modus angezeigt werden
 */
void FlipDot::consoleMenu() {
	string input = "0";
	cout << "Hallo und Herzlich Willkommen in der Welt der flippenden Dots"
			<< endl << "Es gibt folgende Modi:" << endl << endl;
	while (1) {
		cout << "\t1: Einzelauswahl" << endl << "\t2: Gesamtauswahl" << endl
				<< "\t3: Digitaluhr" << endl << "\t4: Snake Single" << endl << "\t5: Text Editor" << endl
				<< endl
				<< "Auswahl durch eintippen der Auswahlnummer und Bestaetigung mittels Enter"
				<< endl
				<< "Fuer weitere Erlaeuterungen: Auswahlnummer? eingeben und bestaetigen"
				<< endl;
		cin >> input;
		if (input == "1")
			modeChange();
		else if (input == "2")
			modeChangeAll();
		else if (input == "3") {
			DigitalWatch* clock = new DigitalWatch(screen_p);
			clock->runClock();
			screen_p->updateScreen_All(false);
			screen_p->showScreen_Display();
		} else if (input == "4") {
			SnakeSingle2 *snake = new SnakeSingle2(screen_p);
			snake->menu();
			screen_p->updateScreen_All(false);
			screen_p->showScreen_Display();
		} else if (input == "5") {
			TextEditor *textEditor = new TextEditor(screen_p);
			textEditor->userInput();
		} else if (input == "1?") {
			cout << endl << "Auswahl einzelner Dots möglich." << endl;
		} else if (input == "2?") {
			cout << endl << "Ansteuerung des gesamten Displays." << endl;
		} else if (input == "3?") {
			cout << endl
					<< "Es wird die aktuelle Uhrzeit in digitaler Form angezeigt."
					<< endl << "(Raspi muss mit dem Internet verbunden sein)"
					<< endl;
		} else if (input == "4?") {
			cout << endl << "Snake kann im Single-Player-Modus gespielt werden."
					<< endl
					<< "weitere Informationen in der Menüführung der Spiels."
					<< endl;
		}
		else {
			cout << endl << endl << "Bitte erneute Auswahl:" << endl << endl;
			continue;
		}
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
	screen_p->showScreen_Console();
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
		screen_p->updateScreen_Single(row, column, newState);
		screen_p->showScreen_Display();
		screen_p->showScreen_Console();
	}
}

/*
 * Führt das Ändern aller Dots aus
 * danach direkter Rücksprung ins Hauptmenü
 */
void FlipDot::modeChangeAll() {
int newState = 0;
cout << "NewState: ";
cin >> newState;
cout << endl;
screen_p->updateScreen_All(newState);
screen_p->showScreen_Display();
screen_p->showScreen_Console();
}

/*
 * main-Methode:
 * Start des Programms
 */
int main() {
FlipDot* f = new FlipDot();
f->consoleMenu();
return 0;
}
