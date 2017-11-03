/*
 * Digit5x7.cpp
 *
 *  Created on: 08.10.2017
 *      Author: paul
 */

#include "Digit5x7.h"

using namespace std;

Digit5x7::Digit5x7(int col_start, int row_start) :
		Segment(col_start, row_start, 5, 7) {
}

void Digit5x7::chooseDigit(string digit) {
	changeAll(false);
	if (digit == "a") {
		showa();
	} else if (digit == "A") {
		showA();
	}

	else if (digit == "b") {
		showb();
	}

	else if (digit == "B") {
		showB();
	}

	else if (digit == "c") {
		showc();
	}

	else if (digit == "C") {
		showC();
	}

	else if (digit == "d") {
		showd();
	}

	else if (digit == "D") {
		showD();
	}

	else if (digit == "e") {
		showe();
	}

	else if (digit == "E") {
		showE();
	}

	else if (digit == "f") {
		showf();
	}

	else if (digit == "F") {
		showF();
	}

	else if (digit == "g") {
		showg();
	}

	else if (digit == "G") {
		showG();
	}

	else if (digit == "h") {
		showh();
	}

	else if (digit == "H") {
		showH();
	}

	else if (digit == "i") {
		showi();
	}

	else if (digit == "I") {
		showI();
	}

	else if (digit == "j") {
		showj();
	}

	else if (digit == "J") {
		showJ();
	}

	else if (digit == "k") {
		showk();
	}

	else if (digit == "K") {
		showK();
	}

	else if (digit == "l") {
		showl();
	}

	else if (digit == "L") {
		showL();
	}

	else if (digit == "m") {
		showm();
	}

	else if (digit == "M") {
		showM();
	}

	else if (digit == "n") {
		shown();
	}

	else if (digit == "N") {
		showN();
	}

	else if (digit == "o") {
		showo();
	}

	else if (digit == "O") {
		showO();
	}

	else if (digit == "p") {
		showp();
	}

	else if (digit == "P") {
		showP();
	}

	else if (digit == "q") {
		showq();
	}

	else if (digit == "Q") {
		showQ();
	}

	else if (digit == "r") {
		showr();
	}

	else if (digit == "R") {
		showR();
	}

	else if (digit == "s") {
		shows();
	}

	else if (digit == "S") {
		showS();
	}

	else if (digit == "t") {
		showt();
	}

	else if (digit == "T") {
		showT();
	}

	else if (digit == "u") {
		showu();
	}

	else if (digit == "U") {
		showU();
	}

	else if (digit == "v") {
		showv();
	}

	else if (digit == "V") {
		showV();
	}

	else if (digit == "w") {
		showw();
	}

	else if (digit == "W") {
		showW();
	}

	else if (digit == "x") {
		showx();
	}

	else if (digit == "X") {
		showX();
	}

	else if (digit == "y") {
		showy();
	}

	else if (digit == "Y") {
		showY();
	}

	else if (digit == "z") {
		showz();
	}

	else if (digit == "Z") {
		showZ();
	}

	else if (digit == "0") {
		show0();
	}

	else if (digit == "1") {
		show1();
	}

	else if (digit == "2") {
		show2();
	}

	else if (digit == "3") {
		show3();
	}

	else if (digit == "4") {
		show4();
	}

	else if (digit == "5") {
		show5();
	}

	else if (digit == "6") {
		show6();
	}

	else if (digit == "7") {
		show7();
	}

	else if (digit == "8") {
		show8();
	}

	else if (digit == "9") {
		show9();
	} else if (digit == "?") {
		showQM();
	} else if (digit == ".") {
		showFS();
	} else if (digit == ",") {
		showComma();
	} else if (digit == "!") {
		showEM();
	} else if (digit == " ") {

	} else if (digit == ":") {
		showDP();
	} else if (digit == ";") {
		showSemCol();
	}
	else if (digit == "/") {
		showPi();
	}
	else {
		showError();
	}

}

void Digit5x7::showa() {
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 4, true);
	change(4, 1, true);
	change(4, 2, true);
	change(4, 3, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
	change(6, 4, true);
}

void Digit5x7::showA() {
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(5, 0, true);
	change(6, 0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 4, true);
	change(2, 4, true);
	change(3, 4, true);
	change(5, 4, true);
	change(6, 4, true);
	changeRow(4, true);
}

void Digit5x7::showb() {
	changeColumn(0, true);
	change(3, 1, true);
	change(5, 1, true);
	change(2, 2, true);
	change(6, 2, true);
	change(2, 3, true);
	change(6, 3, true);
	change(3, 4, true);
	change(4, 4, true);
	change(5, 4, true);

}

void Digit5x7::showB() {
	changeColumn(0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
	change(1, 4, true);
	change(2, 4, true);
	change(4, 4, true);
	change(5, 4, true);
}

void Digit5x7::showc() {
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 0, true);
	change(4, 0, true);
	change(5, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showC() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(3, 0, true);
	change(4, 0, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showd() {
	changeColumn(4, true);
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 0, true);
	change(4, 0, true);
	change(5, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showD() {
	changeColumn(0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(1, 3, true);
	change(2, 4, true);
	change(3, 4, true);
	change(4, 4, true);
	change(5, 3, true);
	change(6, 1, true);
	change(6, 2, true);
}

void Digit5x7::showe() {
	changeRow(4, true);
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 0, true);
	change(3, 4, true);
	change(5, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
	change(6, 4, true);
}

void Digit5x7::showE() {
	changeRow(0, true);
	changeRow(6, true);
	changeColumn(0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
}

void Digit5x7::showf() {
	change(0, 3, true);
	change(0, 4, true);
	change(1, 2, true);
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 2, true);
	change(4, 2, true);
	change(5, 2, true);
	change(6, 2, true);
}

void Digit5x7::showF() {
	changeRow(0, true);
	changeColumn(0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
}

void Digit5x7::showg() {
	change(1, 1, true);
	change(1, 2, true);
	change(1, 3, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 1, true);
	change(4, 2, true);
	change(4, 3, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showG() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 2, true);
	change(3, 3, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
	change(6, 4, true);
}

void Digit5x7::showh() {
	changeColumn(0, true);
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 4, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 4, true);
}

void Digit5x7::showH() {
	changeColumn(0, true);
	changeColumn(4, true);
	changeRow(3, true);
}

void Digit5x7::showi() {
	change(0, 2, true);
	change(2, 1, true);
	change(2, 2, true);
	change(3, 2, true);
	change(4, 2, true);
	change(5, 2, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showI() {
	changeColumn(2, true);
	change(0, 1, true);
	change(0, 3, true);
	change(6, 1, true);
	change(6, 3, true);
}

void Digit5x7::showj() {
	change(0, 3, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 3, true);
	change(4, 3, true);
	change(5, 0, true);
	change(5, 3, true);
	change(6, 1, true);
	change(6, 2, true);
}

void Digit5x7::showJ() {
	changeRow(0, true);
	change(1, 4, true);
	change(2, 4, true);
	change(3, 4, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showk() {
	changeColumn(0, true);
	change(2, 3, true);
	change(3, 2, true);
	change(4, 1, true);
	change(5, 2, true);
	change(6, 3, true);
}

void Digit5x7::showK() {
	changeColumn(0, true);
	change(0, 4, true);
	change(1, 3, true);
	change(2, 2, true);
	change(3, 1, true);
	change(4, 2, true);
	change(5, 3, true);
	change(6, 4, true);
}

void Digit5x7::showl() {
	changeColumn(2, true);
	change(0, 1, true);
	change(6, 1, true);
	change(6, 3, true);
}

void Digit5x7::showL() {
	changeColumn(0, true);
	changeRow(6, true);
}

void Digit5x7::showm() {
	change(2, 0, true);
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 0, true);
	change(3, 2, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 2, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 2, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 2, true);
	change(6, 4, true);
}

void Digit5x7::showM() {
	changeColumn(0, true);
	changeColumn(4, true);
	change(1, 1, true);
	change(1, 3, true);
	change(2, 2, true);
}

void Digit5x7::shown() {
	change(2, 0, true);
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 4, true);
}

void Digit5x7::showN() {
	changeColumn(0, true);
	changeColumn(4, true);
	change(2, 1, true);
	change(3, 2, true);
	change(4, 3, true);
}

void Digit5x7::showo() {
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showO() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showp() {
	change(1, 0, true);
	change(1, 1, true);
	change(1, 2, true);
	change(1, 3, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 1, true);
	change(4, 2, true);
	change(4, 3, true);
	change(5, 0, true);
	change(6, 0, true);
}

void Digit5x7::showP() {
	changeColumn(0 , true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 4, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
}

void Digit5x7::showq() {
	change(1, 1, true);
	change(1, 2, true);
	change(1, 3, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 1, true);
	change(4, 2, true);
	change(4, 3, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 4, true);
}

void Digit5x7::showQ() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 2, true);
	change(4, 4, true);
	change(5, 1, true);
	change(5, 2, true);
	change(5, 3, true);
	change(6, 4, true);
}

void Digit5x7::showr() {
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 0, true);
	change(4, 0, true);
	change(5, 0, true);
	change(6, 0, true);
}

void Digit5x7::showR() {
	changeColumn(0 , true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 4, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 2, true);
	change(5, 3, true);
	change(6, 4, true);
}

void Digit5x7::shows() {
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(2, 4, true);
	change(3, 0, true);
	change(4, 1, true);
	change(4, 2, true);
	change(4, 3, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showS() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showt() {
	change(0, 2, true);
	change(1, 2, true);
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(2, 4, true);
	change(3, 2, true);
	change(4, 2, true);
	change(5, 2, true);
	change(6, 3, true);
	change(6, 4, true);
}

void Digit5x7::showT() {
	changeRow(0 , true);
	changeColumn(2 , true);
}

void Digit5x7::showu() {
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
	change(6, 4, true);
}

void Digit5x7::showU() {
	change(0, 0, true);
	change(0, 4, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showv() {
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 1, true);
	change(4, 3, true);
	change(5, 1, true);
	change(5, 3, true);
	change(6, 2, true);
}

void Digit5x7::showV() {
	change(0, 0, true);
	change(0, 4, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 1, true);
	change(5, 3, true);
	change(6, 2, true);
}

void Digit5x7::showw() {
	change(2, 0, true);
	change(2, 2, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 2, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 2, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 2, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 3, true);
}

void Digit5x7::showW() {
	change(0, 0, true);
	change(0, 4, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 2, true);
	change(3, 4, true);
	change(4, 0, true);
	change(4, 2, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 2, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 3, true);
}

void Digit5x7::showx() {
	change(2, 0, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 3, true);
	change(4, 2, true);
	change(5, 1, true);
	change(5, 3, true);
	change(6, 0, true);
	change(6, 4, true);
}

void Digit5x7::showX() {
	change(0, 0, true);
	change(0, 4, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 1, true);
	change(2, 3, true);
	change(3, 2, true);
	change(4, 1, true);
	change(4, 3, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 4, true);
}

void Digit5x7::showy() {
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 1, true);
	change(4, 2, true);
	change(4, 3, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showY() {
	change(0, 0, true);
	change(0, 4, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 3, true);
	change(4, 2, true);
	change(5, 2, true);
	change(6, 2, true);
}

void Digit5x7::showz() {
	changeRow(2 , true);
	change(3, 3, true);
	change(4, 2, true);
	change(5, 1, true);
	changeRow(6 , true);
}

void Digit5x7::showZ() {
	changeRow(0 , true);
	changeRow(6 , true);
	change(1, 4, true);
	change(2, 3, true);
	change(3, 2, true);
	change(4, 1, true);
	change(5, 0, true);
}

void Digit5x7::show0() {
	showO();
}

void Digit5x7::show1() {
	changeColumn(2, true);
}

void Digit5x7::show2() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 3, true);
	change(3, 2, true);
	change(4, 1, true);
	change(5, 0, true);
	changeRow(6, true);
}

void Digit5x7::show3() {
	change(0, 0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 4, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::show4() {
	change(0, 0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 2, true);
	changeRow(4, true);
	change(5, 2, true);
	change(6, 2, true);
}

void Digit5x7::show5() {
	changeRow(0, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::show6() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::show7() {
	change(0, 0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 3, true);
	change(2, 3, true);
	change(3, 2, true);
	change(3, 3, true);
	change(3, 4, true);
	change(4, 3, true);
	change(5, 3, true);
	change(6, 3, true);
}

void Digit5x7::show8() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(4, 0, true);
	change(4, 4, true);
	change(5, 0, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::show9() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 0, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
	change(3, 4, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
}

void Digit5x7::showDoubleDots(){
	change(0, 0, true);
	change(0, 1, true);
	change(1, 0, true);
	change(1, 1, true);
	change(3, 0, true);
	change(3, 1, true);
	change(4, 0, true);
	change(4, 1, true);
}

void Digit5x7::showQM() {
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 0, true);
	change(1, 4, true);
	change(2, 4, true);
	change(3, 3, true);
	change(4, 2, true);
	change(6, 2, true);
}

void Digit5x7::showFS() {
	change(6, 0, true);
}

void Digit5x7::showComma() {
	change(4, 2, true);
	change(5, 2, true);
	change(6, 1, true);
}

void Digit5x7::showEM() {
	change(0, 2, true);
	change(1, 2, true);
	change(2, 2, true);
	change(3, 2, true);
	change(4, 2, true);
	change(6, 2, true);
}

void Digit5x7::showDP() {
	change(2, 2, true);
	change(4, 2, true);
}

void Digit5x7::showSemCol() {
	change(2, 2, true);
	change(4, 2, true);
	change(5, 2, true);
	change(6, 1, true);
}

void Digit5x7::showError() {
	change(0, 0, true);
	change(0, 2, true);
	change(0, 4, true);
	change(1, 1, true);
	change(1, 3, true);
	change(2, 0, true);
	change(2, 2, true);
	change(2, 4, true);
	change(3, 1, true);
	change(3, 3, true);
	change(4, 0, true);
	change(4, 2, true);
	change(4, 4, true);
	change(5, 1, true);
	change(5, 3, true);
	change(6, 0, true);
	change(6, 2, true);
	change(6, 4, true);
}

void Digit5x7::showPi() {
	changeRow(2 , true);
	change(3, 1, true);
	change(3, 3, true);
	change(4, 1, true);
	change(4, 3, true);
	change(5, 1, true);
	change(5, 3, true);
	change(6, 1, true);
	change(6, 4, true);
}
