/*
 * ShiftRegister.h
 *
 *  Created on: 06.08.2017
 *      Author: paul, alex
 */

#ifndef HAL_SHIFTREGISTER_H_
#define HAL_SHIFTREGISTER_H_

class HAL_ShiftRegister{
public:
	HAL_ShiftRegister();
	void loadnWrite(bool []);
	void enableSR(void);
	void disableSR(void);
private:
	void shifter(int);

};

#endif /* HAL_SHIFTREGISTER_H_ */
