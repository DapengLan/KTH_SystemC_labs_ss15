#include "switch.h"


using basic_protocol::basic_status;

switch_2::switch_2( sc_module_name module_name) :
  sc_module( module_name ),
  target_port("tport2"),initiator_port1("iport1"),initiator_port2("iport2")
{
  target_port( *this );  // this point to own obeject  this == mem_slave;
}

basic_status switch_2::write( const ADDRESS_TYPE &a , const DATA_TYPE &d )
{

	count_write++;
	if (a%2==1) {
		initiator_port1.write(a,d);
		 cout << name() << " writing at [odd] memory " << a << " value " << d << endl;
	} else
		{initiator_port2.write(a,d);
		 cout << name() << " writing at [even] memory " << a << " value " << d << endl;
		}

  return basic_protocol::SUCCESS;
}

basic_status switch_2::read( const ADDRESS_TYPE &a , DATA_TYPE &d )
{
	count_read++;
	if (a%2==1) {
		initiator_port1.read(a,d);
		 cout << name() << " read at [odd] memory " << a << " value " << d << endl;
	} else
		{initiator_port2.read(a,d);
		 cout << name() << " read at [even] memory " << a << " value " << d << endl;
		}
  return basic_protocol::SUCCESS;
}

switch_2::~switch_2() {
//	delete memory;
  cout << "The switch transaction read is :" << count_read<<endl;
  cout << "The switch transaction write is :" << count_write<<endl;
}
