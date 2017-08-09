/*
 * Dot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul, alex
 */

#include "Dot.h"

//	int row, column;
//	bool state;

	Dot::Dot() {
		row=0;
		column=0;
		state=false;
	}

	void Dot::setState(bool state) {
		this->state=state;
	}

	bool Dot::getState() {
		return state;
	}

	void Dot::set(int row, int column, bool state) {
		this->row=row;
		this->column=column;
		this->state=state;
	}

	int Dot::getRow() {
		return row;
	}

	int Dot::getColumn() {
		return column;
	}

