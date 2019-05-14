#include "Text.h"
#include "../TextLib/MyString.h"
#include <iostream>
using namespace std;

int main()
{
	TMyString S;
	S = "This is string";
	TNode A(S);
	char* C = A.ToStr();
	TMyString S2(C);
	cout << S2 << endl;
}