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

#include "master.h"
#include "mem_slave.h"
//#include "tlm.h"
//#include "tlm_utils.h"
//#include "systemc.h"


int sc_main( int argc , char **argv )
{

	master m("master");
	mem_slave s("slave",4);  // size num K;

  m.initiator_port( s.target_port );

  sc_start(2000,SC_NS);

  return 0;

}