/*
 * adder.h
 *
 *  Created on: Sep 21, 2015
 *      Author: parallels
 */

#ifndef ADDER_H_
#define ADDER_H_

#include "systemc.h"

SC_MODULE(adder) {
	sc_in<int> a,b;
	sc_out<int> c;

	void add()
	{
		c = a + b;
	};

	SC_CTOR(adder){

		SC_METHOD(add);
		sensitive<<a<<b;
	}
};



#endif /* ADDER_H_ */
