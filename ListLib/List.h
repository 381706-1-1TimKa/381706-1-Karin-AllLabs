#pragma once
#include "Elem.h"
#include "Exeption.h"
using namespace std;

template <class T>
class TList {
protected:
	TElem<T>* begin;
public:
	TList();
	TList(TList<T> &A);
	~TList();
	void PutBegin(T A);
	void PutEnd(T A);
	T GetBegin();
	T GetEnd();
	T GetElem(int ind);
	bool IsEmpty();
	//T* GetInd(T A);
};

template <class T>
TList<T>::TList(){
	begin = 0;
}

template <class T>
TList<T>::TList(TList<T> &A) {
	TElem<T> *a, *b;
	a = A.begin;
	if (A.begin == 0)
		begin = 0;
	else {
		begin = new TElem<T>(*A.begin);
		b = begin;
		while (a->GetNext() != 0) {
			b->SetNext(new TElem<T> (*(a->GetNext())) );
			a = a->GetNext();
			b = b->GetNext();
		}
	}
}

template <class T>
TList<T>::~TList()
{
	if (begin != 0) {
		TElem<T> *a, *b;
		a = begin;
		while (a->GetNext() != 0)
		{
			b = a;
			a = a->GetNext();
			delete b;
		}
	}

}

template <class T>
void TList<T>::PutBegin(T A){
	if (begin == 0) {
		TElem<T>* tmp = new TElem<T>(A, 0);
		begin = tmp;
	}
	else {
		TElem<T>* tmp = new TElem<T>(A, begin);
		begin = tmp;
	}
}

template <class T>
void TList<T>::PutEnd(T A){
	if (begin != 0) {
		TElem<T>* a = begin;
		while (a->GetNext() != 0) {
			a = a->GetNext();
		}
		a->SetNext(new TElem<T>(A, 0));
	}
	else {
		begin = new TElem<T>(A, 0);
	}
}

template <class T>
T TList<T>::GetBegin(){
	if (IsEmpty()) {
		TExeption ex("Empty list", "List.h", "GetBegin", 2);
		throw ex;
	}
	TElem<T>* a = begin;
	T tmp = begin->Get();
	begin = begin->GetNext();
	delete a;
	return tmp;
}

template <class T>
T TList<T>::GetEnd(){
	if (IsEmpty()) {
		TExeption ex("Empty list", "List.h", "GetEnd", 2);
		throw ex;
	}
	TElem<T>* a;
	T tmp;
	if (begin->GetNext() != 0) {
		a = begin;
		while (a->GetNext()->GetNext() != 0) 
			a = a->GetNext();
		tmp = a->GetNext()->Get();
		a->SetNext(0);
		delete[] a->GetNext();
	}

	else if (begin->GetNext() == 0) 
	{
		tmp = begin->Get();
		begin = 0;
	}
	else
		throw 1;

	return tmp;
}

template <class T>
T TList<T>::GetElem(int ind) {
	TElem<T>* a = begin;
	for (int i = 0; i <= ind; i++) {
		if (a->GetNext() == 0) {
			TExeption ex("Element not found", "List.h", "GetElem", 1);
			throw ex;
		}
		a = a->GetNext();
	}
	return a->Get();
}

template <class T>
bool TList<T>::IsEmpty() {
	return (begin == 0);
}

//template <class T>
//T TList<T>::GetElem(T* A){
//}

//template <class T>
//T* TList<T>::GetInd(T A){
//	TElem<T>* a = begin;
//	int i = 0;
//	while (*(a->GetNext()) != A) {
//		if (a->GetNext() != 0) && (a->GetNext() != nullptr)
//			throw 1;
//		a = a->GetNext();
//	}
//	return 
//}