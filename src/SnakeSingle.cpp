/*
 * SnakeSingle.cpp
 *
 *  Created on: 31.08.2017
 *      Author: alexander
 */

#include "SnakeSingle.h"
#include "HAL_HardwareDefines.h"

#define UPDATE_TIME 1E5

using namespace std;

SnakeSingle::SnakeSingle(Screen* scr_p) :
		screen_p(scr_p), head_column(0), head_row(0), tail_column(0), tail_row(
				0), seg_FullScreen(
				new Segment(COL_MIN, ROW_MIN, COL_MAX, ROW_MAX)), vec_snake(0), movingDirection(
				"H-R"),	//Horizontal - Rechts
		cookie(0)
{
	for (int col = 0; col < 6; col++) {
		vec_snake->push_back(new Dot(7, col, true));
	}
}

void SnakeSingle::consoleMenu() {
	int speed = 0;
	cout << "Herzlich willkommen beim Single Player des Spiels Snake" << endl;
	while (1) {
		cout << "Geben Sie den Schwierigkeitsgrad (1-10) an" << endl
				<< "(Abbruch durch eine nicht valide Eingabe)" << endl;
		cin >> speed;
		if (speed < 1 || speed > 10)
			break;
		runSnake(speed * UPDATE_TIME);
		cout << "Nochmal?" << endl;
	}
	cout << endl << "Auf Wiedersehen!" << endl;
}

void SnakeSingle::runSnake(int speed) {
	while (1) {
		usleep(speed);
		//TODO Keyboard read
		// Erstes Element der Snake (in dem Fall "back" des Vectors)
		Dot* head = vec_snake->back();
		head_column = head->getColumn();
		head_row = head->getRow();
		// Letztes Element der Snake
		Dot* tail = vec_snake->front();
		tail_column = tail->getColumn();
		tail_row = tail->getRow();
		bool wall = false;
		//Je nach Keyboardeingabe andere Methode
		// ...
		//Aufruf in der Form:
		if (!moveStraight())
			wall = true;

		if (wall == true)
			break;
		seg_FullScreen->change(head_row, head_column, true);
		seg_FullScreen->change(tail_row, tail_column, false);
//TODO Auf jeden Fall testen, ob das mit dem Entfernen funktioniert!
		int size = vec_snake->size();
		vec_snake->push_back(new Dot(head_row, head_column, true));
		vec_snake->erase(vec_snake->begin());
		cout << "Test: Grösse vorher: " << size << endl << "Jetzt: "
				<< vec_snake->size() << endl;
		if (biten(head_column, head_row))
			break;
	}
	cout << "Es wurde eine Wand getroffen" << endl << "das Spiel wird beendet"
			<< endl;
}
/*
 * Geradlienige Bewegung
 * 	2 wichtige Parameter: Position des Kopfs und Bewegungsrichtung
 * 	Mit dem Kopf wird getestet, ob eine Wand berühurt wird und die
 * 	Bewegungsrichtung gitb vor wo der nächste Dot zu setzen ist
 * 	Abschließend wird geprüft, ob die Schlange sich selbst bebissen hat
 */
bool SnakeSingle::moveStraight() {
	if (movingDirection == "H-R") {
		if (head_column < (COL_MAX - 1)) {
			head_column++;
		} else {
			return false;
		}
	} else if (movingDirection == "H-L") {
		if (head_column > COL_MIN) {
			head_column--;
		} else {
			return false;
		}
	} else if (movingDirection == "V-U") {
		if (head_row > ROW_MIN) {
			head_row--;
		} else {
			return false;
		}
	} else if (movingDirection == "V-D") {
		if (head_row < (ROW_MAX - 1)) {
			head_row++;
		} else {
			return false;
		}
	}
// TEST
	else {
		cout << "Fehler beim bestimmen der Bewegungsrichtung" << endl;
		return false;
	}
	return true;
}

bool SnakeSingle::moveRight() {
	if (movingDirection == "V-U") {
		if (head_column < (COL_MAX - 1)) {
			head_column++;
		} else {
			return false;
		}
	} else if (movingDirection == "V-D") {
		if (head_column > COL_MIN) {
			head_column--;
		} else {
			return false;
		}
	} else if (movingDirection == "H-L") {
		if (head_row > ROW_MIN) {
			head_row--;
		} else {
			return false;
		}
	} else if (movingDirection == "H-R") {
		if (head_row < (ROW_MAX - 1)) {
			head_row++;
		} else {
			return false;
		}
	}
// TEST
	else {
		cout << "Fehler beim bestimmen der Bewegungsrichtung" << endl;
		return false;
	}
	return true;
}

bool SnakeSingle::moveLeft() {
	if (movingDirection == "V-D") {
		if (head_column < (COL_MAX - 1)) {
			head_column++;
		} else {
			return false;
		}
	} else if (movingDirection == "V-U") {
		if (head_column > COL_MIN) {
			head_column--;
		} else {
			return false;
		}
	} else if (movingDirection == "H-R") {
		if (head_row > ROW_MIN) {
			head_row--;
		} else {
			return false;
		}
	} else if (movingDirection == "H-L") {
		if (head_row < (ROW_MAX - 1)) {
			head_row++;
		} else {
			return false;
		}
	}
	// TEST
	else {
		cout << "Fehler beim bestimmen der Bewegungsrichtung" << endl;
		return false;
	}
	return true;

}

/*
 * Testet, ob sich Schlange selbst gebissen hat
 * Vector durchgehen und prüfen ob sich Position des Kopfs mit einem der Dots überschneidet
 */
bool SnakeSingle::biten(int head_column, int head_row) {
	for (iterator it = (vec_snake->begin()) + 1; it < vec_snake->size(); it++) {
		Dot snakeElement = *it;
		if (head_column == snakeElement.getColumn()
				&& head_row == snakeElement.getRow())
			return true;
	}
	return false;
}

void SnakeSingle::placeCookie(){
	srand((unsigned)time(NULL));
	int rand_column = rand() % (COL_MAX - COL_MIN + 1) + COL_MIN +1;
	int rand_row = rand() % (ROW_MAX - ROW_MIN + 1) + ROW_MIN +1;
	cookie = new Dot(rand_row, rand_column, true);
}
