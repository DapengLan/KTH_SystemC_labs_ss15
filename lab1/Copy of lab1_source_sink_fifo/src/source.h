// file name = source.h

#include"systemc.h"
#include"channel.h"

class source : public sc_module
{
   public:

  //  sc_port<w_if> out;
	sc_fifo_out<char> out;
    SC_HAS_PROCESS(source);
//	sc_CTOR ()
    source(sc_module_name name) : sc_module(name)
     {

    	 SC_THREAD(source_p);
  /*  	while (true)
    		{
    		source_p();
    		}*/
//    	out->reset(); // reset the fifo
     };

     void source_p();
};
