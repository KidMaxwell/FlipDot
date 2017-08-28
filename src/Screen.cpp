/*
 * Screen.cpp
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */

#include "Screen.h"
#include <iostream>

using namespace std;

Screen::Screen() {
	for (int r = 0; r < ROW_MAX; r++) {
		for (int c = 0; c < COL_MAX; c++) {
			screenArray[r][c] = 0;
		}
	}
}

void Screen::updateScreen(int row, int column, int state) {
	screenArray[row][column] = state;
}

void Screen::showScreen() {
	cout << "------------------------------" << endl;
	for (int r = 0; r < ROW_MAX; r++) {
		cout << "|";
		for (int c = 0; c < COL_MAX; c++) {
			cout << screenArray[r][c];
		}
		cout << "|" << endl;
	}
	cout << "------------------------------" << endl;
}

