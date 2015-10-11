/*
 * add3in.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: parallels
 */

#include "systemc.h"
#include "adder.h"
#include "add3In.h"



int sc_main(int argc, char *argv[]) {
	sc_signal<int> ta("ta"), tb("tb"), tc("tc"), td("td");

	add3in myadder("myadder");  // module instance in sc_main is a valuable;

	myadder.a(ta);
	myadder.b(tb);
	myadder.c(tc);
	myadder.f(td);

	sc_start();

	return 0;
}


