#pragma once
#include <queue>
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
	queue<int> freeElem;
	
public:
	TMasList(int _size = 10);
	TMasList(TMasList<T> &A);
	void PushStart(T elem);	//положить элемент в начало
	void PushFinish(T elem);	//положить элемент в конец
	T PullStart();	//взять первый элемент
	T PullFinish();		//взять последний элемент
	bool IsFull();	//проверка на полноту
	bool IsEmpty();	//проверка на пустоту
};

template <class T>
TMasList<T>::TMasList(int _size)
{
	if (_size <= 0)
		throw 1;
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
		freeElem.push(i);
	}
}

template <class T>
TMasList<T>::TMasList(TMasList<T> &A)
{
	start = A.start;
	finish = A.finish;
	size = A.size;
	count = A.count;
	mas = new T[size];
	nextInd = new int[size];
	prevInd = new int[size];
	freeElem = A.freeElem;
	for (int i = 0; i < size; i++) {
		mas[i] = A.mas[i];
		nextInd[i] = A.nextInd[i];
		prevInd[i] = A.prevInd[i];
	}
}

template <class T>
void TMasList<T>::PushStart(T elem)	//положить элемент в начало
{
	if (IsFull() == 1)
		throw 1;
	int ifree = freeElem.front();
	freeElem.pop();
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
	if(IsFull() == 1)
		throw 1;
	int ifree = freeElem.front();
	freeElem.pop();
	mas[ifree] = elem;
	if (finish != -1)
		nextInd[finish] = ifree;
	else {
		start = ifree;
		prevInd[ifree] = -1;
	}
	prevInd[ifree] = finish;
	finish = ifree;
	count++;
}

template <class T>
T TMasList<T>::PullStart()	//взять первый элемент
{
	if (IsEmpty() == 1)
		throw 1;
	T elem = mas[start];
	int newstart = nextInd[start];
	freeElem.push(start);
	nextInd[start] = -2;
	prevInd[start] = -2;
	if(newstart!=-1)
		prevInd[newstart] = -1;
	count--;
	start = newstart;
	return elem;
}

template <class T>
T TMasList<T>::PullFinish()		//взять последний элемент
{
	if (IsEmpty() == 1)
		throw 1;
	T elem = mas[finish];
	int newFinish = prevInd[finish];
	prevInd[finish] = -2;
	nextInd[finish] = -2;
	freeElem.push(finish);
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