#include <iostream>
#include "List.h"
#define fortravis
using namespace std;

#ifndef fortravis
int main()
{
	try {
		TList<int> L;
		while (1) {
			cout << "What you want to do?" << endl;
			cout << "1) Add to begin" << endl;
			cout << "2) Add to the end" << endl;
			cout << "3) Take first" << endl;
			cout << "4) Take last" << endl;
			cout << "5) Check for emptiness" << endl;
			cout << "6) Exit" << endl;
			int n;
			cin >> n;
			switch (n) {
			case 1:
				int tmp;
				cout << "Enter element" << endl;
				cin >> tmp;
				L.PutBegin(tmp);
				break;
			case 2:
				int temp;
				cout << "Enter element" << endl;
				cin >> temp;
				L.PutEnd(temp);
				break;
			case 3:
				cout << L.GetBegin();
				break;
			case 4:
				cout << L.GetEnd();
				break;
			case 5:
				if (L.IsEmpty())
					cout << "Empty" << endl;
				else
					cout << "Not empty" << endl;
				break;
			case 6:
				return 0;
			default:
				cout << "Incorrect value" << endl;
			}
		}
	}
	catch (TExeption ex) {
		ex.Print();
	}
}
#endif

#ifdef fortravis
int main() {
	TList<int> A;
	cout << "Add to the end 1" << endl;
	A.PutEnd(1);
	cout << "Add to the end 2" << endl;
	A.PutEnd(2);
	cout << "Add to begin 3" << endl;
	A.PutBegin(3);
	cout << "Add to begin 4" << endl;
	A.PutBegin(4);
	cout << "Add to finish 5" << endl << endl;
	A.PutEnd(5);
	cout << "Take first" << endl;
	cout << A.GetBegin() << endl << endl;
	cout << "Take first" << endl;
	cout << A.GetBegin() << endl << endl;
	cout << "Take last" << endl;
	cout << A.GetEnd() << endl << endl;
	cout << "Take first" << endl;
	cout << A.GetBegin() << endl << endl;
	cout << "Take last" << endl;
	cout << A.GetEnd() << endl << endl;
	return 0;
}
#endif