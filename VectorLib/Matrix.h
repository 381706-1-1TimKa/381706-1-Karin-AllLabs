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
	T GetDet();
	TMatrix<T> GetInvers();
	TMatrix<T> operator/(TMatrix<T>& A);
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
	T sum = 0;
	for (int i = 0; i < TVector<TVector<T> >::size; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < i - j + 1; k++)
				sum =sum + TVector<TVector<T> >::mas[i][k + j] * A.mas[k + j][j];
			tmp[i][j] = sum;
			sum = 0;
		}
	}
	return tmp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T>& A)
{
	if (this->size != A.size)
		if (TMatrix<T>::size != A.size) {
			TExeption Ex("different size", "Matrix", "operator*", 7);
			throw Ex;
		}
	return (*this)*A.GetInvers();
}

template <class T>
T TMatrix<T>::GetDet() 
{
	T det = 1;
	for (int i = 0; i < TMatrix<T>::size; i++)
	{
		det = det * (*this)[i][i];
	}
	return det;
}

template <class T>
TMatrix<T> TMatrix<T>::GetInvers() 
{
	T det = this->GetDet();
	if ((det < 0.0001) && (det > -0.0001))
	{
		TExeption Ex("null determinant", "Matrix", "operator/", 8);
		throw Ex;
	}

	//создаём основную матрицу (копируем) и вспомогательную (единичную)
	TMatrix<T> Acopy(*this);
	TMatrix<T> Rez(TMatrix<T>::size);
	for (int i = 0; i < Rez.size; i++) //проход по строкам
	{
		Rez[i][i] = 1;
		T k = Acopy[i][i];
		for (int j = 0; j <= i; j++)// проход по столбцам 
		{
			Acopy[i][j] = Acopy[i][j] / k;
			Rez[i][j] = Rez[i][j] / k; //это можно оптимизировать
		}
	}//получили основную единичную и диагональную вспомогательную

	for (int j = 0; j < Rez.size - 1; j++)
	{
		for (int i = j + 1; i < Rez.size; i++)
		{
			for (int k = 0; k <= j; k++)
				Rez[i][k] = Rez[i][k] - Acopy[i][j] * Rez[j][k];
		}
	}
	return Rez;
}

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

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &A) : TVector<TVector<T> >(A) {};


template <class T1>
ostream& operator<<(ostream& ostr, TMatrix<T1> &A) {
	for (int i = 0; i < A.size; i++) {
		for (int j = 0; j <= i; j++) {
			ostr << A.mas[i][j] << "\t";
		}
		/*for (int k = 0; k < A.size - i - 1; k++)
			ostr << "0\t";*/
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