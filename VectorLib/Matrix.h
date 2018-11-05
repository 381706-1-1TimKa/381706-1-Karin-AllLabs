//#pragma once
//#include "Vector.h"
//#include <iostream>
//using namespace std;
//
//template <class T>
//class TMatrix: public TVector<TVector<T>>
//{
//public:
//	TMatrix<T> (int n=0, int m=0);
//	TMatrix<T> (const TMatrix<T>& A);
//	TMatrix<T> operator+(TMatrix& A);
//	TMatrix<T> operator-(TMatrix& A);
//	TMatrix<T> operator*(TMatrix& A);
//	virtual ~TMatrix();
//};
//
//template <class T>
//TMatrix<T>::TMatrix<T> (int n) {
//	if (n == 0) {
//		l = 0;
//		m = NULL;
//	}
//	if (n > 0) {
//		l = n;
//		m = new TVector<T>[l];
//		for (int i = 0; i < l; i++) {
//			m[i] = new TVector<T>(l);
//		}
//	}
//	else {
//		throw 1;
//	}
//}
//
//template <class T>
//TMatrix<T>::TMatrix<T>(const TMatrix<T>& A) {
//	l = A.l;
//	if (l == 0) {
//		delete m;
//		m = NULL;
//	}
//	if (l > 0) {
//		m = new TVector<T>[l];
//		for (int i = 0; i < l; i++) {
//			m[i] = new TVector<T>(l);
//			m[i] = A.m[i];
//		}
//	}
//	if (l < 0)
//		throw 1;
//}
//
//template <class T>
//TMatrix<T> TMatrix<T>::operator+(TMatrix<T> &A) {
//
//}
//
//template <class T>
//TMatrix<T> TMatrix<T>::operator-(TMatrix& A) {
//
//}
//
//template <class T>
//TMatrix<T> TMatrix<T>::operator*(TMatrix& A) {
//
//}
//
//template <class T>
//TMatrix::~TMatrix() {
//
//}