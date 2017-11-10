/*
 * FileReader.cpp
 *
 *  Created on: 10.11.2017
 *      Author: paul
 */

#include "FileReader.h"

FileReader::FileReader(Screen* scr_p) :
	screen(scr_p) {
}

void FileReader::menu() {
	while(1) {
		screen->updateScreen_All(false);
		cout << endl << "Bitte den Dateinamen eingeben:" << endl;
		string in;
		cin >> in;
		showFile(in);
	}
}

void FileReader::showFile(string name) {
	fstream file;
	cout << endl << name.c_str() << endl;
	file.open(name.c_str(), std::fstream::in);
	char* line;
	for(int i=0 ; i<16 ; i++) {
		file.getline(line, 28);
		cout << line << endl;
	}
}
