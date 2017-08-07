/*
 * ShiftRegister.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul
 *
 *  implementiert eine Kette von Schieberegistern mit variabel vielen Schieberegistern.
 *  SRCLK RCLK sind zusammengefasst. Das hießt, dass der Inhalt des Schieberegisters immer einen Takt vor dem
 *  Inhalt des Ausgangsregisters ist. OE ist negiert. -> angesteuerte Pins sind somit:
 *  CLK, SER, nOE
 */

#include <wiringPi.h>

namespace FlipDot{
	const int ShiftRegister::clkP, ShiftRegister::serP, ShiftRegister::sEnableP;


	ShiftRegister::ShiftRegister(int clkP, int serP, int enableP) {
		this->clkP=clkP;
		this->serP=serP;
		this->sEnableP=enableP;
		pinMode(clkP, OUTPUT);
		pinMode(serP, OUTPUT);
		pinMode(enableP, OUTPUT);
		digitalWrite(clkP,0);
		digitalWrite(serP,0);
		digitalWrite(enableP, 1);
	}

	void ShiftRegister::loadnWrite(bool inputArray[]) {
		for(int i=0; i<sizeof(inputArray);i++) {
			digitalWrite(serP, inputArray[i]);
			delay(10);
			shifter(1);
		}
		shifter(1);
	}

	void ShiftRegister::enableSR() {
		digitalWrite(sEnableP, 0);
		delay(10);
	}

	void ShiftRegister::disableSR() {
		digitalWrite(sEnableP, 1);
		delay(10);
	}

	void ShiftRegister::shifter(int amount) {
		for(int i=0; i<amount; i++) {
			digitalWrite(clkP, HIGH);
			delay(10);
			digitalWrite(clkP, LOW);
			delay(10);
		}
	}


}
