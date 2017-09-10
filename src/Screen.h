/*
 * Screen.h
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */
#include <iostream>
#include <vector>
#include <iterator>
#include "HAL_HardwareDefines.h"
#include "HAL_Addr.h"
#include "Dot.h"
#include "Segment.h"
#include "TetrisElement.h"

#ifndef SCREEN_H_
#define SCREEN_H_

class Screen {
public:
	Screen();
	void updateScreen_Segment(Segment segment);
	void updateScreen_Dot(Dot dot);
	void updateScreen_Single(int row, int column, bool state);
	void updateScreen_All(bool state);
	void showScreen_Display();
	void showIstScreen_Console();
	void showSollScreen_Console();
	void showScreen_Console();
	void remove_builtColumn();
	bool check_hitBuilt(Segment::koordinates koord);
	bool check_hitTop();
private:
	Dot* istDisplay[ROW_MAX][COL_MAX];
	Dot* sollDisplay[ROW_MAX][COL_MAX];
	HAL_Addr* addr;
};

#endif /* SCREEN_H_ */
