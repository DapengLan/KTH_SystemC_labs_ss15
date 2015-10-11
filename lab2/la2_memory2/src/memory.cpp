#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "systemc.h"
#include <fstream>
#include <bitset>
#include "memory.h"
using namespace std;

void memory::entry() {
	if (address.read() > addr_last) {
		SC_REPORT_ERROR ( "","out of range memory size");
	} else {
		if (ce.read() == 1) {
			cout << "ce:1@" << sc_time_stamp () << endl;
			if(we.read() == 1) {
				mem_temp[address.read()] = data.read();  //write into memory
			} else {
				data.write(mem_temp[address.read()]); //read from memory //to_int?
			}
		} else {
			cout << "ce=0:@" << sc_time_stamp () << endl;
			if(we.read() == 1) {NULL;}  //write nothing into memory
			else {data.write ( 0xFF );}
		}
	}
}

void memory::memread() {
	ifstream ifs(in_name.c_str(),ifstream::in);
	int faddr;
	int fdata;
	while (!ifs.eof()) {
		ifs >> dec >> faddr >> hex >> fdata;
		if (faddr >= MEMSIZE)
			break;
		mem_temp[faddr] = fdata;
		cout << dec << faddr << "  " << hex << mem_temp[faddr] << endl;
	}
	addr_last.write(faddr - 1);
	ifs.close();
}

void memory::memwrite() {
	ofstream myfile("T4", ofstream::out);
	for (int i = 0; i < MEMSIZE; i ++) {
		myfile << dec << i  << "  " << hex << mem_temp[i] << endl;
		cout << "success" << endl;
	}
	myfile.close();
}
