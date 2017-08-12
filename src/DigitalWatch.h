/*
 * DigitalWatch.h
 *
 *  Created on: 09.08.2017
 *      Author: alexander
 */

#ifndef DIGITALWATCH_H_
#define DIGITALWATCH_H_

class DigitalWatch {
public:
	DigitalWatch();
	void init(FlipDot*);
private:
	FlipDot f;
	Segment seg_hour1, seg_hour2, seg_min1, seg_min2;
	int hour1, hour2, min1, min2;
};

#endif /* DIGITALWATCH_H_ */
