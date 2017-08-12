/*
 * Segment.cpp
 *
 *  Created on: 09.08.2017
 *      Author: paul, alex
 */

#include "Segment.h"
#include "Dot.h"
#include "FlipDot.h"

using namespace std;

Segment::Segment() {
	this->f = 0;
	this->c_start = 0;
	this->r_start = 0;
	this->width = 28;
	this->hight = 16;
	this->newState = false;
}

void Segment::init(FlipDot *f, int c_start, int r_start, int width, int hight){
	this->f = *f;
	this->c_start = c_start;
	this->r_start = r_start;
	this->width = width;
	this->hight = hight;
	// Dots werden in der Groesse des Segements erstellt und in Array abgelegt
	for (int r = 0; r < width; r++) {
			for (int c = 0; c < hight; c++) {
				dots[r][c].set(r, c, false);
			}
		}
}

int Segment::getR_start(){
	return r_start;
}
int Segment::getC_start(){
	return c_start;
}
int Segment::getHight(){
	return hight;
}
int Segment::getWidth(){
	return width;
}

void Segment::change(int row, int column, bool newState) {
	dots[row][column].setState(newState);
	f.loadSR(row, column, newState);
	f.enable(newState);
}

void Segment::changeIfDifferent(Dot d, bool newState) {
	bool oldState = d.getState();
	if (oldState != newState) {
		change(d.getRow(), d.getColumn(), newState);
	}
}

void Segment::changeRow(int r, bool newState){
	for (int c = c_start; c <= width; c++) {
				change(r, c, newState);
			}
}

void Segment::changeCollum(int c, bool newState){
	for (int r = r_start; r <= hight; r++) {
		change(r, c, newState);
	}
}
void Segment::changeAll(bool newState) {
	for (int r = r_start; r <= hight; r++) {
		for (int c = c_start; c <= width; c++) {
			change(r, c, newState);
		}
	}
}


