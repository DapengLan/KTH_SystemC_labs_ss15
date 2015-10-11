/*
 * monitor.h
 *
 *  Created on: Sep 9, 2015
 *      Author: parallels
 */

#ifndef MONITOR_H_
#define MONITOR_H_

#include "systemc.h"

SC_MODULE(Monitor){
	sc_in<int> m_a;
	sc_in<int> m_b;
	sc_in<int> m_c;
	sc_in<bool> m_clk;


void pro_monitor();

	SC_CTOR(Monitor) {
		SC_METHOD(pro_monitor);
		sensitive<<m_a<<m_b<<m_c<<m_clk.pos();

	}
};



#endif /* MONITOR_H_ */