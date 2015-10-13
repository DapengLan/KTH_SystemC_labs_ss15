/*
 * switch.h
 *
 *  Created on: Oct 13, 2015
 *      Author: parallels
 */

#ifndef SWITCH_H_
#define SWITCH_H_

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


#include "systemc.h"



#include "basic_initiator_port.h"
using basic_protocol::basic_initiator_port;

#include "bus_types.h"
#include "basic_protocol.h"
#include "basic_slave_base.h"
using basic_protocol::basic_status;
using basic_protocol::basic_slave_base;
using tlm::tlm_transport_if;


class switch_2 :
  public sc_module ,
  public virtual basic_slave_base< ADDRESS_TYPE , DATA_TYPE >
{
public:
  switch_2( sc_module_name module_name);

  sc_export< if_type > target_port;
  basic_initiator_port<ADDRESS_TYPE,DATA_TYPE> initiator_port1;
  basic_initiator_port<ADDRESS_TYPE,DATA_TYPE> initiator_port2;

  basic_status write( const ADDRESS_TYPE & , const DATA_TYPE & ); //why const?
  basic_status read( const ADDRESS_TYPE & , DATA_TYPE & );

  int count_read=0;
  int count_write=0;

  ~switch_2();

};




#endif /* SWITCH_H_ */
