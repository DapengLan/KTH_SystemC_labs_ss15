#include "systemc.h"
#include <iomanip>

using namespace std;
using std::setw;

class top: public sc_module {
public:
	int x;
	int y;
	int z;
//	sc_event produce_x_done;
//	sc_event produce_y_done;
//	sc_event produce_y_done;
	int arrayx[11];
	int arrayy[11];
	int arrayz[11];
	void prox() {
		arrayx[0] = 0;
		cout << "[x] is: " << sc_time_stamp() << " value: " << arrayx[0]<< endl;
		wait(2, SC_NS);

		for (int i = 1; i < 11; i++) {
			arrayx[i] = i;
			cout << "[x] is: " << sc_time_stamp() << " value: " << arrayx[i]<< endl;
			wait(2, SC_NS);
		}
	}

	void proy() {
		arrayy[0] = 0;
		cout << setw(35) << "y is: " << sc_time_stamp() << " value: "<< arrayy[0] << endl;
		wait(5, SC_NS);

		for (int j = 1; j < 11; j++) {
			arrayy[j] = 2 * arrayx[j];
			cout << setw(35) << "y is: " << sc_time_stamp() << " value: "<< arrayy[j] << endl;
			wait(3, SC_NS);
		}
	}

	void proz() {
		arrayz[0] = 0;
		cout << setw(60) << " {z} is: " << sc_time_stamp() << " value: "<< arrayz[0] << endl;
		wait(5, SC_NS);

		for (int z = 1; z < 11; z++) {
			wait(4, SC_NS);
			arrayz[z] = arrayx[z] + arrayy[z];
			cout << setw(60) << " {z} is: " << sc_time_stamp() << " value: "<< arrayz[z] << endl;

		}
	}

	SC_CTOR(top) {
		SC_THREAD(prox);
		SC_THREAD(proy);
		SC_THREAD(proz);
	}

};

//simulate 45ns
int sc_main(int argc, char *argv[]) {
	top top("top");
	sc_start(46, SC_NS);
	return (0);

}
