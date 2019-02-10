#include <iostream>
#include "MStack.h"
#define fortravis
using namespace std;

int ChoiceStack(TMStack<int> &S);
int Menu(TMStack<int> &S);

int main()
{
	try
	{
		cout << "Let's create MultiStack" << endl;
		cout << "Enter size of your Multistack and" << endl;
		cout << "number of stacks"<<endl;
		int n, size;
#ifndef fortravis
		cin >> size;
		cin >> n;
#endif
#ifdef fortravis
		n = 5;
		size = 10;
#endif
		TMStack <int> S(n, size);
#ifndef fortravis
		Menu(S);
		return 0;
#endif

#ifdef fortravis
		S.Put(0, 5);
		S.Put(1, 6);
		S.Put(2, 21);
		S.Put(3, -22);
		S.Put(4, 100);
		cout << endl << "Put(0, 5);" << endl;
		cout << "Put(1, 6);" << endl;
		cout << "Put(2, 21);" << endl;
		cout << "Put(3, -22);" << endl;
		cout << "Put(4, 100);" << endl << endl;
		cout << endl;
		for (int i = 0; i < 5; i++) {
			cout << "Get(" << i << ")=";
			cout << S.Get(i) << endl;
		}
#endif
	}
	catch (TException ex)
	{
		ex.Print();
	}
}

int Menu(TMStack<int> &S) {
	while (1) {
		cout << "What you want to do" << endl;
		cout << "1) Put" << endl;
		cout << "2) Get" << endl;
		cout << "3) Check for full" << endl;
		cout << "4) Check for Empty" << endl;
		cout << "5) Exit" << endl;
		int n;
		cin >> n;
		int k = ChoiceStack(S);
		switch (n) {
		case 1:
			cout << "Enter value" << endl;
			int a;
			cin >> a;
			cout << endl;
			S.Put(k, a);
			break;
		case 2:
			cout << S.Get(k) << endl;
			break;
		case 3:
			if (S.IsFull(k))
				cout << "True. Stack is full" << endl;
			else
				cout << "False. Stack isn't full" << endl;
			break;
		case 4:
			if (S.IsEmpty(k))
				cout << "True. Stack is empty" << endl;
			else
				cout << "False. Stack isn't empty" << endl;
			break;
		case 5:
			return 0;
		default:
			cout << "Incorrect value" << endl;
		}
	}
}

int ChoiceStack(TMStack<int> &S) {
	while (1) {
		cout << "Enter stack number" << endl;
		int k;
		cin >> k;
		if ((k >= 0) && (k < S.GetStackNumber()))
			return k;
		else
			cout << "incorrect value. Try again" << endl;
	}
}