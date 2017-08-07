/*
 * ShiftRegister.h
 *
 *  Created on: 06.08.2017
 *      Author: paul
 */

#ifndef SHIFTREGISTER_H_
#define SHIFTREGISTER_H_

namespace FlipDot{
class ShiftRegister
{
public:
	void ShiftRegister(int, int, int);

	void loadnWrite(bool);
	void enableSR(void);
	void disableSR(void);

private:
	const int clkP, serP, sEnableP;
	void shifter(int);

};
}


#endif /* SHIFTREGISTER_H_ */
