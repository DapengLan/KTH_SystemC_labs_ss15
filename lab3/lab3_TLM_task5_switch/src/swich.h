/*
 * swich.h
 *
 *  Created on: Oct 13, 2015
 *      Author: parallels
 */

#ifndef SWICH_H_
#define SWICH_H_

#include "bus_types.h"
#include "basic_initiator_port.h"

#include "systemc.h"
#include "basic_protocol.h"
#include "basic_slave_base.h"

using basic_protocol::basic_status;
using basic_protocol::basic_slave_base;
using tlm::tlm_transport_if;

using basic_protocol::basic_initiator_port;

class sw:
  public sc_module ,
  public virtual basic_slave_base< ADDRESS_TYPE , DATA_TYPE >
{
public:
  sw( sc_module_name module_name ,int i );

  basic_initiator_port<ADDRESS_TYPE,DATA_TYPE> initiator_port1;
  basic_initiator_port<ADDRESS_TYPE,DATA_TYPE> initiator_port2;
  basic_initiator_port<ADDRESS_TYPE,DATA_TYPE> initiator_port3;
  basic_initiator_port<ADDRESS_TYPE,DATA_TYPE> initiator_port0;

  sc_export< if_type > target_port1;
  sc_export< if_type > target_port2;
  sc_export< if_type > target_port3;
  sc_export< if_type > target_port0;

  int i;
  basic_status write( const ADDRESS_TYPE & , const DATA_TYPE & );
  basic_status read( const ADDRESS_TYPE & , DATA_TYPE & );

  ~sw();
private:
  ADDRESS_TYPE a0=0;
  ADDRESS_TYPE a1=0;
  ADDRESS_TYPE a2=0;
  ADDRESS_TYPE a3=0;
};


#endif /* SWICH_H_ */
