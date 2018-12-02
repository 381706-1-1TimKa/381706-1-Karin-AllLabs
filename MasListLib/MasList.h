#pragma once
#include <queue>
using namespace std;

template <class T>
class TMasList{
	T* mas;
	int *index;
	int size;
	int count;
	int start;
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
	mas = new T[size];
	index = new int[size];
	for (int i = 0; i < size; i++) {
		index[i] = -2;
		freeElem.push(i);
	}
}

template <class T>
TMasList<T>::TMasList(TMasList<T> &A)
{
	start = A.start;
	size = A.size;
	count = A.count;
	mas = new T[size];
	index = new int[size];
	freeElem = A.freeElem;
	for (int i = 0; i < size; i++) {
		mas[i] = A.mas[i];
		index[i] = A.index[i];
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
	index[ifree] = start;
	start = ifree;
	count++;
}

template <class T>
void TMasList<T>::PushFinish(T elem)	//положить элемент в конец
{
	if(IsFull() == 1)
		throw 1;
	int i = 0;
	while (i != -1)
		i++;
	int ifree = freeElem.front();
	freeElem.pop();
	mas[ifree] = elem;
	index[i] = ifree;
	index[ifree] = -1;
	count++;
}

template <class T>
T TMasList<T>::PullStart()	//взять первый элемент
{
	if (IsEmpty() == 1)
		throw 1;
	T elem = mas[start];
	int newstart = index[start];
	freeElem.push(start);
	index[start] = -2;
	count--;
	start = newstart;
	return elem;
}

template <class T>
T TMasList<T>::PullFinish()		//взять последний элемент
{
	if (IsEmpty() == 1)
		throw 1;
	int i = 0;
	while (index[i] != -1)
		i++;
	T elem = mas[i];
	index[i] = -2;
	int j = 0;
	while (index[j] != i)
		j++;
	index[j] = -1;
	freeElem.push(i);
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