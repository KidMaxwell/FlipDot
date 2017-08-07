/*
 * FlipDot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul
 */

#include <Dot.h>
#include <ShiftRegister.h>
#include <stdio.h>
#include <string>
#include <wiringPi.h>
#include <iostream>

using namespace std;
using namespace FlipDot;

#define dEnableP 0
#define dD 1
#define clkP 2
#define serP 3
#define sEnableP 4
/*
 */

	//2D Array mit allen Dots
	Dot dots[16][28];
	ShiftRegister SR;
	int row, column, newStateI;
	bool newState;

	/* Konstruktor der Klasse FlipDot
	 * initialisiert wiringPi und das 2D Array
	 * setzt den pinMode von enableP auf OUTPUT
	 */
	void Init() {
		cout << "Programm wird gestartet" << endl;
		wiringPiSetup();
		pinMode(dEnableP, OUTPUT);
		digitalWrite(dEnableP, 0);
		//alle Dots erstellen und in dots Array speichern
		for (int r = 0; r < 16; r++) {
			for (int c = 0; c < 28; c++) {
				dots[r][c] = new Dot(r, c, false);
			}
		}
		newStateI=0;
		row=0;
		column=0;
		newState=false;
		SR=new ShiftRegister(clkP, serP, sEnableP);
	}

	void start() {
		for(;;) {
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

	void changeIfDifferent(Dot d, bool newState) {
		bool oldState = d.getState();
		if (oldState != newState) {
			change(d.getRow(), d.getColumn(), newState);
		}
	}

	void changeAll(bool newState) {
		for (Dot d : dots) {
			change(d.getRow(), d.getColumn(), newState);
		}
	}

	void change(int row, int column, bool newState) {
		dots[row][column].setState(newState);
		loadSR(row, column, newState);
		enable();
	}

	void loadSR(int row, int column, bool newState) {
		bool inputArray [32]=false;
		// Auswählen der Zeile
		for(int i=1; i<row; i++) {
			inputArray[15+i]=!newState;
		}
		inputArray[15+row]=newState;
		for(int i=(row+1); i<17; i++) {
			inputArray[15+i]=!newState;
		}
		// Zeilen Enable
		inputArray[7+((row+1)/2)]=true;
		// Auswählen der Spalte
		switch(column) {
		case 1:
			inputArray[0]=true;
			break;
		case 2:
			inputArray[1]=true;
			break;
		case 3:
			inputArray[0]=true;
			inputArray[1]=true;
			break;
		case 4:
			inputArray[2]=true;
			break;
		case 5:
			inputArray[0]=true;
			inputArray[2]=true;
			break;
		case 6:
			inputArray[1]=true;
			inputArray[2]=true;
			break;
		case 7:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[2]=true;
			break;
		case 8:
			inputArray[0]=true;
			inputArray[3]=true;
			break;
		case 9:
			inputArray[1]=true;
			inputArray[3]=true;
			break;
		case 10:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[3]=true;
			break;
		case 11:
			inputArray[2]=true;
			inputArray[3]=true;
			break;
		case 12:
			inputArray[0]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			break;
		case 13:
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			break;
		case 14:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			break;
		case 15:
			inputArray[0]=true;
			inputArray[4]=true;
			break;
		case 16:
			inputArray[1]=true;
			inputArray[4]=true;
			break;
		case 17:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[4]=true;
			break;
		case 18:
			inputArray[2]=true;
			inputArray[4]=true;
			break;
		case 19:
			inputArray[0]=true;
			inputArray[2]=true;
			inputArray[4]=true;
			break;
		case 20:
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[4]=true;
			break;
		case 21:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[4]=true;
			break;
		case 22:
			inputArray[0]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 23:
			inputArray[1]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 24:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 25:
			inputArray[2]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 26:
			inputArray[0]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 27:
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		case 28:
			inputArray[0]=true;
			inputArray[1]=true;
			inputArray[2]=true;
			inputArray[3]=true;
			inputArray[4]=true;
			break;
		default:
			break;
		}
		SR.loadnWrite(inputArray);
	}

	void enable() {
		SR.enableSR();
		delay(10);
		digitalWrite(dEnableP, 1);
		delay(10);
		digitalWrite(dEnableP, 0);
		delay(10);
		SR.disableSR();
		delay(10);
	}


int main() {
	Init();
	start();
	return 0;
}
