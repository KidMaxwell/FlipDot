/*
 * FlipDot.cpp
 *
 *  Created on: 21.05.2017
 *      Author: paul
 */

#include <stdio.h>
#include <string>
#include <wiringPi.h>
#include <iostream>

using namespace std;

#define enable 0
#define data 1
#define a0 2
#define a1 3
#define a2 4
#define b1 5
#define b2 6

int main() {
	cout << "Programm wird gestartet" << endl;

	int in = 0;

	wiringPiSetup();

	for (int i=0; i<7; i++) {
		pinMode(i, OUTPUT);
		digitalWrite(i, 0);
	}

	for (;;) {
		cout << "Data:" << endl;
		cin >> in;
		if (in == 1) {
			cout << "Data -> " << in << endl;
			digitalWrite(data, in);
		} else if (in == 0) {
			cout << "Data -> " << in << endl;
			digitalWrite(data, in);
		} else {
			cout << "Erbitte 1 oder 0 " << endl;
			break;
		}
		cout << "Enable: " << endl;
		for (int i = 0; i == 0 || i == 1;) {
			cin >> in;
			i = in;
			if (in == 1) {
				cout << "Enable -> " << in << endl;
				digitalWrite(enable, in);
			} else if (in == 0) {
				cout << "Enable -> " << in << endl;
				digitalWrite(enable, in);
			} else {
				cout << "Erbitte 1 oder 0 " << endl;
			}
		}

	}
	return 0;
}

void selectColumn(string column) {

	for (int i=0; i<7; i++) {
			digitalWrite(i, 0);
		}

	switch(column) {
	case 'aa':
		digitalWrite(a0, 1);
		break;
	case 'ab':
		digitalWrite(a1, 1);
		break;
	case 'ac':
		digitalWrite(a0, 1);
		digitalWrite(a1, 1);
		break;
	case 'ad':
		digitalWrite(a2, 1);
		break;
	case 'ae':
		digitalWrite(a0, 1);
		digitalWrite(a2, 1);
		break;
	case 'af':
		digitalWrite(a1, 1);
		digitalWrite(a2, 1);
		break;
	case 'ag':
		digitalWrite(a0, 1);
		digitalWrite(a1, 1);
		digitalWrite(a2, 1);
		break;
	case 'ah':
		digitalWrite(a0, 1);
		digitalWrite(b1, 1);
		break;
	case 'ai':
		digitalWrite(a1, 1);
		digitalWrite(b1, 1);
		break;
	case 'aj':
		digitalWrite(a0, 1);
		digitalWrite(a1, 1);
		digitalWrite(b1, 1);
		break;
	case 'ak':
		digitalWrite(a2, 1);
		digitalWrite(b1, 1);
		break;
	case 'al':
		digitalWrite(a0, 1);
		digitalWrite(a2, 1);
		digitalWrite(b1, 1);
		break;
	case 'am':
		digitalWrite(a1, 1);
		digitalWrite(a2, 1);
		digitalWrite(b1, 1);
		break;
	case 'an':
		digitalWrite(a0, 1);
		digitalWrite(a1, 1);
		digitalWrite(a2, 1);
		digitalWrite(b1, 1);
		break;
	case 'ao':
		digitalWrite(a0, 1);
		digitalWrite(b2, 1);
		break;
	case 'ap':
		digitalWrite(a1, 1);
		digitalWrite(b2, 1);
		break;
	case 'aq':
		digitalWrite(a0, 1);
		digitalWrite(a1, 1);
		digitalWrite(b2, 1);
		break;
	case 'ar':
		digitalWrite(a2, 1);
		digitalWrite(b2, 1);
		break;
	case 'as':
		digitalWrite(a0, 1);
		digitalWrite(a2, 1);
		digitalWrite(b2, 1);
		break;
	case 'at':
		digitalWrite(a1, 1);
		digitalWrite(a2, 1);
		digitalWrite(b2, 1);
		break;
	case 'au':
		digitalWrite(a0, 1);
		digitalWrite(a1, 1);
		digitalWrite(a2, 1);
		digitalWrite(b2, 1);
		break;
	case 'av':
		digitalWrite(a0, 1);
		digitalWrite(b1, 1);
		digitalWrite(b2, 1);
		break;
	case 'aw':
		digitalWrite(a1, 1);
		digitalWrite(b1, 1);
		digitalWrite(b2, 1);
		break;
	case 'ax':
		digitalWrite(a0, 1);
		digitalWrite(a1, 1);
		digitalWrite(b1, 1);
		digitalWrite(b2, 1);
		break;
	case 'ay':
		digitalWrite(a2, 1);
		digitalWrite(b1, 1);
		digitalWrite(b2, 1);
		break;
	case 'az':
		digitalWrite(a0, 1);
		digitalWrite(a2, 1);
		digitalWrite(b1, 1);
		digitalWrite(b2, 1);
		break;
	case 'ba':
		digitalWrite(a1, 1);
		digitalWrite(a2, 1);
		digitalWrite(b1, 1);
		digitalWrite(b2, 1);
		break;
	case 'bb':
		digitalWrite(a0, 1);
		digitalWrite(a1, 1);
		digitalWrite(a2, 1);
		digitalWrite(b1, 1);
		digitalWrite(b2, 1);
		break;
	default:
		cout<< 'incorrect column value' << endl;
	}


}
