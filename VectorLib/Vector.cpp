#include "Matrix.h"

int main() {
	TMatrix<int> A(2), B(2);
	A[0][0] = 1 ;
	A[0][1] = 2;
	A[1][0] = 1;

	B[0][0] = 1;
	B[0][1] = 2;
	B[1][0] = 1;

	TMatrix<int> C(2);
	C = A - B;
	return 0;
}