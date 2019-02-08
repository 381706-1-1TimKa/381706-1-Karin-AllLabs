#pragma once
#include "Queue.h"
#include "Exception.h"
using namespace std;

template <class T>
class TMasList{
	T* mas;
	int *nextInd;
	int *prevInd;
	int size;
	int count;
	int start;
	int finish;
	TQueue<int> freeElem;
	
public:
	TMasList(int _size = 10);
	TMasList(TMasList<T> &A);
	~TMasList();
	void PushStart(T elem);	//положить элемент в начало
	void PushFinish(T elem);	//положить элемент в конец
	T PullStart();	//взять первый элемент
	T PullFinish();		//взять последний элемент
	bool IsFull();	//проверка на полноту
	bool IsEmpty();	//проверка на пустоту
};

template <class T>
TMasList<T>::TMasList(int _size) : freeElem(_size)
{
	if (_size <= 0) {
		TException Ex("negative size", "MasList.h", "TMasList(int _size)", 1);
		throw Ex;
	}
	size = _size;
	count = 0;
	start = -1;
	finish = -1;
	mas = new T[size];
	nextInd = new int[size];
	prevInd = new int[size];
	for (int i = 0; i < size; i++) {
		nextInd[i] = -2;
		prevInd[i] = -2;
		freeElem.Put(i);
	}
}

template <class T>
TMasList<T>::TMasList(TMasList<T> &A):freeElem(A.freeElem)
{
	start = A.start;
	finish = A.finish;
	size = A.size;
	count = A.count;
	mas = new T[size];
	nextInd = new int[size];
	prevInd = new int[size];
	for (int i = 0; i < size; i++) {
		mas[i] = A.mas[i];
		nextInd[i] = A.nextInd[i];
		prevInd[i] = A.prevInd[i];
	}
}

template <class T>
TMasList<T>::~TMasList() {
	size = 0;
	count = 0;
	start = -1;
	finish = -1;
	delete[] mas;
	delete[] nextInd;
	delete[] prevInd;
}

template <class T>
void TMasList<T>::PushStart(T elem)	//положить элемент в начало
{
	if (IsFull() == 1) {
		TException Ex("Full list", "MasList.h", "PushStart", 2);
		throw Ex;
	}
	int ifree = freeElem.Get();
	mas[ifree] = elem;
	nextInd[ifree] = start;
	if (start != -1)
		prevInd[start] = ifree;
	else
		finish = ifree;
	start = ifree;
	count++;
}

template <class T>
void TMasList<T>::PushFinish(T elem)	//положить элемент в конец
{
	if (IsFull() == 1) {
		TException Ex("Full list", "MasList.h", "PushFinish", 2);
		throw Ex;
	}
	int ifree = freeElem.Get();
	mas[ifree] = elem;
	if (finish != -1)
		nextInd[finish] = ifree;
	else {
		start = ifree;
	}
	prevInd[ifree] = finish;
	finish = ifree;
	count++;
}

template <class T>
T TMasList<T>::PullStart()	//взять первый элемент
{
	if (IsEmpty() == 1) {
		TException Ex("Empty list", "MasList.h", "PullStart", 3);
		throw Ex;
	}
	T elem = mas[start];
	int newstart = nextInd[start];
	freeElem.Put(start);
	nextInd[start] = -2;
	prevInd[start] = -2;
	start = newstart;
	if (start != -1)
		prevInd[start] = -1;
	else
		finish = -1;
	count--;
	return elem;
}

template <class T>
T TMasList<T>::PullFinish()		//взять последний элемент
{
	if (IsEmpty() == 1){
		TException Ex("Empty list", "MasList.h", "PullFinish", 3);
		throw Ex;
}
	T elem = mas[finish];
	int newFinish = prevInd[finish];
	prevInd[finish] = -2;
	nextInd[finish] = -2;
	freeElem.Put(finish);
	finish = newFinish;
	if (newFinish != -1)
		nextInd[newFinish] = -1;
	else
		start = -1;
	count--;
	return elem;
}

template <class T>
bool TMasList<T>::IsFull()	//проверка на полноту
{
	if (count == size)
		return true;
	else
	return false;

}

template <class T>
bool TMasList<T>::IsEmpty()	//проверка на пустоту
{
	if (count == 0)
		return true;
	else
		return false;

}