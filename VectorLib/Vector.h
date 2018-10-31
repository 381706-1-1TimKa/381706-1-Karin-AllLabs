#pragma once
#include <iostream>
using namespace std;
template <class T>
class TVector {
protected:
	int l; // длина(размерность)
	T* m; //массив
public:
	TVector<T>	(int n = 0);
	TVector<T>(TVector <T> &A);
	TVector<T>& operator=(TVector<T> &A);
	T& operator[](int A);
	TVector<T> operator+(TVector<T> &A);
	TVector<T> operator-(TVector<T> &A);
	T operator*(TVector<T> &A);
	virtual ~TVector();
	template <class T>
	friend ostream& operator<< (ostream& ostr, const TVector<T> &A);
	template <class T>
	friend istream& operator>> (istream& istr, TVector<T> &A);
};

template <class T>
TVector<T>::TVector(int n) {
	if (n < 0) {
		throw "Lenght isn't correct";
	}
	l = n;
	m = new T[l];
	for (int i = 0; i < l; i++) {
		m[i] = 0;
	}
}

template <class T>
TVector<T>::TVector(TVector <T> &A) {
	TVector<T> N(A.l);
	N.l = A.l;
	for (int i = 0; i < N.l; i++) {
		N.l = A.l;
	}
}

template <class T>
TVector<T>& TVector<T> :: operator=(TVector<T> &A) {
	if (this = &A) {
		return *this;
	}

	if (l != A.l) {
		delete[] m;
		m = new <T>[A.l];
	}

	for (int i = 0; i < l; i++) {
		m[i] = A.m[i];
	}
	return *this;

}
template <class T>
T& TVector<T> :: operator[](int A) {
	if ((A < 0) || (A > l)) {
		throw "Element doesn't exist";
	}
	return A.m[i];
}

template <class T>
TVector<T> TVector<T> :: operator+(TVector<T> &A) {
	if (l != A.l) {
		throw "Different lenght";
	}
	TVector<T> B(*this);
	for (int i = 0; i < B.l; i++) {
		B.m[i] += A.m[i];
	}
	return B;
}

template <class T>
TVector<T> TVector<T> :: operator-(TVector<T> &A) {
	if (l != A.l) {
		throw "Different lenght";
	}
	TVector<T> B(*this);
	for (int i = 0; i < B.l; i++) {
		B.m[i] -= A.m[i];
	}
	return B;
}
template <class T>
T TVector<T> :: operator*(TVector<T> &A) {
	if (l != A.l) {
		throw "Different lenght";
	}
	T Sum = 0;
	for (int i = 0; i < l; i++){
		Sum += m[i] * A.m[i];
	}
	return Sum;
}


template <class T>
TVector<T>::~TVector() {
	delete[] m;
	l = 0;
	m = nullptr;
}

template <class T> 
ostream& operator<< (ostream& ostr, const TVector<T> &A) {
	for (int i = 0; i < A.l; i++) {
		ostr << A.m[i] << endl;
	}
	return ostr;
}

template <class T>
istream& operator>> (istream& istr, TVector<T> &A) {
	for (int i = 0; i < A.l; i++) {
		istr >> A.m[i];
	}
	return istr;
}