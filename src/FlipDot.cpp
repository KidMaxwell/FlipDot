/*
 * FlipDot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul, alex
 */

#include "Dot.h"
#include "ShiftRegister.h"
#include "FlipDot.h"
#include <string>
#include <wiringPi.h>
#include <iostream>

using namespace std;

#define dEnableP 0
#define dDP 1
#define clkP 2
#define serP 3
#define sEnableP 4
/*
 */

	//2D Array mit allen Dots
//	Dot dots[16][28];
//	ShiftRegister SR;
//	int row, column, newStateI;
//	bool newState;

	/* Konstruktor der Klasse FlipDot
	 * initialisiert wiringPi und das 2D Array
	 * setzt den pinMode von enableP auf OUTPUT
	 */
	FlipDot::FlipDot() {
		cout << "Programm wird gestartet" << endl;
		wiringPiSetup();
		pinMode(dEnableP, OUTPUT);
		digitalWrite(dEnableP, 0);
		pinMode(dDP, OUTPUT);
		digitalWrite(dDP, 0);
		//alle Dots erstellen und in dots Array speichern
		for (int r = 0; r < 16; r++) {
			for (int c = 0; c < 28; c++) {
				dots[r][c].set(r, c, false);
			}
		}
		newStateI=0;
		row=0;
		column=0;
		newState=false;
		SR.Init(clkP, serP, sEnableP);
	}

	void FlipDot::start() {
		for(;;) {
			for (int r = 0; r < 16; r++) {
				for (int c = 0; c < 28; c++) {
					cout << dots[r][c].getState();
				}
				cout << endl;
			}
			int a= 0;
			cout << "all?:" <<endl;
			cin>> a;
			if(a==1) {
				int b=0;
				cout << "an/aus?:" << endl;
				cin>> b;
				changeAll((bool)b);
			}
			else {
				cout << "Row:" << endl;
				cin >> row;
				cout << "Column:" << endl;
				cin >> column;
				cout << "NewState:" << endl;
				cin >> newStateI;
				newState=(bool)newStateI;
				change(row, column, newState);
			}
		}
	}

	void FlipDot::changeIfDifferent(Dot d, bool newState) {
		bool oldState = d.getState();
		if (oldState != newState) {
			change(d.getRow(), d.getColumn(), newState);
		}
	}

	void FlipDot::changeAll(bool newState) {
		//for (int r = 0; r < 16; r++) {
			for (int c = 0; c < 28; c++) {
				change(0, c, newState);
			}
		//}
	}

	void FlipDot::change(int row, int column, bool newState) {
		this->newState=newState;
		dots[row][column].setState(newState);
		loadSR(row, column, newState);
		enable();
	}

	void FlipDot::loadSR(int row, int column, bool newState) {
		bool inputArray[32];
		for(int i=0; i<32; i++) {
			inputArray[i]=false;
		}
		// Auswählen der Zeile
		for(int i=0; i<row; i++) {
			inputArray[16+i]=!newState;
		}
		inputArray[16+row]=newState;
		for(int i=(row+1); i<16; i++) {
			inputArray[16+i]=!newState;
		}
		// Zeilen Enable
		inputArray[8+((row)/2)]=true;
		// Auswählen der Spalte
		switch(column) {
		case 0:
			inputArray[0]=true;
			break;
		case 1:
			inputArray[1]=true;
			break;
		case 2:
			inputArray[0]=true;
			inputArray[1]=true;
			break;
		case 3:
			inputArray[2]=true;
			break;
		case 4:
			inputArray[0]=true;
			inputArray[2]=true;
			break;
		case 5:
			inputArray[1]=true;
			inputArray[2]=true;
			break;
		case 6:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[2]=true;
			break;
		case 7:
			inputArray[0]=true;
			inputArray[3]=true;
			break;
		case 8:
			inputArray[1]=true;
			inputArray[3]=true;
			break;
		case 9:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[3]=true;
			break;
		case 10:
			inputArray[2]=true;
			inputArray[3]=true;
			break;
		case 11:
			inputArray[0]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			break;
		case 12:
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			break;
		case 13:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			break;
		case 14:
			inputArray[0]=true;
			inputArray[4]=true;
			break;
		case 15:
			inputArray[1]=true;
			inputArray[4]=true;
			break;
		case 16:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[4]=true;
			break;
		case 17:
			inputArray[2]=true;
			inputArray[4]=true;
			break;
		case 18:
			inputArray[0]=true;
			inputArray[2]=true;
			inputArray[4]=true;
			break;
		case 19:
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[4]=true;
			break;
		case 20:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[4]=true;
			break;
		case 21:
			inputArray[0]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 22:
			inputArray[1]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 23:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 24:
			inputArray[2]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 25:
			inputArray[0]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 26:
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 27:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		default:
			break;
		}
//		cout << "###" << endl;
//		for(int i=0; i<32; i++) {
//			cout << (int)inputArray[i];
//		}
//		cout << endl;
//		cout << "###" << endl;
//		cout << (int)!newState << endl;
//		cout << "###" << endl;
		SR.loadnWrite(inputArray);
	}

	void FlipDot::enable() {
		SR.enableSR();
		digitalWrite(dDP, !newState);
		delay(1);
		digitalWrite(dEnableP, 1);
		delay(10);
		digitalWrite(dEnableP, 0);
		SR.disableSR();
	}


int main() {
	FlipDot f;
	f.start();
	return 0;
}
