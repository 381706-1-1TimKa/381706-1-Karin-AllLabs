#include <iostream>
#include "Queue.h"
//#define _IO_EXAMPLE_
using namespace std;

void Print(TQueue<int> Q);
int main()
{
	cout << "Let's create Queue" << endl;
	cout << "Enter size of your Queue" << endl;

	int n;
#ifdef _IO_EXAMPLE_
	cin >> n;
#endif
#ifndef _IO_EXAMPLE_
	n = 10;
#endif
	TQueue <int> Q(n);

#ifdef _IO_EXAMPLE_
	while (1) {
		cout << "What you want to do" << endl;
		cout << "1) Put" << endl;
		cout << "2) Get" << endl;
		cout << "3) Check for full" << endl;
		cout << "4) Check for Empty" << endl;
		cout << "5) Print" << endl;
		cout << "6) Exit" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Enter value" << endl;
			int a;
			cin >> a;
			cout << endl;
			Q.Put(a);
			break;
		case 2:
			cout << Q.Get() << endl;
			break;
		case 3:
			if (Q.IsFull())
				cout << "True. Queue is full" << endl;
			else
				cout << "False. Queue isn't full" << endl;
			break;
		case 4:
			if (Q.IsEmpty())
				cout << "True. Queue is empty" << endl;
			else
				cout << "False. Queue isn't empty" << endl;
			break;
		case 5:
			Print(Q);
			break;
		case 6:
			return 0;
		default:
			cout << "Incorrect value" << endl;
		}
	}
#endif

#ifndef _IO_EXAMPLE_
	Q.Put(5);
	Q.Put(6);
	Q.Put(21);
	Q.Put(-22);
	Q.Put(100);
	cout << endl << "Put(5);" << endl;
	cout << "Put(6);" << endl;
	cout << "Put(21);" << endl;
	cout << "Put(-22);" << endl;
	cout << "Put(100);" << endl << endl;
	cout << "print queue" << endl;
	Print(Q);
	for (int i = 0; i < 5; i++) {
		cout << "Get()=";
		cout << Q.Get() << endl;
	}
#endif
	return 0;
}

void Print(TQueue<int> Q) {
	for (int i = 0; i < Q.GetCount(); i++) {
		int a;
		a = Q.Get();
		cout << a << " ";
		Q.Put(a);
	}
	cout << endl;
}