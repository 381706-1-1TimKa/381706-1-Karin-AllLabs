#pragma once
#include "Stack.h"
#include "Exeption.h"

template <class T>
class TNewStack :public TStack<T>
{
public:
	TNewStack(int n, T* m);
	TNewStack(TNewStack<T> &A);
	int Free();
	int GetSize();
	int GetTop();
	void SetMas(int n, T* m);
};

template <class T>
TNewStack<T>::TNewStack(int n, T* m){
	size = n;
	top = 0;
	mas = m;
}

template <class T>
TNewStack<T>::TNewStack(TNewStack<T> &A) {
	size = A.size;
	top = A.top;
	mas = A.mas;
}

template <class T>
int TNewStack<T>::Free() {
	return size - top;
}

template <class T>
int TNewStack<T>::GetSize() {
	return size;
}

template <class T>
int TNewStack<T>::GetTop() {
	return top;
}

template <class T>
void TNewStack<T>::SetMas(int n, T* m) {
	size = n;
	mas = m;
}
