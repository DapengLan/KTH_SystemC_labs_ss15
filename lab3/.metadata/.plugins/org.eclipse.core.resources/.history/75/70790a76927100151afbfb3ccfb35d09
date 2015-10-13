/*
 *
 * SystemC TLM API Standard Proposal and Examples
 * Copyright Cadence Design Systems Inc 2004
 *
 */

#include "master.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

master::master(sc_module_name module_name, int i) :  //constructor
		sc_module(module_name), i(i), initiator_port("iport") {
	SC_THREAD(run);
}

void master::run() {

	DATA_TYPE d;
	if (i == 1) {
		for (ADDRESS_TYPE a = 0; a < 20; a++) {
			initiator_port.write(a, 1);
			cout << "MEM[" << i << "]Writing Address " << a << " value :" << 1
					<< endl;
		}
	}

	if (i == 2) {
		wait(10,SC_NS);
		for (ADDRESS_TYPE a = 0; a < 20; a++) {
			initiator_port.write(a, 2);
			cout << "MEM[" << i << "]Writing Address " << a << " value :" << 2
					<< endl;
		}
	}

	if (i == 3) {
		wait(10,SC_NS);
		for (ADDRESS_TYPE a = 0; a < 20; a++) {
			initiator_port.read(a, d);
			cout << "MEM[" << i << "]Reading Address " << a << " value :" << d
					<< endl;
		}
	}
}

