/*
 * Tetris.cpp
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "Tetris.h"

using namespace std;

Tetris::Tetris(Screen* scr_p) :
		screen_p(scr_p), seg_built(new Segment(0, 0, COL_MAX, ROW_MAX)), newElement_p(
				0), buttons(new HAL_Button()), speed(1), highscore(0), button_hits(
				{ 0, 0, 0, 0 }) {
	screen_p->updateScreen_All(false);
	elements_Array[0] = new TetrisElement("Block", 2);
	elements_Array[1] = new TetrisElement("I", 4);
	elements_Array[2] = new TetrisElement("L", 3);
	elements_Array[3] = new TetrisElement("Stair", 3);
	elements_Array[4] = new TetrisElement("T", 3);
}

void Tetris::menuTetris() {
	cout << "Gechwindigkeit?" << endl;
	cin >> speed;
}

/*
 * Hauptsteuerschleife
 */
void Tetris::runTetris() {
	do {
		// zufälliges Erzeugen neuer Elemente
		TetrisElement newElement = createElement();
		newElement_p = &newElement;
		// Bewegung des Elements
		moveElement();
		// Löschen voller Reihen
		remove_builtColumn();
	} while (check_hitTop());
}

void Tetris::moveElement() {
	// TEST
	bool checkBuilt = check_hitBuilt();
	/*
	while (!check_hitBuilt()) {
		// Steuerbewegungen Abfragen
		// Implementiert auch das Warten
		button_hits = buttons->readButton(speed);
		// pos: Verschiebung nach links, neg: Verschiebung nach rechts
		int move_amount = button_hits.b_left - button_hits.b_right;
		if (move_amount > 0 && check_validMovement(move_amount))
			moveElement_Direction("left", move_amount);
		if (move_amount < 0 && check_validMovement(move_amount))
			moveElement_Direction("right", 0 - move_amount);
		moveElement_Direction("down", 1);
		screen_p->updateScreen_Segment(*newElement_p);
		screen_p->showScreen_Display();
		screen_p->showScreen_Console();
	}
	*/
	// Element zum Built-Bereich hinzufügen
	seg_built->changeSegment(newElement_p);
}

/*
 * Erzeugt ein zufälliges TetrisElement
 */
TetrisElement Tetris::createElement() {
	TetrisElement newElement = *(elements_Array[rand_min_max(0, 3)]);
	// TODO Rotate() nochmal anschauen!
//	newElement.rotate(rand_min_max(0, 3));
	return newElement;
}

void Tetris::moveElement_Direction(string direction, int move_amount) {
	Segment* seg_p = (Segment*) malloc(sizeof(Segment));
	if (direction == "down") {
		seg_p = newElement_p->move_Down(move_amount);
	} else if (direction == "left") {
		seg_p = newElement_p->move_Left(move_amount);
	} else if (direction == "right") {
		seg_p = newElement_p->move_Right(move_amount);
	} else {
		cout << "Fehler: falscher Parameter moveElement_Direction" << endl;
	}
	screen_p->updateScreen_Segment(*seg_p);
	free(seg_p);
}

/*
 * Prüft, ob noch weiter nach links oder rechts verschoben werden darf
 */
bool Tetris::check_validMovement(int move_amount) {
	int max_move_amount = 0;
	// Bewegung nach OBEN (Querformat)
	if (move_amount > 0) {
		for (int element_column = 0;
				element_column < newElement_p->get_seg_column_width();
				element_column++) {
			int disp_column = element_column
					+ newElement_p->get_seg_column_start();
			// Am oberen Rand mit dem Durchsuchen beginnen
			for (int element_row = 0;
					element_row < newElement_p->get_seg_row_hight();
					element_row++) {
				// Bestimmung macht nur bei true-Dot Sinn!
				if (!newElement_p->get_state(element_row, element_column))
					continue;
				// Bestimmung der maximalen Bewegungen nach oben
				int disp_row = element_row + newElement_p->get_seg_row_start();
				int possible_move_amount = 0;
				while (!seg_built->get_state(disp_row, disp_column)
						&& disp_row < ROW_MAX) {
					possible_move_amount++;
					disp_row++;
				}
				// Vergleich mit max. Menge
				if (max_move_amount < possible_move_amount)
					max_move_amount = possible_move_amount;
				break;
			}
		}
		return (move_amount <= max_move_amount);
	}
	// Bewegung nach UNTEN (Querformat)
	if (move_amount < 0) {
		for (int element_column = 0;
				element_column < newElement_p->get_seg_column_width();
				element_column++) {
			int disp_column = element_column
					+ newElement_p->get_seg_column_start();
			// Am unteren Rand mit dem Durchsuchen beginnen
			for (int element_row = newElement_p->get_seg_row_hight() - 1;
					element_row != 0; element_row--) {
				// Bestimmung macht nur bei true-Dot Sinn!
				if (!newElement_p->get_state(element_row, element_column))
					continue;
				// Bestimmung der maximalen Bewegungen nach unten
				int disp_row = element_row + newElement_p->get_seg_row_start();
				int possible_move_amount = 0;
				while (!seg_built->get_state(disp_row, disp_column)
						&& disp_row < ROW_MAX) {
					possible_move_amount--;
					disp_row--;
				}
				// Vergleich mit max. Menge (neg!)
				if (max_move_amount > possible_move_amount)
					max_move_amount = possible_move_amount;
				break;
			}
		}
	}
	return (move_amount >= max_move_amount);
}

/*
 * Prüft, ob Element schon auf Built-Bereich ist
 */
bool Tetris::check_hitBuilt() {
	Segment::koordinates koord_display = newElement_p->get_lowestDot();
	if (koord_display.row.front() != -1 && koord_display.column.front() != -1) {
		for (int disp_column = 0; disp_column < COL_MAX; disp_column++) {
			for (int disp_row = 0; disp_row < ROW_MAX; disp_row++) {
				if (!seg_built->get_state(disp_row, disp_column))
					continue;
				vector<int>::iterator it_column = koord_display.column.begin();
				for (vector<int>::iterator it_row = koord_display.row.begin();
						it_row != koord_display.row.end(); it_row++) {
					if (*it_row == disp_row && (*it_column + 1) == disp_column)
						return true;
				}
			}
		}
		return false;
	} else {
		cout << "Fehler beim Bestimmen der tiefsten Koordinatenpunkte" << endl;
		return false;
	}
}

/*
 * Prüfen, ob der Built-Bereich am oberen Bildrand angestoßen ist
 */
bool Tetris::check_hitTop() {
	for (int row = ROW_MIN; row < ROW_MAX; row++) {
		if (seg_built->get_state(row, 0))
			return true;
	}
	return false;
}

/*
 * Auffinden und Löschen vollständiger Reihen
 * Führt nur ein Update auf dem Screen druch -> liegt im sollDisplay!
 */
void Tetris::remove_builtColumn() {
	vector<int> built_columns;
// Auffinden einer vollständigen Reihe (von oben nach unten)
	for (int column = COL_MAX; column != COL_MIN; column--) {
		bool built = true;
		for (int row = 0; row < ROW_MAX; row++) {
			if (!seg_built->get_state(row, column)) {
				built = false;
				break;
			}
		}
		if (built)
			built_columns.push_back(column);
	}
// Löschen einer vollständigen Spalte
// Spalten, die links davon liegen rutschen nach (Querformat)
	for (vector<int>::iterator it = built_columns.begin();
			it != built_columns.end(); it++) {
		int remove_column = *it;
		Segment seg_leftToBuiltColumn = *(new Segment(COL_MIN, ROW_MIN,
				(COL_MAX - remove_column), ROW_MAX));
		for (int column = COL_MIN; column < remove_column; column++) {
			for (int row = ROW_MIN; row < ROW_MIN; row++) {
				bool newState = seg_built->get_state(row, column);
				seg_leftToBuiltColumn.change(row, column, newState);
				seg_built->change(row, column, false);
			}
		}
		seg_leftToBuiltColumn.set_seg_column_start(COL_MIN + 1);
		seg_built->changeSegment(&seg_leftToBuiltColumn);
		screen_p->updateScreen_Segment(*seg_built);
	}
	increment_Highscore(built_columns.size());
}

/*
 * Aktualisiert den Highscore
 * auch in Abhängigkeit von der Anzahl der auf ein Mal entfernten Reihen
 * 10 Pkt. pro Reihe
 * Bonus für mehrere Reihen noch zusätzlich überlegen
 */
void Tetris::increment_Highscore(int removed_columns){
	int increment = removed_columns * 10;
	// TODO Bonus noch implementieren
	highscore += increment;
}

/*
 * Gernerierten einer Zufallszahl im Bereich [min, max]
 */
int Tetris::rand_min_max(int min, int max) {
	srand((unsigned) time(NULL));
	return rand() % (max - min + 1) + min + 1;
}
