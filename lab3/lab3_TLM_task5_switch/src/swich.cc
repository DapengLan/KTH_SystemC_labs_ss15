/*
 * swich.cc
 *
 *  Created on: Oct 13, 2015
 *      Author: parallels
 */

#include "swich.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using basic_protocol::basic_status;

sw::sw(sc_module_name module_name, int i) : //constructor
		sc_module(module_name), target_port1("iport1"),target_port2("iport2"),target_port3("iport3"),
		target_port0("iport4"),initiator_port1("iport5"),initiator_port2("iport6"),initiator_port3("iport7"),
		initiator_port0("iport8"),i(i) {
	target_port1(*this);
	target_port2(*this);
	target_port3(*this);
	target_port0(*this);

}

basic_status sw::write(const ADDRESS_TYPE &a, const DATA_TYPE &d) {
	if(a==0) {
		initiator_port0.write(a0, d);
		a0++;
	}

	if(a==1) {
		initiator_port1.write(a1, d);
		a1++;
	}

	if(a==2) {
		initiator_port2.write(a2, d);
		a2++;
	}

	if(a==3) {
		initiator_port3.write(a3, d);
		a3++;
	}
	return basic_protocol::SUCCESS;
}

basic_status sw::read(const ADDRESS_TYPE &a, DATA_TYPE &d) {
	cout << name() << " Memory " << i << ":reading at " << a << " value " << d
			<< endl;
	return basic_protocol::SUCCESS;
}

sw::~sw() {
}
