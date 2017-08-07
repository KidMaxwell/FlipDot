/*
 * Dot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul
 */

namespace FlipDot{
	int Dot::row, Dot::column;
	bool Dot::state;

	Dot::Dot(int row, int column, bool state) {
		this->row=row;
		this->column=column;
		this->state=state;
	}

	void Dot::setState(bool state) {
		this->state=state;
	}

	bool Dot::getState() {
		return state;
	}

	int Dot::getRow() {
		return row;
	}

	int Dot::getColumn() {
		return column;
	}

}
