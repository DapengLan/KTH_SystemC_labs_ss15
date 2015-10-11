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
#include "tb_noise.h"

#include "check_parity.h"
#include "HextoBin.h"

using namespace std;

void tb_noise::copy_to_ram() {

	cout << "Begin copy to ram process..." << endl;
	ifstream ifs(in_name.c_str(), ifstream::in);

	int faddr;
	char fdata[10];
	while (!ifs.eof()) {
		ifs >> faddr >> fdata;
		address.write(faddr);
		//	wait(2,SC_NS); // no need
		data.write(strtol(fdata, NULL, 16));
		wait(2, SC_NS);
	}
	cout << "copy_to_ram finish" << endl;
	ifs.close();
}

void tb_noise::check_mem() {
	int faddr;
	char fdata[10]; //	string fdata;
	int i = 0;
	int mem_check_flag = 0;
	int odd_parity_value = 0;
	int err_correction_flag = 0;
	ifstream datafile;
	ofstream errfile;

	if (memA_flag == 1) {  //check which memory A or B
		wait(2, SC_NS);
		cout << "\n Begin check RAM A for errors" << endl;

	} else if (memB_flag == 1) {
		wait(6000000, SC_NS);  // wait for memA finish
		cout << "\n Begin check RAM B for errors" << endl;
	}
	// MEMORY check mode
	datafile.open(in_name.c_str());
	string file_data[1045] = { "" };
	wait(2, SC_NS);
	// Read the file data to an array
	while (!datafile.eof()) {
		datafile >> faddr >> fdata;
		if (faddr >= addr_last.read() + 1)
			break;
		file_data[faddr] = fdata;
	}
	//compare the RAM and the T1;check for errors and write to the error file
	errfile.open(out_name.c_str());
	while (i <= addr_last.read()) {

		address.write(i);
		wait(2, SC_NS);
		//	cout<<"TB_Address: "<<i<<"\t"<<"Testbech read data:"<< data.read() << endl;

		char *a = (char *) file_data[i].c_str(); //after file_data[i].c_str() is a pointer
		string mem_data_string;
		mem_data_string = data.read().to_string(SC_BIN, true);
		//  cout << "mem_data_string: " << mem_data_string << endl;
		if (data.read() != strtol(a, NULL, 16)) {
			odd_parity_value = check_odd_parity(mem_data_string);
			string correct_data = correct_odd_parity(mem_data_string, a);
			err_correction_flag = 1;
			// ------------ Write the correct data to memory ------------
			if (correct_data != "0b0" + HexToBin(file_data[i])) {
				cout << "correct_data process: " << endl;

				errfile << "addr:" << i << "\t file:" << file_data[i]
						<< "\t ram:" << data.read() << "\t" << "oddparity :"
						<< odd_parity_value << endl;
				mem_check_flag = 1;
			}
			// ------------ Write the correct data to memory ------------
			else {
				// ------------ Enter RAM write mode ------------
				ce = 1;
				ce = 1;
				address.write(i);
				data.write(
						strtoul(file_data[i].substr(0, 2).c_str(), NULL, 16));
				errfile << "addr:" << i << "\t file:" << file_data[i]
						<< "\t ram:" << data.read() << "; \t Corrected ram:"
						<< correct_data << "\t" << "oddparity :"
						<< odd_parity_value << endl;
				wait(2, SC_NS);
			}
			/* no_correction
			 * errfile << "addr:"<<i <<"\t file:"<< file_data[i]  <<"\t ram:"<<data.read() <<"\t"<<"oddparity :"<< odd_parity_value <<endl;
			 *mem_check_flag == 1*/
		}
		i++;
	}
	if (mem_check_flag == 1) {
		cout << "MEMORY has some errors, check the file:" << out_name << endl;
	}
	if (err_correction_flag) {
		cout << "MEMORY has some errors, they are corrected" << out_name
				<< endl;
	}
	cout << "\n RAM check complete!..............";
	errfile.close();
	check_done.notify();
	cout << "Check the mem: done" << endl;
}

void tb_noise::test() {
	//test case 3.3.  Check the noise1 of T3.txt
	cout << "\n ------------ Test 3 : Check the noise[1] of T3.txt ------------"
			<< endl;
	ce = 1;
	in_name =
			"/home/parallels/Documents/workspace/lab2/ lab2_memory_component/T3.txt";
	we = 0;
	wait(check_done);
}

