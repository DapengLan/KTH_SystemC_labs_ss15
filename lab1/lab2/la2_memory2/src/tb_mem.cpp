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
	ifstream ifs(in_name.c_str(),ifstream::in);
	int faddr,fdata;
	while(!ifs.eof()) {
		ifs>>dec>>faddr>>hex>>fdata;
		address.write(faddr);
		wait(2,SC_NS);
		data.write(fdata);
		wait(2,SC_NS);
	}
	cout<<"copy_to_ram finish"<<endl;
	ifs.close();
}

void tb_mem::check_mem() {
	// initial
	int faddr,fdata;
	string in_name,out_name;
	int i = 0;
	int mem_check_flag = 0;
	ifstream datafile;
	ofstream errfile;

	// MEMORY check mode
	datafile.open(in_name.c_str());
	cout<<"\n check RAM for errors"<<endl;
	unsigned int file_data[1045];
	wait(2,SC_NS);
	// Read the file data to an array
	while (!datafile.eof()) {
		datafile>>dec>>faddr>>hex>>fdata;
		if (faddr >= addr_last) break;
		file_data[faddr] = fdata;
	}
	//compare the RAM and the T1;check for errors and write to the error file
	errfile.open(out_name.c_str());
	while ( i <= addr_last.read()) {
		ce = 1;
		we = 0;
		address.write(i);
		wait(2,SC_NS);
		cout<<"test the data:"<<data.read() << endl;
		if(data.read()!= file_data[i]) {
			errfile << "addr:"<<i <<"\t file:"<< file_data[i]  <<"\t ram:"<<data.read() << endl;
			mem_check_flag = 1;
		}
		i ++ ;
	}
	if(mem_check_flag = 1) { cout<<"MEMORY has some errors, check the file:" << out_name<< endl; }
	check_done.notify();
	errfile.close();
}

void tb_mem::test() {
	//test case 3.1
	cout << "test case 1, compare memory data with T1.txt " << endl;
	in_name = "/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T1.txt";
	out_name = "/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T1_error.txt";
	wait (check_done);
}
