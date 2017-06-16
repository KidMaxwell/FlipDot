/*
 * FlipDot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul
 */

#include <Dot.h>
#include <stdio.h>
#include <string>
#include <wiringPi.h>
#include <iostream>

using namespace std;

#define enableP 0
/*
*/


class FlipDot
{
	//2D Array mit allen Dots
	Dot dots[16][28];

	FlipDot::FlipDot() {
		wiringPiSetup();

		//alle Dots erstellen und in dots Array speichern
		for(int r=0; r<16;r++){
			for(int c=0; c<28; c++) {
				dots[r][c]=new Dot(r, c, false);
			}
		}
	}

	void FlipDot::start() {

	}

	void FlipDot::changeIfDifferent(Dot d, bool newState) {
		bool oldState=d.getState();
		if(oldState!=newState) {
			change(d.getRow(), d.getColumn(), newState);
		}
	}

	void FlipDot::changeAll(bool newState) {
		for(Dot d:dots) {
			change(d.getRow(), d.getColumn(), newState);
		}
	}

	void FlipDot::change(int row, int column, bool newState) {
		selectAdress(row, column, newState);
		enable();
	}

	void FlipDot::selectAdress(int row, int column, bool newState) {

	}

	void FlipDot::enable() {
		digitalWrite(enableP, 1);
		delay(10);
		digitalWrite(enableP, 0);
		delay(10);
	}

};

int main() {
	FlipDot f = new FlipDot();
	f.start();

	return 0;
}
