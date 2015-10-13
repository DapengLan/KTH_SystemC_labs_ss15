#include "master.h"
#include "mem_slave.h"
#include "switch.h"
//#include "tlm.h"
//#include "tlm_utils.h"
//#include "systemc.h"


int sc_main( int argc , char **argv )
{

	master m("master");
	mem_slave s1("slave1",4 , 1);  // size num K;
	mem_slave s2("slave2",4 , 2);  // size num K;

	switch_2 swi("switch");

  m.initiator_port( swi.target_port );
  swi.initiator_port1(s1.target_port);
  swi.initiator_port2(s2.target_port);

  sc_start(2000,SC_NS);

  return 0;

}