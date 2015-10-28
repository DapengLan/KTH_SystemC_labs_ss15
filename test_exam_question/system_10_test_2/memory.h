/*
 * MODULE_H.h
 *
 *  Created on: Oct 27, 2015
 *      Author: parallels
 */
#pragma once

#ifndef SRC_MEMORY_H_
#define SRC_MEMORY_H_

#include "systemc.h"

using namespace std;
SC_MODULE(memory) {
	sc_in<bool> clk;
	sc_event p1_done;
	int s;
	void p1() {

		s = 1;
		cout << "P1:" <<s << endl;
		p1_done.notify();
	}

	void p2() {
		wait(p1_done);
		s = 2;
		cout <<"P2:"<< s << endl;
	}

	SC_CTOR(memory) {
		SC_THREAD(p1);
			sensitive << clk.pos();
		dont_initialize();
		SC_THREAD(p2);
			sensitive << clk.pos();
		dont_initialize();
	}
};



#endif /* SRC_MEMORY_H_ */
