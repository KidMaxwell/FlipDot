/*
 * Digit3x5.cpp
 *
 *  Created on: 09.09.2017
 *      Author: paul
 */

#include "Digit3x5.h"

Digit3x5::Digit3x5(int col_start, int row_start):
Segment(col_start, row_start, 3, 5) {}

void Digit3x5::chooseDigit(string digit) {
	if(digit=="A"||digit=="a") {
		showA();
	}
	else if(digit=="B"||digit=="b"){
		showB();
	}
	else if(digit=="C"||digit=="c"){
		showC();
	}
	else if(digit=="D"||digit=="d"){
		showD();
	}
	else if(digit=="E"||digit=="e"){
		showE();
	}
	else if(digit=="F"||digit=="f"){
		showF();
	}
	else if(digit=="G"||digit=="g"){
		showG();
	}
	else if(digit=="H"||digit=="h"){
		showH();
	}
	else if(digit=="I"||digit=="i"){
		showI();
	}
	else if(digit=="J"||digit=="j"){
		showJ();
	}
	else if(digit=="K"||digit=="k"){
		showK();
	}
	else if(digit=="L"||digit=="l"){
		showL();
	}
	else if(digit=="M"||digit=="m"){
		showM();
	}
	else if(digit=="N"||digit=="n"){
		showN();
	}
	else if(digit=="O"||digit=="o"){
		showO();
	}
	else if(digit=="P"||digit=="p"){
		showP();
	}
	else if(digit=="Q"||digit=="q"){
		showQ();
	}
	else if(digit=="R"||digit=="r"){
		showR();
	}
	else if(digit=="S"||digit=="s"){
		showS();
	}
	else if(digit=="T"||digit=="t"){
		showT();
	}
	else if(digit=="U"||digit=="u"){
		showU();
	}
	else if(digit=="V"||digit=="v"){
		showV();
	}
	else if(digit=="W"||digit=="w"){
		showW();
	}
	else if(digit=="X"||digit=="x"){
		showX();
	}
	else if(digit=="Y"||digit=="y"){
		showY();
	}
	else if(digit=="Z"||digit=="z"){
		showZ();
	}
	else if(digit=="0"){
		show0();
	}
	else if(digit=="1"){
		show1();
	}
	else if(digit=="2"){
		show2();
	}
	else if(digit=="3"){
		show3();
	}
	else if(digit=="4"){
		show4();
	}
	else if(digit=="5"){
		show5();
	}
	else if(digit=="6"){
		show6();
	}
	else if(digit=="7"){
		show7();
	}
	else if(digit=="8"){
		show8();
	}
	else if(digit=="9"){
		show9();
	}
	else if(digit=="?"){
		showQM();
	}
	else if(digit=="."){
		showFS();
	}
	else if(digit=="!"){
		showEM();
	}
	else if(digit==" "){

	}
	else {
		showError();
	}
}

void Digit3x5::showA() {
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	changeRow(2, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 2, true);
}

void Digit3x5::showB() {
	change(0, 0, true);
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 1, true);
}

void Digit3x5::showC() {
	change(0, 1, true);
	change(0, 2, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(4, 1, true);
	change(4, 2, true);
}

void Digit3x5::showD(){
	change(0, 0, true);
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 1, true);
}

void Digit3x5::showE() {
	changeRow(0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 0, true);
	changeRow(4, true);
}

void Digit3x5::showF() {
	changeRow(0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 0, true);
	change(4, 0, true);
}

void Digit3x5::showG() {
	change(0, 1, true);
	change(0, 2, true);
	change(1, 0, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 1, true);
	change(4, 2, true);
}

void Digit3x5::showH() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 0, true);
	change(1, 2, true);
	changeRow(2, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 2, true);
}

void Digit3x5::showI() {
	change(0, 1, true);
	change(1, 1, true);
	change(2, 1, true);
	change(3, 1, true);
	change(4, 1, true);
}

void Digit3x5::showJ() {
	changeRow(0, true);
	change(1, 2, true);
	change(2, 2, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 1, true);
}

void Digit3x5::showK() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 2, true);
}

void Digit3x5::showL() {
	change(0, 0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	changeRow(4, true);
}

void Digit3x5::showM() {
	change(0, 0, true);
	change(0, 2, true);
	changeRow(1, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 2, true);
}

void Digit3x5::showN() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 0, true);
	change(1, 2, true);
	changeRow(2, true);
	changeRow(3, true);
	change(4, 0, true);
	change(4, 2, true);
}

void Digit3x5::showO() {
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 1, true);
}

void Digit3x5::showP() {
	change(0, 0, true);
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 0, true);
	change(4, 0, true);
}

void Digit3x5::showQ() {
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 1, true);
	change(4, 2, true);
}

void Digit3x5::showR() {
	change(0, 0, true);
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 2, true);
}

void Digit3x5::showS() {
	change(0, 1, true);
	change(0, 2, true);
	change(1, 0, true);
	change(2, 1, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 1, true);
}

void Digit3x5::showT() {
	changeRow(0, true);
	change(1, 1, true);
	change(2, 1, true);
	change(3, 1, true);
	change(4, 1, true);
}

void Digit3x5::showU() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 0, true);
	change(3, 2, true);
	changeRow(4, true);
}

void Digit3x5::showV() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 1, true);
}

void Digit3x5::showW() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 2, true);
	changeRow(3, true);
	change(4, 0, true);
	change(4, 2, true);
}

void Digit3x5::showX() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 1, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 2, true);
}

void Digit3x5::showY() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 1, true);
	change(3, 1, true);
	change(4, 1, true);
}

void Digit3x5::showZ() {
	changeRow(0, true);
	change(1, 2, true);
	change(2, 1, true);
	change(3, 0, true);
	changeRow(4, true);
}

void Digit3x5::show0() {
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 1, true);
}

void Digit3x5::show1() {
	changeColumn(1, true);
}

void Digit3x5::show2() {
	change(0, 0, true);
	change(0, 1, true);
	change(1, 2, true);
	change(2, 2, true);
	change(3, 1, true);
	changeRow(4, true);
}

void Digit3x5::show3() {
	change(0, 0, true);
	change(0, 1, true);
	change(1, 2, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 1, true);
}

void Digit3x5::show4() {
	change(0, 0, true);
	change(1, 0, true);
	change(1, 2, true);
	changeRow(2, true);
	change(3, 2, true);
	change(4, 2, true);
}

void Digit3x5::show5() {
	changeRow(0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 1, true);
}

void Digit3x5::show6() {
	change(0, 1, true);
	change(0, 2, true);
	change(1, 0, true);
	change(2, 0, true);
	change(2, 1, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 1, true);
}

void Digit3x5::show7() {
	changeRow(0, true);
	change(1, 2, true);
	change(2, 1, true);
	change(3, 0, true);
	change(4, 0, true);
}

void Digit3x5::show8() {
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 1, true);
	change(3, 0, true);
	change(3, 2, true);
	change(4, 1, true);
}

void Digit3x5::show9() {
	change(0, 1, true);
	change(1, 0, true);
	change(1, 2, true);
	change(2, 1, true);
	change(2, 2, true);
	change(3, 2, true);
	change(4, 0, true);
	change(4, 1, true);
}

void Digit3x5::showQM() {
	change(0, 0, true);
	change(0, 1, true);
	change(1, 2, true);
	change(2, 1, true);
	change(4, 1, true);
}

void Digit3x5::showFS() {
	change(4, 0, true);
}

void Digit3x5::showEM() {
	change(0, 1, true);
	change(1, 1, true);
	change(2, 1, true);
	change(4, 1, true);
}

void Digit3x5::showError() {
	change(0, 0, true);
	change(0, 2, true);
	change(1, 1, true);
	change(2, 0, true);
	change(2, 2, true);
	change(3, 1, true);
	change(4, 0, true);
	change(4, 2, true);
}
