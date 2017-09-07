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
	for (int r = 0; r < ROW_MAX; r++) {
		for (int c = 0; c < COL_MAX; c++) {
			consoleArray[r][c] = 0;
		}
	}
}

void Screen::updateScreen_Segment(Segment segment) {
	int seg_row_hight = segment.get_seg_row_hight();
	int seg_column_width = segment.get_seg_column_width();
	for (int seg_row = 0; seg_row < seg_row_hight; seg_row++) {
		for (int seg_column = 0; seg_column < seg_column_width; seg_column++) {
			int disp_row = seg_row_hight + segment.get_seg_row_start();
			int disp_column = seg_column_width + segment.get_seg_column_start();
			bool newState = segment.get_state(seg_row, seg_column);
			sollDisplay[disp_row][disp_column]->setState(newState);
		}
	}
}

void Screen::updateScreen_Single(int row, int column, bool newState) {
	sollDisplay[row][column] = newState;
}

void Screen::updateScreen_All(bool newState) {
	for (int disp_row = ROW_MIN; disp_row < ROW_MAX; disp_row++) {
		for (int disp_column = COL_MIN; disp_column < COL_MAX; disp_column++) {
			sollDisplay[disp_row][disp_column] = newState;
		}
	}
}

void Screen::showIstScreen_Console() {
	cout << "------------------------------" << endl;
	for (int row = 0; row < ROW_MAX; row++) {
		cout << "|";
		for (int column = 0; column < COL_MAX; column++) {
//			int state_int = (int) istDisplay[row][column]->getState();
			// TODO nochmal testen
			cout << (int) istDisplay[row][column]->getState() << " ";
		}
		cout << "|" << endl;
	}
	cout << "------------------------------" << endl;
}

void Screen::showSollScreen_Console() {
	cout << "------------------------------" << endl;
	for (int row = 0; row < ROW_MAX; row++) {
		cout << "|";
		for (int column = 0; column < COL_MAX; column++) {
//			int state_int = (int) istDisplay[row][column]->getState();
			// TODO nochmal testen
			cout << (int) sollDisplay[row][column]->getState() << " ";
		}
		cout << "|" << endl;
	}
	cout << "------------------------------" << endl;
}

void Screen::showScreen_Display() {
	for (int disp_row = ROW_MIN; disp_row < ROW_MAX; disp_row++) {
		for (int disp_column = COL_MIN; disp_column < COL_MAX; disp_column++) {
			Dot sollDot = *sollDisplay[disp_row][disp_column];
			Dot istDot = *istDisplay[disp_row][disp_column];
			if (sollDot.getState() != istDot.getState()) {
				bool newState = sollDot.getState();
				istDot.setState(newState);
				addr->loadSR(disp_row, disp_column, newState);
				addr->enable(newState);
			}
		}
	}
}
