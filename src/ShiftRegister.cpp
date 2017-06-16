/*
 * ShiftRegister.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul
 */

#include <stdio.h>
#include <string>
#include <wiringPi.h>
#include <iostream>

using namespace std;

/*
#define data1P 1
#define data2P 2
*/
#define shift 3
/*
#define enableSR1P 4
#define enableSR2P 5
*/

class ShiftRegister
{
	const int queued, dataP, enableP, maxPossible;


	ShiftRegister::ShiftRegister(int queued, int dataP, int enableP) {
		this->queued=queued;
		this->dataP=dataP;
		this->enableP=enableP;
		maxPossible=(queued*8)--;
	}

	void ShiftRegister::loadnWrite(int selectedNumber) {
		if(selectedNumber>maxPossible) {
			cout << "Obacht, dieses Element kann nicht ausgewaehlt werden (selectedNumber>maxPossible)" << endl;
		}
		else {

		}
	}
};
