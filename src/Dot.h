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
	Dot(int r, int c, bool s);
	void setState(bool state);
	void setBuilt(bool build);
	bool getState();
	int getRow();
	int getColumn();
	bool getBuilt();
private:
	int row, column;
	bool state, built;
};

#endif /* DOT_H_ */
