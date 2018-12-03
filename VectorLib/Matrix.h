#pragma once
#include "Vector.h"
#include <iostream>
using namespace std;

template <class T>
class TMatrix: public TVector<TVector<T>>
{
public:
	TMatrix (int n=0);
	TMatrix (const TMatrix<T>& A);
	TMatrix<T> operator+(TMatrix& A);
	TMatrix<T> operator-(TMatrix& A);
	TMatrix<T> operator*(TMatrix& A);
	TMatrix(TVector<TVector<T>> &A);
	template <class T1>
	friend ostream& operator<<(ostream& ostr, TMatrix<T1> &A);
};

template <class T>
TMatrix<T>::TMatrix (int n):TVector<TVector<T>>(n) {
	for (int i = 0; i < n; i++) {
		m[i] = TVector<T>(l - i);
	}
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& A):TVector<TVector<T>>(A) {
	
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(TMatrix<T> &A) {
	return TVector<TVector<T>>::operator+(A);
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(TMatrix& A) {
	return TVector<TVector<T>>::operator-(A);
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(TMatrix& A) {

}

template <class T>
TMatrix<T>::TMatrix(TVector<TVector<T> > &A) : TVector<TVector<T>>(A) {};

//template <class T>
//T TMatrix<T>::Get(int row, int col) {
//	if (row < col)
//		throw 5;
//	else
//		return m[row][col];
//}
//
//template <class T>
//void Set(int row, int col, T val) {
//	if (row < col)
//		throw 5;
//	else
//		m[row][col] = val;
//}

template <class T1>
ostream& operator<<(ostream& ostr, TMatrix<T1> &A) {
	for (int i = 0; i < A.l; i++) {
		for (int j = 0; j < i; j++)
			ostr << "0\t";
		for (int k = 0; k < A.l - i; k++)
			ostr << A.m[i][k] << "\t";
		ostr << endl;
	}
	return ostr;
}