/*
 * top.cpp
 *
 *  Created on: Sep 9, 2015
 *      Author: parallels
 */

#include "systemc.h"
#include "top.h"

int sc_main (int argc, char* argv[]){

	Top top("top");
	sc_start();
	return 0;
}



