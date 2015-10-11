/*
 * testbench.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: parallels
 */

#include "testbench.h"

/*
void driver::drivea() {
	d_a.write((sc_bit)false);
	wait(5,SC_NS);
	d_a.write((sc_bit)true);
	wait(5,SC_NS);
	d_a.write((sc_bit)false);
	wait(5,SC_NS);
	d_a.write((sc_bit)true);
	wait(5,SC_NS);
}

void driver::driveb() {
	d_b.write((sc_bit)false);
	wait(10,SC_NS);
	d_b.write((sc_bit)true);
	wait(10,SC_NS);
}

*/

void driver::drivea() {
	d_a.write((sc_bit)false);
	next_trigger(5,SC_NS);
	d_a.write((sc_bit)true);
	next_trigger(5,SC_NS);
	d_a.write((sc_bit)false);
	next_trigger(5,SC_NS);
	d_a.write((sc_bit)true);
	next_trigger(5,SC_NS);
}

void driver::driveb() {
	d_b.write((sc_bit)false);
	next_trigger(10,SC_NS);
	d_b.write((sc_bit)true);
	next_trigger(5,SC_NS);
}


