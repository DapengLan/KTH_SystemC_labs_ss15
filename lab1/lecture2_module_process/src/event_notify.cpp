/*
 * event_notify.cpp
 *
 *  Created on: Sep 26, 2015
 *      Author: parallels
 */

#include "systemc.h"

SC_MODULE(Test) {
	int data;
	sc_event e;

	SC_CTOR(Test) {
		SC_THREAD (producer);
		SC_THREAD (consumer);
	}

	void producer() {
		wait(1,SC_NS);
		for (data = 0; data < 100; data ++){
			e.notify();
			wait(1,SC_NS);
		}
	}
	void consumer() {
		for(;;){
			wait(e);
			cout<<"Received"<<data<<endl;
		}
	}
};




