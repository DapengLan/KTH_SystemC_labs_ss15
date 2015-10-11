/*
 * top.h
 *
 *  Created on: Sep 20, 2015
 *      Author: parallels
 */

#ifndef TOP_H_
#define TOP_H_

#include "systemc.h"
#include "arbitor.h"
#include "change_case.h"
#include "filter.h"
#include "arbitor.h"
#include "m_bus.h"
#include "testbench.h"
#include "UART.h"

SC_MODULE (top) {
	sc_signal<char> sig_driver_char_out;
	sc_signal<char> sig_case_char_out;
	sc_signal<char> sig_fil_char_out;

	sc_signal<bool> m_selector;
	sc_signal<char> m_bus_char_out;

	sc_signal<char> uart_char_out;

	arbitor arbi;
	filter fil;
	m_bus mbus;
	driver dri;
	monitor moni;
	UART uart;
	change_case c_case;

	SC_CTOR(top):arbi("arbi"),fil("fil"),mbus("mbus"),dri("dri"),moni("moni"),uart("uart"),c_case("c_case")
	{
		dri.d_char(sig_driver_char_out);

		c_case.char_in(sig_driver_char_out);
		c_case.char_out(sig_case_char_out);

		fil.char_in(sig_driver_char_out);
		fil.char_out(sig_fil_char_out);

		arbi.char_in1(sig_case_char_out);
		arbi.char_in2(sig_fil_char_out);
		arbi.selector(m_selector);

		mbus.char_in1(sig_case_char_out);
		mbus.char_in2(sig_fil_char_out);
		mbus.selector(m_selector);
		mbus.char_out(m_bus_char_out);

		uart.char_in(m_bus_char_out);
		uart.char_out(uart_char_out);

		moni.m_char(uart_char_out);
	}
};



#endif /* TOP_H_ */
