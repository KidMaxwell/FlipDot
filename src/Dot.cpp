/*
 * Dot.cpp
 *
 *  Created on: 16.06.2017
 *      Author: paul, alex
 */

#include "Dot.h"

	Dot::Dot(int r, int c, bool s):
	row(r), column(c), state(s), built(false)
	{}

	void Dot::setState(bool state) {
		this->state=state;
	}

	void Dot::setBuilt(bool built){
		this->built = built;
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

	bool Dot::getBuilt(){
		return built;
	}
