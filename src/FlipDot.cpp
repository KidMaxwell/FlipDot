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

int main() {
	cout << "Programm wird gestartet" << endl;

	int in = 0;

	wiringPiSetup();
	pinMode(enable, OUTPUT);
	pinMode(data, OUTPUT);

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
