/*
 * SnakeSingle.h
 *
 *  Created on: 31.08.2017
 *      Author: alexander
 */

#ifndef SNAKESINGLE_H_
#define SNAKESINGLE_H_
#include "Dot.h"
#include "Screen.h"
#include "Segment.h"
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

class SnakeSingle {
public:
	SnakeSingle(Screen *scr_p);
	void consoleMenu();
	void runSnake(int speed);
	bool moveStraight();
	bool moveRight();
	bool moveLeft();
	bool biten(int head_column, int head_row);
	void placeCookie();

private:
	int head_column, head_row, tail_column, tail_row;
	Screen* screen_p;
	Segment* seg_FullScreen;
	std::vector<Dot> *vec_snake;
	std::string movingDirection;
	Dot* cookie;
};

#endif /* SNAKESINGLE_H_ */
