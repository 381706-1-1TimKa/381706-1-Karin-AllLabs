#include <iostream>
#include "RPN.h"
using namespace std;

int main()
{
	cout << "Enter string" << endl;
	TString str;
	cin >> str;
	TQueue<char> q(3 * str.GetLength());
	q = StrToRPN(str);
	double res;
	TQueue<char> q1(q);
	while (!q1.IsEmpty())
		cout << q1.Get();
	cout << endl;
	res = Calculate(q);
	cout << res << endl;
	return 0;
}