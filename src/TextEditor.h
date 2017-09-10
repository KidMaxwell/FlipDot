/*
 * TextEditor.h
 *
 *  Created on: 10.09.2017
 *      Author: paul
 */

#ifndef TEXTEDITOR_H_
#define TEXTEDITOR_H_

#include "Screen.h"
#include "Digit3x5.h"
#include <iostream>
#include <string>

class TextEditor {
public:
	TextEditor(Screen* scr_p);
	void stringInput(string print);
	void userInput();
private:
	Screen* screen;
};



#endif /* TEXTEDITOR_H_ */
