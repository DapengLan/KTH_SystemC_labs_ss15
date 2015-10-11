/*
 * memory.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: parallels
 */
#ifndef MEMORY_CPP_
#define MEMORY_CPP_
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include "systemc.h"
#include <stdio.h>
#include "string.h"
//#include "errno.h"
using namespace std;

SC_MODULE(memory) {
	sc_inout<sc_lv<8> > data;  //
	sc_inout<int> addr_last;
	sc_in<int> address;
	sc_in<bool> we;
	sc_in<bool> ce;
	sc_event begin_check_ram2;

	int mem_num;
	int MEMSIZE;

	string in_name;
//	unsigned int *mem_temp = new unsigned int[MEMSIZE];
	string *mem_temp = new string[MEMSIZE];SC_HAS_PROCESS(memory);
	memory(sc_module_name name, int size, string in_name) :
			sc_module(name), MEMSIZE(size), in_name(in_name) {
		SC_METHOD(memread);
		SC_THREAD(listingA);
		SC_METHOD(entry);
		sensitive << ce << we << address;
	}

	memory(sc_module_name name, int size, string in_name ,int mem_num) :
			sc_module(name), MEMSIZE(size), in_name(in_name),mem_num(mem_num) {
		SC_METHOD(memread);
		SC_THREAD(listingB);
		SC_METHOD(entry);
		sensitive << ce << we << address;
	}
	void entry();
	void memread();
	void memwrite();
	void listingA();
	void listingB();
};

#endif /* MEMORY_CPP_ */
