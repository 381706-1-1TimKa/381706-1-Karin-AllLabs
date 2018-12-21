#pragma once
#include "Exeption.h"
#include <string>
using namespace std;


template <class T>
class TQueue {
protected:
	int size;
	int start;
	int r;
	int count;
	T* mas;
public:
	TQueue(int n = 0);
	TQueue(TQueue<T> &A);
	void Put(T A);
	T Get();
	int GetCount();
	bool IsFull();
	bool IsEmpty();
};

template <class T>
TQueue<T>::TQueue(int n = 0) {
	if (n < 0)
	{
		TExeption Ex("negative size", "TQueue", "TQueue", 1);
		throw Ex;
	}
	else if (n == 0) {
		size = 0;
		start = 0;
		r = 0;
		mas = nullptr;
	}
	else {
		size = n;
		start = 0;
		r = 0;
		count = 0;
		mas = new T[size];
		for (int i = 0; i < size; i++) {
			mas[i] = 0;
		}
	}
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &A) {
	if (A.size == 0) {
		size = 0;
		start = 0;
		r = 0;
		mas = nullptr;
	}
	else {
		size = A.size;
		start = A.start;
		r = A.r;
		count = A.count;
		mas = new T[size];
		for (int i = 0; i < size; i++) {
			mas[i] = A.mas[i];
		}
	}
}

template <class T>
void TQueue<T>::Put(T A) {
	if (IsFull())
	{
		TExeption Ex("full queue", "TQueue", "Put", 2);
		throw Ex;
	}
	mas[r] = A;
	r = (r + 1) % size;
	count++;
}

template <class T>
T TQueue<T>::Get() {
	if (IsEmpty())
	{
		TExeption Ex("empty queue", "TQueue", "Get", 3);
		throw Ex;
	}
	count--;
	int s1 = start;
	start = (start + 1) % size;
	return mas[s1];
}

template <class T>
int TQueue<T>::GetCount() {
	return count;
}

template <class T>
bool TQueue<T>::IsFull() {
	if (count == size)
		return true;
	else
		return false;
}

template <class T>
bool TQueue<T>::IsEmpty() {
	if (count == 0)
		return true;
	else
		return false;
}
