
#include "swich.h"
#include "node.h"
//#include "tlm.h"
//#include "tlm_utils.h"
//#include "systemc.h"


int sc_main( int argc , char **argv )
{

	node n0("node0",1,0,"/home/parallels/workspace/Systemc_lab_KTH/lab3/lab3_TLM_task5_switch/node0.txt");
	node n1("node1",1,1,"/home/parallels/workspace/Systemc_lab_KTH/lab3/lab3_TLM_task5_switch/node1.txt");
	node n2("node2",1,2,"/home/parallels/workspace/Systemc_lab_KTH/lab3/lab3_TLM_task5_switch/node2.txt");
	node n3("node3",1,3,"/home/parallels/workspace/Systemc_lab_KTH/lab3/lab3_TLM_task5_switch/node3.txt");

	sw s1("switch1",0);

	n0.initiator_port(s1.target_port0);
	n1.initiator_port(s1.target_port1);
	n2.initiator_port(s1.target_port2);
	n3.initiator_port(s1.target_port3);

	s1.initiator_port0(n0.target_port);
	s1.initiator_port1(n1.target_port);
	s1.initiator_port2(n2.target_port);
	s1.initiator_port3(n3.target_port);

  sc_start(20000,SC_NS);

  return 0;

}
