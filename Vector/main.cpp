#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	TVector <int> A(2);
	TVector <double> B(2);
	cin >> A;
	cin >> B;
	cout << "A=" << endl << A << endl;
	cout <<"B="<<endl<<B<<endl;
	return 0;
}