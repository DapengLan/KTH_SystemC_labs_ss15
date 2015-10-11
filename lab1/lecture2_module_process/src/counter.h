/*
 * counter.h
 *
 *  Created on: Sep 21, 2015
 *      Author: parallels
 */

#ifndef COUNTER_H_
#define COUNTER_H_

#include "systemc.h"

class counter: public sc_module {
	sc_in<bool> clk,reset;
	sc_out<int> q;

/*    counter(sc_module_name _n, int _mod):sc_module(_n),cnt(0),modulo(_mod) {
    	SC_METHOD(count);
    	sensitive<<clk.pos();
    }*/

	counter(sc_module_name _n, int _mod);

    SC_HAS_PROCESS(counter);

private:
    void count();
    int cnt;
    const int modulo;
};



#endif /* COUNTER_H_ */
