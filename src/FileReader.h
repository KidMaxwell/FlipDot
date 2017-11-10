/*
 * FileReader.h
 *
 *  Created on: 10.11.2017
 *      Author: paul
 */

#ifndef FILEREADER_H_
#define FILEREADER_H_


#include "Screen.h"
#include "Digit3x5.h"
#include "Digit5x7.h"
#include <iostream>
#include <string>
#include <fstream>

class FileReader {
public:
	FileReader(Screen* scr_p);
	void menu();
	void showFile(string name);
private:
	Screen* screen;
};



#endif /* FILEREADER_H_ */
