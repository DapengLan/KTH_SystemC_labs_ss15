/*
 * top.h
 *
 *  Created on: Sep 9, 2015
 *      Author: parallels
 */

#ifndef TOP_H_
#define TOP_H_
//connect togother using the channel..
#include "adder.h"
#include "stimulus.h"
#include "monitor.h"
#include "systemc.h"

SC_MODULE(Top){
	sc_signal<int> siga, sigb, sigc;
	sc_clock testclk;

	sc_trace_file* tracefile;

	Stimulus stim;
	Adder dut;
	Monitor mon;


	SC_CTOR(Top):testclk("testclk"), stim("stim"), dut("dut"), mon("mon") {
		stim.s_a (siga);
		stim.s_b (sigb);
		stim.clk (testclk);

		dut.a (siga);
		dut.b (sigb);
		dut.c (sigc);
		//dut(siga,sigb,sigc);

		mon.m_a(siga);
		mon.m_b(sigb);
		mon.m_c(sigc);
		mon.m_clk(testclk);
		tracefile = sc_create_vcd_trace_file("tracefile");

		sc_trace (tracefile, siga,"siga");
		sc_trace (tracefile, sigb,"sigb");
		sc_trace (tracefile, sigc,"sigc");
		sc_trace (tracefile, testclk,"testclk");
	}

	~Top() {
		sc_close_vcd_trace_file(tracefile);
	};
};




#endif /* TOP_H_ */
