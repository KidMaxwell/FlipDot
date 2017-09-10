/*
 * HAL_HardwareDefines.h
 *
 *  Created on: 13.08.2017
 *      Author: alexander
 */

#ifndef HAL_HARDWAREDEFINES_H_
#define HAL_HARDWAREDEFINES_H_

#define COL_MAX 28
#define COL_MIN 0
#define ROW_MAX 16
#define ROW_MIN 0
#define DELAY_SR 1

// Pin-Belegung Raspi
#define D_ENABLE_P 0
#define D_DP 1
#define CLK_P 2
#define SER_P 3
#define S_ENABLE_P 4

// Pin-Belegung Snake
#define T_RIGHT 5
#define T_LEFT 6

// Pin-Belegung Tetris
#define B_RIGHT 5
#define B_LEFT 6
#define B_ROTATE 7		//TODO nochmal im GPIO-Outline schauen
#define B_MOVEDOWN 8

#endif /* HAL_HARDWAREDEFINES_H_ */
