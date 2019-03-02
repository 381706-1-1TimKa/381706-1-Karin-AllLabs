#pragma once
#include "Stack.h"
#include "../Exception/Exception.h"

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
	TStack<T>::size = n;
	TStack<T>::top = 0;
	TStack<T>::mas = m;
}

template <class T>
TNewStack<T>::TNewStack(TNewStack<T> &A) {
	TStack<T>::size = A.TStack<T>::size;
	TStack<T>::top = A.TStack<T>::top;
	TStack<T>::mas = A.TStack<T>::mas;
}

template <class T>
int TNewStack<T>::Free() {
	return TStack<T>::size - TStack<T>::top;
}

template <class T>
int TNewStack<T>::GetSize() {
	return TStack<T>::size;
}

template <class T>
int TNewStack<T>::GetTop() {
	return TStack<T>::top;
}

template <class T>
void TNewStack<T>::SetMas(int n, T* m) {
	TStack<T>::size = n;
	TStack<T>::mas = m;
}
