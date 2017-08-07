/*
 * Dot.h
 *
 *  Created on: 16.06.2017
 *      Author: paul
 */

#ifndef DOT_H_
#define DOT_H_

namespace FlipDot {
class Dot{
public:
	Dot(int row, int column, bool state) {
			this->row=row;
			this->column=column;
			this->state=state;
	}

	void setState(bool);
	bool getState();
	int getRow();
	int getColumn();

private:
	int row, column;
	bool state;
};
}

#endif /* DOT_H_ */
