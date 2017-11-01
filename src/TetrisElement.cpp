/*
 * TetrisElement.cpp
 *
 *  Created on: 09.09.2017
 *      Author: alexander
 */

#include "TetrisElement.h"

using namespace std;

TetrisElement::TetrisElement(string type, int seg_size) :
		Segment(0, (8 - seg_size / 2), seg_size, seg_size), element_size(
				seg_size), type(type) {
	if (type == "Block" && seg_size == 2) {
		changeAll(true);
	} else if (type == "I" && seg_size == 4) {
		changeRow(2, true);
	}

	else if (type == "L" && seg_size == 3) {
		changeRow(2, true);
		change(1, 2, true);
	}

	else if (type == "Stair" && seg_size == 3) {
		change(2, 2, true);
		change(1, 2, true);
		change(1, 1, true);
		change(0, 1, true);
	}

	else if (type == "T" && seg_size == 3) {
		change(1, 1, true);
		changeColumn(0, true);
	}

	else {
		cout << "Falschen String bei Elementerzeugung angegeben!" << endl;
	}
}

/*
 * Führt die Bewegung der Segmente aus
 * Rückgabeobjekt ist der Teil des Segments, der gecleart werden soll
 * Für die Bewegung an sich werden nur die Startkoordinaten des Segments manipuliert
 */
Segment* TetrisElement::move_Down(int move_amount) {
	Segment* seg_above = new Segment(seg_column_start, seg_row_start,
			move_amount, seg_row_hight);
	seg_above->changeAll(false);
	seg_column_start += move_amount;
	return seg_above;
}

Segment* TetrisElement::move_Right(int move_amount) {
	Segment* seg_right = new Segment(seg_column_start,
			(seg_row_start + seg_row_hight), move_amount, 1);
	seg_right->changeAll(false);
	seg_row_start -= move_amount;
	return seg_right;
}

Segment* TetrisElement::move_Left(int move_amount) {
	Segment* seg_left = new Segment(seg_column_start, seg_row_start,
			move_amount, 1);
	seg_left->changeAll(false);
	seg_row_start += move_amount;
	return seg_left;
}

void TetrisElement::rotate(int amount) {
	for (int n = amount; n != 0; n--) {
		int e_size = element_size;
		// Kopie von vec_dots erstellen
		vector<vector<bool> > vec_rotate;
		for (int row = 0; row < seg_row_hight; row++) {
			vector<bool> vec_row;
			for (int col = 0; col < seg_column_width; col++) {
				vec_row.push_back(vec_dots[row][col]);
			}
			vec_rotate.push_back(vec_row);
		}
		// eigentliche Rotation
		for (int col = 0; col < e_size; col++) {
			for (int row = 0; row < e_size; row++) {
				vec_dots[col][row] = vec_rotate[e_size - 1 - row][col];
			}
		}
	}
}

/*
 * Tiefsten Punkt im Element lokalisieren (Querformat: am weitesten links)
 * Rückgabe als Koordinaten in Bezug auf das gesamte Display
 */
Segment::koordinates TetrisElement::get_lowestDot() {
	Segment::koordinates koordinates;
	int found = false;
	for (int seg_column = seg_column_width - 1; seg_column != 0; seg_column--) {
		for (int seg_row = 0; seg_row < seg_row_hight; seg_row++) {
			if (vec_dots[seg_row][seg_column]) {
				found = true;
				koordinates.row.push_back(seg_row + seg_row_start);
				koordinates.column.push_back(seg_column + seg_column_start);
			}
		}
		if (found)
			break;
	}
	if (!found) {
		koordinates.row.push_back(-1);
		koordinates.column.push_back(-1);
	}
	return koordinates;
}

