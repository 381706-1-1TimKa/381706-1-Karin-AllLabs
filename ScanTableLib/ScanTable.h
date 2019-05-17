#pragma once
#include "ScanElem.h"
#include "Exception.h"
template <class T>
class TScanTable
{
protected:
	TScanElem<T>* mas;
	unsigned size;
	unsigned count;
public:
	TScanElem<T> not_find;
	TScanTable(int n = 0);
	TScanTable(TScanTable<T>& A);
	void Put(TString k, T d);
	void Del(TString k);
	int GetCount() { return count; }
	TScanElem<T>& Search(TString k);
	T& operator[](TString k);
	~TScanTable();
	template <class T1>
	friend ostream& operator<<(ostream& ostr, const TScanTable<T1> &A);
};

template <class T>
TScanTable<T>::TScanTable(int n)
{
	if (n <= 0)
		throw TException("negative size", "ScanTable", "TScanTable", 1);
	mas = new TScanElem<T>[n];
	size = n;
	count = 0;
	TString not_find("not_find");
	not_find.SetKey(not_find);
}

template <class T>
TScanTable<T>::TScanTable(TScanTable<T>& A)
{
	size = A.size;
	count = A.count;
	mas = new TScanElem<T>[size];
	for (int i = 0; i < size; i++)
		mas[i] = A.mas[i];
	TString not_find("not_find");
	not_find.SetKey(not_find);
}

template <class T>
void TScanTable<T>::Put(TString k, T d)
{
	if (size == count)
		throw TException("Table is full", "ScanTable", "Put", 4);
	if (!(Search(k) == not_find))
		throw TException("Element already exist", "ScanTable", "Put", 5);
	mas[count].SetKey(k);
	mas[count].SetData(d);
	count++;
}

template <class T>
void TScanTable<T>::Del(TString k)
{
	int tmp = -1;
	if (count == 0)
		throw TException("Table is empty", "ScanTable", "Del", 2);
	for (int i = 0; i < count; i++)
		if (mas[i].GetKey() == k)
		{
			tmp = i;
			break;
		}
	if (tmp == -1)
		throw TException("Element isn't exist", "ScanTable", "Del", 3);
	mas[tmp] = mas[count - 1];
	mas[count - 1].SetData((T)0);
	TString noname("noname");
	mas[count - 1].SetKey(noname);
	count--;
}

template <class T>
TScanElem<T>& TScanTable<T>::Search(TString k)
{
	for (int i = 0; i < count; i++)
		if (mas[i].GetKey() == k)
			return mas[i];
	return not_find;
}

template <class T>
T& TScanTable<T>::operator[](TString k)
{
	TScanElem<T>& tmp = Search(k);
	if (tmp == not_find)
	{
		Put(k, (T)0);
		return mas[count - 1]();
	}
	return tmp();
}


template <class T>
TScanTable<T>::~TScanTable()
{
	if (size != 0)
	{
		delete[] mas;
		count = 0;
		size = 0;
	}
}

template <class T1>
ostream& operator<<(ostream& ostr, const TScanTable<T1> &A)
{
	ostr << "key\t\tdata" << endl;
	for (int i = 0; i < A.count; i++)
		ostr << "| " << A.mas[i] << "\t |" << endl;
	return ostr;
}