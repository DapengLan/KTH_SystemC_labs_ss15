/*
 * arbitor.h
 *
 *  Created on: Sep 20, 2015
 *      Author: parallels
 */

#ifndef ARBITOR_H_
#define ARBITOR_H_

#include "systemc.h"


SC_MODULE(arbitor)
{
	sc_in<char> char_in1;
	sc_in<char> char_in2;
	sc_out<bool> selector ;

	void prc_arbi();

	SC_CTOR(arbitor)
	{
	SC_THREAD (prc_arbi);
	sensitive << char_in1 << char_in2;
	}

};



#endif /* ARBITOR_H_ */

/*sc_clock( const char* name_,
      double         period_v_,
      sc_time_unit   period_tu_,
      double         duty_cycle_,
      double         start_time_v_,
      sc_time_unit   start_time_tu_,
      bool           posedge_first_ = true );*/
