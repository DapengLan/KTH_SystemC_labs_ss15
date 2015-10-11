/*
 * top.cpp
 *
 *  Created on: Sep 20, 2015
 *      Author: parallels
 */

#include "systemc.h"
#include "top.h"

int sc_main (int argc, char* argv[]){

	top top("top");
	sc_start();
	return 0;
}




