//============================================================================
// Name        : TLM_example.cpp
// Author      : dp
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "systemc.h"
//#include "tlm.h"  for tlm 2.0

class IF: virtual public sc_interface {
public:
	virtual void method() = 0;
};

class channel:public IF, public sc_object {
public:
	channel (char* _nm):sc_object(_nm) {}   // constructor? what is this means?
	virtual void method();
};

SC_MODULE(Child1) {
	sc_port<IF> port;
	SC_CTOR (Child1) {
		SC_THREAD(T);
	}
	void T() {
	  port->method();  // interface method call
	}
};



SC_MODULE(Child2) {
	sc_export<IF> export1;
	channel chan;

	SC_CTOR (Child2):chan("channel") {  //?
		export1.bind(chan);
	}
};

SC_MODULE(Parent) {
	Child1 *child1;
	Child2 *child2;

	SC_CTOR(Parent) {
		child1 = new Child1("child1");
		child2 = new Child2("child2");

		//top level port-to-export binding
		//Method bind() is equivalent to operator()

		child1->port.bind(child2->export1);

	}
};
