
#include "systemc.h"
#include "adder.h"

//instntiation in sc_module
/*SC_MODULE (add3in)
{
	sc_in<int> a,b,c;
	sc_out<int> f;
	adder adder1,adder2;
	sc_signal<int> i;

	SC_CTOR(add3in):adder1("adder1"),adder2("adder2"),i("internal") {
	adder1.a(a);
	adder1.b(b);
	adder1.c(i);

	adder2.a(i);
	adder2.b(c);
	adder2.c(f);
	}
};*/

//initialization via pointer
SC_MODULE (add3in)
{
	sc_in<int> a,b,c;
	sc_out<int> f;
	sc_signal<int> i;
	adder *adder1,*adder2;


	SC_CTOR(add3in) {
	adder1 = new adder("adder1");
	adder2 = new adder("adder2");

	adder1->a(a);
	adder1->b(b);
	adder1->c(i);

	adder2->a(i);
	adder2->b(c);
	adder2->c(f);

	}

/*
	~add3in{delete adder1;
	delete adder2;};
*/  //don't forget the branket
	~add3in (){delete adder1;
	delete adder2;}
};
