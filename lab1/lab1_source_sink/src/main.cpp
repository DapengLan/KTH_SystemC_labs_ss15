/*
 * main.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: parallels
 */

#include "systemc.h"
#include "source.h"
#include "sink.h"
#include "channel.h"

int sc_main (int argc, char* argv[]) {

	fifo *fifo_inst; // a fifo instance
//	sc_fifo<char> *fifo_inst; // a fifo instance
	source *source_inst; // a producer instance
	sink *sink_inst; // a consumer instance

	source_inst = new source ("source1");
	fifo_inst = new fifo ("fifo1");
	source_inst -> out(*fifo_inst);

	sink_inst = new sink ("sink1");
	sink_inst -> in(*fifo_inst);

	sc_start();

	return 0;
}




