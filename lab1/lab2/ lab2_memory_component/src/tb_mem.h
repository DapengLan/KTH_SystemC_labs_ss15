/*
 * tb_mem.h
 *
 *  Created on: Oct 8, 2015
 *      Author: parallels
 */

#pragma once
#include <iostream>
#include "systemc.h"
#include <string.h>
#include <fstream>

SC_MODULE(tb_mem) {
	sc_inout<sc_lv<8> > data;
//	sc_in <sc_lv<8> > data;
	sc_inout<int> addr_last;
	sc_out<int> address;
	sc_out<bool> we;
	sc_out<bool> ce;
	sc_event check_done, check_event;

	string in_name, out_name;

	SC_CTOR(tb_mem) {
		SC_THREAD(test);  // input the test mode
		SC_THREAD(check_mem);
		//	SC_THREAD(copy_to_ram);
	}

	void test();
	void check_mem();
	void copy_to_ram();  // initial for onetime?
};

