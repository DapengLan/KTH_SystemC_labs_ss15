/*
 * stimulus.cpp
 *
 *  Created on: Sep 9, 2015
 *      Author: parallels
 */

#ifndef STIMULUS_CPP_
#define STIMULUS_CPP_

#include "stimulus.h"

void Stimulus::generate() {
	wait();
	s_a= 100; s_b =200;
	wait();
	s_a = -100; s_b = -200;
	wait();
	s_a = 100; s_b = -100;
	wait();
	sc_stop();
};




#endif /* STIMULUS_CPP_ */
