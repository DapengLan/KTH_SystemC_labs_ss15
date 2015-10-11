
#include "systemc.h"

struct Adder : sc_module {	//port, processes, internal data,etc.
	sc_in<int> a;
	sc_in<int> b;
	sc_out<int> c;

	void compute () ;

	SC_CTOR (Adder) {
		SC_METHOD (compute);
		sensitive << a << b;
	}
};
