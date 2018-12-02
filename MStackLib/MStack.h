#pragma once
#include "NewStack.h"
using namespace std;

template <class T>
class TMStack {
	int size;	//общая длина
	T* mas;		//память для всего мультистека
	int n;		//количество стеков в мультистеке
	TNewStack<T>** h;	//псевдостеки без выделения памяти
public:
	TMStack(int _n, int _size);
	TMStack(TMStack<T> &A);
	int GetFreeMem();
	void Repack(int k);
	void Set(int n1, T p);
	T Get(int n1);
	bool IsFull(int n1);
	bool IsEmpty(int n1);
};

template <class T>
TMStack<T>::TMStack(int _n, int _size) {
	if ((_n < 1) || (_size < 1))
		throw 1;
	n = _n;
	size = _size;
	h = new TNewStack<T>*[n];
	mas = new T[size];
	
	int* p;			//p-массив размеров псевдостеков
	p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = size / n;
	p[0] += size % n;

	h[0] = new TNewStack<T>(p[0], &mas[0]);
	for (int i = 1; i < n; i++)
		h[i] = new TNewStack<T>(p[i], &mas[p[0]] + ((i - 1)*size / n));
}

template <class T>
TMStack<T>::TMStack(TMStack<T> &A) {
	size = A.size;
	n = A.n;
	mas = new T[size];
	h = new TNewStack<T>*[n];
	for (int i = 0; i < n; i++)
		mas[i] = A.mas[i];

	int *p;
	p = new int[n];
	for (int i = 0; i < n; i++) 
		p[i] = A.h[i]->GetSize();
	h[0] = new TNewStack<T>(*A.h[0]);
	h[0]->SetMas(p[0], mas);
	int sizeSt = 0;
	for (int i = 1; i < n; i++) {
		h[i] = new TNewStack<T>(*A.h[i]);
		h[i]->SetMas(p[i], &mas[p[0] + sizeSt]);		//разобраться
		sizeSt += p[i - 1];
	}
}

template <class T>
int TMStack<T>::GetFreeMem() {
	int count = 0;
	for (int i = 0; i < n; i++)
		count += h[i]->GetFreeMem();
	return count;
}

template <class T>
void TMStack<T>::Repack(int k) {
	int FM = GetFreeMem();
	int add_ev = FM / n;
	int add_full = FM % n;
}

template <class T>
void TMStack<T>::Set(int n1, T p) {

}

template <class T>
T TMStack<T>::Get(int n1) {

}

template <class T>
bool TMStack<T>::IsFull(int n1) {

}

template <class T>
bool TMStack<T>::IsEmpty(int n1) {

}
