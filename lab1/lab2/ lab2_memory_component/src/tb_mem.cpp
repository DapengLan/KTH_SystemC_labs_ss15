/*
 * tb_mem.cpp
 *
 *  Created on: Oct 8, 2015
 *      Author: parallels
 */

#include <iostream>
#include "systemc.h"
#include <string.h>
#include <fstream>
#include "memory.h"
#include "tb_mem.h"

using namespace std;

void tb_mem::copy_to_ram(){
//	wait(check_event);
//	next_trigger(check_event);
	cout<<"Begin copy to ram process..." <<endl;
	ifstream ifs(in_name.c_str(),ifstream::in);
//	ifstream ifs("/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T1.txt",ifstream::in);

	int faddr;
	char fdata[10];
	while(!ifs.eof()) {
		ifs>>faddr>>fdata;
	//	cout<<"Writing into T2 data: " << faddr << "  " <<fdata << endl;
		address.write(faddr);
	//	wait(2,SC_NS); // no need
		data.write(strtol(fdata,NULL,16));
		wait(2,SC_NS);
	}
//	addr_last.write(faddr - 1);
	cout<<"copy_to_ram finish"<<endl;
	ifs.close();
//	check_init.notify();
}

void tb_mem::check_mem() {
	// initial
	int faddr;
	char fdata[10];
	int i = 0;
	int mem_check_flag = 0;
	ifstream datafile;
	ofstream errfile;

	// MEMORY check mode
	datafile.open(in_name.c_str());
	cout<<"\n Begin check RAM for errors"<<endl;
	string file_data[1045] = { "" };
	wait(2,SC_NS);
	// Read the file data to an array
	while (!datafile.eof()) {
		datafile>>faddr>>fdata;
		if (faddr >= addr_last.read()+1) break;
		file_data[faddr] = fdata;
	}
	//compare the RAM and the T1;check for errors and write to the error file
	errfile.open(out_name.c_str());
	while ( i <= addr_last.read()) {
	//	ce = 1;
	//	we = 1;
		address.write(i);
		wait(2,SC_NS);
	//	cout<<"TB_Address: "<<i<<"\t"<<"Testbech read data:"<< data.read() << endl;
	//	cout<<"test the ce:"<<ce << endl;
	//	cout<<"test the address:"<<i << endl;
		char *a = (char *)file_data[i].c_str();
		if(data.read() != strtol(a, NULL, 16)) {
			errfile << "addr:"<<i <<"\t file:"<< file_data[i]  <<"\t ram:"<<data.read() << endl;
	//		cout <<"the last address is:" << addr_last.read()<<endl;
			mem_check_flag = 1;
		}
		i ++ ;
	}
	if(mem_check_flag == 1) { cout<<"MEMORY has some errors, check the file:" << out_name<< endl; }

	errfile.close();
	check_done.notify();
}

void tb_mem::test() {
	//test case 3.1.  Check initialization of T1.txt
	cout << "\n ------------ Test 1 : Check initialization of T1.txt ------------"<<endl;
	in_name = "/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T1.txt";
	out_name = "/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T1_error.txt";
	ce=1;
	we=0;
	//	check_event.notify();
	wait (check_done);

	//Test case 3.2 Check write the data T2.txt
	cout << "\n ------------ Test 2 : Check write the data T2.txt ------------"<<endl;
	in_name = "/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T2.txt";
	out_name = "/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T2_error.txt";
	ce=1;
	we=1;//	check_event.notify();
	copy_to_ram();
	we = 0;
	check_mem();

	// Test case 3 :Write OP when CE = '0'------------
	cout << "\n ------------ Test 3 : Write OP when CE = '0' ------------"<<endl;;
	int wr_address = 1000;
	ce = 0;
	we = 1;
	address.write(wr_address);
	data.write("10110011");
	//wait (check_done);

	// Test case 4 :Read OP when CE = '0' ------------
	cout << "\n ------------ Test 4 : Read OP when CE = '0' ------------"<<endl;
	wr_address = 1000;
	ce = 0;
	we = 0;
	address.write(wr_address);
	wait(2, SC_NS);
	cout << "\n mem[" << wr_address << "] : " << data.read().to_string(SC_HEX, true)<<endl;
//Test case 5 (Out of range address) ------------
	cout << "\n ------------ Test 5 : Out of range address ------------";
	wr_address = 1080;
	ce=1;
	we=0;
	address.write(wr_address);
	wait(5, SC_NS);
	cout << "\n men[" << wr_address << "] : " << data.read().to_string(SC_HEX, true);
	//check_event.notify();
}

