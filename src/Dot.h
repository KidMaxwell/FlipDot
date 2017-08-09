/*
 * Dot.h
 *
 *  Created on: 16.06.2017
 *      Author: paul, alex
 */

#ifndef DOT_H_
#define DOT_H_

class Dot{
public:
	Dot();
	void setState(bool);
	bool getState();
	void set(int, int, bool);
	int getRow();
	int getColumn();
private:
	int row, column;
	bool state;
};

#endif /* DOT_H_ */
