/*
 * HAL_ButtonReader.h
 *
 *  Created on: 31.10.2017
 *      Author: paul
 */

#include <wiringPi.h>
#include "HAL_HardwareDefines.h"
using namespace std;

#ifndef HAL_BUTTONREADER_H_
#define HAL_BUTTONREADER_H_

class HAL_ButtonReader{
public:
	HAL_ButtonReader();
	array<bool, 4> read();
private:

};




#endif /* HAL_BUTTONREADER_H_ */
