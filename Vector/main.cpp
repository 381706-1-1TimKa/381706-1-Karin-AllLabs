#include <iostream>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

int main()
{
	TMatrix<double> A(4), B(4);
	A[0][0] = 1;
	A[1][0] = 5;
	A[1][1] = 5;
	A[2][0] = 7;
	A[2][1] = 4;
	A[2][2] = 3;
	A[3][0] = 3;
	A[3][1] = 4;
	A[3][2] = 9;
	A[3][3] = 2;
	cout << A << endl;

	B[0][0] = 9;
	B[1][0] = 4;
	B[1][1] = 9;
	B[2][0] = 7;
	B[2][1] = 8;
	B[2][2] = 2;
	B[3][0] = 4;
	B[3][1] = 6;
	B[3][2] = 3;
	B[3][3] = 1;

	cout << B << endl;

	TMatrix<double> C(4);
	C = A / B;
	cout << C <<endl;
	return 0;

}