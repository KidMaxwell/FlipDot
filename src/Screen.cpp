/*
 * Screen.cpp
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */

#include "Screen.h"

using namespace std;

Screen::Screen() :
		addr(new HAL_Addr()) {
	for (int row = ROW_MIN; row < ROW_MAX; row++) {
		for (int column = COL_MIN; column < COL_MAX; column++) {
			istDisplay[row][column] = new Dot(row, column, false);
			sollDisplay[row][column] = new Dot(row, column, false);
		}
	}
}
//TODO +++ hight in HEIGHT aendern (fuer Paul)
void Screen::updateScreen_Segment(Segment segment) {
	int seg_row_hight = segment.get_seg_row_hight();
	int seg_column_width = segment.get_seg_column_width();
	for (int seg_row = 0; seg_row < seg_row_hight; seg_row++) {
		for (int seg_column = 0; seg_column < seg_column_width; seg_column++) {
			// Umrechnen ins Display-Format
			int disp_row = seg_row + segment.get_seg_row_start();
			int disp_column = seg_column + segment.get_seg_column_start();
			bool newState = segment.get_state(seg_row, seg_column);
			sollDisplay[disp_row][disp_column]->setState(newState);
		}
	}
}

void Screen::updateScreen_Dot(Dot dot) {
	int column = dot.getColumn();
	int row = dot.getRow();
	int newState = dot.getState();
	sollDisplay[row][column]->setState(newState);
}

void Screen::updateScreen_Single(int row, int column, bool newState) {
	sollDisplay[row][column]->setState(newState);
}

void Screen::updateScreen_All(bool newState) {
	for (int disp_row = ROW_MIN; disp_row < ROW_MAX; disp_row++) {
		for (int disp_column = COL_MIN; disp_column < COL_MAX; disp_column++) {
			sollDisplay[disp_row][disp_column]->setState(newState);
		}
	}
}

void Screen::showScreen_Display() {
	for (int disp_row = ROW_MIN; disp_row < ROW_MAX; disp_row++) {
		for (int disp_column = COL_MIN; disp_column < COL_MAX; disp_column++) {
			Dot* sollDot = sollDisplay[disp_row][disp_column];
			Dot* istDot = istDisplay[disp_row][disp_column];
			if (sollDot->getState() != istDot->getState()) {
				bool newState = sollDot->getState();
				istDot->setState(newState);
				addr->loadSR(disp_row, disp_column, newState);
				addr->enable(newState);
			}
		}
	}
}

/*
 * Anzeigen des Ist-Displays in der Konsole (mit Gitter)
 */
void Screen::showIstScreen_Console() {
	cout << "-----------------------------------------------------------"
			<< endl;
	for (int row = ROW_MIN; row < ROW_MAX; row++) {
		cout << "| ";
		for (int column = COL_MIN; column < COL_MAX; column++) {
			cout << (int) istDisplay[row][column]->getState() << " ";
		}
		cout << "|" << endl;
	}
	cout << "-----------------------------------------------------------"
			<< endl;
}

/*
 * Anzeigen des Soll-Displays in der Konsole (mit Gitter)
 */
void Screen::showSollScreen_Console() {
	cout << "-----------------------------------------------------------"
			<< endl;
	for (int row = ROW_MIN; row < ROW_MAX; row++) {
		cout << "| ";
		for (int column = COL_MIN; column < COL_MAX; column++) {
			cout << (int) sollDisplay[row][column]->getState() << " ";
		}
		cout << "|" << endl;
	}
	cout << "-----------------------------------------------------------"
			<< endl;
}

/*
 * Anzeigen des Displays in der Konsole (ohne Gitter)
 */
void Screen::showScreen_Console() {
	cout << "-----------------------------------------------------------"
			<< endl;
	for (int row = ROW_MIN; row < ROW_MAX; row++) {
		cout << "| ";
		for (int column = COL_MIN; column < COL_MAX; column++) {
			if (istDisplay[row][column]->getState() == 1)
				cout << "o ";
			else
				cout << "  ";
		}
		cout << "|" << endl;
	}
	cout << "-----------------------------------------------------------"
			<< endl;
}

/*
 * Auffinden und Löschen vollständiger Reihen
 * Führt nur ein Update auf dem Screen druch -> liegt im sollDisplay!
 */
// TODO In Tetris übernehmen
void Screen::remove_builtColumn() {
	vector<int> built_columns;
	// Auffinden einer vollständigen Reihe (von oben nach unten)
	for (int column = COL_MAX; column != 0; column--) {
		bool built = true;
		for (int row = 0; row < ROW_MAX; row++) {
			if (!istDisplay[row][column]->getState()) {
				built = false;
				break;
			}
		}
		if (!built)
			built_columns.push_back(column);
	}
	// Löschen einer vollständigen Spalte
	// Spalten, die links davon liegen rutschen nach
	for (vector<int>::iterator it = built_columns.begin();
			it != built_columns.end(); it++) {
		int remove_column = *it;
		Segment seg_leftToBuiltColumn = *(new Segment(COL_MIN, ROW_MIN,
				(COL_MAX - remove_column), ROW_MAX));
		for (int column = COL_MIN; column < remove_column; column++) {
			for (int row = ROW_MIN; row < ROW_MIN; row++) {
				bool newState = sollDisplay[row][column]->getState();
				seg_leftToBuiltColumn.change(row, column, newState);
				sollDisplay[row][column]->setState(false);
			}
		}
		seg_leftToBuiltColumn.set_seg_column_start(COL_MIN + 1);
		updateScreen_Segment(seg_leftToBuiltColumn);
	}
}

// TODO In Tetris übernehmen
/*
 * Prüfen, ob Koordinaten des tiefsten Punkts einen Dot berühren
 */
bool Screen::check_hitBuilt(Segment::koordinates koord) {
	int lowestColumn = koord.column.front() + 1;
	for (vector<int>::iterator it_row = koord.row.begin();
			it_row != koord.row.end(); it_row++) {
		return sollDisplay[*it_row][lowestColumn]->getState();
	}
	return true;
}

// TODO In Tetris übernehmen
bool Screen::check_hitTop() {
	for (int row = ROW_MIN; row < ROW_MAX; row++) {
		if (sollDisplay[row][COL_MIN]->getState())
			return true;
	}
	return false;
}

