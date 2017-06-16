/*
 * Dot.h
 *
 *  Created on: 16.06.2017
 *      Author: paul
 */

#ifndef DOT_H_
#define DOT_H_

class Dot
{
public:
	Dot(int, int, bool);

	void setState(bool);
	bool getState();
	int getRow(int);
	int getColumn();

private:
	const int row, column;
	bool state;

};

#endif /* DOT_H_ */
