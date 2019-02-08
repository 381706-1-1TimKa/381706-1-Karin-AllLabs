#include <iostream>
#include "Vector.h";
#include "Matrix.h"

#define fortravis
using namespace std;

#ifdef fortravis
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
	cout << "A =" << endl<< endl << A << endl << endl;

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

	cout <<"B ="<< endl << endl << B << endl << endl;

	TMatrix<double> C(4);
	C = A * B;
	cout << "A*B="<<endl << endl << C << endl << endl;
	C = A / B;
	cout << "A/B=" << endl << endl << C << endl << endl;
	C = A + B;
	cout << "A+B=" << endl << endl << C << endl << endl;
	C = A - B;
	cout << "A-B=" << endl << endl << C << endl << endl;
	double det = A.GetDet();
	cout << "determinant A = " << det << endl << endl;
	C = B.GetInvers();
	cout << "B^-1 = " << endl << endl << C << endl << endl;
	
	return 0;

}
#endif

#ifndef fortravis
void Menu(int size);

int main()
{
	try
	{
		cout << "Enter the size of Matrix" << endl;
		cout << "Warning: you can not choose it later" << endl;
		int n;
		cin >> n;
		Menu(n);
		return 0;
	}
	catch (TException ex)
	{
		ex.Print();
	}
}

void Menu(int size)
{
	TMatrix<double> A(size), B(size), C(size), T(size);
	while (1)
	{
		cout << "_______________________________" << endl;
		cout << "What you want to do?" << endl;
		cout << "1) Enter Matrix" << endl;
		cout << "2) A+B" << endl;
		cout << "3) A-B" << endl;
		cout << "4) A*B" << endl;
		cout << "5) A/B" << endl;
		cout << "6) A <-> B" << endl;
		cout << "7) Determinant A" << endl;
		cout << "8) Invers A" << endl;
		cout << "9) Print" << endl;
		cout << "10) Result in A" << endl;
		cout << "11) Exit A" << endl;
		cout << "_______________________________" << endl<<endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "Enter A" << endl;
			cin >> A;
			cout << "Enter B" << endl;
			cin >> B;
			break;
		case 2:
			C = A + B;
			cout << endl << C << endl;
			break;
		case 3:
			C = A - B;
			cout << endl << C << endl;
			break;
		case 4:
			C = A * B;
			cout << endl << C << endl;
			break;
		case 5:
			C = A / B;
			cout << endl << C << endl;
			break;
		case 6:
			T = A;
			A = B;
			B = T;
			cout << "Done" << endl;
			break;
		case 7:
			cout << "Determinant A = " << A.GetDet() << endl;
			break;
		case 8:
			C = A.GetInvers();
			cout << endl << C << endl;
		case 9:
			cout << "Matrix A" << endl << endl;
			cout << A << endl << endl;
			cout << "Matrix B" << endl << endl;
			cout << B << endl << endl;
			break;
		case 10:
			A = C;
			cout << "Done" << endl;
			break;
		case 11:
			return;
		default:
			cout << "Enter again, please" << endl;
		}
	}
}
#endif