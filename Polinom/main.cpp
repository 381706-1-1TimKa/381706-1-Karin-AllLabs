#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	TStack<double> S(10);
	S.put(2);
	S.put(30);
	double A = S.Get();
	double B = S.Get();
	bool E = S.IsEmpty();
	bool F = S.IsFull();
	cout << A << endl << B << endl << E << endl << F << endl;
	return 0;
}