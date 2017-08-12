/*
 * DigitalWatch.cpp
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */

#include "DigitalWatch.h"
#include "Segment.h"
#include "FlipDot.h"

using namespace std;

DigitalWatch::DigitalWatch() {
	this->hour1 = 0;
	this->hour2 = 0;
	this->min1 = 0;
	this->min2 = 0;
}

void DigitalWatch::init(FlipDot *f){
	this->f = *f;
	seg_hour1.init(f, 0, 0, 1, 1);
//	Segmente dem Array in FlipDot hinzufügen
//	f->addtoSegments(seg_hour1());
	seg_hour2.init(f, 0, 0, 1, 1);
	seg_min1.init(f, 0, 0, 1, 1);
	seg_min2.init(f, 0, 0, 1, 1);

}

