/*
 * HALAdressing.cpp
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */
#include "HAL_Addr.h"
#include <wiringPi.h>
#include "HAL_HardwareDefines.h"

using namespace std;

HAL_Addr::HAL_Addr() {
	wiringPiSetup();
	pinMode(D_ENABLE_P, OUTPUT);
	digitalWrite(D_ENABLE_P, 0);
	pinMode(D_DP, OUTPUT);
	digitalWrite(D_DP, 0);
}

void HAL_Addr::enable(bool newState) {
	sr.enableSR();
	digitalWrite(D_DP, !newState);
	delay(1);
	digitalWrite(D_ENABLE_P, 1);
	delay(10);
	digitalWrite(D_ENABLE_P, 0);
	sr.disableSR();
}

void HAL_Addr::loadSR(int row, int column, bool newState) {
	bool inputArray[32];
	for (int i = 0; i < 32; i++) {
		inputArray[i] = false;
	}
// Auswählen der Zeile
	for (int i = 0; i < row; i++) {
		inputArray[16 + i] = !newState;
	}
	inputArray[16 + row] = newState;
	for (int i = (row + 1); i < 16; i++) {
		inputArray[16 + i] = !newState;
	}
// Zeilen Enable
	inputArray[8 + ((row) / 2)] = true;
// Auswählen der Spalte
	switch (column) {
	case 0:
		inputArray[0] = true;
		break;
	case 1:
		inputArray[1] = true;
		break;
	case 2:
		inputArray[0] = true;
		inputArray[1] = true;
		break;
	case 3:
		inputArray[2] = true;
		break;
	case 4:
		inputArray[0] = true;
		inputArray[2] = true;
		break;
	case 5:
		inputArray[1] = true;
		inputArray[2] = true;
		break;
	case 6:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[2] = true;
		break;
	case 7:
		inputArray[0] = true;
		inputArray[3] = true;
		break;
	case 8:
		inputArray[1] = true;
		inputArray[3] = true;
		break;
	case 9:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[3] = true;
		break;
	case 10:
		inputArray[2] = true;
		inputArray[3] = true;
		break;
	case 11:
		inputArray[0] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		break;
	case 12:
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		break;
	case 13:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		break;
	case 14:
		inputArray[0] = true;
		inputArray[4] = true;
		break;
	case 15:
		inputArray[1] = true;
		inputArray[4] = true;
		break;
	case 16:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[4] = true;
		break;
	case 17:
		inputArray[2] = true;
		inputArray[4] = true;
		break;
	case 18:
		inputArray[0] = true;
		inputArray[2] = true;
		inputArray[4] = true;
		break;
	case 19:
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[4] = true;
		break;
	case 20:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[4] = true;
		break;
	case 21:
		inputArray[0] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 22:
		inputArray[1] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 23:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 24:
		inputArray[2] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 25:
		inputArray[0] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 26:
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	case 27:
		inputArray[0] = true;
		inputArray[1] = true;
		inputArray[2] = true;
		inputArray[3] = true;
		inputArray[4] = true;
		break;
	default:
		break;
	}
	sr.loadnWrite(inputArray);
}
