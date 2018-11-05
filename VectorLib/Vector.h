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
	bool operator==(TVector &A);
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
	l = A.l;
	if (l == 0)
		m = nullptr;
	else {
		m = new T [l];
		for (int i = 0; i < l; i++)
			m[i] = A.m[i];
	}
}

template <class T>
TVector<T>& TVector<T> :: operator=(TVector<T> &A) {
	if (this == &A) {
		return *this;
	}

	if (l != A.l) {
		delete[] m;
		m = new T [A.l];
		l = A.l;
	}

	for (int i = 0; i < l; i++) {
		m[i] = A.m[i];
	}
	return *this;

}

template <class T>
bool TVector<T>::operator==(TVector<T> &A) {
	if (l != A.l)
		return false;
	for (int i = 0; i < l; i++) {
		if (m[i] != A.m[i])
			return false;
	}
	return true;
}

template <class T>
T& TVector<T> :: operator[](int i) {
	if ((i < 0) || (i > l)) {
		throw "Element doesn't exist";
	}
	return m[i];
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

template <class T1> 
ostream& operator<< (ostream& ostr, const TVector<T1> &A) {
	for (int i = 0; i < A.l; i++) {
		ostr << A.m[i] << endl;
	}
	return ostr;
}

template <class T1>
istream& operator>> (istream& istr, TVector<T1> &A) {
	for (int i = 0; i < A.l; i++) {
		istr >> A.m[i];
	}
	return istr;
}