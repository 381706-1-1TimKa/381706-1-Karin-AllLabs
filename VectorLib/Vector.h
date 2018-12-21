#pragma once
#include <iostream>
#include <string>
#include "Exeption.h"
using namespace std;
template <class T>
class TVector {
protected:
	int size; // длина(размерность)
	T* mas; //массив
public:
	TVector	(int n = 0);
	TVector (TVector <T> &A);
	TVector<T>& operator=(TVector<T> &A);
	bool operator==(TVector &A);
	bool operator!=(TVector &A);
	T& operator[](int i);
	TVector<T> operator+(TVector<T> &A);
	TVector<T> operator-(TVector<T> &A);
	T operator*(TVector<T> &A);
	virtual ~TVector();
	template <class T1>
	friend ostream& operator<< (ostream& ostr, const TVector<T1> &A);
	template <class T1>
	friend istream& operator>> (istream& istr, TVector<T1> &A);
};

template <class T>
TVector<T>::TVector(int n) {
	if (n < 0) 
		{
			TExeption Ex("negative size", "Vector", "TVector", 1);
			throw Ex;
		}
	size = n;
	mas = new T[size];
	for (int i = 0; i < size; i++) {
		mas[i] = (T)0;
	}
}

template <class T>
TVector<T>::TVector(TVector <T> &A) {
	size = A.size;
	if (size == 0)
		mas = nullptr;
	else {
		mas = new T [size];
		for (int i = 0; i < size; i++)
			mas[i] = A.mas[i];
	}
}

template <class T>
TVector<T>& TVector<T> :: operator=(TVector<T> &A) {
	if (this == &A) {
		return *this;
	}
	delete[] mas;
	size = A.size;
	mas = new T[A.size];
	for (int i = 0; i < size; i++) {
		mas[i] = A.mas[i];
	}
	return *this;
}

template <class T>
bool TVector<T>::operator==(TVector<T> &A) {
	if (size != A.size)
		return false;
	for (int i = 0; i < size; i++) {
		if (mas[i] != A.mas[i])
			return false;
	}
	return true;
}

template <class T>
bool TVector<T>::operator!=(TVector &A) {
	if (size != A.size)
		return true;
	for (int i = 0; i < size; i++) {
		if (mas[i] != A.mas[i])
			return true;
	}
	return false;
}


template <class T>
T& TVector<T> :: operator[](int i) {
	if ((i < 0) || (i > size)) 
		{
			TExeption Ex("incorrect index", "Vector", "operator[]", 6);
			throw Ex;
		}
	return mas[i];
}

template <class T>
TVector<T> TVector<T> :: operator+(TVector<T> &A) {
	if (size != A.size) {
		TExeption Ex("different size", "Vector", "operator+", 7);
		throw Ex;
	}
	TVector<T> B(*this);
	for (int i = 0; i < B.size; i++) {
		B.mas[i] = B.mas[i] + A.mas[i];
	}
	return B;
}

template <class T>
TVector<T> TVector<T> :: operator-(TVector<T> &A) {
	if (size != A.size) {
		TExeption Ex("different size", "Vector", "operator-", 7);
		throw Ex;
	}
	TVector<T> B(*this);
	for (int i = 0; i < B.size; i++) {
		B.mas[i] = B.mas[i] - A.mas[i];
	}
	return B;
}

template <class T>
T TVector<T> :: operator*(TVector<T> &A) {
	if (size != A.size) {
		TExeption Ex("different size", "Vector", "operator*", 7);
		throw Ex;
	}
	T Sum = 0;
	for (int i = 0; i < size; i++){
		Sum += mas[i] * A.mas[i];
	}
	return Sum;
}


template <class T>
TVector<T>::~TVector() {
	delete[] mas;
	size = 0;
	mas = nullptr;
}

template <class T1> 
ostream& operator<< (ostream& ostr, const TVector<T1> &A) {
	for (int i = 0; i < A.size; i++) {
		ostr << A.mas[i] << endl;
	}
	return ostr;
}

template <class T1>
istream& operator>> (istream& istr, TVector<T1> &A) {
	for (int i = 0; i < A.size; i++) {
		istr >> A.mas[i];
	}
	return istr;
}