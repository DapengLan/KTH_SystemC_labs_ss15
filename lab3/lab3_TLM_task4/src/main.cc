#include "master.h"
#include "mem_slave.h"
//#include "tlm.h"
//#include "tlm_utils.h"
//#include "systemc.h"


int sc_main( int argc , char **argv )
{

	master m1("master1",1);
	master m2("master2",2);
	master m3("master3",3);
	mem_slave s1("slave1",4 , 1);  // size num K;

  m1.initiator_port( s1.target_port1 );
  m2.initiator_port( s1.target_port2 );
  m3.initiator_port( s1.target_port3 );

  sc_start(2000,SC_NS);

  return 0;

}
