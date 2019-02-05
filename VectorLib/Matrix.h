#pragma once
#include "Vector.h"
#include <iostream>
#include "Exeption.h"
#include <string>
using namespace std;
//Для удобства обращения (индексации) и вывода матрицы сделаны нижнетреугольными
template <class T>
class TMatrix: public TVector<TVector<T> >
{
public:
	TMatrix (int n=0);
	TMatrix (const TMatrix<T>& A);
	TMatrix<T> operator+(const TMatrix<T>& A);
	TMatrix<T> operator-(const TMatrix<T>& A);
	TMatrix<T> operator*(const TMatrix<T>& A);
	//TMatrix<T> operator/(TMatrix<T>& A);
	TMatrix(const TVector<TVector<T> > &A);
	TMatrix<T>& operator=(const TMatrix<T>& A);
	bool operator==(const TMatrix<T>& A);
	bool operator!=(const TMatrix<T>& A);
	template <class T1>
	friend ostream& operator<<(ostream& ostr, TMatrix<T1> &A);
	template <class T1>
	friend istream& operator>>(istream& istr, TMatrix<T1> &A);
};

template <class T>
TMatrix<T>::TMatrix (int n):TVector<TVector<T> >(n) {
	for (int i = 0; i < n; i++) {
		TVector<TVector<T> >::mas[i] = TVector<T>(i+1);
	}
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& A):TVector<TVector<T> >(A) {
	
}
//TMatrix<T>::TMatrix (const TMatrix<T>& A){
//	l = A.l;
//	if (A.l > 0) {
//		for (int i = 0; i < l; i++) {
//			m[i] = TVector<T>(i + 1);
//			for (int j = 0; j < i + 1; j++)
//				m[i][j] = A.m[i][j];
//		}
//	}
//}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &A) {
	return TVector<TVector<T> >::operator+(A);
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& A) {
	return TVector<TVector<T> >::operator-(A);
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& A) {
	if (this->size != A.size)
	{
		TExeption Ex("different size", "Matrix", "operator*", 7);
		throw Ex;
	}
	TMatrix<T> tmp(TVector<TVector<T> >::size);
	int sum = 0;
	for (int i = 0; i < TVector<TVector<T> >::size; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < i - j + 1; k++)
				sum += TVector<TVector<T> >::mas[i][k + j] * A[k + j][j];
			tmp[i][j] = sum;
			sum = 0;
		}
	}
	return tmp;
}

//template <class T>
//TMatrix<T> TMatrix<T>::operator/(TMatrix<T>& A)
//{
//	if (this->size != A.size)
//		if (size != A.size) {
//			TExeption Ex("different size", "Matrix", "operator*", 7);
//			throw Ex;
//		}
//	double det = 1;
//	for (int i = 0; i < size; i++)
//	{
//		det = det * A[i][i];
//	}
//	if ((det < 0.0001) && (det > -0.0001))
//	{
//		TExeption Ex("null determinant", "Matrix", "operator/", 8);
//		throw Ex;
//	}
//
//	TMatrix<T> Acopy(A);
//	TMatrix<T> Rez(size);
//	for (int i = 0; i < Rez.size; i++) //проход по строкам
//	{
//		Rez[i][i] = 1;
//		T k = Acopy[i][i];
//		for (int j = 0; j <= i; j++)// проход по столбцам 
//		{
//			Acopy[i][j] = Acopy[i][j] / k;
//			Rez[i][j] = Rez[i][j] / k;
//		}
//	}//получили матрицу с 1 по диагонали
//
//	/*for (int i = 1; i < Rez.size; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			for (int k=0; )
//		}
//	}*/
//	for (int j=0; j<Rez.size-1; j++)
//	{
//		for (int i=j+1; i<Rez.size; i++)
//		{
//		for(int k=0; k<=j; k++)
//			Rez[i][k] = Rez[i][k] - Acopy[i][j] * Rez[i-1][k];
//		}
//	}
//
//	cout << Rez;
//	return (*this)*Rez;
//}

template <class T>
TMatrix<T>& TMatrix<T>::operator= (const TMatrix<T>& A) 
{
	TVector < TVector<T> >::operator= (A);
	return *(this);
}

template <class T>
bool TMatrix<T>::operator==(const TMatrix<T>& A)
{
	TVector<TVector<T> >::operator==(A);
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T>& A)
{
	TVector<TVector<T> >::operator!=(A);
}

//TMatrix<T>& TMatrix<T>::operator=(TMatrix<T>& A) {
//	if (this == &A)
//		return *this;
//	if (l != A.l) {
//		for (int i=0; i<l; i++)
//			delete[] m[i];
//		delete[] m;
//		l = A.l;
//		m = new TVector<T>[A.l];
//		for (int i = 0; i < l; i++) {
//			m[i] = TVector<T>(i + 1);
//		}
//	}
//	for (int i = 0; i < l; i++)
//		for (int j = 0; j < i + 1; j++)
//			m[i][j] = A.m[i][j];
//	return *this;
//}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &A) : TVector<TVector<T> >(A) {};

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
	for (int i = 0; i < A.size; i++) {
		for (int j = 0; j <= i; j++) {
			ostr << A.mas[i][j] << "\t";
		}
		for (int k = 0; k < A.size - i - 1; k++)
			ostr << "0\t";
		ostr << endl;
	}
	return ostr;
}

template <class T1>
istream& operator>>(istream& istr, TMatrix<T1> &A) {
	for (int i = 0; i < A.size; i++)
		for (int j = 0; j <= i; j++)
			istr >> A.mas[i][j];
	return istr;
}