#pragma once
#include "List.h"
#include "../Exception/Exception.h"

template <class T>
class TStackList {
protected:
	TList<T> mas;
public:
	TStackList<T>();
	TStackList<T>(TStackList<T> &A);
	void Put(T A);
	T Get();
	int GetCount();
	bool IsEmpty();
};

template <class T>
TStackList<T>::TStackList() {
}

template <class T>
TStackList<T>::TStackList(TStackList<T> &A): mas(A.mas){
}

template <class T>
void TStackList<T>::Put(T A) {
	mas.PutBegin(A);
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
	return temp;
}

template <class T>
int TStackList<T>::GetCount()
{
	return mas.GetCount();
}

template <class T>
bool TStackList<T>::IsEmpty() {
	return mas.IsEmpty();
}
