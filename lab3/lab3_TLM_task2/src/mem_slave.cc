
/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2004 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.4 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/


#include "mem_slave.h"


using basic_protocol::basic_status;

mem_slave::mem_slave( sc_module_name module_name , int k , int i ) :
  sc_module( module_name ) ,
  target_port("iport"), i(i)
{

  target_port( *this );  // this point to own obeject  this == mem_slave;

  memory = new ADDRESS_TYPE[ k * 1024 ];    // here use the pointer,memory, so need the constructor;
 // memory = new ADDRESS_TYPE[ k * 1024 ];

}

basic_status mem_slave::write( const ADDRESS_TYPE &a , const DATA_TYPE &d )
{
	count_write++;
  cout << name() << " Memory " << i << ":writing at " << a << " value " << d << endl;
//	cout << "The transactions of read and write is :" << count<<endl;

  memory[a] = d;

  return basic_protocol::SUCCESS;
}

basic_status mem_slave::read( const ADDRESS_TYPE &a , DATA_TYPE &d )
{
	count_read++;
  d = memory[a];
  cout << name() << " Memory " << i << ":reading at " << a << " value " << d << endl;
  return basic_protocol::SUCCESS;
}
 
mem_slave::~mem_slave() {

  delete [] memory;
//	delete memory;
  cout << "The memory "<< i << " read transaction is :" << count_read<< endl;
  cout << "The memory "<< i << " write transaction is :" << count_write<<endl;

}

//this measure doesn't work;
/*void mem_slave::print_transaction() {
	cout << "The transactions of read and write is :" << count<<endl;

}*/
