/*
 * ShiftRegister.h
 *
 *  Created on: 06.08.2017
 *      Author: paul
 */

#ifndef SHIFTREGISTER_H_
#define SHIFTREGISTER_H_

class ShiftRegister{
public:
	ShiftRegister();
	void Init(int, int, int);
	void loadnWrite(bool []);
	void enableSR(void);
	void disableSR(void);
private:
	int clkP, serP, sEnableP;
	void shifter(int);

};

#endif /* SHIFTREGISTER_H_ */
