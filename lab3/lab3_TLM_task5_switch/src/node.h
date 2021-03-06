/*
 * node.h
 *
 *  Created on: Oct 13, 2015
 *      Author: parallels
 */
#include <iostream>
#include <fstream>
#include <string>

#include "bus_types.h"
#include "basic_initiator_port.h"

#include "systemc.h"
#include "basic_protocol.h"
#include "basic_slave_base.h"

using namespace std;
using basic_protocol::basic_status;
using basic_protocol::basic_slave_base;
using tlm::tlm_transport_if;

using basic_protocol::basic_initiator_port;

class node :
  public sc_module ,
  public virtual basic_slave_base< ADDRESS_TYPE , DATA_TYPE >
{
public:
  node( sc_module_name module_name , int k,int i ,string in_file );

  SC_HAS_PROCESS( node );
  basic_initiator_port<ADDRESS_TYPE,DATA_TYPE> initiator_port;
  sc_export< if_type > target_port;

  int i;
  string in_file;
  basic_status write( const ADDRESS_TYPE & , const DATA_TYPE & );
  basic_status read( const ADDRESS_TYPE & , DATA_TYPE & );

  int count_transmit = 0;
  int count_receive=0;
  ~node();
private:
  ADDRESS_TYPE *memory;
  void run();
};

