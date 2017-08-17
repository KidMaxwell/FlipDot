/*
 * HALAdressing.h
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */
#include "HAL_HardwareDefines.h"
#include "HAL_ShiftRegister.h"

#ifndef HAL_ADDR_H_
#define HAL_ADDR_H_

class HAL_Addr {
public:
	HAL_Addr();
	void enable(bool);
	void loadSR(int, int, bool);
private:
	HAL_ShiftRegister sr;
};

#endif /* HAL_ADDR_H_ */
