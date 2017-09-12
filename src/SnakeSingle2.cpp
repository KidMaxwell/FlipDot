/*
 * SnakeSingle2.cpp
 *
 *  Created on: 11.09.2017
 *      Author: paul
 */

#include "SnakeSingle2.h"

SnakeSingle2::SnakeSingle2(Screen* scr_p) :
		screen(scr_p) {
	screen->updateScreen_All(false);
	screen->showScreen_Display();
	consoleOutput = true;
	lastDirection = 5;
	alive = true;
	startOrientation = 0;
	apple = NULL;
}

void SnakeSingle2::menu() {
	cout
			<< "Are you sure you want to enter the hazardous yet stunning world of s-s-s-Snake? (y/n)"
			<< endl;
	string in;
	cin >> in;
	if (in == "y") {
		cout << "Your choice!" << endl;
		sleep(1);
		game();
	} else if (in == "n") {
		cout << "Come back when you have the guts!" << endl;
		sleep(3);
		return;
	} else {
		cout << "try again!" << endl;
		menu();
	}
}

void SnakeSingle2::game() {
	cout << "Levelauswahl:" << endl << "\t1: Classic" << endl;
	string in;
	cin >> in;
	if (in == "1") {
		border(1);
	}
	alive = true;
	placeSnake();
	placeApple();
	while (alive) {
		int dir = direction();
		move(dir);
	}
	cout << "GAME OVER!!" << endl << endl;
	TextEditor* textEditor=new TextEditor(screen);
	stringstream out;
	out << "score: " << (snakeVector.size()-START_LENGTH);
	textEditor->stringInput(out.str());

}

void SnakeSingle2::border(int level) {
	if (level == 1) {
		for (int i = COL_MIN; i < COL_MAX; i++) {
			Dot* dot = new Dot(ROW_MIN, i, true);
			borderVector.push_back(dot);
			screen->showInstantDot(*dot);
		}
		for (int i = ROW_MIN + 1; i < ROW_MAX - 1; i++) {
			Dot* dot = new Dot(i, COL_MAX - 1, true);
			borderVector.push_back(dot);
			screen->showInstantDot(*dot);
		}
		for (int i = COL_MIN; i < COL_MAX; i++) {
			Dot* dot = new Dot(ROW_MAX - 1, COL_MAX - 1 - i, true);
			borderVector.push_back(dot);
			screen->showInstantDot(*dot);
		}
		for (int i = ROW_MIN; i < ROW_MAX - 1; i++) {
			Dot* dot = new Dot(ROW_MAX - 1 - i, COL_MIN, true);
			borderVector.push_back(dot);
			screen->showInstantDot(*dot);
		}
		if (consoleOutput) {
			screen->showScreen_Console();
		}
	}
}

void SnakeSingle2::placeApple() {
	int randRow = rand()%14+1;
	int randColumn = rand()%26+1;
	apple = new Dot(randRow, randColumn, true);
	if(checkNewHeadNoSnake(apple)) {
		screen->showInstantDot(*apple);
		if(consoleOutput) {
			screen->showScreen_Console();
		}
	} else {
		placeApple();
	}
}

void SnakeSingle2::placeSnake() {
	srand(time(0));
	int randRow = rand() % 8 + 3;
	int randColumn = rand() % 20 + 3;
	//1: up, 2: right, 3: down, 4: left
	startOrientation = rand() % 4 + 1;
	lastDirection=startOrientation;
	cout << randRow << "\t" << randColumn << "\t" << startOrientation << "\t"
			<< RAND_MAX << endl;
	if (startOrientation == 1) {
		for (int i = 0; i < START_LENGTH; i++) {
			Dot* dot = new Dot(randRow + i, randColumn, true);
			snakeVector.push_back(dot);
			screen->showInstantDot(*dot);
		}
	} else if (startOrientation == 2) {
		for (int i = 0; i < START_LENGTH; i++) {
			Dot* dot = new Dot(randRow, randColumn - i, true);
			snakeVector.push_back(dot);
			screen->showInstantDot(*dot);
		}
	} else if (startOrientation == 3) {
		for (int i = 0; i < START_LENGTH; i++) {
			Dot* dot = new Dot(randRow - i, randColumn, true);
			snakeVector.push_back(dot);
			screen->showInstantDot(*dot);
		}
	} else if (startOrientation == 4) {
		for (int i = 0; i < START_LENGTH; i++) {
			Dot* dot = new Dot(randRow, randColumn + i, true);
			snakeVector.push_back(dot);
			screen->showInstantDot(*dot);
		}
	}
	if (consoleOutput) {
		screen->showScreen_Console();
	}
}

int SnakeSingle2::direction() {
	//TODO Tastensteuerung??
	int dir=startOrientation /*= rand() % 4 + 1*/;

	string input;
	cin >> input;
	if(input.substr(input.length()-1, 1)=="w") {
		dir=1;
	} else if(input.substr(input.length()-1, 1)=="d") {
		dir=2;
	} else if(input.substr(input.length()-1, 1)=="s") {
		dir=3;
	} else if(input.substr(input.length()-1, 1)=="a") {
		dir=4;
	} else {
		dir=lastDirection;
	}

	if (lastDirection - 2 == dir || lastDirection + 2 == dir) {
		dir = lastDirection;
	}
	lastDirection = dir;
	return dir;
}

void SnakeSingle2::move(int dir) {
	Dot* head = snakeVector.front();
	Dot* newHead;
	if (dir == 1) {
		newHead = new Dot(head->getRow() - 1, head->getColumn(), true);
	} else if (dir == 2) {
		newHead = new Dot(head->getRow(), head->getColumn() + 1, true);
	} else if (dir == 3) {
		newHead = new Dot(head->getRow() + 1, head->getColumn(), true);
	} else if (dir == 4) {
		newHead = new Dot(head->getRow(), head->getColumn() - 1, true);
	}
	if (checkNewHeadNoBorder(newHead)&&checkNewHeadNoSnake(newHead)) {
		snakeVector.insert(snakeVector.begin(), newHead);
		screen->showInstantDot(*newHead);
		if (checkNewHeadNoApple(newHead)) {
			Dot* tail = snakeVector.back();
			tail->setState(false);
			screen->showInstantDot(*tail);
			snakeVector.pop_back();
		} else {
			placeApple();
		}
		if (consoleOutput) {
			screen->showScreen_Console();
		}
	} else {
		alive = false;
	}
}

bool SnakeSingle2::checkNewHeadNoSnake(Dot* newHead) {
	bool noSnake = true;
	for(unsigned int i=0 ; i<snakeVector.size(); i++) {
		if(snakeVector.at(i)->getRow()==newHead->getRow()&&snakeVector.at(i)->getColumn()==newHead->getColumn()) {
			noSnake=false;
		}
	}
	return noSnake;
}

bool SnakeSingle2::checkNewHeadNoBorder(Dot* newHead) {
	bool noBorder = true;
	for(unsigned int i=0 ; i<borderVector.size(); i++) {
		if(borderVector.at(i)->getRow()==newHead->getRow()&&borderVector.at(i)->getColumn()==newHead->getColumn()) {
			noBorder=false;
		}
	}
	return noBorder;
}

bool SnakeSingle2::checkNewHeadNoApple(Dot* newHead) {
	bool noApple = true;
	if(apple->getRow()==newHead->getRow()&&apple->getColumn()==newHead->getColumn()) {
		noApple = false;
	}
	return noApple;
}


