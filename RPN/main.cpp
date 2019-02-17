#include <iostream>
#include "RPN.h"
using namespace std;

#define fortravis

int main()
{
	cout << "Enter string" << endl;
	TString str;

#ifndef fortravis
	cin >> str;
#endif

#ifdef fortravis
	TString s1("3*2*(45-31)/6+(56-(2+8)/2)");
	str = s1;
	cout << "3 * 2 * (45 - 31) / 6 + (56 - (2 + 8) / 2)" << endl;
#endif

	TQueue<char> q = StrToRPN(str);
	double res;
	TQueue<char> q1(q);
	while (!q1.IsEmpty())
		cout << q1.Get();
	cout << endl;
	res = Calculate(q);
	cout << res << endl;
	return 0;
}