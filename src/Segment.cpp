/*
 * Segment.cpp
 *
 *  Created on: 09.08.2017
 *      Author: paul, alex
 */
#include "Segment.h"

using namespace std;

Segment::Segment() {
	this->seg_column_start = 0;
	this->seg_row_start = 0;
	this->seg_column_width = 28;
	this->seg_row_hight = 16;
	this->newState = false;
}

/*
 * Initialisierung des Segments:
 * Es wird ein Array erzeugt, welches einen Teil des Displays darstellt
 * Dieser kann dann gesondert manipuliert werden
 * WICHTIG: die Segmente dürfen sich nicht überlagern!
 */
void Segment::init(int seg_colmn_start, int seg_row_start, int seg_column_width,
		int seg_row_max) {
	if (seg_column_start > -1 && seg_column_start < COL_MAX) {
		this->seg_column_start = seg_column_start;
	} else {
		// TODO-- Interrupt
	}
	if (seg_row_start > -1 && seg_row_start < ROW_MAX) {
		this->seg_row_start = seg_row_start;
	} else {
		// Interrupt
	}
	if (seg_column_width > 0 && (seg_column_start + seg_column_width) < COL_MAX) {
		this->seg_column_width = seg_column_width;
	} else {
		// Interrupt
	}
	if (seg_row_hight > 0 && (seg_row_start + seg_row_hight) < COL_MAX) {
		this->seg_row_hight = seg_row_hight;
	} else {
		// Interrupt
	}
	// Dots werden in der Groesse des Segements erstellt und in Array abgelegt
	for (int r = 0; r < seg_column_width; r++) {
		for (int c = 0; c < seg_row_hight; c++) {
			dots[r][c].set(r, c, false);
		}
	}
}

/*
 * Verändert Status einzelner Dots
 * Übergabeparameter sind die Reihen- und Spaĺtenangaben für das konkrete Segment
 * Diese werden dann in einen Displaywert umgerechnet und an die HAL-Ebene weitergeleitet
 * Abschließen noch den Screen (interne Anzeige updaten und ausgeben)
 */
void Segment::change(Screen* screen_p, int seg_row, int seg_column,
		bool newState) {
	int disp_row = seg_row + seg_row_start;
	int disp_column = seg_column + seg_column_start;
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
	for (int seg_column = 0; seg_column < seg_column_width; seg_column++) {
		change(screen_p, seg_row, seg_column, newState);
	}
}

void Segment::changeColumn(Screen* screen_p, int seg_column, bool newState) {
	for (int seg_row = 0; seg_row < seg_row_hight; seg_row++) {
		change(screen_p, seg_row, seg_column, newState);
	}
}
void Segment::changeAll(Screen* screen_p, bool newState) {
	for (int seg_row = 0; seg_row < seg_row_hight; seg_row++) {
		for (int seg_column = 0; seg_column < seg_column_width; seg_column++) {
			change(screen_p, seg_row, seg_column, newState);
		}
	}
}

