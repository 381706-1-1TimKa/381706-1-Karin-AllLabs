#pragma once
#include "List.h"
#include "Exception.h"

template <class T>
class TStackList {
protected:
	TList<T> mas;
	int count;
public:
	TStackList<T>();
	TStackList<T>(TStackList<T> &A);
	void Put(T A);
	T Get();
	int GetSize();
	bool IsEmpty();
};

template <class T>
TStackList<T>::TStackList() {
	count = 0;
}

template <class T>
TStackList<T>::TStackList(TStackList<T> &A): mas(A.mas){
	count = A.count;
}

template <class T>
void TStackList<T>::Put(T A) {
	mas.PutBegin(A);
	count++;
}

template <class T>
T TStackList<T>::Get() {
	if (IsEmpty())
	{
		TException Ex("empty", "StackList", "Get", 3);
		throw Ex;
	}
	T temp;
	temp = mas.GetBegin();
	count--;
	return temp;
}

template <class T>
int TStackList<T>::GetSize() {
	return count;
}

template <class T>
bool TStackList<T>::IsEmpty() {
	if (count == 0) 
		return true;
	return false;
}
