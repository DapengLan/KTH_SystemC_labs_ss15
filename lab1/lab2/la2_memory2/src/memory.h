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
	sc_inout<unsigned int> data;  //
	sc_inout<unsigned int> addr_last;
	sc_in<unsigned int> address;
	sc_in<bool> we;
	sc_in<bool> ce;
	int MEMSIZE;

	string in_name;
	unsigned int *mem_temp = new unsigned int[MEMSIZE];

	SC_HAS_PROCESS(memory);
	memory(sc_module_name name, int size, string filename) :
			sc_module(name), MEMSIZE(size), in_name(filename) {
		SC_METHOD(entry);
		sensitive << ce << we << address;
	}
	void entry();
	void memread();
	void memwrite();
};

#endif /* MEMORY_CPP_ */