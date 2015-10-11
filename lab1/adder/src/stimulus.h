/*
 * stimulus.h
 *
 *  Created on: Sep 8, 2015
 *      Author: parallels
 */

#ifndef STIMULUS_H_
#define STIMULUS_H_

#include "systemc.h"

SC_MODULE(Stimulus) {
	sc_in<bool> clk;
	sc_out<int> s_a;
	sc_out<int> s_b;

	void generate();

	SC_CTOR(Stimulus) {
		SC_THREAD(generate);
		sensitive<<clk.pos();
	}
};




#endif /* STIMULUS_H_ */
