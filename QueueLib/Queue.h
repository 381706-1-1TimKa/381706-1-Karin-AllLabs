#pragma once
#include "Stack.h"
#include "Exeption.h"
#include <string>
using namespace std;


template <class T>
class TQueue: public TStack<T> {
protected:
	int rear;
	int count;
public:
	TQueue(int n);
	TQueue(TQueue<T> &A);
	~TQueue();
	void Put(T A);
	T Get();
	int GetCount();
	bool IsFull();
	bool IsEmpty();
};

template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n) 
{
	count = 0;
	rear = 0;
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &A): TStack<T>(A) 
{
	count = A.count;
	rear = A.rear;
}

template <class T>
TQueue<T>::~TQueue()
{
	count = 0;
	rear = 0;
}

template <class T>
void TQueue<T>::Put(T A) 
{
	if (IsFull())
	{
		TExeption Ex("full queue", "TQueue", "Put", 2);
		throw Ex;
	}
	mas[rear] = A;
	rear = (rear + 1) % size;
	count++;
}

template <class T>
T TQueue<T>::Get() 
{
	if (IsEmpty())
	{
		TExeption Ex("empty queue", "TQueue", "Get", 3);
		throw Ex;
	}
	count--;
	int t1 = top;
	top = (top + 1) % size;
	return mas[t1];
}

template <class T>
int TQueue<T>::GetCount() 
{
	return count;
}

template <class T>
bool TQueue<T>::IsFull() 
{
	return (count == size);
}

template <class T>
bool TQueue<T>::IsEmpty()
{
	return (count == 0);
}
