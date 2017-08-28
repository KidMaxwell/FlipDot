/*
 * Segment.cpp
 *
 *  Created on: 09.08.2017
 *      Author: paul, alex
 */
#include "Segment.h"
#include <iostream>

using namespace std;

/*
 * Erzeugen eines Segments:
 * Es wird ein Array erzeugt, welches einen Teil des Displays darstellt
 * Dieser kann dann gesondert manipuliert werden
 * WICHTIG: die Segmente dürfen sich nicht überlagern!
 */
Segment::Segment(Screen* scr_p, int col_start, int row_start, int col_max, int row_max) :
		screen_p(scr_p), seg_column_start(col_start), seg_row_start(row_start), seg_column_width(
				col_max), seg_row_hight(row_max), newState(false)
	{
	addr = new HAL_Addr();
	if(!checkValues()){
		// TODO- - - Interrupt
	}
	// Dots werden in der Groesse des Segements erstellt und in Array abgelegt
	for (int row = 0; row < seg_row_hight; row++) {
		vector<Dot> vec_row;
		for (int col = 0; col < seg_column_width; col++) {
			vec_row.push_back(*(new Dot(row, col, false)));
		}
		vec_dots.push_back(vec_row);
	}
}

/*
 * Eingegebene Werte können geprueft werden
 * 	Bei manueller Eingabe über Konsole wichtig!
 */
bool Segment::checkValues() {
	if (!(seg_column_start >= 0 && seg_column_start < COL_MAX)) {
		cout << "Error: seg_column_start out of bounds" << endl;
		return false;
	}
	if (!(seg_row_start >= 0 && seg_row_start < ROW_MAX)) {
		cout << "Error: seg_row_start out of bounds" << endl;
		return false;
	}
	if (!(seg_column_width > 0
			&& (seg_column_start + seg_column_width) <= COL_MAX)) {
		cout << "Error: seg_column_width out of bounds" << endl;
		return false;
	}
	if (!(seg_row_hight > 0 && (seg_row_start + seg_row_hight) <= ROW_MAX)) {
		cout << "Error: seg_row_hight out of bounds" << endl;
		return false;
	}
	return true;
}

/*
 * Verändert Status einzelner Dots
 * Übergabeparameter sind die Reihen- und Spaĺtenangaben für das konkrete Segment
 * Diese werden dann in einen Displaywert umgerechnet und an die HAL-Ebene weitergeleitet
 * Abschließen noch den Screen (interne Anzeige) updaten und ausgeben
 */
void Segment::change(int seg_row, int seg_column,
		bool newState) {
	int disp_row = seg_row + seg_row_start;
	int disp_column = seg_column + seg_column_start;
	vec_dots[seg_row][seg_column].setState(newState);
	addr->loadSR(disp_row, disp_column, newState);
	addr->enable(newState);
	screen_p->updateScreen(disp_row, disp_column, newState);
}

/*
 void Segment::changeIfDifferent(Dot d, bool newState) {
 bool oldState = d.getState();
 if (oldState != newState) {
 change(screen_p, d.getRow(), d.getColumn(), newState);
 }
 }
 */

void Segment::changeRow(int seg_row, bool newState) {
	for (int seg_column = 0; seg_column < seg_column_width; seg_column++) {
		change(seg_row, seg_column, newState);
	}
}

void Segment::changeColumn(int seg_column, bool newState) {
	for (int seg_row = 0; seg_row < seg_row_hight; seg_row++) {
		change(seg_row, seg_column, newState);
	}
}

void Segment::changeAll(bool newState) {
	for (int seg_row = 0; seg_row < seg_row_hight; seg_row++) {
		for (int seg_column = 0; seg_column < seg_column_width; seg_column++) {
			change(seg_row, seg_column, newState);
		}
	}
}
