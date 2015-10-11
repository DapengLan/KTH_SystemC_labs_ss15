/*
 * channel.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: parallels
 */

#include "channel.h"

void fifo::write(char c) {
	if (num_elements == max)
		wait(read_event);
	data[(first + num_elements) % max] = c;
	++num_elements;
	write_event.notify();
}

void fifo::read(char& c) {
	if (num_elements == 0)
		wait(write_event);
	c = data[first];
	--num_elements;
	first = (first + 1) % max;
	read_event.notify();
}

void fifo::reset() {
	num_elements = first = 0;
}
int fifo::num_available() {
	return num_elements;
}
