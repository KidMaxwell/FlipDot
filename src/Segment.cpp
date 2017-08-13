/*
 * Segment.cpp
 *
 *  Created on: 09.08.2017
 *      Author: paul, alex
 */
#include "Segment.h"

using namespace std;

Segment::Segment() {
	this->c_start = 0;
	this->r_start = 0;
	this->width = 28;
	this->hight = 16;
	this->newState = false;
}

/*
 * Initialisierung des Segments:
 * Es wird ein Array erzeugt, welches einen Teil des Displays darstellt
 * Dieser kann dann gesondert manipuliert werden
 * WICHTIG: die Segmente dürfen sich nicht überlagern!
 */
void Segment::init(int c_start, int r_start, int width, int hight) {
	this->c_start = c_start;
	this->r_start = r_start;
	this->width = width;
	this->hight = hight;
	// Dots werden in der Groesse des Segements erstellt und in Array abgelegt
	for (int r = 0; r < width; r++) {
		for (int c = 0; c < hight; c++) {
			dots[r][c].set(r, c, false);
		}
	}
}

int Segment::getR_start() {
	return r_start;
}
int Segment::getC_start() {
	return c_start;
}
int Segment::getHight() {
	return hight;
}
int Segment::getWidth() {
	return width;
}

/*
 * Verändert Status einzelner Dots
 * Übergabeparameter sind die Reihen- und Spaĺtenangaben für das konkrete Segment
 * Diese werden dann in einen Displaywert umgerechnet und an die HAL-Ebene weitergeleitet
 * Abschließen noch den Screen (interne Anzeige updaten und ausgeben)
 */
void Segment::change(Screen* screen_p, int seg_row, int seg_column,
		bool newState) {
	int disp_row = seg_row + r_start;
	int disp_column = seg_column + c_start;
	dots[seg_row][seg_column].setState(newState);
	addr.loadSR(disp_row, disp_column, newState);
	addr.enable(newState);
	screen_p->updateScreen(disp_row, disp_column, newState);
}

/*
 void Segment::changeIfDifferent(Screen* screen_p,Dot d, bool newState) {
 bool oldState = d.getState();
 if (oldState != newState) {
 change(screen_p, d.getRow(), d.getColumn(), newState);
 }
 }
 */

void Segment::changeRow(Screen* screen_p, int seg_row, bool newState) {
	for (int seg_column = 0; seg_column <= width; seg_column++) {
		change(screen_p, seg_row, seg_column, newState);
	}
}

void Segment::changeCollum(Screen* screen_p, int seg_column, bool newState) {
	for (int seg_row = 0; seg_row <= hight; seg_row++) {
		change(screen_p, seg_row, seg_column, newState);
	}
}
void Segment::changeAll(Screen* screen_p, bool newState) {
	for (int seg_row = 0; seg_row <= hight; seg_row++) {
		for (int seg_column = 0; seg_column <= width; seg_column++) {
			change(screen_p, seg_row, seg_column, newState);
		}
	}
}

