/*
 * Digit_5x7.cpp
 *
 *  Created on: 08.10.2017
 *      Author: paul
 */

#include "Digit_5x7.h"

using namespace std;

Digit_5x7::Digit_5x7(int col_start, int row_start) :
		Segment(col_start, row_start, 5, 7) {
}

void Digit_5x7::showDigit(string digit) {
	changeAll(false);
	if (digit == "a") {
		show_a();
	} else if (digit == "A") {
		show_A();
	}

	else if (digit == "b") {
		show_b();
	}

	else if (digit == "B") {
		show_B();
	}

	else if (digit == "c") {
		show_c();
	}

	else if (digit == "C") {
		show_C();
	}

	else if (digit == "d") {
		show_d();
	}

	else if (digit == "D") {
		show_D();
	}

	else if (digit == "e") {
		show_e();
	}

	else if (digit == "E") {
		show_E();
	}

	else if (digit == "f") {
		show_f();
	}

	else if (digit == "F") {
		show_F();
	}

	else if (digit == "g") {
		show_g();
	}

	else if (digit == "G") {
		show_G();
	}

	else if (digit == "h") {
		show_h();
	}

	else if (digit == "H") {
		show_H();
	}

	else if (digit == "i") {
		show_i();
	}

	else if (digit == "I") {
		show_I();
	}

	else if (digit == "j") {
		show_j();
	}

	else if (digit == "J") {
		show_J();
	}

	else if (digit == "k") {
		show_k();
	}

	else if (digit == "K") {
		show_K();
	}

	else if (digit == "l") {
		show_l();
	}

	else if (digit == "L") {
		show_L();
	}

	else if (digit == "m") {
		show_m();
	}

	else if (digit == "M") {
		show_M();
	}

	else if (digit == "n") {
		show_n();
	}

	else if (digit == "N") {
		show_N();
	}

	else if (digit == "o") {
		show_o();
	}

	else if (digit == "O") {
		show_O();
	}

	else if (digit == "p") {
		show_p();
	}

	else if (digit == "P") {
		show_P();
	}

	else if (digit == "q") {
		show_q();
	}

	else if (digit == "Q") {
		show_Q();
	}

	else if (digit == "r") {
		show_r();
	}

	else if (digit == "R") {
		show_R();
	}

	else if (digit == "s") {
		show_s();
	}

	else if (digit == "S") {
		show_S();
	}

	else if (digit == "t") {
		show_t();
	}

	else if (digit == "T") {
		show_T();
	}

	else if (digit == "u") {
		show_u();
	}

	else if (digit == "U") {
		show_U();
	}

	else if (digit == "v") {
		show_v();
	}

	else if (digit == "V") {
		show_V();
	}

	else if (digit == "w") {
		show_w();
	}

	else if (digit == "W") {
		show_W();
	}

	else if (digit == "x") {
		show_x();
	}

	else if (digit == "X") {
		show_X();
	}

	else if (digit == "y") {
		show_y();
	}

	else if (digit == "Y") {
		show_Y();
	}

	else if (digit == "z") {
		show_z();
	}

	else if (digit == "Z") {
		show_Z();
	}

	else if (digit == "0") {
		show_0();
	}

	else if (digit == "1") {
		show_1();
	}

	else if (digit == "2") {
		show_2();
	}

	else if (digit == "3") {
		show_3();
	}

	else if (digit == "4") {
		show_4();
	}

	else if (digit == "5") {
		show_5();
	}

	else if (digit == "6") {
		show_6();
	}

	else if (digit == "7") {
		show_7();
	}

	else if (digit == "8") {
		show_8();
	}

	else if (digit == "9") {
		show_9();
	} else if (digit == "?") {
		show_QM();
	} else if (digit == ".") {
		show_FS();
	} else if (digit == ",") {
		show_Comma();
	} else if (digit == "!") {
		show_EM();
	} else if (digit == " ") {

	} else if (digit == ":") {
		show_DP();
	} else if (digit == ";") {
		show_SemCol();
	} else {
		show_Error();
	}

}

void Digit_5x7::show_a() {
	change(3, 0, true);
	change(4, 0, true);
	change(5, 0, true);
	change(2, 1, true);
	change(6, 1, true);
	change(2, 2, true);
	change(6, 2, true);
	change(3, 3, true);
	change(5, 3, true);
	change(2, 4, true);
	change(3, 4, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 4, true);
}

void Digit_5x7::show_A() {
	change(1, 0, true);
	change(2, 0, true);
	change(3, 0, true);
	change(5, 0, true);
	change(6, 0, true);
	change(0, 1, true);
	change(0, 2, true);
	change(0, 3, true);
	change(1, 5, true);
	change(2, 6, true);
	change(3, 6, true);
	change(5, 6, true);
	change(6, 6, true);
	changeRow(4, true);
}

void Digit_5x7::show_b() {
	changeColumn(0, true);
	change(3, 1, true);
	change(5, 1, true);
	change(2, 2, true);
	change(6, 2, true);
	change(2, 3, true);
	change(6, 3, true);
	change(3, 5, true);
	change(4, 5, true);
	change(5, 5, true);

}

void Digit_5x7::show_B() {
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

void Digit_5x7::show_c() {
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 0, true);
	change(3, 4, true);
	change(4, 0, true);
	change(5, 0, true);
	change(6, 1, true);
	change(6, 2, true);
	change(6, 3, true);
	change(6, 4, true);
}

void Digit_5x7::show_C() {
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

void Digit_5x7::show_d() {
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

void Digit_5x7::show_D() {
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

void Digit_5x7::show_e() {
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

void Digit_5x7::show_E() {
	changeRow(0, true);
	changeRow(6, true);
	changeColumn(0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
}

void Digit_5x7::show_f() {
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

void Digit_5x7::show_F() {
	changeRow(0, true);
	changeColumn(0, true);
	change(3, 1, true);
	change(3, 2, true);
	change(3, 3, true);
}

void Digit_5x7::show_g() {
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

void Digit_5x7::show_G() {
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

void Digit_5x7::show_h() {
	changeColumn(0, true);
	change(2, 1, true);
	change(2, 2, true);
	change(2, 3, true);
	change(3, 4, true);
	change(4, 4, true);
	change(5, 4, true);
	change(6, 4, true);
}

void Digit_5x7::show_H() {
	changeColumn(0, true);
	changeColumn(4, true);
	changeRow(3, true);
}

void Digit_5x7::show_i() {
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

void Digit_5x7::show_I() {
	changeColumn(2, true);
	change(0, 1, true);
	change(0, 3, true);
	change(6, 1, true);
	change(6, 3, true);
}

void Digit_5x7::show_j() {
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

void Digit_5x7::show_J() {
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

void Digit_5x7::show_k() {
	changeColumn(0, true);
	change(2, 4, true);
	change(3, 3, true);
	change(4, 2, true);
	change(4, 1, true);
	change(5, 3, true);
	change(6, 4, true);
}

void Digit_5x7::show_K() {
	changeColumn(0, true);
	change(0, 4, true);
	change(1, 3, true);
	change(2, 2, true);
	change(3, 1, true);
	change(4, 2, true);
	change(5, 3, true);
	change(6, 4, true);
}

void Digit_5x7::show_l() {
	changeColumn(2, true);
	change(0, 1, true);
	change(6, 1, true);
	change(6, 3, true);
}

void Digit_5x7::show_L() {
	changeColumn(0, true);
	changeRow(6, true);
}

void Digit_5x7::show_m() {
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

void Digit_5x7::show_M() {
	changeColumn(0, true);
	changeColumn(4, true);
	change(1, 1, true);
	change(1, 3, true);
	change(2, 2, true);
}

void Digit_5x7::show_n() {
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

void Digit_5x7::show_N() {
	changeColumn(0, true);
	changeColumn(4, true);
	change(2, 1, true);
	change(3, 2, true);
	change(4, 3, true);
}

void Digit_5x7::show_o() {

}

void Digit_5x7::show_O() {

}

void Digit_5x7::show_p() {

}

void Digit_5x7::show_P() {

}

void Digit_5x7::show_q() {

}

void Digit_5x7::show_Q() {

}

void Digit_5x7::show_r() {

}

void Digit_5x7::show_R() {

}

void Digit_5x7::show_s() {

}

void Digit_5x7::show_S() {

}

void Digit_5x7::show_t() {

}

void Digit_5x7::show_T() {

}

void Digit_5x7::show_u() {

}

void Digit_5x7::show_U() {

}

void Digit_5x7::show_v() {

}

void Digit_5x7::show_V() {

}

void Digit_5x7::show_w() {

}

void Digit_5x7::show_W() {

}

void Digit_5x7::show_x() {

}

void Digit_5x7::show_X() {

}

void Digit_5x7::show_y() {

}

void Digit_5x7::show_Y() {

}

void Digit_5x7::show_z() {

}

void Digit_5x7::show_Z() {

}

void Digit_5x7::show_0() {

}

void Digit_5x7::show_1() {

}

void Digit_5x7::show_2() {

}

void Digit_5x7::show_3() {

}

void Digit_5x7::show_4() {

}

void Digit_5x7::show_5() {

}

void Digit_5x7::show_6() {

}

void Digit_5x7::show_7() {

}

void Digit_5x7::show_8() {

}

void Digit_5x7::show_9() {

}

void Digit_5x7::show_QM() {

}

void Digit_5x7::show_FS() {

}

void Digit_5x7::show_Comma() {

}

void Digit_5x7::show_EM() {

}

void Digit_5x7::show_DP() {

}

void Digit_5x7::show_SemCol() {

}

void Digit_5x7::show_Error() {

}
