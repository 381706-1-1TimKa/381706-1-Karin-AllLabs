#pragma once
#include <iostream>
using namespace std;

template <class T>
class TStack {
protected:
	int size;
	int r;
	T* mas;
public:
	TStack<T> (int n=0);
	TStack<T> (TStack<T> &A);
	void put (T A);
	T Get();
	bool IsFull();
	bool IsEmpty();
};

template <class T>
TStack<T>::TStack<T>(int n){
	if (n < 0)
		throw "Incorrect length";
	else if (n == 0) {
		size = 0;
		r = 0;
		mas = nullptr;
	}
	else {
		size = n;
		r = 0;
		mas = new T[size];
	}
}

template <class T>
TStack<T>::TStack<T>(TStack<T> &A) {
	r = A.r;
	size = A.size;
	if (size == 0)
		mas = 0;
	else
		mas = new T[size];
	for (int i = 0; i < size; i++) {
		mas[i] = A.mas[i];
	}
}

template <class T>
void TStack<T>::put(T A) {
	if (IsFull())
		throw "FULL";
	else {
		mas[r] = A;
		r++;
	}
}

template <class T>
T TStack<T>::Get(){
	if (IsEmpty())
		throw "Empty";
	else {
		r--;
		return mas[r];
	}
}

template <class T>
bool TStack<T>::IsFull() {
	if (r >= size)
		return true;
	else
		return false;
}

template <class T>
bool TStack<T>::IsEmpty(){
	if (r == 0)
		return true;
	else
		return false;
}
