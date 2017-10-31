/*
 * Screen.cpp
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */

#include "Screen.h"
#include <iostream>

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
void Screen::updateScreen_Segment(Segment segment) {
	int seg_row_height = segment.get_seg_row_height();
	int seg_column_width = segment.get_seg_column_width();
	for (int seg_row = 0; seg_row < seg_row_height; seg_row++) {
		for (int seg_column = 0; seg_column < seg_column_width; seg_column++) {
			// Umrechnen ins Display-Format
			int disp_row = seg_row + segment.get_seg_row_start();
			int disp_column = seg_column + segment.get_seg_column_start();
			bool newState = segment.get_state(seg_row, seg_column);
			sollDisplay[disp_row][disp_column]->setState(newState);
		}
	}
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
				hardwareFlip(disp_row, disp_column, newState);
			}
		}
	}
}

void Screen::showBlackScreen_Display() {
	for (int disp_row = ROW_MIN; disp_row < ROW_MAX; disp_row++) {
		for (int disp_column = COL_MIN; disp_column < COL_MAX; disp_column++) {
			hardwareFlip(disp_row, disp_column, false);
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

void Screen::showInstantSingle(int row, int column, bool newState) {
	istDisplay[row][column]->setState(newState);
	hardwareFlip(row, column, newState);
}

void Screen::showInstantDot(Dot dot) {
	int row=dot.getRow();
	int column=dot.getColumn();
	bool newState=dot.getState();
	istDisplay[row][column]->setState(newState);
	hardwareFlip(row, column, newState);
}

void Screen::hardwareFlip(int row, int column, bool newState) {
	addr->loadSR(row, column, newState);
	addr->enable(newState);
}
