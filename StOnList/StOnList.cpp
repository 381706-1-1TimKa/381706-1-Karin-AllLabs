#include <iostream>
#include "StackList.h"
//#define _IO_EXAMPLE_
using namespace std;

void Print(TStackList<int> A);
int main()
{
	cout << "Let's create Stack on List" << endl;
	TStackList <int> S;

#ifdef _IO_EXAMPLE_
	while (1) {
		cout << "What you want to do" << endl;
		cout << "1) Put" << endl;
		cout << "2) Get" << endl;
		cout << "3) Check for Empty" << endl;
		cout << "4) Print" << endl;
		cout << "5) Exit" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Enter value" << endl;
			int a;
			cin >> a;
			cout << endl;
			S.Put(a);
			break;
		case 2:
			cout << S.Get() << endl;
			break;
		case 3:
			if (S.IsEmpty())
				cout << "True. Stack is empty" << endl;
			else
				cout << "False. Stack isn't empty" << endl;
			break;
		case 4:
			Print(S);
			break;
		case 5:
			return 0;
		default:
			cout << "Incorrect value" << endl;
		}
	}
#endif

#ifndef _IO_EXAMPLE_
	S.Put(5);
	S.Put(6);
	S.Put(21);
	S.Put(-22);
	S.Put(100);
	cout << endl << "Put(5);" << endl;
	cout << "Put(6);" << endl;
	cout << "Put(21);" << endl;
	cout << "Put(-22);" << endl;
	cout << "Put(100);" << endl << endl;
	cout << "print stack" << endl;
	Print(S);
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Get()=";
		cout << S.Get() << endl;
	}
#endif
}

void Print(TStackList<int> S) {
	TStackList<int> S1;
	while (!(S.IsEmpty())) {
		int a = S.Get();
		S1.Put(a);
		cout << a << " ";
	}
	cout << endl;
	while (!(S1.IsEmpty()))
		S.Put(S1.Get());
}