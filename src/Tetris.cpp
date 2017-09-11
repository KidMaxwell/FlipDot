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
				0), buttons(new HAL_Button()), speed(0), highscore(0), button_hits(
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
		// Bewegung der Elemente
		moveElement();
		// Element zum Built-Bereich hinzufügen
		seg_built->changeSegment(newElement_p);
		// Löschen voller Reihen
		screen_p->remove_builtColumn();
	} while (screen_p->check_hitTop());
}

void Tetris::moveElement() {
	while (check_hitBuilt()) {
		// Implementiert auch das Warten
		button_hits = buttons->readButton(speed);
		// pos: Verschiebung nach links, neg: Verschiebung nach rechts
		int move_amount = button_hits.b_left - button_hits.b_right;
		if (move_amount > 0)
			moveElement_Direction("left", move_amount);
		if (move_amount < 0)
			moveElement_Direction("right", 0 - move_amount);
		moveElement_Direction("down", 1);
		screen_p->updateScreen_Segment(*newElement_p);
		screen_p->showScreen_Display();
		screen_p->showScreen_Console();
	}
}

/*
 * Erzeugt ein zufälliges TetrisElement
 */
TetrisElement Tetris::createElement() {
	TetrisElement newElement = *(elements_Array[rand_min_max(0, 3)]);
	newElement.rotate(rand_min_max(0, 3));
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
 * Prüft, ob Element schon auf Built-Bereich ist
 */
bool Tetris::check_hitBuilt() {
	Segment::koordinates koord = newElement_p->get_lowestDot();
	if (koord.row.front() != -1 && koord.column.front() != -1)
		return screen_p->check_hitBuilt(koord);
	else {
		cout << "Fehler beim Bestimmen der tiefsten Koordinatenpunkte" << endl;
		return false;
	}
}

/*
 * Gernerierten einer Zufallszahl im Bereich [min, max]
 */
int Tetris::rand_min_max(int min, int max) {
	srand((unsigned) time(NULL));
	return rand() % (max - min + 1) + min + 1;
}
