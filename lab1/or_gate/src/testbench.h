/*
 * testbench.h
 *
 *  Created on: Sep 16, 2015
 *      Author: parallels
 */

#include "systemc.h"

SC_MODULE (driver)
{
	sc_out<sc_bit> d_a;
	sc_out<sc_bit> d_b;

	void drivea();
	void driveb();

	SC_HAS_PROCESS(driver);
//	SC_CTOR(driver)
	driver (sc_module_name name)
	{
	//	SC_THREAD (drivea);
	//	SC_THREAD (driveb);
		SC_METHOD (drivea);
		SC_METHOD (driveb);

	}
};


