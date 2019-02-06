#include <iostream>
#include "List.h"
#include "Exeption.h"
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
			cout << "3) Add to ..." << endl;
			cout << "4) Take first" << endl;
			cout << "5) Take last" << endl;
			cout << "6) Take ..." << endl;
			cout << "7) Check for emptiness" << endl;
			cout << "8) Exit" << endl;
			int n;
			cin >> n;
			switch (n) {
			case 1:
				int tmp1;
				cout << "Enter element" << endl;
				cin >> tmp1;
				L.PutBegin(tmp1);
				break;
			case 2:
				int tmp2;
				cout << "Enter element" << endl;
				cin >> tmp2;
				L.PutEnd(tmp2);
				break;
			case 3:
				int putpos, tmp3;
				cout << "Enter element" << endl;
				cin >> tmp3;
				cout << "Enter position" << endl;
				cin >> putpos;
				L.PutElem(tmp3, putpos);
				break;
			case 4:
				cout << L.GetBegin() << endl;
				break;
			case 5:
				cout << L.GetEnd() << endl;
				break;
			case 6:
				cout << "Enter position" << endl;
				int getpos;
				cin >> getpos;
				cout << L.GetElem(getpos) << endl;
				break;
			case 7:
				if (L.IsEmpty())
					cout << "Empty" << endl;
				else
					cout << "Not empty" << endl;
				break;
			case 8:
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
int main()
{
	try
	{
		TList<int> A;
		cout << "Add to the end 1" << endl;
		A.PutEnd(1);
		cout << "Add to the end 2" << endl;
		A.PutEnd(2);
		cout << "Add to begin 3" << endl;
		A.PutBegin(3);
		cout << "Add to begin 4" << endl;
		A.PutBegin(4);
		cout << "Add to finish 5" << endl;
		A.PutEnd(5);
		cout << "Add 6 to 4 position" << endl;
		A.PutElem(6, 3);
		cout << "Add 7 to 2 position" << endl;
		A.PutElem(7, 1);
		cout << "Take first" << endl;
		cout << A.GetBegin() << endl << endl;
		cout << "Take first" << endl;
		cout << A.GetBegin() << endl << endl;
		cout << "Take last" << endl;
		cout << A.GetEnd() << endl << endl;
		cout << "Take first" << endl;
		cout << A.GetBegin() << endl << endl;
		cout << "Take 2nd" << endl;
		cout << A.GetElem(1) << endl << endl;
		cout << "Take last" << endl;
		cout << A.GetEnd() << endl << endl;
		return 0;
	}
	catch (TExeption ex)
	{
		ex.Print();
	}
}
#endif