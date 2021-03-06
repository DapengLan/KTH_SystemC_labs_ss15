#include "node.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using basic_protocol::basic_status;

node::node(sc_module_name module_name, int k, int i ,string in_file) : //constructor
		sc_module(module_name), target_port("iport"), initiator_port("iport"), i(i),in_file (in_file) {
	target_port(*this);
	memory = new ADDRESS_TYPE[k * 1024];
	SC_THREAD(run);
}

basic_status node::write(const ADDRESS_TYPE &a, const DATA_TYPE &d) {
	count_receive++;
	cout << name() << " Memory " << i << ":writing at " << a << " value " << d
			<< endl;
	memory[a] = d;
	return basic_protocol::SUCCESS;
}

basic_status node::read(const ADDRESS_TYPE &a, DATA_TYPE &d) {
	//count_read++;
	d = memory[a];
	cout << name() << " Memory " << i << ":reading at " << a << " value " << d
			<< endl;
	return basic_protocol::SUCCESS;
}

node::~node() {
	cout <<  endl;
	for(int j = 0; j < count_receive; j++) {
		cout << "The Node " << i << " received data is :" <<"["<<dec<< j << "]"<< hex << memory[j]
				<< endl;
	}
	delete[] memory;
	cout << "The Node " << i << " count_receive is :" <<dec << count_receive
			<< endl;
	cout << "The Node " << i << " count_transmit is :" <<dec << count_transmit
			<< endl;
	cout <<  endl;

}

void node::run() {
	cout << "\n Reading the Node:"<< i <<".txt file.............." << endl;
	ADDRESS_TYPE faddr=1;
	DATA_TYPE fdata=1;
	ifstream datafile(in_file.c_str());
	while ( !datafile.eof() ) {
		datafile >>dec>> faddr >>hex>> fdata;
		cout << "Node:"<<i<<" Writing Address: " << faddr << " value: " << fdata << endl;
		initiator_port.write(faddr, fdata);
		count_transmit++;
	}
	datafile.close();
		}

