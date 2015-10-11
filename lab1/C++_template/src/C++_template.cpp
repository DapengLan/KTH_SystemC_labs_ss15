//============================================================================
// Name        : C++_template.cpp
// Author      : DapengLan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <class T>
T GetMax (T a, T b) {
	T result;
	result = (a>b)? a:b;
	return (result);
}

int main() {
	int i = 5, j =6, k;
	long l = 10, m =5, n;
	k= GetMax<long>(i,j);
	n= GetMax(l,m);

	cout << "k:" << k <<endl;
	cout << "n:" << n <<endl;
	return 0;
}
