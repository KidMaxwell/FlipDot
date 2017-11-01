/*
 * Digit_5x7.h
 *
 *  Created on: 08.10.2017
 *      Author: paul
 */

#ifndef DIGIT_5X7_H_
#define DIGIT_5X7_H_

#include <iostream>
#include <string>
#include "Segment.h"

class Digit_5x7 : public Segment{
public:
	Digit_5x7(int col_start, int row_start);
	void showDigit(std::string digit);
private:
	void show_a();
	void show_A();
	void show_b();
	void show_B();
	void show_c();
	void show_C();
	void show_d();
	void show_D();
	void show_e();
	void show_E();
	void show_f();
	void show_F();
	void show_g();
	void show_G();
	void show_h();
	void show_H();
	void show_i();
	void show_I();
	void show_j();
	void show_J();
	void show_k();
	void show_K();
	void show_l();
	void show_L();
	void show_m();
	void show_M();
	void show_n();
	void show_N();
	void show_o();
	void show_O();
	void show_p();
	void show_P();
	void show_q();
	void show_Q();
	void show_r();
	void show_R();
	void show_s();
	void show_S();
	void show_t();
	void show_T();
	void show_u();
	void show_U();
	void show_v();
	void show_V();
	void show_w();
	void show_W();
	void show_x();
	void show_X();
	void show_y();
	void show_Y();
	void show_z();
	void show_Z();
	void show_0();
	void show_1();
	void show_2();
	void show_3();
	void show_4();
	void show_5();
	void show_6();
	void show_7();
	void show_8();
	void show_9();
	void show_QM();
	void show_FS();
	void show_Comma();
	void show_EM();
	void show_DP();
	void show_SemCol();
	void show_Error();
};

#endif /* DIGIT_5X7_H_ */
