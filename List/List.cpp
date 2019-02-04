#include <iostream>
#include "List.h"
using namespace std;

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