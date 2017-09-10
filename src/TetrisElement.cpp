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
				seg_size) {
	if (type == "Block" && seg_size == 2) {
		changeAll(true);
	} else if (type == "I" && seg_size == 4) {
		changeRow(2, true);
	}

	else if (type == "L" && seg_size == 3) {
		changeRow(2, true);
		change(1, 3, true);
	}

	else if (type == "Stair" && seg_size == 3) {
		change(2, 2, true);
		change(1, 2, true);
		change(1, 1, true);
		change(0, 1, true);
	}

	else if (type == "T" && seg_size == 3) {
		changeRow(1, true);
		changeColumn(0, true);
	}

	else {
		cout << "Falschen String bei Elementerzeugung angegeben!" << endl;
	}
}

void TetrisElement::move_Down(int move_amount) {
	seg_column_start += move_amount;
}

void TetrisElement::move_Right(int move_amount) {
	seg_row_start -= move_amount;
}
void TetrisElement::move_Left(int move_amount) {
	seg_row_start += move_amount;
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
		// 'break' bewusst weggelassen, dass an der entsprechenden Stelle begonnen wird
		switch (e_size) {
		case 4:
			// Querformat
			// linke Reihe
			vec_dots[e_size - 4][e_size - 4] =
					vec_rotate[e_size - 4][e_size - 1];
			vec_dots[e_size - 3][e_size - 4] =
					vec_rotate[e_size - 4][e_size - 2];
			vec_dots[e_size - 2][e_size - 4] =
					vec_rotate[e_size - 4][e_size - 3];
			vec_dots[e_size - 1][e_size - 4] =
					vec_rotate[e_size - 4][e_size - 4];
			// obere Reihe
			vec_dots[e_size - 4][e_size - 3] =
					vec_rotate[e_size - 3][e_size - 1];
			vec_dots[e_size - 4][e_size - 2] =
					vec_rotate[e_size - 2][e_size - 1];
			// rechte Reihe
			vec_dots[e_size - 4][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 4];
			vec_dots[e_size - 3][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 3];
			vec_dots[e_size - 2][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 2];
			vec_dots[e_size - 1][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 1];
			// untere Reihe
			vec_dots[e_size - 1][e_size - 2] =
					vec_rotate[e_size - 2][e_size - 4];
			vec_dots[e_size - 1][e_size - 3] =
					vec_rotate[e_size - 3][e_size - 4];
			e_size--;
		case 3:
			// linke Reihe
			vec_dots[e_size - 3][e_size - 3] =
					vec_rotate[e_size - 3][e_size - 1];
			vec_dots[e_size - 2][e_size - 3] =
					vec_rotate[e_size - 3][e_size - 2];
			vec_dots[e_size - 1][e_size - 3] =
					vec_rotate[e_size - 3][e_size - 3];
			// obere Reihe
			vec_dots[e_size - 3][e_size - 2] =
					vec_rotate[e_size - 2][e_size - 1];
			// rechte Reihe
			vec_dots[e_size - 3][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 3];
			vec_dots[e_size - 2][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 2];
			vec_dots[e_size - 1][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 1];
			// untere Reihe
			vec_dots[e_size - 1][e_size - 2] =
					vec_rotate[e_size - 2][e_size - 4];
			e_size--;
		case 2:
			// linke Reihe
			vec_dots[e_size - 2][e_size - 2] =
					vec_rotate[e_size - 2][e_size - 1];
			vec_dots[e_size - 1][e_size - 2] =
					vec_rotate[e_size - 2][e_size - 2];
			// rechte Reihe
			vec_dots[e_size - 2][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 2];
			vec_dots[e_size - 1][e_size - 1] =
					vec_rotate[e_size - 1][e_size - 1];
		}
	}
}

