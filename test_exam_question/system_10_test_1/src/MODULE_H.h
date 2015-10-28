/*
 * MODULE_H.h
 *
 *  Created on: Oct 27, 2015
 *      Author: parallels
 */

#ifndef SRC_MODULE_H_H_
#define SRC_MODULE_H_H_

#include "systemc.h"

SC_MODULE(Module) {
	//sc_in<int> clock("clock");
	sc_in<bool> clock;
	const int i = 10;
	void P1() {
		wait(10,SC_NS);
		std:cout<<"Process execution .." <<endl;
	}
	SC_CTOR(Module) {
		SC_THREAD(P1);
		 sensitive <<clock.pos() ;
	}
};



#endif /* SRC_MODULE_H_H_ */
