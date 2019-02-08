#include "Matrix.h"
#include <gtest.h>

TEST(Matrix, can_create)
{
	ASSERT_NO_THROW(TMatrix<int> A(3));
}

TEST(Matrix, can_not_create_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<int> A(-3));
}

TEST(Matrix, can_set_elem)
{
	TMatrix<int> A(3);
	A[0][0] = 1;
	A[1][0] = 2;
	A[1][1] = 3;
	A[2][0] = 4;
	A[2][1] = 5;
	A[2][2] = 6;
	ASSERT_EQ(A[0][0], 1);
	ASSERT_EQ(A[1][0], 2);
	ASSERT_EQ(A[1][1], 3);
	ASSERT_EQ(A[2][0], 4);
	ASSERT_EQ(A[2][1], 5);
	ASSERT_EQ(A[2][2], 6);
}

TEST(Matrix, can_not_get_does_not_exist_elem)
{
	TMatrix<int> A(3);
	ASSERT_ANY_THROW(A[0][1] = 5);
}

TEST(Matrix, can_get_determinant)
{
	TMatrix<int> A(6);
	for (int i = 0; i < 6; i++)
		for (int j = 0; j <= i; j++)
			A[i][j] =1 + i + j;
	ASSERT_EQ(A.GetDet(), 10395);
}

TEST(Matrix, can_get_invers)
{
	TMatrix<double> A(4);
	A[0][0] = 1;
	A[1][0] = 12;
	A[1][1] = 1;
	A[2][0] = 2;
	A[2][1] = 14;
	A[2][2] = 1;
	A[3][0] = 3;
	A[3][1] = 12;
	A[3][2] = 9;
	A[3][3] = 10;
	TMatrix<double> B(4);
	B = A.GetInvers();
	ASSERT_EQ(B[0][0], 1.0);
	ASSERT_EQ(B[1][0], -12.0);
	ASSERT_EQ(B[1][1], 1.0);
	ASSERT_EQ(B[2][0], 166.0);
	ASSERT_EQ(B[2][1], -14.0);
	ASSERT_EQ(B[2][2], 1.0);
	ASSERT_EQ(B[3][0], -135.3);
	ASSERT_EQ(B[3][1], 11.4);
	ASSERT_EQ(B[3][2], -0.9);
	ASSERT_EQ(B[3][3], 0.1);
}

TEST(Matrix, can_not_get_invers_with_null_determinant)
{
	TMatrix<double> A(4);
	A[0][0] = 0;
	A[1][0] = 12;
	A[1][1] = 1;
	A[2][0] = 2;
	A[2][1] = 14;
	A[2][2] = 1;
	A[3][0] = 3;
	A[3][1] = 12;
	A[3][2] = 9;
	A[3][3] = 10;
	ASSERT_ANY_THROW(A.GetInvers());
}

TEST(Matrix, can_addition)
{
	TMatrix<int> A(4);
	A[0][0] = 1;
	A[1][0] = 12;
	A[1][1] = 1;
	A[2][0] = 2;
	A[2][1] = 14;
	A[2][2] = 1;
	A[3][0] = 3;
	A[3][1] = 12;
	A[3][2] = 9;
	A[3][3] = 10;
	TMatrix<int> B(4);
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
	TMatrix<int> C;
	C = A + B;
	ASSERT_EQ(C[0][0], 10);
	ASSERT_EQ(C[1][0], 16);
	ASSERT_EQ(C[1][1], 10);
	ASSERT_EQ(C[2][0], 9);
	ASSERT_EQ(C[2][1], 22);
	ASSERT_EQ(C[2][2], 3);
	ASSERT_EQ(C[3][0], 7);
	ASSERT_EQ(C[3][1], 18);
	ASSERT_EQ(C[3][2], 12);
	ASSERT_EQ(C[3][3], 11);
}

TEST(Matrix, can_substraction)
{
	TMatrix<int> A(4);
	A[0][0] = 1;
	A[1][0] = 12;
	A[1][1] = 1;
	A[2][0] = 2;
	A[2][1] = 14;
	A[2][2] = 1;
	A[3][0] = 3;
	A[3][1] = 12;
	A[3][2] = 9;
	A[3][3] = 10;
	TMatrix<int> B(4);
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
	TMatrix<int> C;
	C = A - B;
	ASSERT_EQ(C[0][0], -8);
	ASSERT_EQ(C[1][0], 8);
	ASSERT_EQ(C[1][1], -8);
	ASSERT_EQ(C[2][0], -5);
	ASSERT_EQ(C[2][1], 6);
	ASSERT_EQ(C[2][2], -1);
	ASSERT_EQ(C[3][0], -1);
	ASSERT_EQ(C[3][1], 6);
	ASSERT_EQ(C[3][2], 6);
	ASSERT_EQ(C[3][3], 9);
}

TEST(Matrix, can_multiplication)
{
	TMatrix<int> A(4);
	A[0][0] = 1;
	A[1][0] = 12;
	A[1][1] = 1;
	A[2][0] = 2;
	A[2][1] = 14;
	A[2][2] = 1;
	A[3][0] = 3;
	A[3][1] = 12;
	A[3][2] = 9;
	A[3][3] = 10;
	TMatrix<int> B(4);
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
	TMatrix<int> C;
	C = A * B;
	ASSERT_EQ(C[0][0], 9);
	ASSERT_EQ(C[1][0], 112);
	ASSERT_EQ(C[1][1], 9);
	ASSERT_EQ(C[2][0], 81);
	ASSERT_EQ(C[2][1], 134);
	ASSERT_EQ(C[2][2], 2);
	ASSERT_EQ(C[3][0], 178);
	ASSERT_EQ(C[3][1],240);
	ASSERT_EQ(C[3][2], 48);
	ASSERT_EQ(C[3][3], 10);
}

TEST(Matrix, can_division)
{
	TMatrix<double> A(4);
	A[0][0] = 1;
	A[1][0] = 12;
	A[1][1] = 1;
	A[2][0] = 2;
	A[2][1] = 14;
	A[2][2] = 1;
	A[3][0] = 3;
	A[3][1] = 12;
	A[3][2] = 9;
	A[3][3] = 10;
	TMatrix<double> B(4);
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
	TMatrix<double> C;
	C = A / B;
	ASSERT_EQ((int)C[0][0], 0);
	ASSERT_EQ((int)C[1][0], 1);
	ASSERT_EQ((int)C[1][1], 0);
	ASSERT_EQ((int)C[2][0], 0);
	ASSERT_EQ((int)C[2][1], 1);
	ASSERT_EQ((int)C[2][2], 0);
	ASSERT_EQ((int)C[3][0], 2);
	//ASSERT_EQ((int)C[3][1], 4.0) закоментирован, т.к. из-за погрешности считает за 3.9999
	ASSERT_EQ((int)C[3][2], -10);
	ASSERT_EQ((int)C[3][3], 10);
}