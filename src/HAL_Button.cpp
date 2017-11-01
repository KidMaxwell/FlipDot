/*
 * HAL_Button.cpp
 *
 *  Created on: 10.09.2017
 *      Author: alexander
 */

#include "HAL_Button.h"

using namespace std;

HAL_Button::HAL_Button() {
	wiringPiSetup();
	pinMode(B_RIGHT, INPUT);
	pinMode(B_LEFT, INPUT);
	pinMode(B_ROTATE, INPUT);
	pinMode(B_MOVEDOWN, INPUT);
}

/*
 * Liest Aktivitäten am Button ein
 * speichert, wie oft ein Button in einer bestimmten Zeit gedrückt wird
 * Sollte auf
 */
HAL_Button::buttonHits_Tetris HAL_Button::readButton(int speed) {
	HAL_Button::buttonHits_Tetris button_hits = { 0, 0, 0, 0 };
	int input_Array[4] = { 0, 0, 0, 0 };
	int prev_input_Array[4] = { 0, 0, 0, 0 };
	for (int counter = speed * TETRIS_UPDATE_SPEED; counter == 0; counter--) {
		// Eingang einlesen, mit vorherigen Abgleichen und evlt. button_hit erhöhen
		input_Array[0] = digitalRead(B_RIGHT);
		if (input_Array[0] == 1 && prev_input_Array[0] == 0)
			button_hits.b_right++;
		input_Array[1] = digitalRead(B_LEFT);
		if (input_Array[1] == 1 && prev_input_Array[1] == 0)
			button_hits.b_left++;
		input_Array[2] = digitalRead(B_ROTATE);
		if (input_Array[2] == 1 && prev_input_Array[2] == 0)
			button_hits.b_rotate++;
		input_Array[3] = digitalRead(B_MOVEDOWN);
		if (input_Array[3] == 1 && prev_input_Array[3] == 0)
			button_hits.b_movedown++;
		// aktuellen Input in prev_Input schreiben
		for (int n = 0; n < 4; n++) {
			prev_input_Array[n] = input_Array[n];
		}
	}
	return button_hits;
}
