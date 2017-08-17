/*
 * ClockSegment.h
 *
 *  Created on: 17.08.2017
 *      Author: alexander, paul
 */
#include "Segment.h"
#include "Screen.h"

#ifndef CLOCKSEGMENT_H_
#define CLOCKSEGMENT_H_

class ClockSegment: public Segment {
public:
	ClockSegment();
	void choseNumber(Screen*, int);
	void show0(Screen*);
	void show1(Screen*);
	void show2(Screen*);
	void show3(Screen*);
	void show4(Screen*);
	void show5(Screen*);
	void show6(Screen*);
	void show7(Screen*);
	void show8(Screen*);
	void show9(Screen*);
};

#endif /* CLOCKSEGMENT_H_ */
