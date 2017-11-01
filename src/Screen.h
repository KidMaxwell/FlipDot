/*
 * Screen.h
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */
#include <iostream>
#include "HAL_HardwareDefines.h"
#include "HAL_Addr.h"
#include "Dot.h"
#include "Segment.h"

#ifndef SCREEN_H_
#define SCREEN_H_

/*
 * Klasse welche zentral alle Dots verwaltet und die Hardware ansteuert.
 * sollScreen: wird durch update Methoden geaendert und beim naechsten Aufruf der showScreen_Display Methode auf dem Display angezeigt.
 * istScreen: sollte dem entsprechen was auf dem Display zu sehen ist.
 * showInstantSingle(): flippt einen Dot sowohl im istScreen als auch auf dem Display -> direkter Flip ohne update+show.
 */

class Screen {
public:
	Screen();
	void updateScreen_Segment(Segment segment);
	void updateScreen_Single(int row, int column, bool state);
	void updateScreen_All(bool state);
	void showScreen_Display();
	void showIstScreen_Console();
	void showSollScreen_Console();
	void showScreen_Console();
	void showInstantSingle(int row, int column, bool newState);
	void showInstantDot(Dot dot);
	void showBlackScreen_Display();

private:
	Dot* istDisplay[ROW_MAX][COL_MAX];
	Dot* sollDisplay[ROW_MAX][COL_MAX];
	HAL_Addr* addr;
	void hardwareFlip(int row, int column, bool newState);
};

#endif /* SCREEN_H_ */
