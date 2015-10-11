/*
 * monitor.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: parallels
 */

#include "monitor.h"

void monitor::prc_monitor() {
	cout <<"AT" << sc_simulation_time() << "input is :"<<endl;
	cout << m_a << "," << m_b << " out_put is: "<< m_c<<endl;
}


