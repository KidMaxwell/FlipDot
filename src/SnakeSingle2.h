/*
 * SnakeSingle2.h
 *
 *  Created on: 11.09.2017
 *      Author: paul
 */

#ifndef SRC_SNAKESINGLE2_H_
#define SRC_SNAKESINGLE2_H_

#include "Screen.h"
#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
#include "Dot.h"
#include <vector>
#include "HAL_HardwareDefines.h"
#include <cstdlib>

using namespace std;

#define BORD_DELAY 1E6
#define START_LENGTH 3

class SnakeSingle2 {
public:
	SnakeSingle2(Screen* scr_p);
	void menu();
private:
	Screen* screen;
	void game();
	void border(int level);
	void placeSnake();
	void placeApple();
	int direction();
	void move(int dir);
	bool checkNewHeadNoBorder(Dot* newHead);
	bool checkNewHeadNoApple(Dot* newHead);
	bool checkNewHeadNoSnake(Dot* newHead);
	vector<Dot*> borderVector;
	vector<Dot*> snakeVector;
	bool consoleOutput;
	int lastDirection;
	bool alive;
	Dot* apple;
	int startOrientation;
};



#endif /* SRC_SNAKESINGLE2_H_ */
