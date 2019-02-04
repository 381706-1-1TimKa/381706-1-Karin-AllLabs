#include <iostream>
#include "MasList.h"
using namespace std;

int main()
{
	try {
		cout << "Enter the size, please" << endl;
		int size;
		cin >> size;
		TMasList<int> L (size);
		while (1) {
			cout << endl << endl;
			cout << "What you want to do?" << endl;
			cout << "1) Add to begin" << endl;
			cout << "2) Add to the end" << endl;
			cout << "3) Take first" << endl;
			cout << "4) Take last" << endl;
			cout << "5) Check for emptiness" << endl;
			cout << "6) Check for fullness" << endl;
			cout << "7) Exit" << endl;
			int n;
			cin >> n;
			switch (n) {
			case 1:
				int tmp;
				cout << "Enter element" << endl;
				cin >> tmp;
				L.PushStart(tmp);
				break;
			case 2:
				int temp;
				cout << "Enter element" << endl;
				cin >> temp;
				L.PushFinish(temp);
				break;
			case 3:
				cout << L.PullStart();
				break;
			case 4:
				cout << L.PullFinish();
				break;
			case 5:
				if (L.IsEmpty())
					cout << "Empty" << endl;
				else
					cout << "Not empty" << endl;
				break;
			case 6:
				if (L.IsFull())
					cout << "Full" << endl;
				else
					cout << "Not full" << endl;
				break;
			case 7:
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