/*
 * channel.h
 *
 *  Created on: Sep 16, 2015
 *      Author: parallels
 */
#include "systemc.h"
#pragma once

class w_if: virtual public sc_interface {
public:
	virtual void write(char) = 0; //     write a character
	virtual void reset() = 0;			// empty the fifo
};

class r_if: virtual public sc_interface {
public:
	virtual void read(char &) = 0; // read a character
	virtual int num_available() = 0;
};

class fifo: public sc_channel, public w_if, public r_if {
public:
	SC_CTOR(fifo) { // channel constructor
		num_elements = first = 0;
	}
	void write(char );
	void read(char &);
	void reset();
	int num_available() ;
private:
	enum e {
		max = 26//max is just a constant in class scope
	};

	char data[max];
	int num_elements, first;
	sc_event write_event, read_event;
};
