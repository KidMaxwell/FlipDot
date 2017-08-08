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
#include "ShiftRegister.h"
#include <iostream>

using namespace std;

//	const int clkP, serP, sEnableP;


	ShiftRegister::ShiftRegister() {
		this->clkP=0;
		this->serP=0;
		this->sEnableP=0;
	}

	void ShiftRegister::Init(int clkP, int serP, int enableP) {
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
		for(int i=31; i>-1; i--) {
			digitalWrite(serP, inputArray[i]);
//			delay(1);
			shifter(1);
		}
		shifter(1);
	}

	void ShiftRegister::enableSR() {
		digitalWrite(sEnableP, 0);
//		delay(1);
	}

	void ShiftRegister::disableSR() {
		digitalWrite(sEnableP, 1);
//		delay(1);
	}

	void ShiftRegister::shifter(int amount) {
		for(int i=0; i<amount; i++) {
			digitalWrite(clkP, HIGH);
//			delay(1);
			digitalWrite(clkP, LOW);
//			delay(1);
		}
	}
