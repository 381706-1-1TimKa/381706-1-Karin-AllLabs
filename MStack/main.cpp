#include <iostream>
#include "MStack.h"
using namespace std;

int main()
{
	TMStack<int> A(3, 12);
	TMStack<int> B(A);
	return 0;
}