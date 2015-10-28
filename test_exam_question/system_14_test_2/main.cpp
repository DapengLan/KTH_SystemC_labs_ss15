#include "systemc.h"
#include <iomanip>

using namespace std;
using std::setw;

class nb_write_if: virtual public sc_interface{
public:
	virtual bool nb_write(sc_int<64> ) = 0; //     write a character
	virtual void reset() = 0;			// empty the fifo
};

class nb_read_if: virtual public sc_interface{
public:
	virtual bool nb_read(sc_int<64>&) = 0; // read a character
};

class fifo_channel:public sc_module, public nb_write_if, public nb_read_if {
public:
	fifo_channel(sc_module_name nm , int _size):sc_module(nm),size(_size){
		data = new sc_int<64>[size];
		w = r = n = 0;
	}
	void reset() {
		w = r = n = 0;
	}
	bool nb_write(sc_int<64> c){
		if (n < size) {
			n ++;
			data[w++] = c;
			//	if(w==size) w = 0;
			return true;
		}
		else{
			cout << "nb_write_error" <<endl;
			cout << "the value of n is" << n <<endl;
		//	reset();
		return false;
		}
	}

	bool nb_read (sc_int<64>& c) {
		if(n>0){
			n--;
			c = data[r++];
		//		if(r == size) r=0;
			return true;
		}
		else {
			cout << "nb_read_error" <<endl;
		//	reset();
		return false;
		}
	}

private:
	sc_int<64>* data;
	sc_int<64> size;
	sc_int<64> w,r,n;

};

class sender:public sc_module {
public:
	//sc_port<nb_write_if> out;
//	sc_in<bool> clock;

	sc_out<sc_int<64> > out;
/*	void write_fifo () {
		int i = 0;
		sc_int<64> A[8] = {1,2,3,4,5,6,7,8};
		while (true) {
			wait(); // wait for clock edge
			if (out[i]-> nb_write(A[i]))
				cout << "Write FIFO " << A[i] <<"at" << sc_time_stamp() <<endl ;
			i++;
		}
	}*/
	void write() {
		int i = 0;
		sc_int<64> A[8] = {1,2,3,4,5,6,7,8};
		while (true) {

		 // wait for clock edge
			wait(10,SC_NS);
			out = A[i];
		//	cout<< "the value of cout is:" << out << endl;
			i = (i + 1) % 8;
		}
	}
	SC_CTOR(sender){
		SC_THREAD(write);
	//	sensitive << clock.pos();
	}
};

class receiver:public sc_module {
public:
	fifo_channel fifo1;
	sc_in <sc_int<64> > receiver_in;
	sc_int<64> y_temp;
	sc_int<64> y;

	void write_fifo () {
			while (true) {
				wait();
					if(fifo1.nb_write(receiver_in))
					cout << setw(20) << "Write FIFO: " <<receiver_in<<"  at" << sc_time_stamp() <<endl ;
			}
		}

	void Rprocess(){
		wait(20,SC_NS);
	while (true) {

		if( fifo1.nb_read(y_temp))
			{ cout << "y_temp is :" << y_temp <<endl;
			y = y_temp * 2;
		cout << setw(30) <<"Rprocess data: " <<y<<"  at" << sc_time_stamp() <<endl ;
			}
		wait(10,SC_NS);
	//	else
	//		cout << "error at the Rprocess: "<< endl;
	}
	}

	SC_CTOR(receiver):fifo1("fifo1",5){
		SC_THREAD(write_fifo);
			sensitive << receiver_in;
		SC_THREAD(Rprocess);

	}

};


class top: public sc_module {
public:
	//sc_clock clk1;
	sender send1;
	receiver rece1;
	sc_signal<sc_int<64> > i;
	SC_CTOR(top):send1("send1"),rece1("rece1"), i("internal"){
	//	send1.clock(clk1);
		send1.out(i);
		rece1.receiver_in(i);
	}

};

int sc_main(int argc, char *argv[]) {
	top top("top");
	sc_start(101, SC_NS);
	return (0);

}
