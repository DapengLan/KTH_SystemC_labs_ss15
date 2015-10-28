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
			cout <<"  at" << sc_time_stamp()<< "nb_write_error" <<endl;
		return false;
		}
	}

	bool nb_read (sc_int<64>& c) {
		if(n>0){
			n--;
			c = data[r++];
			return true;
		}
		else {
			cout <<"  at" << sc_time_stamp()<< " :nb_read_error" <<endl;

		return false;
		}
	}

	//~data(){};
private:
	sc_int<64>* data;
	sc_int<64> size;
	sc_int<64> w,r,n;

};

class sender:public sc_module {
public:
	sc_out<sc_int<64> > out;
	void write() {
		int i = 0;
		sc_int<64> A[8] = {1,2,3,4,5,6,7,8};
		while (i<8) {
			out = A[i];
			i++;
			wait(10,SC_NS);
		}
	}
	SC_CTOR(sender){
		SC_THREAD(write);
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
					cout << setw(40) << "Write FIFO: " <<receiver_in<<"  at" << sc_time_stamp() <<endl ;
			}
		}

	void Rprocess(){
		wait(20,SC_NS);
	while (true) {

		if( fifo1.nb_read(y_temp))
			{ cout << "y_temp is :" << y_temp <<"  at" << sc_time_stamp() <<endl;
			y = y_temp * 2;
			cout << setw(70) <<"Rprocess data: " <<y<<"  at" << sc_time_stamp() <<endl ;
			}
		wait(10,SC_NS);
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
	sender send1;
	receiver rece1;
	sc_signal<sc_int<64> > i;
	SC_CTOR(top):send1("send1"),rece1("rece1"), i("internal"){
		send1.out(i);
		rece1.receiver_in(i);
	}
};

int sc_main(int argc, char *argv[]) {
	top top("top");
	sc_start(101, SC_NS);
	return (0);

}
