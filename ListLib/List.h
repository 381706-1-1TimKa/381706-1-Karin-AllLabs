#pragma once
#include "Elem.h"
template <class T>
class TList {
protected:
	TElem<T>* begin;
public:
	TList();
	TList(TList<T> &A);
	void PutBegin(T A);
	void PutEnd(T A);
	T GetBegin();
	T GetEnd();
	T GetElem(T* A);
	T* GetInd(T A);
};

template <class T>
TList<T>::TList(){
	begin = 0;
}

template <class T>
TList<T>::TList(TList<T> &A) {
	TElem<T>* a, b;
	a = A.begin;
	if (A.begin == 0)
		begin = 0;
	else {
		begin = new TElem<T>(A.begin);
		b = begin;
		while (a->GetNext() != 0) {
			b.next = new TElem<T>(a->GetNext());
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
		begin = new TElem(A, 0);
	}
}

template <class T>
T TList<T>::GetBegin(){
	TElem<T>* a = begin;
	T tmp = begin->Get();
	begin = begin->GetNext();
	delete a;
	return tmp;
}

template <class T>
T TList<T>::GetEnd(){

}

template <class T>
T TList<T>::GetElem(T* A){
}

template <class T>
T* TList<T>::GetInd(T A){

}