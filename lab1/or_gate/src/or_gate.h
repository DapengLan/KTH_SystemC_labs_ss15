/*
 * or_gate.h
 *
 *  Created on: Sep 16, 2015
 *      Author: parallels
 */

#ifndef OR_GATE_H_
#define OR_GATE_H_

#include "systemc.h"
SC_MODULE(or_gate)
{
	sc_in<sc_bit> a;
	sc_in<sc_bit> b;
	sc_out<sc_bit> c;

	void prc_or_gate();

	SC_CTOR (or_gate)
	{
		SC_METHOD (prc_or_gate);
		sensitive <<a<<b;

	}
};



#endif /* OR_GATE_H_ */
