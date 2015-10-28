

#include "systemc.h"
#include "memory.h"


 int sc_main(int argc, char* argv[]) {

 // sc_clock Clock("TestClock",10,SC_NS,0.5);
	 sc_clock Clock;
  memory m1("m1");
  m1.clk(Clock);
  sc_start(10000,SC_NS);

  return(0);
  }

