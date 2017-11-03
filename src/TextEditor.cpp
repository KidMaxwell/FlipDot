/*
 * TextEditor.cpp
 *
 *  Created on: 10.09.2017
 *      Author: paul
 */

#include "TextEditor.h"

using namespace std;

TextEditor::TextEditor(Screen* scr_p) :
		screen(scr_p) {
	screen->updateScreen_All(false);
//	screen->showScreen_Display();
//	screen->showScreen_Console();
}

void TextEditor::userInput() {
	while (1) {
		screen->updateScreen_All(false);
		cout << endl << "Text eintippen!" << endl;
		string in;
		getline(cin, in);
		if (!stringInput(in)) {
			cout << "Text zu lang, bitte kuerzer (max. 14)" << endl;
		}
	}
}


bool TextEditor::stringInput(string print) {
	int length = print.length();
	if (length < 15) {
		for (int i = 0; i < length; i++) {
			Digit3x5* digit = new Digit3x5((i * 4) % 28, ((i / 7) * 6));
			digit->chooseDigit(print.substr(i, 1));
			screen->updateScreen_Segment(*digit);
		}
		screen->showScreen_Display();
		screen->showScreen_Console();
		return true;
	} else {
		return false;
	}
}

