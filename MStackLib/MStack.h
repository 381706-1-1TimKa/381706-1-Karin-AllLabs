#pragma once
#include "NewStack.h"
using namespace std;

template <class T>
class TMStack 
{
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
TMStack<T>::TMStack(int _n, int _size) 
{
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
		h[i] = new TNewStack<T>(p[i], &mas[p[0]] + ((i - 1)*p[i]));
}

template <class T>
TMStack<T>::TMStack(TMStack<T> &A) 
{
	size = A.size;
	n = A.n;
	mas = new T[size];
	h = new TNewStack<T>*[n];
	for (int i = 0; i < size; i++)
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
		h[i]->SetMas(p[i], &mas[p[0] + sizeSt]);
		sizeSt += p[i];
	}
}

template <class T>
int TMStack<T>::GetFreeMem() 
{
	int count = 0;
	for (int i = 0; i < n; i++)
		count += h[i]->GetFreeMem();
	return count;
}

template <class T>
void TMStack<T>::Repack(int k)
{
	int freeMem = GetFreeMem();
	if (freeMem == 0)
		throw "No free memory";
	int addEv = FM / n;
	int addFull = FM % n;
	int* newSize = new int[n];
	T** oldStart = new T*[n];
	T** newStart = new T*[n];

	for (int i = 0; i < n; i++)
		newSize[i] = addEv + h[i]->TNewStack<T>::GetTop();
	newSize[k] += addFull;
	newStart[0] = oldStart[0];
	for (int i = 1; i < n; i++) {
		newStart[i] = newStart[i - 1] + newSize[i - 1];
		oldStart[i] = oldStart[i - 1] + h[i - 1]->TStack<T>::GetSize();
	}

	for (int i = 0; i < n; i++) {
		if (newStart[i] <= oldStart[i]) {
			for (int j = 0; j < h[i]->TNewStack<T>::GetTop(); j++)
				newStart[i][j] = oldStart[i][j];
		}
		else {
			for (int s = i + 1; s < n; s++)
				if (newStart[s] <= oldStart[s])
					break;
			for (int j = s - 1; j > i; j--) {
				for (int r = h[j]->TNewStack<T>::GetTop() - 1; r >= 0; r--)
					newStart[i][r] = oldStart[j][r];
				i = s - 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		h[i]->TNewStack<T>::SetMas(NewSize[i], newStart[i]);
	delete[] newStart;
	delete[] oldStart;
	delete[] newSize;
}

template <class T>
void TMStack<T>::Set(int n1, T p) 
{
	if ((n1 < 0) || (n1 > n))
		throw 1;
	h[n1]->TStack<T>::Set(p);
}

template <class T>
T TMStack<T>::Get(int n1) 
{
	if ((n1 < 0) || (n1 > n))
		throw 1;
	return h[n1]->TStack<T>::Get();
}

template <class T>
bool TMStack<T>::IsFull(int n1) 
{
	if ((n1 < 0) || (n1 > n))
		throw 1;
	return h[n1]->TStack<T>::IsFull();
}

template <class T>
bool TMStack<T>::IsEmpty(int n1) 
{
	if ((n1 < 0) || (n1 > n))
		throw 1;
	return h[n1]->TStack<T>::IsEmpty();
}