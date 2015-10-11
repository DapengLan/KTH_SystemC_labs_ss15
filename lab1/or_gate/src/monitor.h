/*
 * monitor.h
 *
 *  Created on: Sep 16, 2015
 *      Author: parallels
 */

#ifndef MONITOR_H_
#define MONITOR_H_

#include "systemc.h"

SC_MODULE (monitor){
	sc_in<sc_bit> m_a, m_b;
	sc_in<sc_bit> m_c;

	void prc_monitor();

	SC_CTOR(monitor)
	{
		SC_METHOD (prc_monitor);
		sensitive <<m_a<<m_b<<m_c;
	}
};





#endif /* MONITOR_H_ */
