/*
 * Screen.h
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */
#include "HAL_HardwareDefines.h"

#ifndef SCREEN_H_
#define SCREEN_H_

class Screen {
public:
	Screen();
	void updateScreen(int, int, int);
	void showScreen();
private:
	int screenArray[16][28];
};

#endif /* SCREEN_H_ */
