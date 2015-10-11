/*
 * main.cpp
 *
 *  Created on: Oct 8, 2015
 *      Author: parallels
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "systemc.h"
#include "memory.h"
#include "tb_mem.h"
#include "tb_noise.h"

int sc_main(int argc, char* argv[]) {
	/*
	 * for task 3.1 and 3.2
	 *
	sc_signal<sc_lv<8> > data;
	sc_signal<int> addr_last;
	sc_signal<int> address;
	sc_signal<bool> we, ce;

	memory mem1("mem1", 1040,
			"/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T1.txt");
	tb_mem test1("test1");
	mem1.ce(ce);
	mem1.we(we);
	mem1.data(data);
	mem1.addr_last(addr_last);
	mem1.address(address);

	test1.ce(ce);
	test1.we(we);
	test1.data(data);
	test1.addr_last(addr_last);
	test1.address(address);*/

	// for task 3.3
	sc_signal<sc_lv<8> > dataA;
	sc_signal<int> addr_lastA;
	sc_signal<int> addressA;
	sc_signal<bool> weA, ceA;

	sc_signal<sc_lv<8> > dataB;
	sc_signal<int> addr_lastB;
	sc_signal<int> addressB;
	sc_signal<bool> weB, ceB;

	memory memA("memA", 1024,
				"/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T3.txt");
	tb_noise test2("noise1");

	memory memB("memB", 1024,
				"/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T3.txt",1);
	tb_noise test3("noise2",1);


	memA.ce(ceA);
	memA.we(weA);
	memA.data(dataA);
	memA.addr_last(addr_lastA);
	memA.address(addressA);

	test2.ce(ceA);
	test2.we(weA);
	test2.data(dataA);
	test2.addr_last(addr_lastA);
	test2.address(addressA);

	memB.ce(ceB);
	memB.we(weB);
	memB.data(dataB);
	memB.addr_last(addr_lastB);
	memB.address(addressB);

	test3.ce(ceB);
	test3.we(weB);
	test3.data(dataB);
	test3.addr_last(addr_lastB);
	test3.address(addressB);
	sc_start();

	return 0;
}

