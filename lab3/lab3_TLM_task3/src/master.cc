/*
 *
 * SystemC TLM API Standard Proposal and Examples
 * Copyright Cadence Design Systems Inc 2004
 *
 */

#include "master.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

master::master( sc_module_name module_name ) :  //constructor
  sc_module( module_name ) , 
  initiator_port("iport")
{
  SC_THREAD( run );
}

void master::run()
{

  DATA_TYPE d;
  DATA_TYPE d_arr[10];
  DATA_TYPE average=0;
  DATA_TYPE sum = 0;


  ADDRESS_TYPE a[10]={11,15,12,3,33,35,21,18,55,41};
  srand (time(NULL));
  for (int j = 1 ; j < 6 ; j++) {

  for(int i = 0; i<10;i++){
	  d = rand() % 20 + 1;
	  initiator_port.write(a[i], d );
	    cout << "Writing Address " << a[i] << " value " << d << endl;
  }


  for(int i = 0; i<10;i++){
	  initiator_port.read(a[i], d );
	    cout << "Reading Address " << a[i] << " value " << d << endl;
	    d_arr[i] = d;
	    sum = sum + d_arr[i];
  }

  average = sum/10;
  cout << "The average" << j <<" \t of the random number is : "<< average << endl;

}

}
