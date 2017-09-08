/*
 * HAL_ShiftRegister.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul, alex
 *
 *  implementiert eine Kette von Schieberegistern mit variabel vielen Schieberegistern.
 *  SRCLK RCLK sind zusammengefasst. Das hießt, dass der Inhalt des Schieberegisters immer einen Takt vor dem
 *  Inhalt des Ausgangsregisters ist. OE ist negiert. -> angesteuerte Pins sind somit:
 *  CLK, SER, nOE
 */

#include "HAL_ShiftRegister.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;

HAL_ShiftRegister::HAL_ShiftRegister() {
	pinMode(CLK_P, OUTPUT);
	pinMode(SER_P, OUTPUT);
	pinMode(D_ENABLE_P, OUTPUT);
	digitalWrite(CLK_P, 0);
	digitalWrite(SER_P, 0);
	digitalWrite(S_ENABLE_P, 1);
}

void HAL_ShiftRegister::loadnWrite(bool inputArray[]) {
	for (int i = 31; i > -1; i--) {
		digitalWrite(SER_P, inputArray[i]);
		shifter(1);
	}
	shifter(1);
}

void HAL_ShiftRegister::enableSR() {
	digitalWrite(S_ENABLE_P, 0);
}

void HAL_ShiftRegister::disableSR() {
	digitalWrite(S_ENABLE_P, 1);
}

void HAL_ShiftRegister::shifter(int amount) {
	for (int i = 0; i < amount; i++) {
		digitalWrite(CLK_P, HIGH);
		digitalWrite(CLK_P, LOW);
	}
}
