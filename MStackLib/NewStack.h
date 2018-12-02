#pragma once
#include "Stack.h"

template <class T>
class TNewStack :public TStack<T>
{
public:
	TNewStack(int n, T* m);
	TNewStack(TNewStack<T> &A);
	int Free();
	int GetSize();
	void SetMas(int n, T* m);
};

template <class T>
TNewStack<T>::TNewStack(int n, T* m){
	size = n;
	r = 0;
	mas = m;
}

template <class T>
TNewStack<T>::TNewStack(TNewStack<T> &A) {
	size = A.size;
	r = A.r;
	mas = A.mas;
}

template <class T>
int TNewStack<T>::Free() {
	return size - r;
}

template <class T>
int TNewStack<T>::GetSize() {
	return size;
}

template <class T>
void TNewStack<T>::SetMas(int n, T* m) {
	size = n;
	mas = m;
}
