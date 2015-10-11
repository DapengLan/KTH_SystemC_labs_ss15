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
	sc_inout <unsigned int> data;
	sc_inout <unsigned int> addr_last;
	sc_out <unsigned int> address;
	sc_out <bool> we,ce;
	sc_event check_done,check_event;

	string in_name,out_name;

	SC_CTOR(tb_mem) {
		SC_THREAD(test);  // input the test mode
		SC_THREAD(check_mem);
	}

	void test();
	void check_mem();
	void copy_to_ram();  // initial for onetime?
};
