/*
 * counter.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: parallels
 */

#include "counter.h"

counter::counter(sc_module_name _n, int _mod):sc_module(_n),cnt(0),modulo(_mod) {
	SC_METHOD(count);
	sensitive<<clk.pos();
}

